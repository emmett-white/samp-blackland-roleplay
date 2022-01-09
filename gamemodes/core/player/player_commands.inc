#if defined _inc_player_commands
    #undef _inc_player_commands
#endif
// custom include-guard to ensure we don't duplicate
#if defined _player_commands_included
    #endinput

#endif
#define _player_commands_included

static
    BitArray: Bit_PoliceDuty<MAX_PLAYERS>,

    gInvitedFrom[MAX_PLAYERS],
    gInvitedPlayer[MAX_PLAYERS],
    
    bool: gInvitedStatus[MAX_PLAYERS];

cmd:promenilozinku(playerid, const string: params[])
{
    if (isnull(string: params))
    {
        return SendSyntaxMsg(playerid, "/promenilozinku [new password]");
    }

    if (!(MIN_PASSWORD_LENGTH <= strlen(string: params) <= MAX_PASSWORD_LENGTH))
    {
        return SendErrorMsg(playerid, "Prekratka ili predugacka lozinka!");
    }

    if (!strcmp(string: params, Account_GetPlayerPassword(playerid), false))
    {
        return SendErrorMsg(playerid, "Nova lozinka ne moze biti ista kao stara!");
    }

    Account_SetPlayerPassword(playerid, string: params);
    SendServerMsgF(playerid, "Vasa nova lozinka je %s.", Account_GetPlayerPassword(playerid));

    return 1;
}

cmd:kupizlato(playerid, const string: params[])
{
    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 193.3017, Float: 1850.3898, Float: 994.3726))
    {
        return SendErrorMsg(playerid, "Niste kod meste gde se kupuje zlato!");
    }

    static tmpprice;
    tmpprice = Random(MIN_GOLD_PRICE, MAX_GOLD_PRICE);

    if (Account_GetPlayerMoney(playerid) < MIN_GOLD_PRICE && !GetPlayerMoney(playerid))
    {
        return SendErrorMsg(playerid, "Nemate dovoljno novca za jedan zlatnik!");
    }
    
    Account_SetPlayerMoney(playerid, (Account_GetPlayerMoney(playerid) - tmpprice));
    Account_SetPlayerGold(playerid, (Account_GetPlayerGold(playerid) + 1));
    GivePlayerMoney(playerid, -tmpprice);
    
    SendServerMsgF(playerid, "Kupili ste jedan zlatnik za $%d.", tmpprice);

    return 1;
}

cmd:prodajzlato(playerid, const string: params[])
{
    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 193.3422, Float: 1852.8479, Float: 994.3726))
    {
        return SendErrorMsg(playerid, "Niste kod meste gde se prodaje zlato!");
    }

    static tmpprice;
    tmpprice = Random(500, 8000);

    if (!Account_GetPlayerGold(playerid))
    {
        return SendErrorMsg(playerid, "Nemate ni jedan zlatnik!");
    }
    
    Account_SetPlayerMoney(playerid, (Account_GetPlayerMoney(playerid) + tmpprice));
    Account_SetPlayerGold(playerid, (Account_GetPlayerGold(playerid) - 1));
    GivePlayerMoney(playerid, tmpprice);
    
    SendServerMsgF(playerid, "Prodali ste jedan zlatnik za $%d.", tmpprice);

    return 1;
}

cmd:otvoriracun(playerid, const string: params[])
{
    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1425.9658, Float: -977.8441, Float: 996.1050))
    {
        return SendErrorMsg(playerid, "Niste kod saltera za otvaranje bankovnog racuna!");
    }

    if (Account_GetPlayerBankAccount(playerid))
    {
        return SendErrorMsg(playerid, "Vec imate otvoren bankovni racun!");
    }

    Account_SetPlayerBankAccount(playerid, 1);
    SendServerMsg(playerid, "Uspesno ste otvorili bankovni racun.");

    return 1;
}

