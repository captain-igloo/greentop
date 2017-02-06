/**
 * Copyright 2016 Colin Doig.  Distributed under the MIT license.
 */

#ifndef RUNNERCATALOG_H
#define RUNNERCATALOG_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {

/**
 * Information about the Runners (selections) in a market
 */
class RunnerCatalog : public JsonMember {
    public:
        RunnerCatalog();

        RunnerCatalog(const int64_t selectionId,
            const std::string& runnerName,
            const double handicap,
            const int32_t sortPriority,
            const std::map<std::string, std::string> metadata = std::map<std::string, std::string>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const int64_t getSelectionId() const;
        void setSelectionId(const int64_t selectionId);

        const std::string& getRunnerName() const;
        void setRunnerName(const std::string& runnerName);

        const double getHandicap() const;
        void setHandicap(const double handicap);

        const int32_t getSortPriority() const;
        void setSortPriority(const int32_t sortPriority);

        const std::map<std::string, std::string>& getMetadata() const;
        void setMetadata(const std::map<std::string, std::string>& metadata);


    private:
        /**
         * The unique id for the selection.
         */
        int64_t selectionId;
        /**
         * The name of the runner
         */
        std::string runnerName;
        /**
         * The handicap
         */
        Optional<double> handicap;
        /**
         * The sort priority of this runner
         */
        Optional<int32_t> sortPriority;
        /**
         * Metadata associated with the runner
         */
        std::map<std::string, std::string> metadata;
};

}

#endif // RUNNERCATALOG_H


