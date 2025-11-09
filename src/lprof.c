#include "luaprof.h"

static lua_prof_cb_n_t g_lua_prof_cb_n = 0;

LUA_API void lua_prof_set_cb_n(lua_prof_cb_n_t cb) {
	g_lua_prof_cb_n = cb;
}

void lua_prof_ontrap_n(lua_State *L, unsigned int n) {
	lua_prof_cb_n_t cb = g_lua_prof_cb_n;
	if (cb && n > 0) cb(L, n);
}


