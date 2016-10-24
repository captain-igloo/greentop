/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PLACEORDERSREQUEST_H
#define PLACEORDERSREQUEST_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/sport/PlaceInstruction.h"

namespace greentop {

class PlaceOrdersRequest : public JsonRequest {
    public:
        PlaceOrdersRequest();

        PlaceOrdersRequest(const std::string& marketId,
            const std::vector<PlaceInstruction>& instructions,
            const std::string& customerRef = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const std::vector<PlaceInstruction>& getInstructions() const;
        void setInstructions(const std::vector<PlaceInstruction>& instructions);

        const std::string& getCustomerRef() const;
        void setCustomerRef(const std::string& customerRef);


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
};

}

#endif // PLACEORDERSREQUEST_H


