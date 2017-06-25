/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ListCompetitionsResponse.h"

namespace greentop {

ListCompetitionsResponse::ListCompetitionsResponse() {
}

ListCompetitionsResponse::ListCompetitionsResponse(const std::vector<CompetitionResult>& competitionResults) :
    competitionResults(competitionResults) {
}

void ListCompetitionsResponse::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        for (unsigned i = 0; i < json.size(); ++i) {
            CompetitionResult competitionResult;
            competitionResult.fromJson(json[i]);
            competitionResults.push_back(competitionResult);
        }
    }
}

Json::Value ListCompetitionsResponse::toJson() const {
    Json::Value json(Json::arrayValue);
    if (competitionResults.size() > 0) {
        for (unsigned i = 0; i < competitionResults.size(); ++i) {
            json.append(competitionResults[i].toJson());
        }
    }
    return json;
}

bool ListCompetitionsResponse::isValid() const {
    return competitionResults.size() > 0;
}

const std::vector<CompetitionResult>& ListCompetitionsResponse::getCompetitionResults() const {
    return competitionResults;
}
void ListCompetitionsResponse::setCompetitionResults(const std::vector<CompetitionResult>& competitionResults) {
    this->competitionResults = competitionResults;
}


}



