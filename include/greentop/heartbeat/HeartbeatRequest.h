/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef HEARTBEATREQUEST_H
#define HEARTBEATREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"

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
        int32_t preferredTimeoutSeconds;
};

}

#endif // HEARTBEATREQUEST_H


