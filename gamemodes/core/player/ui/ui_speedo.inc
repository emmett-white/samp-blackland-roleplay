#if defined _inc_ui_speedo
    #undef _inc_ui_speedo
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ui_speedo_included
    #endinput
#endif
#define _ui_speedo_included

#include <YSI_Coding\y_hooks>

// ---
// Variables
// ---
const
    MAX_VEHICLE_FUEL =  (45),
    FUEL_DOWN_TIME =    (50000);

static
    gPlayerVehicleFuel[MAX_PLAYERS],

    BitArray: Bit_VehicleLights<MAX_PLAYERS>,
    PlayerText: speedoTextDraw[MAX_PLAYERS][17] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...};

new gVehicleNames[][] =
{
	"Landstalker",
	"Bravura",
	"Buffalo",
	"Linerunner",
	"Perenniel",
	"Sentinel",
	"Dumper",
	"Firetruck",
	"Trashmaster",
	"Stretch",
	"Manana",
	"Infernus",
	"Voodoo",
	"Pony",
	"Mule",
	"Cheetah",
	"Ambulance",
	"Leviathan",
	"Moonbeam",
	"Esperanto",
	"Taxi",
	"Washington",
	"Bobcat",
	"Mr Whoopee",
	"BF Injection",
	"Hunter",
	"Premier",
	"Enforcer",
	"Securicar",
	"Banshee",
	"Predator",
	"Bus",
	"Rhino",
	"Barracks",
	"Hotknife",
	"Trailer",
	"Previon",
	"Coach",
	"Cabbie",
	"Stallion",
	"Rumpo",
	"RC Bandit",
	"Romero",
	"Packer",
	"Monster Truck",
	"Admiral",
	"Squalo",
	"Seasparrow",
	"Pizzaboy",
	"Tram",
	"Trailer",
	"Turismo",
	"Speeder",
	"Reefer",
	"Tropic",
	"Flatbed",
	"Yankee",
	"Caddy",
	"Solair",
	"Berkley's RC Van",
	"Skimmer",
	"PCJ-600",
	"Faggio",
	"Freeway",
	"RC Baron",
	"RC Raider",
	"Glendale",
	"Oceanic",
	"Sanchez",
	"Sparrow",
	"Patriot",
	"Quad",
	"Coastguard",
	"Dinghy",
	"Hermes",
	"Sabre",
	"Rustler",
	"ZR-350",
	"Walton",
	"Regina",
	"Comet",
	"BMX",
	"Burrito",
	"Camper",
	"Marquis",
	"Baggage",
	"Dozer",
	"Maverick",
	"News Chopper",
	"Rancher",
	"FBI Rancher",
	"Virgo",
	"Greenwood",
	"Jetmax",
	"Hotring",
	"Sandking",
	"Blista Compact",
	"Police Maverick",
	"Boxville",
	"Benson",
	"Mesa",
	"RC Goblin",
	"Hotring Racer",
	"Hotring Racer",
	"Bloodring Banger",
	"Rancher",
	"Super GT",
	"Elegant",
	"Journey",
	"Bike",
	"Mountain Bike",
	"Beagle",
	"Cropdust",
	"Stunt Plane",
	"Tanker",
	"RoadTrain",
	"Nebula",
	"Majestic",
	"Buccaneer",
	"Shamal",
	"Hydra",
	"FCR-900",
	"NRG-500",
	"HPV1000",
	"Cement Truck",
	"Tow Truck",
	"Fortune",
	"Cadrona",
	"FBI Truck",
	"Willard",
	"Forklift",
	"Tractor",
	"Combine",
	"Feltzer",
	"Remington",
	"Slamvan",
	"Blade",
	"Freight",
	"Streak",
	"Vortex",
	"Vincent",
	"Bullet",
	"Clover",
	"Sadler",
	"Firetruck",
	"Hustler",
	"Intruder",
	"Primo",
	"Cargobob",
	"Tampa",
	"Sunrise",
	"Merit",
	"Utility",
	"Nevada",
	"Yosemite",
	"Windsor",
	"Monster Truck",
	"Monster Truck",
	"Uranus",
	"Jester",
	"Sultan",
	"Stratum",
	"Elegy",
	"Raindance",
	"RC Tiger",
	"Flash",
	"Tahoma",
	"Savanna",
	"Bandito",
	"Freight",
	"Trailer",
	"Kart",
	"Mower",
	"Duneride",
	"Sweeper",
	"Broadway",
	"Tornado",
	"AT-400",
	"DFT-30",
	"Huntley",
	"Stafford",
	"BF-400",
	"Newsvan",
	"Tug",
	"Trailer",
	"Emperor",
	"Wayfarer",
	"Euros",
	"Hotdog",
	"Club",
	"Trailer",
	"Trailer",
	"Andromada",
	"Dodo",
	"RC Cam",
	"Launch",
	"Police Car (LSPD)",
	"Police Car (SFPD)",
	"Police Car (LVPD)",
	"Police Ranger",
	"Picador",
	"S.W.A.T. Van",
	"Alpha",
	"Phoenix",
	"Glendale",
	"Sadler",
	"Luggage Trailer",
	"Luggage Trailer",
	"Stair Trailer",
	"Boxville",
	"Farm Plow",
	"Utility Trailer"
};

