/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETONCLOSEORDER_H
#define MARKETONCLOSEORDER_H

#include <json/json.h>

#include "greentop/JsonMember.h"

namespace greentop {

class MarketOnCloseOrder : public JsonMember {
    public:
        MarketOnCloseOrder();

        MarketOnCloseOrder(const double liability);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const double getLiability() const;
        void setLiability(const double liability);


    private:
        double liability;
};

}

#endif // MARKETONCLOSEORDER_H


