#if defined _inc_admin_commands_2
    #undef _inc_admin_commands_2
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_commands_2_included
    #endinput
#endif
#define _admin_commands_2_included

acmd:[2]unban(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
    {
        return SendErrorMsg(playerid, "Morate biti na admin duznosti (/aduty)!");
    }
    
    if (isnull(string: params) && IsNumeric(string: params))
    {
        return SendSyntaxMsg(playerid, "/unban [ime igraca]");
    }

    Ban_Remove(string: params, playerid);

    return 1;
}

acmd:[2]podesivreme(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
    {
        return SendClientMessage(playerid, X11_RED, "[!ADMIN]: "WHITE"Morate biti na admin duznosti (/aduty)!");
    }
    
    if (isnull(string: params))
    {
        return SendClientMessage(playerid, X11_ORANGE, "[KORISTI]: "WHITE"/podesivreme [id vremena]");
    }

    if (!(0 <= strval(string: params) <= 20))
    {
        return SendClientMessage(playerid, X11_RED, "[VREME]: "WHITE"Ne mozete ispod 0 i iznad 20!");
    }

    SetWeather(strval(string: params));
    Admin_SendMessage(ADMIN_CHAT_COLOR, "[ADMIN]: %s je postavio vreme na %d.",
        ReturnPlayerName(playerid), strval(string: params)
    );

    return 1;
}

acmd:[2]podesisate(playerid, const string: params[])
{
    if (!Admin_GetDutyStatus(playerid))
    {
        return SendClientMessage(playerid, X11_RED, "[!ADMIN]: "WHITE"Morate biti na admin duznosti (/aduty)!");
    }

    if (isnull(string: params))
    {
        return SendClientMessage(playerid, X11_ORANGE, "[KORISTI]: "WHITE"/podesisate [sat]");
    }

    if (!(0 <= strval(string: params) <= 23))
    {
        return SendClientMessage(playerid, X11_RED, "[SATI]: "WHITE"Ne mozete ispod 0 i iznad 23!");
    }

    SetWorldTime(strval(string: params));
    Admin_SendMessage(ADMIN_CHAT_COLOR, "[ADMIN]: %s je postavio sate na %d.",
        ReturnPlayerName(playerid), strval(string: params)
    );

    return 1;
}

acmd:[2]mutiraj(playerid, const string: params[])
{
    static
        targetid,
        time,
        string: reason[MAX_REASON_LENGTH];

    if (sscanf(string: params, "ris["#MAX_REASON_LENGTH"]", targetid, time, string: reason))
    {
        return SendSyntaxMsg(playerid, "/mutiraj [id igraca] [vreme(minuti)] [razlog]");
    }

    Mute_Player(playerid, targetid, time, string: reason);

    return 1;
}

acmd:[2]odmutiraj(playerid, const string: params[])
{
    if (isnull(string: params) || !IsNumeric(string: params))
    {
        return SendSyntaxMsg(playerid, "/odmutiraj [id igraca]");
    }

    if (!IsPlayerConnected(strval(string: params)))
    {
        return 0;
    }

    Mute_Remove(playerid, strval(string: params));

    return 1;
}