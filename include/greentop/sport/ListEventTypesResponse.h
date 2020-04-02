/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_LISTEVENTTYPESRESPONSE_H
#define SPORT_LISTEVENTTYPESRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/EventTypeResult.h"

namespace greentop {
namespace sport {

class ListEventTypesResponse : public JsonResponse {
    public:
        ListEventTypesResponse();

        ListEventTypesResponse(const std::vector<EventTypeResult>& eventTypeResults);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<EventTypeResult>& getEventTypeResults() const;
        void setEventTypeResults(const std::vector<EventTypeResult>& eventTypeResults);


    private:

        std::vector<EventTypeResult> eventTypeResults;
};

}
}

#endif // SPORT_LISTEVENTTYPESRESPONSE_H
