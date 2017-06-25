/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef COMPETITIONRESULT_H
#define COMPETITIONRESULT_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/sport/Competition.h"

namespace greentop {
/**
 * Competition Result
 */
class CompetitionResult : public JsonMember {
    public:

        CompetitionResult(const Competition& competition = Competition(),
            const Optional<int32_t>& marketCount = Optional<int32_t>(),
            const std::string& competitionRegion = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Competition& getCompetition() const;
        void setCompetition(const Competition& competition);

        const Optional<int32_t>& getMarketCount() const;
        void setMarketCount(const Optional<int32_t>& marketCount);

        const std::string& getCompetitionRegion() const;
        void setCompetitionRegion(const std::string& competitionRegion);


    private:
        /**
         * Competition
         */
        Competition competition;
        /**
         * Count of markets associated with this competition
         */
        Optional<int32_t> marketCount;
        /**
         * Region in which this competition is happening
         */
        std::string competitionRegion;
};

}

#endif // COMPETITIONRESULT_H
