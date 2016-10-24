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

/**
 * Describes a version of an external application
 */
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
        /**
         * The sportex user who owns the specific version of the application
         */
        std::string owner;
        /**
         * The unique Id of the application version
         */
        int64_t versionId;
        /**
         * The version identifier string such as 1.0, 2.0. Unique for a given application.
         */
        std::string version;
        /**
         * The unqiue application key associated with this application version
         */
        std::string applicationKey;
        /**
         * Indicates whether the data exposed by platform services as seen by this application key
         * is delayed or realtime.
         */
        Optional<bool> delayData;
        /**
         * Indicates whether the application version needs explicit subscription
         */
        Optional<bool> subscriptionRequired;
        /**
         * Indicates whether the application version needs explicit management by producers. A
         * value of false indicates, this is a version meant for developer use.
         */
        Optional<bool> ownerManaged;
        /**
         * Indicates whether the application version is currently active
         */
        Optional<bool> active;
};

}

#endif // DEVELOPERAPPVERSION_H


