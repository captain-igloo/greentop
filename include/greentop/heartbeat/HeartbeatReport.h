/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef HEARTBEATREPORT_H
#define HEARTBEATREPORT_H

#include <json/json.h>

#include "greentop/JsonResponse.h"
#include "greentop/heartbeat/enum/ActionPerformed.h"

namespace greentop {

class HeartbeatReport : public JsonResponse {
    public:
        HeartbeatReport();

        HeartbeatReport(const ActionPerformed& actionPerformed,
            const int32_t actualTimeoutSeconds);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const ActionPerformed& getActionPerformed() const;
        void setActionPerformed(const ActionPerformed& actionPerformed);

        const int32_t getActualTimeoutSeconds() const;
        void setActualTimeoutSeconds(const int32_t actualTimeoutSeconds);


    private:
        ActionPerformed actionPerformed;
        int32_t actualTimeoutSeconds;
};

}

#endif // HEARTBEATREPORT_H


