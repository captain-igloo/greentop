/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CANCELINSTRUCTION_H
#define CANCELINSTRUCTION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

class CancelInstruction : public JsonMember {
    public:
        CancelInstruction();

        CancelInstruction(const std::string& betId,
            const double sizeReduction = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const double getSizeReduction() const;
        void setSizeReduction(const double sizeReduction);


    private:
        std::string betId;
        double sizeReduction;
};

}

#endif // CANCELINSTRUCTION_H


