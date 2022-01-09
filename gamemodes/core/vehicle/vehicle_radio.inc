#if defined _inc_vehicle_radio
    #undef _inc_vehicle_radio
#endif
// custom include-guard to ensure we don't duplicate
#if defined _vehicle_radio_included
    #endinput
#endif
#define _vehicle_radio_included

#include <YSI_Coding\y_hooks>

/** Variables */
static
    gRadioStatus[MAX_PLAYERS],
    gPlayingSong[MAX_PLAYERS];

static gRadioStations[][] =
{
    "http://radio.bumbumradio.rs:8010",
    "http://naxi128.streaming.rs:9150",
    "http://stream.rtvbn.com:8522"
};

/** Hooks */
hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if (newstate == PLAYER_STATE_ONFOOT && gRadioStatus[playerid])
    {
        Vehicle_SetRadioStatus(playerid, false);
    }
    
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid)
{
    gPlayingSong[playerid] =
    gRadioStatus[playerid] = 0;

    return Y_HOOKS_CONTINUE_RETURN_1;
}

/** Get/Set functions */
stock Vehicle_GetRadioStatus(const playerid) return gRadioStatus[playerid];
stock Vehicle_SetRadioStatus(const playerid, bool: status)
{
    if (!status)
    {
        if (gPlayingSong[playerid])
        {
            StopAudioStreamForPlayer(playerid);
            gPlayingSong[playerid] = 0;
        }

        gRadioStatus[playerid] = 0;
        SendServerMsg(playerid, "Ugasili ste radio.");
        return 1;
    }

    if (!IsPlayerInAnyVehicle(playerid))
    {
        return SendErrorMsg(playerid, "Niste u vozilu!");
    }

    gRadioStatus[playerid] = 1;
    SendServerMsg(playerid, "Upalili ste radio.");

    return 1;
}

stock Vehicle_FindStation(const playerid)
{
    if (!IsPlayerInAnyVehicle(playerid))
    {
        return SendErrorMsg(playerid, "Niste u vozilu!");
    }

    if (gRadioStatus[playerid])
    {
        SendInfoMsg(playerid, "Trazi se stanica...");
        PlayAudioStreamForPlayer(playerid, gRadioStations[random(sizeof gRadioStations)]);
        gPlayingSong[playerid] = 1;
    }

    return 1;
}