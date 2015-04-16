#ifndef RUNNERID_H
#define RUNNERID_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

class RunnerId : public JsonMember {
    public:
        RunnerId();

        RunnerId(const std::string& marketId,
            const std::string& selectionId,
            const double handicap = -1);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getMarketId() const;
        void setMarketId(const std::string& marketId);

        const std::string& getSelectionId() const;
        void setSelectionId(const std::string& selectionId);

        const double getHandicap() const;
        void setHandicap(const double handicap);


    private:
        std::string marketId;
        std::string selectionId;
        double handicap;
};

}

#endif // RUNNERID_H


