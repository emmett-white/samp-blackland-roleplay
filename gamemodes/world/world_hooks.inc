#if defined _inc_world_hooks
    #undef _inc_world_hooks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _world_hooks_included
    #endinput
#endif
#define _world_hooks_included

#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    new hour;
    gettime(hour);
    SetWorldTime(hour);
    SetWeather(4);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_SECONDARY_ATTACK))
    {
        // Jewerly store enter/exit
        if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1874.9480, Float: -1762.0485, Float: 13.5469))
            Streamer_UpdateEx(playerid, Float: 194.8216, Float: 1851.7327, Float: 994.3726, .type = STREAMER_TYPE_OBJECT, .compensatedtime = 2000);

        else if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 194.8216, Float: 1851.7327, Float: 994.3726))
            Streamer_UpdateEx(playerid, Float: 1874.9480, Float: -1762.0485, Float: 13.5469, .type = STREAMER_TYPE_OBJECT, .compensatedtime = 2000);
        
        // Los Santos Police Department enter/exit
        if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1553.5037, Float: -1682.9091, Float: 13.5774))
            Streamer_UpdateEx(playerid, Float: -7.9572, Float: 2688.0039, Float: -44.0710, .type = STREAMER_TYPE_OBJECT, .compensatedtime = 2000);

        else if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: -7.9572, Float: 2688.0039, Float: -44.0710))
            Streamer_UpdateEx(playerid, Float: 1553.5037, Float: -1682.9091, Float: 13.5774, .type = STREAMER_TYPE_OBJECT, .compensatedtime = 2000);

        // Garage enter
        else if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: -4.8074, Float: 2657.5234, Float: -49.2784))
            Streamer_UpdateEx(playerid, Float: 1543.8165, Float: -1635.6431, Float: 13.3410, .type = STREAMER_TYPE_OBJECT, .compensatedtime = 2000);

        // Bank enter/exit
        if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1461.2765, Float: -1021.2448, Float: 24.0317))
            Streamer_UpdateEx(playerid, Float: 1454.8555, Float: -985.5658, Float: 996.1050, .type = STREAMER_TYPE_OBJECT, .compensatedtime = 2000);

        else if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1454.8555, Float: -985.5658, Float: 996.1050))
            Streamer_UpdateEx(playerid, Float: 1461.2765, Float: -1021.2448, Float: 24.0317, .type = STREAMER_TYPE_OBJECT, .compensatedtime = 2000);

        // City hall enter/exit
        if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1481.0818, Float: -1771.7318, Float: 18.7979))
            Streamer_UpdateEx(playerid, Float: 1357.1696, Float: 717.8872, Float: -15.7573, .type = STREAMER_TYPE_OBJECT, .compensatedtime = 2000);

        else if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1357.1696, Float: 717.8872, Float: -15.7573))
            Streamer_UpdateEx(playerid, Float: 1481.0818, Float: -1771.7318, Float: 18.7979, .type = STREAMER_TYPE_OBJECT, .compensatedtime = 2000);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}