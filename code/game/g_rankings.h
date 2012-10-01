/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/
// g_rankings.h -- score keys for global rankings

#ifndef _G_RANKINGS_H_
#define _G_RANKINGS_H_

/*
==============================================================================

Key digits:
    10^9: report type
            1 = normal
            2 = developer-only
    10^8: stat type
            0 = match stat
            1 = single player stat
            2 = duel stat
    10^7: data type
            0 = string
            1 = uint32
    10^6: calculation
            0 = use raw value
            1 = add to total
            2 = average
            3 = max
            4 = min
    10^5
    10^4: category
            00 = general
            01 = session
            02 = weapon
            03 = ammo
            04 = health
            05 = armor
            06 = powerup
            07 = holdable
            08 = hazard
            09 = reward
            10 = teammate
            11 = ctf
    10^3:
    10^2: sub-category
    10^1:
    10^0: ordinal

==============================================================================
*/

// general keys
#define QGR_KEY_MATCH_RATING            1112000001
#define QGR_KEY_PLAYED_WITH             1210000002

// session keys
#define QGR_KEY_HOSTNAME                1000010000
#define QGR_KEY_MAP                     1000010001
#define QGR_KEY_MOD                     1000010002
#define QGR_KEY_GAMETYPE                1010010003
#define QGR_KEY_FRAGLIMIT               1010010004
#define QGR_KEY_TIMELIMIT               1010010005
#define QGR_KEY_MAXCLIENTS              1010010006
#define QGR_KEY_MAXRATE                 1010010007
#define QGR_KEY_MINPING                 1010010008
#define QGR_KEY_MAXPING                 1010010009
#define QGR_KEY_DEDICATED               1010010010
#define QGR_KEY_VERSION                 1000010011

// weapon keys
#define QGR_KEY_FRAG                    1211020000
#define QGR_KEY_SUICIDE                 1111020001
#define QGR_KEY_SHOT_FIRED              1111020002
#define QGR_KEY_HIT_GIVEN               1111020003
#define QGR_KEY_HIT_TAKEN               1111020004
#define QGR_KEY_DAMAGE_GIVEN            1111020005
#define QGR_KEY_DAMAGE_TAKEN            1111020006
#define QGR_KEY_SPLASH_GIVEN            1111020007
#define QGR_KEY_SPLASH_TAKEN            1111020008
#define QGR_KEY_PICKUP_WEAPON           1111020009
#define QGR_KEY_TIME                    1111020010

#define QGR_KEY_FRAG_GAUNTLET           1211020100
#define QGR_KEY_SUICIDE_GAUNTLET        1111020101
#define QGR_KEY_SHOT_FIRED_GAUNTLET     1111020102
#define QGR_KEY_HIT_GIVEN_GAUNTLET      1111020103
#define QGR_KEY_HIT_TAKEN_GAUNTLET      1111020104
#define QGR_KEY_DAMAGE_GIVEN_GAUNTLET   1111020105
#define QGR_KEY_DAMAGE_TAKEN_GAUNTLET   1111020106
#define QGR_KEY_SPLASH_GIVEN_GAUNTLET   1111020107
#define QGR_KEY_SPLASH_TAKEN_GAUNTLET   1111020108
#define QGR_KEY_PICKUP_GAUNTLET         1111020109
#define QGR_KEY_TIME_GAUNTLET           1111020110

#define QGR_KEY_FRAG_MACHINEGUN         1211020200
#define QGR_KEY_SUICIDE_MACHINEGUN      1111020201
#define QGR_KEY_SHOT_FIRED_MACHINEGUN   1111020202
#define QGR_KEY_HIT_GIVEN_MACHINEGUN    1111020203
#define QGR_KEY_HIT_TAKEN_MACHINEGUN    1111020204
#define QGR_KEY_DAMAGE_GIVEN_MACHINEGUN 1111020205
#define QGR_KEY_DAMAGE_TAKEN_MACHINEGUN 1111020206
#define QGR_KEY_SPLASH_GIVEN_MACHINEGUN 1111020207
#define QGR_KEY_SPLASH_TAKEN_MACHINEGUN 1111020208
#define QGR_KEY_PICKUP_MACHINEGUN       1111020209
#define QGR_KEY_TIME_MACHINEGUN         1111020210

