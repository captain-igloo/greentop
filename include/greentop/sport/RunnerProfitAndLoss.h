/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef RUNNERPROFITANDLOSS_H
#define RUNNERPROFITANDLOSS_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
/**
 * Profit and loss if selection is wins or loses
 */
class RunnerProfitAndLoss : public JsonMember {
    public:

        RunnerProfitAndLoss(const Optional<int64_t>& selectionId = Optional<int64_t>(),
            const Optional<double>& ifWin = Optional<double>(),
            const Optional<double>& ifLose = Optional<double>(),
            const Optional<double>& ifPlace = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int64_t>& getSelectionId() const;
        void setSelectionId(const Optional<int64_t>& selectionId);

        const Optional<double>& getIfWin() const;
        void setIfWin(const Optional<double>& ifWin);

        const Optional<double>& getIfLose() const;
        void setIfLose(const Optional<double>& ifLose);

        const Optional<double>& getIfPlace() const;
        void setIfPlace(const Optional<double>& ifPlace);


    private:
        /**
         * The unique identifier for the selection
         */
        Optional<int64_t> selectionId;
        /**
         * Profit and loss for the market if this selection is the winner
         */
        Optional<double> ifWin;
        /**
         * Profit and loss for the market if this selection is the loser. Only returned for
         * multi-winner odds markets.
         */
        Optional<double> ifLose;
        /**
         * Profit and loss for the market if this selection is placed. Only returned for EACH_WAY
         * markets.
         */
        Optional<double> ifPlace;
};

}

#endif // RUNNERPROFITANDLOSS_H
