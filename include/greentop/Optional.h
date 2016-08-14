/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */
#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <stdexcept>

#include "greentop/JsonMember.h"

namespace greentop {

/**
 * A wrapper for representing primitive types (bool, integer, double) that can be
 * serialised/unserialised to/from json.
 */
template<typename T>
class Optional : public JsonMember {

    public:

        /**
         * Default constructor.
         */
        Optional() {
            valid = false;
        }

        /**
         * Constructor.
         *
         * @param value The value to serialise as json.
         */
        Optional(T value) : value(value) {
            valid = true;
        }

        /**
         * Converts to Json::Value.
         *
         * @return Json::Value.
         */
        virtual Json::Value toJson() const {
            Json::Value json(value);
            return json;
        }

        /**
         * Returns the value.
         *
         * @return T
         */
        operator T () const {
            return value;
        }

        /**
         * Returns the value if there is one, else throws an exception.
         *
         * @return T
         */
        T getValue() const {
            if (!valid) {
                throw std::runtime_error("Value has not been set");
            }
            return value;
        }

        /**
         * Extract the value from the Json::Value given.
         *
         * @param json The json to extract the value from.
         */
        virtual void fromJson(const Json::Value& json);

    private:
        T value;
};

}

#endif // OPTIONAL_H