#define QGR_KEY_FRAG_SHOTGUN            1211020300
#define QGR_KEY_SUICIDE_SHOTGUN         1111020301
#define QGR_KEY_SHOT_FIRED_SHOTGUN      1111020302
#define QGR_KEY_HIT_GIVEN_SHOTGUN       1111020303
#define QGR_KEY_HIT_TAKEN_SHOTGUN       1111020304
#define QGR_KEY_DAMAGE_GIVEN_SHOTGUN    1111020305
#define QGR_KEY_DAMAGE_TAKEN_SHOTGUN    1111020306
#define QGR_KEY_SPLASH_GIVEN_SHOTGUN    1111020307
#define QGR_KEY_SPLASH_TAKEN_SHOTGUN    1111020308
#define QGR_KEY_PICKUP_SHOTGUN          1111020309
#define QGR_KEY_TIME_SHOTGUN            1111020310

#define QGR_KEY_FRAG_GRENADE            1211020400
#define QGR_KEY_SUICIDE_GRENADE         1111020401
#define QGR_KEY_SHOT_FIRED_GRENADE      1111020402
#define QGR_KEY_HIT_GIVEN_GRENADE       1111020403
#define QGR_KEY_HIT_TAKEN_GRENADE       1111020404
#define QGR_KEY_DAMAGE_GIVEN_GRENADE    1111020405
#define QGR_KEY_DAMAGE_TAKEN_GRENADE    1111020406
#define QGR_KEY_SPLASH_GIVEN_GRENADE    1111020407
#define QGR_KEY_SPLASH_TAKEN_GRENADE    1111020408
#define QGR_KEY_PICKUP_GRENADE          1111020409
#define QGR_KEY_TIME_GRENADE            1111020410

#define QGR_KEY_FRAG_ROCKET             1211020500
#define QGR_KEY_SUICIDE_ROCKET          1111020501
#define QGR_KEY_SHOT_FIRED_ROCKET       1111020502
#define QGR_KEY_HIT_GIVEN_ROCKET        1111020503
#define QGR_KEY_HIT_TAKEN_ROCKET        1111020504
#define QGR_KEY_DAMAGE_GIVEN_ROCKET     1111020505
#define QGR_KEY_DAMAGE_TAKEN_ROCKET     1111020506
#define QGR_KEY_SPLASH_GIVEN_ROCKET     1111020507
#define QGR_KEY_SPLASH_TAKEN_ROCKET     1111020508
#define QGR_KEY_PICKUP_ROCKET           1111020509
#define QGR_KEY_TIME_ROCKET             1111020510

#define QGR_KEY_FRAG_PLASMA             1211020600
#define QGR_KEY_SUICIDE_PLASMA          1111020601
#define QGR_KEY_SHOT_FIRED_PLASMA       1111020602
#define QGR_KEY_HIT_GIVEN_PLASMA        1111020603
#define QGR_KEY_HIT_TAKEN_PLASMA        1111020604
#define QGR_KEY_DAMAGE_GIVEN_PLASMA     1111020605
#define QGR_KEY_DAMAGE_TAKEN_PLASMA     1111020606
#define QGR_KEY_SPLASH_GIVEN_PLASMA     1111020607
#define QGR_KEY_SPLASH_TAKEN_PLASMA     1111020608
#define QGR_KEY_PICKUP_PLASMA           1111020609
#define QGR_KEY_TIME_PLASMA             1111020610

#define QGR_KEY_FRAG_RAILGUN            1211020700
#define QGR_KEY_SUICIDE_RAILGUN         1111020701
#define QGR_KEY_SHOT_FIRED_RAILGUN      1111020702
#define QGR_KEY_HIT_GIVEN_RAILGUN       1111020703
#define QGR_KEY_HIT_TAKEN_RAILGUN       1111020704
#define QGR_KEY_DAMAGE_GIVEN_RAILGUN    1111020705
#define QGR_KEY_DAMAGE_TAKEN_RAILGUN    1111020706
#define QGR_KEY_SPLASH_GIVEN_RAILGUN    1111020707
#define QGR_KEY_SPLASH_TAKEN_RAILGUN    1111020708
#define QGR_KEY_PICKUP_RAILGUN          1111020709
#define QGR_KEY_TIME_RAILGUN            1111020710

