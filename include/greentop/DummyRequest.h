/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef DUMMYREQUEST_H
#define DUMMYREQUEST_H

#include "greentop/JsonRequest.h"

namespace greentop {

/**
 * Some types of betfair API requests don't take any parameters.  DummyRequest is used for these;
 * toString() returns an empty string.
 */
class DummyRequest : public JsonRequest {

    public:

        /**
         * Constructor.
         */
        DummyRequest();

        /**
         * Returns an empty string.
         *
         * @return Empty string.
         */
        virtual std::string toString() const;

    protected:
    private:
        /**
         * Not used.
         */
        virtual void fromJson(const Json::Value& json);
        /**
         * Not used.
         */
        virtual Json::Value toJson() const;
};

}

#endif // DUMMYREQUEST_H
