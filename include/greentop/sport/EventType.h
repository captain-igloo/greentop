/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef EVENTTYPE_H
#define EVENTTYPE_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

class EventType : public JsonMember {
    public:

        EventType(const std::string& id = std::string(),
            const std::string& name = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getId() const;
        void setId(const std::string& id);

        const std::string& getName() const;
        void setName(const std::string& name);


    private:
        std::string id;
        std::string name;
};

}

#endif // EVENTTYPE_H


