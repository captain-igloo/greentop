/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef DUMMYREQUEST_H
#define DUMMYREQUEST_H

#include "greentop/JsonRequest.h"

namespace greentop {

class DummyRequest : public JsonRequest {
    public:
        DummyRequest();
        virtual void fromJson(const Json::Value& json);
        virtual Json::Value toJson() const;
        virtual std::string toString() const;

    protected:
    private:
};

}

#endif // DUMMYREQUEST_H
