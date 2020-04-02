/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_LISTEVENTSRESPONSE_H
#define SPORT_LISTEVENTSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/EventResult.h"

namespace greentop {
namespace sport {

class ListEventsResponse : public JsonResponse {
    public:
        ListEventsResponse();

        ListEventsResponse(const std::vector<EventResult>& eventResults);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<EventResult>& getEventResults() const;
        void setEventResults(const std::vector<EventResult>& eventResults);


    private:

        std::vector<EventResult> eventResults;
};

}
}

#endif // SPORT_LISTEVENTSRESPONSE_H
