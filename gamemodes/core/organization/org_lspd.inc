#if defined _inc_org_lspd
    #undef _inc_org_lspd
#endif
// custom include-guard to ensure we don't duplicate
#if defined _org_lspd_included
    #endinput
#endif
#define _org_lspd_included

#include <YSI_Coding\y_hooks>

/** Variables */
const MAX_LSPD_VEHICLES = (11);
static lspdVehicle[MAX_LSPD_VEHICLES];

/** Hooks */
hook OnGameModeInit()
{
    lspdVehicle[0] = AddStaticVehicleEx(596, Float: 1555.5271, Float: -1614.5618, Float: 13.0836, Float: 181.0543, 0, 0, 0, true);
    lspdVehicle[1] = AddStaticVehicleEx(596, Float: 1568.7434, Float: -1615.3671, Float: 13.0605, Float: 178.7417, 0, 0, 0, true);
    lspdVehicle[2] = AddStaticVehicleEx(596, Float: 1583.5939, Float: -1614.0125, Float: 13.0638, Float: 180.4347, 0, 0, 0, true);
    lspdVehicle[3] = AddStaticVehicleEx(596, Float: 1597.8556, Float: -1614.0237, Float: 13.0623, Float: 178.5848, 0, 0, 0, true);
    lspdVehicle[4] = AddStaticVehicleEx(579, Float: 1598.2275, Float: -1631.7709, Float: 13.2741, Float: 1.0266, 0, 0, 0, true);
    lspdVehicle[5] = AddStaticVehicleEx(579, Float: 1584.3545, Float: -1632.5948, Float: 13.2742, Float: 359.1021, 0, 0, 0, true);
    lspdVehicle[6] = AddStaticVehicleEx(579, Float: 1569.1897, Float: -1631.6890, Float: 13.2691, Float: 0.2207, 0, 0, 0, true);
    lspdVehicle[7] = AddStaticVehicleEx(522, Float: 1605.3846, Float: -1632.3119, Float: 12.9110, Float: 93.1448, 0, 0, 0, true);
    lspdVehicle[8] = AddStaticVehicleEx(522, Float: 1605.4634, Float: -1629.0072, Float: 12.9046, Float: 89.0219, 0, 0, 0, true);
    lspdVehicle[9] = AddStaticVehicleEx(522, Float: 1605.9266, Float: -1618.0750, Float: 12.9136, Float: 87.3598, 0, 0, 0, true);
    lspdVehicle[10] = AddStaticVehicleEx(522, Float: 1605.9331, Float: -1614.1830, Float: 12.9061, Float: 84.7595, 0, 0, 0, true);

    for (new i = 0; i < MAX_LSPD_VEHICLES; ++i)
    {
        CreateDynamic3DTextLabel("ORGANIZACIJA: "WHITE"Policija", MAIN_COLOR_HEX,
            Float: 0.0, Float: 0.0, Float: 0.0, Float: 20.0,
            .attachedvehicle = lspdVehicle[i]
        );
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if (Organization_IsPoliceVeh(vehicleid) && Organization_GetPlayerOrgID(playerid) != Organization_LSPD())
    {
        GameTextForPlayer(playerid, "~b~SAMO CLANOVI POLICIJE!", 2000, 3);
        ClearAnimations(playerid);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

/** Functions */
stock Organization_IsPoliceVeh(const vehicleid)
{
    for (new i = 0; i < sizeof lspdVehicle; ++i)
    {
        if (vehicleid == lspdVehicle[i])
        {
            return 1;
        }
    }

    return 0;
}