#if defined _inc_actor_variables
    #undef _inc_actor_variables
#endif
// custom include-guard to ensure we don't duplicate
#if defined _actor_variables_included
    #endinput
#endif
#define _actor_variables_included

// ---
// Variables
// ---
const MAX_SERVER_ACTORS = (200);

new
    actorUniqueID[MAX_ACTORS],
    actorSkinID[MAX_ACTORS],
    actorSkin[MAX_ACTORS],
    actorAnimation[MAX_ACTORS],
    actorVirtualWorld[MAX_ACTORS],
    actorInterior[MAX_ACTORS],

    Float: actorX[MAX_ACTORS],
    Float: actorY[MAX_ACTORS],
    Float: actorZ[MAX_ACTORS],
    Float: actorA[MAX_ACTORS],
    
    Iterator: Iter_Actors<MAX_ACTORS>;

// ---
// Functions
// ---
stock Actor_Create(const playerid, const skin, const animation = 0)
{
    new
        id = Iter_Alloc(Iter_Actors),
        x, y, z, a;

    GetPlayerPos(playerid, Float: x, Float: y, Float: z);
    GetPlayerFacingAngle(playerid, Float: a);
    SetPlayerPos(playerid, (Float: x + 1.0), Float: y, Float: z);

    actorSkinID[id] = skin, actorAnimation[id] = animation,
    actorVirtualWorld[id] = GetPlayerVirtualWorld(playerid),
    actorInterior[id] = GetPlayerInterior(playerid);
    actorX[id] = Float: x, actorY[id] = Float: y, actorZ[id] = Float: z, actorA[id] = Float: a;

    actorSkin[id] = CreateDynamicActor(actorSkinID[id],
        Float: x, Float: y, Float: z, Float: a,
        .worldid = actorVirtualWorld[id], .interiorid = actorInterior[id]
    );

    switch (actorAnimation[id])
    {
        /** Animation IDs
         * 0 - none
         * 1 - sit
         * 2 - chat
         * 3 - hands up
         * 4 - tired
         */
        case 1: { ApplyDynamicActorAnimation(actorSkin[id], "PED", "SEAT_idle", Float: 4.0, 0, 0, 0, 1, 0); }
        case 2: { ApplyDynamicActorAnimation(actorSkin[id], "PED", "IDLE_chat", Float: 4.0, 1, 0, 0, 1, 0); }
        case 3: { ApplyDynamicActorAnimation(actorSkin[id], "PED", "handsup", Float: 4.0, 0, 0, 0, 1, 0); }
        case 4: { ApplyDynamicActorAnimation(actorSkin[id], "PED", "IDLE_TIRED", Float: 4.0, 0, 0, 0, 1, 0); }
        default: return 1;
    }

    new String: str_query_insert = String: str_format(
        "INSERT INTO actors (actor_skin, actor_animation, actor_vw, actor_interior, \
        actor_x, actor_y, actor_z, actor_a) \
        VALUES ('%d', '%d', '%d', '%d', '%f', '%f', '%f', '%f')",
        actorSkinID[id], actorAnimation[id], actorVirtualWorld[id], actorInterior[id],
        Float: actorX[id], Float: actorY[id], Float: actorZ[id], Float: actorA[id]
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_insert, "Actor_Created", "i", id);

    return 1;
}