/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LISTEVENTSRESPONSE_H
#define LISTEVENTSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/EventResult.h"

namespace greentop {

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

#endif // LISTEVENTSRESPONSE_H


