/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */
#ifndef JSONMEMBER_H
#define JSONMEMBER_H

#include <json/json.h>

#include <string>

namespace greentop {

class JsonMember {

    public:

        /**
         * Constructor.
         */
        JsonMember();

        /**
         * Returns true if all mandatory child members are valid, else false.
         */
        virtual bool isValid() const;

        /**
         * Populate from JSON.
         *
         * @param json The json to populate from.
         */
        virtual void fromJson(const Json::Value& json) = 0;

        /**
         * Convert to JSON.
         *
         * @return A JSON representation of the object.
         */
        virtual Json::Value toJson() const = 0;

        /**
         * Convert to JSON string.
         *
         * @return A JSON representation of the object.
         */
        virtual std::string toString() const;

    protected:
        bool valid;

    private:

};

}

std::ostream& operator<<(std::ostream& os, const greentop::JsonMember& jm);

std::istream& operator>>(std::istream& is, greentop::JsonMember& jm);

#endif // JSONMEMBER_H
