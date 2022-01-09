#if defined _inc_ui_login
    #undef _inc_ui_login
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ui_login_included
    #endinput
#endif
#define _ui_login_included

#include <YSI_Coding\y_hooks>

/** Variables */
static PlayerText: loginTextDraw[MAX_PLAYERS][8] = {INVALID_PLAYER_TEXT_DRAW,...};

/** Functions */
stock UI_ClickLoginTextDraw(const playerid) return _:loginTextDraw[playerid][5];
stock UI_CreateLoginTextDraws(const playerid, bool: status = true)
{
    if (!status)
    {
        for (new i = 0; i < 8; ++i)
        {
            PlayerTextDrawDestroy(playerid, PlayerText: loginTextDraw[playerid][i]);
            loginTextDraw[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        }

        CancelSelectTextDraw(playerid);
        return 1;
    }

    loginTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 243.800109, 161.844451, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, loginTextDraw[playerid][0], 153.000000, 107.000000);
    PlayerTextDrawAlignment(playerid, loginTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, loginTextDraw[playerid][0], 117);
    PlayerTextDrawSetShadow(playerid, loginTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, loginTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, loginTextDraw[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, loginTextDraw[playerid][0], 0);

    loginTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 318.599853, 163.100036, "B L A C K L A N D");
    PlayerTextDrawLetterSize(playerid, loginTextDraw[playerid][1], 0.156999, 0.641778);
    PlayerTextDrawTextSize(playerid, loginTextDraw[playerid][1], 0.000000, 510.000000);
    PlayerTextDrawAlignment(playerid, loginTextDraw[playerid][1], 2);
    PlayerTextDrawColor(playerid, loginTextDraw[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, loginTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, loginTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, loginTextDraw[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, loginTextDraw[playerid][1], 1);

    loginTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 274.900054, 220.000000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, loginTextDraw[playerid][2], 88.000000, 22.000000);
    PlayerTextDrawAlignment(playerid, loginTextDraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, loginTextDraw[playerid][2], 107721349);
    PlayerTextDrawSetShadow(playerid, loginTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, loginTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, loginTextDraw[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, loginTextDraw[playerid][2], 0);

    loginTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 244.999877, 163.200012, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, loginTextDraw[playerid][3], 0.390001, 105.000000);
    PlayerTextDrawAlignment(playerid, loginTextDraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, loginTextDraw[playerid][3], 107721349);
    PlayerTextDrawSetShadow(playerid, loginTextDraw[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, loginTextDraw[playerid][3], 255);
    PlayerTextDrawFont(playerid, loginTextDraw[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, loginTextDraw[playerid][3], 0);

    loginTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 395.299957, 163.100189, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, loginTextDraw[playerid][4], 0.390001, 105.000000);
    PlayerTextDrawAlignment(playerid, loginTextDraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, loginTextDraw[playerid][4], 107721349);
    PlayerTextDrawSetShadow(playerid, loginTextDraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, loginTextDraw[playerid][4], 255);
    PlayerTextDrawFont(playerid, loginTextDraw[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, loginTextDraw[playerid][4], 0);

    loginTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 318.400024, 226.399963, "PRIJAVLJIVANJE");
    PlayerTextDrawLetterSize(playerid, loginTextDraw[playerid][5], 0.136000, 0.896889);
    PlayerTextDrawTextSize(playerid, loginTextDraw[playerid][5], 8.0, 20.0);
    PlayerTextDrawAlignment(playerid, loginTextDraw[playerid][5], 2);
    PlayerTextDrawColor(playerid, loginTextDraw[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, loginTextDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, loginTextDraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, loginTextDraw[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, loginTextDraw[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, loginTextDraw[playerid][5], true);

    loginTextDraw[playerid][6] = va_CreatePlayerTextDraw(playerid, 320.900115, 185.000305,
        "DOBRODOSLI %s NA BLACKLAND ROLEPLAY.~N~ZA NASTAVAK IGRE MORATE SE PRIJAVITI NA VAS NALOG.\
        ~N~KLIKNITE NA PRIJAVLJIVANE", ReturnPlayerName(playerid)
    );
    PlayerTextDrawLetterSize(playerid, loginTextDraw[playerid][6], 0.116000, 0.691555);
    PlayerTextDrawTextSize(playerid, loginTextDraw[playerid][6], 0.000000, 510.000000);
    PlayerTextDrawAlignment(playerid, loginTextDraw[playerid][6], 2);
    PlayerTextDrawColor(playerid, loginTextDraw[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, loginTextDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, loginTextDraw[playerid][6], 255);
    PlayerTextDrawFont(playerid, loginTextDraw[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, loginTextDraw[playerid][6], 1);

    loginTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 319.499908, 259.900054, "2021/22");
    PlayerTextDrawLetterSize(playerid, loginTextDraw[playerid][7], 0.116000, 0.691555);
    PlayerTextDrawTextSize(playerid, loginTextDraw[playerid][7], 0.000000, 510.000000);
    PlayerTextDrawAlignment(playerid, loginTextDraw[playerid][7], 2);
    PlayerTextDrawColor(playerid, loginTextDraw[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, loginTextDraw[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, loginTextDraw[playerid][7], 255);
    PlayerTextDrawFont(playerid, loginTextDraw[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, loginTextDraw[playerid][7], 1);

    for (new i = 0; i < 8; ++i)
    {
        PlayerTextDrawShow(playerid, PlayerText: loginTextDraw[playerid][i]);
    }

    SelectTextDraw(playerid, 0x000000FF);

    return 1;
}