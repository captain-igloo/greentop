/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LIMITONCLOSEORDER_H
#define LIMITONCLOSEORDER_H

#include <json/json.h>

#include "greentop/JsonMember.h"

namespace greentop {

/**
 * Place a new LIMIT_ON_CLOSE bet
 */
class LimitOnCloseOrder : public JsonMember {
    public:
        LimitOnCloseOrder();

        LimitOnCloseOrder(const double liability,
            const double price);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const double getLiability() const;
        void setLiability(const double liability);

        const double getPrice() const;
        void setPrice(const double price);


    private:
        /**
         * The size of the bet.
         */
        double liability;
        /**
         * The limit price of the bet if LOC
         */
        double price;
};

}

#endif // LIMITONCLOSEORDER_H


