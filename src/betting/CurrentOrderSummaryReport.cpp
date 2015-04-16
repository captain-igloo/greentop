#include "greentop/betting/CurrentOrderSummaryReport.h"

namespace greentop {
CurrentOrderSummaryReport::CurrentOrderSummaryReport() {
}

CurrentOrderSummaryReport::CurrentOrderSummaryReport(const std::vector<CurrentOrderSummary>& currentOrders,
    const BoolJsonMember& moreAvailable) :
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
            };
        }
        if (json.isMember("moreAvailable")) {
            moreAvailable.fromJson(json["moreAvailable"]);
        }
    }
}

Json::Value CurrentOrderSummaryReport::toJson() const {
    Json::Value json;
    if (currentOrders.size() > 0) {
        for (unsigned i = 0; i < currentOrders.size(); ++i) {
            json["currentOrders"].append(currentOrders[i].toJson());
        };
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

const BoolJsonMember& CurrentOrderSummaryReport::getMoreAvailable() const {
    return moreAvailable;
}
void CurrentOrderSummaryReport::setMoreAvailable(const BoolJsonMember& moreAvailable) {
    this->moreAvailable = moreAvailable;
}


}



