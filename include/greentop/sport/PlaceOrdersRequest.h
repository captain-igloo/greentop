/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_PLACEORDERSREQUEST_H
#define SPORT_PLACEORDERSREQUEST_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"
#include "greentop/sport/MarketVersion.h"
#include "greentop/sport/PlaceInstruction.h"

namespace greentop {
namespace sport {

class PlaceOrdersRequest : public JsonRequest {
    public:
        PlaceOrdersRequest();

        PlaceOrdersRequest(const std::string& marketId,
            const std::vector<PlaceInstruction>& instructions,
            const std::string& customerRef = std::string(),
            const MarketVersion& marketVersion = MarketVersion(),
            const std::string& customerStrategyRef = std::string(),
            const Optional<bool>& async = Optional<bool>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const std::vector<PlaceInstruction>& getInstructions() const;
        void setInstructions(const std::vector<PlaceInstruction>& instructions);

        const std::string& getCustomerRef() const;
        void setCustomerRef(const std::string& customerRef);

        const MarketVersion& getMarketVersion() const;
        void setMarketVersion(const MarketVersion& marketVersion);

        const std::string& getCustomerStrategyRef() const;
        void setCustomerStrategyRef(const std::string& customerStrategyRef);

        const Optional<bool>& getAsync() const;
        void setAsync(const Optional<bool>& async);


    private:
        /**
         * The market id these orders are to be placed on
         */
        std::string marketId;

        std::vector<PlaceInstruction> instructions;
        /**
         * Optional parameter allowing the client to pass a unique string (up to 32 chars) that is
         * used to de-dupe mistaken re-submissions.
         */
        std::string customerRef;
        /**
         * Optional parameter allowing the client to specify which version of the market the orders
         * should be placed on. If the current market version is higher than that sent on an order,
         * the bet will be lapsed. Useful when a customer doesn't want to bet in play and is
         * worried that their bet might arrive after the market has turned in play.
         */
        MarketVersion marketVersion;
        /**
         * An optional reference customers can use to specify which strategy has sent the order.
         * The reference will be returned on order change messages through the stream API. The
         * string is limited to 15 characters. If an empty string is provided it will be treated as
         * null.
         */
        std::string customerStrategyRef;
        /**
         * An optional flag (not setting equates to false) which specifies if the orders should be
         * placed asynchronously. Orders can be tracked via the Exchange Stream API or or the
         * API-NG by providing a customerOrderRef for each place order. An order's status will be
         * PENDING and no bet ID will be returned. This functionality is available for all bet
         * types - including MOC and LOC.
         */
        Optional<bool> async;
};

}
}

#endif // SPORT_PLACEORDERSREQUEST_H
