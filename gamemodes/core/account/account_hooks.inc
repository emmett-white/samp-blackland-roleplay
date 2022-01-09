#if defined _inc_account_hooks
    #undef _inc_account_hooks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _account_hooks_included
    #endinput
#endif
#define _account_hooks_included

#include <YSI_Coding\y_hooks>

/** Variables */
static
    gCheckPlayerField[MAX_PLAYERS][6],
    gPlayerLoginAttempts[MAX_PLAYERS];

/** Hooks */
hook OnPlayerConnect(playerid)
{
    if (!IsValidNickName(ReturnPlayerName(playerid)))
    {
        SendErrorMsg(playerid, "Molimo unesite ime u formatu: Ime_Prezime!");
        task_await(Task: BindToPlayer(task_ms(1000), playerid));
        Kick(playerid);

        Admin_SendMessage(ADMIN_CHAT_COLOR, "[ADMIN]: %s je kikovan zbog nepravilnog imena.",
            ReturnPlayerName(playerid)
        );
        return 1;
    }
    
    Admin_SetDutyStatus(playerid, false);
    Player_SetSpawnedStatus(playerid, false);
    Ban_CheckPlayerStatus(playerid);
    Winter_SnowObjStatus(playerid);

    SetPlayerColor(playerid, 0xFFFFFFAA);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if (playertextid == PlayerText: UI_ClickRegisterTextDraw(playerid, 9))
    {
        Dialog_Show(playerid, "DIALOG_PASSWORD", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"Blackland - "WHITE"Lozinka",
            ""RED"[!]: "WHITE"Jednom kada unesete lozinku necete biti u mogucnosti ponovo je uneti.\n\n\
            "MAIN_COLOR"%s "WHITE"molimo Vas unesite Vasu zeljenu lozinku:",
            ""MAIN_COLOR"Unesi", "Izlaz", ReturnPlayerName(playerid)
        );
    }

    if (playertextid == PlayerText: UI_ClickRegisterTextDraw(playerid, 10))
    {
        Dialog_Show(playerid, "DIALOG_EMAIL", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"Blackland - "WHITE"E-mail adresa",
            ""MAIN_COLOR"%s "WHITE"molimo Vas unesite Vasu vazecu e-mail adresu.\n\
            "MAIN_COLOR"[?]: "WHITE"E-mail adresa Vam moze pomoci u slucaju zaboravljanja lozinke Vaseg naloga.",
            ""MAIN_COLOR"Unesi", "Izlaz", ReturnPlayerName(playerid)
        );
    }

    if (playertextid == PlayerText: UI_ClickRegisterTextDraw(playerid, 12))
    {
        Dialog_Show(playerid, "DIALOG_AGES", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"Blackland - "WHITE"Godine",
            ""MAIN_COLOR"%s "WHITE"Koliko imate godina?",
            ""MAIN_COLOR"Unesi", "Izlaz", ReturnPlayerName(playerid)
        );
    }

    if (playertextid == PlayerText: UI_ClickRegisterTextDraw(playerid, 11))
    {
        Dialog_Show(playerid, "DIALOG_COUNTRY", DIALOG_STYLE_LIST,
            ""MAIN_COLOR"Blackland - "WHITE"Drzava",
            "Srbija\nBosna i Hercegovina\nHrvatska\nCrna Gora\nOstalo",
            ""MAIN_COLOR"Odaberi", "Izlaz"
        );
    }

    if (playertextid == PlayerText: UI_ClickRegisterTextDraw(playerid, 13))
    {
        Dialog_Show(playerid, "DIALOG_SEX", DIALOG_STYLE_MSGBOX,
            ""MAIN_COLOR"Blackland - "WHITE"Spol",
            ""MAIN_COLOR"%s "WHITE"odaberite kog ste spola:",
            ""MAIN_COLOR"Zensko", "Musko", ReturnPlayerName(playerid)
        );
    }

    if (playertextid == PlayerText: UI_ClickRegisterTextDraw(playerid, 14) && accountSex[playerid] != -1)
    {
        Dialog_Show(playerid, "DIALOG_SKIN", DIALOG_STYLE_LIST,
            ""MAIN_COLOR"Blackland - "WHITE"Skin",
            (!accountSex[playerid] ? ("Obicna devojka\nSekretarica\nKucka\nSportska devojka") :
            ("Cloud\nBiznismen\nDeeJay\nBelac sa kapuljacom")),
            ""MAIN_COLOR"Odaberi", "Izlaz"
        );
    }

    if (playertextid == PlayerText: UI_ClickRegisterTextDraw(playerid, 15))
    {
        for (new i = 0; i < 6; ++i)
        {
            if (!gCheckPlayerField[playerid][i])
            {
                return SendErrorMsg(playerid, "Niste popunili sva polja!");
            }
        }

        Account_SetPlayerMoney(playerid, 10000);
        Account_SetPlayerLevel(playerid, 1);

        GameTextForPlayer(playerid, "~w~Loading account...", 3000, 3);
        defer Account_SetPlayerSpawn(playerid, 1);
    }

    if (playertextid == PlayerText: UI_ClickLoginTextDraw(playerid))
    {
        Dialog_Show(playerid, "DIALOG_LOGIN", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"Blackland - "WHITE"Prijavljivanje",
            ""RED"[!]: "WHITE"Imate maksimalno %d pokusaja da se prijavite.\n\n\
            "MAIN_COLOR"%s "WHITE"molimo Vas unesite Vasu tacnu lozinku:",
            ""MAIN_COLOR"Unesi", "Izlaz", MAX_LOGIN_ATTEMPTS, ReturnPlayerName(playerid)
        );
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

/** Dialogs */
Dialog:DIALOG_PASSWORD(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        Kick(playerid);
        return 1;
    }

    if (!(MIN_PASSWORD_LENGTH <= strlen(string: inputtext) <= MAX_PASSWORD_LENGTH))
    {
        return SendErrorMsg(playerid, "Prekratka ili predugacka lozinka!");
    }

    strcopy(accountPassword[playerid], string: inputtext);

    new
        String: str_query_acc_insert,
        String: str_query_char_insert;

    str_query_acc_insert = String: str_format("INSERT INTO accounts (account_name, account_password) VALUES ('%e', '%e')", ReturnPlayerName(playerid), string: accountPassword[playerid]);
    str_query_char_insert = String: str_format("INSERT INTO characters (char_name) VALUES ('%e')", ReturnPlayerName(playerid));
    
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_acc_insert, "Account_InsertAccountID", "d", playerid);
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_char_insert, "Account_InsertCharID", "d", playerid);

    va_PlayerTextDrawSetString(playerid, PlayerText: UI_ClickRegisterTextDraw(playerid, 9),
        "%s", Account_GetPlayerPassword(playerid)
    );

    gCheckPlayerField[playerid][0] = 1;

    return 1;
}

