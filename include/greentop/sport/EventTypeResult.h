/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_EVENTTYPERESULT_H
#define SPORT_EVENTTYPERESULT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/EventType.h"

namespace greentop {
namespace sport {
/**
 * EventType Result
 */
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
        /**
         * EventType
         */
        EventType eventType;
        /**
         * Count of markets associated with this eventType
         */
        Optional<int32_t> marketCount;
};

}
}

#endif // SPORT_EVENTTYPERESULT_H
