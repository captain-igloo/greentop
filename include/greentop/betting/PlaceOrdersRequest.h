/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PLACEORDERSREQUEST_H
#define PLACEORDERSREQUEST_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/betting/PlaceInstruction.h"

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
        std::string marketId;
        std::vector<PlaceInstruction> instructions;
        std::string customerRef;
};

}

#endif // PLACEORDERSREQUEST_H


