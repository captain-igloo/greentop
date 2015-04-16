#ifndef CANCELORDERSREQUEST_H
#define CANCELORDERSREQUEST_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonRequest.h"
#include "greentop/betting/CancelInstruction.h"

namespace greentop {

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
        std::string marketId;
        std::vector<CancelInstruction> instructions;
        std::string customerRef;
};

}

#endif // CANCELORDERSREQUEST_H