// ---
// Hooks
// ---
hook OnPlayerConnect(playerid)
{
    gPlayerVehicleFuel[playerid] = MAX_VEHICLE_FUEL;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_YES) && IsPlayerInAnyVehicle(playerid))
    {
        if (Bit_Get(Bit: Bit_VehicleLights, playerid))
            return Speedo_SetVehicleLights(playerid, false);

        Speedo_SetVehicleLights(playerid);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if (Player_IsSpawned(playerid))
        UI_CreateSpeedoTextDraws(playerid, (newstate == PLAYER_STATE_DRIVER ? (true) : (false)));

    return Y_HOOKS_CONTINUE_RETURN_1;
}

// ---
// Functions
// ---
stock UI_CreateSpeedoTextDraws(const playerid, bool: status = true)
{
    if (!status)
    {
        for (new i = 0; i < 17; ++i)
        {
            PlayerTextDrawDestroy(playerid, PlayerText: speedoTextDraw[playerid][i]);
            speedoTextDraw[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        }
        return 1;
    }

    if (!Speedo_IsPlayerInBicycle(GetVehicleModel(GetPlayerVehicleID(playerid))))
    {
        speedoTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 524.199584, 389.411376, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][0], 91.000000, 17.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][0], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][0], 96);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][0], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][0], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][0], 4);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][0], 0);

        speedoTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 524.099365, 371.355651, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][1], 91.000000, 17.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][1], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][1], 96);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][1], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][1], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][1], 4);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][1], 0);

        speedoTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 524.100097, 353.277740, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][2], 91.000000, 17.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][2], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][2], 96);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][2], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][2], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][2], 4);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][2], 0);

        speedoTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 524.100097, 335.376647, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][3], 91.000000, 17.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][3], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][3], 96);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][3], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][3], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][3], 4);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][3], 0);

        speedoTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 524.100097, 316.909973, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][4], 91.000000, 17.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][4], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][4], 761825376);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][4], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][4], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][4], 4);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][4], 0);

        speedoTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 523.299926, 318.032287, "particle:lamp_shad_64");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][5], 91.000000, 17.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][5], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][5], 112);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][5], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][5], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][5], 4);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][5], 0);

        speedoTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 521.899780, 334.798858, "particle:lamp_shad_64");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][6], 95.000000, 71.700363);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][6], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][6], -224);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][6], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][6], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][6], 4);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][6], 0);

        speedoTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 568.699584, 322.066741, gVehicleNames[GetVehicleModel(GetPlayerVehicleID(playerid)) - 400]);
        PlayerTextDrawLetterSize(playerid, speedoTextDraw[playerid][7], 0.166000, 0.710222);
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][7], 0.000000, 255.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][7], 2);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][7], -1);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][7], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][7], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][7], 2);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][7], 1);

        speedoTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 569.699584, 340.777801, "BRZINA: 400km/h");
        PlayerTextDrawLetterSize(playerid, speedoTextDraw[playerid][8], 0.166000, 0.710222);
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][8], 0.000000, 255.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][8], 2);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][8], -1);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][8], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][8], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][8], 2);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][8], 1);

        speedoTextDraw[playerid][9] = va_CreatePlayerTextDraw(playerid,
            568.499755, 358.122222, "GORIVO: %dL", Speedo_GetPlayerVehicleFuel(playerid));
        PlayerTextDrawLetterSize(playerid, speedoTextDraw[playerid][9], 0.166000, 0.710222);
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][9], 0.000000, 255.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][9], 2);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][9], -1);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][9], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][9], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][9], 2);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][9], 1);

        speedoTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 570.099731, 376.355438, "_");
        PlayerTextDrawLetterSize(playerid, speedoTextDraw[playerid][10], 0.166000, 0.710222);
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][10], 0.000000, 255.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][10], 2);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][10], -1);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][10], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][10], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][10], 2);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][10], 1);

        speedoTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 569.799682, 394.477722, "OSTECENJE: 1000");
        PlayerTextDrawLetterSize(playerid, speedoTextDraw[playerid][11], 0.166000, 0.710222);
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][11], 0.000000, 255.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][11], 2);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][11], -1);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][11], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][11], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][11], 2);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][11], 1);

        speedoTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 605.599975, 392.388885, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][12], 7.000000, 11.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][12], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][12], 820791295);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][12], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][12], 255);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][12], 4);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][12], 0);

        static
            color1,
            color2;
            
        GetVehicleColor(GetPlayerVehicleID(playerid), color1, color2);
        speedoTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 475.000000, 338.555603, "");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][13], 54.000000, 58.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][13], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][13], -1);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][13], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][13], 0x00000000);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][13], 5);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][13], 0);
        PlayerTextDrawSetPreviewModel(playerid, speedoTextDraw[playerid][13], GetVehicleModel(GetPlayerVehicleID(playerid)));
        PlayerTextDrawSetPreviewRot(playerid, speedoTextDraw[playerid][13], -90.000000, 0.000000, 180.000000, 1.000000);
        PlayerTextDrawSetPreviewVehCol(playerid, speedoTextDraw[playerid][13], color1, color2);

        speedoTextDraw[playerid][14] = CreatePlayerTextDraw(playerid, 467.500000, 322.377746, "");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][14], 59.000000, 52.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][14], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][14], -1);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][14], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][14], 0x00000000);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][14], 5);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][14], 0);
        PlayerTextDrawSetPreviewModel(playerid, speedoTextDraw[playerid][14], 18656);
        PlayerTextDrawSetPreviewRot(playerid, speedoTextDraw[playerid][14], 90.000000, 0.000000, 0.000000, 1.000000);

        speedoTextDraw[playerid][15] = CreatePlayerTextDraw(playerid, 477.501068, 322.377746, "");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][15], 59.000000, 52.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][15], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][15], -1);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][15], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][15], 0x00000000);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][15], 5);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][15], 0);
        PlayerTextDrawSetPreviewModel(playerid, speedoTextDraw[playerid][15], 18656);
        PlayerTextDrawSetPreviewRot(playerid, speedoTextDraw[playerid][15], 90.000000, 0.000000, 0.000000, 1.000000);

        speedoTextDraw[playerid][16] = CreatePlayerTextDraw(playerid, 472.501098, 327.355529, "");
        PlayerTextDrawTextSize(playerid, speedoTextDraw[playerid][16], 59.000000, 52.000000);
        PlayerTextDrawAlignment(playerid, speedoTextDraw[playerid][16], 1);
        PlayerTextDrawColor(playerid, speedoTextDraw[playerid][16], -1);
        PlayerTextDrawSetShadow(playerid, speedoTextDraw[playerid][16], 0);
        PlayerTextDrawBackgroundColor(playerid, speedoTextDraw[playerid][16], 0x00000000);
        PlayerTextDrawFont(playerid, speedoTextDraw[playerid][16], 5);
        PlayerTextDrawSetProportional(playerid, speedoTextDraw[playerid][16], 0);
        PlayerTextDrawSetPreviewModel(playerid, speedoTextDraw[playerid][16], 18656);
        PlayerTextDrawSetPreviewRot(playerid, speedoTextDraw[playerid][16], 90.000000, 0.000000, 0.000000, 1.000000);

        for (new i = 0; i < 17; ++i)
            PlayerTextDrawShow(playerid, PlayerText: speedoTextDraw[playerid][i]);

        PlayerTextDrawHide(playerid, speedoTextDraw[playerid][14]);
        PlayerTextDrawHide(playerid, speedoTextDraw[playerid][15]);
        PlayerTextDrawHide(playerid, speedoTextDraw[playerid][16]);
        
        new engine, lights, alarm, doors, bonnet, boot, objective;
        GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
        Speedo_SetVehicleLights(playerid, (!lights ? (false) : (true)));

        GameTextForPlayer(playerid, "~w~SVETLA PALITE/GASITE NA: ~y~Y", 2000, 3);
    }

    return 1;
}

