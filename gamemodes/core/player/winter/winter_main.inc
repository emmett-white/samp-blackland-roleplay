#if defined _inc_winter_main
    #undef _inc_winter_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _winter_main_included
    #endinput
#endif
#define _winter_main_included

#include <winter_functions>
#include <winter_hooks>