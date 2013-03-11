/*
===========================================================================
Copyright (C) 2013 Manuel Wiese

This file is part of AfterShock source code.

Aftershock source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

AfterShock source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/
//
#include "cg_local.h"

static const char* hudNames[] = {
    "DEFAULT",
    "AmmoMessage",
    "AttackerIcon",
    "AttackerName",
    "Chat1",
    "Chat2",
    "Chat3",
    "Chat4",
    "Chat5",
    "Chat6",
    "Chat7",
    "Chat8",
    "FlagStatus_OWN",
    "FlagStatus_NME",
    "FollowMessage",
    "FPS",
    "FragMessage",
    "GameTime",
    "RoundTime",
    "GameType",
    "ItemPickupName",
    "ItemPickupTime",
    "ItemPickupIcon",
    "NetGraph",
    "NetGraphPing",
    "PlayerSpeed",
    "PlayerAccel",
    "PowerUp1_Time",
    "PowerUp2_Time",
    "PowerUp3_Time",
    "PowerUp4_Time",
    "PowerUp1_Icon",
    "PowerUp2_Icon",
    "PowerUp3_Icon",
    "PowerUp4_Icon",
    "RankMessage",
    "Score_Limit",
    "Score_NME",
    "Score_OWN",
    "SpecMessage",
    "StatusBar_ArmorBar",
    "StatusBar_ArmorCount",
    "StatusBar_ArmorIcon",
    "StatusBar_AmmoBar",
    "StatusBar_AmmoCount",
    "StatusBar_AmmoIcon",
    "StatusBar_HealthBar",
    "StatusBar_HealthCount",
    "StatusBar_HealthIcon",
    "TargetName",
    "TargetStatus",
    "TeamCount_NME",
    "TeamCount_OWN",
    "TeamIcon_NME",
    "TeamIcon_OWN",
    "Team1",
    "Team2",
    "Team3",
    "Team4",
    "Team5",
    "Team6",
    "Team7",
    "Team8",
    "VoteMessage",
    "WarmupInfo",
    "WeaponList",
    "ReadyStatus",
    "DeathNotice1",
    "DeathNotice2",
    "DeathNotice3",
    "DeathNotice4",
    "DeathNotice5",
    "Countdown",
    "RespawnTimer",
    "StatusBar_Flag",
    "TeamOverlay1",
    "TeamOverlay2",
    "TeamOverlay3",
    "TeamOverlay4",
    "TeamOverlay5",
    "TeamOverlay6",
    "TeamOverlay7",
    "TeamOverlay8",
    "Reward",
    "RewardCount",
    "Console",
    "PreDecorate1",
    "PreDecorate2",
    "PreDecorate3",
    "PreDecorate4",
    "PreDecorate5",
    "PreDecorate6",
    "PreDecorate7",
    "PreDecorate8",
    "PostDecorate1",
    "PostDecorate2",
    "PostDecorate3",
    "PostDecorate4",
    "PostDecorate5",
    "PostDecorate6",
    "PostDecorate7",
    "PostDecorate8"
};

typedef struct hudElementCommands_s {
        char *name;
        qboolean    (*function)(int handle, int hudElementNumber);
} hudElementCommands_t;

static qboolean CG_SetHudAngles(int handle, int hudElementNumber) {
    pc_token_t token;
    int i;
    for (i = 0; i < 3; i++) {
        if(trap_PC_ReadToken(handle, &token)) {
            if (token.type == TT_NUMBER) {
                cgs.hud[hudElementNumber].angles[i] = token.floatvalue;
            } else {
                CG_Printf("angles:\"%s\" is not a number\n", token.string);
                return qfalse;
            }
        } else {
            CG_Printf("angles: missing argument(%i)\n", i);
        }
    }
    return qtrue;
}

static qboolean CG_SetHudBgColor(int handle, int hudElementNumber) {
    pc_token_t token;
    int i;
    for (i = 0; i < 4; i++) {
        if(trap_PC_ReadToken(handle, &token)) {
            if (token.type == TT_NUMBER) {
                cgs.hud[hudElementNumber].bgcolor[i] = token.floatvalue;
            } else {
                CG_Printf("bgcolor:\"%s\" is not a number\n", token.string);
                return qfalse;
            }
        } else {
            CG_Printf("bgcolor: missing argument(%i)\n", i);
        }
    }
    return qtrue;
}

static qboolean CG_SetHudColor(int handle, int hudElementNumber) {
    pc_token_t token;
    int i;
    for (i = 0; i < 4; i++) {
        if(trap_PC_ReadToken(handle, &token)) {
            if (token.type == TT_NUMBER) {
                cgs.hud[hudElementNumber].color[i] = token.floatvalue;
            } else {
                CG_Printf("color:\"%s\" is not a number\n", token.string);
                return qfalse;
            }
        } else {
            CG_Printf("color: missing argument(%i)\n", i);
        }
    }
    return qtrue;
}

static qboolean CG_SetHudDoublebar(int handle, int hudElementNumber) {
    cgs.hud[hudElementNumber].doublebar = qtrue;
    return qtrue;
}

static qboolean CG_SetHudFade(int handle, int hudElementNumber) {
    pc_token_t token;
    int i;
    for (i = 0; i < 4; i++) {
        if(trap_PC_ReadToken(handle, &token)) {
            if (token.type == TT_NUMBER) {
                cgs.hud[hudElementNumber].fade[i] = token.floatvalue;
            } else {
                CG_Printf("fade:\"%s\" is not a number\n", token.string);
                return qfalse;
            }
        } else {
            CG_Printf("fade: missing argument(%i)\n", i);
        }
    }
    return qtrue;
}

static qboolean CG_SetHudFill(int handle, int hudElementNumber) {
    cgs.hud[hudElementNumber].fill = qtrue;
    return qtrue;
}

static qboolean CG_SetHudFont(int handle, int hudElementNumber) {
    pc_token_t token;
    if(trap_PC_ReadToken(handle, &token)) {
        cgs.hud[hudElementNumber].font = 1;
        return qtrue;
    } else {
        CG_Printf("font: missing argument\n");
    }
    return qfalse;
}

static qboolean CG_SetHudFontsize(int handle, int hudElementNumber) {
    pc_token_t token;
    int i;
    for (i = 0; i < 2; i++) {
        if(trap_PC_ReadToken(handle, &token)) {
            if (token.type == TT_NUMBER) {
                cgs.hud[hudElementNumber].fontSize[i] = token.floatvalue;
            } else {
                CG_Printf("fontsize:\"%s\" is not a number\n", token.string);
                return qfalse;
            }
        } else {
            CG_Printf("fontsize: missing argument(%i)\n", i);
        }
    }
    return qtrue;
}

static qboolean CG_SetHudImage(int handle, int hudElementNumber) {
    pc_token_t token;
    if(trap_PC_ReadToken(handle, &token)) {
        if (token.type == TT_STRING) {
            cgs.hud[hudElementNumber].image = trap_R_RegisterShader(token.string);
            return qtrue;
        }
        CG_Printf("image: \"%s\" is not a string\n", token.string);
    } else {
        CG_Printf("image: missing argument\n");
    }
    return qfalse;
}

static qboolean CG_SetHudModel(int handle, int hudElementNumber) {
    pc_token_t token;
    if(trap_PC_ReadToken(handle, &token)) {
        if (token.type == TT_STRING) {
            cgs.hud[hudElementNumber].model = trap_R_RegisterModel(token.string);
            return qtrue;
        }
        CG_Printf("model: \"%s\" is not a string\n", token.string);
    } else {
        CG_Printf("model: missing argument\n");
    }
    return qfalse;
}

static qboolean CG_SetHudOffset(int handle, int hudElementNumber) {
    pc_token_t token;
    int i;
    for (i = 0; i < 3; i++) {
        if(trap_PC_ReadToken(handle, &token)) {
            if (token.type == TT_NUMBER) {
                cgs.hud[hudElementNumber].offset[i] = token.floatvalue;
            } else {
                CG_Printf("offset: \"%s\" is not a number\n", token.string);
                return qfalse;
            }
        } else {
            CG_Printf("offset: missing argument(%i)\n", i);
        }
    }
    return qtrue;
}

static qboolean CG_SetHudRect(int handle, int hudElementNumber) {
    pc_token_t token;
    int i;
    for (i = 0; i < 4; i++) {
        if(trap_PC_ReadToken(handle, &token)) {
            if (token.type == TT_NUMBER) {
                cgs.hud[hudElementNumber].rect[i] = token.floatvalue;
            } else {
                CG_Printf("rect:\"%s\" is not a number\n", token.string);
                return qfalse;
            }
        } else {
            CG_Printf("rect: missing argument(%i)\n", i);
        }
    }
    return qtrue;
}

static qboolean CG_SetHudText(int handle, int hudElementNumber) {
    pc_token_t token;
    if(trap_PC_ReadToken(handle, &token)) {
        if (token.type == TT_STRING) {
             Com_sprintf(cgs.hud[hudElementNumber].text, 64, "%s", token.string);
            return qtrue;
        }
        CG_Printf("text: \"%s\" is not a string\n", token.string); 
    } else {
        CG_Printf("text: missing argument\n");
    }
    return qfalse;
}

static qboolean CG_SetHudTextalign(int handle, int hudElementNumber) {
    pc_token_t token;
    if(trap_PC_ReadToken(handle, &token)) {
        if (token.type == TT_STRING || token.type == TT_NAME) {
             if (Q_stricmp(token.string, "L") == 0){
                 cgs.hud[hudElementNumber].textalign = -1;
             } else if (Q_stricmp(token.string, "C") == 0){
                 cgs.hud[hudElementNumber].textalign = 0;
             } else if (Q_stricmp(token.string, "R") == 0){
                 cgs.hud[hudElementNumber].textalign = 1;
             } else {
                 CG_Printf("textalign: \"%s\" not allowed\n", token.string);
                 return qfalse;
             }
            return qtrue;
        }
        CG_Printf("textalign: \"%s\" not allowed\n", token.string);
    } else {
        CG_Printf("textalign: missing argument\n");
    }
    return qfalse;
}

static qboolean CG_SetHudTextstyle(int handle, int hudElementNumber) {
    pc_token_t token;
    if(trap_PC_ReadToken(handle, &token)) {
        if (token.type == TT_NUMBER) {
             cgs.hud[hudElementNumber].textstyle = token.intvalue;
            return qtrue;
        }
        CG_Printf("textstyle: \"%s\" is not a number\n", token.string);
    } else {
        CG_Printf("textalign: missing argument\n");
    }
    return qfalse;
}

static qboolean CG_SetHudTime(int handle, int hudElementNumber) {
    pc_token_t token;
    if(trap_PC_ReadToken(handle, &token)) {
        if (token.type == TT_NUMBER) {
             cgs.hud[hudElementNumber].time = token.intvalue;
            return qtrue;
        }
        CG_Printf("time: \"%s\" is not a number\n", token.string);
    } else {
        CG_Printf("time: missing argument\n");
    }
    return qfalse;
}

#define MAX_PROPERTIES 16
hudElementCommands_t hudCommands[MAX_PROPERTIES] = {
    { (char*)"angles", CG_SetHudAngles },
    { (char*)"bgcolor", CG_SetHudBgColor },
    { (char*)"color", CG_SetHudColor },
    { (char*)"doublebar", CG_SetHudDoublebar },
    { (char*)"fade", CG_SetHudFade },
    { (char*)"fill", CG_SetHudFill },
    { (char*)"font", CG_SetHudFont },
    { (char*)"fontsize", CG_SetHudFontsize },
    { (char*)"image", CG_SetHudImage },
    { (char*)"model", CG_SetHudModel },
    { (char*)"offset", CG_SetHudOffset },
    { (char*)"rect", CG_SetHudRect },
    { (char*)"text", CG_SetHudText },
    { (char*)"textalign", CG_SetHudTextalign },
    { (char*)"textstyle", CG_SetHudTextstyle },
    { (char*)"time", CG_SetHudTime }
};

static void CG_SetDefault(int hudElementNumber) {
    hudElement_t* hudelement = &cgs.hud[hudElementNumber];
    hudElement_t* defaultElement = &cgs.hud[HUD_DEFAULT];
    
    memcpy(hudelement, defaultElement, sizeof(hudElement_t));
}

static int CG_IsSuperhudPropertie(pc_token_t *token) {
    int i;
    for(i = 0; i < MAX_PROPERTIES; i++) {
        if (Q_stricmp(token->string, hudCommands[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

static qboolean CG_ParseHudElement(int handle, int hudElementNumber) {
    pc_token_t token;
    int command;
    trap_PC_ReadToken(handle, &token);

    CG_SetDefault(hudElementNumber);

    if (token.type != TT_PUNCTUATION) {
        CG_Printf("\"{\" expected\n");
        return qfalse;
    }
    while (trap_PC_ReadToken(handle, &token)) {
        if (Q_stricmp(token.string, "}") == 0) {
            return qtrue;
        }
        command = CG_IsSuperhudPropertie(&token);
        if (command != -1) {
            if(!hudCommands[command].function(handle, hudElementNumber)) {
                return qfalse;
            }
        } else {
            CG_Printf("\"%s\" is not a valid hud property\n", token.string);
            return qfalse;
        }
    }
    CG_Printf("} missing\n");
    return qfalse;
}

static int CG_IsSuperhudKeyword(pc_token_t *token) {
    int i;

    if (token->type != TT_STRING && token->type != TT_NAME) {
        return -1;
    }
    for (i = 0; i < HUD_MAX; i++) {
        if (Q_stricmp(token->string, hudNames[i]) == 0) {
            return i;
        }
    }
    return -1;
}

static void CG_InitHud(void) {
    hudElement_t* defaultHud = &cgs.hud[HUD_DEFAULT];
    int i;
    
    defaultHud->angles[0] = defaultHud->angles[1] = defaultHud->angles[2] = 0.0f;
    defaultHud->bgcolor[0] = defaultHud->bgcolor[1] = defaultHud->bgcolor[2] = defaultHud->bgcolor[3] = 0.0f;
    defaultHud->color[0] = defaultHud->color[1] = defaultHud->color[2] = defaultHud->color[3] = 1.0f;
    defaultHud->doublebar = qfalse;
    defaultHud->fade[0] = defaultHud->fade[1] = defaultHud->fade[2] = 1.0f;
    defaultHud->fade[3] = 0.0f;
    defaultHud->fill = qfalse;
    defaultHud->font = 1;
    defaultHud->fontSize[0] = 8;
    defaultHud->fontSize[1] = 12;
    defaultHud->image = 0;
    defaultHud->inUse = qfalse;
    defaultHud->model = 0;
    defaultHud->offset[0] = defaultHud->offset[1] =defaultHud->offset[2] = 0.0f;
    defaultHud->rect[0] = defaultHud->rect[1] = defaultHud->rect[2] = defaultHud->rect[3] = 0.0f;
    Com_sprintf(defaultHud->text, sizeof(defaultHud->text), "");
    defaultHud->textalign = 0;
    defaultHud->textstyle = 0;
    defaultHud->time = 0;

    for (i = HUD_DEFAULT + 1; i < HUD_MAX; i++) {
        memcpy(&cgs.hud[i], defaultHud, sizeof(hudElement_t));
    }

    defaultHud->inUse = qtrue;
}

void CG_LoadSuperhud(void) {
    pc_token_t token;
    int handle;
    int hudElementNumber;

    handle = trap_PC_LoadSource("hud/default.cfg");
    if (!handle) {
        return;
    }

    CG_InitHud();

    while (trap_PC_ReadToken(handle, &token)) {
        hudElementNumber = CG_IsSuperhudKeyword(&token);
        if (hudElementNumber != -1) {
            if (!CG_ParseHudElement(handle, hudElementNumber)) {
                CG_Printf("Error in %s\n", token.string);
                break;
            }
        } else {
            CG_Printf("\"%s\" is not a valid hud keyword\n", token.string);
            break;
        }
    }
    
    trap_PC_FreeSource(handle);
}
