#if defined _inc_cmd_process
    #undef _inc_cmd_process
#endif
// custom include-guard to ensure we don't duplicate
#if defined _cmd_process_included
    #endinput
#endif
#define _cmd_process_included

#if defined CMD
    #undef CMD
#endif

#define acmd:[%0]%1(%2,%3) cmd:%1(%2,%3) if (Admin_GetLevel(%2) < %0) return \
	SendErrorMsg(%2,"Niste ovlasceni!"); else

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
	if (result == -1)
		return SendErrorMsgF(playerid, "Komanda /%s ne postoji!", cmd);

	return 1;
}