/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CLEAREDORDERSUMMARYREPORT_H
#define CLEAREDORDERSUMMARYREPORT_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/betting/ClearedOrderSummary.h"

namespace greentop {

class ClearedOrderSummaryReport : public JsonResponse {
    public:
        ClearedOrderSummaryReport();

        ClearedOrderSummaryReport(const std::vector<ClearedOrderSummary>& clearedOrders,
            const bool moreAvailable);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<ClearedOrderSummary>& getClearedOrders() const;
        void setClearedOrders(const std::vector<ClearedOrderSummary>& clearedOrders);

        const bool getMoreAvailable() const;
        void setMoreAvailable(const bool moreAvailable);


    private:
        std::vector<ClearedOrderSummary> clearedOrders;
        bool moreAvailable;
};

}

#endif // CLEAREDORDERSUMMARYREPORT_H


