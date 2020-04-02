/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/sport/ClearedOrderSummaryReport.h"

namespace greentop {
namespace sport {

ClearedOrderSummaryReport::ClearedOrderSummaryReport() {
}

ClearedOrderSummaryReport::ClearedOrderSummaryReport(const std::vector<ClearedOrderSummary>& clearedOrders,
    const Optional<bool>& moreAvailable) :
    clearedOrders(clearedOrders),
    moreAvailable(moreAvailable) {
}

void ClearedOrderSummaryReport::fromJson(const Json::Value& json) {
    if (validateJson(json)) {
        if (json.isMember("clearedOrders")) {
            for (unsigned i = 0; i < json["clearedOrders"].size(); ++i) {
                ClearedOrderSummary clearedOrder;
                clearedOrder.fromJson(json["clearedOrders"][i]);
                clearedOrders.push_back(clearedOrder);
            }
        }
        if (json.isMember("moreAvailable")) {
            moreAvailable = json["moreAvailable"].asBool();
        }
    }
}

Json::Value ClearedOrderSummaryReport::toJson() const {
    Json::Value json(Json::objectValue);
    if (clearedOrders.size() > 0) {
        for (unsigned i = 0; i < clearedOrders.size(); ++i) {
            json["clearedOrders"].append(clearedOrders[i].toJson());
        }
    }
    if (moreAvailable.isValid()) {
        json["moreAvailable"] = moreAvailable.toJson();
    }
    return json;
}

bool ClearedOrderSummaryReport::isValid() const {
    return clearedOrders.size() > 0 && moreAvailable.isValid();
}

const std::vector<ClearedOrderSummary>& ClearedOrderSummaryReport::getClearedOrders() const {
    return clearedOrders;
}
void ClearedOrderSummaryReport::setClearedOrders(const std::vector<ClearedOrderSummary>& clearedOrders) {
    this->clearedOrders = clearedOrders;
}

const Optional<bool>& ClearedOrderSummaryReport::getMoreAvailable() const {
    return moreAvailable;
}
void ClearedOrderSummaryReport::setMoreAvailable(const Optional<bool>& moreAvailable) {
    this->moreAvailable = moreAvailable;
}


}
}
