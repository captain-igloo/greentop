/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef HEARTBEATREQUEST_H
#define HEARTBEATREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"

namespace greentop {

class HeartbeatRequest : public JsonRequest {
    public:
        HeartbeatRequest();

        HeartbeatRequest(const int32_t preferredTimeoutSeconds);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const int32_t getPreferredTimeoutSeconds() const;
        void setPreferredTimeoutSeconds(const int32_t preferredTimeoutSeconds);


    private:
        /**
         * Maximum period in seconds that may elapse (without a subsequent heartbeat request),
         * before a cancellation request is automatically submitted on your behalf. Passing 0 will
         * result in your heartbeat being unregistered (or ignored if you have no current heartbeat
         * registered). You will still get an actionPerformed value returned when passing 0, so
         * this may be used to determine if any action was performed since your last heartbeat,
         * without actually registering a new heartbeat. Passing a negative value will result in an
         * error being returned, INVALID_INPUT_DATA. Any errors while registering your heartbeat
         * will result in a error being returned, UNEXPECTED_ERROR. Passing a value that is less
         * than the minimum timeout will result in your heartbeat adopting the minimum timeout.
         * Passing a value that is greater than the maximum timeout will result in your heartbeat
         * adopting the maximum timeout. The minimum and maximum timeouts are subject to change, so
         * your client should utilise the returned actualTimeoutSeconds to set an appropriate
         * frequency for your subsequent heartbeat requests.
         */
        Optional<int32_t> preferredTimeoutSeconds;
};

}

#endif // HEARTBEATREQUEST_H


