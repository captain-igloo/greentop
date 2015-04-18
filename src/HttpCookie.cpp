/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include <iostream>
#include <sstream>

#include "greentop/HttpCookie.h"

namespace greentop {

HttpCookie::HttpCookie(const std::string &cookieString) {

    std::string part;

    std::istringstream strm(cookieString);

    getline(strm, part, '\t');
    domain = part;

    getline(strm, part, '\t');
    tail = part == "TRUE";

    getline(strm, part, '\t');
    path = part;

    getline(strm, part, '\t');
    secure = part == "TRUE";

    // not implemented
    getline(strm, part, '\t');
    expires = 0;

    getline(strm, part, '\t');
    name = part;

    getline(strm, part, '\t');
    value = part;

}

HttpCookie::~HttpCookie() {
}

}
