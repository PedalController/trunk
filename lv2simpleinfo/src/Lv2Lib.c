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
/*
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include <errno.h>
#include <limits.h>
#include <pthread.h>
*/
/* Jack */
//#include <jack/jack.h>
//#include <jack/midiport.h>

/* LV2 and Lilv */
#include <lilv/lilv.h>
/*#include <lv2/lv2plug.in/ns/ext/atom/atom.h>
#include <lv2/lv2plug.in/ns/ext/atom/forge.h>
#include <lv2/lv2plug.in/ns/ext/midi/midi.h>
#include <lv2/lv2plug.in/ns/ext/urid/urid.h>
#include <lv2/lv2plug.in/ns/ext/uri-map/uri-map.h>
#include <lv2/lv2plug.in/ns/ext/time/time.h>
#include <lv2/lv2plug.in/ns/ext/worker/worker.h>
#include <lv2/lv2plug.in/ns/ext/patch/patch.h>
#include <lv2/lv2plug.in/ns/ext/event/event.h>
#include <lv2/lv2plug.in/ns/ext/state/state.h>
#include <lv2/lv2plug.in/ns/ext/presets/presets.h>
#include <lv2/lv2plug.in/ns/ext/options/options.h>
#include <lv2/lv2plug.in/ns/ext/port-props/port-props.h>
#include <lv2/lv2plug.in/ns/ext/buf-size/buf-size.h>
#include <lv2/lv2plug.in/ns/ext/parameters/parameters.h>*/

#include "Lv2Lib.h"


////////////////////////////////////////////
// PRIVATE
////////////////////////////////////////////

const LilvPlugin * get_livl_plugin(const char *uri, Lv2Lib * lv2Lib);

////////////////////////////////////////////

/**
 * Initialize the Lv2Liv
 */
void Lv2Lib_constructor(Lv2Lib * lv2Liv) {
    lv2Liv->world = lilv_world_new();
    lilv_world_load_all(lv2Liv->world);

    lv2Liv->plugins = lilv_world_get_all_plugins(lv2Liv->world);
}

/**
 * Destroy the Lv2Liv
 */
void Lv2Lib_destroy(Lv2Lib * lv2Liv) {
    lilv_world_free(lv2Liv->world);
    //lilv_plugins_free(lv2Liv->world);// LilvPlugins which is internal and thus lacks a free function
}

/**
 * List all ports by uri
 */
void Lv2Lib_ports_of(const char *uri, Lv2Lib * lv2Lib) {
	const LilvPlugin *plugin = get_livl_plugin(uri, lv2Lib);

    if (plugin == NULL) {
        printf("Plugin não informado: %s", uri);
        return;
    }

    uint32_t ports_count = lilv_plugin_get_num_ports(plugin);
    float * min_values = calloc(ports_count, sizeof(float *));
    float * max_values = calloc(ports_count, sizeof(float *));
    float * def_values = calloc(ports_count, sizeof(float *));

    lilv_plugin_get_port_ranges_float(plugin, min_values, max_values, def_values);

    for (unsigned int i=0; i<ports_count; i++) {
        const LilvPort* port = lilv_plugin_get_port_by_index(plugin, i);
        const LilvNode* port_name_node = lilv_port_get_name(plugin, port);
        const char* port_name = lilv_node_as_string(port_name_node);

        printf("%u - Port \"%s\" : %f %f %f\n", i, port_name, min_values[i], max_values[i], def_values[i]);
    }

    free(min_values);
    free(max_values);
    free(def_values);

    min_values = NULL;
    max_values = NULL;
    def_values = NULL;
}

/**
 * Get livl plugin by uri
 */
const LilvPlugin * get_livl_plugin(const char *uri, Lv2Lib * lv2Lib) {
    LilvNode *plugin_uri = lilv_new_uri(lv2Lib->world, uri);
    const LilvPlugin *plugin = lilv_plugins_get_by_uri(lv2Lib->plugins, plugin_uri);
    lilv_node_free(plugin_uri);
    return plugin;
}

/**
 * List all lv2 effects
 */
int Lv2Lib_list_effects() {
    return system("lv2ls");
}



