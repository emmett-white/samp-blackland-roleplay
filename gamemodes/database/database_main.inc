#if defined _inc_database_main
    #undef _inc_database_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _database_main_included
    #endinput
#endif
#define _database_main_included

#include <YSI_Coding\y_hooks>

/**
  * Variables
 */
new MySQL: db_handle = MYSQL_INVALID_HANDLE;
#define MySQL_GetHandle() db_handle

/**
  * Hooks
 */
hook OnGameModeInit()
{
	CreateDatabaseConnection();
    // pp_use_funcidx(true);

	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeExit()
{
    if (!mysql_close(db_handle))
    {
        print("[MySQL]: Nemoguce zavrsiti konekciju sa databazom.");
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

/**
  * Functions
 */
static CreateDatabaseConnection()
{
	static
        env_hostname[10],
        env_username[5],
        env_database[14];

	if (Env_Has("MYSQL_HOSTNAME"))
    {
		Env_Get("MYSQL_HOSTNAME", env_hostname);
	}

	if (Env_Has("MYSQL_USERNAME"))
    {
		Env_Get("MYSQL_USERNAME", env_username);
	}

	if (Env_Has("MYSQL_DATABASE"))
    {
		Env_Get("MYSQL_DATABASE", env_database);
	}

	new MySQLOpt: options = mysql_init_options();
    mysql_set_option(options, AUTO_RECONNECT, true);
    mysql_set_option(options, MULTI_STATEMENTS, true);
    mysql_set_option(options, POOL_SIZE, 2);

    MySQL_GetHandle() = mysql_connect(env_hostname, env_username, "", env_database, options);

    if (mysql_errno(MySQL_GetHandle()))
    {
        print("[MySQL]: Nije moguce uspostaviti konekciju sa databazom!");
        SendRconCommand("exit");
        return 1;
    }

    print("[MySQL]: Uspesna konekcija sa databazom.");

	return 1;
}

// OnQueryError - REQUIRED
public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle) return 1;

stock Task: MySQL_Query(const query[]) return mysql_aquery(MySQL_GetHandle(), query, true);
stock Task: MySQL_QueryS(ConstStringTag:query) return mysql_aquery_s(MySQL_GetHandle(), query, true);