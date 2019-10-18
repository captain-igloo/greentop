/**
 * Copyright 2019 Colin Doig.  Distributed under the MIT license.
 */
#ifndef CURL_ICURL_H
#define CURL_ICURL_H

#include <curl/curl.h>
#include <memory>

namespace greentop {

typedef size_t writeCallback(char *ptr, size_t size, size_t nmemb, std::ostream* stream);
typedef std::unique_ptr<CURL, void(*)(CURL*)> CurlHandle;

class ICurl {
    public:

        virtual CurlHandle easyInit() const = 0;

        virtual CURLcode easySetopt(
            const CurlHandle& handle,
            const CURLoption& option,
            const char* parameter
        ) const = 0;

        virtual CURLcode easySetopt(
            const CurlHandle& handle,
            const CURLoption& option,
            long parameter
        ) const = 0;

        virtual CURLcode easySetopt(
            const CurlHandle& handle,
            const CURLoption& option,
            const curl_slist* parameter
        ) const = 0;

        virtual CURLcode easySetopt(
            const CurlHandle& handle,
            const CURLoption& option,
            writeCallback parameter
        ) const = 0;

        virtual CURLcode easySetopt(
            const CurlHandle& handle,
            const CURLoption& option,
            const std::stringstream* parameter
        ) const = 0;

        virtual CURLcode easySend(
            const CurlHandle& handle,
            const void* buffer,
            size_t buflen,
            size_t* n
        ) const = 0;

        virtual CURLcode easyRecv(
            const CurlHandle& handle,
            void* buffer,
            size_t buflen,
            size_t* n
        ) const = 0;

        virtual CURLcode easyPerform(const CurlHandle& handle) const = 0;

        virtual CURLcode easyGetinfo(
            const CurlHandle& handle,
            const CURLINFO& info,
            const curl_socket_t* socket
        ) const = 0;

        virtual ~ICurl() {}
};

}

#endif // CURL_ICURL_H