stock Speedo_IsPlayerInMotorcycle(const vehicleid)
{
	switch (vehicleid)
    {
        case 462, 448, 581, 522, 461, 521, 523, 463, 468, 471: return 1;
    }
	
    return 0;
}

stock Speedo_IsPlayerInBicycle(const vehicleid)
{
    switch (vehicleid)
    {
        case 481, 509, 510: return 1;
    }

    return 0;
}

stock Speedo_SetVehicleLights(const playerid, bool: status = true)
{
    new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);

    if (!status)
    {
        PlayerTextDrawHide(playerid, speedoTextDraw[playerid][14]);
        PlayerTextDrawHide(playerid, speedoTextDraw[playerid][15]);
        PlayerTextDrawHide(playerid, speedoTextDraw[playerid][16]);

        Bit_Set(Bit: Bit_VehicleLights, playerid, false);
        PlayerTextDrawSetString(playerid, PlayerText: speedoTextDraw[playerid][10], "SVETLA: ~r~UGASENA");
        SetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, 0, alarm, doors, bonnet, boot, objective);
        return 1;
    }

    if (Speedo_IsPlayerInMotorcycle(GetVehicleModel(GetPlayerVehicleID(playerid))))
    {
        PlayerTextDrawHide(playerid, speedoTextDraw[playerid][14]);
        PlayerTextDrawHide(playerid, speedoTextDraw[playerid][15]);
        PlayerTextDrawShow(playerid, speedoTextDraw[playerid][16]);
    }

    else
    {
        PlayerTextDrawShow(playerid, speedoTextDraw[playerid][14]);
        PlayerTextDrawShow(playerid, speedoTextDraw[playerid][15]);
        PlayerTextDrawHide(playerid, speedoTextDraw[playerid][16]);
    }

    Bit_Let(Bit: Bit_VehicleLights, playerid);
    PlayerTextDrawSetString(playerid, PlayerText: speedoTextDraw[playerid][10], "SVETLA: ~g~UPALJENA");
    SetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, 1, alarm, doors, bonnet, boot, objective);

    return 1;
}

