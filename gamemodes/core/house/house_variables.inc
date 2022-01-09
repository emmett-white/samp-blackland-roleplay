#if defined _inc_house_variables
    #undef _inc_house_variables
#endif
// custom include-guard to ensure we don't duplicate
#if defined _house_variables_included
    #endinput
#endif
#define _house_variables_included

/** Variables */
const MAX_HOUSES = 200;
new
    houseID[MAX_HOUSES],
    housePrice[MAX_HOUSES],
    houseMapIcon[MAX_HOUSES],
    houseIDUsed[MAX_HOUSES],
    houseLocked[MAX_HOUSES],
    houseOwned[MAX_HOUSES],
    housePickup[MAX_HOUSES],

    string: houseOwner[MAX_HOUSES][MAX_PLAYER_NAME],
    string: houseDescription[MAX_HOUSES][MAX_REASON_LENGTH],

    Text3D: houseLabel[MAX_HOUSES],

    Float: houseExtX[MAX_HOUSES],
    Float: houseExtY[MAX_HOUSES],
    Float: houseExtZ[MAX_HOUSES],
    Float: houseIntX[MAX_HOUSES],
    Float: houseIntY[MAX_HOUSES],
    Float: houseIntZ[MAX_HOUSES];

/** Functions */
stock House_GetMaxHouses() return MAX_HOUSES;
stock House_GetOwner(const houseid) return houseOwner[houseid];
stock House_GetDescription(const houseid) return houseDescription[houseid];
stock House_GetPrice(const houseid) return housePrice[houseid];
stock House_IsLocked(const houseid) return houseLocked[houseid];
stock House_HasOwner(const houseid) return houseOwned[houseid];

stock House_Create(const playerid, const houseid, const price, Float: x, Float: y, Float: z)
{
    strcopy(string: houseOwner[houseid], "Niko");
    strcopy(string: houseDescription[houseid], "Na prodaju");

    houseID[houseid] = houseid;
    housePrice[houseid] = price;
    houseIDUsed[houseid] =
    houseLocked[houseid] = 1;
    houseOwned[houseid] = 0;
    houseExtX[houseid] = Float: x;
    houseExtY[houseid] = Float: y;
    houseExtZ[houseid] = Float: z;
    houseIntX[houseid] =
    houseIntY[houseid] =
    houseIntZ[houseid] = 0.0;

    new String: str_format_label = String: str_format(
        "[KUCA - %d]\nOva kuca je na prodaju!\nVlasnik: %s\nOpis: %s\nCena: $%d\nDa kupite kucu kucajte /kupikucu!",
        houseid, string: houseOwner[houseid], string: houseDescription[houseid], housePrice[houseid]
    );

    houseLabel[houseid] = fmt_CreateDyn3DTextLabel(str_format_label, X11_GREEN, Float: houseExtX[houseid], Float: houseExtY[houseid], Float: houseExtZ[houseid], Float: 30.0);
    housePickup[houseid] = CreateDynamicPickup(1272, 1, Float: houseExtX[houseid], Float: houseExtY[houseid], Float: houseExtZ[houseid]);
    houseMapIcon[houseid] = CreateDynamicMapIcon(Float: houseExtX[houseid], Float: houseExtY[houseid], Float: houseExtZ[houseid], 31, 1);

    SendServerMsgF(playerid, "Kreirali ste kucu! ID Kuce: %d", houseid);

    return 1;
}

stock House_Delete(const playerid, const houseid)
{
    houseIDUsed[houseid] = 0;
	houseID[houseid] = MAX_HOUSES;

    DestroyDynamicPickup(housePickup[houseid]);
	DestroyDynamicMapIcon(houseMapIcon[houseid]);
	DestroyDynamic3DTextLabel(houseLabel[houseid]);

    SendServerMsgF(playerid, "Obrisali ste kucu! ID Kuce: %d", houseid);

    return 1;
}

