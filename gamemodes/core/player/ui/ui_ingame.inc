#if defined _inc_ui_ingame
    #undef _inc_ui_ingame
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ui_ingame_included
    #endinput
#endif
#define _ui_ingame_included

/** Variables */
static
    PlayerText: ingameTextDraw[MAX_PLAYERS][8] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},
    PlayerBar: ingameBarPlayers[MAX_PLAYERS] = {PlayerBar: INVALID_PLAYER_BAR_ID,...},
    
    gConnectedPlayers;

static gRandomMessage[][] = {
    "~y~INFO: ~w~Nemojte nikome davati Vasu lozinku, samo je Vi morate znati!",
    "~y~INFO: ~w~Ukoliko ste videli citera, prijavite ga na ~r~/report~w~!",
    "~y~INFO: ~w~Ostavite novac u banku, kako bi izbegli da Vas opljackaju.",
    "~y~INFO: ~w~Ukoliko imate neko pitanje, postavite ga na ~y~/askq~w~.",
    "~y~INFO: ~w~Postujte druge igrace kako bi i oni postovali Vas.",
    "~y~INFO: ~w~Nemojte psovati, vredjati, citovati, bicete kaznjeni.",
    "~y~INFO: ~w~Ukoliko se ne mozete snaci na serveru kucajte ~r~/gps~w~."
};

