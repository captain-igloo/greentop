/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EVENTRESULT_H
#define EVENTRESULT_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/Event.h"

namespace greentop {

class EventResult : public JsonMember {
    public:

        EventResult(const Event& event = Event(),
            const Optional<int32_t>& marketCount = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Event& getEvent() const;
        void setEvent(const Event& event);

        const Optional<int32_t>& getMarketCount() const;
        void setMarketCount(const Optional<int32_t>& marketCount);


    private:
        Event event;
        Optional<int32_t> marketCount;
};

}

#endif // EVENTRESULT_H


