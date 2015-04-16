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
        std::string vendorClientId;
        std::string applicationKey;
};

}

#endif // GETAPPLICATIONSUBSCRIPTIONHISTORYREQUEST_H