Dialog:DIALOG_EMAIL(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        return 1;
    }

    new Regex: regex = Regex_New("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
    if (!Regex_Check(string: inputtext, Regex: regex))
    {
        return SendErrorMsg(playerid, "Unesite vazecu e-mail adresu!");
    }

    Account_SetPlayerEmail(playerid, string: inputtext);
    
    if (strlen(string: inputtext) < 24)
    {
        va_PlayerTextDrawSetString(playerid, PlayerText: UI_ClickRegisterTextDraw(playerid, 10),
            "%s", Account_GetPlayerEmail(playerid)
        );
    }

    gCheckPlayerField[playerid][1] = 1;

    return 1;
}

Dialog:DIALOG_AGES(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        return 1;
    }

    if (!(12 <= strval(string: inputtext) <= 50))
    {
        return SendErrorMsg(playerid, "Ne mozete biti mladji od 12 i stariji od 50 godina!");
    }

    PlayerTextDrawSetString(playerid, PlayerText: UI_ClickRegisterTextDraw(playerid, 12), inputtext);
    gCheckPlayerField[playerid][2] = 1;

    return 1;
}

Dialog:DIALOG_COUNTRY(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        return 1;
    }

    PlayerTextDrawSetString(playerid, PlayerText: UI_ClickRegisterTextDraw(playerid, 11),
        (!listitem ? ("Srbija") : (listitem == 1 ? ("Bosna i Hercegovina") :
        (listitem == 2 ? ("Hrvatska") : (listitem == 3 ? ("Crna Gora") : ("Ostalo")))))
    );
    gCheckPlayerField[playerid][3] = 1;

    return 1;
}

Dialog:DIALOG_SEX(const playerid, response, listitem, string: inputtext[])
{
    accountSex[playerid] = (!response ? (1) : (0));
    gCheckPlayerField[playerid][4] = 1;

    PlayerTextDrawSetString(playerid, PlayerText: UI_ClickRegisterTextDraw(playerid, 13),
        (!response ? ("Musko") : ("Zensko"))
    );

    return 1;
}

Dialog:DIALOG_SKIN(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        return 1;
    }

    static selectSkin;
    if (!accountSex[playerid])
    {
        switch (listitem)
        {
            case 0: selectSkin = 12;
            case 1: selectSkin = 11;
            case 2: selectSkin = 40;
            case 3: selectSkin = 56;
        }

        Account_SetPlayerSkin(playerid, selectSkin);
        gCheckPlayerField[playerid][5] = 1;
        return 1;
    }

    switch (listitem)
    {
        case 0: selectSkin = 299;
        case 1: selectSkin = 295;
        case 2: selectSkin = 19;
        case 3: selectSkin = 29;
    }

    Account_SetPlayerSkin(playerid, selectSkin);
    gCheckPlayerField[playerid][5] = 1;

    return 1;
}

Dialog:DIALOG_LOGIN(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        return Kick(playerid);
    }

    if (!strcmp(inputtext, Account_GetPlayerPassword(playerid), false))
    {
        Dialog_Close(playerid);
        UI_CreateLoginTextDraws(playerid, false);
        GameTextForPlayer(playerid, "~w~Ucitavanje naloga...", 3000, 3);
        
        defer Account_SetPlayerSpawn(playerid, 2);
    }

    else
    {
        ++gPlayerLoginAttempts[playerid];
        SendErrorMsgF(playerid, "Preostalo pokusaja: %d/%d!", gPlayerLoginAttempts[playerid], MAX_LOGIN_ATTEMPTS);

        if (gPlayerLoginAttempts[playerid] == MAX_LOGIN_ATTEMPTS)
        {
            return Kick(playerid);
        }
    }

    return 1;
}