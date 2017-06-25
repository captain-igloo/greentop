/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef RUNNERID_H
#define RUNNERID_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
/**
 * This object contains the unique identifier for a runner
 */
class RunnerId : public JsonMember {
    public:
        RunnerId();

        RunnerId(const std::string& marketId,
            const Optional<int64_t>& selectionId,
            const Optional<double>& handicap = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const Optional<int64_t>& getSelectionId() const;
        void setSelectionId(const Optional<int64_t>& selectionId);

        const Optional<double>& getHandicap() const;
        void setHandicap(const Optional<double>& handicap);


    private:
        /**
         * The id of the market bet on
         */
        std::string marketId;
        /**
         * The id of the selection bet on
         */
        Optional<int64_t> selectionId;
        /**
         * The handicap associated with the runner in case of asian handicap markets, null
         * otherwise.
         */
        Optional<double> handicap;
};

}

#endif // RUNNERID_H
