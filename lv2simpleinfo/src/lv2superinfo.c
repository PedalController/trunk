/*
 * This file is part of lv2superinfo
 *
 * mod-host is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * lv2superinfo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with lv2superinfo.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*
************************************************************************************************************************
*           INCLUDE FILES
************************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

#include "Lv2Lib.h"

//./lv2superinfo http://guitarix.sourceforge.net/plugins/gx_amp#GUITARIX

void list_uri_ports(const char * uri) {
    // List effects params
    Lv2Lib * lib = malloc(sizeof(Lv2Lib *));
    Lv2Lib_constructor(lib);

    Lv2Lib_ports_of(uri, lib);

    Lv2Lib_destroy(lib);
}

void list_effects() {
    Lv2Lib_list_effects();
}

int main(int argc, const char* argv[]) {
    /*
    printf("%i", argc);
    printf("%s", argv[1]);
    printf("%p", &argv[1]);
     */

    const char * effect = argv[1];
    list_uri_ports(effect);

    list_effects();
}

