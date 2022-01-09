#if defined _inc_ban_main
    #undef _inc_ban_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ban_main_included
    #endinput
#endif
#define _ban_main_included

#include <ban_functions>