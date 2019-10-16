/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef MARKETSUBSCRIPTIONMESSAGE_H
#define MARKETSUBSCRIPTIONMESSAGE_H

#include <json/json.h>
#include <string>

#include "greentop/Optional.h"
#include "greentop/stream/MarketDataFilter.h"
#include "greentop/stream/MarketFilter.h"
#include "greentop/stream/RequestMessage.h"

namespace greentop {
namespace stream {        

class MarketSubscriptionMessage : public RequestMessage {
    public:

        MarketSubscriptionMessage(const std::string& op = std::string(),
            const Optional<int32_t>& id = Optional<int32_t>(),
            const Optional<bool>& segmentationEnabled = Optional<bool>(),
            const std::string& clk = std::string(),
            const Optional<int64_t>& heartbeatMs = Optional<int64_t>(),
            const std::string& initialClk = std::string(),
            const MarketFilter& marketFilter = MarketFilter(),
            const Optional<int64_t>& conflateMs = Optional<int64_t>(),
            const MarketDataFilter& marketDataFilter = MarketDataFilter());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getOp() const;
        void setOp(const std::string& op);

        const Optional<int32_t>& getId() const;
        void setId(const Optional<int32_t>& id);

        const Optional<bool>& getSegmentationEnabled() const;
        void setSegmentationEnabled(const Optional<bool>& segmentationEnabled);

        const std::string& getClk() const;
        void setClk(const std::string& clk);

        const Optional<int64_t>& getHeartbeatMs() const;
        void setHeartbeatMs(const Optional<int64_t>& heartbeatMs);

        const std::string& getInitialClk() const;
        void setInitialClk(const std::string& initialClk);

        const MarketFilter& getMarketFilter() const;
        void setMarketFilter(const MarketFilter& marketFilter);

        const Optional<int64_t>& getConflateMs() const;
        void setConflateMs(const Optional<int64_t>& conflateMs);

        const MarketDataFilter& getMarketDataFilter() const;
        void setMarketDataFilter(const MarketDataFilter& marketDataFilter);


    private:
        /**
         * The operation type
         */
        std::string op;
        /**
         * Client generated unique id to link request with response (like json rpc)
         */
        Optional<int32_t> id;
        /**
         * Segmentation Enabled - allow the server to send large sets of data in segments, instead
         * of a single block
         */
        Optional<bool> segmentationEnabled;
        /**
         * Token value delta (received in MarketChangeMessage) that should be passed to resume a
         * subscription
         */
        std::string clk;
        /**
         * Heartbeat Milliseconds - the heartbeat rate (looped back on initial image after
         * validation: bounds are 500 to 5000)
         */
        Optional<int64_t> heartbeatMs;
        /**
         * Token value (received in initial MarketChangeMessage) that should be passed to resume a
         * subscription
         */
        std::string initialClk;

        MarketFilter marketFilter;
        /**
         * Conflate Milliseconds - the conflation rate (looped back on initial image after
         * validation: bounds are 0 to 120000)
         */
        Optional<int64_t> conflateMs;

        MarketDataFilter marketDataFilter;
};

}
}

#endif // MARKETSUBSCRIPTIONMESSAGE_H
