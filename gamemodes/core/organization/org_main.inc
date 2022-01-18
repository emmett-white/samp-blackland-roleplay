#if defined _inc_org_main
    #undef _inc_org_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _org_main_included
    #endinput
#endif
#define _org_main_included

// ---
// Variables
// ---
const
    ORGANIZATION_NONE =     (0),
    ORGANIZATION_LSPD =     (1);

static
    orgPlayerID[MAX_PLAYERS],
    orgPlayerLeader[MAX_PLAYERS];

// ---
// Get/Set functions
// ---
stock Organization_SetPlayerOrgID(const playerid, const orgid, bool: leader = false)
{
    orgPlayerID[playerid] = orgid;
    orgPlayerLeader[playerid] = (!leader ? (0): (1));

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_orgid = '%d', char_leader = '%d' WHERE char_id = '%d'",
        Organization_GetPlayerOrgID(playerid), Organization_IsPlayerLeader(playerid),
        Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Organization_SetPlayerLeader(const playerid, const status)
{
    orgPlayerLeader[playerid] = (!status ? (0): (1));

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_leader = '%d' WHERE char_id = '%d'",
        Organization_IsPlayerLeader(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Organization_GetPlayerOrgID(const playerid) return orgPlayerID[playerid];
stock Organization_IsPlayerLeader(const playerid) return orgPlayerLeader[playerid];

// ---
// Return org IDs
// ---
stock Organization_NONE() return ORGANIZATION_NONE;
stock Organization_LSPD() return ORGANIZATION_LSPD;

// ---
// Call modules
// ---
#include <org_lspd>