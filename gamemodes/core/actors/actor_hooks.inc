#if defined _inc_actor_hooks
    #undef _inc_actor_hooks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _actor_hooks_included
    #endinput
#endif
#define _actor_hooks_included

#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_tquery(MySQL: MySQL_GetHandle(), "SELECT * FROM actors", "Actor_Load");
    return Y_HOOKS_CONTINUE_RETURN_1;
}