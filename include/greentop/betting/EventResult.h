#ifndef EVENTRESULT_H
#define EVENTRESULT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/betting/Event.h"

namespace greentop {

class EventResult : public JsonMember {
    public:

        EventResult(const Event& event = Event(),
            const int marketCount = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Event& getEvent() const;
        void setEvent(const Event& event);

        const int getMarketCount() const;
        void setMarketCount(const int marketCount);


    private:
        Event event;
        int marketCount;
};

}

#endif // EVENTRESULT_H


