/*
** Lightweight profiler bridge between Lua VM and external module.
** Exposed only when compiled with -DLUA_PROF_TRAP.
*/
#ifndef luaprof_h
#define luaprof_h

#include "lua.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*lua_prof_cb_n_t)(lua_State *L, unsigned int n);

/* Set callback that will be invoked inside VM when sampling counter > 0 */
LUA_API void lua_prof_set_cb_n(lua_prof_cb_n_t cb);

/* Called by VM with the number of pending ticks (does nothing if no cb set). */
void lua_prof_ontrap_n(lua_State *L, unsigned int n);

#ifdef __cplusplus
}
#endif

#endif


