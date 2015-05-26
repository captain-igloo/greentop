/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/betting/CompetitionResult.h"

namespace greentop {

CompetitionResult::CompetitionResult(const Competition& competition,
    const uint64_t marketCount,
    const std::string& competitionRegion) :
    competition(competition),
    marketCount(marketCount),
    competitionRegion(competitionRegion) {
}

void CompetitionResult::fromJson(const Json::Value& json) {
    if (json.isMember("competition")) {
        competition.fromJson(json["competition"]);
    }
    if (json.isMember("marketCount")) {
        marketCount = json["marketCount"].asUInt64();
    }
    if (json.isMember("competitionRegion")) {
        competitionRegion = json["competitionRegion"].asString();
    }
}

Json::Value CompetitionResult::toJson() const {
    Json::Value json(Json::objectValue);
    if (competition.isValid()) {
        json["competition"] = competition.toJson();
    }
    if (marketCount > 0) {
        json["marketCount"] = marketCount;
    }
    if (competitionRegion != "") {
        json["competitionRegion"] = competitionRegion;
    }
    return json;
}

bool CompetitionResult::isValid() const {
    return true;
}

const Competition& CompetitionResult::getCompetition() const {
    return competition;
}
void CompetitionResult::setCompetition(const Competition& competition) {
    this->competition = competition;
}

const uint64_t CompetitionResult::getMarketCount() const {
    return marketCount;
}
void CompetitionResult::setMarketCount(const uint64_t marketCount) {
    this->marketCount = marketCount;
}

const std::string& CompetitionResult::getCompetitionRegion() const {
    return competitionRegion;
}
void CompetitionResult::setCompetitionRegion(const std::string& competitionRegion) {
    this->competitionRegion = competitionRegion;
}


}