cmd:ostavinovac(playerid, const string: params[])
{
    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1425.7939, Float: -973.4025, Float: 996.1050))
    {
        return SendErrorMsg(playerid, "Niste kod saltera za ostavljanje novca u banku!");
    }

    if (!Account_GetPlayerMoney(playerid))
    {
        return SendErrorMsg(playerid, "Nemate novac kod sebe!");
    }

    Dialog_Show(playerid, "DIALOG_LEAVEMONEY", DIALOG_STYLE_INPUT,
        ""MAIN_COLOR"Blackland - "WHITE"Banka",
        ""MAIN_COLOR"%s "WHITE"unesite kolicinu novca koju zelite da ostavite u banku:",
        ""MAIN_COLOR"Ostavi", "Izlaz", ReturnPlayerName(playerid)
    );

    return 1;
}

cmd:podigninovac(playerid, const string: params[])
{
    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1425.7753, Float: -975.6477, Float: 996.1050))
    {
        return SendErrorMsg(playerid, "Niste kod saltera za podizanje novca!");
    }

    if (!Account_GetPlayerBankMoney(playerid))
    {
        return SendErrorMsg(playerid, "Nemate novac u banci!");
    }

    Dialog_Show(playerid, "DIALOG_TAKEMONEY", DIALOG_STYLE_INPUT,
        ""MAIN_COLOR"Blackland - "WHITE"Banka",
        ""MAIN_COLOR"%s "WHITE"unesite kolicinu novca koju zelite da podignete iz banke:",
        ""MAIN_COLOR"Podigni", "Izlaz", ReturnPlayerName(playerid)
    );

    return 1;
}

cmd:oruzijedozvola(playerid, const string: params[])
{
    if (Account_GetPlayerGunLicense(playerid))
    {
        return SendErrorMsg(playerid, "Vec imate dozvolu za oruzije!");
    }

    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: -3.5446, Float: 2688.2627, Float: -44.0646))
    {
        return SendErrorMsg(playerid, "Niste na mestu gde se kupuje dozvola za oruzije!");
    }

    if (Account_GetPlayerMoney(playerid) < 500)
    {
        return SendErrorMsg(playerid, "Nemate dovoljno novca!");
    }

    SendServerMsg(playerid, "Uspesno ste kupili dozvolu za oruzije.");
    GivePlayerMoney(playerid, -500);

    Account_SetPlayerGunLicense(playerid, 1);
    Account_SetPlayerMoney(playerid, (Account_GetPlayerMoney(playerid) - 500));
    
    return 1;
}

cmd:pdduznost(playerid, const string: params[])
{
    if (Organization_GetPlayerOrgID(playerid) != Organization_LSPD())
    {
        return SendErrorMsg(playerid, "Samo pripadnici policije!");
    }

    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: -6.0534, Float: 2660.2209, Float: -49.2784))
    {
        return SendErrorMsg(playerid, "Niste na mestu za uzimanje duznosti!");
    }

    if (Bit_Get(Bit: Bit_PoliceDuty, playerid))
    {
        Bit_Set(Bit: Bit_PoliceDuty, playerid, false);

        SendInfoMsg(playerid, "Skinuli ste duznost.");
        SendInfoMsgToAllF("Policajac %s vise nije na duznosti.", ReturnPlayerName(playerid));
        
        ResetPlayerWeapons(playerid);
        SetPlayerSkin(playerid, Account_GetPlayerSkin(playerid));
        return 1;
    }

    Bit_Let(Bit: Bit_PoliceDuty, playerid);
    
    SendInfoMsg(playerid, "Sada ste na duznosti.");
    SendInfoMsgToAllF("Policajac %s je na duznosti.", ReturnPlayerName(playerid));

    SetPlayerSkin(playerid, 280);
    GivePlayerWeapon(playerid, 3, 1);
    GivePlayerWeapon(playerid, 22, cellmax);
    GivePlayerWeapon(playerid, 29, cellmax);
    GivePlayerWeapon(playerid, 41, cellmax);

    return 1;
}

