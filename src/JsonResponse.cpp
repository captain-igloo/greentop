#include "greentop/JsonResponse.h"

namespace greentop {

JsonResponse::JsonResponse() : success(false) {
}

bool JsonResponse::isSuccess() {
    return success;
}

std::string& JsonResponse::getFaultCode() {
    return faultCode;
}

std::string& JsonResponse::getFaultString() {
    return faultString;
}

bool JsonResponse::validateJson(const Json::Value& json) {

    success = true;

    if (json.isObject() && json.isMember("faultcode")) {
        faultCode = json["faultcode"].asString();
        if (json.isMember("faultstring")) {
            faultString = json["faultstring"].asString();
        }
        success = false;
    }

    return success;
}

}
