/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STREAM_RUNNERDEFINITION_H
#define STREAM_RUNNERDEFINITION_H

#include <json/json.h>
#include <string>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace stream {        

class RunnerDefinition : public JsonMember {
    public:

        RunnerDefinition(const Optional<int32_t>& sortPriority = Optional<int32_t>(),
            const std::string& removalDate = std::string(),
            const Optional<int64_t>& id = Optional<int64_t>(),
            const Optional<double>& hc = Optional<double>(),
            const Optional<double>& adjustmentFactor = Optional<double>(),
            const Optional<double>& bsp = Optional<double>(),
            const std::string& status = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<int32_t>& getSortPriority() const;
        void setSortPriority(const Optional<int32_t>& sortPriority);

        const std::string& getRemovalDate() const;
        void setRemovalDate(const std::string& removalDate);

        const Optional<int64_t>& getId() const;
        void setId(const Optional<int64_t>& id);

        const Optional<double>& getHc() const;
        void setHc(const Optional<double>& hc);

        const Optional<double>& getAdjustmentFactor() const;
        void setAdjustmentFactor(const Optional<double>& adjustmentFactor);

        const Optional<double>& getBsp() const;
        void setBsp(const Optional<double>& bsp);

        const std::string& getStatus() const;
        void setStatus(const std::string& status);


    private:

        Optional<int32_t> sortPriority;

        std::string removalDate;
        /**
         * Selection Id - the id of the runner (selection)
         */
        Optional<int64_t> id;
        /**
         * Handicap - the handicap of the runner (selection) (null if not applicable)
         */
        Optional<double> hc;

        Optional<double> adjustmentFactor;

        Optional<double> bsp;

        std::string status;
};

}
}

#endif // STREAM_RUNNERDEFINITION_H
