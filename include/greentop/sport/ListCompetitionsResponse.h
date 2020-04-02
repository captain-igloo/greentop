/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_LISTCOMPETITIONSRESPONSE_H
#define SPORT_LISTCOMPETITIONSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/sport/CompetitionResult.h"

namespace greentop {
namespace sport {

class ListCompetitionsResponse : public JsonResponse {
    public:
        ListCompetitionsResponse();

        ListCompetitionsResponse(const std::vector<CompetitionResult>& competitionResults);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<CompetitionResult>& getCompetitionResults() const;
        void setCompetitionResults(const std::vector<CompetitionResult>& competitionResults);


    private:

        std::vector<CompetitionResult> competitionResults;
};

}
}

#endif // SPORT_LISTCOMPETITIONSRESPONSE_H
