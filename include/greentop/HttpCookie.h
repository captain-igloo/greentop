/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef HTTPCOOKIE_H
#define HTTPCOOKIE_H

namespace greentop {

class HttpCookie {
    public:
        HttpCookie(const std::string &cookieString);

        std::string domain;
        bool tail;
        std::string path;
        bool secure;
        time_t expires;
        std::string name;
        std::string value;

        virtual ~HttpCookie();
    protected:
    private:
};

}
#endif // HTTPCOOKIE_H
