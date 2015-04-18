/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef COMPETITIONRESULT_H
#define COMPETITIONRESULT_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/betting/Competition.h"

namespace greentop {

class CompetitionResult : public JsonMember {
    public:

        CompetitionResult(const Competition& competition = Competition(),
            const uint64_t marketCount = 0,
            const std::string& competitionRegion = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Competition& getCompetition() const;
        void setCompetition(const Competition& competition);

        const uint64_t getMarketCount() const;
        void setMarketCount(const uint64_t marketCount);

        const std::string& getCompetitionRegion() const;
        void setCompetitionRegion(const std::string& competitionRegion);


    private:
        Competition competition;
        uint64_t marketCount;
        std::string competitionRegion;
};

}

#endif // COMPETITIONRESULT_H


