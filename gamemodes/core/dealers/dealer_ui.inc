#if defined _inc_dealer_ui
    #undef _inc_dealer_ui
#endif
// custom include-guard to ensure we don't duplicate
#if defined _dealer_ui_included
    #endinput
#endif
#define _dealer_ui_included

/** Variables */
static
    PlayerText: dealerTextDraw[MAX_PLAYERS][19] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},
    dealerStatus[MAX_PLAYERS];

/** Functions */
stock UI_DealerTextDrawCreated(const playerid) return dealerStatus[playerid];
stock UI_CreateDealerTextDraws(const playerid, bool: status = true)
{
    if (!status)
    {
        for (new i = 0; i < 19; ++i)
        {
            PlayerTextDrawDestroy(playerid, PlayerText: dealerTextDraw[playerid][i]);
            dealerTextDraw[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        }

        Dialog_Close(playerid);
        CancelSelectTextDraw(playerid);
        dealerStatus[playerid] = 0;
        return 1;
    }

    dealerTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, -55.000000, -78.955558, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][0], 849.000000, 536.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][0], 0);

    dealerTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 104.500000, 122.644462, "");
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][1], 182.000000, 233.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][1], 0x00000000);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, dealerTextDraw[playerid][1], 29);
    PlayerTextDrawSetPreviewRot(playerid, dealerTextDraw[playerid][1], -20.000000, 0.000000, 15.000000, 1.000000);

    foreach (new id: Iter_Dealers)
    {
        dealerTextDraw[playerid][2] = va_CreatePlayerTextDraw(playerid, 197.500000, 103.511062, "DILER - %s", dealerName[Dealer_NearbyID(playerid)]);
    }
    PlayerTextDrawLetterSize(playerid, dealerTextDraw[playerid][2], 0.180999, 1.145777);
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][2], 0.000000, 623.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][2], 2);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][2], 1);

    dealerTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 601.500000, 24.955507, "LD_CHAT:THUMBDN");
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][3], 14.000000, 18.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][3], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, dealerTextDraw[playerid][3], true);

    dealerTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 277.000000, 139.444427, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][4], 230.000000, 129.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][4], 761825535);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][4], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][4], 0);

    dealerTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 277.000000, 140.244476, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][5], 233.000000, 127.430091);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][5], 1);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][5], 0);

    dealerTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 349.000000, 147.733322, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][6], 0.380000, 111.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][6], 1);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][6], 761825535);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][6], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][6], 0);

    dealerTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 434.299591, 147.855514, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][7], 0.380000, 111.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][7], 1);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][7], 761825535);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][7], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][7], 0);

    dealerTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 279.000000, 156.244445, "");
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][8], 64.000000, 65.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][8], 1);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][8], 0x00000000);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, dealerTextDraw[playerid][8], true);
    PlayerTextDrawSetPreviewModel(playerid, dealerTextDraw[playerid][8], 1575);
    PlayerTextDrawSetPreviewRot(playerid, dealerTextDraw[playerid][8], 90.000000, 0.000000, 90.000000, 1.000000);

    dealerTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 375.000000, 163.088897, "");
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][9], 64.000000, 65.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][9], 1);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][9], 0x00000000);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][9], 5);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][9], 0);
    PlayerTextDrawSetSelectable(playerid, dealerTextDraw[playerid][9], true);
    PlayerTextDrawSetPreviewModel(playerid, dealerTextDraw[playerid][9], 348);
    PlayerTextDrawSetPreviewRot(playerid, dealerTextDraw[playerid][9], 0.000000, 0.000000, 0.000000, 1.000000);

    dealerTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 439.000091, 163.711120, "");
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][10], 64.000000, 65.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][10], 1);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][10], 0x00000000);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][10], 5);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, dealerTextDraw[playerid][10], true);
    PlayerTextDrawSetPreviewModel(playerid, dealerTextDraw[playerid][10], 702);
    PlayerTextDrawSetPreviewRot(playerid, dealerTextDraw[playerid][10], 90.000000, 0.000000, 90.000000, 1.000000);

    dealerTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 311.000000, 234.800033, "KOMAD: 1~n~CENA: $50");
    PlayerTextDrawLetterSize(playerid, dealerTextDraw[playerid][11], 0.147999, 0.803555);
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][11], 0.000000, 230.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][11], 2);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][11], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][11], 2);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][11], 1);

    dealerTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 392.004943, 234.800033, "KOMAD: 1~n~CENA: $65");
    PlayerTextDrawLetterSize(playerid, dealerTextDraw[playerid][12], 0.147999, 0.803555);
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][12], 0.000000, 230.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][12], 2);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][12], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][12], 2);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][12], 1);

    dealerTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 472.409851, 234.800033, "KOMAD: 1~n~CENA: $23");
    PlayerTextDrawLetterSize(playerid, dealerTextDraw[playerid][13], 0.147999, 0.803555);
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][13], 0.000000, 230.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][13], 2);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][13], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][13], 2);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][13], 1);

    dealerTextDraw[playerid][14] = CreatePlayerTextDraw(playerid, 312.409851, 149.677719, "DROGA");
    PlayerTextDrawLetterSize(playerid, dealerTextDraw[playerid][14], 0.147999, 0.803555);
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][14], 0.000000, 230.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][14], 2);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][14], 761825535);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][14], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][14], 2);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][14], 1);

    dealerTextDraw[playerid][15] = CreatePlayerTextDraw(playerid, 391.609802, 149.677719, "DESERT EAGLE");
    PlayerTextDrawLetterSize(playerid, dealerTextDraw[playerid][15], 0.147999, 0.803555);
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][15], 0.000000, 230.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][15], 2);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][15], 761825535);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][15], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][15], 2);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][15], 1);

    dealerTextDraw[playerid][16] = CreatePlayerTextDraw(playerid, 470.509765, 149.677719, "TRAVA");
    PlayerTextDrawLetterSize(playerid, dealerTextDraw[playerid][16], 0.147999, 0.803555);
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][16], 0.000000, 230.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][16], 2);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][16], 761825535);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][16], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][16], 2);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][16], 1);

    dealerTextDraw[playerid][17] = CreatePlayerTextDraw(playerid, 394.609771, 279.699981, "UKOLIKO ZELITE UZETI NESTO OD DILERA, KLIKNITE NA ZELJENI PREDMET. UZETI PREDMETI OD DILERA SU ILEGALNI.");
    PlayerTextDrawLetterSize(playerid, dealerTextDraw[playerid][17], 0.134499, 0.809777);
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][17], 0.000000, 230.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][17], 2);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][17], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][17], 2);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][17], 1);

    dealerTextDraw[playerid][18] = CreatePlayerTextDraw(playerid, 394.109771, 294.688293, "AKO VAM POLICIJA PRONADJE NEDOZVOLJENE PREDMETE~N~MOZETE DOBITI ZATVORSKU KAZNU.");
    PlayerTextDrawLetterSize(playerid, dealerTextDraw[playerid][18], 0.134499, 0.809777);
    PlayerTextDrawTextSize(playerid, dealerTextDraw[playerid][18], 0.000000, 230.000000);
    PlayerTextDrawAlignment(playerid, dealerTextDraw[playerid][18], 2);
    PlayerTextDrawColor(playerid, dealerTextDraw[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, dealerTextDraw[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, dealerTextDraw[playerid][18], 255);
    PlayerTextDrawFont(playerid, dealerTextDraw[playerid][18], 2);
    PlayerTextDrawSetProportional(playerid, dealerTextDraw[playerid][18], 1);

    for (new i = 0; i < 19; ++i)
    {
        PlayerTextDrawShow(playerid, PlayerText: dealerTextDraw[playerid][i]);
    }

    SelectTextDraw(playerid, MAIN_COLOR_HEX);
    dealerStatus[playerid] = 1;

    return 1;
}

stock Dealer_ReturnTextDraw(const playerid, const index) return _:dealerTextDraw[playerid][index];