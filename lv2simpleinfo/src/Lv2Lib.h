/*
 * This file is part of mod-host.
 *
 * mod-host is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mod-host is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mod-host.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*
************************************************************************************************************************
*
************************************************************************************************************************
*/

#ifndef LV2_LIB_H
#define LV2_LIB_H

#include <lilv/lilv.h>

typedef struct {
    LilvWorld * world;
    const LilvPlugins * plugins;
    float saldo;
} Lv2Lib;


/*
************************************************************************************************************************
*           FUNCTION PROTOTYPES
************************************************************************************************************************
*/

void Lv2Lib_constructor(Lv2Lib * lv2Liv);
void Lv2Lib_destroy(Lv2Lib * lv2Liv);
void Lv2Lib_ports_of(const char *uri, Lv2Lib * lv2Lib);
int Lv2Lib_list_effects();

#endif
