#if defined _inc_admin_commands_4
    #undef _inc_admin_commands_4
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_commands_4_included
    #endinput
#endif
#define _admin_commands_4_included

acmd:[4 && !IsPlayerAdmin(playerid)]postaviadmina(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
    {
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    }
    
    static
        targetid,
        level;
    
    if (sscanf(string: params, "ri", targetid, level))
    {
        return SendSyntaxMsg(playerid, "/postaviadmina [id igraca] [level]");
    }

    if (!IsPlayerConnected(targetid))
    {
        return 0;
    }

    Admin_SetLevel(targetid, playerid, level);

    return 1;
}

acmd:[4]postavilevel(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
    {
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    }
    
    static
        targetid,
        level;

    if (sscanf(string: params, "ri", targetid, level))
    {
        return SendSyntaxMsg(playerid, "/postavilevel [id igraca] [level]");
    }

    if (!IsPlayerConnected(targetid))
    {
        return 0;
    }

    if (!(1 <= level <= 1000))
    {
        return SendErrorMsg(playerid, "Ne mozete ispod 1 i iznad 1.000!");
    }

    Account_SetPlayerLevel(targetid, level);
    SetPlayerScore(targetid, level);
    SendInfoMsgToAllF("Admin %s je postavio level %d igracu %s.", ReturnPlayerName(playerid), level, ReturnPlayerName(targetid));

    return 1;
}

acmd:[4]postavinovac(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
    {
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    }

    static
        targetid,
        money;

    if (sscanf(string: params, "ri", targetid, money))
    {
        return SendSyntaxMsg(playerid, "/postavinovac [id igraca] [novac]");
    }

    if (!IsPlayerConnected(targetid))
    {
        return 0;
    }

    Account_SetPlayerMoney(targetid, money);
    ResetPlayerMoney(targetid);
    GivePlayerMoney(targetid, money);
    SendInfoMsgToAllF("Admin %s je postavio novac igracu %s na $%d.", ReturnPlayerName(playerid), ReturnPlayerName(targetid), money);

    return 1;
}

acmd:[4]dajnovac(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
    {
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    }

    static
        targetid,
        money;

    if (sscanf(string: params, "ri", targetid, money))
    {
        return SendSyntaxMsg(playerid, "/dajnovac [id igraca] [novac]");
    }

    if (!IsPlayerConnected(targetid))
    {
        return 0;
    }

    Account_SetPlayerMoney(targetid, (Account_GetPlayerMoney(targetid) + money));
    GivePlayerMoney(targetid, money);
    SendInfoMsgToAllF("Admin %s je dao $%d igracu %s.", ReturnPlayerName(playerid), money, ReturnPlayerName(targetid));

    return 1;
}

acmd:[4]promeniime(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
    {
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    }

    static
        targetid,
        string: name[MAX_PLAYER_NAME];

    if (sscanf(string: params, "rs[25]", targetid, string: name))
    {
        return SendSyntaxMsg(playerid, "/promeniime [id igraca] [novo ime]");
    }

    if (!IsPlayerConnected(targetid))
    {
        return 0;
    }

    if (!strcmp(string: name, ReturnPlayerName(targetid), false))
    {
        return SendErrorMsg(playerid, "Taj igrac ima vec takvo ime!");
    }

    Account_SetPlayerName(targetid, string: name);
    SendInfoMsgToAllF("Admin %s je promenio ime igracu %s u %s.", ReturnPlayerName(playerid), ReturnPlayerName(targetid), string: name);
    SetPlayerName(targetid, string: name);

    return 1;
}

acmd:[4]postavilidera(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
    {
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    }

    Dialog_Show(playerid, "DIALOG_MAKELEADER", DIALOG_STYLE_INPUT,
        ""MAIN_COLOR"Blackland - "WHITE"Lider",
        ""MAIN_COLOR"Organizacije:\n"WHITE"0. Skini lidera\n1. Policija\n2. Bice dodato...\n\
        Unesite ID igraca i broj: ", ""MAIN_COLOR"Potvrdi", "Izlaz"
    );

    return 1;
}

acmd:[4]kreirajdilera(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
    {
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    }

    static
        skin,
        x, y, z, a,
        string: name[MAX_PLAYER_NAME];

    if (sscanf(string: params, "is[25]", skin, string: name))
    {
        return SendSyntaxMsg(playerid, "/kreirajdilera [skin] [ime dilera]");
    }

    GetPlayerPos(playerid, Float: x, Float: y, Float: z);
    GetPlayerFacingAngle(playerid, Float: a);
    Dealer_Create(skin, string: name, Float: x, Float: y, Float: z, Float: a);

    return 1;
}

acmd:[4]kreirajaktora(playerid, const string: params[])
{
    Dialog_Show(playerid, "DIALOG_ACTORSKIN", DIALOG_STYLE_INPUT,
        ""MAIN_COLOR"Blackland - "WHITE"Aktor",
        ""MAIN_COLOR"INFO: "WHITE"Unesite skin aktora:",
        ""MAIN_COLOR"Unesi", "Izlaz"
    );

    return 1;
}

acmd:[4]kreirajkucu(playerid, const string: params[])
{
    new
        x, y, z,
        houseid = House_GetNextID();

    if (houseid == House_GetMaxHouses())
    {
        return SendErrorMsg(playerid, "Dostignut je maksimalan broj kuca!");
    }

    if (isnull(string: params) || !IsNumeric(string: params))
    {
        return SendSyntaxMsg(playerid, "/kreirajkucu [cena]");
    }

    GetPlayerPos(playerid, Float: x, Float: y, Float: z);
    House_Create(playerid, houseid, strval(string: params), Float: x, Float: y, Float: z);

    new String: str_query_insert = String: str_format(
        "INSERT INTO houses (house_id, house_owner, house_extx, house_exty, house_extz, house_desc, house_price) \
        VALUES ('%d', 'Niko', '%f', '%f', '%f', 'Na prodaju', '%d')", (houseid + 1), Float: x, Float: y, Float: z, strval(string: params)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_insert);

    return 1;
}

acmd:[4]obrisikucu(playerid, const string: params[])
{
    new houseid = House_GetNearby(playerid);
    if (houseid == House_GetMaxHouses())
    {
        return SendErrorMsg(playerid, "Morate biti blizu neke kuce!");
    }

    House_Delete(playerid, houseid);

    new String: str_query_delete = String: str_format(
        "DELETE FROM houses WHERE house_id = '%d'", (houseid + 1)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_delete);

    return 1;
}

alias:prodajsvekuce("prodajkuce")
acmd:[4]prodajsvekuce(playerid, const string: params[])
{
    House_SellAll();

    foreach (new i: Player)
    {
        Account_SetPlayerHouse(i, -1);
    }

    SendInfoMsgToAllF("Sve kuce su prodate!");
    SendInfoMsg(playerid, "Prodali ste sve kuce na ovom serveru!");

    return 1;
}