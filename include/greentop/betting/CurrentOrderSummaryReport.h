/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CURRENTORDERSUMMARYREPORT_H
#define CURRENTORDERSUMMARYREPORT_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/betting/CurrentOrderSummary.h"

namespace greentop {

class CurrentOrderSummaryReport : public JsonResponse {
    public:
        CurrentOrderSummaryReport();

        CurrentOrderSummaryReport(const std::vector<CurrentOrderSummary>& currentOrders,
            const bool moreAvailable);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<CurrentOrderSummary>& getCurrentOrders() const;
        void setCurrentOrders(const std::vector<CurrentOrderSummary>& currentOrders);

        const bool getMoreAvailable() const;
        void setMoreAvailable(const bool moreAvailable);


    private:
        std::vector<CurrentOrderSummary> currentOrders;
        bool moreAvailable;
};

}

#endif // CURRENTORDERSUMMARYREPORT_H


