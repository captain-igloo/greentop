/**
 * Copyright 2018 Colin Doig.  Distributed under the MIT license.
 */
#include "greentop/curl/Curl.h"

namespace greentop {

Curl::Curl(long flags) {
    curl_global_init(flags);
}

CurlHandle Curl::easyInit() const {
    return CurlHandle(curl_easy_init(), curl_easy_cleanup);
}

CURLcode Curl::easySetopt(const CurlHandle& handle, const CURLoption& option, const char* parameter) const {
    return curl_easy_setopt(handle.get(), option, parameter);
}

CURLcode Curl::easySetopt(const CurlHandle& handle, const CURLoption& option, long parameter) const {
    return curl_easy_setopt(handle.get(), option, parameter);
}

CURLcode Curl::easySetopt(const CurlHandle& handle, const CURLoption& option, const curl_slist* parameter) const {
    return curl_easy_setopt(handle.get(), option, parameter);
}

CURLcode Curl::easySetopt(const CurlHandle& handle, const CURLoption& option, writeCallback parameter) const {
    return curl_easy_setopt(handle.get(), option, parameter);
}

CURLcode Curl::easySetopt(const CurlHandle& handle, const CURLoption& option, const std::stringstream* parameter) const {
    return curl_easy_setopt(handle.get(), option, parameter);
}

CURLcode Curl::easyPerform(const CurlHandle& handle) const {
    return curl_easy_perform(handle.get());
}

Curl::~Curl() {
    curl_global_cleanup();
}

}
