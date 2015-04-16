#ifndef RUNNERCATALOG_H
#define RUNNERCATALOG_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"

namespace greentop {

class RunnerCatalog : public JsonMember {
    public:
        RunnerCatalog();

        RunnerCatalog(const uint64_t selectionId,
            const std::string& runnerName,
            const double handicap,
            const int sortPriority);

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const uint64_t getSelectionId() const;
        void setSelectionId(const uint64_t selectionId);

        const std::string& getRunnerName() const;
        void setRunnerName(const std::string& runnerName);

        const double getHandicap() const;
        void setHandicap(const double handicap);

        const int getSortPriority() const;
        void setSortPriority(const int sortPriority);


    private:
        uint64_t selectionId;
        std::string runnerName;
        double handicap;
        int sortPriority;
};

}

#endif // RUNNERCATALOG_H