stock House_Buy(const playerid, const houseid)
{
    SendServerMsgF(playerid, "Uspesno ste kupili kucu za $%d!", House_GetPrice(houseid));
    houseOwned[houseid] = 1;
    strcopy(string: houseOwner[houseid], ReturnPlayerName(playerid));

    new string: fmt[50 + MAX_PLAYER_NAME];
    format(string: fmt, sizeof(fmt), "[KUCA - %d]\nVlasnik: %s\nOpis: %s\nCena: $%d",
        houseid, ReturnPlayerName(playerid), string: houseDescription[houseid], House_GetPrice(houseid)
    );
    UpdateDynamic3DTextLabelText(houseLabel[houseid], X11_GREEN, string: fmt);

    DestroyDynamicMapIcon(houseMapIcon[houseid]);
    houseMapIcon[houseid] = CreateDynamicMapIcon(Float: houseExtX[houseid], Float: houseExtY[houseid], Float: houseExtZ[houseid], 32, 1);

    return 1;
}

stock House_SellAll()
{
    for (new i = 0; i < MAX_HOUSES; ++i)
    {
        if (!houseIDUsed[i])
        {
            return 0;
        }

        houseIDUsed[i] = 0;
        strcopy(string: houseOwner[i], "Niko");
        strcopy(string: houseDescription[i], "Na prodaju");

        DestroyDynamicMapIcon(houseMapIcon[i]);
        houseMapIcon[i] = CreateDynamicMapIcon(Float: houseExtX[i], Float: houseExtY[i], Float: houseExtZ[i], 31, 1);

        new
            string: fmt[128],
            String: str_query_update;

        format(string: fmt, sizeof(fmt), "[KUCA - %d]\nOva kuca je na prodaju!\nVlasnik: %s\nOpis: %s\nCena: $%d\nDa kupite kucu kucajte /kupikucu!",
            i, string: houseOwner[i], string: houseDescription[i], House_GetPrice(i)
        );
        UpdateDynamic3DTextLabelText(houseLabel[i], X11_GREEN, string: fmt);

        str_query_update = String: str_format(
            "UPDATE houses SET house_owned = '0', house_owner = 'Niko', house_desc = 'Na prodaju' \
            WHERE house_id = '%d'", (i + 1)
        );
        mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);
    }

    return 1;
}

stock House_SetDescription(const houseid, const string: desc[])
{
    strcopy(string: houseDescription[houseid], string: desc);
    new String: str_query_update = String: str_format(
        "UPDATE houses SET house_desc = '%e' WHERE house_id = '%d'", string: desc, (houseid + 1)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    new string: fmt[50 + MAX_PLAYER_NAME];
    format(string: fmt, sizeof(fmt), "[KUCA - %d]\nVlasnik: %s\nOpis: %s\nCena: $%d",
        houseid, House_GetOwner(houseid), string: houseDescription[houseid], House_GetPrice(houseid)
    );
    UpdateDynamic3DTextLabelText(houseLabel[houseid], X11_GREEN, string: fmt);

    return 1;
}

stock House_SetLocked(const houseid, const value)
{
    houseLocked[houseid] = value;
    new String: str_query_update = String: str_format(
        "UPDATE houses SET house_locked = '%d' WHERE house_id = '%d'", House_IsLocked(houseid), (houseid + 1)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock House_DestroyCheckpoint(const playerid)
{
    DisablePlayerCheckpoint(playerid);
    Player_SetHouseCPStatus(playerid, false);

    return 1;
}

stock House_SetPlayerCheckpoint(const playerid, Float: x, Float: y, Float: z)
{
    SetPlayerCheckpoint(playerid, Float: x, Float: y, Float: z, Float: 2.0);
    return 1;
}

stock Float: House_GetPos(const houseid, index)
{
    switch (index)
    {
        case 0: return Float: houseExtX[houseid];
        case 1: return Float: houseExtY[houseid];
        case 2: return Float: houseExtZ[houseid];
        case 3: return Float: houseIntX[houseid];
        case 4: return Float: houseIntY[houseid];
        case 5: return Float: houseIntZ[houseid];
        default: return Float: 0.0;
    }

    return Float: 0.0;
}

stock House_GetNextID()
{
    for (new i = 0; i < MAX_HOUSES; ++i)
    {
		if (!houseIDUsed[i])
        {
			return i;
        }
	}

	return MAX_HOUSES;
}

stock House_GetNearby(const playerid)
{
    for (new i = 0; i < MAX_HOUSES; ++i)
    {
        if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: houseExtX[i], Float: houseExtY[i], Float: houseExtZ[i]))
        {
            return i;
        }
    }

	return MAX_HOUSES;
}