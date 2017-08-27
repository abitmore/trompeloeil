/*
 * Trompeloeil C++ mocking framework
 *
 * Copyright Björn Fahller 2016,2017
 *
 *  Use, modification and distribution is subject to the
 *  Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 *
 * Project home: https://github.com/rollbear/trompeloeil
 */

//RETURN non-reference from function returning reference

#include <trompeloeil.hpp>

struct MS
{
  MAKE_MOCK0(f, char&());
};

int main()
{
  MS obj;

#if (TROMPELOEIL_CPLUSPLUS == 201103L)

#if (TROMPELOEIL_CXX11_API_VERSION == 1)

  using m_t = NAMED_MOCK_TYPE(obj, f());
  REQUIRE_CALL(obj, f())
    .RETURN_TYPE(m_t, 'a');

#elif (TROMPELOEIL_CXX11_API_VERSION == 2)

  MAKE_EXPECTATION(obj, f(),
  REQUIRE_CALL(obj, f())
    .RETURN('a')
  );

#else /* (TROMPELOEIL_CXX11_API_VERSION == 3) */

  REQUIRE_CALL_V(obj, f(),
    .RETURN('a'));

#endif /* !(TROMPELOEIL_CXX11_API_VERSION == 3) */

#else /* (TROMPELOEIL_CPLUSPLUS == 201103L) */

  REQUIRE_CALL(obj, f())
    .RETURN('a');

#endif /* !(TROMPELOEIL_CPLUSPLUS == 201103L) */
}
