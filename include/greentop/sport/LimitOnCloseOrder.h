/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LIMITONCLOSEORDER_H
#define LIMITONCLOSEORDER_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
/**
 * Place a new LIMIT_ON_CLOSE bet
 */
class LimitOnCloseOrder : public JsonMember {
    public:
        LimitOnCloseOrder();

        LimitOnCloseOrder(const Optional<double>& liability,
            const Optional<double>& price);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getLiability() const;
        void setLiability(const Optional<double>& liability);

        const Optional<double>& getPrice() const;
        void setPrice(const Optional<double>& price);


    private:
        /**
         * The size of the bet.
         */
        Optional<double> liability;
        /**
         * The limit price of the bet if LOC
         */
        Optional<double> price;
};

}

#endif // LIMITONCLOSEORDER_H
