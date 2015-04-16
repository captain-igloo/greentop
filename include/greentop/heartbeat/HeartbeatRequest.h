#ifndef HEARTBEATREQUEST_H
#define HEARTBEATREQUEST_H

#include <json/json.h>

#include "greentop/JsonRequest.h"

namespace greentop {

class HeartbeatRequest : public JsonRequest {
    public:
        HeartbeatRequest();

        HeartbeatRequest(const int preferredTimeoutSeconds);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const int getPreferredTimeoutSeconds() const;
        void setPreferredTimeoutSeconds(const int preferredTimeoutSeconds);


    private:
        int preferredTimeoutSeconds;
};

}

#endif // HEARTBEATREQUEST_H