/** Hooks */
hook OnPlayerConnect(playerid)
{
    UI_CreateInGameTextDraws(playerid, .create = true, .show = false);
    ++gConnectedPlayers;
    SetPlayerProgressBarValue(playerid, PlayerBar: ingameBarPlayers[playerid], gConnectedPlayers);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    --gConnectedPlayers;
    SetPlayerProgressBarValue(playerid, PlayerBar: ingameBarPlayers[playerid], gConnectedPlayers);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

/** Functions */
stock UI_CreateInGameTextDraws(const playerid, bool: status = true, bool: create, bool: show)
{
    if (!status)
    {
        for (new i = 0; i < 8; ++i)
        {
            PlayerTextDrawDestroy(playerid, PlayerText: ingameTextDraw[playerid][i]);
            ingameTextDraw[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        }

        DestroyPlayerProgressBar(playerid, PlayerBar: ingameBarPlayers[playerid]);
        ingameBarPlayers[playerid] = PlayerBar: INVALID_PLAYER_BAR_ID;
        return 1;
    }

    if (create)
    {
        ingameTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 588.000000, 10.800026, "00:00:00");
        PlayerTextDrawLetterSize(playerid, ingameTextDraw[playerid][0], 0.344999, 2.116444);
        PlayerTextDrawTextSize(playerid, ingameTextDraw[playerid][0], 0.000000, 350.000000);
        PlayerTextDrawAlignment(playerid, ingameTextDraw[playerid][0], 2);
        PlayerTextDrawColor(playerid, ingameTextDraw[playerid][0], -1);
        PlayerTextDrawSetShadow(playerid, ingameTextDraw[playerid][0], 0);
        PlayerTextDrawSetOutline(playerid, ingameTextDraw[playerid][0], 1);
        PlayerTextDrawBackgroundColor(playerid, ingameTextDraw[playerid][0], 255);
        PlayerTextDrawFont(playerid, ingameTextDraw[playerid][0], 3);
        PlayerTextDrawSetProportional(playerid, ingameTextDraw[playerid][0], 1);

        ingameTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 6.499998, 434.755584, "~y~INFO: ~w~Nemojte nikome davati vasu lozinku naloga, samo je vi morate znati!");
        PlayerTextDrawLetterSize(playerid, ingameTextDraw[playerid][1], 0.207499, 0.890666);
        PlayerTextDrawTextSize(playerid, ingameTextDraw[playerid][1], 1190.000000, 0.000000);
        PlayerTextDrawAlignment(playerid, ingameTextDraw[playerid][1], 1);
        PlayerTextDrawColor(playerid, ingameTextDraw[playerid][1], -1);
        PlayerTextDrawSetShadow(playerid, ingameTextDraw[playerid][1], 0);
        PlayerTextDrawSetOutline(playerid, ingameTextDraw[playerid][1], 1);
        PlayerTextDrawBackgroundColor(playerid, ingameTextDraw[playerid][1], 255);
        PlayerTextDrawFont(playerid, ingameTextDraw[playerid][1], 1);
        PlayerTextDrawSetProportional(playerid, ingameTextDraw[playerid][1], 1);

        ingameTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 74.300003, 314.688751, "360|");
        PlayerTextDrawLetterSize(playerid, ingameTextDraw[playerid][2], 0.225999, 1.120887);
        PlayerTextDrawTextSize(playerid, ingameTextDraw[playerid][2], 0.000000, 1190.000000);
        PlayerTextDrawAlignment(playerid, ingameTextDraw[playerid][2], 2);
        PlayerTextDrawColor(playerid, ingameTextDraw[playerid][2], -1);
        PlayerTextDrawSetShadow(playerid, ingameTextDraw[playerid][2], 0);
        PlayerTextDrawSetOutline(playerid, ingameTextDraw[playerid][2], 1);
        PlayerTextDrawBackgroundColor(playerid, ingameTextDraw[playerid][2], 255);
        PlayerTextDrawFont(playerid, ingameTextDraw[playerid][2], 2);
        PlayerTextDrawSetProportional(playerid, ingameTextDraw[playerid][2], 1);

        ingameTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 499.600006, 106.700004, "~g~BANKA: ~w~$545455342");
        PlayerTextDrawLetterSize(playerid, ingameTextDraw[playerid][3], 0.219999, 1.063777);
        PlayerTextDrawTextSize(playerid, ingameTextDraw[playerid][3], 826.000000, 0.000000);
        PlayerTextDrawAlignment(playerid, ingameTextDraw[playerid][3], 1);
        PlayerTextDrawColor(playerid, ingameTextDraw[playerid][3], -1);
        PlayerTextDrawSetShadow(playerid, ingameTextDraw[playerid][3], 0);
        PlayerTextDrawSetOutline(playerid, ingameTextDraw[playerid][3], 1);
        PlayerTextDrawBackgroundColor(playerid, ingameTextDraw[playerid][3], 255);
        PlayerTextDrawFont(playerid, ingameTextDraw[playerid][3], 2);
        PlayerTextDrawSetProportional(playerid, ingameTextDraw[playerid][3], 1);

        ingameTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 499.600006, 118.399826, "~y~ZLATO: ~w~452G");
        PlayerTextDrawLetterSize(playerid, ingameTextDraw[playerid][4], 0.219999, 1.063777);
        PlayerTextDrawTextSize(playerid, ingameTextDraw[playerid][4], 826.000000, 0.000000);
        PlayerTextDrawAlignment(playerid, ingameTextDraw[playerid][4], 1);
        PlayerTextDrawColor(playerid, ingameTextDraw[playerid][4], -1);
        PlayerTextDrawSetShadow(playerid, ingameTextDraw[playerid][4], 0);
        PlayerTextDrawSetOutline(playerid, ingameTextDraw[playerid][4], 1);
        PlayerTextDrawBackgroundColor(playerid, ingameTextDraw[playerid][4], 255);
        PlayerTextDrawFont(playerid, ingameTextDraw[playerid][4], 2);
        PlayerTextDrawSetProportional(playerid, ingameTextDraw[playerid][4], 1);

        ingameTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 499.600006, 130.399826, "~b~LEVEL: ~w~100");
        PlayerTextDrawLetterSize(playerid, ingameTextDraw[playerid][5], 0.219999, 1.063777);
        PlayerTextDrawTextSize(playerid, ingameTextDraw[playerid][5], 826.000000, 0.000000);
        PlayerTextDrawAlignment(playerid, ingameTextDraw[playerid][5], 1);
        PlayerTextDrawColor(playerid, ingameTextDraw[playerid][5], -1);
        PlayerTextDrawSetShadow(playerid, ingameTextDraw[playerid][5], 0);
        PlayerTextDrawSetOutline(playerid, ingameTextDraw[playerid][5], 1);
        PlayerTextDrawBackgroundColor(playerid, ingameTextDraw[playerid][5], 255);
        PlayerTextDrawFont(playerid, ingameTextDraw[playerid][5], 2);
        PlayerTextDrawSetProportional(playerid, ingameTextDraw[playerid][5], 1);

        ingameTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 132.099914, 356.577789, "I~n~G~n~R~n~A~N~C~N~A");
        PlayerTextDrawLetterSize(playerid, ingameTextDraw[playerid][6], 0.144500, 0.959111);
        PlayerTextDrawAlignment(playerid, ingameTextDraw[playerid][6], 2);
        PlayerTextDrawColor(playerid, ingameTextDraw[playerid][6], -1);
        PlayerTextDrawSetShadow(playerid, ingameTextDraw[playerid][6], 0);
        PlayerTextDrawSetOutline(playerid, ingameTextDraw[playerid][6], 1);
        PlayerTextDrawBackgroundColor(playerid, ingameTextDraw[playerid][6], 255);
        PlayerTextDrawFont(playerid, ingameTextDraw[playerid][6], 1);
        PlayerTextDrawSetProportional(playerid, ingameTextDraw[playerid][6], 1);

        ingameTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 564.800415, 435.155700, "REKORD: 1000 igraca");
        PlayerTextDrawLetterSize(playerid, ingameTextDraw[playerid][7], 0.184000, 0.803555);
        PlayerTextDrawTextSize(playerid, ingameTextDraw[playerid][7], 863.000000, 0.000000);
        PlayerTextDrawAlignment(playerid, ingameTextDraw[playerid][7], 1);
        PlayerTextDrawColor(playerid, ingameTextDraw[playerid][7], -1);
        PlayerTextDrawSetShadow(playerid, ingameTextDraw[playerid][7], 0);
        PlayerTextDrawSetOutline(playerid, ingameTextDraw[playerid][7], 1);
        PlayerTextDrawBackgroundColor(playerid, ingameTextDraw[playerid][7], 255);
        PlayerTextDrawFont(playerid, ingameTextDraw[playerid][7], 1);
        PlayerTextDrawSetProportional(playerid, ingameTextDraw[playerid][7], 1);

        ingameBarPlayers[playerid] = CreatePlayerProgressBar(playerid,
            128.00, 429.00, 5.50, 100.69, 107590399, GetMaxPlayers(), 2
        );
    }

    if (show)
    {
        for (new i = 0; i < 8; ++i)
        {
            PlayerTextDrawShow(playerid, PlayerText: ingameTextDraw[playerid][i]);
        }

        va_PlayerTextDrawSetString(playerid, PlayerText: ingameTextDraw[playerid][4], "~y~ZLATO: ~w~%dG", Account_GetPlayerGold(playerid));
        va_PlayerTextDrawSetString(playerid, PlayerText: ingameTextDraw[playerid][5], "~b~LEVEL: ~w~%d", Account_GetPlayerLevel(playerid));
        va_PlayerTextDrawSetString(playerid, PlayerText: ingameTextDraw[playerid][3], "~g~BANKA: $~w~%d", Account_GetPlayerBankMoney(playerid));

        ShowPlayerProgressBar(playerid, PlayerBar: ingameBarPlayers[playerid]);
        SetPlayerProgressBarValue(playerid, PlayerBar: ingameBarPlayers[playerid], gConnectedPlayers);
        va_PlayerTextDrawSetString(playerid, ingameTextDraw[playerid][7], "REKORD: %d igrac/a", UI_GetMaxRecord());
    }

    return 1;
}

