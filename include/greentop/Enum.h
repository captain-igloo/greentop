#ifndef ENUM_H
#define ENUM_H

#include <string>

namespace greentop {

template<class T>
class Enum {
    public:

        std::string getValue() const {
            return value;
        }

        operator std::string () const {
            return value;
        }

        virtual bool operator<(const T& other) const = 0;

        virtual bool operator==(const T& other) const = 0;

        bool isValid() const {
            return valid;
        }

    protected:
        std::string value;
        bool valid;

};

}

#endif // ENUM_H
