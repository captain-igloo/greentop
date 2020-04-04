/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_MARKETGROUP_H
#define SPORT_MARKETGROUP_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/sport/MarketGroupId.h"
#include "greentop/sport/enum/MarketGroupType.h"

namespace greentop {
namespace sport {
/**
 * Represents a market group
 */
class MarketGroup : public JsonMember {
    public:
        MarketGroup();

        MarketGroup(const MarketGroupType& type,
            const MarketGroupId& id);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const MarketGroupType& getType() const;
        void setType(const MarketGroupType& type);

        const MarketGroupId& getId() const;
        void setId(const MarketGroupId& id);


    private:
        /**
         * Type of the group
         */
        MarketGroupType type;
        /**
         * ID of the group
         */
        MarketGroupId id;
};

}
}

#endif // SPORT_MARKETGROUP_H
