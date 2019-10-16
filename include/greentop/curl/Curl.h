/**
 * Copyright 2019 Colin Doig.  Distributed under the MIT license.
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

        virtual CURLcode easySend(
            const CurlHandle& handle,
            const void* buffer,
            size_t buflen,
            size_t* n
        ) const;

        virtual CURLcode easyRecv(
            const CurlHandle& handle,
            void* buffer,
            size_t buflen,
            size_t* n
        ) const;

        virtual CURLcode easyPerform(const CurlHandle& handle) const;

        virtual CURLcode easyGetinfo(
            const CurlHandle& handle,
            const CURLINFO& info,
            const curl_socket_t* socket
        ) const;

        virtual ~Curl();
    private:
        // no copying
        Curl(const Curl&);
        Curl& operator=(const Curl&);
};

}

#endif // CURL_CURL_H
