/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef DEVELOPERAPPVERSION_H
#define DEVELOPERAPPVERSION_H

#include <json/json.h>
#include <string>

#include "greentop/BoolJsonMember.h"
#include "greentop/JsonMember.h"

namespace greentop {

class DeveloperAppVersion : public JsonMember {
    public:
        DeveloperAppVersion();

        DeveloperAppVersion(const std::string& owner,
            const uint64_t versionId,
            const std::string& version,
            const std::string& applicationKey,
            const BoolJsonMember& delayData,
            const BoolJsonMember& subscriptionRequired,
            const BoolJsonMember& ownerManaged,
            const BoolJsonMember& active);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getOwner() const;
        void setOwner(const std::string& owner);

        const uint64_t getVersionId() const;
        void setVersionId(const uint64_t versionId);

        const std::string& getVersion() const;
        void setVersion(const std::string& version);

        const std::string& getApplicationKey() const;
        void setApplicationKey(const std::string& applicationKey);

        const BoolJsonMember& getDelayData() const;
        void setDelayData(const BoolJsonMember& delayData);

        const BoolJsonMember& getSubscriptionRequired() const;
        void setSubscriptionRequired(const BoolJsonMember& subscriptionRequired);

        const BoolJsonMember& getOwnerManaged() const;
        void setOwnerManaged(const BoolJsonMember& ownerManaged);

        const BoolJsonMember& getActive() const;
        void setActive(const BoolJsonMember& active);


    private:
        std::string owner;
        uint64_t versionId;
        std::string version;
        std::string applicationKey;
        BoolJsonMember delayData;
        BoolJsonMember subscriptionRequired;
        BoolJsonMember ownerManaged;
        BoolJsonMember active;
};

}

#endif // DEVELOPERAPPVERSION_H


