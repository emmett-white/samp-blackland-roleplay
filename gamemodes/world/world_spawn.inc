#if defined _inc_world_spawn
    #undef _inc_world_spawn
#endif
// custom include-guard to ensure we don't duplicate
#if defined _world_spawn_included
    #endinput
#endif
#define _world_spawn_included

#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 6140, 657.570, -1498.328, 19.328, 0.250);
    RemoveBuildingForPlayer(playerid, 6193, 717.195, -1490.984, 15.757, 0.250);
    RemoveBuildingForPlayer(playerid, 1297, 675.750, -1540.429, 16.921, 0.250);
    RemoveBuildingForPlayer(playerid, 6138, 657.570, -1498.328, 19.328, 0.250);
    RemoveBuildingForPlayer(playerid, 621, 671.250, -1508.609, 12.656, 0.250);
    RemoveBuildingForPlayer(playerid, 1297, 674.078, -1514.632, 16.921, 0.250);
    RemoveBuildingForPlayer(playerid, 1297, 674.078, -1484.921, 16.921, 0.250);
    RemoveBuildingForPlayer(playerid, 1297, 675.601, -1457.882, 16.921, 0.250);
    RemoveBuildingForPlayer(playerid, 620, 678.781, -1512.796, 13.390, 0.250);
    RemoveBuildingForPlayer(playerid, 620, 677.664, -1485.781, 7.679, 0.250);
    RemoveBuildingForPlayer(playerid, 762, 680.945, -1522.906, 15.742, 0.250);
    RemoveBuildingForPlayer(playerid, 762, 680.945, -1496.101, 15.742, 0.250);
    RemoveBuildingForPlayer(playerid, 762, 680.945, -1468.625, 15.742, 0.250);
    RemoveBuildingForPlayer(playerid, 620, 682.304, -1530.820, 8.156, 0.250);
    RemoveBuildingForPlayer(playerid, 621, 682.648, -1533.828, 10.453, 0.250);
    RemoveBuildingForPlayer(playerid, 621, 682.570, -1512.242, 13.109, 0.250);
    RemoveBuildingForPlayer(playerid, 621, 682.648, -1508.484, 10.453, 0.250);
    RemoveBuildingForPlayer(playerid, 620, 681.843, -1504.031, 13.906, 0.250);
    RemoveBuildingForPlayer(playerid, 620, 682.859, -1464.921, 11.382, 0.250);
    RemoveBuildingForPlayer(playerid, 621, 681.640, -1485.039, 12.703, 0.250);
    RemoveBuildingForPlayer(playerid, 634, 765.023, -1546.320, 12.007, 0.250);
    RemoveBuildingForPlayer(playerid, 1297, 783.546, -1539.125, 15.937, 0.250);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeInit()
{
    new world_spawn;
    world_spawn = CreateDynamicObject(18981, 659.924133, -1467.004150, 13.424389, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 6487, "councl_law2", "Grass_lawn_128HV", 0x00000000);
    world_spawn = CreateDynamicObject(18981, 659.922851, -1491.960937, 13.422400, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 6487, "councl_law2", "Grass_lawn_128HV", 0x00000000);
    world_spawn = CreateDynamicObject(18981, 659.927185, -1516.950439, 13.422400, 0.006000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 6487, "councl_law2", "Grass_lawn_128HV", 0x00000000);
    world_spawn = CreateDynamicObject(18981, 659.925415, -1541.743896, 13.416399, 0.006000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 6487, "councl_law2", "Grass_lawn_128HV", 0x00000000);
    world_spawn = CreateDynamicObject(18981, 676.828979, -1538.936645, 13.422400, 0.006000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 6487, "councl_law2", "Grass_lawn_128HV", 0x00000000);
    world_spawn = CreateDynamicObject(18981, 676.828979, -1516.950439, 13.420399, 0.006000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 6487, "councl_law2", "Grass_lawn_128HV", 0x00000000);
    world_spawn = CreateDynamicObject(18981, 676.828979, -1491.960937, 13.426400, 0.006000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 6487, "councl_law2", "Grass_lawn_128HV", 0x00000000);
    world_spawn = CreateDynamicObject(18981, 676.828979, -1467.004150, 13.422400, 0.006000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 6487, "councl_law2", "Grass_lawn_128HV", 0x00000000);
    world_spawn = CreateDynamicObject(4008, 676.094116, -1506.254882, 21.508739, 0.000000, 0.000000, 185.000000, -1, -1, -1, 300.00, 300.00); 
    
    SetDynamicObjectMaterial(world_spawn, 0, 13691, "bevcunto2_lahills", "stonewall3_la", 0x00000000);
    SetDynamicObjectMaterial(world_spawn, 1, -1, "none", "none", 0xFFCCFFFF);
    SetDynamicObjectMaterial(world_spawn, 2, -1, "none", "none", 0xFFCCFFFF);
    SetDynamicObjectMaterial(world_spawn, 4, 18646, "matcolours", "grey-80-percent", 0x00000000);
    SetDynamicObjectMaterial(world_spawn, 6, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    SetDynamicObjectMaterial(world_spawn, 7, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    SetDynamicObjectMaterial(world_spawn, 8, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    SetDynamicObjectMaterial(world_spawn, 9, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    SetDynamicObjectMaterial(world_spawn, 10, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    
    world_spawn = CreateDynamicObject(19463, 656.586425, -1493.222778, 13.837599, 0.000000, -90.000000, 92.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 13691, "bevcunto2_lahills", "stonewall3_la", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 652.121582, -1493.382324, 13.835599, 0.000000, -90.000000, 92.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 13691, "bevcunto2_lahills", "stonewall3_la", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 647.388366, -1486.996215, 14.303370, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 647.388305, -1477.366943, 14.301400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 647.386596, -1467.762573, 14.299400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 647.385803, -1458.191162, 14.297400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 647.409240, -1500.077636, 14.303370, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 647.420104, -1509.686401, 14.301400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 647.419311, -1519.278808, 14.301400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 647.422973, -1528.896728, 14.299400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 647.422302, -1538.529663, 14.299400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 647.422302, -1548.146240, 14.297400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(18981, 661.637451, -1545.126586, 9.363989, -90.000000, 90.000000, 352.259552, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 10101, "2notherbuildsfe", "ferry_build14", 0xFF333333);
    world_spawn = CreateDynamicObject(19463, 652.206481, -1491.561157, 14.301400, 0.000000, 0.000000, 91.954002, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 661.828308, -1491.235839, 14.299400, 0.000000, 0.000000, 91.954002, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 661.681457, -1494.843505, 14.299400, 0.000000, 0.000000, 91.954002, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 652.132873, -1495.170288, 14.301400, 0.000000, 0.000000, 91.954002, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 651.635620, -1454.518798, 14.295399, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 661.263183, -1454.519042, 14.295399, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 670.785278, -1454.567260, 14.293399, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 675.456481, -1459.339843, 14.295399, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(19463, 675.458374, -1468.846191, 14.293399, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 3820, "boxhses_sfsx", "ws_ irongate", 0x00000000);
    world_spawn = CreateDynamicObject(18765, 681.173095, -1477.690917, 12.160189, 0.000000, 0.000000, 348.484710, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    world_spawn = CreateDynamicObject(18765, 671.362792, -1475.728759, 12.160189, 0.000000, 0.000000, 348.484710, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    world_spawn = CreateDynamicObject(18765, 674.927124, -1470.438476, 12.158200, 0.000000, 0.000000, 348.484710, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(world_spawn, 0, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    world_spawn = CreateDynamicObject(19481, 664.440307, -1507.533447, 25.572326, 0.000000, 0.000000, -175.100036, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterialText(world_spawn, 0, "{FFFFFF} GRAND", 120, "Ariel", 50, 1, 0x00000000, 0x00000000, 0);
    world_spawn = CreateDynamicObject(19481, 664.641784, -1495.140625, 28.972345, 0.000000, 0.000000, -175.100036, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterialText(world_spawn, 0, "{FFFFFF} HOTEL", 120, "Ariel", 50, 1, 0x00000000, 0x00000000, 0);
    
    world_spawn = CreateDynamicObject(18980, 674.456604, -1546.864257, 9.369059, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(869, 650.090881, -1489.514770, 14.351400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(869, 653.621398, -1489.512207, 14.351400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(869, 656.912475, -1489.380004, 14.351400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(869, 659.580932, -1489.268920, 14.351400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(869, 659.658325, -1496.721191, 14.351400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(869, 656.390075, -1497.025390, 14.351400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(869, 652.929626, -1497.092895, 14.351400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(869, 649.428039, -1497.307006, 14.351400, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(18013, 666.010070, -1488.803588, 24.737230, 0.000000, 0.000000, 95.031608, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(18013, 665.062316, -1478.615600, 24.737230, 0.000000, 0.000000, 95.031608, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(18013, 660.148620, -1515.953369, 24.737199, 0.000000, 0.000000, 79.874710, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(18013, 656.737426, -1535.619140, 24.737199, 0.000000, 0.000000, 79.874710, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(11500, 654.348815, -1475.701049, 13.398799, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(8991, 649.547058, -1476.285644, 14.592100, 0.000000, 0.000000, 90.555320, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(8991, 652.211425, -1476.452148, 14.592100, 0.000000, 0.000000, 90.555320, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(8991, 657.331726, -1476.427368, 14.592100, 0.000000, 0.000000, 90.555320, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(8991, 656.841308, -1462.784790, 14.592100, 0.000000, 0.000000, 90.555320, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(8991, 651.830261, -1463.666870, 14.592100, 0.000000, 0.000000, 90.555320, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(8991, 649.425964, -1463.907470, 14.592100, 0.000000, 0.000000, 90.555320, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(3515, 654.307861, -1465.401855, 13.253840, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(14469, 657.450012, -1485.576782, 14.524040, 0.000000, 0.000000, 3.370140, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(14469, 653.524841, -1485.608764, 14.524040, 0.000000, 0.000000, 3.370140, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(14469, 649.813659, -1485.751586, 14.524040, 0.000000, 0.000000, 3.370140, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(14469, 649.932678, -1500.666259, 14.524040, 0.000000, 0.000000, 3.370140, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(14469, 654.572875, -1500.546508, 14.524040, 0.000000, 0.000000, 3.370140, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(14469, 658.553466, -1500.404174, 14.524040, 0.000000, 0.000000, 3.370140, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(8991, 651.654602, -1510.359130, 14.592100, 0.000000, 0.000000, 83.441207, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(8991, 650.767822, -1523.180053, 14.592100, 0.000000, 0.000000, 88.329849, -1, -1, -1, 300.00, 300.00); 
    world_spawn = CreateDynamicObject(3515, 651.544677, -1515.473632, 13.253840, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);

    CreateDynamicPickup(1277, 1, Float: 645.5413, Float: -1493.5575, Float: 14.8128);
    CreateDynamic3DTextLabel("- Blackland RolePlay -\n\
        Vlasnik: "WHITE"emmett\n"MAIN_COLOR"Developer: "WHITE"emmett\n"MAIN_COLOR"Mapper: "WHITE"None\n\
        "MAIN_COLOR"Discord: "WHITE"https://discord.gg/"DISCORD_INVITE_LINK"\n\
        "MAIN_COLOR"- 2021/22 -", MAIN_COLOR_HEX,
        Float: 645.5413, Float: -1493.5575, Float: 14.8128, Float: 15.0
    );

    return Y_HOOKS_CONTINUE_RETURN_1;
}