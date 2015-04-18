/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef BOOLJSONMEMBER_H
#define BOOLJSONMEMBER_H

#include <json/json.h>

#include "JsonMember.h"

namespace greentop {

class BoolJsonMember : public JsonMember {
    public:
        BoolJsonMember();

        BoolJsonMember(bool value);

        void fromJson(const Json::Value& json);

        Json::Value toJson() const;

    private:
        bool value;
};

}

#endif // BOOLJSONMEMBER_H
