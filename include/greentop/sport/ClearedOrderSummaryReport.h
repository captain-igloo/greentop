/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_CLEAREDORDERSUMMARYREPORT_H
#define SPORT_CLEAREDORDERSUMMARYREPORT_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonResponse.h"
#include "greentop/Optional.h"
#include "greentop/sport/ClearedOrderSummary.h"

namespace greentop {
namespace sport {
/**
 * A container representing search results.
 */
class ClearedOrderSummaryReport : public JsonResponse {
    public:
        ClearedOrderSummaryReport();

        ClearedOrderSummaryReport(const std::vector<ClearedOrderSummary>& clearedOrders,
            const Optional<bool>& moreAvailable);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<ClearedOrderSummary>& getClearedOrders() const;
        void setClearedOrders(const std::vector<ClearedOrderSummary>& clearedOrders);

        const Optional<bool>& getMoreAvailable() const;
        void setMoreAvailable(const Optional<bool>& moreAvailable);


    private:
        /**
         * The list of cleared orders returned by your query. This will be a valid list (i.e. empty
         * or non-empty but never 'null').
         */
        std::vector<ClearedOrderSummary> clearedOrders;
        /**
         * Indicates whether there are further result items beyond this page. Note that underlying
         * data is highly time-dependent and the subsequent search orders query might return an
         * empty result.
         */
        Optional<bool> moreAvailable;
};

}
}

#endif // SPORT_CLEAREDORDERSUMMARYREPORT_H
