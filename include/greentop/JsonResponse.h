/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef JSONRESPONSE_H
#define JSONRESPONSE_H

#include <string>

#include "JsonMember.h"

namespace greentop {

class JsonResponse : public JsonMember {
    public:
        JsonResponse();

        bool isSuccess();

        std::string& getFaultCode();

        std::string& getFaultString();


    protected:

        bool success;

        bool validateJson(const Json::Value& json);

    private:
        std::string faultCode;
        std::string faultString;

};

}

#endif // JSONRESPONSE_H
