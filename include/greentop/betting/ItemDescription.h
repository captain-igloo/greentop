/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ITEMDESCRIPTION_H
#define ITEMDESCRIPTION_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

class ItemDescription : public JsonMember {
    public:

        ItemDescription(const std::string& eventTypeDesc = std::string(),
            const std::string& eventDesc = std::string(),
            const std::string& marketDesc = std::string(),
            const std::tm& marketStartTime = std::tm(),
            const std::string& runnerDesc = std::string(),
            const uint64_t numberOfWinners = 0);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getEventTypeDesc() const;
        void setEventTypeDesc(const std::string& eventTypeDesc);

        const std::string& getEventDesc() const;
        void setEventDesc(const std::string& eventDesc);

        const std::string& getMarketDesc() const;
        void setMarketDesc(const std::string& marketDesc);

        const std::tm& getMarketStartTime() const;
        void setMarketStartTime(const std::tm& marketStartTime);

        const std::string& getRunnerDesc() const;
        void setRunnerDesc(const std::string& runnerDesc);

        const uint64_t getNumberOfWinners() const;
        void setNumberOfWinners(const uint64_t numberOfWinners);


    private:
        std::string eventTypeDesc;
        std::string eventDesc;
        std::string marketDesc;
        std::tm marketStartTime;
        std::string runnerDesc;
        uint64_t numberOfWinners;
};

}

#endif // ITEMDESCRIPTION_H


