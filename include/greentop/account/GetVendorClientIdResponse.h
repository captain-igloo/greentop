/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef GETVENDORCLIENTIDRESPONSE_H
#define GETVENDORCLIENTIDRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {

class GetVendorClientIdResponse : public JsonResponse {
    public:
        GetVendorClientIdResponse();

        GetVendorClientIdResponse(const std::string& vendorClientId);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getVendorClientId() const;
        void setVendorClientId(const std::string& vendorClientId);


    private:
        std::string vendorClientId;
};

}

#endif // GETVENDORCLIENTIDRESPONSE_H


