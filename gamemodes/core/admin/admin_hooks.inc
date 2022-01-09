#if defined _inc_admin_hooks
    #undef _inc_admin_hooks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_hooks_included
    #endinput
#endif
#define _admin_hooks_included

#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    Admin_AddCommandToList(1, "/ban");
    Admin_AddCommandToList(1, "/kick");
    Admin_AddCommandToList(1, "/ubij");
    Admin_AddCommandToList(1, "/osamari");
    Admin_AddCommandToList(1, "/zaledi");
    Admin_AddCommandToList(1, "/odledi");
    Admin_AddCommandToList(1, "/goto");
    Admin_AddCommandToList(1, "/gethere");
    Admin_AddCommandToList(1, "/postaviskin");
    Admin_AddCommandToList(1, "/gotodiler");
    Admin_AddCommandToList(1, "/a");
    Admin_AddCommandToList(1, "/fixveh");

    Admin_AddCommandToList(2, "/unban");
    Admin_AddCommandToList(2, "/podesivreme");
    Admin_AddCommandToList(2, "/podesisate");
    Admin_AddCommandToList(2, "/mutiraj");
    Admin_AddCommandToList(2, "/odmutiraj");

    Admin_AddCommandToList(3, "/offban");
    
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/postpaviadmina");
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/postavilevel");
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/postavinovac");
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/dajnovac");
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/postavilidera");
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/promeniime");
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/kreirajdilera");
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/kreirajaktora");
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/kreirajkucu");
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/obrisikucu");
    Admin_AddCommandToList(MAX_ADMIN_LEVEL, "/prodajsvekuce");

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if (Admin_GetVehicleSpawned(playerid))
    {
        Admin_DestroyVehicle(playerid);
    }

    static disconnectReason[3][] =
    {
        "Crash",
        "Dobrovoljno",
        "Kick/Ban"
    };

    Admin_SendMessage(ADMIN_CHAT_COLOR, "[ADMIN]: %s je napustio server. Razlog: %s",
        ReturnPlayerName(playerid), disconnectReason[reason]
    );
    printf("[ADMIN]: %s je napustio server. Razlog: %s",
        ReturnPlayerName(playerid), disconnectReason[reason]
    );

    return Y_HOOKS_CONTINUE_RETURN_1;
}