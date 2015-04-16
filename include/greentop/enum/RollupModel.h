#ifndef ROLLUPMODEL_H
#define ROLLUPMODEL_H

#include <stdexcept>
#include <string>

#include "greentop/Enum.h"

namespace greentop {

class RollupModel : public Enum<RollupModel> {

    public:

        static const std::string STAKE;
        static const std::string PAYOUT;
        static const std::string MANAGED_LIABILITY;
        static const std::string NONE;

        RollupModel();

        RollupModel(const std::string& v);

        bool operator<(const RollupModel& other) const;

        bool operator==(const RollupModel& other) const;
};

}

#endif // ROLLUPMODEL_H
