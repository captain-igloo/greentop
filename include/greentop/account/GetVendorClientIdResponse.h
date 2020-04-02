/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ACCOUNT_GETVENDORCLIENTIDRESPONSE_H
#define ACCOUNT_GETVENDORCLIENTIDRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {
namespace account {

class GetVendorClientIdResponse : public JsonResponse {
    public:
        GetVendorClientIdResponse();

        GetVendorClientIdResponse(const std::string& response);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getResponse() const;
        void setResponse(const std::string& response);


    private:

        std::string response;
};

}
}

#endif // ACCOUNT_GETVENDORCLIENTIDRESPONSE_H
