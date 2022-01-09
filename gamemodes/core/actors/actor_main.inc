#if defined _inc_actor_main
    #undef _inc_actor_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _actor_main_included
    #endinput
#endif
#define _actor_main_included

#include <actor_variables>
#include <actor_callbacks>
#include <actor_hooks>