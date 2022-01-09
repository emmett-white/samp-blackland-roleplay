#if defined _inc_player_main
    #undef _inc_player_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _player_main_included
    #endinput
#endif
#define _player_main_included

#include <player_functions>
#include <player_commands>