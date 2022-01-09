#if defined _inc_admin_main
    #undef _inc_admin_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_main_included
    #endinput
#endif
#define _admin_main_included

#include <admin_functions>
#include <admin_commands_1>
#include <admin_commands_2>
#include <admin_commands_3>
#include <admin_commands_4>
#include <admin_hooks>
#include <admin_dialogs>