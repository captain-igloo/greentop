#include "greentop/betting/ItemDescription.h"

namespace greentop {

ItemDescription::ItemDescription(const std::string& eventTypeDesc,
    const std::string& eventDesc,
    const std::string& marketDesc,
    const std::tm& marketStartTime,
    const std::string& runnerDesc,
    const uint64_t numberOfWinners) :
    eventTypeDesc(eventTypeDesc),
    eventDesc(eventDesc),
    marketDesc(marketDesc),
    marketStartTime(marketStartTime),
    runnerDesc(runnerDesc),
    numberOfWinners(numberOfWinners) {
}

void ItemDescription::fromJson(const Json::Value& json) {
    if (json.isMember("eventTypeDesc")) {
        eventTypeDesc = json["eventTypeDesc"].asString();
    }
    if (json.isMember("eventDesc")) {
        eventDesc = json["eventDesc"].asString();
    }
    if (json.isMember("marketDesc")) {
        marketDesc = json["marketDesc"].asString();
    }
    if (json.isMember("marketStartTime")) {
        strptime(json["marketStartTime"].asString().c_str(), "%Y-%m-%dT%H:%M:%S.000Z", &marketStartTime);
    }
    if (json.isMember("runnerDesc")) {
        runnerDesc = json["runnerDesc"].asString();
    }
    if (json.isMember("numberOfWinners")) {
        numberOfWinners = json["numberOfWinners"].asUInt();
    }
}

Json::Value ItemDescription::toJson() const {
    Json::Value json;
    if (eventTypeDesc != "") {
        json["eventTypeDesc"] = eventTypeDesc;
    }
    if (eventDesc != "") {
        json["eventDesc"] = eventDesc;
    }
    if (marketDesc != "") {
        json["marketDesc"] = marketDesc;
    }
    if (false) {
        // marketStartTime not implemented;
    }
    if (runnerDesc != "") {
        json["runnerDesc"] = runnerDesc;
    }
    if (numberOfWinners >= 0) {
        json["numberOfWinners"] = numberOfWinners;
    }
    return json;
}

bool ItemDescription::isValid() const {
    return true;
}

const std::string& ItemDescription::getEventTypeDesc() const {
    return eventTypeDesc;
}
void ItemDescription::setEventTypeDesc(const std::string& eventTypeDesc) {
    this->eventTypeDesc = eventTypeDesc;
}

const std::string& ItemDescription::getEventDesc() const {
    return eventDesc;
}
void ItemDescription::setEventDesc(const std::string& eventDesc) {
    this->eventDesc = eventDesc;
}

const std::string& ItemDescription::getMarketDesc() const {
    return marketDesc;
}
void ItemDescription::setMarketDesc(const std::string& marketDesc) {
    this->marketDesc = marketDesc;
}

const std::tm& ItemDescription::getMarketStartTime() const {
    return marketStartTime;
}
void ItemDescription::setMarketStartTime(const std::tm& marketStartTime) {
    this->marketStartTime = marketStartTime;
}

const std::string& ItemDescription::getRunnerDesc() const {
    return runnerDesc;
}
void ItemDescription::setRunnerDesc(const std::string& runnerDesc) {
    this->runnerDesc = runnerDesc;
}

const uint64_t ItemDescription::getNumberOfWinners() const {
    return numberOfWinners;
}
void ItemDescription::setNumberOfWinners(const uint64_t numberOfWinners) {
    this->numberOfWinners = numberOfWinners;
}


}