#define QGR_KEY_FRAG_LIGHTNING          1211020800
#define QGR_KEY_SUICIDE_LIGHTNING       1111020801
#define QGR_KEY_SHOT_FIRED_LIGHTNING    1111020802
#define QGR_KEY_HIT_GIVEN_LIGHTNING     1111020803
#define QGR_KEY_HIT_TAKEN_LIGHTNING     1111020804
#define QGR_KEY_DAMAGE_GIVEN_LIGHTNING  1111020805
#define QGR_KEY_DAMAGE_TAKEN_LIGHTNING  1111020806
#define QGR_KEY_SPLASH_GIVEN_LIGHTNING  1111020807
#define QGR_KEY_SPLASH_TAKEN_LIGHTNING  1111020808
#define QGR_KEY_PICKUP_LIGHTNING        1111020809
#define QGR_KEY_TIME_LIGHTNING          1111020810

#define QGR_KEY_FRAG_BFG                1211020900
#define QGR_KEY_SUICIDE_BFG             1111020901
#define QGR_KEY_SHOT_FIRED_BFG          1111020902
#define QGR_KEY_HIT_GIVEN_BFG           1111020903
#define QGR_KEY_HIT_TAKEN_BFG           1111020904
#define QGR_KEY_DAMAGE_GIVEN_BFG        1111020905
#define QGR_KEY_DAMAGE_TAKEN_BFG        1111020906
#define QGR_KEY_SPLASH_GIVEN_BFG        1111020907
#define QGR_KEY_SPLASH_TAKEN_BFG        1111020908
#define QGR_KEY_PICKUP_BFG              1111020909
#define QGR_KEY_TIME_BFG                1111020910

#define QGR_KEY_FRAG_GRAPPLE            1211021000
#define QGR_KEY_SUICIDE_GRAPPLE         1111021001
#define QGR_KEY_SHOT_FIRED_GRAPPLE      1111021002
#define QGR_KEY_HIT_GIVEN_GRAPPLE       1111021003
#define QGR_KEY_HIT_TAKEN_GRAPPLE       1111021004
#define QGR_KEY_DAMAGE_GIVEN_GRAPPLE    1111021005
#define QGR_KEY_DAMAGE_TAKEN_GRAPPLE    1111021006
#define QGR_KEY_SPLASH_GIVEN_GRAPPLE    1111021007
#define QGR_KEY_SPLASH_TAKEN_GRAPPLE    1111021008
#define QGR_KEY_PICKUP_GRAPPLE          1111021009
#define QGR_KEY_TIME_GRAPPLE            1111021010

#define QGR_KEY_FRAG_UNKNOWN            1211021100
#define QGR_KEY_SUICIDE_UNKNOWN         1111021101
#define QGR_KEY_SHOT_FIRED_UNKNOWN      1111021102
#define QGR_KEY_HIT_GIVEN_UNKNOWN       1111021103
#define QGR_KEY_HIT_TAKEN_UNKNOWN       1111021104
#define QGR_KEY_DAMAGE_GIVEN_UNKNOWN    1111021105
#define QGR_KEY_DAMAGE_TAKEN_UNKNOWN    1111021106
#define QGR_KEY_SPLASH_GIVEN_UNKNOWN    1111021107
#define QGR_KEY_SPLASH_TAKEN_UNKNOWN    1111021108
#define QGR_KEY_PICKUP_UNKNOWN          1111021109
#define QGR_KEY_TIME_UNKNOWN            1111021110

