/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_SETDEFAULTEXPOSURELIMITFORMARKETGROUPSRESPONSE_H
#define SPORT_SETDEFAULTEXPOSURELIMITFORMARKETGROUPSRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {
namespace sport {

class SetDefaultExposureLimitForMarketGroupsResponse : public JsonResponse {
    public:
        SetDefaultExposureLimitForMarketGroupsResponse();

        SetDefaultExposureLimitForMarketGroupsResponse(const std::string& response);

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

#endif // SPORT_SETDEFAULTEXPOSURELIMITFORMARKETGROUPSRESPONSE_H
