/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STREAM_AUTHENTICATIONMESSAGE_H
#define STREAM_AUTHENTICATIONMESSAGE_H

#include <json/json.h>
#include <string>

#include "greentop/stream/RequestMessage.h"
#include "greentop/Optional.h"

namespace greentop {
namespace stream {        

class AuthenticationMessage : public RequestMessage {
    public:

        AuthenticationMessage(const std::string& op = std::string(),
            const Optional<int32_t>& id = Optional<int32_t>(),
            const std::string& session = std::string(),
            const std::string& appKey = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getOp() const;
        void setOp(const std::string& op);

        const Optional<int32_t>& getId() const;
        void setId(const Optional<int32_t>& id);

        const std::string& getSession() const;
        void setSession(const std::string& session);

        const std::string& getAppKey() const;
        void setAppKey(const std::string& appKey);


    private:

        std::string op;

        Optional<int32_t> id;

        std::string session;

        std::string appKey;
};

}
}

#endif // STREAM_AUTHENTICATIONMESSAGE_H
