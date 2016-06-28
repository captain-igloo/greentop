/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef RUNNERPROFITANDLOSS_H
#define RUNNERPROFITANDLOSS_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

class RunnerProfitAndLoss : public JsonMember {
    public:

        RunnerProfitAndLoss(const uint64_t selectionId = 0,
            const Optional<double>& ifWin = Optional<double>(),
            const Optional<double>& ifLose = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const uint64_t getSelectionId() const;
        void setSelectionId(const uint64_t selectionId);

        const Optional<double>& getIfWin() const;
        void setIfWin(const Optional<double>& ifWin);

        const Optional<double>& getIfLose() const;
        void setIfLose(const Optional<double>& ifLose);


    private:
        uint64_t selectionId;
        Optional<double> ifWin;
        Optional<double> ifLose;
};

}

#endif // RUNNERPROFITANDLOSS_H