cmd:ubaciclana(playerid, const string: params[])
{
    if (isnull(params))
    {
        return SendSyntaxMsg(playerid, "/ubaciclana [targetid]");
    }

    if (!IsPlayerConnected(strval(string: params)))
    {
        return 0;
    }

    if (Organization_GetPlayerOrgID(strval(string: params)) != Organization_NONE())
    {
        return SendErrorMsg(playerid, "Taj igrac je vec pozvan ili je u nekoj organizaciji!");
    }

    if (Organization_GetPlayerOrgID(strval(string: params)) == Organization_GetPlayerOrgID(playerid))
    {
        return SendErrorMsg(playerid, "Taj igrac je vec u toj organizaciji!");
    }

    static orgname[24];
    switch (Organization_GetPlayerOrgID(playerid))
    {
        case 1: { orgname = "Policija"; }
    }

    gInvitedFrom[strval(string: params)] = playerid;
    gInvitedStatus[strval(string: params)] = true;
    gInvitedPlayer[playerid] = strval(string: params);

    SendServerMsgF(playerid, "Pozvali ste igraca %s da se pridruzi Vasoj organizaciji.", ReturnPlayerName(strval(string: params)));
    SendServerMsgF(strval(string: params), "Lider %s Vas je pozvao da se pridruzite organizaciji %s.", ReturnPlayerName(playerid), string: orgname);
    SendServerMsg(strval(string: params), "Da se pridruzite kucajte /acceptinvite!");

    return 1;
}

cmd:prihvatipoziv(playerid, const string: params[])
{
    if (!gInvitedStatus[playerid])
    {
        return SendErrorMsg(playerid, "Lider nije tu ili Vas trenutno niko nije pozvao!");
    }

    SendServerMsgF(playerid, "Uspesno ste se pridruzili organizaciji. Lider: %s", ReturnPlayerName(gInvitedFrom[playerid]));
    SendServerMsgF(gInvitedFrom[playerid], "Igrac %s se pridruzio Vasoj organizaciji.", ReturnPlayerName(playerid));

    Organization_SetPlayerOrgID(playerid, Organization_GetPlayerOrgID(gInvitedFrom[playerid]));
    gInvitedStatus[gInvitedPlayer[playerid]] = false;

    return 1;
}

cmd:odbijpoziv(playerid, const string: params[])
{
    if (!gInvitedStatus[playerid])
    {
        return SendErrorMsg(playerid, "Lider nije tu ili Vas trenutno niko nije pozvao!");
    }

    SendServerMsg(playerid, "Odbili ste da se pridruzite toj organizaciji.");
    SendServerMsgF(gInvitedFrom[playerid], "Igrac %s je odbio da se pridruzi Vasoj organizaciji.", ReturnPlayerName(gInvitedPlayer[playerid]));

    gInvitedStatus[gInvitedPlayer[playerid]] = false;

    return 1;
}

cmd:izbaciclana(playerid, const string: params[])
{
    if (!Organization_IsPlayerLeader(playerid))
    {
        return SendErrorMsg(playerid, "Samo lideri!");
    }
    
    if (isnull(params))
    {
        return SendSyntaxMsg(playerid, "/izbaciclana [targetid]");
    }

    if (!IsPlayerConnected(strval(string: params)))
    {
        return 0;
    }

    if (Organization_GetPlayerOrgID(strval(string: params)) != Organization_GetPlayerOrgID(playerid))
    {
        return SendErrorMsg(playerid, "Taj igrac nije u Vasoj organizaciji!");
    }

    static orgname[24];
    switch (Organization_GetPlayerOrgID(playerid))
    {
        case 1: { orgname = "Policija"; }
    }

    SendServerMsgF(playerid, "Izbacili ste igraca %s iz Vase organizacije.", ReturnPlayerName(strval(string: params)));
    SendServerMsgF(strval(string: params), "Lider %s Vas je izbacio iz organizacije: %s.", ReturnPlayerName(playerid), string: orgname);

    Organization_SetPlayerOrgID(strval(string: params), Organization_NONE());
    gInvitedStatus[strval(string: params)] = false;
    
    return 1;
}

