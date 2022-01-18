#if defined _inc_winter_functions
    #undef _inc_winter_functions
#endif
// custom include-guard to ensure we don't duplicate
#if defined _winter_functions_included
    #endinput
#endif
#define _winter_functions_included

// ---
// Variables
// ---
static
    snowObj[MAX_PLAYERS],

    BitArray: PLAYER_WINTERALL<MAX_PLAYERS>,
    BitArray: PLAYER_SNOWOBJ<MAX_PLAYERS>,
    BitArray: PLAYER_SNOWFLAKES<MAX_PLAYERS>,
    BitArray: PLAYER_CAP<MAX_PLAYERS>,
    BitArray: PLAYER_COLDBREATH<MAX_PLAYERS>;

// ---
// Timer
// ---
PTASK__ ColdBreath[2500](playerid)
{
    if (Winter_GetColdBreathStatus(playerid) && !GetPlayerInterior(playerid) && !GetPlayerVirtualWorld(playerid))
    {
        RemovePlayerAttachedObject(playerid, 4);
        SetPlayerAttachedObject(playerid, 4, 18696, 2, 0.0, 0.1, -0.2, -25.5000, 0.0, 0.0, 0.10, 0.3, 0.15);
    }
}

// ---
// Functions
// ---
stock Winter_CreateSnowObject(const modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, vw, ent, pid, Float:ddist=300.0, Float:vrdist=300.0)
{
	new object = CreateDynamicObject(modelid,
        (x + 0.05), (y + 0.075), (z + 0.1), rx, ry, rz,
        vw, ent, pid, ddist, vrdist
    );

	for(new i = 0; i < 15; ++i)
        SetDynamicObjectMaterial(object, i, 17944, "lngblok_lae2", "white64bumpy", 0);

	return object;
}

stock Winter_ReturnSnowObject(const playerid) return snowObj[playerid];
stock Winter_GetSnowObjStatus(const playerid) return Bit_Get(Bit: PLAYER_SNOWOBJ, playerid);
stock Winter_GetSnowflakeStatus(const playerid) return Bit_Get(Bit: PLAYER_SNOWFLAKES, playerid);
stock Winter_GetSnowCapStatus(const playerid) return Bit_Get(Bit: PLAYER_CAP, playerid);
stock Winter_GetStatusAll(const playerid) return Bit_Get(Bit: PLAYER_WINTERALL, playerid);
stock Winter_GetColdBreathStatus(const playerid) return Bit_Get(Bit: PLAYER_COLDBREATH, playerid);

stock Winter_StatusAll(const playerid, bool: status = true)
{
    if (!status)
    {
        Winter_SnowflakeStatus(playerid, false);
        Winter_SnowObjStatus(playerid, false);
        Winter_SnowCapStatus(playerid, false);
        Winter_ColdBreathStatus(playerid, false);
        Bit_Set(Bit: PLAYER_WINTERALL, playerid, false);
        return 1;
    }

    if (Winter_GetSnowflakeStatus(playerid))
        Winter_SnowflakeStatus(playerid, false);

    else if (Winter_GetSnowObjStatus(playerid))
        Winter_SnowObjStatus(playerid, false);

    else if (Winter_GetSnowCapStatus(playerid))
        Winter_SnowCapStatus(playerid, false);

    else if (Winter_GetColdBreathStatus(playerid))
        Winter_ColdBreathStatus(playerid, false);

    Winter_SnowObjStatus(playerid);
    Winter_SnowflakeStatus(playerid);
    Winter_SnowCapStatus(playerid);
    Winter_ColdBreathStatus(playerid);
    Bit_Let(Bit: PLAYER_WINTERALL, playerid);

    return 1;
}

stock Winter_SnowObjStatus(const playerid, bool: status = true)
{
    Winter_ShowSnow(playerid, status);
    Bit_Set(Bit: PLAYER_SNOWOBJ, playerid, status);

    return 1;
}

stock Winter_SnowflakeStatus(const playerid, bool: status = true)
{
    if (!status)
    {
        DestroyPlayerObject(playerid, snowObj[playerid]);
        Bit_Set(Bit: PLAYER_SNOWFLAKES, playerid, false);
        return 1;
    }

    static x, y, z;
    GetPlayerCameraPos(playerid, Float: x, Float: z, Float: z);
    snowObj[playerid] = CreatePlayerObject(playerid, 18864,
        (Float: x + random(25)), (Float: y + random(25)), (Float: z - 5), 0.0, 0.0, 0.0, 300.0
    );

    Bit_Let(Bit: PLAYER_SNOWFLAKES, playerid);

    return 1;
}

stock Winter_SnowCapStatus(const playerid, bool: status = true)
{
    if (!status)
    {
        RemovePlayerAttachedObject(playerid, 3);
        Bit_Set(Bit: PLAYER_CAP, playerid, false);
        return 1;
    }

    // Attach winter cap to head
    SetPlayerAttachedObject(playerid, 3, 19065, 2, 0.120000, 0.040000, -0.003500, 0, 100, 100, 1.4, 1.4, 1.4);
    Bit_Let(Bit: PLAYER_CAP, playerid);

    return 1;
}

stock Winter_ColdBreathStatus(const playerid, bool: status = true)
{
    if (!status)
    {
        RemovePlayerAttachedObject(playerid, 4);
        Bit_Set(Bit: PLAYER_COLDBREATH, playerid, false);
        return 1;
    }

    Bit_Let(Bit: PLAYER_COLDBREATH, playerid);

    return 1;
}