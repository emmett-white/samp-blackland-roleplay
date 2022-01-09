#if defined _inc_mute_variables
    #undef _inc_mute_variables
#endif
// custom include-guard to ensure we don't duplicate
#if defined _mute_variables_included
    #endinput
#endif
#define _mute_variables_included

/** Variables */
static mutedTime[MAX_PLAYERS];

/** Timer */
PTASK__ Mute_TimerDown[60000](playerid)
{
    if (Mute_GetTime(playerid))
    {
        Mute_SetTime(playerid, (Mute_GetTime(playerid) - 1));
    }

    if (!Mute_GetTime(playerid))
    {
        return 0;
    }

    return 1;
}

/** Get/Set Functions */
stock Mute_GetTime(const playerid) return mutedTime[playerid];
stock Mute_SetTime(const playerid, const time)
{
    mutedTime[playerid] = time;

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_mutedtime = '%d' WHERE char_id = '%d'",
        Mute_GetTime(playerid), Account_GetPlayerCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Mute_Player(const adminid, const targetid, const time, const string: reason[])
{
    if (targetid == adminid)
    {
        return SendErrorMsg(adminid, "Ne mozete mutirati sami sebe!");
    }

    if (Mute_GetTime(targetid))
    {
        return SendErrorMsgF(adminid, "Igrac %s je vec mutiran!", ReturnPlayerName(targetid));
    }

    if (!(1 <= time <= 9999))
    {
        return SendErrorMsg(adminid, "Ne mozete ispod 1 i iznad 9999 minuta!");
    }

    Mute_SetTime(targetid, time);
    SendInfoMsgToAllF("Admin %s je mutirao igraca %s na %d minut/a zbog %s.",
        ReturnPlayerName(adminid), ReturnPlayerName(targetid), time, string: reason
    );

    return 1;
}

stock Mute_Remove(const adminid, const targetid)
{
    if (!Mute_GetTime(targetid))
    {
        return SendErrorMsgF(adminid, "Igrac %s nije mutiran!", ReturnPlayerName(targetid));
    }

    Mute_SetTime(targetid, 0);

    SendInfoMsgToAllF("Igrac %s vise nije mutiran.", ReturnPlayerName(targetid));
    Admin_SendMessage(ADMIN_CHAT_COLOR, "%s je odmutirao igraca %s.",
        ReturnPlayerName(adminid), ReturnPlayerName(targetid)
    );

    return 1;
}