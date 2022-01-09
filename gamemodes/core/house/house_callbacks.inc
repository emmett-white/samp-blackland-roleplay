#if defined _inc_house_callbacks
    #undef _inc_house_callbacks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _house_callbacks_included
    #endinput
#endif
#define _house_callbacks_included

forward House_Load(); public House_Load()
{
    if (!cache_num_rows())
    {
        return 0;
    }

    new
        String: str_format_label,
        rows;

    cache_get_row_count(rows);
    
    for (new i = 0; i < rows; ++i)
    {
        cache_get_value_name_int(i, "house_id", houseID[i]);
        cache_get_value_name_int(i, "house_owned", houseOwned[i]);
        cache_get_value_name_int(i, "house_locked", houseLocked[i]);
        cache_get_value_name_int(i, "house_price", housePrice[i]);

        cache_get_value_name(i, "house_owner", string: houseOwner[i]);
        cache_get_value_name(i, "house_desc", string: houseDescription[i]);
        
        cache_get_value_name_float(i, "house_extx", Float: houseExtX[i]);
        cache_get_value_name_float(i, "house_exty", Float: houseExtY[i]);
        cache_get_value_name_float(i, "house_extz", Float: houseExtZ[i]);
        cache_get_value_name_float(i, "house_intx", Float: houseIntX[i]);
        cache_get_value_name_float(i, "house_inty", Float: houseIntY[i]);
        cache_get_value_name_float(i, "house_intz", Float: houseIntZ[i]);

        if (houseOwned[i])
        {
            str_format_label = String: str_format(
                "[KUCA - %d]\nVlasnik: %s\nOpis: %s\nCena: $%d",
                i, string: houseOwner[i], string: houseDescription[i], housePrice[i]
            );
            houseMapIcon[i] = CreateDynamicMapIcon(Float: houseExtX[i], Float: houseExtY[i], Float: houseExtZ[i], 32, 1);
        }

        else
        {
            str_format_label = String: str_format(
                "[KUCA - %d]\nOva kuca je na prodaju!\nVlasnik: %s\nOpis: %s\nCena: $%d\nDa kupite kucu kucajte /kupikucu!",
                i, string: houseOwner[i], string: houseDescription[i], housePrice[i]
            );
            houseMapIcon[i] = CreateDynamicMapIcon(Float: houseExtX[i], Float: houseExtY[i], Float: houseExtZ[i], 31, 1);
        }

        houseIDUsed[i] = 1;
        houseLabel[i] = fmt_CreateDyn3DTextLabel(str_format_label, X11_GREEN, Float: houseExtX[i], Float: houseExtY[i], Float: houseExtZ[i], Float: 30.0);
        housePickup[i] = CreateDynamicPickup(1272, 1, Float: houseExtX[i], Float: houseExtY[i], Float: houseExtZ[i]);
    }

    return 1;
}