/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETVERSION_H
#define MARKETVERSION_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

/**
 * Market version
 */
class MarketVersion : public JsonMember {
    public:

        MarketVersion(const Optional<int64_t>& version = Optional<int64_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int64_t>& getVersion() const;
        void setVersion(const Optional<int64_t>& version);


    private:
        /**
         * A non-monotonically increasing number indicating market changes
         */
        Optional<int64_t> version;
};

}

#endif // MARKETVERSION_H


