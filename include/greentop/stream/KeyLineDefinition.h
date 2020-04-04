/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STREAM_KEYLINEDEFINITION_H
#define STREAM_KEYLINEDEFINITION_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/stream/KeyLineSelection.h"

namespace greentop {
namespace stream {        

class KeyLineDefinition : public JsonMember {
    public:

        KeyLineDefinition(const std::vector<KeyLineSelection>& kl = std::vector<KeyLineSelection>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::vector<KeyLineSelection>& getKl() const;
        void setKl(const std::vector<KeyLineSelection>& kl);


    private:

        std::vector<KeyLineSelection> kl;
};

}
}

#endif // STREAM_KEYLINEDEFINITION_H
