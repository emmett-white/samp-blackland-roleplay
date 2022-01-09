#if defined _inc_dealer_callbacks
    #undef _inc_dealer_callbacks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _dealer_callbacks_included
    #endinput
#endif
#define _dealer_callbacks_included

forward Dealer_Created(const dealerid); public Dealer_Created(const dealerid)
{
    dealerID[dealerid] = cache_insert_id();
    return 1;
}

forward Dealer_Load(); public Dealer_Load()
{
    for (new i; i < cache_num_rows(); ++i)
    {
        new id = Iter_Alloc(Iter_Dealers);
        
        cache_get_value_name_int(i, "dealer_id", dealerID[id]);
        cache_get_value_name_int(i, "dealer_skin", dealerSkin[id]);

        cache_get_value_name(i, "dealer_name", string: dealerName[id]);
        
        cache_get_value_name_float(i, "dealer_x", Float: dealerX[id]);
        cache_get_value_name_float(i, "dealer_y", Float: dealerY[id]);
        cache_get_value_name_float(i, "dealer_z", Float: dealerZ[id]);
        cache_get_value_name_float(i, "dealer_a", Float: dealerA[id]);

        dealerActor[id] = CreateActor(
            dealerSkin[id], Float: dealerX[id], Float: dealerY[id], Float: dealerZ[id], Float: dealerA[id]
        );

        new String: str_dealer_label = String: str_format("[DILER (%d) %s]\nDa kupite nesto od dilera /diler", dealerID[id], string: dealerName[id]);
        dealerLabel[id] = Text3D: fmt_Create3DTextLabel(
            str_dealer_label, X11_YELLOW,
            Float: dealerX[id], Float: dealerY[id], Float: dealerZ[id], Float: 30.0, 0
        );
    }

    return 1;
}