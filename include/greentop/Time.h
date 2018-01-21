/**
 * Copyright 2018 Colin Doig.  Distributed under the MIT license.
 */
#ifndef TIME_H
#define TIME_H

#if defined(__APPLE__) || defined(__linux__)
#include <time.h>
#elif defined _WIN32
#include <iomanip>
#include <locale>
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
#else
#error Platform not supported
#endif

#endif // TIME_H
