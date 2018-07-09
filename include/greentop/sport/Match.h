/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
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
/**
 * An individual bet Match, or rollup by price or avg price. Rollup depends on the requested
 * MatchProjection
 */
class Match : public JsonMember {
    public:

        Match(const std::string& betId = std::string(),
            const std::string& matchId = std::string(),
            const Side& side = Side(),
            const Optional<double>& price = Optional<double>(),
            const Optional<double>& size = Optional<double>(),
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
        void setSize(const Optional<double>& size);

        const std::tm& getMatchDate() const;
        void setMatchDate(const std::tm& matchDate);


    private:
        /**
         * Only present if no rollup
         */
        std::string betId;
        /**
         * Only present if no rollup
         */
        std::string matchId;

        Side side;
        /**
         * Either actual match price or avg match price depending on rollup. This value is not
         * meaningful for activity on LINE markets and is not guaranteed to be returned or
         * maintained for these markets.
         */
        Optional<double> price;
        /**
         * Size matched at in this fragment, or at this price or avg price depending on rollup
         */
        Optional<double> size;
        /**
         * Only present if no rollup
         */
        std::tm matchDate;
};

}

#endif // MATCH_H
