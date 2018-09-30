/**
 * Copyright 2018 Colin Doig.  Distributed under the MIT license.
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

        virtual CURLcode easyPerform(const CurlHandle& handle) const = 0;

        virtual ~ICurl() {}
};

}

#endif // CURL_ICURL_H

