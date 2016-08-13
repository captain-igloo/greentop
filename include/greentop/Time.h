/**
* Copyright 2015 Colin Doig.  Distributed under the MIT license.
*/
#ifndef TIME_H
#define TIME_H

#if defined _WIN32
#include <time.h>
#include <iomanip>
#include <sstream>

static char* strptime(const char* s, const char* f, struct tm* tm) {
    std::istringstream input(s);
    input.imbue(std::locale(setlocale(LC_ALL, nullptr)));
    input >> std::get_time(tm, f);
    if (input.fail()) {
        return nullptr;
    }
    return (char*)(s + input.tellg());
}
#endif // _WIN32

#endif // TIME_H
