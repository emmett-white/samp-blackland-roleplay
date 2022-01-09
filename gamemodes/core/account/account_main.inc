#if defined _inc_account_main
    #undef _inc_account_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _account_main_included
    #endinput
#endif
#define _account_main_included

#include <account_variables>
#include <account_functions>
#include <account_hooks>
#include <account_callbacks>