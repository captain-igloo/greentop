/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef RUNNERPROFITANDLOSS_H
#define RUNNERPROFITANDLOSS_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

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
        Optional<int64_t> selectionId;
        Optional<double> ifWin;
        Optional<double> ifLose;
        Optional<double> ifPlace;
};

}

#endif // RUNNERPROFITANDLOSS_H


