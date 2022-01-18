#if defined _inc_player_functions
    #undef _inc_player_functions
#endif
// custom include-guard to ensure we don't duplicate
#if defined _player_functions_included
    #endinput
#endif
#define _player_functions_included

// ---
// Variables
// ---
static
    Text3D: gPlayerRankLabel[MAX_PLAYERS],

    BitArray: Bit_PlayerSpawned<MAX_PLAYERS>,
    BitArray: Bit_HouseLocated<MAX_PLAYERS>;

// ---
// Functions
// ---
stock Player_ClearChat(const playerid, const lines)
{
    for (new i = 0; i < lines; ++i)
        SendClientMessage(playerid, -1, " ");

    SendServerMsg(playerid, "Chat je ociscen.");
    SendInfoMsg(playerid, "https://discord.gg/"DISCORD_INVITE_LINK"");

    return 1;
}

stock GetPlayerID(const string: name[])
{
	foreach (new i: Player)
        if(strcmp(string: name, ReturnPlayerName(i), true) == 0)
            return i;

	return -1;
}

stock Player_SendRadiusMsg(Float: radi, playerid, const string: string[], c1, c2, c3, c4, c5)
{
	if (IsPlayerConnected(playerid))
    {
		new
            Float:pPosX, Float:pPosY, Float:pPosZ,
		    Float:oldpPosX, Float:oldpPosY, Float:oldpPosZ,
		    Float:tmpPosX, Float:tmpPosY, Float:tmpPosZ;

		GetPlayerPos(playerid, oldpPosX, oldpPosY, oldpPosZ);
		foreach(new i: Player)
        {
            if (GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i))
            {
                GetPlayerPos(i, pPosX, pPosY, pPosZ);
                
                tmpPosX = (oldpPosX -pPosX);
                tmpPosY = (oldpPosY -pPosY);
                tmpPosZ = (oldpPosZ -pPosZ);
                
                if(((tmpPosX < radi/16) && (tmpPosX > -radi/16)) && ((tmpPosY < radi/16) && (tmpPosY > -radi/16)) && ((tmpPosZ < radi/16) && (tmpPosZ > -radi/16)))
                    SendClientMessage(i, c1, string);

                else if(((tmpPosX < radi/8) && (tmpPosX > -radi/8)) && ((tmpPosY < radi/8) && (tmpPosY > -radi/8)) && ((tmpPosZ < radi/8) && (tmpPosZ > -radi/8)))
                    SendClientMessage(i, c2, string);

                else if(((tmpPosX < radi/4) && (tmpPosX > -radi/4)) && ((tmpPosY < radi/4) && (tmpPosY > -radi/4)) && ((tmpPosZ < radi/4) && (tmpPosZ > -radi/4)))
                    SendClientMessage(i, c3, string);

                else if(((tmpPosX < radi/2) && (tmpPosX > -radi/2)) && ((tmpPosY < radi/2) && (tmpPosY > -radi/2)) && ((tmpPosZ < radi/2) && (tmpPosZ > -radi/2)))
                    SendClientMessage(i, c4, string);

                else if(((tmpPosX < radi) && (tmpPosX > -radi)) && ((tmpPosY < radi) && (tmpPosY > -radi)) && ((tmpPosZ < radi) && (tmpPosZ > -radi)))
                    SendClientMessage(i, c5, string);
            }
		}
	}
    
	return 1;
}

stock Player_IsSpawned(const playerid) return Bit_Get(Bit: Bit_PlayerSpawned, playerid);
stock Player_SetSpawnedStatus(const playerid, bool: status = true)
{
    Bit_Set(Bit: Bit_PlayerSpawned, playerid, status);
    return 1;
}

stock Player_HouseCPEnabled(const playerid) return Bit_Get(Bit: Bit_HouseLocated, playerid);
stock Player_SetHouseCPStatus(const playerid, bool: status = true)
{
    Bit_Set(Bit: Bit_HouseLocated, playerid, status);
    return 1;
}

stock Player_SetNewbieRank(const playerid)
{
    if (!Admin_GetLevel(playerid) && Account_GetPlayerLevel(playerid) < 10)
        gPlayerRankLabel[playerid] = CreateDynamic3DTextLabel("NOVAJLIJA", X11_YELLOW, 0.0, 0.0, 0.0, Float: 30.0, playerid);

    return 1;
}

