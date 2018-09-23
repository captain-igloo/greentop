/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ADDEXPOSUREREUSEENABLEDEVENTSREQUEST_H
#define ADDEXPOSUREREUSEENABLEDEVENTSREQUEST_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonRequest.h"

namespace greentop {

class AddExposureReuseEnabledEventsRequest : public JsonRequest {
    public:
        AddExposureReuseEnabledEventsRequest();

        AddExposureReuseEnabledEventsRequest(const std::vector<int64_t>& eventIds);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<int64_t>& getEventIds() const;
        void setEventIds(const std::vector<int64_t>& eventIds);


    private:
        /**
         * List of event ids to remove.
         */
        std::vector<int64_t> eventIds;
};

}

#endif // ADDEXPOSUREREUSEENABLEDEVENTSREQUEST_H
