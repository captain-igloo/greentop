/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef HEARTBEATREPORT_H
#define HEARTBEATREPORT_H

#include <json/json.h>

#include "greentop/JsonResponse.h"
#include "greentop/enum/ActionPerformed.h"

namespace greentop {

class HeartbeatReport : public JsonResponse {
    public:

        HeartbeatReport(const ActionPerformed& actionPerformed = ActionPerformed(),
            const int actualTimeoutSeconds = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const ActionPerformed& getActionPerformed() const;
        void setActionPerformed(const ActionPerformed& actionPerformed);

        const int getActualTimeoutSeconds() const;
        void setActualTimeoutSeconds(const int actualTimeoutSeconds);


    private:
        ActionPerformed actionPerformed;
        int actualTimeoutSeconds;
};

}

#endif // HEARTBEATREPORT_H


