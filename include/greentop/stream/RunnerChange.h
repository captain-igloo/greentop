/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef RUNNERCHANGE_H
#define RUNNERCHANGE_H

#include <json/json.h>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"

namespace greentop {
namespace stream {        

class RunnerChange : public JsonMember {
    public:

        RunnerChange(const Optional<double>& tv = Optional<double>(),
            const std::vector<std::vector<double>>& batb = std::vector<std::vector<double>>(),
            const std::vector<std::vector<double>>& spb = std::vector<std::vector<double>>(),
            const std::vector<std::vector<double>>& bdatl = std::vector<std::vector<double>>(),
            const std::vector<std::vector<double>>& trd = std::vector<std::vector<double>>(),
            const Optional<double>& spf = Optional<double>(),
            const Optional<double>& ltp = Optional<double>(),
            const std::vector<std::vector<double>>& atb = std::vector<std::vector<double>>(),
            const std::vector<std::vector<double>>& spl = std::vector<std::vector<double>>(),
            const Optional<double>& spn = Optional<double>(),
            const std::vector<std::vector<double>>& atl = std::vector<std::vector<double>>(),
            const std::vector<std::vector<double>>& batl = std::vector<std::vector<double>>(),
            const Optional<int64_t>& id = Optional<int64_t>(),
            const Optional<double>& hc = Optional<double>(),
            const std::vector<std::vector<double>>& bdatb = std::vector<std::vector<double>>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const Optional<double>& getTv() const;
        void setTv(const Optional<double>& tv);

        const std::vector<std::vector<double>>& getBatb() const;
        void setBatb(const std::vector<std::vector<double>>& batb);

        const std::vector<std::vector<double>>& getSpb() const;
        void setSpb(const std::vector<std::vector<double>>& spb);

        const std::vector<std::vector<double>>& getBdatl() const;
        void setBdatl(const std::vector<std::vector<double>>& bdatl);

        const std::vector<std::vector<double>>& getTrd() const;
        void setTrd(const std::vector<std::vector<double>>& trd);

        const Optional<double>& getSpf() const;
        void setSpf(const Optional<double>& spf);

        const Optional<double>& getLtp() const;
        void setLtp(const Optional<double>& ltp);

        const std::vector<std::vector<double>>& getAtb() const;
        void setAtb(const std::vector<std::vector<double>>& atb);

        const std::vector<std::vector<double>>& getSpl() const;
        void setSpl(const std::vector<std::vector<double>>& spl);

        const Optional<double>& getSpn() const;
        void setSpn(const Optional<double>& spn);

        const std::vector<std::vector<double>>& getAtl() const;
        void setAtl(const std::vector<std::vector<double>>& atl);

        const std::vector<std::vector<double>>& getBatl() const;
        void setBatl(const std::vector<std::vector<double>>& batl);

        const Optional<int64_t>& getId() const;
        void setId(const Optional<int64_t>& id);

        const Optional<double>& getHc() const;
        void setHc(const Optional<double>& hc);

        const std::vector<std::vector<double>>& getBdatb() const;
        void setBdatb(const std::vector<std::vector<double>>& bdatb);


    private:
        /**
         * The total amount matched. This value is truncated at 2dp.
         */
        Optional<double> tv;
        /**
         * Best Available To Back - LevelPriceVol triple delta of price changes, keyed by level (0
         * vol is remove)
         */
        std::vector<std::vector<double>> batb;
        /**
         * Starting Price Back - PriceVol tuple delta of price changes (0 vol is remove)
         */
        std::vector<std::vector<double>> spb;
        /**
         * Best Display Available To Lay (includes virtual prices)- LevelPriceVol triple delta of
         * price changes, keyed by level (0 vol is remove)
         */
        std::vector<std::vector<double>> bdatl;
        /**
         * Traded - PriceVol tuple delta of price changes (0 vol is remove)
         */
        std::vector<std::vector<double>> trd;
        /**
         * Starting Price Far - The far starting price (or null if un-changed)
         */
        Optional<double> spf;
        /**
         * Last Traded Price - The last traded price (or null if un-changed)
         */
        Optional<double> ltp;
        /**
         * Available To Back - PriceVol tuple delta of price changes (0 vol is remove)
         */
        std::vector<std::vector<double>> atb;
        /**
         * Starting Price Lay - PriceVol tuple delta of price changes (0 vol is remove)
         */
        std::vector<std::vector<double>> spl;
        /**
         * Starting Price Near - The far starting price (or null if un-changed)
         */
        Optional<double> spn;
        /**
         * Available To Lay - PriceVol tuple delta of price changes (0 vol is remove)
         */
        std::vector<std::vector<double>> atl;
        /**
         * Best Available To Lay - LevelPriceVol triple delta of price changes, keyed by level (0
         * vol is remove)
         */
        std::vector<std::vector<double>> batl;
        /**
         * Selection Id - the id of the runner (selection)
         */
        Optional<int64_t> id;
        /**
         * Handicap - the handicap of the runner (selection) (null if not applicable)
         */
        Optional<double> hc;
        /**
         * Best Display Available To Back (includes virtual prices)- LevelPriceVol triple delta of
         * price changes, keyed by level (0 vol is remove)
         */
        std::vector<std::vector<double>> bdatb;
};

}
}

#endif // RUNNERCHANGE_H
