#if defined _inc_account_callbacks
    #undef _inc_account_callbacks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _account_callbacks_included
    #endinput
#endif
#define _account_callbacks_included

forward Account_InsertAccountID(const playerid); public Account_InsertAccountID(const playerid)
{
    accountUniqueID[playerid] = cache_insert_id();
    return 1;
}

forward Account_InsertCharID(const playerid); public Account_InsertCharID(const playerid)
{
    accountCharUniqueID[playerid] = cache_insert_id();
    return 1;
}