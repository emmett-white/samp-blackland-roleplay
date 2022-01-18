#if defined _inc_ui_loading
    #undef _inc_ui_loading
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ui_loading_included
    #endinput
#endif
#define _ui_loading_included

// ---
// Variables
// ---
static
    PlayerText: loadingTextDraw[MAX_PLAYERS][2] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},
    PlayerBar: loadingBar[MAX_PLAYERS] = {PlayerBar: INVALID_PLAYER_BAR_ID,...},
    
    loadingBarTimer[MAX_PLAYERS];

// ---
// Timer
// ---
forward LoadingBarTimer(const playerid, const connection);
public LoadingBarTimer(const playerid, const connection)
{
    new
        Float: value = GetPlayerProgressBarValue(playerid, PlayerBar: loadingBar[playerid]),
        randomValue = Random(20, 60);

    if (value != 100.0)
    {
        SetPlayerProgressBarValue(playerid, PlayerBar: loadingBar[playerid], Float: (value + randomValue));
        ShowPlayerProgressBar(playerid, PlayerBar: loadingBar[playerid]);
        loadingBarTimer[playerid] = SetTimerEx("LoadingBarTimer", 1000, 0, "di", playerid, connection);
        return 1;
    }

    if (connection)
        Account_CheckStatus(playerid);

    SetPlayerProgressBarValue(playerid, PlayerBar: loadingBar[playerid], Float: 0.0);
    UI_CreateLoadingTextDraw(playerid, false, connection);
    KillTimer(loadingBarTimer[playerid]);

    return 1;
}

// ---
// Functions
// ---
stock UI_CreateLoadingTextDraw(const playerid, bool: status = true, connection)
{
    if (!status)
    {
        PlayerTextDrawDestroy(playerid, PlayerText: loadingTextDraw[playerid][0]);
        PlayerTextDrawDestroy(playerid, PlayerText: loadingTextDraw[playerid][1]);
        loadingTextDraw[playerid][0] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        loadingTextDraw[playerid][1] = PlayerText: INVALID_PLAYER_TEXT_DRAW;

        DestroyPlayerProgressBar(playerid, PlayerBar: loadingBar[playerid]);
        loadingBar[playerid] = PlayerBar: INVALID_PLAYER_BAR_ID;
        return 1;
    }

    loadingBar[playerid] = CreatePlayerProgressBar(playerid,
        226.00, 111.00, 191.50, 11.70, 761825535,
        100.0, 0
    );

    ShowPlayerProgressBar(playerid, PlayerBar: loadingBar[playerid]);

    loadingTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 260.368011, 94.916702, "B L A C K L A N D  ~w~R O L E P L A Y");
    PlayerTextDrawLetterSize(playerid, loadingTextDraw[playerid][0], 0.179794, 0.865000);
    PlayerTextDrawTextSize(playerid, loadingTextDraw[playerid][0], 568.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, loadingTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, loadingTextDraw[playerid][0], 761825535);
    PlayerTextDrawSetShadow(playerid, loadingTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, loadingTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, loadingTextDraw[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, loadingTextDraw[playerid][0], 1);

    loadingTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 298.802032, 128.166656, "Ucitavanje...");
    PlayerTextDrawLetterSize(playerid, loadingTextDraw[playerid][1], 0.149809, 0.707499);
    PlayerTextDrawAlignment(playerid, loadingTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, loadingTextDraw[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, loadingTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, loadingTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, loadingTextDraw[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, loadingTextDraw[playerid][1], 1);

    PlayerTextDrawShow(playerid, PlayerText: loadingTextDraw[playerid][0]);
    PlayerTextDrawShow(playerid, PlayerText: loadingTextDraw[playerid][1]);

    loadingBarTimer[playerid] = SetTimerEx("LoadingBarTimer", 1000, 0, "di", playerid, connection);

    return 1;
}