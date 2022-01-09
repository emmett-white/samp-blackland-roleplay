#if defined _inc_vehicle_main
    #undef _inc_vehicle_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _vehicle_main_included
    #endinput
#endif
#define _vehicle_main_included

#include <vehicle_radio>