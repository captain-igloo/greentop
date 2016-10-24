/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GETAPPLICATIONSUBSCRIPTIONHISTORYREQUEST_H
#define GETAPPLICATIONSUBSCRIPTIONHISTORYREQUEST_H

#include <json/json.h>
#include <string>

#include "greentop/JsonRequest.h"

namespace greentop {

class GetApplicationSubscriptionHistoryRequest : public JsonRequest {
    public:

        GetApplicationSubscriptionHistoryRequest(const std::string& vendorClientId = std::string(),
            const std::string& applicationKey = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getVendorClientId() const;
        void setVendorClientId(const std::string& vendorClientId);

        const std::string& getApplicationKey() const;
        void setApplicationKey(const std::string& applicationKey);


    private:
        /**
         * A vendor client id must be provided if this operation is being called by the application
         * key owner. nb. The presence of an x-application header implies that this operation is
         * being called by the application key owner. A vendor client id will be ignored, if the
         * operation is being called by the client. nb. The absence of an x-application header
         * implies that this operation is being called by the client.
         */
        std::string vendorClientId;
        /**
         * If the operation is called by the client then an applicationKey must be provided as a
         * parameter (as opposed to a x-application header)
         */
        std::string applicationKey;
};

}

#endif // GETAPPLICATIONSUBSCRIPTIONHISTORYREQUEST_H


