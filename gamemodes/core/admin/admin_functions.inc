#if defined _inc_admin_functions
    #undef _inc_admin_functions
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_functions_included
    #endinput
#endif
#define _admin_functions_included

// ---
// Variables
// ---
static
    adminLevel[MAX_PLAYERS],
    adminCode[MAX_PLAYERS],
    adminVehicle[MAX_PLAYERS],
    adminCommands[MAX_ADMIN_LEVEL][MAX_COMMANDS_PER_LEVEL][2048],

    Text3D: adminVehLabel[MAX_VEHICLES],
    Iterator: Iter_AdminCommands[MAX_ADMIN_LEVEL]<MAX_COMMANDS_PER_LEVEL>,
    BitArray: Bit_AdminDuty<MAX_PLAYERS>,
    BitArray: Bit_AdminVehicle<MAX_PLAYERS>;

// ---
// Functions
// ---
stock Admin_SetLevel(const targetid, const adminid, const level = 0)
{
    if (level > MAX_ADMIN_LEVEL)
        return SendErrorMsg(adminid, "Maksimalni admin level je 4!");

    if (Admin_GetLevel(targetid) == level)
        return SendErrorMsg(adminid, "Taj igrac je vec taj admin level!");

    Admin_SetPlayerLevel(targetid, level);
    Admin_SetPlayerCode(targetid, (!level ? (0) : (random(1000000))));

    if (!level)
    {
        SendServerMsgF(targetid, "Vlasnik %s Vam je skinuo admina.", ReturnPlayerName(adminid));
        SendServerMsgF(adminid, "Skinuli ste admina igracu %s.", ReturnPlayerName(targetid));

        Account_SetPlayerSkin(targetid, 1);
        SetPlayerHealth(targetid, Float: 99.0);
        return 1;
    }

    SendServerMsgF(targetid, "Kod: %d", Admin_GetCode(targetid));
    SendInfoMsgToAllF("[ADMIN]: "WHITE"Igrac %s je postao admin level %d.", ReturnPlayerName(targetid), level);
    SendInfoMsgF(adminid, "Postavili ste admina level %d igracu %s.", level, ReturnPlayerName(targetid));
    
    Account_SetPlayerSkin(targetid, 294);

    return 1;
}

stock Admin_SetPlayerLevel(const playerid, const level)
{
    adminLevel[playerid] = level;

    new String: str_query_admin_update = String: str_format(
        "UPDATE characters SET char_admin = '%d' WHERE char_id = '%d'",
        Admin_GetLevel(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_admin_update);

    return 1;
}

stock Admin_SetPlayerCode(const playerid, const code)
{
    adminCode[playerid] = code;

    new String: str_query_admin_update = String: str_format(
        "UPDATE characters SET char_admincode = '%d' WHERE char_id = '%d'",
        Admin_GetCode(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_admin_update);

    return 1;
}

stock Admin_AddCommandToList(const level, const string: command[])
{
    if (!(1 <= level <= MAX_ADMIN_LEVEL))
        return 0;

    new
        string: tmpString[152],
        freeid = Iter_Alloc(Iter_AdminCommands[level - 1]);

    if (freeid == ITER_NONE)
        return ITER_NONE;

    format(string: tmpString, sizeof tmpString, "%s\n", string: command);
    strcat(adminCommands[level - 1][freeid], string: tmpString);

    return 1;
}

stock Admin_ShowAdminCmdsOfLevel(const playerid, const level)
{
    new
        string: acmds[2048],
        string: tmpString[50];

    foreach (new i : Iter_AdminCommands[level])
        strcat(string: acmds, adminCommands[level][i]);

    format(string: tmpString, sizeof tmpString, "%s", Admin_GetRankNameFromLevel(level));
    Dialog_Show(playerid, "DIALOG_ADMINCMDSLEVEL", DIALOG_STYLE_LIST, string: tmpString, string: acmds, "Ok", "Zatvori");

    return 1;
}

stock Admin_GetRankNameFromLevel(level)
{
    new admin_RankNames[4][24] =
    {
        "Junior Admin",     // 1
        "General Admin",    // 2
        "Head Admin",       // 3
        "Owner"             // 4
    };

    return admin_RankNames[level];
}

stock Admin_SendMessage(const color, const string: message[], va_args<>)
{
    foreach (new i: Player)
        if (Admin_GetLevel(i))
            return SendClientMessage(i, color, va_return(message, va_start<2>));

    return 0;
}

stock Admin_SetDutyStatus(const playerid, bool: status)
{
    Bit_Set(Bit: Bit_AdminDuty, playerid, status);
    return 1;
}

stock Admin_CreateVehicle(const playerid, const vehicleid)
{
    new x, y, z, angle;
    GetPlayerPos(playerid, Float: x, Float: y, Float: z);
    GetPlayerFacingAngle(playerid, Float: angle);

    adminVehicle[playerid] = CreateVehicle(vehicleid,
        Float: x, Float: y, Float: z, Float: angle, random(20), random(20), 0
    );

    adminVehLabel[adminVehicle[playerid]] = Create3DTextLabel("ADMIN VOZILO", X11_YELLOW,
        Float: x, Float: y, Float: z, Float: 50.0, 0
    );

    Attach3DTextLabelToVehicle(Text3D: adminVehLabel[adminVehicle[playerid]], adminVehicle[playerid], Float: 0.0, Float: 0.0, Float: 0.0);
    PutPlayerInVehicle(playerid, adminVehicle[playerid], 0);
    Bit_Let(Bit: Bit_AdminVehicle, playerid);

    return 1;
}

stock Admin_DestroyVehicle(const playerid)
{
    DestroyVehicle(adminVehicle[playerid]);
    Bit_Set(Bit: Bit_AdminVehicle, playerid, false);
    
    return 1;
}

stock Admin_GetVehicleSpawned(const playerid) return Bit_Get(Bit: Bit_AdminVehicle, playerid);
stock Admin_GetDutyStatus(const playerid) return Bit_Get(Bit: Bit_AdminDuty, playerid);
stock Admin_GetLevel(const playerid) return adminLevel[playerid];
stock Admin_GetCode(const playerid) return adminCode[playerid];

/** Autofix vehicle timer */
PTASK__ FixAdminVehicle[2000](playerid)
{
    if (Admin_GetLevel(playerid))
    {
        if (IsPlayerInAnyVehicle(playerid))
        {
            RepairVehicle(GetPlayerVehicleID(playerid));
            SetVehicleHealth(GetPlayerVehicleID(playerid), 999.0);
        }
    }
}