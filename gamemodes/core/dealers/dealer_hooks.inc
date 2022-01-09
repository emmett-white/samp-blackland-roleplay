#if defined _inc_dealer_hooks
    #undef _inc_dealer_hooks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _dealer_hooks_included
    #endinput
#endif
#define _dealer_hooks_included

#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    mysql_tquery(MySQL: MySQL_GetHandle(), "SELECT * FROM dealers", "Dealer_Load");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if (UI_DealerTextDrawCreated(playerid))
    {
        if (clickedid == INVALID_TEXT_DRAW)
        {
            UI_CreateDealerTextDraws(playerid, false);
            UI_CreateInGameTextDraws(playerid, true, true, true);
            ClearActorAnimations(Dealer_NearbyID(playerid));
        }
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if (playertextid == PlayerText: Dealer_ReturnTextDraw(playerid, 3))
    {
        UI_CreateDealerTextDraws(playerid, false);
        UI_CreateInGameTextDraws(playerid, true, true, true);
        ClearActorAnimations(Dealer_NearbyID(playerid));
    }
    
    else if (playertextid == PlayerText: Dealer_ReturnTextDraw(playerid, 8))
    {
        if (GetPlayerMoney(playerid) < 50)
        {
            SendErrorMsg(playerid, "Nemate dovoljno novca!");
            return 1;
        }

        Account_SetPlayerDrugs(playerid, (Account_GetPlayerDrugs(playerid) + 1));
        Account_SetPlayerMoney(playerid, (Account_GetPlayerMoney(playerid) - 50));
        
        GivePlayerMoney(playerid, -50);
        SendServerMsg(playerid, "Kupili ste kokain za $50!");
        SendServerMsgF(playerid, "Ukupno kokaina: %d", Account_GetPlayerDrugs(playerid));
    }

    else if (playertextid == PlayerText: Dealer_ReturnTextDraw(playerid, 9))
    {
        if (GetPlayerMoney(playerid) < 65)
        {
            SendErrorMsg(playerid, "Nemate dovoljno novca!");
            return 1;
        }

        Account_SetPlayerMoney(playerid, (Account_GetPlayerMoney(playerid) - 65));
        
        GivePlayerMoney(playerid, -65);
        GivePlayerWeapon(playerid, 24, 20);
        SendServerMsg(playerid, "Kupili ste digl za $65!");
    }

    else if (playertextid == PlayerText: Dealer_ReturnTextDraw(playerid, 10))
    {
        if (GetPlayerMoney(playerid) < 50)
        {
            SendErrorMsg(playerid, "Nemate dovoljno novca!");
            return 1;
        }

        Account_SetPlayerWeed(playerid, (Account_GetPlayerWeed(playerid) + 1));
        Account_SetPlayerMoney(playerid, (Account_GetPlayerMoney(playerid) - 25));
        
        GivePlayerMoney(playerid, -25);
        SendServerMsg(playerid, "Kupili ste travu za $25!");
        SendServerMsgF(playerid, "Ukupno trave: %d", Account_GetPlayerWeed(playerid));
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}