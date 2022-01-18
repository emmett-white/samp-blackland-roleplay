#if defined _inc_admin_commands_1
    #undef _inc_admin_commands_1
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_commands_1_included
    #endinput
#endif
#define _admin_commands_1_included

// ---
// Variables
// ---
static
    BitArray: Bit_PlayerFreezed<MAX_PLAYERS>,
    adminChatCleared;

// ---
// Commands
// ---
acmd:[1]xyz(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
	static
		x,
		y,
		z;

	if (sscanf(params, "fff", Float: x, Float: y, Float: z))
        return SendSyntaxMsg(playerid, "/xyz [x] [y] [z]");

	SetPlayerPos(playerid, Float: x, Float: y, Float: z);

	return 1;
}

acmd:[1]veh(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
    if (!Admin_GetVehicleSpawned(playerid))
    {
        if (isnull(string: params))
            return SendSyntaxMsg(playerid, "/veh [id vozila]");

        if (!(400 <= strval(string: params) <= 605))
            return SendErrorMsg(playerid, "ID vozila ne moze biti manji od 400 i veci od 605!");

        Admin_CreateVehicle(playerid, strval(string: params));
        return 1;
    }

    Admin_DestroyVehicle(playerid);

    return 1;
}

acmd:[1]ahelp(playerid, const string: params[])
{
    new
        string: tmpString[152],
        string: ranks[256],
        
        alevel = Admin_GetLevel(playerid);

    for(new i; i < alevel; i++)
    {
        new level = i;
        format(string: tmpString, sizeof tmpString, "%s\n", Admin_GetRankNameFromLevel(level));
        strcat(string: ranks, string: tmpString);
    }

    Dialog_Show(playerid, "DIALOG_AHELP", DIALOG_STYLE_LIST,
        ""MAIN_COLOR"Blackland - "WHITE"Admin komande",
        string: ranks, "Ok", "Zatvori"
    );
    
    return 1;
}

acmd:[1]cc(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
    if (gettime() < adminChatCleared)
        return SendErrorMsg(playerid, "Chat se moze cistiti svakih 5 sekundi!");

    if (isnull(string: params))
        return SendSyntaxMsg(playerid, "/cc [broj linija]");

    if (!(10 <= strval(string: params) <= 60))
        return SendErrorMsg(playerid, "Ne mozete ispod 10 i iznad 60 linija!");

    foreach(new i: Player)
        Player_ClearChat(i, strval(string: params));

    Admin_SendMessage(ADMIN_CHAT_COLOR, "[ADMIN]: %s je ocistio chat.", ReturnPlayerName(playerid));
    adminChatCleared = (gettime() + 5);

    return 1;
}

acmd:[1]zaledi(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
    if (isnull(string: params))
        return SendSyntaxMsg(playerid, "/zaledi [id igraca]");

    if (!IsPlayerConnected(strval(string: params)))
        return 0;

    if (Bit_Get(Bit: Bit_PlayerFreezed, strval(string: params)))
        return SendErrorMsgF(playerid, "Igrac %s je vec zaledjen!", ReturnPlayerName(strval(string: params)));

    TogglePlayerControllable(strval(string: params), 0);
    Bit_Let(Bit: Bit_PlayerFreezed, strval(string: params));
    
    SendInfoMsgToAllF("Admin %s je zaledio igraca %s.", ReturnPlayerName(playerid), ReturnPlayerName(strval(string: params)));

    return 1;
}

acmd:[1]odledi(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
    if (isnull(string: params))
        return SendSyntaxMsg(playerid, "/odledi [id igraca]");

    if (!IsPlayerConnected(strval(string: params)))
        return 0;

    if (!Bit_Get(Bit: Bit_PlayerFreezed, strval(string: params)))
        return SendErrorMsgF(playerid, "Igrac %s nije zaledjen!", ReturnPlayerName(strval(string: params)));

    TogglePlayerControllable(strval(string: params), 1);
    Bit_Set(Bit: Bit_PlayerFreezed, strval(string: params), false);
    
    SendInfoMsgToAllF("Admin %s je odledio igraca %s.", ReturnPlayerName(playerid), ReturnPlayerName(strval(string: params)));

    return 1;
}

