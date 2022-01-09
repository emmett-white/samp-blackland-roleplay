#if defined _inc_house_hooks
    #undef _inc_house_hooks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _house_hooks_included
    #endinput
#endif
#define _house_hooks_included

#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_tquery(MySQL: MySQL_GetHandle(), "SELECT * FROM houses", "House_Load");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterCheckpoint(playerid)
{
    House_DestroyCheckpoint(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}