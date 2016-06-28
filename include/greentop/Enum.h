/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef ENUM_H
#define ENUM_H

#include <string>

namespace greentop {

/**
 * Base class for betfair enums.
 */
template<class T>
class Enum {
    public:

        /**
         * Gets the enum value.
         *
         * @return The enum value.
         */
        std::string getValue() const {
            return value;
        }

        /**
         * Gets the enum value.
         *
         * @return The enum value.
         */
        operator std::string () const {
            return value;
        }

        /**
         * Less than operator.
         *
         * @param other The other enum to compare.
         * @return True if this enum is less than the other else false.
         */
        virtual bool operator<(const T& other) const = 0;

        /**
         * Equality operator.
         *
         * @param other The other enum to compare.
         * @return True if this enum is equal to the other else false.
         */
        virtual bool operator==(const T& other) const = 0;

        /**
         * Not equal operator.
         *
         * @param other The other enum to compare.
         * @return True if this enum is not equal to the other else false.
         */
        virtual bool operator!=(const T& other) const = 0;

        /**
         * Whether or not a value has been set.
         *
         * @return True if a value has been set else false.
         */
        bool isValid() const {
            return valid;
        }

    protected:
        std::string value;
        bool valid;

};

}

#endif // ENUM_H
