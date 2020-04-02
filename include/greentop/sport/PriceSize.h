/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_PRICESIZE_H
#define SPORT_PRICESIZE_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace sport {

class PriceSize : public JsonMember {
    public:
        PriceSize();

        PriceSize(const Optional<double>& price,
            const Optional<double>& size);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getPrice() const;
        void setPrice(const Optional<double>& price);

        const Optional<double>& getSize() const;
        void setSize(const Optional<double>& size);


    private:

        Optional<double> price;

        Optional<double> size;
};

}
}

#endif // SPORT_PRICESIZE_H
