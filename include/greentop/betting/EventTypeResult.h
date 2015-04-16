#ifndef EVENTTYPERESULT_H
#define EVENTTYPERESULT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/betting/EventType.h"

namespace greentop {

class EventTypeResult : public JsonMember {
    public:

        EventTypeResult(const EventType& eventType = EventType(),
            const uint64_t marketCount = 0);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const EventType& getEventType() const;
        void setEventType(const EventType& eventType);

        const uint64_t getMarketCount() const;
        void setMarketCount(const uint64_t marketCount);


    private:
        EventType eventType;
        uint64_t marketCount;
};

}

#endif // EVENTTYPERESULT_H


