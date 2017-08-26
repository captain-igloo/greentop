/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/CurrentOrderSummaryReport.h"

namespace greentop {

CurrentOrderSummaryReport::CurrentOrderSummaryReport() {
}

CurrentOrderSummaryReport::CurrentOrderSummaryReport(const std::vector<CurrentOrderSummary>& currentOrders,
    const Optional<bool>& moreAvailable) :
    currentOrders(currentOrders),
    moreAvailable(moreAvailable) {
}

void CurrentOrderSummaryReport::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("currentOrders")) {
            for (unsigned i = 0; i < json["currentOrders"].size(); ++i) {
                CurrentOrderSummary currentOrder;
                currentOrder.fromJson(json["currentOrders"][i]);
                currentOrders.push_back(currentOrder);
            }
        }
        if (json.isMember("moreAvailable")) {
            moreAvailable = json["moreAvailable"].asBool();
        }
    }
}

Json::Value CurrentOrderSummaryReport::toJson() const {
    Json::Value json(Json::objectValue);
    if (currentOrders.size() > 0) {
        for (unsigned i = 0; i < currentOrders.size(); ++i) {
            json["currentOrders"].append(currentOrders[i].toJson());
        }
    }
    if (moreAvailable.isValid()) {
        json["moreAvailable"] = moreAvailable.toJson();
    }
    return json;
}

bool CurrentOrderSummaryReport::isValid() const {
    return currentOrders.size() > 0 && moreAvailable.isValid();
}

const std::vector<CurrentOrderSummary>& CurrentOrderSummaryReport::getCurrentOrders() const {
    return currentOrders;
}
void CurrentOrderSummaryReport::setCurrentOrders(const std::vector<CurrentOrderSummary>& currentOrders) {
    this->currentOrders = currentOrders;
}

const Optional<bool>& CurrentOrderSummaryReport::getMoreAvailable() const {
    return moreAvailable;
}
void CurrentOrderSummaryReport::setMoreAvailable(const Optional<bool>& moreAvailable) {
    this->moreAvailable = moreAvailable;
}


}