acmd:[1]ubij(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
    if (isnull(string: params))
        return SendSyntaxMsg(playerid, "/ubij [id igraca]");

    if (!IsPlayerConnected(strval(string: params)))
        return 0;

    if (Admin_GetLevel(strval(string: params)))
        return SendErrorMsg(playerid, "Ne mozes ubiti admina!");

    SetPlayerHealth(strval(string: params), Float: 0.0);
    SendInfoMsgToAllF("Admin %s je ubio igraca %s.", ReturnPlayerName(playerid), ReturnPlayerName(strval(string: params)));

    return 1;
}

acmd:[1]osamari(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
    if (isnull(string: params))
        return SendSyntaxMsg(playerid, "/osamari [id igraca]");

    if (!IsPlayerConnected(strval(string: params)))
        return 0;

    static x, y, z;
    GetPlayerPos(strval(string: params), Float: x, Float: y, Float: z);
    SetPlayerPos(strval(string: params), Float: x, Float: y, (Float: z + 2.0));

    SendInfoMsgToAllF("Admin %s je osamario igraca %s.", ReturnPlayerName(playerid), ReturnPlayerName(strval(string: params)));

    return 1;
}

acmd:[1]goto(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
    if (isnull(string: params))
        return SendSyntaxMsg(playerid, "/goto [id igraca]");

    if (!IsPlayerConnected(strval(string: params)))
        return 0;

    static x, y, z;
    GetPlayerPos(strval(string: params), Float: x, Float: y, Float: z);
    SetPlayerPos(playerid, Float: x, Float: y, Float: z);

    SendServerMsgF(strval(string: params), "Admin %s se teleportovao do Vas.", ReturnPlayerName(playerid));
    SendServerMsgF(playerid, "Teleportovali ste se do igraca %s.", ReturnPlayerName(strval(string: params)));

    Admin_SendMessage(ADMIN_CHAT_COLOR, "[ADMIN]: %s se teleportovao do %s.",
        ReturnPlayerName(playerid), ReturnPlayerName(strval(string: params))
    );

    return 1;
}

acmd:[1]gethere(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
    if (isnull(string: params))
        return SendSyntaxMsg(playerid, "/gethere [id igraca]");

    if (!IsPlayerConnected(strval(string: params)))
        return 0;

    static x, y, z;
    GetPlayerPos(playerid, Float: x, Float: y, Float: z);
    SetPlayerPos(strval(string: params), Float: x, Float: y, Float: z);

    SendServerMsgF(strval(string: params), "Admin %s Vas je teleportovao do sebe.", ReturnPlayerName(playerid));
    SendServerMsgF(playerid, "Teleportovali ste igraca %s do sebe.", ReturnPlayerName(strval(string: params)));

    Admin_SendMessage(ADMIN_CHAT_COLOR, "[ADMIN]: %s je teleportovao %s do sebe.",
        ReturnPlayerName(playerid), ReturnPlayerName(strval(string: params))
    );

    return 1;
}

