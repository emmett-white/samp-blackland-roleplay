#if defined _inc_world_main
    #undef _inc_world_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _world_main_included
    #endinput
#endif
#define _world_main_included

const WORLD_PICKUP_ENTER_EXIT = 19132;

#include <world_hooks>
#include <world_spawn>
#include <world_jewerly>
#include <world_lspd>
#include <world_bank>
#include <world_cityhall>