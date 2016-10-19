/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef REPLACEINSTRUCTION_H
#define REPLACEINSTRUCTION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

class ReplaceInstruction : public JsonMember {
    public:
        ReplaceInstruction();

        ReplaceInstruction(const std::string& betId,
            const double newPrice);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const double getNewPrice() const;
        void setNewPrice(const double newPrice);


    private:
        std::string betId;
        double newPrice;
};

}

#endif // REPLACEINSTRUCTION_H


