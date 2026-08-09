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

#ifndef SOL_CONFIG_HPP
#define SOL_CONFIG_HPP

/* Base, empty configuration file!

	 To override, place a file in your include paths of the form:


. (your include path here)
| sol (directory, or equivalent)
  | config.hpp (your config.hpp file)


	 So that when sol2 includes the file


#include <sol/config.hpp>


	 it gives you the configuration values you desire. Configuration values can be
seen in the safety.rst of the doc/src, or at
https://sol2.readthedocs.io/en/latest/safety.html ! You can also pass them through
the build system, or the command line options of your compiler.

*/

#ifndef SOL_USE_LUAU
#define SOL_USE_LUAU 1
#endif

#ifndef SOL_LUA_BIT32_LIB
#define SOL_LUA_BIT32_LIB 0
#endif

#ifndef SOL_SAFE_STACK_CHECK
#define SOL_SAFE_STACK_CHECK 0
#endif

#ifndef SOL_SAFE_GETTER
#define SOL_SAFE_GETTER 0
#endif

#ifndef SOL_SAFE_USERTYPE
#define SOL_SAFE_USERTYPE 0
#endif

#ifndef SOL_SAFE_REFERENCES
#define SOL_SAFE_REFERENCES 0
#endif

#ifndef SOL_SAFE_FUNCTION_CALLS
#define SOL_SAFE_FUNCTION_CALLS 0
#endif

#ifndef SOL_SAFE_PROXIES
#define SOL_SAFE_PROXIES 0
#endif

#ifndef SOL_SAFE_NUMERICS
#define SOL_SAFE_NUMERICS 0
#endif

#ifndef SOL_NO_CHECK_NUMBER_PRECISION
#define SOL_NO_CHECK_NUMBER_PRECISION 1
#endif

#ifndef SOL_ALL_INTEGER_VALUES_FIT
#define SOL_ALL_INTEGER_VALUES_FIT 1
#endif

#ifndef SOL_NO_COMPAT
#define SOL_NO_COMPAT 0
#endif

#ifndef SOL_USERTYPE_TYPE_BINDING_INFO
#define SOL_USERTYPE_TYPE_BINDING_INFO 0
#endif

#ifndef SOL_USE_UNSAFE_BASE_LOOKUP
#define SOL_USE_UNSAFE_BASE_LOOKUP 1
#endif

#ifndef SOL_NOEXCEPT_FUNCTION_TYPE
#define SOL_NOEXCEPT_FUNCTION_TYPE 1
#endif

#endif // SOL_CONFIG_HPP
