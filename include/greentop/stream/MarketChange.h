/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STREAM_MARKETCHANGE_H
#define STREAM_MARKETCHANGE_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/stream/MarketDefinition.h"
#include "greentop/stream/RunnerChange.h"

namespace greentop {
namespace stream {        

class MarketChange : public JsonMember {
    public:

        MarketChange(const std::vector<RunnerChange>& rc = std::vector<RunnerChange>(),
            const Optional<bool>& img = Optional<bool>(),
            const Optional<double>& tv = Optional<double>(),
            const Optional<bool>& con = Optional<bool>(),
            const MarketDefinition& marketDefinition = MarketDefinition(),
            const std::string& id = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<RunnerChange>& getRc() const;
        void setRc(const std::vector<RunnerChange>& rc);

        const Optional<bool>& getImg() const;
        void setImg(const Optional<bool>& img);

        const Optional<double>& getTv() const;
        void setTv(const Optional<double>& tv);

        const Optional<bool>& getCon() const;
        void setCon(const Optional<bool>& con);

        const MarketDefinition& getMarketDefinition() const;
        void setMarketDefinition(const MarketDefinition& marketDefinition);

        const std::string& getId() const;
        void setId(const std::string& id);


    private:
        /**
         * Runner Changes - a list of changes to runners (or null if un-changed)
         */
        std::vector<RunnerChange> rc;
        /**
         * Image - replace existing prices / data with the data supplied: it is not a delta (or
         * null if delta)
         */
        Optional<bool> img;
        /**
         * The total amount matched across the market. This value is truncated at 2dp (or null if
         * un-changed)
         */
        Optional<double> tv;
        /**
         * Conflated - have more than a single change been combined (or null if not conflated)
         */
        Optional<bool> con;
        /**
         * Market Definition - the definition of the market (or null if un-changed)
         */
        MarketDefinition marketDefinition;
        /**
         * Market Id - the id of the market
         */
        std::string id;
};

}
}

#endif // STREAM_MARKETCHANGE_H
