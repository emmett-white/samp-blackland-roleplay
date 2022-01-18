#if defined _inc_mute_hooks
    #undef _inc_mute_hooks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _mute_hooks_included
    #endinput
#endif
#define _mute_hooks_included

#include <YSI_Coding\y_hooks>

hook OnPlayerText(playerid, text[])
{
    if (Mute_GetTime(playerid))
        return SendErrorMsgF(playerid,
            "Ne mozete pricati jer ste mutirani jos %d minut/a!", Mute_GetTime(playerid)
        ), 0;

    static string: str[YSI_MAX_STRING];

    format(string: str, sizeof str, "%s(%d): %s", ReturnPlayerName(playerid), playerid, string: text);
    Player_SendRadiusMsg(Float: 30.0, playerid, string: str, X11_WHITE, X11_WHITE, X11_LIGHTGRAY, X11_WHITE, X11_WHITE);

    return Y_HOOKS_CONTINUE_RETURN_0;
}