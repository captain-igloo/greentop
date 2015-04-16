#include "greentop/DummyRequest.h"

namespace greentop {

DummyRequest::DummyRequest() {
    valid = true;
}

void DummyRequest::fromJson(const Json::Value& json) {
}

Json::Value DummyRequest::toJson() const {
    Json::Value json;
    return json;
}

std::string DummyRequest::toString()  const {
    std::string string;
    return string;
}

}
