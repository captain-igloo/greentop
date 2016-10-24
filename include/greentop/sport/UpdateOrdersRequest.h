/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef UPDATEORDERSREQUEST_H
#define UPDATEORDERSREQUEST_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/sport/UpdateInstruction.h"

namespace greentop {

class UpdateOrdersRequest : public JsonRequest {
    public:
        UpdateOrdersRequest();

        UpdateOrdersRequest(const std::string& marketId,
            const std::vector<UpdateInstruction>& instructions,
            const std::string& customerRef = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const std::vector<UpdateInstruction>& getInstructions() const;
        void setInstructions(const std::vector<UpdateInstruction>& instructions);

        const std::string& getCustomerRef() const;
        void setCustomerRef(const std::string& customerRef);


    private:
        /**
         * The market id these orders are to be placed on
         */
        std::string marketId;
        std::vector<UpdateInstruction> instructions;
        /**
         * Optional parameter allowing the client to pass a unique string (up to 32 chars) that is
         * used to de-dupe mistaken re-submissions.
         */
        std::string customerRef;
};

}

#endif // UPDATEORDERSREQUEST_H


