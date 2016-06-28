#ifndef OPTIONAL_H
#define OPTIONAL_H

#include "greentop/JsonMember.h"

namespace greentop {

template<typename T>
class Optional : public JsonMember {

    public:
        Optional() {
            valid = false;
        }

        Optional(T value) : value(value) {
            valid = true;
        }

        virtual Json::Value toJson() const {
            Json::Value json(value);
            return json;
        }

        virtual void fromJson(const Json::Value& json);

        operator T () const {
            return value;
        }

    private:
        T value;
};

}

#endif // OPTIONAL_H
