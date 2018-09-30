/**
 * Copyright 2018 Colin Doig.  Distributed under the MIT license.
 */
#ifndef CURL_CURL_H
#define CURL_CURL_H

#include <curl/curl.h>
#include <memory>
#include <sstream>

#include "greentop/curl/ICurl.h"

namespace greentop {

class Curl : public ICurl {
    public:
        Curl(long flags = CURL_GLOBAL_ALL);

        virtual CurlHandle easyInit() const;

        virtual CURLcode easySetopt(
            const CurlHandle& handle,
            const CURLoption& option,
            const char* parameter
        ) const;

        virtual CURLcode easySetopt(
            const CurlHandle& handle,
            const CURLoption& option,
            long parameter
        ) const;

        virtual CURLcode easySetopt(
            const CurlHandle& handle,
            const CURLoption& option,
            const curl_slist* parameter
        ) const;

        virtual CURLcode easySetopt(
            const CurlHandle& handle,
            const CURLoption& option,
            writeCallback parameter
        ) const;

        virtual CURLcode easySetopt(
            const CurlHandle& handle,
            const CURLoption& option,
            const std::stringstream* parameter
        ) const;

        virtual CURLcode easyPerform(const CurlHandle& handle) const;

        virtual ~Curl();
    private:
        // no copying
        Curl(const Curl&);
        Curl& operator=(const Curl&);
};

}

#endif // CURL_CURL_H
