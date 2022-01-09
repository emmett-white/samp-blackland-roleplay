#if defined _inc_account_variables
    #undef _inc_account_variables
#endif
// custom include-guard to ensure we don't duplicate
#if defined _account_variables_included
    #endinput
#endif
#define _account_variables_included

/** Variables */
new
    accountUniqueID[MAX_PLAYERS],
    accountCharUniqueID[MAX_PLAYERS],
    accountSex[MAX_PLAYERS] = -1,

    string: accountPassword[MAX_PLAYERS][MAX_PASSWORD_LENGTH],
    string: accountEmail[MAX_PLAYERS][128];

#define Account_GetPlayerUniqueID(%0) accountUniqueID[%0]
#define Account_GetPlayerCharUniqueID(%0) accountCharUniqueID[%0]
#define Account_GetPlayerPassword(%0) accountPassword[%0]

static
    accountMoney[MAX_PLAYERS],
    accountSkin[MAX_PLAYERS],
    accountLevel[MAX_PLAYERS],
    accountGold[MAX_PLAYERS],
    accountBankMoney[MAX_PLAYERS],
    accountBankAccount[MAX_PLAYERS],
    accountGunLicense[MAX_PLAYERS],
    accountIDCard[MAX_PLAYERS],
    accountDrugs[MAX_PLAYERS],
    accountWeed[MAX_PLAYERS],
    accountHouse[MAX_PLAYERS];

/** Get/Set functions */
stock Account_GetPlayerMoney(const playerid) return accountMoney[playerid];
stock Account_GetPlayerSkin(const playerid) return accountSkin[playerid];
stock Account_GetPlayerLevel(const playerid) return accountLevel[playerid];
stock Account_GetPlayerEmail(const playerid) return string: accountEmail[playerid];
stock Account_GetPlayerGold(const playerid) return accountGold[playerid];
stock Account_GetPlayerBankMoney(const playerid) return accountBankMoney[playerid];
stock Account_GetPlayerBankAccount(const playerid) return accountBankAccount[playerid];
stock Account_GetPlayerGunLicense(const playerid) return accountGunLicense[playerid];
stock Account_GetPlayerIDCard(const playerid) return accountIDCard[playerid];
stock Account_GetPlayerDrugs(const playerid) return accountDrugs[playerid];
stock Account_GetPlayerWeed(const playerid) return accountWeed[playerid];
stock Account_GetPlayerHouse(const playerid) return accountHouse[playerid];

stock Account_SetPlayerPassword(const playerid, const string: password[] = "N/A")
{
    strcopy(string: accountPassword[playerid], string: password);

    new String: str_query_update = String: str_format(
        "UPDATE accounts SET account_password = '%e' WHERE account_id = '%d'",
        Account_GetPlayerPassword(playerid), Account_GetPlayerUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerEmail(const playerid, const string: address[] = "N/A")
{
    strcopy(string: accountEmail[playerid], string: address);

    new String: str_query_update = String: str_format(
        "UPDATE accounts SET account_email = '%e' WHERE account_id = '%d'",
        Account_GetPlayerEmail(playerid), Account_GetPlayerUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerMoney(const playerid, const value)
{
    accountMoney[playerid] = value;

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_money = '%d' WHERE char_id = '%d'",
        Account_GetPlayerMoney(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerSkin(const playerid, const value)
{
    accountSkin[playerid] = value;
    SetPlayerSkin(playerid, value);

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_skin = '%d' WHERE char_id = '%d'",
        Account_GetPlayerSkin(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerLevel(const playerid, const value)
{
    accountLevel[playerid] = value;
    va_PlayerTextDrawSetString(playerid, PlayerText: UI_ReturnInGameStatsTextDraw(playerid, 1),
        "~b~LEVEL: ~w~%d", Account_GetPlayerLevel(playerid)
    );

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_level = '%d' WHERE char_id = '%d'",
        Account_GetPlayerLevel(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerGold(const playerid, const value)
{
    accountGold[playerid] = value;
    va_PlayerTextDrawSetString(playerid, PlayerText: UI_ReturnInGameStatsTextDraw(playerid, 0),
        "~y~ZLATO: ~w~%dG", Account_GetPlayerGold(playerid)
    );

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_gold = '%d' WHERE char_id = '%d'",
        Account_GetPlayerGold(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerBankMoney(const playerid, const value)
{
    accountBankMoney[playerid] = value;
    va_PlayerTextDrawSetString(playerid, PlayerText: UI_ReturnInGameStatsTextDraw(playerid, 1),
        "~g~BANKA: $~w~%d", Account_GetPlayerBankMoney(playerid)
    );

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_bankmoney = '%d' WHERE char_id = '%d'",
        Account_GetPlayerBankMoney(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerBankAccount(const playerid, const value)
{
    accountBankAccount[playerid] = value;

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_bankaccount = '%d' WHERE char_id = '%d'",
        Account_GetPlayerBankAccount(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerGunLicense(const playerid, const value)
{
    accountGunLicense[playerid] = value;

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_gunlicense = '%d' WHERE char_id = '%d'",
        Account_GetPlayerGunLicense(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerName(const playerid, const string: name[])
{
    new String: str_query_update;
    
    str_query_update = String: str_format(
        "UPDATE accounts SET account_name = '%e' WHERE account_id = '%d'",
        string: name, Account_GetPlayerUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    str_query_update = String: str_format(
        "UPDATE characters SET char_name = '%e' WHERE char_id = '%d'",
        string: name, Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerIDCard(const playerid, const value)
{
    accountIDCard[playerid] = value;

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_idcard = '%d' WHERE char_id = '%d'",
        Account_GetPlayerIDCard(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerDrugs(const playerid, const value)
{
    accountDrugs[playerid] = value;

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_drugs = '%d' WHERE char_id = '%d'",
        Account_GetPlayerDrugs(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerWeed(const playerid, const value)
{
    accountWeed[playerid] = value;

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_weed = '%d' WHERE char_id = '%d'",
        Account_GetPlayerWeed(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Account_SetPlayerHouse(const playerid, const value)
{
    accountHouse[playerid] = value;

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_house = '%d' WHERE char_id = '%d'",
        Account_GetPlayerHouse(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}