cmd:izvadilicnu(playerid, const string: params[])
{
    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1369.6998, Float: 715.6658, Float: -15.7573))
    {
        return SendErrorMsg(playerid, "Niste na mestu gde se vadi licna karta!");
    }

    if (Account_GetPlayerIDCard(playerid))
    {
        return SendErrorMsg(playerid, "Vec imate licnu kartu!");
    }

    Account_SetPlayerIDCard(playerid, 1);
    Account_SetPlayerMoney(playerid, (Account_GetPlayerMoney(playerid) - 50));
    
    GivePlayerMoney(playerid, - 50);
    SendServerMsg(playerid, "Uspesno ste izvadili licnu kartu!");

    return 1;
}

cmd:napustiorg(playerid, const string: params[])
{
    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1369.8857, Float: 724.9853, Float: -15.7573))
    {
        return SendErrorMsg(playerid, "Niste na mestu gde se napusta organizacija!");
    }

    if (Organization_GetPlayerOrgID(playerid) == Organization_NONE())
    {
        return SendErrorMsg(playerid, "Vi niste u organizaciji!");
    }

    static orgname[24];
    switch (Organization_GetPlayerOrgID(playerid))
    {
        case 1: { orgname = "Policija"; }
    }

    Organization_SetPlayerOrgID(playerid, Organization_NONE());
    SendServerMsgF(playerid, "Uspesno ste naputili organizaciju: %s", string: orgname);

    return 1;
}

cmd:diler(playerid, const string: params[])
{
    if (!Dealer_Nearby(playerid))
    {
        return SendErrorMsg(playerid, "Niste blizu dilera!");
    }

    if (!Account_GetPlayerMoney(playerid))
    {
        return SendErrorMsg(playerid, "Nemate dovoljno novca!");
    }

    UI_CreateDealerTextDraws(playerid);
    UI_CreateInGameTextDraws(playerid, false, false, false);

    ApplyActorAnimation(Dealer_NearbyID(playerid), "PED", "IDLE_chat", Float: 4.0, 1, 0, 0, 0, 0);

    return 1;
}

cmd:radio(playerid, const string: params[])
{
    Vehicle_SetRadioStatus(playerid, (!Vehicle_GetRadioStatus(playerid) ? (true) : (false)));

    return 1;
}

alias:stanica("radiostanica")
cmd:stanica(playerid, const string: params[])
{
    Vehicle_FindStation(playerid);

    return 1;
}

alias:winter("we")
cmd:winter(playerid, const string: params[])
{
    static string: tmpstr[5][40];
    strcopy(string: tmpstr[0], (Winter_GetSnowObjStatus(playerid) ? (""LIGHTGREEN"Ukljuceno") : (""DARKRED"Iskljuceno")));
    strcopy(string: tmpstr[1], (Winter_GetSnowflakeStatus(playerid) ? (""LIGHTGREEN"Ukljuceno") : (""DARKRED"Iskljuceno")));
    strcopy(string: tmpstr[2], (Winter_GetSnowCapStatus(playerid) ? (""LIGHTGREEN"Ukljuceno") : (""DARKRED"Iskljuceno")));
    strcopy(string: tmpstr[4], (Winter_GetColdBreathStatus(playerid) ? (""LIGHTGREEN"Ukljuceno") : (""DARKRED"Iskljuceno")));
    if (Winter_GetSnowObjStatus(playerid) && Winter_GetSnowflakeStatus(playerid) && Winter_GetSnowCapStatus(playerid) && Winter_GetColdBreathStatus(playerid))
    {
        strcopy(string: tmpstr[3], ""LIGHTGREEN"Iskljuci sve");
    }

    else
    {
        strcopy(string: tmpstr[3], ""DARKRED"Ukljuci sve");
    }

    Dialog_Show(playerid, "DIALOG_WINTER", DIALOG_STYLE_TABLIST_HEADERS,
        ""MAIN_COLOR"Blackland - "WHITE"Winter Edition",
        ""MAIN_COLOR"Opcija\t"MAIN_COLOR"Status\n\
        "WHITE"Sneg po mapi\t%s\n\
        "WHITE"Padanje snega\t%s\n\
        "WHITE"Kapica\t%s\n\
        "WHITE"Dah iz usta\t%s\n\
        "WHITE"%s",
        "Potvrdi", "Izlaz",
        string: tmpstr[0], string: tmpstr[1], string: tmpstr[2], string: tmpstr[4], string: tmpstr[3]
    );

    return 1;
}

