/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef LIMITBREACHACTION_H
#define LIMITBREACHACTION_H

#include <json/json.h>

#include "greentop/JsonMember.h"
#include "greentop/sport/enum/LimitBreachActionType.h"

namespace greentop {
/**
 * Action that should be execute when limit is breached
 */
class LimitBreachAction : public JsonMember {
    public:
        LimitBreachAction();

        LimitBreachAction(const LimitBreachActionType& actionType);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const LimitBreachActionType& getActionType() const;
        void setActionType(const LimitBreachActionType& actionType);


    private:
        /**
         * Type of the action
         */
        LimitBreachActionType actionType;
};

}

#endif // LIMITBREACHACTION_H
