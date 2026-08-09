// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_COMPATIBILITY_LUA_VERSION_HPP
#define SOL_COMPATIBILITY_LUA_VERSION_HPP

#include <sol/version.hpp>

// clang-format off

#include <lua.h>
#include <lualib.h>

// Bla bla bla compiler warning about unreachable code, so we have to use macros
#define return_luaL_error(L, fmt, ...) luaL_errorL(L, fmt, ##__VA_ARGS__);
#define return_lua_error(L) lua_error(L);

// Exception safety / propagation, according to Lua information
// and user defines. Note this can sometimes change based on version information...
#if defined(SOL_EXCEPTIONS_ALWAYS_UNSAFE)
	#if (SOL_EXCEPTIONS_ALWAYS_UNSAFE != 0)
		#define SOL_PROPAGATE_EXCEPTIONS_I_ SOL_OFF
	#else
		#define SOL_PROPAGATE_EXCEPTIONS_I_ SOL_ON
	#endif
#elif defined(SOL_EXCEPTIONS_SAFE_PROPAGATION)
	#if (SOL_EXCEPTIONS_SAFE_PROPAGATION != 0)
		#define SOL_PROPAGATE_EXCEPTIONS_I_ SOL_ON
	#else
		#define SOL_PROPAGATE_EXCEPTIONS_I_ SOL_OFF
	#endif
#else
	// This project targets Luau only, which has no native exception
	// support to propagate through; errors are always serialized.
	#define SOL_PROPAGATE_EXCEPTIONS_I_ SOL_DEFAULT_OFF
#endif

// Some configurations work with exceptions,
// but cannot catch-all everything...
#if defined(SOL_EXCEPTIONS_CATCH_ALL)
	#if (SOL_EXCEPTIONS_CATCH_ALL != 0)
		#define SOL_EXCEPTIONS_CATCH_ALL_I_ SOL_ON
	#else
		#define SOL_EXCEPTIONS_CATCH_ALL_I_ SOL_OFF
	#endif
#else
	// By default, everything should be caught.
	#define SOL_EXCEPTIONS_CATCH_ALL_I_ SOL_DEFAULT_ON
#endif

// Luau's compat-luau.h luaL_Stream shim has no `closef` member (Luau
// has no io library, so it's never actually instantiated at runtime);
// referencing ->closef would fail to compile.
#if defined(SOL_LUAL_STREAM_HAS_CLOSE_FUNCTION)
	#if (SOL_LUAL_STREAM_HAS_CLOSE_FUNCTION != 0)
		#define SOL_LUAL_STREAM_USE_CLOSE_FUNCTION_I_ SOL_ON
	#else
		#define SOL_LUAL_STREAM_USE_CLOSE_FUNCTION_I_ SOL_OFF
	#endif
#else
	#define SOL_LUAL_STREAM_USE_CLOSE_FUNCTION_I_ SOL_DEFAULT_OFF
#endif

// Luau has no bit32 library (version.hpp forces SOL_LUA_BIT32_LIB to 0
// when SOL_USE_LUAU is on); the PUC-Lua 5.2-vs-5.3-vs-5.4 branching
// that stock sol2 uses here does not apply.
#if defined(SOL_LUA_BIT32_LIB)
	#if (SOL_LUA_BIT32_LIB != 0)
		#define SOL_LUA_BIT32_LIB_I_ SOL_ON
	#else
		#define SOL_LUA_BIT32_LIB_I_ SOL_OFF
	#endif
#else
	#define SOL_LUA_BIT32_LIB_I_ SOL_DEFAULT_OFF
#endif

// clang-format on

#endif // SOL_COMPATIBILITY_LUA_VERSION_HPP
