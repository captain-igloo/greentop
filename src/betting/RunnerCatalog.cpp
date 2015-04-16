#include "greentop/betting/RunnerCatalog.h"

namespace greentop {
RunnerCatalog::RunnerCatalog()  : selectionId(0), handicap(-1), sortPriority(-1){
}

RunnerCatalog::RunnerCatalog(const uint64_t selectionId,
    const std::string& runnerName,
    const double handicap,
    const int sortPriority) :
    selectionId(selectionId),
    runnerName(runnerName),
    handicap(handicap),
    sortPriority(sortPriority) {
}

void RunnerCatalog::fromJson(const Json::Value& json) {
    if (json.isMember("selectionId")) {
        selectionId = json["selectionId"].asUInt();
    }
    if (json.isMember("runnerName")) {
        runnerName = json["runnerName"].asString();
    }
    if (json.isMember("handicap")) {
        handicap = json["handicap"].asDouble();
    }
    if (json.isMember("sortPriority")) {
        sortPriority = json["sortPriority"].asInt();
    }
}

Json::Value RunnerCatalog::toJson() const {
    Json::Value json;
    if (selectionId >= 0) {
        json["selectionId"] = selectionId;
    }
    if (runnerName != "") {
        json["runnerName"] = runnerName;
    }
    if (handicap >= 0) {
        json["handicap"] = handicap;
    }
    if (sortPriority >= 0) {
        json["sortPriority"] = sortPriority;
    }
    return json;
}

bool RunnerCatalog::isValid() const {
    return selectionId >= 0 && runnerName != "" && handicap >= 0 && sortPriority >= 0;
}

const uint64_t RunnerCatalog::getSelectionId() const {
    return selectionId;
}
void RunnerCatalog::setSelectionId(const uint64_t selectionId) {
    this->selectionId = selectionId;
}

const std::string& RunnerCatalog::getRunnerName() const {
    return runnerName;
}
void RunnerCatalog::setRunnerName(const std::string& runnerName) {
    this->runnerName = runnerName;
}

const double RunnerCatalog::getHandicap() const {
    return handicap;
}
void RunnerCatalog::setHandicap(const double handicap) {
    this->handicap = handicap;
}

const int RunnerCatalog::getSortPriority() const {
    return sortPriority;
}
void RunnerCatalog::setSortPriority(const int sortPriority) {
    this->sortPriority = sortPriority;
}


}



