/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_CANCELORDERSREQUEST_H
#define SPORT_CANCELORDERSREQUEST_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/sport/CancelInstruction.h"

namespace greentop {
namespace sport {

class CancelOrdersRequest : public JsonRequest {
    public:

        CancelOrdersRequest(const std::string& marketId = std::string(),
            const std::vector<CancelInstruction>& instructions = std::vector<CancelInstruction>(),
            const std::string& customerRef = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const std::vector<CancelInstruction>& getInstructions() const;
        void setInstructions(const std::vector<CancelInstruction>& instructions);

        const std::string& getCustomerRef() const;
        void setCustomerRef(const std::string& customerRef);


    private:
        /**
         * If not supplied all bets are cancelled
         */
        std::string marketId;
        /**
         * All instructions need to be on the same market. If not supplied all bets on the market
         * (if market id is passed) are fully cancelled
         */
        std::vector<CancelInstruction> instructions;
        /**
         * Optional parameter allowing the client to pass a unique string (upto 32 chars) that is
         * used to de-dupe mistaken re-submitions.
         */
        std::string customerRef;
};

}
}

#endif // SPORT_CANCELORDERSREQUEST_H
