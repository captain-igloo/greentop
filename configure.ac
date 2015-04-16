AC_INIT([greentop], [0.1])

AC_PROG_CXX
AC_LANG(C++)

AC_CHECK_HEADER([json/json.h], [], [FAIL=1])

if test "$FAIL" == 1
then
    AC_MSG_ERROR([json/json.h not found])
fi

AC_CHECK_HEADER([curlpp/cURLpp.hpp], [], [FAIL=1])

if test "$FAIL" == 1
then
    AC_MSG_ERROR([curlpp/cURLpp.hpp not found])
fi

AC_OUTPUT(Makefile examples/Makefile)
