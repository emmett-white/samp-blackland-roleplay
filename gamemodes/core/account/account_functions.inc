#if defined _inc_account_functions
    #undef _inc_account_functions
#endif
// custom include-guard to ensure we don't duplicate
#if defined _account_functions_included
    #endinput
#endif
#define _account_functions_included

stock Account_CheckStatus(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM accounts WHERE account_name = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (cache_num_rows())
    {
        static string: tmpstr[MAX_PASSWORD_LENGTH];
        cache_get_value_name_int(0, "account_id", Account_GetPlayerUniqueID(playerid));

        cache_get_value_name(0, "account_password", string: tmpstr);
        Account_SetPlayerPassword(playerid, string: tmpstr);

        task_await(
            Task: MySQL_QueryS(
                String: str_format(
                    "SELECT * FROM characters WHERE char_name = '%e'", ReturnPlayerName(playerid)
                )
            )
        );

        if (cache_num_rows())
        {
            static tmpint;
            cache_get_value_name_int(0, "char_id", Account_GetPlayerCharUniqueID(playerid));

            cache_get_value_name_int(0, "char_money", tmpint);
            Account_SetPlayerMoney(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_level", tmpint);
            Account_SetPlayerLevel(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_skin", tmpint);
            Account_SetPlayerSkin(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_admin", tmpint);
            Admin_SetPlayerLevel(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_admincode", tmpint);
            Admin_SetPlayerCode(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_gold", tmpint);
            Account_SetPlayerGold(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_bankmoney", tmpint);
            Account_SetPlayerBankMoney(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_bankaccount", tmpint);
            Account_SetPlayerBankAccount(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_orgid", tmpint);
            Organization_SetPlayerOrgID(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_leader", tmpint);
            Organization_SetPlayerLeader(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_gunlicense", tmpint);
            Account_SetPlayerGunLicense(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_idcard", tmpint);
            Account_SetPlayerIDCard(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_drugs", tmpint);
            Account_SetPlayerDrugs(playerid, tmpint);
            
            cache_get_value_name_int(0, "char_weed", tmpint);
            Account_SetPlayerWeed(playerid, tmpint);

            cache_get_value_name_int(0, "char_mutedtime", tmpint);
            Mute_SetTime(playerid, tmpint);

            cache_get_value_name_int(0, "char_house", tmpint);
            Account_SetPlayerHouse(playerid, tmpint);
        }

        TogglePlayerSpectating(playerid, true);
        UI_CreateLoginTextDraws(playerid);

        InterpolateCameraPos(playerid, 1284.4456, -417.3779, 161.2294, 1163.6970, -1035.5303, 227.6295, 30000);
	    InterpolateCameraLookAt(playerid, 1284.1553, -418.3311, 160.8544, 1163.6310, -1034.5365, 225.3495, 30000);

        Player_ClearChat(playerid, 40);

        return 1;
    }

    TogglePlayerSpectating(playerid, true);
    UI_CreateRegisterTextDraws(playerid);

    InterpolateCameraPos(playerid, 1284.4456, -417.3779, 161.2294, 1163.6970, -1035.5303, 227.6295, 30000);
	InterpolateCameraLookAt(playerid, 1284.1553, -418.3311, 160.8544, 1163.6310, -1034.5365, 225.3495, 30000);

    Player_ClearChat(playerid, 40);

    return 1;
}

/** Timers for spawn */
timer Account_SetPlayerSpawn[2000](playerid, type)
{
    switch (type)
    {
        case 1:
        {
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);

            CancelSelectTextDraw(playerid);
            Player_SetSpawnedStatus(playerid);

            TogglePlayerSpectating(playerid, false);
            UI_CreateRegisterTextDraws(playerid, false);
            UI_CreateInGameTextDraws(playerid, .create = false, .show = true);

            SetSpawnInfo(playerid, 0, Account_GetPlayerSkin(playerid),
                Float: 657.9413, Float: -1493.2218, Float: 14.9235, Float: 92.1932,
                0, 0, 0, 0, 0, 0
            );
            SpawnPlayer(playerid);
            Streamer_UpdateEx(playerid, Float: 657.9413, Float: -1493.2218, Float: 14.9235, .compensatedtime = 2000);

            SendServerMsgF(playerid, "Dobrodosli %s na Blackland Roleplay!", ReturnPlayerName(playerid));
            SendServerMsgF(playerid, "ID: %d | Email: %s", Account_GetPlayerUniqueID(playerid), Account_GetPlayerEmail(playerid));

            Player_SetNewbieRank(playerid);

            GivePlayerMoney(playerid, Account_GetPlayerMoney(playerid));
            SetPlayerScore(playerid, Account_GetPlayerLevel(playerid));
        }

        case 2:
        {
            SetPlayerVirtualWorld(playerid, 0);
            SetPlayerInterior(playerid, 0);

            CancelSelectTextDraw(playerid);
            Player_SetSpawnedStatus(playerid);

            TogglePlayerSpectating(playerid, false);
            UI_CreateInGameTextDraws(playerid, .create = false, .show = true);

            SetSpawnInfo(playerid, 0, Account_GetPlayerSkin(playerid),
                Float: 657.9413, Float: -1493.2218, Float: 14.9235, Float: 92.1932,
                0, 0, 0, 0, 0, 0
            );
            SpawnPlayer(playerid);
            Streamer_UpdateEx(playerid, Float: 657.9413, Float: -1493.2218, Float: 14.9235, .compensatedtime = 2000);

            SendServerMsgF(playerid, "Dobrodosli nazad %s(%d) na Blackland Roleplay!", ReturnPlayerName(playerid), playerid);

            GivePlayerMoney(playerid, Account_GetPlayerMoney(playerid));
            SetPlayerScore(playerid, Account_GetPlayerLevel(playerid));

            Player_SetNewbieRank(playerid);

            if (Admin_GetLevel(playerid))
                SetPlayerColor(playerid, 0x00000000);
        }
    }

    return 1;
}