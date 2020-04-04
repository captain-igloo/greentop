/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STREAM_PRICELADDERDEFINITION_H
#define STREAM_PRICELADDERDEFINITION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {
namespace stream {        

class PriceLadderDefinition : public JsonMember {
    public:

        PriceLadderDefinition(const std::string& type = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getType() const;
        void setType(const std::string& type);


    private:

        std::string type;
};

}
}

#endif // STREAM_PRICELADDERDEFINITION_H