cmd:kupikucu(playerid, const string: params[])
{
    if (Account_GetPlayerHouse(playerid) != -1)
    {
        return SendErrorMsg(playerid, "Vec imate kucu!");
    }

    new houseid = House_GetNearby(playerid);
    if (houseid == House_GetMaxHouses())
    {
        return SendErrorMsg(playerid, "Morate biti blizu neke kuce!");
    }

    if (House_HasOwner(houseid))
    {
        return SendErrorMsg(playerid, "Ta kuca nije na prodaju.");
    }

    if (Account_GetPlayerMoney(playerid) < House_GetPrice(houseid))
    {
        return SendErrorMsg(playerid, "Nemate dovoljno novca za ovu kucu!");
    }

    Account_SetPlayerHouse(playerid, houseid);
    Account_SetPlayerMoney(playerid, (Account_GetPlayerMoney(playerid) - House_GetPrice(houseid)));
    GivePlayerMoney(playerid, -House_GetPrice(houseid));
    House_Buy(playerid, houseid);

    new String: str_query_update = String: str_format(
        "UPDATE houses SET house_owned = '1', house_owner = '%e' WHERE house_id = '%d'",
        ReturnPlayerName(playerid), (houseid + 1)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

cmd:kuca(playerid, const string: params[])
{
    if (Account_GetPlayerHouse(playerid) == -1)
    {
        return SendErrorMsg(playerid, "Nemate kucu!");
    }

    new houseid = House_GetNearby(playerid);
    if (houseid == House_GetMaxHouses())
    {
        return SendErrorMsg(playerid, "Morate biti blizu kuce!");
    }

    if (strcmp(ReturnPlayerName(playerid), House_GetOwner(houseid)))
    {
        return SendErrorMsg(playerid, "Morate biti kod svoje kuce!");
    }

    static string: tmpstr[32];
    strcopy(string: tmpstr, (House_IsLocked(houseid) ? (""LIGHTGREEN"Otkljucaj") : (""DARKRED"Zakljucaj")));

    Dialog_Show(playerid, "DIALOG_HOUSEMENU", DIALOG_STYLE_LIST,
        ""MAIN_COLOR"Blackland - "WHITE"Kuca",
        "Komande za kucu\nPromeni opis kuce\n%s kucu\nProdaj kucu",
        ""MAIN_COLOR"Potvrdi", "Izlaz", string: tmpstr
    );

    return 1;
}

cmd:locirajkucu(playerid, const string: params[])
{
    if (!Player_HouseCPEnabled(playerid))
    {
        new houseid = Account_GetPlayerHouse(playerid);
        if (Account_GetPlayerHouse(playerid) == -1)
        {
            return SendErrorMsg(playerid, "Nemate kucu!");
        }

        House_SetPlayerCheckpoint(playerid, Float: House_GetPos(houseid, 0), Float: House_GetPos(houseid, 1), Float: House_GetPos(houseid, 2));
        SendServerMsg(playerid, "Locirali ste Vasu kucu.");
        Player_SetHouseCPStatus(playerid);
        return 1;
    }

    Player_SetHouseCPStatus(playerid, false);
    House_DestroyCheckpoint(playerid);

    return 1;
}