#ifdef MISSIONPACK
// new to team arena
#define QGR_KEY_FRAG_NAILGIN            1211021200
#define QGR_KEY_SUICIDE_NAILGIN         1111021201
#define QGR_KEY_SHOT_FIRED_NAILGIN      1111021202
#define QGR_KEY_HIT_GIVEN_NAILGIN       1111021203
#define QGR_KEY_HIT_TAKEN_NAILGIN       1111021204
#define QGR_KEY_DAMAGE_GIVEN_NAILGIN    1111021205
#define QGR_KEY_DAMAGE_TAKEN_NAILGIN    1111021206
#define QGR_KEY_SPLASH_GIVEN_NAILGIN    1111021207
#define QGR_KEY_SPLASH_TAKEN_NAILGIN    1111021208
#define QGR_KEY_PICKUP_NAILGIN          1111021209
#define QGR_KEY_TIME_NAILGIN            1111021210
// new to team arena
#define QGR_KEY_FRAG_PROX_LAUNCHER          1211021300
#define QGR_KEY_SUICIDE_PROX_LAUNCHER       1111021301
#define QGR_KEY_SHOT_FIRED_PROX_LAUNCHER    1111021302
#define QGR_KEY_HIT_GIVEN_PROX_LAUNCHER     1111021303
#define QGR_KEY_HIT_TAKEN_PROX_LAUNCHER     1111021304
#define QGR_KEY_DAMAGE_GIVEN_PROX_LAUNCHER  1111021305
#define QGR_KEY_DAMAGE_TAKEN_PROX_LAUNCHER  1111021306
#define QGR_KEY_SPLASH_GIVEN_PROX_LAUNCHER  1111021307
#define QGR_KEY_SPLASH_TAKEN_PROX_LAUNCHER  1111021308
#define QGR_KEY_PICKUP_PROX_LAUNCHER        1111021309
#define QGR_KEY_TIME_PROX_LAUNCHER          1111021310
// new to team arena
#define QGR_KEY_FRAG_CHAINGUN           1211021400
#define QGR_KEY_SUICIDE_CHAINGUN        1111021401
#define QGR_KEY_SHOT_FIRED_CHAINGUN     1111021402
#define QGR_KEY_HIT_GIVEN_CHAINGUN      1111021403
#define QGR_KEY_HIT_TAKEN_CHAINGUN      1111021404
#define QGR_KEY_DAMAGE_GIVEN_CHAINGUN   1111021405
#define QGR_KEY_DAMAGE_TAKEN_CHAINGUN   1111021406
#define QGR_KEY_SPLASH_GIVEN_CHAINGUN   1111021407
#define QGR_KEY_SPLASH_TAKEN_CHAINGUN   1111021408
#define QGR_KEY_PICKUP_CHAINGUN         1111021409
#define QGR_KEY_TIME_CHAINGUN           1111021410
#endif /* MISSIONPACK */

// ammo keys
#define QGR_KEY_BOXES                   1111030000
#define QGR_KEY_ROUNDS                  1111030001

#define QGR_KEY_BOXES_BULLETS           1111030100
#define QGR_KEY_ROUNDS_BULLETS          1111030101

#define QGR_KEY_BOXES_SHELLS            1111030200
#define QGR_KEY_ROUNDS_SHELLS           1111030201

#define QGR_KEY_BOXES_GRENADES          1111030300
#define QGR_KEY_ROUNDS_GRENADES         1111030301

#define QGR_KEY_BOXES_ROCKETS           1111030400
#define QGR_KEY_ROUNDS_ROCKETS          1111030401

#define QGR_KEY_BOXES_CELLS             1111030500
#define QGR_KEY_ROUNDS_CELLS            1111030501

#define QGR_KEY_BOXES_SLUGS             1111030600
#define QGR_KEY_ROUNDS_SLUGS            1111030601

#define QGR_KEY_BOXES_LG_AMMO           1111030700
#define QGR_KEY_ROUNDS_LG_AMMO          1111030701

#define QGR_KEY_BOXES_BFG_AMMO          1111030800
#define QGR_KEY_ROUNDS_BFG_AMMO         1111030801

#ifdef MISSIONPACK
// new to team arena
#define QGR_KEY_BOXES_NAILGUN_AMMO      1111030900
#define QGR_KEY_ROUNDS_NAILGUN_AMMO     1111030901
// new to team arena
#define QGR_KEY_BOXES_PROX_LAUNCHER_AMMO    1111031000
#define QGR_KEY_ROUNDS_PROX_LAUNCHER_AMMO   1111031001
// new to team arena
#define QGR_KEY_BOXES_CHAINGUN_AMMO     1111031100
#define QGR_KEY_ROUNDS_CHAINGUN_AMMO    1111031101
#endif /* MISSIONPACK */