stock UI_ReturnInGameStatsTextDraw(const playerid, const index)
{
    /** indexes
      * index 0 - gold textdraw
      * index 1 - bank money textdraw
      * index 2 - level textdraw
     */

    switch (index)
    {
        case 0: return _:ingameTextDraw[playerid][4];
        case 1: return _:ingameTextDraw[playerid][3];
        case 2: return _:ingameTextDraw[playerid][5];
    }

    return 1;
}

stock UI_GetMaxRecord()
{
    static maxConnectedPlayers;
    task_await(
        Task: MySQL_Query(
            "SELECT * FROM accounts WHERE account_id >= 1"
        )
    );

    if (cache_num_rows())
    {
        for (new i; i < cache_num_rows(); ++i)
        {
            maxConnectedPlayers = i;
        }
    }

    return (maxConnectedPlayers + 1);
}

/** Timers */
PTASK__ UI_TimeDateTimer[1000](playerid)
{
    new
        Timestamp: ts = Timestamp: Now(),
        ts_format[12],
        angle;

    TimeFormat(Timestamp: ts, ISO6801_TIME, ts_format, sizeof ts_format);
    PlayerTextDrawSetString(playerid, PlayerText: ingameTextDraw[playerid][0], ts_format);

    if (IsPlayerInAnyVehicle(playerid))
    {
		GetVehicleZAngle(GetPlayerVehicleID(playerid), Float: angle);
    }

	else
    {
		GetPlayerFacingAngle(playerid, Float: angle);
    }

    va_PlayerTextDrawSetString(playerid, PlayerText: ingameTextDraw[playerid][2], "%.0f|", (360 - Float: angle));
}

PTASK__ UI_UpdateRandomMessages[7000](playerid)
{
    PlayerTextDrawSetString(playerid, PlayerText: ingameTextDraw[playerid][1], gRandomMessage[random(sizeof gRandomMessage)]);
}