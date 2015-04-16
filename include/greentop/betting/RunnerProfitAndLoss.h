#ifndef RUNNERPROFITANDLOSS_H
#define RUNNERPROFITANDLOSS_H

#include <json/json.h>

#include "greentop/JsonMember.h"

namespace greentop {

class RunnerProfitAndLoss : public JsonMember {
    public:

        RunnerProfitAndLoss(const double selectionId = -1,
            const double ifWin = -1,
            const double ifLose = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const double getSelectionId() const;
        void setSelectionId(const double selectionId);

        const double getIfWin() const;
        void setIfWin(const double ifWin);

        const double getIfLose() const;
        void setIfLose(const double ifLose);


    private:
        double selectionId;
        double ifWin;
        double ifLose;
};

}

#endif // RUNNERPROFITANDLOSS_H


