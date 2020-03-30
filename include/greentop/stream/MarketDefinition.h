/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STREAM_MARKETDEFINITION_H
#define STREAM_MARKETDEFINITION_H

#include <json/json.h>
#include <set>
#include <string>
#include <vector>

#include "greentop/JsonMember.h"
#include "greentop/Optional.h"
#include "greentop/stream/KeyLineDefinition.h"
#include "greentop/stream/PriceLadderDefinition.h"
#include "greentop/stream/RunnerDefinition.h"

namespace greentop {
namespace stream {        

class MarketDefinition : public JsonMember {
    public:

        MarketDefinition(const std::string& venue = std::string(),
            const std::string& raceType = std::string(),
            const std::string& settledTime = std::string(),
            const std::string& timezone = std::string(),
            const Optional<double>& eachWayDivisor = Optional<double>(),
            const std::set<std::string>& regulators = std::set<std::string>(),
            const std::string& marketType = std::string(),
            const Optional<double>& marketBaseRate = Optional<double>(),
            const Optional<int32_t>& numberOfWinners = Optional<int32_t>(),
            const std::string& countryCode = std::string(),
            const Optional<double>& lineMaxUnit = Optional<double>(),
            const Optional<bool>& inPlay = Optional<bool>(),
            const Optional<int32_t>& betDelay = Optional<int32_t>(),
            const Optional<bool>& bspMarket = Optional<bool>(),
            const std::string& bettingType = std::string(),
            const Optional<int32_t>& numberOfActiveRunners = Optional<int32_t>(),
            const Optional<double>& lineMinUnit = Optional<double>(),
            const std::string& eventId = std::string(),
            const Optional<bool>& crossMatching = Optional<bool>(),
            const Optional<bool>& runnersVoidable = Optional<bool>(),
            const Optional<bool>& turnInPlayEnabled = Optional<bool>(),
            const PriceLadderDefinition& priceLadderDefinition = PriceLadderDefinition(),
            const KeyLineDefinition& keyLineDefinition = KeyLineDefinition(),
            const std::string& suspendTime = std::string(),
            const Optional<bool>& discountAllowed = Optional<bool>(),
            const Optional<bool>& persistenceEnabled = Optional<bool>(),
            const std::vector<RunnerDefinition>& runners = std::vector<RunnerDefinition>(),
            const Optional<int64_t>& version = Optional<int64_t>(),
            const std::string& eventTypeId = std::string(),
            const Optional<bool>& complete = Optional<bool>(),
            const std::string& openDate = std::string(),
            const std::string& marketTime = std::string(),
            const Optional<bool>& bspReconciled = Optional<bool>(),
            const Optional<double>& lineInterval = Optional<double>(),
            const std::string& status = std::string());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getVenue() const;
        void setVenue(const std::string& venue);

        const std::string& getRaceType() const;
        void setRaceType(const std::string& raceType);

        const std::string& getSettledTime() const;
        void setSettledTime(const std::string& settledTime);

        const std::string& getTimezone() const;
        void setTimezone(const std::string& timezone);

        const Optional<double>& getEachWayDivisor() const;
        void setEachWayDivisor(const Optional<double>& eachWayDivisor);

        const std::set<std::string>& getRegulators() const;
        void setRegulators(const std::set<std::string>& regulators);

        const std::string& getMarketType() const;
        void setMarketType(const std::string& marketType);

        const Optional<double>& getMarketBaseRate() const;
        void setMarketBaseRate(const Optional<double>& marketBaseRate);

        const Optional<int32_t>& getNumberOfWinners() const;
        void setNumberOfWinners(const Optional<int32_t>& numberOfWinners);

        const std::string& getCountryCode() const;
        void setCountryCode(const std::string& countryCode);

        const Optional<double>& getLineMaxUnit() const;
        void setLineMaxUnit(const Optional<double>& lineMaxUnit);

        const Optional<bool>& getInPlay() const;
        void setInPlay(const Optional<bool>& inPlay);

        const Optional<int32_t>& getBetDelay() const;
        void setBetDelay(const Optional<int32_t>& betDelay);

        const Optional<bool>& getBspMarket() const;
        void setBspMarket(const Optional<bool>& bspMarket);

        const std::string& getBettingType() const;
        void setBettingType(const std::string& bettingType);

        const Optional<int32_t>& getNumberOfActiveRunners() const;
        void setNumberOfActiveRunners(const Optional<int32_t>& numberOfActiveRunners);

