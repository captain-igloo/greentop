/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MATCH_H
#define MATCH_H

#include <ctime>
#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/Time.h"
#include "greentop/sport/enum/Side.h"

namespace greentop {

class Match : public JsonMember {
    public:

        Match(const std::string& betId = std::string(),
            const std::string& matchId = std::string(),
            const Side& side = Side(),
            const Optional<double>& price = Optional<double>(),
            const Optional<double>& Size = Optional<double>(),
            const std::tm& matchDate = std::tm());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getBetId() const;
        void setBetId(const std::string& betId);

        const std::string& getMatchId() const;
        void setMatchId(const std::string& matchId);

        const Side& getSide() const;
        void setSide(const Side& side);

        const Optional<double>& getPrice() const;
        void setPrice(const Optional<double>& price);

        const Optional<double>& getSize() const;
        void setSize(const Optional<double>& Size);

        const std::tm& getMatchDate() const;
        void setMatchDate(const std::tm& matchDate);


    private:
        std::string betId;
        std::string matchId;
        Side side;
        Optional<double> price;
        Optional<double> Size;
        std::tm matchDate;
};

}

#endif // MATCH_H