/** Dialogs */
Dialog:DIALOG_LEAVEMONEY(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    if (!(10 <= strval(string: inputtext) <= 100000))
        return SendErrorMsg(playerid, "Ne mozete ispod $10 i iznad $100.000!");

    Account_SetPlayerBankMoney(playerid, (Account_GetPlayerBankMoney(playerid) + strval(string: inputtext)));
    Account_SetPlayerMoney(playerid, (Account_GetPlayerMoney(playerid) - strval(string: inputtext)));
    GivePlayerMoney(playerid, -strval(string: inputtext));

    SendServerMsgF(playerid, "Ostavili ste $%d novca u banku. Ukupno u banci: $%d.", strval(string: inputtext), Account_GetPlayerBankMoney(playerid));

    return 1;
}

Dialog:DIALOG_TAKEMONEY(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    if (!(10 <= strval(string: inputtext) <= 100000))
        return SendErrorMsg(playerid, "Ne mozete ispod $10 i iznad $100.000!");

    if (Account_GetPlayerBankMoney(playerid) < strval(string: inputtext))
        return SendErrorMsg(playerid, "Nemate toliko novca u banci!");

    Account_SetPlayerBankMoney(playerid, (Account_GetPlayerBankMoney(playerid) - strval(string: inputtext)));
    Account_SetPlayerMoney(playerid, (Account_GetPlayerMoney(playerid) + strval(string: inputtext)));
    GivePlayerMoney(playerid, strval(string: inputtext));

    SendServerMsgF(playerid, "Podigli ste $%d novca iz banke. Ukupno u banci: $%d.", strval(string: inputtext), Account_GetPlayerBankMoney(playerid));

    return 1;
}

Dialog:DIALOG_WINTER(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    switch (listitem)
    {
        case 0:
        {
            Winter_SnowObjStatus(playerid, (Winter_GetSnowObjStatus(playerid) ? (false) : (true)));
            return callcmd::winter(playerid, "");
        }

        case 1:
        {
            Winter_SnowflakeStatus(playerid, (Winter_GetSnowflakeStatus(playerid) ? (false) : (true)));
            return callcmd::winter(playerid, "");
        }

        case 2:
        {
            Winter_SnowCapStatus(playerid, (Winter_GetSnowCapStatus(playerid) ? (false) : (true)));
            return callcmd::winter(playerid, "");
        }

        case 3:
        {
            Winter_ColdBreathStatus(playerid, (Winter_GetColdBreathStatus(playerid) ? (false) : (true)));
            return callcmd::winter(playerid, "");
        }

        case 4:
        {
            Winter_StatusAll(playerid, (Winter_GetStatusAll(playerid) ? (false) : (true)));
            return callcmd::winter(playerid, "");
        }
    }

    return 1;
}

Dialog:DIALOG_HOUSEMENU(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;
    
    switch (listitem)
    {
        case 0:
        {
            Dialog_Show(playerid, "DIALOG_HOUSEHELP", DIALOG_STYLE_LIST,
                ""MAIN_COLOR"Blackland - "WHITE"Kuca komande",
                "/kuca\n\
                /locirajkucu",
                "Nazad"
            );
        }

        case 1:
        {
            Dialog_Show(playerid, "DIALOG_HOUSEDESC", DIALOG_STYLE_INPUT,
                ""MAIN_COLOR"Blackland - "WHITE"Opis kuce",
                "Unesite opis za vasu kucu:",
                ""MAIN_COLOR"Potvrdi", "Nazad"
            );
        }

        case 2:
        {
            new houseid = House_GetNearby(playerid);
            House_SetLocked(houseid, (House_IsLocked(houseid) ? (0) : (1)));

            SendInfoMsgF(playerid, "%s ste kucu", (House_IsLocked(houseid) ? ("Zakljucali") : ("Otkljucali")));
            callcmd::kuca(playerid, "");
        }
    }

    return 1;
}

Dialog:DIALOG_HOUSEHELP(const playerid, response, listitem, string: inputtext[])
{
    return callcmd::kuca(playerid, "");
}

Dialog:DIALOG_HOUSEDESC(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return callcmd::kuca(playerid, "");

    new houseid = House_GetNearby(playerid);
    if (!strcmp(string: inputtext, House_GetDescription(houseid), false))
        return SendErrorMsg(playerid, "Ne mozete isti opis."), callcmd::kuca(playerid, "");

    House_SetDescription(houseid, string: inputtext);

    return callcmd::kuca(playerid, "");
}