/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MATCHES_H
#define MATCHES_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/sport/Match.h"

namespace greentop {
/**
 * Match list.
 */
class Matches : public JsonMember {
    public:

        Matches(const std::vector<Match>& matches = std::vector<Match>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<Match>& getMatches() const;
        void setMatches(const std::vector<Match>& matches);


    private:
        /**
         * List of matches
         */
        std::vector<Match> matches;
};

}

#endif // MATCHES_H
