#if defined _inc_house_main
    #undef _inc_house_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _house_main_included
    #endinput
#endif
#define _house_main_included

#include <house_variables>
#include <house_hooks>
#include <house_callbacks>