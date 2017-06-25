/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef REPLACEINSTRUCTION_H
#define REPLACEINSTRUCTION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
/**
 * Instruction to replace a LIMIT or LIMIT_ON_CLOSE order at a new price. Original order will be
 * cancelled and a new order placed at the new price for the remaining stake.
 */
class ReplaceInstruction : public JsonMember {
    public:
        ReplaceInstruction();

        ReplaceInstruction(const std::string& betId,
            const Optional<double>& newPrice);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const Optional<double>& getNewPrice() const;
        void setNewPrice(const Optional<double>& newPrice);


    private:

        std::string betId;
        /**
         * The price to replace the bet at
         */
        Optional<double> newPrice;
};

}

#endif // REPLACEINSTRUCTION_H
