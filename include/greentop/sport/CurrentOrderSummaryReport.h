/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef CURRENTORDERSUMMARYREPORT_H
#define CURRENTORDERSUMMARYREPORT_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"
#include "greentop/sport/CurrentOrderSummary.h"

namespace greentop {

/**
 * A container representing search results.
 */
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
        /**
         * The list of current orders returned by your query. This will be a valid list (i.e. empty
         * or non-empty but never 'null').
         */
        std::vector<CurrentOrderSummary> currentOrders;
        /**
         * Indicates whether there are further result items beyond this page. Note that underlying
         * data is highly time-dependent and the subsequent search orders query might return an
         * empty result.
         */
        Optional<bool> moreAvailable;
};

}

#endif // CURRENTORDERSUMMARYREPORT_H


