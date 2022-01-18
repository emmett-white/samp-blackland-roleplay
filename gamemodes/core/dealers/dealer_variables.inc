#if defined _inc_dealer_variables
    #undef _inc_dealer_variables
#endif
// custom include-guard to ensure we don't duplicate
#if defined _dealer_variables_included
    #endinput
#endif
#define _dealer_variables_included

// ---
// Variables
// ---
const MAX_DEALERS = 50;

new
    Iterator: Iter_Dealers<MAX_DEALERS>,
    Text3D: dealerLabel[MAX_DEALERS],

    dealerID[MAX_DEALERS],
    dealerActor[MAX_DEALERS],
    dealerSkin[MAX_DEALERS],

    Float: dealerX[MAX_DEALERS],
    Float: dealerY[MAX_DEALERS],
    Float: dealerZ[MAX_DEALERS],
    Float: dealerA[MAX_DEALERS],
    
    string: dealerName[MAX_DEALERS][MAX_PLAYER_NAME];

// ---
// Functions
// ---
stock Dealer_Create(const skin, const string: name[], Float: x, Float: y, Float: z, Float: a)
{
    new id = Iter_Alloc(Iter_Dealers);

    if (!(1 <= skin <= 299))
        return 0;

    dealerSkin[id] = skin;
    dealerX[id] = Float: x, dealerY[id] = Float: y, dealerZ[id] = Float: z, dealerA[id] = Float: a;

    strcopy(string: dealerName[id], string: name);

    dealerActor[id] = CreateActor(
        dealerSkin[id], Float: dealerX[id], Float: dealerY[id], Float: dealerZ[id], Float: dealerA[id]
    );

    new String: str_dealer_label = String: str_format("[DILER (%d) %s]\nDa kupite nesto od dilera /diler", (id + 1), string: name);
    dealerLabel[id] = Text3D: fmt_Create3DTextLabel(
        str_dealer_label, X11_YELLOW,
        Float: dealerX[id], Float: dealerY[id], Float: dealerZ[id], Float: 30.0, 0
    );

    // Query
    new String: str_query_dealer_add = String: str_format(
        "INSERT INTO \
            dealers (dealer_name, dealer_skin, dealer_x, dealer_y, dealer_z, dealer_a) \
        VALUES \
            ('%e', '%d', '%f', '%f', '%f', '%f')",
        string: dealerName[id], dealerSkin[id],
        Float: dealerX[id], Float: dealerY[id], Float: dealerZ[id], Float: dealerA[id]
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_dealer_add, "Dealer_Created", "d", id);

    return 1;
}

stock Dealer_Goto(const playerid, const dealerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM dealers WHERE dealer_id = '%d'", dealerid
            )
        )
    );

    if (!cache_num_rows())
        return 0;

    SetPlayerPos(playerid, (Float: dealerX[(dealerid - 1)] + 2.0), Float: dealerY[(dealerid - 1)], Float: dealerZ[(dealerid - 1)]);

    return 1;
}

stock Dealer_Nearby(const playerid)
{
    foreach (new i: Iter_Dealers)
        if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: dealerX[i], Float: dealerY[i], Float: dealerZ[i]))
            return 1;

    return 0;
}

stock Dealer_NearbyID(const playerid)
{
    foreach (new i: Iter_Dealers)
    {
        if (dealerX[i] == 0.0)
            continue;

        if (IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: dealerX[i], Float: dealerY[i], Float: dealerZ[i]))
            return i;
    }

    return -1;
}