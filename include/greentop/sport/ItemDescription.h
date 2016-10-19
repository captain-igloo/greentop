/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ITEMDESCRIPTION_H
#define ITEMDESCRIPTION_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"

namespace greentop {

class ItemDescription : public JsonMember {
    public:

        ItemDescription(const std::string& eventTypeDesc = std::string(),
            const std::string& eventDesc = std::string(),
            const std::string& marketDesc = std::string(),
            const std::string& marketType = std::string(),
            const std::tm& marketStartTime = std::tm(),
            const std::string& runnerDesc = std::string(),
            const Optional<int32_t>& numberOfWinners = Optional<int32_t>(),
            const Optional<double>& eachWayDivisor = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getEventTypeDesc() const;
        void setEventTypeDesc(const std::string& eventTypeDesc);

        const std::string& getEventDesc() const;
        void setEventDesc(const std::string& eventDesc);

        const std::string& getMarketDesc() const;
        void setMarketDesc(const std::string& marketDesc);

        const std::string& getMarketType() const;
        void setMarketType(const std::string& marketType);

        const std::tm& getMarketStartTime() const;
        void setMarketStartTime(const std::tm& marketStartTime);

        const std::string& getRunnerDesc() const;
        void setRunnerDesc(const std::string& runnerDesc);

        const Optional<int32_t>& getNumberOfWinners() const;
        void setNumberOfWinners(const Optional<int32_t>& numberOfWinners);

        const Optional<double>& getEachWayDivisor() const;
        void setEachWayDivisor(const Optional<double>& eachWayDivisor);


    private:
        std::string eventTypeDesc;
        std::string eventDesc;
        std::string marketDesc;
        std::string marketType;
        std::tm marketStartTime;
        std::string runnerDesc;
        Optional<int32_t> numberOfWinners;
        Optional<double> eachWayDivisor;
};

}

#endif // ITEMDESCRIPTION_H


