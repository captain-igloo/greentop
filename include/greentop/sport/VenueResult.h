/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef VENUERESULT_H
#define VENUERESULT_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

/**
 * Venue Result
 */
class VenueResult : public JsonMember {
    public:

        VenueResult(const std::string& venue = std::string(),
            const Optional<int32_t>& marketCount = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getVenue() const;
        void setVenue(const std::string& venue);

        const Optional<int32_t>& getMarketCount() const;
        void setMarketCount(const Optional<int32_t>& marketCount);


    private:
        /**
         * Venue
         */
        std::string venue;
        /**
         * Count of markets associated with this Venue
         */
        Optional<int32_t> marketCount;
};

}

#endif // VENUERESULT_H


