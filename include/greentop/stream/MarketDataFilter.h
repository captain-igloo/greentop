/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETDATAFILTER_H
#define MARKETDATAFILTER_H

#include <json/json.h>
#include <set>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace stream {        

class MarketDataFilter : public JsonMember {
    public:

        MarketDataFilter(const Optional<int32_t>& ladderLevels = Optional<int32_t>(),
            const std::set<std::string>& fields = std::set<std::string>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int32_t>& getLadderLevels() const;
        void setLadderLevels(const Optional<int32_t>& ladderLevels);

        const std::set<std::string>& getFields() const;
        void setFields(const std::set<std::string>& fields);


    private:

        Optional<int32_t> ladderLevels;

        std::set<std::string> fields;
};

}
}

#endif // MARKETDATAFILTER_H