stock GetVehicleSpeed(const vehicleid)
{
    static
        pos_y,
        pos_x,
        pos_z,

        Float: veh_speed;

    GetVehicleVelocity(vehicleid, Float: pos_x, Float: pos_y, Float: pos_z);
    veh_speed = (floatsqroot((Float: pos_x * Float: pos_x) + (Float: pos_y * Float: pos_y) + (Float: pos_z * Float: pos_z)) * 180);
    
    return floatround(Float: veh_speed, floatround_round);
}

stock GetVehicleHP(const vehicleid)
{
    static health;
    GetVehicleHealth(vehicleid, Float: health);

    return _:health;
}

stock Speedo_GetPlayerVehicleFuel(const playerid) return gPlayerVehicleFuel[playerid];

// ---
// Timer update vehicle status
// ---
PTASK__ Speedo_UpdateVehStatus[1000](playerid)
{
    if (IsPlayerInAnyVehicle(playerid))
    {
        va_PlayerTextDrawSetString(
            playerid, PlayerText: speedoTextDraw[playerid][8],
            "Brzina: %d", GetVehicleSpeed(GetPlayerVehicleID(playerid))
        );

        va_PlayerTextDrawSetString(
            playerid, PlayerText: speedoTextDraw[playerid][11],
            "Ostecenje: %.0f", GetVehicleHP(GetPlayerVehicleID(playerid))
        );

        new health;
        GetVehicleHealth(GetPlayerVehicleID(playerid), Float: health);

        if (Float: health >= 800.00)
        {
            PlayerTextDrawColor(playerid, PlayerText: speedoTextDraw[playerid][12], 820791295);
            PlayerTextDrawShow(playerid, PlayerText: speedoTextDraw[playerid][12]);
        }

        else if (Float: health >= 600.00)
        {
            PlayerTextDrawColor(playerid, PlayerText: speedoTextDraw[playerid][12], X11_DARKGREEN);
            PlayerTextDrawShow(playerid, PlayerText: speedoTextDraw[playerid][12]);
        }

        else if (Float: health >= 300.00)
        {
            PlayerTextDrawColor(playerid, PlayerText: speedoTextDraw[playerid][12], X11_ORANGE);
            PlayerTextDrawShow(playerid, PlayerText: speedoTextDraw[playerid][12]);
        }

        else if (Float: health >= 0.00)
        {
            PlayerTextDrawColor(playerid, PlayerText: speedoTextDraw[playerid][12], X11_RED);
            PlayerTextDrawShow(playerid, PlayerText: speedoTextDraw[playerid][12]);
        }
    }
}

PTASK__ Speedo_FuelDown[FUEL_DOWN_TIME](playerid)
{
    if (IsPlayerInAnyVehicle(playerid))
    {
        if (!Speedo_GetPlayerVehicleFuel(playerid))
        {
            new engine, lights, alarm, doors, bonnet, boot, objective;
            GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
            SetVehicleParamsEx(GetPlayerVehicleID(playerid), 0, 0, alarm, doors, bonnet, boot, objective);
            return 1;
        }

        --gPlayerVehicleFuel[playerid];

        va_PlayerTextDrawSetString(
            playerid, PlayerText: speedoTextDraw[playerid][9],
            "GORIVO: %dL", Speedo_GetPlayerVehicleFuel(playerid)
        );
    }

    return 1;
}