acmd:[1]kick(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
    static
        targetid,
        string: reason[MAX_REASON_LENGTH];

    if (sscanf(string: params, "rs["#MAX_REASON_LENGTH"]", targetid, string: reason))
        return SendSyntaxMsg(playerid, "/kick [id igraca] [razlog]");

    if (!IsPlayerConnected(targetid))
        return 0;

    if (Admin_GetLevel(targetid) && Admin_GetLevel(playerid) != MAX_ADMIN_LEVEL)
        return SendErrorMsg(playerid, "Samo vlasnik moze kikovati admina!");

    GameTextForPlayer(targetid, "~r~KICKED", 10000, 3);
    Kick(targetid);

    SendInfoMsgToAllF("Igrac %s je kikovan zbog %s.", ReturnPlayerName(targetid), string: reason);

    return 1;
}

acmd:[1]ban(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");

    static
        targetid,
        string: reason[MAX_REASON_LENGTH];

    if (sscanf(string: params, "rs["#MAX_REASON_LENGTH"]", targetid, string: reason))
        return SendSyntaxMsg(playerid, "/ban [id igraca] [razlog]");

    if (!IsPlayerConnected(targetid))
        return 0;

    Ban_Player(targetid, playerid, string: reason);

    return 1;
}

acmd:[1]postaviskin(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");

    static
        targetid,
        skinid;
    
    if (sscanf(string: params, "ri", targetid, skinid))
        return SendSyntaxMsg(playerid, "/postaviskin [id igraca] [id skina]");

    if (!IsPlayerConnected(targetid))
        return 0;

    if (!(1 <= skinid <= 311))
        return SendErrorMsg(playerid, "Ne mozete ispod 1 i iznad 311!");

    Account_SetPlayerSkin(targetid, skinid);

    SendServerMsgF(targetid, "Admin %s Vam je postavio skin na %d.", ReturnPlayerName(playerid), skinid);
    SendServerMsgF(playerid, "Postavili ste igracu %s skin na %d.", ReturnPlayerName(targetid), skinid);

    Admin_SendMessage(ADMIN_CHAT_COLOR, "[ADMIN]: %s je postavio %s skin id na %d.",
        ReturnPlayerName(playerid), ReturnPlayerName(strval(string: params)), skinid
    );

    return 1;
}

acmd:[1]aduty(playerid, const string: params[])
{
    if (Admin_GetDutyStatus(playerid))
    {
        Admin_SetDutyStatus(playerid, false);
        SetPlayerHealth(playerid, Float: 99.0);

        SendInfoMsgToAllF("Administrator %s vise nije na duznosti.", ReturnPlayerName(playerid));
        return 1;
    }

    Dialog_Show(playerid, "DIALOG_ACODE", DIALOG_STYLE_INPUT,
        ""MAIN_COLOR"Blackland - "WHITE"Admin kod",
        ""MAIN_COLOR"%s "WHITE"Vi ste admin level %d na ovom serveru.\n\
        Unesite Vas admin kod za nastavak:", ""MAIN_COLOR"Unesi", "Izlaz",
        ReturnPlayerName(playerid), Admin_GetLevel(playerid)
    );

    return 1;
}

acmd:[1]gotodiler(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");

    if (isnull(string: params))
        return SendSyntaxMsg(playerid, "/gotodiler [id dilera]");

    Dealer_Goto(playerid, strval(string: params));

    return 1;
}

acmd:[1]fixveh(playerid, const string: params[])
{
    if (isnull(string: params))
        return SendSyntaxMsg(playerid, "/fixveh [targetid]");

    if (!IsPlayerConnected(strval(string: params)))
        return 0;

    if (!IsPlayerInAnyVehicle(strval(string: params)))
        return SendErrorMsg(playerid, "Taj igrac nije u vozilu!");

    RepairVehicle(GetPlayerVehicleID(strval(string: params)));
    SetVehicleHealth(GetPlayerVehicleID(strval(string: params)), Float: 1000.0);

    SendInfoMsgToAllF("Admin %s je popravio vozilo igracu %s.", ReturnPlayerName(playerid), ReturnPlayerName(strval(string: params)));

    return 1;
}

acmd:[1]a(playerid, const string: params[])
{
    if (isnull(string: params))
        return SendSyntaxMsg(playerid, "/a [tekst]");

    Admin_SendMessage(X11_RED, "[A]: %s "WHITE"%s(%d): %s",
        Admin_GetRankNameFromLevel(Admin_GetLevel(playerid) - 1), ReturnPlayerName(playerid), playerid, string: params
    );

    return 1;
}