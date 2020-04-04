/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_GETEXPOSUREREUSEENABLEDEVENTSRESPONSE_H
#define SPORT_GETEXPOSUREREUSEENABLEDEVENTSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"

namespace greentop {
namespace sport {

class GetExposureReuseEnabledEventsResponse : public JsonResponse {
    public:
        GetExposureReuseEnabledEventsResponse();

        GetExposureReuseEnabledEventsResponse(const std::vector<int64_t>& response);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<int64_t>& getResponse() const;
        void setResponse(const std::vector<int64_t>& response);


    private:

        std::vector<int64_t> response;
};

}
}

#endif // SPORT_GETEXPOSUREREUSEENABLEDEVENTSRESPONSE_H
