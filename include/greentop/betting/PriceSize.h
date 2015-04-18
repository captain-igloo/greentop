/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef PRICESIZE_H
#define PRICESIZE_H

#include <json/json.h>

#include "greentop/JsonMember.h"

namespace greentop {

class PriceSize : public JsonMember {
    public:
        PriceSize();

        PriceSize(const double price,
            const double size);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const double getPrice() const;
        void setPrice(const double price);

        const double getSize() const;
        void setSize(const double size);


    private:
        double price;
        double size;
};

}

#endif // PRICESIZE_H


