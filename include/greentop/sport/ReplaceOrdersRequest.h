/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_REPLACEORDERSREQUEST_H
#define SPORT_REPLACEORDERSREQUEST_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/Optional.h"
#include "greentop/sport/MarketVersion.h"
#include "greentop/sport/ReplaceInstruction.h"

namespace greentop {
namespace sport {

class ReplaceOrdersRequest : public JsonRequest {
    public:
        ReplaceOrdersRequest();

        ReplaceOrdersRequest(const std::string& marketId,
            const std::vector<ReplaceInstruction>& instructions,
            const std::string& customerRef = std::string(),
            const MarketVersion& marketVersion = MarketVersion(),
            const Optional<bool>& async = Optional<bool>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const std::vector<ReplaceInstruction>& getInstructions() const;
        void setInstructions(const std::vector<ReplaceInstruction>& instructions);

        const std::string& getCustomerRef() const;
        void setCustomerRef(const std::string& customerRef);

        const MarketVersion& getMarketVersion() const;
        void setMarketVersion(const MarketVersion& marketVersion);

        const Optional<bool>& getAsync() const;
        void setAsync(const Optional<bool>& async);


    private:
        /**
         * The market id these orders are to be placed on
         */
        std::string marketId;

        std::vector<ReplaceInstruction> instructions;
        /**
         * Optional parameter allowing the client to pass a unique string (up to 32 chars) that is
         * used to de-dupe mistaken re-submissions.
         */
        std::string customerRef;
        /**
         * Optional parameter allowing the client to specify which version of the market the orders
         * should be placed on. Useful when a customer doesn't want to bet in play and is worried
         * that their bet might arrive after the market has turned in play.
         */
        MarketVersion marketVersion;
        /**
         * An optional flag (not setting equates to false) which specifies if the orders should be
         * replaced asynchronously. Orders can be tracked via the Exchange Stream API or the API-NG
         * by providing a customerOrderRef for each replace order. Not available for MOC or LOC
         * bets.
         */
        Optional<bool> async;
};

}
}

#endif // SPORT_REPLACEORDERSREQUEST_H
