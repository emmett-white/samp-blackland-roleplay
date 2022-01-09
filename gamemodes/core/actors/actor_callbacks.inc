#if defined _inc_actor_callbacks
    #undef _inc_actor_callbacks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _actor_callbacks_included
    #endinput
#endif
#define _actor_callbacks_included

forward Actor_Created(const actorid); public Actor_Created(const actorid)
{
    actorUniqueID[actorid] = cache_insert_id();
    return 1;
}

forward Actor_Load(); public Actor_Load()
{
    for (new i; i < cache_num_rows(); ++i)
    {
        new id = Iter_Alloc(Iter_Actors);

        cache_get_value_name_int(i, "actor_id", actorUniqueID[id]);
        cache_get_value_name_int(i, "actor_skin", actorSkinID[id]);
        cache_get_value_name_int(i, "actor_animation", actorAnimation[id]);
        cache_get_value_name_int(i, "actor_vw", actorVirtualWorld[id]);
        cache_get_value_name_int(i, "actor_interior", actorInterior[id]);

        cache_get_value_name_float(i, "actor_x", Float: actorX[id]);
        cache_get_value_name_float(i, "actor_y", Float: actorY[id]);
        cache_get_value_name_float(i, "actor_z", Float: actorZ[id]);
        cache_get_value_name_float(i, "actor_a", Float: actorA[id]);
    
        actorSkin[id] = CreateDynamicActor(actorSkinID[id],
            Float: actorX[id], Float: actorY[id], Float: actorZ[id], Float: actorA[id],
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
    }

    return 1;
}