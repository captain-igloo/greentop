/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef RUNNERID_H
#define RUNNERID_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

class RunnerId : public JsonMember {
    public:
        RunnerId();

        RunnerId(const std::string& marketId,
            const uint64_t selectionId,
            const Optional<double>& handicap = Optional<double>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const uint64_t getSelectionId() const;
        void setSelectionId(const uint64_t selectionId);

        const Optional<double>& getHandicap() const;
        void setHandicap(const Optional<double>& handicap);


    private:
        std::string marketId;
        uint64_t selectionId;
        Optional<double> handicap;
};

}

#endif // RUNNERID_H


