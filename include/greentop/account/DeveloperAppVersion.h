/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef DEVELOPERAPPVERSION_H
#define DEVELOPERAPPVERSION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

class DeveloperAppVersion : public JsonMember {
    public:
        DeveloperAppVersion();

        DeveloperAppVersion(const std::string& owner,
            const int64_t versionId,
            const std::string& version,
            const std::string& applicationKey,
            const Optional<bool>& delayData = Optional<bool>(),
            const Optional<bool>& subscriptionRequired = Optional<bool>(),
            const Optional<bool>& ownerManaged = Optional<bool>(),
            const Optional<bool>& active = Optional<bool>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getOwner() const;
        void setOwner(const std::string& owner);

        const int64_t getVersionId() const;
        void setVersionId(const int64_t versionId);

        const std::string& getVersion() const;
        void setVersion(const std::string& version);

        const std::string& getApplicationKey() const;
        void setApplicationKey(const std::string& applicationKey);

        const Optional<bool>& getDelayData() const;
        void setDelayData(const Optional<bool>& delayData);

        const Optional<bool>& getSubscriptionRequired() const;
        void setSubscriptionRequired(const Optional<bool>& subscriptionRequired);

        const Optional<bool>& getOwnerManaged() const;
        void setOwnerManaged(const Optional<bool>& ownerManaged);

        const Optional<bool>& getActive() const;
        void setActive(const Optional<bool>& active);


    private:
        std::string owner;
        int64_t versionId;
        std::string version;
        std::string applicationKey;
        Optional<bool> delayData;
        Optional<bool> subscriptionRequired;
        Optional<bool> ownerManaged;
        Optional<bool> active;
};

}

#endif // DEVELOPERAPPVERSION_H