        const Optional<double>& getLineMinUnit() const;
        void setLineMinUnit(const Optional<double>& lineMinUnit);

        const std::string& getEventId() const;
        void setEventId(const std::string& eventId);

        const Optional<bool>& getCrossMatching() const;
        void setCrossMatching(const Optional<bool>& crossMatching);

        const Optional<bool>& getRunnersVoidable() const;
        void setRunnersVoidable(const Optional<bool>& runnersVoidable);

        const Optional<bool>& getTurnInPlayEnabled() const;
        void setTurnInPlayEnabled(const Optional<bool>& turnInPlayEnabled);

        const PriceLadderDefinition& getPriceLadderDefinition() const;
        void setPriceLadderDefinition(const PriceLadderDefinition& priceLadderDefinition);

        const KeyLineDefinition& getKeyLineDefinition() const;
        void setKeyLineDefinition(const KeyLineDefinition& keyLineDefinition);

        const std::string& getSuspendTime() const;
        void setSuspendTime(const std::string& suspendTime);

        const Optional<bool>& getDiscountAllowed() const;
        void setDiscountAllowed(const Optional<bool>& discountAllowed);

        const Optional<bool>& getPersistenceEnabled() const;
        void setPersistenceEnabled(const Optional<bool>& persistenceEnabled);

        const std::vector<RunnerDefinition>& getRunners() const;
        void setRunners(const std::vector<RunnerDefinition>& runners);

        const Optional<int64_t>& getVersion() const;
        void setVersion(const Optional<int64_t>& version);

        const std::string& getEventTypeId() const;
        void setEventTypeId(const std::string& eventTypeId);

        const Optional<bool>& getComplete() const;
        void setComplete(const Optional<bool>& complete);

        const std::string& getOpenDate() const;
        void setOpenDate(const std::string& openDate);

        const std::string& getMarketTime() const;
        void setMarketTime(const std::string& marketTime);

        const Optional<bool>& getBspReconciled() const;
        void setBspReconciled(const Optional<bool>& bspReconciled);

        const Optional<double>& getLineInterval() const;
        void setLineInterval(const Optional<double>& lineInterval);

        const std::string& getStatus() const;
        void setStatus(const std::string& status);


    private:

        std::string venue;

        std::string raceType;

        std::string settledTime;

        std::string timezone;

        Optional<double> eachWayDivisor;
        /**
         * The market regulators.
         */
        std::set<std::string> regulators;

        std::string marketType;

        Optional<double> marketBaseRate;

        Optional<int32_t> numberOfWinners;

        std::string countryCode;
        /**
         * For Handicap and Line markets, the maximum value for the outcome, in market units for
         * this market (eg 100 runs).
         */
        Optional<double> lineMaxUnit;

        Optional<bool> inPlay;

        Optional<int32_t> betDelay;

        Optional<bool> bspMarket;

        std::string bettingType;

        Optional<int32_t> numberOfActiveRunners;
        /**
         * For Handicap and Line markets, the minimum value for the outcome, in market units for
         * this market (eg 0 runs).
         */
        Optional<double> lineMinUnit;

        std::string eventId;

        Optional<bool> crossMatching;

        Optional<bool> runnersVoidable;

        Optional<bool> turnInPlayEnabled;
        /**
         * Definition of the price ladder type and any related data.
         */
        PriceLadderDefinition priceLadderDefinition;
        /**
         * Definition of a markets key line selection (for valid markets), comprising the
         * selectionId and handicap of the team it is applied to.
         */
        KeyLineDefinition keyLineDefinition;

        std::string suspendTime;

        Optional<bool> discountAllowed;

        Optional<bool> persistenceEnabled;

        std::vector<RunnerDefinition> runners;

        Optional<int64_t> version;
        /**
         * The Event Type the market is contained within.
         */
        std::string eventTypeId;

        Optional<bool> complete;

        std::string openDate;

        std::string marketTime;

        Optional<bool> bspReconciled;
        /**
         * For Handicap and Line markets, the lines available on this market will be between the
         * range of lineMinUnit and lineMaxUnit, in increments of the lineInterval value. e.g. If
         * unit is runs, lineMinUnit=10, lineMaxUnit=20 and lineInterval=0.5, then valid lines
         * include 10, 10.5, 11, 11.5 up to 20 runs.
         */
        Optional<double> lineInterval;

        std::string status;
};

}
}

#endif // STREAM_MARKETDEFINITION_H
