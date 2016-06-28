/**
 * Copyright 2015 Colin Doig.  Distributed under the MIT license.
 */

#ifndef DEVELOPERAPPVERSION_H
#define DEVELOPERAPPVERSION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

class DeveloperAppVersion : public JsonMember {
    public:
        DeveloperAppVersion();

        DeveloperAppVersion(const std::string& owner,
            const uint64_t versionId,
            const std::string& version,
            const std::string& applicationKey,
            const bool delayData,
            const bool subscriptionRequired,
            const bool ownerManaged,
            const bool active);

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

        const bool getDelayData() const;
        void setDelayData(const bool delayData);

        const bool getSubscriptionRequired() const;
        void setSubscriptionRequired(const bool subscriptionRequired);

        const bool getOwnerManaged() const;
        void setOwnerManaged(const bool ownerManaged);

        const bool getActive() const;
        void setActive(const bool active);


    private:
        std::string owner;
        uint64_t versionId;
        std::string version;
        std::string applicationKey;
        bool delayData;
        bool subscriptionRequired;
        bool ownerManaged;
        bool active;
};

}

#endif // DEVELOPERAPPVERSION_H


