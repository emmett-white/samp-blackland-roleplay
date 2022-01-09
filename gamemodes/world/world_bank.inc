#if defined _inc_world_bank
    #undef _inc_world_bank
#endif
// custom include-guard to ensure we don't duplicate
#if defined _world_bank_included
    #endinput
#endif
#define _world_bank_included

#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    // Bank Ext
    new nlbbankazid = CreateDynamicObjectEx(19461, 1479.77710, -1021.77594, 21.88970, 90.00000, 90.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid1 = CreateDynamicObjectEx(19461, 1483.27905, -1021.77612, 24.21360, 90.00000, 90.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid2 = CreateDynamicObjectEx(19461, 1486.78064, -1021.77612, 21.88970, 90.00000, 90.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid3 = CreateDynamicObjectEx(19461, 1440.77246, -1021.77612, 24.21360, 90.00000, 90.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid4 = CreateDynamicObjectEx(19461, 1444.25806, -1021.77612, 21.88970, 90.00000, 90.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid5 = CreateDynamicObjectEx(19461, 1437.27466, -1021.77612, 21.88970, 90.00000, 90.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid6 = CreateDynamicObjectEx(18766, 1445.74805, -1019.40210, 23.33440, 90.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid7 = CreateDynamicObjectEx(18766, 1436.41919, -1019.40210, 23.33440, 90.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid8 = CreateDynamicObjectEx(18980, 1431.79980, -1021.41541, 18.37600, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid9 = CreateDynamicObjectEx(18766, 1436.41919, -1019.40210, 30.37490, 90.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid10 = CreateDynamicObjectEx(18766, 1445.74805, -1019.40210, 30.37490, 90.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid11 = CreateDynamicObjectEx(18766, 1477.38989, -1019.40210, 30.37490, 90.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid12 = CreateDynamicObjectEx(18980, 1472.64819, -1021.41541, 18.37600, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid13 = CreateDynamicObjectEx(18766, 1487.37158, -1019.40210, 30.37490, 90.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid14 = CreateDynamicObjectEx(18766, 1477.38989, -1019.40210, 23.33440, 90.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid15 = CreateDynamicObjectEx(18766, 1487.37158, -1019.40210, 23.33440, 90.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid16 = CreateDynamicObjectEx(18980, 1491.87195, -1021.41541, 18.37600, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankazid17 = CreateDynamicObjectEx(18980, 1451.20325, -1021.41541, 18.37600, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbbankazid, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid1, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid2, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid3, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid4, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid5, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid6, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid7, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid8, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid9, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid10, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid11, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid12, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid13, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid14, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid15, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid16, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	SetDynamicObjectMaterial(nlbbankazid17, 0, 3980, "cityhall_lan", "LAcityhwal1" ,0xFF333399);
	
    new nlbankazidb = CreateDynamicObjectEx(18981, 1459.64050, -1009.32507, 30.36760, 0.00000, 90.00000, 0.00000, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbankazidb, 0, 3922, "bistro", "Marble2", 0xFFFFFFFF);
	
    new nlbbankaprozori = CreateDynamicObjectEx(19377, 1446.45642, -1021.75537, 25.53990, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	new nlbbankaprozori1 = CreateDynamicObjectEx(19377, 1436.83936, -1021.75537, 25.53990, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	new nlbbankaprozori2 = CreateDynamicObjectEx(19377, 1477.65601, -1021.75537, 25.43990, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	new nlbbankaprozori3 = CreateDynamicObjectEx(19377, 1487.27551, -1021.75537, 25.43990, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbbankaprozori, 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(nlbbankaprozori1, 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(nlbbankaprozori2, 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(nlbbankaprozori3, 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
	
    new nlbbankadrzaci = CreateDynamicObjectEx(18981, 1472.17896, -1011.73688, 18.35960, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankadrzaci1 = CreateDynamicObjectEx(18981, 1451.94653, -1011.73688, 18.35960, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankadrzaci2 = CreateDynamicObjectEx(19377, 1469.80383, -1018.06042, 25.43990, 0.00000, 0.00000, -141.16319, 300.0, 300.0 );
	new nlbbankadrzaci3 = CreateDynamicObjectEx(19377, 1454.28711, -1018.05719, 25.43990, 0.00000, 0.00000, 141.16316, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbbankadrzaci, 0, 3922, "bistro", "Marble2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(nlbbankadrzaci1, 0, 3922, "bistro", "Marble2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(nlbbankadrzaci2, 0, 3922, "bistro", "Marble2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(nlbbankadrzaci3, 0, 3922, "bistro", "Marble2", 0xFFFFFFFF);
	
    new nlbbankakodprozora = CreateDynamicObjectEx(19377, 1458.15833, -1014.80792, 24.68170, 0.00000, 90.00000, 90.00000, 300.0, 300.0 );
	new nlbbankakodprozora1 = CreateDynamicObjectEx(19377, 1458.15833, -1014.80792, 27.76380, 0.00000, 90.00000, 90.00000, 300.0, 300.0 );
	new nlbbankakodprozora2 = CreateDynamicObjectEx(19377, 1448.53894, -1014.80792, 27.76380, 0.00000, 90.00000, 90.00000, 300.0, 300.0 );
	new nlbbankakodprozora3 = CreateDynamicObjectEx(19377, 1448.53894, -1014.80792, 24.68170, 0.00000, 90.00000, 90.00000, 300.0, 300.0 );
	new nlbbankakodprozora4 = CreateDynamicObjectEx(19377, 1461.19824, -1015.24451, 27.76380, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankakodprozora5 = CreateDynamicObjectEx(19377, 1456.19861, -1015.24451, 27.76380, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankakodprozora6 = CreateDynamicObjectEx(19377, 1467.76990, -1014.80792, 24.68170, 0.00000, 90.00000, 90.00000, 300.0, 300.0 );
	new nlbbankakodprozora7 = CreateDynamicObjectEx(19377, 1466.86279, -1015.24451, 27.76380, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankakodprozora8 = CreateDynamicObjectEx(19377, 1467.76990, -1014.80792, 27.76380, 0.00000, 90.00000, 90.00000, 300.0, 300.0 );
    SetDynamicObjectMaterial(nlbbankakodprozora, 0, 3980, "cityhall_lan", "LAcityhwal1");
	SetDynamicObjectMaterial(nlbbankakodprozora1, 0, 3980, "cityhall_lan", "LAcityhwal1");
	SetDynamicObjectMaterial(nlbbankakodprozora2, 0, 3980, "cityhall_lan", "LAcityhwal1");
	SetDynamicObjectMaterial(nlbbankakodprozora3, 0, 3980, "cityhall_lan", "LAcityhwal1");
	SetDynamicObjectMaterial(nlbbankakodprozora4, 0, 3980, "cityhall_lan", "LAcityhwal1");
	SetDynamicObjectMaterial(nlbbankakodprozora5, 0, 3980, "cityhall_lan", "LAcityhwal1");
	SetDynamicObjectMaterial(nlbbankakodprozora6, 0, 3980, "cityhall_lan", "LAcityhwal1");
	SetDynamicObjectMaterial(nlbbankakodprozora7, 0, 3980, "cityhall_lan", "LAcityhwal1");
	SetDynamicObjectMaterial(nlbbankakodprozora8, 0, 3980, "cityhall_lan", "LAcityhwal1");
	
    new nlbbankauprozor = CreateDynamicObjectEx(19377, 1467.29492, -1019.96454, 25.43990, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	new nlbbankauprozor1 = CreateDynamicObjectEx(19377, 1457.69067, -1019.96448, 25.43990, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	new nlbbankauprozor2 = CreateDynamicObjectEx(19377, 1448.06873, -1019.96448, 25.43990, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbbankauprozor, 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(nlbbankauprozor1, 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(nlbbankauprozor2, 0, 3979, "civic01_lan", "sl_laglasswall2", 0xFFFFFFFF);
	
    
    new nlbbankaokovrata = CreateDynamicObjectEx(19372, 1461.28931, -1019.99152, 24.35416, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbbankaokovrata, 0, 3980, "cityhall_lan", "LAcityhwal1");
	
    
    new nlbbankavrata = CreateDynamicObjectEx(1533, 1459.78601, -1020.10840, 23.28017, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankavrata1 = CreateDynamicObjectEx(1533, 1461.26758, -1020.12244, 23.28017, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbbankavrata, 2, 12954, "sw_furniture", "CJ_WOOD5");
	SetDynamicObjectMaterial(nlbbankavrata1, 2, 12954, "sw_furniture", "CJ_WOOD5");
	
    
    new nlbbankastakla = CreateDynamicObjectEx(19325, 1455.43188, -1022.87579, 29.28750, 0.00000, 40.00000, 90.00000, 300.0, 300.0 );
	new nlbbankastakla1 = CreateDynamicObjectEx(19325, 1462.04651, -1022.87579, 29.28750, 0.00000, 40.00000, 90.00000, 300.0, 300.0 );
	new nlbbankastakla2 = CreateDynamicObjectEx(19325, 1468.67261, -1022.87579, 29.28750, 0.00000, 40.00000, 90.00000, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbbankastakla, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankastakla1, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankastakla2, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	
    new nlbbankaokostakla = CreateDynamicObjectEx(19089, 1471.71216, -1024.19995, 27.71170, 0.00000, 90.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaokostakla1 = CreateDynamicObjectEx(19089, 1466.92017, -1024.19995, 27.71170, 0.00000, 90.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaokostakla2 = CreateDynamicObjectEx(19089, 1459.53796, -1024.19995, 27.71170, 0.00000, 90.00000, 0.00000, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbbankaokostakla, 0, 2361, "shopping_freezers", "white", 0xFF000000 );
	SetDynamicObjectMaterial(nlbbankaokostakla1, 0, 2361, "shopping_freezers", "white", 0xFF000000 );
	SetDynamicObjectMaterial(nlbbankaokostakla2, 0, 2361, "shopping_freezers", "white", 0xFF000000 );
	
    new nlbbankaokobankomata = CreateDynamicObjectEx(19372, 1474.59607, -1021.76257, 23.73596, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	new nlbbankaokobankomata1 = CreateDynamicObjectEx(19372, 1449.10791, -1021.76257, 23.73600, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbbankaokobankomata, 0, 3922, "bistro", "Marble2", 0xFFFFFFFF);
	SetDynamicObjectMaterial(nlbbankaokobankomata1, 0, 3922, "bistro", "Marble2", 0xFFFFFFFF);
	
    new nlbbankaulazpod = CreateDynamicObjectEx(19377, 1456.73901, -1019.17462, 22.74500, 0.00000, 90.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaulazpod1 = CreateDynamicObjectEx(19377, 1467.23364, -1019.17462, 22.74500, 0.00000, 90.00000, 0.00000, 300.0, 300.0 );
	SetDynamicObjectMaterial(nlbbankaulazpod, 0, 3980, "cityhall_lan", "sl_plazatile01", 0xFFFFFFFF);
	SetDynamicObjectMaterial(nlbbankaulazpod1, 0, 3980, "cityhall_lan", "sl_plazatile01", 0xFFFFFFFF);
	
    new nlbbankaogradice = CreateDynamicObjectEx(970, 1440.36597, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice1 = CreateDynamicObjectEx(970, 1444.50708, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice2 = CreateDynamicObjectEx(970, 1448.69287, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice3 = CreateDynamicObjectEx(970, 1452.83740, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice4 = CreateDynamicObjectEx(970, 1456.99866, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice5 = CreateDynamicObjectEx(970, 1465.06616, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice6 = CreateDynamicObjectEx(970, 1469.16821, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice7 = CreateDynamicObjectEx(970, 1473.29187, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice8 = CreateDynamicObjectEx(970, 1477.44678, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice9 = CreateDynamicObjectEx(970, 1481.56409, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice10 = CreateDynamicObjectEx(970, 1485.68469, -1028.59314, 23.26950, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	new nlbbankaogradice11 = CreateDynamicObjectEx(970, 1436.20435, -1028.59314, 23.26951, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	
    SetDynamicObjectMaterial(nlbbankaogradice, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice1, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice1, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice2, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice2, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice3, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice3, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice4, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice4, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice5, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice5, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice6, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice6, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice7, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice7, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice8, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice8, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice9, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice9, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice10, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice10, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	SetDynamicObjectMaterial(nlbbankaogradice11, 1, 12954, "sw_furniture", "CJ_WOOD5", 0xFFD3D3D3);
	SetDynamicObjectMaterial(nlbbankaogradice11, 0, 2361, "lsmall_shops", "lsmall_window01", 0xFF333399);
	
    CreateDynamicObjectEx(1280, 1476.48804, -1028.07996, 23.18890, 0.00000, 0.00000, -90.00000, 300.0, 300.0 );
	CreateDynamicObjectEx(1280, 1448.99744, -1028.07996, 23.18890, 0.00000, 0.00000, -90.00000, 300.0, 300.0 );
	CreateDynamicObjectEx(640, 1440.72058, -1026.62976, 23.33450, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	CreateDynamicObjectEx(717, 1437.18323, -1026.47461, 22.92554, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	CreateDynamicObjectEx(1232, 1451.71399, -1026.54749, 25.38451, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	CreateDynamicObjectEx(19526, 1449.11694, -1021.29169, 23.61520, 40.00000, 0.00000, 0.00000, 300.0, 300.0 );
	CreateDynamicObjectEx(640, 1461.16956, -1026.62976, 23.33449, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	CreateDynamicObjectEx(1232, 1472.04309, -1026.54749, 25.38450, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	CreateDynamicObjectEx(717, 1486.61890, -1026.44958, 22.92349, 0.00000, 0.00000, 0.00000, 300.0, 300.0 );
	CreateDynamicObjectEx(640, 1483.06165, -1026.64038, 23.33450, 0.00000, 0.00000, 90.00000, 300.0, 300.0 );
	CreateDynamicObjectEx(19526, 1474.51611, -1021.27130, 23.61520, 40.00000, 0.00000, 0.00000, 300.0, 300.0 );
	
    new nlblogo;
	nlblogo = CreateDynamicObjectEx(19325,1461.297,-1020.508,32.086,0.000,0.000,89.499, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlblogo, 0, "None", 10, "Ariel", 20, 0, 0, -13421671, 1);
	nlblogo = CreateDynamicObjectEx(19325,1460.443,-1020.536,32.826,0.000,0.000,88.899, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlblogo, 0, "NLB BANKA", 140, "Quartz MS", 70, 1, -2894893, 0, 1);
	nlblogo = CreateDynamicObjectEx(19325,1463.444,-1020.612,32.916,0.000,0.000,89.500, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlblogo, 0, "n", 130, "Webdings", 85, 0, -2894893, 0, 1);
	nlblogo = CreateDynamicObjectEx(19325,1463.234,-1020.659,32.936,0.000,0.000,86.299, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlblogo, 0, "/", 140, "Ariel", 120, 1, -13421671, 0, 1);
	nlblogo = CreateDynamicObjectEx(19325,1463.584,-1020.615,32.810,0.000,0.000,89.699, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlblogo, 0, "o", 140, "Ariel", 90, 1, -13421671, 0, 1);
	
    new nlbreklame;
	nlbreklame = CreateDynamicObjectEx(19325,1440.560,-1021.887,25.836,0.000,0.000,90.400, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlbreklame, 0, "NLB Razvojna Banka", 140, "Segoe Keycaps", 50, 1, -2894893, 0, 1);
	nlbreklame = CreateDynamicObjectEx(19325,1440.555,-1021.867,24.986,0.000,0.000,90.000, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlbreklame, 0, "Fiksna kamata do kraja otplate", 140, "Segoe Keycaps", 40, 1, -2894893, 0, 1);
	nlbreklame = CreateDynamicObjectEx(19325,1483.184,-1021.872,26.196,0.000,0.000,90.099, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlbreklame, 0, "NLB Razvojna Banka", 140, "Segoe Keycaps", 50, 1, -2894893, 0, 1);
	nlbreklame = CreateDynamicObjectEx(19325,1483.101,-1021.872,25.346,0.000,0.000,90.000, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlbreklame, 0, "Mislite Unapred", 140, "Segoe Keycaps", 40, 1, -2894893, 0, 1);
	nlbreklame = CreateDynamicObjectEx(19466,1474.531,-1021.872,25.376,0.000,0.000,89.399, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlbreklame, 0, "0-24H", 140, "Segoe Keycaps", 60, 1, -13421671, 0, 1);
	nlbreklame = CreateDynamicObjectEx(19466,1449.164,-1021.863,25.396,0.000,0.000,90.600, 300.0, 300.0 );
	SetDynamicObjectMaterialText(nlbreklame, 0, "0-24H", 140, "Segoe Keycaps", 60, 1, -13421671, 0, 1);

    // Banka Int
    static bank_int;
    bank_int = CreateDynamicObject(2773, 1426.076904, -981.189880, 995.657897, 0.000000, 0.000000, 89.160102, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetObjectMaterial(bank_int, 1, 19063, "xmasorbs", "orbcap", 0x00000000);
	bank_int = CreateDynamicObject(2773, 1426.076904, -979.056884, 995.657897, 0.000000, 0.000000, 89.160102, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetObjectMaterial(bank_int, 1, 19063, "xmasorbs", "orbcap", 0x00000000);
	bank_int = CreateDynamicObject(2773, 1426.076904, -976.844909, 995.657897, 0.000000, 0.000000, 89.160102, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetObjectMaterial(bank_int, 1, 19063, "xmasorbs", "orbcap", 0x00000000);
	bank_int = CreateDynamicObject(2773, 1426.076904, -974.632873, 995.657897, 0.000000, 0.000000, 89.160102, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetObjectMaterial(bank_int, 1, 19063, "xmasorbs", "orbcap", 0x00000000);
	bank_int = CreateDynamicObject(2773, 1426.076904, -972.420898, 995.657897, 0.000000, 0.000000, 89.160102, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetObjectMaterial(bank_int, 1, 19063, "xmasorbs", "orbcap", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1425.529174, -987.173828, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1425.555908, -977.531677, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1425.529174, -967.908813, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1436.030151, -996.807800, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1435.950195, -987.233642, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1436.030151, -977.539794, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1436.011840, -967.929321, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1446.530761, -987.191772, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1457.031860, -987.191772, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1457.031860, -977.557800, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1446.531860, -977.557800, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1446.531860, -967.924804, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1446.532226, -996.811828, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(19379, 1436.030151, -1001.035827, 995.023071, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 16639, "a51_labs", "dam_terazzo", 0x00000000);
	bank_int = CreateDynamicObject(18762, 1431.306762, -982.132202, 996.737915, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 9514, "711_sfw", "shingles2", 0x00000000);
	bank_int = CreateDynamicObject(18762, 1440.746948, -989.750000, 996.737915, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 9514, "711_sfw", "shingles2", 0x00000000);
	bank_int = CreateDynamicObject(18762, 1440.789794, -982.051025, 996.737915, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 9514, "711_sfw", "shingles2", 0x00000000);
	bank_int = CreateDynamicObject(18762, 1444.834716, -982.127807, 996.737915, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 9514, "711_sfw", "shingles2", 0x00000000);
	bank_int = CreateDynamicObject(18762, 1444.848876, -989.641540, 996.737915, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 9514, "711_sfw", "shingles2", 0x00000000);
	SetObjectMaterial(bank_int, 1, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	bank_int = CreateDynamicObject(18762, 1433.173461, -989.853149, 995.562683, 0.000000, 90.000000, 315.249511, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 9514, "711_sfw", "shingles2", 0x00000000);
	bank_int = CreateDynamicObject(18762, 1431.719848, -988.423339, 995.542724, 0.000000, 90.000000, 315.249511, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 9514, "711_sfw", "shingles2", 0x00000000);
	bank_int = CreateDynamicObject(18762, 1434.732543, -991.383972, 996.737915, 0.000000, 0.000000, 44.700931, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 9514, "711_sfw", "shingles2", 0x00000000);
	bank_int = CreateDynamicObject(18762, 1429.906250, -986.581726, 996.737915, 0.000000, 0.000000, 44.700931, .streamdistance = 300.0, .drawdistance = 300.0);
	SetObjectMaterial(bank_int, 0, 9514, "711_sfw", "shingles2", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bank_int = CreateDynamicObject(14602, 1443.335205, -985.863281, 1000.470825, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1420.344360, -977.946594, 996.856384, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1420.344360, -968.312622, 996.856384, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1425.395629, -997.238098, 998.695312, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19379, 1425.549072, -996.805480, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1425.395629, -987.599121, 998.699279, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1425.395874, -977.990112, 998.695312, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1425.395629, -968.336120, 998.695312, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1425.152099, -1001.583007, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1444.421752, -992.999206, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1425.240966, -1001.648437, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1435.600219, -997.795593, 996.856384, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1430.772460, -1001.595275, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1569, 1432.615356, -1001.550109, 995.107727, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19388, 1438.838378, -993.016418, 996.854492, 0.000000, 0.000000, 90.900001, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19431, 1436.570312, -993.033691, 996.851928, 0.000000, 0.000000, 89.950401, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19431, 1436.320312, -993.033691, 996.853881, 0.000000, 0.000000, 89.950401, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1425.152099, -970.081970, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1427.718139, -970.081970, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1439.006103, -970.081970, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1448.526123, -970.081970, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19388, 1433.382446, -970.084411, 996.862487, 0.000000, 0.000000, 89.782897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1444.406372, -976.562622, 996.856384, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1444.406372, -966.930603, 996.856384, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1444.406372, -994.985595, 996.856384, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1435.893554, -997.238098, 998.695312, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1435.893554, -987.599121, 998.705322, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1435.893554, -977.970092, 998.705322, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1435.893554, -968.336120, 998.695312, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1446.391601, -968.336120, 998.695312, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1446.391601, -977.970092, 998.697326, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1446.391601, -987.599121, 998.697326, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1444.406372, -986.196594, 1000.162597, -180.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1569, 1457.747436, -985.028808, 995.104309, 0.000000, 0.000000, -90.059997, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1446.358642, -997.238098, 998.695312, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(16101, 1424.504638, -981.150085, 990.734619, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(16101, 1424.504638, -978.966125, 990.734619, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(16101, 1424.504638, -976.782104, 990.734619, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(16101, 1424.504638, -974.598083, 990.734619, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(16101, 1424.504638, -972.414123, 990.734619, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19325, 1424.514282, -980.050781, 999.003906, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19325, 1424.514282, -973.422790, 999.003906, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2164, 1420.474487, -980.712463, 995.106018, 0.000000, 0.000000, 87.659980, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1514, 1424.187255, -980.666320, 996.206115, 0.000000, 0.000000, 89.580001, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1514, 1424.187255, -978.533325, 996.206115, 0.000000, 0.000000, 89.580001, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1514, 1424.187255, -976.321289, 996.206115, 0.000000, 0.000000, 89.580001, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1514, 1424.187255, -974.188293, 996.206115, 0.000000, 0.000000, 89.580001, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1514, 1424.187255, -971.976318, 996.206115, 0.000000, 0.000000, 89.580001, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1422.447875, -971.872131, 995.107421, 0.000000, 0.000000, -78.180023, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1422.447875, -973.373107, 995.107421, 0.000000, 0.000000, -86.220016, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1422.447875, -975.506103, 995.107421, 0.000000, 0.000000, -94.200027, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1422.447875, -977.639099, 995.107421, 0.000000, 0.000000, -93.600021, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1422.447875, -979.930114, 995.107421, 0.000000, 0.000000, -83.640007, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1449.151123, -981.530029, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1458.767089, -981.530029, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1449.152099, -990.174987, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1458.783081, -990.174987, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1449.579589, -985.771118, 998.232299, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1459.645629, -985.733093, 998.231323, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1457.406372, -985.676574, 996.856384, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1569, 1457.370605, -982.481689, 995.105712, 0.000000, 0.000000, 269.376312, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1569, 1457.375488, -985.462585, 995.105712, 0.000000, 0.000000, 89.998001, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1569, 1457.368652, -986.574829, 995.105712, 0.000000, 0.000000, 269.376312, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1569, 1457.375854, -989.577575, 995.105712, 0.000000, 0.000000, 89.998001, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(14576, 1435.294067, -987.928710, 990.715881, 0.000000, 0.000000, -0.360000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19388, 1438.868408, -1002.636413, 996.854492, 0.000000, 0.000000, 90.900001, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1440.540649, -997.846191, 996.856384, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1437.238769, -997.849792, 996.856384, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19377, 1440.833618, -1004.669128, 998.268310, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2634, 1441.069091, -1004.531677, 992.320007, 0.000000, 0.000000, 270.070404, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2198, 1433.273315, -996.867980, 989.920471, 0.000000, 0.000000, 178.639602, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2198, 1433.273315, -994.026000, 989.920471, 0.000000, 0.000000, 178.639602, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2198, 1433.273315, -990.890014, 989.920471, 0.000000, 0.000000, 178.639602, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2198, 1433.273315, -1000.004028, 989.920471, 0.000000, 0.000000, 178.639602, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1432.722778, -998.973632, 989.919006, 0.000000, 0.000000, -167.280029, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1432.605712, -995.737854, 989.919006, 0.000000, 0.000000, 175.128158, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1432.605712, -992.797912, 989.919006, 0.000000, 0.000000, 194.127502, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1432.605712, -989.759887, 989.919006, 0.000000, 0.000000, 186.494781, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(16782, 1443.085449, -993.574951, 992.763244, 0.000000, 0.000000, 179.018188, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3397, 1442.956420, -993.624694, 989.947265, 0.000000, 0.000000, 357.182830, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3386, 1442.722412, -996.432495, 989.895996, 0.000000, 0.000000, 176.062500, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3386, 1442.722412, -997.608520, 989.914001, 0.000000, 0.000000, 176.062500, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3386, 1442.874389, -990.380493, 989.914001, 0.000000, 0.000000, 356.840911, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3386, 1442.874389, -989.246520, 989.914001, 0.000000, 0.000000, 356.840911, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1723, 1439.226684, -972.442138, 995.051513, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1723, 1442.609863, -973.581909, 995.051513, 0.000000, 0.000000, 269.473297, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1723, 1441.659912, -976.881713, 995.051513, 0.000000, 0.000000, 179.192596, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1723, 1438.095458, -975.584899, 995.051513, 0.000000, 0.000000, 86.827003, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1817, 1439.952514, -975.208557, 995.112182, 0.000000, 0.000000, -0.360000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2011, 1437.906372, -970.722106, 995.119506, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2002, 1439.032470, -970.708007, 995.119506, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1776, 1440.219238, -970.603820, 996.182189, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2816, 1439.914794, -974.765197, 995.623779, 0.000000, 0.000000, -66.180000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2245, 1440.357788, -974.716979, 995.854125, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1549, 1441.389038, -970.580200, 995.072814, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2961, 1436.193603, -992.914489, 996.433715, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2690, 1436.225463, -992.867980, 996.925720, 0.000000, 0.000000, 169.800003, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1999, 1435.731567, -1005.598632, 995.122375, 0.000000, 0.000000, 177.899978, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1435.428955, -1003.918395, 995.120788, 0.000000, 0.000000, 146.819976, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2606, 1433.610717, -1004.312316, 996.302795, 0.000000, 0.000000, 89.940002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2606, 1433.610717, -1004.312316, 996.734802, 0.000000, 0.000000, 89.940002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2606, 1433.610717, -1004.312316, 997.166809, 0.000000, 0.000000, 89.940002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2894, 1435.514770, -1005.658752, 995.935119, 0.000000, 0.000000, -156.299880, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(348, 1435.810424, -1005.498413, 995.935180, 91.000000, 0.000000, 38.220020, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2839, 1434.896240, -1005.614929, 995.123474, 0.000000, 0.000000, 28.739999, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2690, 1434.280395, -1002.785461, 996.387817, 0.000000, 0.000000, -4.260000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1892, 1456.529418, -986.437805, 995.140930, 0.000000, 0.000000, 86.760002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1892, 1456.529418, -990.613769, 995.140930, 0.000000, 0.000000, 86.760002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1892, 1456.529418, -982.261779, 995.140930, 0.000000, 0.000000, 86.760002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(14633, 1426.066040, -979.430664, 996.566833, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2811, 1456.851806, -986.051086, 995.106018, 0.000000, 0.000000, 78.960021, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3386, 1442.874389, -988.142517, 989.914001, 0.000000, 0.000000, 356.840911, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3386, 1442.874389, -987.038513, 989.914001, 0.000000, 0.000000, 356.840911, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3386, 1442.722412, -998.808471, 989.914001, 0.000000, 0.000000, 176.062500, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3386, 1442.722412, -1000.008483, 989.914001, 0.000000, 0.000000, 176.062500, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3391, 1440.513793, -987.036376, 989.895996, 0.000000, 0.000000, 89.760032, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(3392, 1436.924804, -987.026550, 989.893981, 0.000000, 0.000000, 89.819976, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1806, 1441.295532, -993.010253, 989.921325, 0.000000, 0.000000, -119.940010, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2634, 1439.314453, -1002.530578, 992.320007, 0.000000, 0.000000, 359.650299, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1502, 1438.058471, -992.990112, 995.106750, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2690, 1440.722167, -1010.176391, 994.914245, 0.000000, 0.000000, -90.419990, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2690, 1433.677124, -1004.352600, 992.917602, 0.000000, 0.000000, 83.580017, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2690, 1440.743041, -1010.164916, 991.041687, 0.000000, 0.000000, -88.080017, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2690, 1433.689086, -1004.277282, 988.577697, 0.000000, 0.000000, 83.940032, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2690, 1433.566650, -1009.760070, 986.422058, 0.000000, 0.000000, 83.700042, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2332, 1436.248046, -964.551818, 982.938415, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2332, 1437.015136, -964.551818, 982.938415, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2332, 1436.189086, -964.551818, 983.764404, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2332, 1435.422119, -964.551818, 983.764404, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2332, 1434.655151, -964.551818, 983.764404, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2332, 1434.655151, -964.551818, 982.938415, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2332, 1433.888183, -964.551818, 982.938415, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19273, 1437.112426, -1001.313964, 983.990173, 0.000000, 0.000000, -92.339996, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1829, 1435.417602, -964.945190, 982.882019, 0.000000, 0.000000, -0.540000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19302, 1433.878540, -1000.645812, 983.760681, 0.000000, 0.000000, -179.820007, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19302, 1435.364868, -1000.657287, 985.859680, 0.000000, -90.000000, 0.180000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1428.695190, -987.153808, 996.852111, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1423.942871, -982.422790, 996.852111, 0.000000, 0.000000, 90.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(16101, 1424.495117, -970.257995, 990.734619, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1502, 1432.573120, -970.265686, 995.106750, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19379, 1428.764038, -958.263671, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19379, 1418.300537, -958.270202, 995.019104, 0.000000, -90.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19325, 1435.814941, -976.727355, 996.285522, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19325, 1435.813842, -970.088806, 996.285522, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1425.151977, -963.489379, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1435.878295, -965.193359, 996.856384, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1434.748657, -963.482055, 996.856384, 0.000000, 0.000000, 89.991897, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2165, 1425.922485, -969.057373, 995.104614, 0.000000, 0.000000, 180.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1715, 1425.347167, -967.878967, 995.106506, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2165, 1429.682739, -969.381530, 995.104614, 0.000000, 0.000000, 180.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(1715, 1428.759765, -968.028869, 995.106506, 0.000000, 0.000000, 43.209701, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2007, 1420.981323, -969.303283, 995.057983, 0.000000, 0.000000, 89.760002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2007, 1421.012207, -968.303405, 995.057983, 0.000000, 0.000000, 89.760002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2007, 1421.022949, -967.302551, 995.057983, 0.000000, 0.000000, 89.760002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2007, 1421.022949, -967.302612, 996.456604, 0.000000, 0.000000, 89.760002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2007, 1421.012207, -968.303405, 996.456604, 0.000000, 0.000000, 89.760002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2007, 1420.981323, -969.303283, 996.456604, 0.000000, 0.000000, 89.760002, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2164, 1420.455078, -965.624023, 995.106018, 0.000000, 0.000000, 87.659980, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(14633, 1423.332763, -969.138671, 995.727905, 0.000000, 0.000000, -90.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19325, 1441.629760, -980.143310, 996.285522, 0.000000, 0.000000, 90.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19172, 1428.772094, -983.846069, 997.039184, 0.000000, 0.000000, 90.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19450, 1432.128173, -989.586303, 996.852111, 0.000000, 0.000000, 45.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19325, 1432.344116, -988.990112, 997.027587, 0.000000, 0.000000, 45.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19603, 1432.454345, -989.783813, 996.319580, 0.000000, 90.000000, -135.000015, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19603, 1431.488647, -988.808776, 996.319580, 0.000000, 90.000000, 45.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19464, 1431.848632, -989.360717, 995.966918, 0.000000, 0.000000, 45.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19839, 1433.289184, -990.382446, 996.107788, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19839, 1432.250610, -989.302124, 996.061218, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19839, 1431.277954, -988.376281, 996.061218, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19839, 1430.540039, -987.642395, 996.061218, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19630, 1433.054443, -990.040222, 996.885925, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19630, 1432.085205, -989.136779, 996.885925, 0.000000, 0.000000, 283.598632, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19630, 1432.706909, -989.542541, 997.659851, 0.000000, 0.000000, 100.014816, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19630, 1431.027099, -988.040771, 996.885925, -2.000000, -38.000000, 154.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19630, 1431.479858, -988.458801, 996.885925, -2.000000, 22.000000, -154.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(19630, 1433.383422, -990.364440, 996.442871, 0.000000, 0.000000, 276.528381, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2075, 1432.102539, -989.076354, 995.664794, 0.000000, 180.000000, 315.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2244, 1429.532714, -985.499572, 995.375915, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2244, 1435.611816, -991.893737, 995.375915, 0.000000, 0.000000, 0.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2164, 1435.736938, -964.179321, 995.106018, 0.000000, 0.000000, -90.000000, .streamdistance = 300.0, .drawdistance = 300.0);
	bank_int = CreateDynamicObject(2164, 1435.749511, -965.952331, 995.106018, 0.000000, 0.000000, -90.000000, .streamdistance = 300.0, .drawdistance = 300.0);

    CreateDynamicPickup(WORLD_PICKUP_ENTER_EXIT, 1, Float: 1461.2765, Float: -1021.2448, Float: 24.0317);
    CreateDynamicPickup(WORLD_PICKUP_ENTER_EXIT, 1, Float: 1454.8555, Float: -985.5658, Float: 996.1050);
    CreateDynamicPickup(1239, 1, Float: 1425.9658, Float: -977.8441, Float: 996.1050);
    CreateDynamicPickup(1239, 1, Float: 1425.7753, Float: -975.6477, Float: 996.1050);
    CreateDynamicPickup(1239, 1, Float: 1425.7939, Float: -973.4025, Float: 996.1050);

    CreateDynamic3DTextLabel("- Banka -\n"WHITE"Pritisnite 'f' za ulaz", MAIN_COLOR_HEX,
        Float: 1461.2765, Float: -1021.2448, Float: 24.0317, Float: 5.0
    );
    CreateDynamic3DTextLabel("- Banka -\n"WHITE"Pritisnite 'f' za izlaz", MAIN_COLOR_HEX,
        Float: 1454.8555, Float: -985.5658, Float: 996.1050, Float: 5.0
    );
    CreateDynamic3DTextLabel("- Banka -\n"WHITE"Da otvorite racun\n/otvoriracun", MAIN_COLOR_HEX,
        Float: 1425.9658, Float: -977.8441, Float: 996.1050, Float: 5.0
    );
    CreateDynamic3DTextLabel("- Banka -\n"WHITE"Da podignete novac sa racuna\n/podigninovac", MAIN_COLOR_HEX,
        Float: 1425.7753, Float: -975.6477, Float: 996.1050, Float: 5.0
    );
    CreateDynamic3DTextLabel("- Banka -\n"WHITE"Da ostavite novac u banku\n/ostavinovac", MAIN_COLOR_HEX,
        Float: 1425.7939, Float: -973.4025, Float: 996.1050, Float: 5.0
    );

    return Y_HOOKS_CONTINUE_RETURN_1;
}