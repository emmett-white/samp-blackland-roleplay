#if defined _inc_settings
    #undef _inc_settings
#endif
// custom include-guard to ensure we don't duplicate
#if defined _settings_included
    #endinput
#endif
#define _settings_included

#define MAIN_COLOR          "{0669b2}"
#define MAIN_COLOR_HEX      0x0669b2FF
#define ADMIN_CHAT_COLOR    0xb5b04aFF
#define DISCORD_INVITE_LINK "tGquNFEpXJ"

const
    MIN_PASSWORD_LENGTH =       6,
    MAX_PASSWORD_LENGTH =       24,
    MAX_LOGIN_ATTEMPTS =        3,
    MAX_ADMIN_LEVEL =           4,
    MAX_COMMANDS_PER_LEVEL =    15,
    MIN_GOLD_PRICE =            1000,
    MAX_GOLD_PRICE =            10000;
    
#define MAX_REASON_LENGTH   64
#define PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

// PawnPlus natives
native Text3D: fmt_Create3DTextLabel(ConstString: text, colour, Float:position_x, Float:position_y, Float:position_z, Float:drawDistance, virtualWorld, testlos = 0) = Create3DTextLabel;
native STREAMER_TAG_3D_TEXT_LABEL:fmt_CreateDyn3DTextLabel(ConstString: text, color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0) = CreateDynamic3DTextLabel;

// Messages
stock SendServerMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "[BLACKLAND]: "WHITE"%s", message);

    return SendClientMessage(playerid, MAIN_COLOR_HEX, str);
}

stock SendServerMsgF(const playerid, const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "[BLACKLAND]: "WHITE"%s", message);

    return va_SendClientMessage(playerid, MAIN_COLOR_HEX, va_return(str, va_start<2>));
}

stock SendErrorMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "[ERROR]: "WHITE"%s", message);

    return SendClientMessage(playerid, X11_RED, str);
}

stock SendErrorMsgF(const playerid, const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "[ERROR]: "WHITE"%s", message);

    return va_SendClientMessage(playerid, X11_RED, va_return(str, va_start<2>));
}

stock SendSyntaxMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "[KORISTI]: "WHITE"%s", message);

    return SendClientMessage(playerid, X11_ORANGE, str);
}

stock SendInfoMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "* %s", message);

    return SendClientMessage(playerid, X11_ORANGE, str);
}

stock SendInfoMsgF(const playerid, const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "* %s", message);

    return va_SendClientMessage(playerid, X11_ORANGE, va_return(str, va_start<2>));
}

stock SendInfoMsgToAllF(const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "* %s", message);

    return va_SendClientMessageToAll(X11_ORANGE, va_return(str, va_start<1>));
}