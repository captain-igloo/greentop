/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_PRICELADDERDESCRIPTION_H
#define SPORT_PRICELADDERDESCRIPTION_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/sport/enum/PriceLadderType.h"

namespace greentop {
namespace sport {
/**
 * Description of the price ladder type and any related data.
 */
class PriceLadderDescription : public JsonMember {
    public:
        PriceLadderDescription();

        PriceLadderDescription(const PriceLadderType& type);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const PriceLadderType& getType() const;
        void setType(const PriceLadderType& type);


    private:
        /**
         * The type of price ladder.
         */
        PriceLadderType type;
};

}
}

#endif // SPORT_PRICELADDERDESCRIPTION_H
