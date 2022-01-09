#if defined _inc_admin_dialogs
    #undef _inc_admin_dialogs
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_dialogs_included
    #endinput
#endif
#define _admin_dialogs_included

/** Variables */
static
    tmpActorSkinID[MAX_PLAYERS],
    adminCodeAttempts[MAX_PLAYERS];

/** Dialogs */
Dialog:DIALOG_AHELP(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        return 1;
    }

    Admin_ShowAdminCmdsOfLevel(playerid, listitem);

    return 1;
}

Dialog:DIALOG_ACODE(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        Kick(playerid);
        return 1;
    }

    if (strval(inputtext) != Admin_GetCode(playerid))
    {
        ++adminCodeAttempts[playerid];

        if (adminCodeAttempts[playerid] == MAX_LOGIN_ATTEMPTS)
        {
            Kick(playerid);
            return 1;
        }

        SendErrorMsg(playerid, "Pogresan kod!");

        Dialog_Show(playerid, "DIALOG_ACODE", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"Blackland - "WHITE"Admin kod",
            ""MAIN_COLOR"%s "WHITE"Vi ste admin level %d na ovom serveru.\n\
            Unesite Vas admin kod za nastavak:", ""MAIN_COLOR"Unesi", "Izlaz",
            ReturnPlayerName(playerid), Admin_GetLevel(playerid)
        );
        return 1;
    }

    Admin_SetDutyStatus(playerid, true);
    SetPlayerHealth(playerid, 0x7F800000);

    SendInfoMsgToAllF("Administrator %s je na duznosti.", ReturnPlayerName(playerid));

    return 1;
}

Dialog:DIALOG_MAKELEADER(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        return 1;
    }

    static
        targetid,
        type;

    if (sscanf(string: inputtext, "ri", targetid, type))
    {
        Dialog_Show(playerid, "DIALOG_MAKELEADER", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"Blackland - "WHITE"Lider",
            ""MAIN_COLOR"Organizacije:\n"WHITE"0. Skini lidera\n1. Policija\n2. Bice dodato...\n\
            Unesite ID igraca i broj: ", ""MAIN_COLOR"Potvrdi", "Izlaz"
        );
        return 1;
    }

    switch (type)
    {
        case 0:
        {
            if (!Organization_IsPlayerLeader(targetid))
            {
                SendErrorMsg(playerid, "Taj igrac nije lider!");
                return 1;
            }

            Organization_SetPlayerLeader(targetid, 0);
            Account_SetPlayerSkin(targetid, 1);

            SendInfoMsgToAllF("Admin %s je skinuo lidera igracu %s.", ReturnPlayerName(playerid), ReturnPlayerName(targetid));
        }
        
        case 1:
        {
            if (Organization_IsPlayerLeader(targetid) && Organization_GetPlayerOrgID(targetid) == Organization_LSPD())
            {
                SendErrorMsg(playerid, "Taj igrac je vec lider te organizacije!");
                return 1;
            }

            Organization_SetPlayerOrgID(targetid, Organization_LSPD(), true);
            Account_SetPlayerSkin(targetid, 283);

            SendInfoMsgToAllF("Admin %s je postavio lidera policije igracu %s.", ReturnPlayerName(playerid), ReturnPlayerName(targetid));
        }
    }

    return 1;
}

Dialog:DIALOG_ACTORSKIN(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        return 1;
    }

    if (!(1 <= strval(string: inputtext) <= 299))
    {
        SendErrorMsg(playerid, "Ne mozete ispod 1 i iznad 299!");
        return Dialog_Show(playerid, "DIALOG_ACTORSKIN", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"Blackland - "WHITE"Aktor",
            ""MAIN_COLOR"INFO: "WHITE"Unesite skin aktora:",
            ""MAIN_COLOR"Unesi", "Izlaz"
        );
    }

    tmpActorSkinID[playerid] = strval(string: inputtext);
    Dialog_Show(playerid, "DIALOG_ACTORANIM", DIALOG_STYLE_INPUT,
        ""MAIN_COLOR"Blackland - "WHITE"Aktor",
        ""MAIN_COLOR"ANIMACIJE: \n\
        "WHITE"0. Nema animaciju\n\
        "WHITE"1. Aktor u sedecem polozaju\n\
        "WHITE"2. Aktor koji govori\n\
        "WHITE"3. Ruke u visu\n\
        "WHITE"4. Umoran aktor\n\
        "MAIN_COLOR"INFO: "WHITE"Unesite id animacije:",
        ""MAIN_COLOR"Unesi", "Izlaz"
    );

    return 1;
}

Dialog:DIALOG_ACTORANIM(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
    {
        return 1;
    }

    if (!(0 <= strval(string: inputtext) <= 4))
    {
        SendErrorMsg(playerid, "Ne mozete ispod 0 i iznad 4!");
        return Dialog_Show(playerid, "DIALOG_ACTORANIM", DIALOG_STYLE_INPUT,
            ""MAIN_COLOR"Blackland - "WHITE"Aktor",
            ""MAIN_COLOR"ANIMACIJE: \n\
            "WHITE"0. Nema animaciju\n\
            "WHITE"1. Aktor u sedecem polozaju\n\
            "WHITE"2. Aktor koji govori\n\
            "WHITE"3. Ruke u visu\n\
            "WHITE"4. Umoran aktor\n\
            "MAIN_COLOR"INFO: "WHITE"Unesite id animacije:",
            ""MAIN_COLOR"Unesi", "Izlaz"
        );
    }

    Actor_Create(playerid, tmpActorSkinID[playerid], strval(string: inputtext));

    return 1;
}