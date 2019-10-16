/**
 * Copyright 2019 Colin Doig.  Distributed under the MIT license.
 */
#ifndef STREAMAPI_H
#define STREAMAPI_H

#include <curl/curl.h>
#include <memory>
#include <string>

#include "greentop/curl/Curl.h"
#include "greentop/curl/ICurl.h"
#include "greentop/stream/Observable.h"
#include "greentop/stream/RequestMessage.h"
#include "greentop/stream/ResponseMessage.h"

namespace greentop {

class StreamApi : public stream::Observable {

    public:
        /** The stream api end point */
        static const char* STREAM_API_END_POINT;
        /** Socket timeout (ms) */
        static const uint32_t TIMEOUT = 60000;

        /**
         * Constructor. 
         * 
         * @param appKey The user's application key.
         * @param curl A wrapper around libcurl.
         */
        StreamApi(
            const std::string& appKey = "",
            std::unique_ptr<ICurl>&& curl = std::unique_ptr<Curl>(new Curl())
        );

        /**
         * Connect to the socket.
         *
         * @return True on success else false. 
         */
        bool connect();

        /**
         * Send authentication message.
         *
         * @param sessionId The session id.
         */
        void authenticate(const std::string& sessionId);

        /**
         * Read messages from the socket.  This will continue reading in a loop until an error
         * occurs.
         */
        void read();

        /**
         * Writes a message to the socket.
         */
        void write(const RequestMessage& request);

    private:
        /** The application key. */
        std::string appKey;
        /** Curl wrapper. */
        std::unique_ptr<ICurl> curl;
        /** Whether or not we are connected. */
        bool connected = false;
        /** Socket file descriptor. */
        curl_socket_t sockfd;
        /** Curl handle */
        CurlHandle handle;

        /**
         * Parse response message and notify observers.
         *
         * @param response The response message to parse.
         */
        void parseResponse(std::stringstream& response);
};

}

#endif // STREAMAPI_H
