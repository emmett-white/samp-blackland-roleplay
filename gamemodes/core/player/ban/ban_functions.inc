#if defined _inc_ban_functions
    #undef _inc_ban_functions
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ban_functions_included
    #endinput
#endif
#define _ban_functions_included

stock Ban_CheckPlayerStatus(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM banned WHERE banned_player = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (!cache_num_rows())
    {
        UI_CreateLoadingTextDraw(playerid, .connection = 1);
        return 1;
    }

    static
        bannedAdmin[MAX_PLAYER_NAME],
        bannedReason[MAX_REASON_LENGTH];

    cache_get_value_name(0, "banned_admin", bannedAdmin);
    cache_get_value_name(0, "banned_reason", bannedReason);

    Dialog_Show(playerid, "DIALOG_BAN", DIALOG_STYLE_MSGBOX,
        ""MAIN_COLOR"Blackland - "WHITE"Banovan status",
        ""MAIN_COLOR"%s "WHITE"- banovani ste sa servera!\n\n\
        "MAIN_COLOR"Admin: "WHITE"%s\n"MAIN_COLOR"Razlog: "WHITE"%s",
        "Izlaz", "", ReturnPlayerName(playerid), bannedAdmin, bannedReason
    );

    return 1;
}

stock Ban_OffPlayer(const string: name[], const adminid, const string: reason[] = "N/A")
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM accounts WHERE account_name = '%e'", string: name
            )
        )
    );

    if (!cache_num_rows())
    {
        SendErrorMsgF(adminid, "Igrac %s ne postoji u bazi podataka!", string: name);
        return 1;
    }

    if (IsPlayerConnected(GetPlayerID(string: name)))
    {
        SendErrorMsgF(adminid, "Igrac %s je online!", string: name);
        return 1;
    }

    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM banned WHERE banned_player = '%e'", string: name
            )
        )
    );

    if (cache_num_rows())
    {
        SendErrorMsgF(adminid, "Igrac %s je vec banovan!", string: name);
        return 1;
    }

    new String: str_query_ban_insert = String: str_format(
        "INSERT INTO banned (banned_player, banned_admin, banned_reason) \
        VALUES ('%e', '%e', '%e')", string: name, ReturnPlayerName(adminid), string: reason
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_ban_insert);

    SendInfoMsgToAllF("Igrac %s je off-bannovan zbog %s.", string: name, string: reason);

    return 1;
}

stock Ban_Player(const targetid, const adminid, const string: reason[] = "N/A")
{
    if (targetid == adminid)
    {
        SendErrorMsg(adminid, "Ne mozete banovati samog sebe!");
        return 1;
    }

    if (Admin_GetLevel(targetid) && Admin_GetLevel(adminid) != MAX_ADMIN_LEVEL)
    {
        SendErrorMsg(adminid, "Samo vlasnik moze banovati admina!");
        return 1;
    }

    new String: str_query_ban_insert = String: str_format(
        "INSERT INTO banned (banned_player, banned_admin, banned_reason) \
        VALUES ('%e', '%e', '%e')", ReturnPlayerName(targetid), ReturnPlayerName(adminid), string: reason
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_ban_insert);

    GameTextForPlayer(targetid, "~r~BANNED", 10000, 3);
    Kick(targetid);

    SendInfoMsgToAllF("Igrac %s je banovan zbog %s.", ReturnPlayerName(targetid), string: reason);

    return 1;
}

stock Ban_Remove(const string: name[], const adminid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM banned WHERE banned_player = '%e'", string: name
            )
        )
    );

    if (!cache_num_rows())
    {
        SendErrorMsgF(adminid, "Igrac %s nije banovan!", string: name);
        return 1;
    }

    new String: str_query_ban_remove = String: str_format(
        "DELETE FROM banned WHERE banned_player = '%e'", string: name
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_ban_remove);

    SendInfoMsgToAllF("Igrac %s je un-banovan.", string: name);
    Admin_SendMessage(ADMIN_CHAT_COLOR, "[ADMIN]: %s je unbanovao igraca %s.", ReturnPlayerName(adminid), string: name);

    return 1;
}

/** Dialogs */
Dialog:DIALOG_BAN(const playerid, response, listitem, string: inputtext[])
{
    if (!response || response)
    {
        Kick(playerid);
        return 1;
    }

    return 1;
}