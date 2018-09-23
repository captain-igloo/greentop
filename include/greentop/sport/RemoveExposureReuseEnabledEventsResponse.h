/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef REMOVEEXPOSUREREUSEENABLEDEVENTSRESPONSE_H
#define REMOVEEXPOSUREREUSEENABLEDEVENTSRESPONSE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonResponse.h"

namespace greentop {

class RemoveExposureReuseEnabledEventsResponse : public JsonResponse {
    public:
        RemoveExposureReuseEnabledEventsResponse();

        RemoveExposureReuseEnabledEventsResponse(const std::string& response);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getResponse() const;
        void setResponse(const std::string& response);


    private:

        std::string response;
};

}

#endif // REMOVEEXPOSUREREUSEENABLEDEVENTSRESPONSE_H
