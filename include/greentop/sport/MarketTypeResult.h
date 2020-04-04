/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_MARKETTYPERESULT_H
#define SPORT_MARKETTYPERESULT_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace sport {
/**
 * MarketType Result
 */
class MarketTypeResult : public JsonMember {
    public:

        MarketTypeResult(const std::string& marketType = std::string(),
            const Optional<int32_t>& marketCount = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketType() const;
        void setMarketType(const std::string& marketType);

        const Optional<int32_t>& getMarketCount() const;
        void setMarketCount(const Optional<int32_t>& marketCount);


    private:
        /**
         * Market Type
         */
        std::string marketType;
        /**
         * Count of markets associated with this marketType
         */
        Optional<int32_t> marketCount;
};

}
}

#endif // SPORT_MARKETTYPERESULT_H
