#ifndef LISTCOMPETITIONSRESPONSE_H
#define LISTCOMPETITIONSRESPONSE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/betting/CompetitionResult.h"

namespace greentop {

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

#endif // LISTCOMPETITIONSRESPONSE_H


