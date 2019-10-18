/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/AuthenticationMessage.h"

namespace greentop {
namespace stream {


AuthenticationMessage::AuthenticationMessage(const std::string& op,
    const Optional<int32_t>& id,
    const std::string& session,
    const std::string& appKey) :
    op(op),
    id(id),
    session(session),
    appKey(appKey) {
}

void AuthenticationMessage::fromJson(const Json::Value& json) {
    if (json.isMember("op")) {
        op = json["op"].asString();
    }
    if (json.isMember("id")) {
        id = json["id"].asInt();
    }
    if (json.isMember("session")) {
        session = json["session"].asString();
    }
    if (json.isMember("appKey")) {
        appKey = json["appKey"].asString();
    }
}

Json::Value AuthenticationMessage::toJson() const {
    Json::Value json(Json::objectValue);
    if (op != "") {
        json["op"] = op;
    }
    if (id.isValid()) {
        json["id"] = id.toJson();
    }
    if (session != "") {
        json["session"] = session;
    }
    if (appKey != "") {
        json["appKey"] = appKey;
    }
    return json;
}

bool AuthenticationMessage::isValid() const {
    return true;
}

const std::string& AuthenticationMessage::getOp() const {
    return op;
}
void AuthenticationMessage::setOp(const std::string& op) {
    this->op = op;
}

const Optional<int32_t>& AuthenticationMessage::getId() const {
    return id;
}
void AuthenticationMessage::setId(const Optional<int32_t>& id) {
    this->id = id;
}

const std::string& AuthenticationMessage::getSession() const {
    return session;
}
void AuthenticationMessage::setSession(const std::string& session) {
    this->session = session;
}

const std::string& AuthenticationMessage::getAppKey() const {
    return appKey;
}
void AuthenticationMessage::setAppKey(const std::string& appKey) {
    this->appKey = appKey;
}


}
}
