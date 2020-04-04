/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef SPORT_RUNNERCATALOG_H
#define SPORT_RUNNERCATALOG_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace sport {
/**
 * Information about the Runners (selections) in a market
 */
class RunnerCatalog : public JsonMember {
    public:
        RunnerCatalog();

        RunnerCatalog(const Optional<int64_t>& selectionId,
            const std::string& runnerName,
            const Optional<double>& handicap,
            const Optional<int32_t>& sortPriority,
            const std::map<std::string, std::string> metadata = std::map<std::string, std::string>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int64_t>& getSelectionId() const;
        void setSelectionId(const Optional<int64_t>& selectionId);

        const std::string& getRunnerName() const;
        void setRunnerName(const std::string& runnerName);

        const Optional<double>& getHandicap() const;
        void setHandicap(const Optional<double>& handicap);

        const Optional<int32_t>& getSortPriority() const;
        void setSortPriority(const Optional<int32_t>& sortPriority);

        const std::map<std::string, std::string>& getMetadata() const;
        void setMetadata(const std::map<std::string, std::string>& metadata);


    private:
        /**
         * The unique id for the selection.
         */
        Optional<int64_t> selectionId;
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
}

#endif // SPORT_RUNNERCATALOG_H
