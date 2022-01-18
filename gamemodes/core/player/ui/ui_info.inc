#if defined _inc_ui_info
    #undef _inc_ui_info
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ui_info_included
    #endinput
#endif
#define _ui_info_included

// ---
// Variables
// ---
static
    PlayerText: infoTextDraw[MAX_PLAYERS][2] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},
    gPlayerMessageSent[MAX_PLAYERS],
    gMessageDestroyInterval = 5000;

// ---
// Timer
// ---
TIMER__ DestroyInfoMessage[gMessageDestroyInterval](playerid)
{
    UI_CreateInfoTextDraws(playerid, false);
    gPlayerMessageSent[playerid] = 0;
}

// ---
// Functions
// ---
stock UI_CreateInfoTextDraws(const playerid, bool: status = true)
{
    if (!status)
    {
        PlayerTextDrawDestroy(playerid, PlayerText: infoTextDraw[playerid][0]);
        PlayerTextDrawDestroy(playerid, PlayerText: infoTextDraw[playerid][1]);
        infoTextDraw[playerid][0] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        infoTextDraw[playerid][1] = PlayerText: INVALID_PLAYER_TEXT_DRAW;

        gPlayerMessageSent[playerid] = 0;
        return 1;
    }

    infoTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 28.900001, 218.922256, "_");
    PlayerTextDrawLetterSize(playerid, infoTextDraw[playerid][1], 0.131500, 1.002666);
    PlayerTextDrawTextSize(playerid, infoTextDraw[playerid][1], 981.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, infoTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, infoTextDraw[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, infoTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, infoTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, infoTextDraw[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, infoTextDraw[playerid][1], 1);

    PlayerTextDrawShow(playerid, PlayerText: infoTextDraw[playerid][1]);

    return 1;
}

stock UI_SendInfoMessage(const playerid, const string: message[], interval, va_args<>)
{
    if (gPlayerMessageSent[playerid])
        return 0;

    UI_CreateInfoTextDraws(playerid);
    gMessageDestroyInterval = interval;
    
    new Float: tmpY = strlen(message);
    if (tmpY > 128)
        return 0;

    else if (tmpY < 40)
        tmpY = (tmpY * 4.5);

    else
        tmpY = (tmpY * 3.5);

    infoTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 25.000000, 214.733352, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, infoTextDraw[playerid][0], tmpY, 18.000000);
    PlayerTextDrawAlignment(playerid, infoTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, infoTextDraw[playerid][0], 128);
    PlayerTextDrawSetShadow(playerid, infoTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, infoTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, infoTextDraw[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, infoTextDraw[playerid][0], 0);
    
    PlayerTextDrawShow(playerid, PlayerText: infoTextDraw[playerid][0]);
    PlayerTextDrawSetString(playerid, PlayerText: infoTextDraw[playerid][1], va_return(message, va_start<3>));

    DEFER__ DestroyInfoMessage(playerid);
    gPlayerMessageSent[playerid] = 1;

    return 1;
}