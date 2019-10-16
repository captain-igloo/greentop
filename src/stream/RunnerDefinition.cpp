/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/RunnerDefinition.h"

namespace greentop {
namespace stream {


RunnerDefinition::RunnerDefinition(const Optional<int32_t>& sortPriority,
    const std::string& removalDate,
    const Optional<int64_t>& id,
    const Optional<double>& hc,
    const Optional<double>& adjustmentFactor,
    const Optional<double>& bsp,
    const std::string& status) :
    sortPriority(sortPriority),
    removalDate(removalDate),
    id(id),
    hc(hc),
    adjustmentFactor(adjustmentFactor),
    bsp(bsp),
    status(status) {
}

void RunnerDefinition::fromJson(const Json::Value& json) {
    if (json.isMember("sortPriority")) {
        sortPriority = json["sortPriority"].asInt();
    }
    if (json.isMember("removalDate")) {
        removalDate = json["removalDate"].asString();
    }
    if (json.isMember("id")) {
        id = json["id"].asInt64();
    }
    if (json.isMember("hc")) {
        hc = json["hc"].asDouble();
    }
    if (json.isMember("adjustmentFactor")) {
        adjustmentFactor = json["adjustmentFactor"].asDouble();
    }
    if (json.isMember("bsp")) {
        bsp = json["bsp"].asDouble();
    }
    if (json.isMember("status")) {
        status = json["status"].asString();
    }
}

Json::Value RunnerDefinition::toJson() const {
    Json::Value json(Json::objectValue);
    if (sortPriority.isValid()) {
        json["sortPriority"] = sortPriority.toJson();
    }
    if (removalDate != "") {
        json["removalDate"] = removalDate;
    }
    if (id.isValid()) {
        json["id"] = id.toJson();
    }
    if (hc.isValid()) {
        json["hc"] = hc.toJson();
    }
    if (adjustmentFactor.isValid()) {
        json["adjustmentFactor"] = adjustmentFactor.toJson();
    }
    if (bsp.isValid()) {
        json["bsp"] = bsp.toJson();
    }
    if (status != "") {
        json["status"] = status;
    }
    return json;
}

bool RunnerDefinition::isValid() const {
    return true;
}

const Optional<int32_t>& RunnerDefinition::getSortPriority() const {
    return sortPriority;
}
void RunnerDefinition::setSortPriority(const Optional<int32_t>& sortPriority) {
    this->sortPriority = sortPriority;
}

const std::string& RunnerDefinition::getRemovalDate() const {
    return removalDate;
}
void RunnerDefinition::setRemovalDate(const std::string& removalDate) {
    this->removalDate = removalDate;
}

const Optional<int64_t>& RunnerDefinition::getId() const {
    return id;
}
void RunnerDefinition::setId(const Optional<int64_t>& id) {
    this->id = id;
}

const Optional<double>& RunnerDefinition::getHc() const {
    return hc;
}
void RunnerDefinition::setHc(const Optional<double>& hc) {
    this->hc = hc;
}

const Optional<double>& RunnerDefinition::getAdjustmentFactor() const {
    return adjustmentFactor;
}
void RunnerDefinition::setAdjustmentFactor(const Optional<double>& adjustmentFactor) {
    this->adjustmentFactor = adjustmentFactor;
}

const Optional<double>& RunnerDefinition::getBsp() const {
    return bsp;
}
void RunnerDefinition::setBsp(const Optional<double>& bsp) {
    this->bsp = bsp;
}

const std::string& RunnerDefinition::getStatus() const {
    return status;
}
void RunnerDefinition::setStatus(const std::string& status) {
    this->status = status;
}


}
}
