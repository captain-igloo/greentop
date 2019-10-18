/**
 * Copyright 2019 Colin Doig.  Distributed under the MIT license.
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

CURLcode Curl::easySend(const CurlHandle& handle, const void* buffer, size_t buflen, size_t* n) const {
    return curl_easy_send(handle.get(), buffer, buflen, n);
}

CURLcode Curl::easyRecv(const CurlHandle& handle, void* buffer, size_t buflen, size_t* n) const {
    return curl_easy_recv(handle.get(), buffer, buflen, n);
}

CURLcode Curl::easyPerform(const CurlHandle& handle) const {
    return curl_easy_perform(handle.get());
}

CURLcode Curl::easyGetinfo(const CurlHandle& handle, const CURLINFO& info, const curl_socket_t* socket) const {
    return curl_easy_getinfo(handle.get(), info, socket);
}

Curl::~Curl() {
    curl_global_cleanup();
}

}
