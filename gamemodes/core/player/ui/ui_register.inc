#if defined _inc_ui_register
    #undef _inc_ui_register
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ui_register_included
    #endinput
#endif
#define _ui_register_included

#include <YSI_Coding\y_hooks>

/** Variables */
static PlayerText: registerTextDraw[MAX_PLAYERS][27] = {INVALID_PLAYER_TEXT_DRAW,...};

/** Functions */
stock UI_ClickRegisterTextDraw(const playerid, const index) return _:registerTextDraw[playerid][index];
stock UI_CreateRegisterTextDraws(const playerid, bool: status = true)
{
    if (!status)
    {
        for (new i = 0; i < 27; ++i)
        {
            PlayerTextDrawDestroy(playerid, PlayerText: registerTextDraw[playerid][i]);
            registerTextDraw[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        }

        CancelSelectTextDraw(playerid);
        return 1;
    }

    registerTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 232.000000, 82.822204, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][0], 170.000000, 256.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][0], 133);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][0], 0);

    registerTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 315.999969, 85.066635, "B L A C K L A N D");
    PlayerTextDrawLetterSize(playerid, registerTextDraw[playerid][1], 0.139500, 0.666666);
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][1], 0.000000, 450.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][1], 2);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][1], 1);

    registerTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 282.200073, 279.600067, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][2], 72.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][2], 107721360);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][2], 0);

    registerTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 282.200073, 253.798492, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][3], 72.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][3], 107721360);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][3], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][3], 0);

    registerTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 282.200073, 228.596954, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][4], 72.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][4], 107721360);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][4], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][4], 0);

    registerTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 282.200073, 203.595428, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][5], 72.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][5], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][5], 107721360);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][5], 0);

    registerTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 282.200073, 178.793914, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][6], 72.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][6], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][6], 107721360);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][6], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][6], 0);

    registerTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 282.200073, 153.992401, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][7], 72.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][7], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][7], 107721360);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][7], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][7], 0);

    registerTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 282.200073, 128.190826, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][8], 72.000000, 17.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][8], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][8], 107721360);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][8], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][8], 0);

    registerTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 317.699981, 132.155487, "LOZINKA");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][9], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, registerTextDraw[playerid][9], 0.153499, 0.871999);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][9], 2);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][9], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][9], 2);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, registerTextDraw[playerid][9], true);

    registerTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 318.699981, 157.666625, "e-mail");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][10], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, registerTextDraw[playerid][10], 0.153499, 0.871999);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][10], 2);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][10], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][10], 2);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][10], 1);
    PlayerTextDrawSetSelectable(playerid, registerTextDraw[playerid][10], true);

    registerTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 317.199981, 182.555541, "DRZAVA");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][11], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, registerTextDraw[playerid][11], 0.153499, 0.871999);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][11], 2);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][11], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][11], 2);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][11], 1);
    PlayerTextDrawSetSelectable(playerid, registerTextDraw[playerid][11], true);

    registerTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 317.699981, 208.066680, "GODINE");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][12], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, registerTextDraw[playerid][12], 0.153499, 0.871999);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][12], 2);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][12], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][12], 2);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][12], 1);
    PlayerTextDrawSetSelectable(playerid, registerTextDraw[playerid][12], true);

    registerTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 318.199981, 232.333374, "SPOL");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][13], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, registerTextDraw[playerid][13], 0.153499, 0.871999);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][13], 2);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][13], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][13], 2);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][13], 1);
    PlayerTextDrawSetSelectable(playerid, registerTextDraw[playerid][13], true);

    registerTextDraw[playerid][14] = CreatePlayerTextDraw(playerid, 317.699981, 257.866699, "SKIN");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][14], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, registerTextDraw[playerid][14], 0.153499, 0.871999);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][14], 2);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][14], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][14], 2);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, registerTextDraw[playerid][14], true);

    registerTextDraw[playerid][15] = CreatePlayerTextDraw(playerid, 318.199981, 283.677856, "REGISTRACIJA");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][15], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, registerTextDraw[playerid][15], 0.153499, 0.871999);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][15], 2);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][15], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][15], 2);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, registerTextDraw[playerid][15], true);

    registerTextDraw[playerid][16] = CreatePlayerTextDraw(playerid, 233.799926, 85.633323, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][16], 0.580000, 251.510269);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][16], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][16], 107721471);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][16], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][16], 0);

    registerTextDraw[playerid][17] = CreatePlayerTextDraw(playerid, 399.399902, 85.644485, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][17], 0.580000, 251.510269);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][17], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][17], 107721471);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][17], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][17], 0);

    registerTextDraw[playerid][18] = va_CreatePlayerTextDraw(playerid, 316.399993, 309.933258,
        "DOBRODOSLI %s NA BLACKLAND ROLEPLAY.~N~UGODNU IGRU VAM ZELI STAFF TEAM~n~- 2021/22 -",
        ReturnPlayerName(playerid)
    );
    PlayerTextDrawLetterSize(playerid, registerTextDraw[playerid][18], 0.115000, 0.672888);
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][18], 0.000000, 540.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][18], 2);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][18], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][18], 2);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][18], 1);

    registerTextDraw[playerid][19] = CreatePlayerTextDraw(playerid, 290.100128, 280.400146, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][19], 54.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][19], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][19], -192);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][19], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][19], 0);

    registerTextDraw[playerid][20] = CreatePlayerTextDraw(playerid, 290.100128, 255.398620, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][20], 54.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][20], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][20], -192);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][20], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][20], 0);

    registerTextDraw[playerid][21] = CreatePlayerTextDraw(playerid, 290.100128, 229.297027, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][21], 54.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][21], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][21], -192);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][21], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][21], 0);

    registerTextDraw[playerid][22] = CreatePlayerTextDraw(playerid, 290.100128, 204.595520, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][22], 54.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][22], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][22], -192);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][22], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][22], 0);

    registerTextDraw[playerid][23] = CreatePlayerTextDraw(playerid, 290.100128, 179.493988, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][23], 54.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][23], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][23], -192);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][23], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][23], 0);

    registerTextDraw[playerid][24] = CreatePlayerTextDraw(playerid, 290.100128, 154.692474, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][24], 54.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][24], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][24], -192);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][24], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][24], 0);

    registerTextDraw[playerid][25] = CreatePlayerTextDraw(playerid, 290.100128, 128.990905, "particle:lamp_shad_64");
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][25], 54.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][25], 1);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][25], -192);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][25], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][25], 0);

    registerTextDraw[playerid][26] = CreatePlayerTextDraw(playerid, 317.899993, 103.844512, "POPUNITE_SVA_POLJA~N~ZATIM KLIKNITE NA 'REGISTRACIJA'.");
    PlayerTextDrawLetterSize(playerid, registerTextDraw[playerid][26], 0.115000, 0.672888);
    PlayerTextDrawTextSize(playerid, registerTextDraw[playerid][26], 0.000000, 540.000000);
    PlayerTextDrawAlignment(playerid, registerTextDraw[playerid][26], 2);
    PlayerTextDrawColor(playerid, registerTextDraw[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, registerTextDraw[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, registerTextDraw[playerid][26], 255);
    PlayerTextDrawFont(playerid, registerTextDraw[playerid][26], 2);
    PlayerTextDrawSetProportional(playerid, registerTextDraw[playerid][26], 1);

    for (new i = 0; i < 27; ++i)
    {
        PlayerTextDrawShow(playerid, PlayerText: registerTextDraw[playerid][i]);
    }
    
    SelectTextDraw(playerid, 0x000000FF);

    return 1;
}