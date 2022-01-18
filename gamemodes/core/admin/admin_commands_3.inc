#if defined _inc_admin_commands_3
    #undef _inc_admin_commands_3
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_commands_3_included
    #endinput
#endif
#define _admin_commands_3_included

acmd:[3]offban(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    
    static
        string: targetname[MAX_PLAYER_NAME],
        string: reason[MAX_REASON_LENGTH];

    if (sscanf(string: params, "s[25]s["#MAX_REASON_LENGTH"]", string: targetname, string: reason))
        return SendSyntaxMsg(playerid, "/offban [ime igraca] [razlog]");

    Ban_OffPlayer(string: targetname, playerid, string: reason);

    return 1;
}