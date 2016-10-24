/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CANCELINSTRUCTION_H
#define CANCELINSTRUCTION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

/**
 * Instruction to fully or partially cancel an order (only applies to LIMIT orders)
 */
class CancelInstruction : public JsonMember {
    public:
        CancelInstruction();

        CancelInstruction(const std::string& betId,
            const Optional<double>& sizeReduction = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const Optional<double>& getSizeReduction() const;
        void setSizeReduction(const Optional<double>& sizeReduction);


    private:
        std::string betId;
        /**
         * If supplied then this is a partial cancel
         */
        Optional<double> sizeReduction;
};

}

#endif // CANCELINSTRUCTION_H


