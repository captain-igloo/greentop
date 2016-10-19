/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EVENTTYPERESULT_H
#define EVENTTYPERESULT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/EventType.h"

namespace greentop {

class EventTypeResult : public JsonMember {
    public:

        EventTypeResult(const EventType& eventType = EventType(),
            const Optional<int32_t>& marketCount = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const EventType& getEventType() const;
        void setEventType(const EventType& eventType);

        const Optional<int32_t>& getMarketCount() const;
        void setMarketCount(const Optional<int32_t>& marketCount);


    private:
        EventType eventType;
        Optional<int32_t> marketCount;
};

}

#endif // EVENTTYPERESULT_H


