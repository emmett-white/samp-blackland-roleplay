/** Macro settings */
#define YSI_YES_HEAP_MALLOC
#define YSI_NO_VERSION_CHECK
#define YSI_NO_MODE_CACHE
#define YSI_NO_OPTIMISATION_MESSAGE

// #define CGEN_MEMORY 50000
#define MAX_COMMANDS 60
#define FOREACH_NO_BOTS
#define FOREACH_NO_STREAMED
#define PP_SYNTAX_AWAIT

/** Libraries */
#include <a_samp>
#include <a_mysql>
#include <crashdetect>
#include <Pawn.CMD>
#include <PawnPlus>
#include <pp-mysql>
#include <Pawn.Regex>
#include <chrono>
#include <streamer>
#include <sscanf2>
#include <env>

#include <progress2>

#include <YSI_Coding\y_malloc>
#include <YSI_Coding\y_timers>
#include <YSI_Coding\y_iterate>
#include <YSI_Server\y_colours>
#include <YSI_Data\y_bit>
#include <YSF>

#undef X11_RED
#define X11_RED 0xFF0000FF

#include <jit>
#include <easy-dialog>

/** Modules */
#include <database_main>
#include <settings>
#include <cmd_process>
#include <account_main>
#include <house_main>
#include <player_main>
#include <ui_main>
#include <ban_main>
#include <world_main>
#include <admin_main>
#include <org_main>
#include <dealer_main>
#include <vehicle_main>
#include <actor_main>
#include <mute_main>
#include <winter_main>

main()
{
	printf("[INFO]: JIT %s", (IsJITPresent() ? ("nije prisutan.") : ("je prisutan.")));
	OnJITCompile();
	
	new
		Timestamp: ts = Timestamp: Now(),
		string: ts_fmt[24];

	TimeFormat(Timestamp: ts, ISO6801_TIME, string: ts_fmt, sizeof(ts_fmt));
	printf("[INFO]: Mod se uspesno ucitao u %s", string: ts_fmt);
}

/** Callbacks */
forward OnJITCompile();
forward Bind_OnPlayerDisconnect(
	CallbackHandler: self, Handle: task_handle, Task: task, const orig_playerid, const playerid
);

public OnGameModeInit()
{
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();

	return 1;
}

public OnJITCompile()
{
	printf("[INFO]: OnJITCompile->JIT %s", (IsJITPresent() ? ("nije prisutan.") : ("je prisutan.")));
	return 1;
}

public Bind_OnPlayerDisconnect(
	CallbackHandler: self, Handle: task_handle, Task: task, const orig_playerid, const playerid
)
{
    if(orig_playerid == playerid)
	{
        pawn_unregister_callback(self);
        handle_release(task_handle);

        if(handle_linked(task_handle))
		{
            task_delete(task);
        }
    }
}

BindToPlayer(Task: task, const playerid)
{
    new Handle: handle = handle_new(_:task, .tag_id = tagof(task));
		
    handle_acquire(handle);
    pawn_register_callback(#OnPlayerDisconnect, #Bind_OnPlayerDisconnect, _, "eddd", _:handle, _:task, playerid);
    
    return _:task;
}

// dafuqqqqqqqqqqqqqqq lol
/*public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_ACTION)
	{
		new Float:vx, Float:vy, Float:vz;

		GetVehicleVelocity(GetPlayerVehicleID(playerid), vx, vy, vz);
		SetVehicleVelocity(GetPlayerVehicleID(playerid), vx * 1.2, vy *1.2, vz * 1.2);
    }

    return 1;
}*/