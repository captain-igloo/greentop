/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef HEARTBEATREPORT_H
#define HEARTBEATREPORT_H

#include <json/json.h>

#include "greentop/JsonResponse.h"
#include "greentop/heartbeat/enum/ActionPerformed.h"

namespace greentop {

/**
 * Response from heartbeat operation
 */
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
        /**
         * The action performed since your last heartbeat request.
         */
        ActionPerformed actionPerformed;
        /**
         * The actual timeout applied to your heartbeat request, see timeout request parameter
         * description for details.
         */
        int32_t actualTimeoutSeconds;
};

}

#endif // HEARTBEATREPORT_H


