#if defined _inc_dealer_main
    #undef _inc_dealer_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _dealer_main_included
    #endinput
#endif
#define _dealer_main_included

#include <dealer_variables>
#include <dealer_ui>
#include <dealer_hooks>
#include <dealer_callbacks>