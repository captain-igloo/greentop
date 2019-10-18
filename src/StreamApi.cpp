/**
 * Copyright 2019 Colin Doig.  Distributed under the MIT license.
 */
#include <iostream>
#include <json/json.h>
#include <string.h>

#include "greentop/stream/AuthenticationMessage.h"
#include "greentop/stream/MarketChangeMessage.h"
#include "greentop/StreamApi.h"

namespace {

int waitOnSocket(curl_socket_t sockfd, int forRecv, long timeoutMs) {
    struct timeval tv;
    fd_set infd, outfd, errfd;
    int res;

    tv.tv_sec = timeoutMs / 1000;
    tv.tv_usec = (timeoutMs % 1000) * 1000;

    FD_ZERO(&infd);
    FD_ZERO(&outfd);
    FD_ZERO(&errfd);

    FD_SET(sockfd, &errfd); // always check for error

    if (forRecv) {
        FD_SET(sockfd, &infd);
    } else {
        FD_SET(sockfd, &outfd);
    }

    // select() returns the number of signalled sockets or -1
    res = select((int)sockfd + 1, &infd, &outfd, &errfd, &tv);
    return res;
}

}

namespace greentop {

const char* StreamApi::STREAM_API_END_POINT = "https://stream-api.betfair.com";

StreamApi::StreamApi(
    const std::string& appKey,
    std::unique_ptr<ICurl>&& curl
) : appKey(appKey), curl(std::move(curl)), handle(CurlHandle(curl_easy_init(), curl_easy_cleanup)) {

}

bool StreamApi::connect() {
    if (!connected) {
        if (handle.get()) {
            curl->easySetopt(handle, CURLOPT_URL, STREAM_API_END_POINT);
            curl->easySetopt(handle, CURLOPT_CONNECT_ONLY, 1L);
            CURLcode curlResult = curl->easyPerform(handle);
            if (curlResult == CURLE_OK) {
                curlResult = curl->easyGetinfo(handle, CURLINFO_ACTIVESOCKET, &sockfd);
                if (curlResult == CURLE_OK) {
                    connected = true;
                }
            }
        }
    }
    return connected;
}

void StreamApi::authenticate(const std::string& sessionId) {
    if (connect()) {
        stream::AuthenticationMessage request("authentication", 1, sessionId, appKey);
        write(request);
    }
}

void StreamApi::read() {
    CURLcode res;

    std::stringstream response;
    for(;;) {
        char buf[1024];
        size_t nread;
        do {
            nread = 0;
            res = curl->easyRecv(handle, buf, sizeof(buf), &nread);

            if (res == CURLE_AGAIN && !waitOnSocket(sockfd, 1, TIMEOUT)) {
                throw std::runtime_error("Read timeout");
            }
        } while(res == CURLE_AGAIN);

        if (res != CURLE_OK) {
            throw std::runtime_error(curl_easy_strerror(res));
        }

        if (nread == 0) {
            break;
        }

        buf[nread] = 0;
        char end[3];
        if (nread >= 2) {
            strncpy(end, buf + nread - 2, 2);
            end[2] = 0;

            if (strcmp(end, "\r\n") == 0) {
                response << buf;

                parseResponse(response);
                std::stringstream().swap(response);
            } else {
                response << buf;
            }
        }
    }
}

void StreamApi::parseResponse(std::stringstream& response) {
    Json::Value json;
    response >> json;

    if (json.isMember("op") && json["op"] == "mcm") {
        stream::MarketChangeMessage mcm;        
        mcm.fromJson(json);
        notify("mcm", mcm);
    }
}

void StreamApi::write(const RequestMessage& request) {
    if (connected) {
        std::string requestStr = request.toString() + "\r\n";
        const char* req = requestStr.c_str();
        size_t requestLen = strlen(req);
        size_t nsentTotal = 0;
        CURLcode curlResult;
        do {
            size_t nsent;
            do {
                nsent = 0;
                curlResult = curl->easySend(
                    handle,
                    req + nsentTotal,
                    requestLen - nsentTotal,
                    &nsent
                );
                nsentTotal += nsent;

                if (curlResult == CURLE_AGAIN && !waitOnSocket(sockfd, 0, TIMEOUT)) {
                    throw std::runtime_error("Write timeout");
                }
            } while(curlResult == CURLE_AGAIN);

            if (curlResult != CURLE_OK) {
                throw std::runtime_error(curl_easy_strerror(curlResult));
            }
        } while (nsentTotal < requestLen);
    }
}

}