// health keys
#define QGR_KEY_HEALTH                  1111040000
#define QGR_KEY_HEALTH_TOTAL            1111040001

#define QGR_KEY_HEALTH_5                1111040100
#define QGR_KEY_HEALTH_25               1111040200
#define QGR_KEY_HEALTH_50               1111040300
#define QGR_KEY_HEALTH_MEGA             1111040400

// armor keys
#define QGR_KEY_ARMOR                   1111050000
#define QGR_KEY_ARMOR_TOTAL             1111050001

#define QGR_KEY_ARMOR_SHARD             1111050100
#define QGR_KEY_ARMOR_YELLOW            1111050200
#define QGR_KEY_ARMOR_RED               1111050300

// powerup keys
#define QGR_KEY_POWERUP                 1111060000
#define QGR_KEY_QUAD                    1111060100
#define QGR_KEY_SUIT                    1111060200
#define QGR_KEY_HASTE                   1111060300
#define QGR_KEY_INVIS                   1111060400
#define QGR_KEY_REGEN                   1111060500
#define QGR_KEY_FLIGHT                  1111060600

#ifdef MISSIONPACK
// persistant powerup keys
// new to team arena
#define QGR_KEY_SCOUT                   1111160800
#define QGR_KEY_GUARD                   1111160801
#define QGR_KEY_DOUBLER                 1111160802
#define QGR_KEY_AMMOREGEN               1111160803

#endif //MISSIONPACK

// holdable item keys
#define QGR_KEY_MEDKIT                  1111070000
#define QGR_KEY_MEDKIT_USE              1111070001

#define QGR_KEY_TELEPORTER              1111070100
#define QGR_KEY_TELEPORTER_USE          1111070101

#ifdef MISSIONPACK
// new to team arena
#define QGR_KEY_KAMIKAZE                1111070200
#define QGR_KEY_KAMIKAZE_USE            1111070201
// new to team arena
#define QGR_KEY_PORTAL                  1111070300
#define QGR_KEY_PORTAL_USE              1111070301
// new to team arena
#define QGR_KEY_INVULNERABILITY         1111070400
#define QGR_KEY_INVULNERABILITY_USE     1111070401
#endif /* MISSIONPACK */

// hazard keys
#define QGR_KEY_HAZARD_DEATH            1111080000
#define QGR_KEY_WATER                   1111080100
#define QGR_KEY_SLIME                   1111080200
#define QGR_KEY_LAVA                    1111080300
#define QGR_KEY_CRUSH                   1111080400
#define QGR_KEY_TELEFRAG                1111080500
#define QGR_KEY_FALLING                 1111080600
#define QGR_KEY_SUICIDE_CMD             1111080700
#define QGR_KEY_TRIGGER_HURT            1111080800
#define QGR_KEY_HAZARD_MISC             1111080900

// reward keys
#define QGR_KEY_IMPRESSIVE              1111090000
#define QGR_KEY_EXCELLENT               1111090100

// teammate keys
#define QGR_KEY_TEAMMATE_FRAG           1211100000
#define QGR_KEY_TEAMMATE_HIT_GIVEN      1111100001
#define QGR_KEY_TEAMMATE_HIT_TAKEN      1111100002
#define QGR_KEY_TEAMMATE_DAMAGE_GIVEN   1111100003
#define QGR_KEY_TEAMMATE_DAMAGE_TAKEN   1111100004
#define QGR_KEY_TEAMMATE_SPLASH_GIVEN   1111100005
#define QGR_KEY_TEAMMATE_SPLASH_TAKEN   1111100006
#define QGR_KEY_TEAM_NAME               1100100007

// ctf keys
#define QGR_KEY_FLAG_PICKUP             1111110000
#define QGR_KEY_FLAG_CAPTURE            1111110001

#endif // _G_RANKINGS_H_
