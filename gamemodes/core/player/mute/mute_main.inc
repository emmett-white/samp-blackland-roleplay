#if defined _inc_mute_main
    #undef _inc_mute_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _mute_main_included
    #endinput
#endif
#define _mute_main_included

#include <mute_variables>
#include <mute_hooks>