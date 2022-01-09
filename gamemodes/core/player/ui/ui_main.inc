#if defined _inc_ui_main
    #undef _inc_ui_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ui_main_included
    #endinput
#endif
#define _ui_main_included

#include <ui_register>
#include <ui_speedo>
#include <ui_login>
#include <ui_ingame>
#include <ui_loading>