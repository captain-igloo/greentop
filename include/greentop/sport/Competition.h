/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef COMPETITION_H
#define COMPETITION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

/**
 * Competition
 */
class Competition : public JsonMember {
    public:

        Competition(const std::string& id = std::string(),
            const std::string& name = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getId() const;
        void setId(const std::string& id);

        const std::string& getName() const;
        void setName(const std::string& name);


    private:
        /**
         * id
         */
        std::string id;
        /**
         * name
         */
        std::string name;
};

}

#endif // COMPETITION_H


