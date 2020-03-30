/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#ifndef STREAM_MARKETCHANGEMESSAGE_H
#define STREAM_MARKETCHANGEMESSAGE_H

#include <json/json.h>
#include <string>
#include <vector>

#include "greentop/Optional.h"
#include "greentop/stream/MarketChange.h"
#include "greentop/stream/ResponseMessage.h"

namespace greentop {
namespace stream {        

class MarketChangeMessage : public ResponseMessage {
    public:

        MarketChangeMessage(const std::string& op = std::string(),
            const Optional<int32_t>& id = Optional<int32_t>(),
            const std::string& ct = std::string(),
            const std::string& clk = std::string(),
            const Optional<int64_t>& heartbeatMs = Optional<int64_t>(),
            const Optional<int64_t>& pt = Optional<int64_t>(),
            const std::string& initialClk = std::string(),
            const std::vector<MarketChange>& mc = std::vector<MarketChange>(),
            const Optional<int64_t>& conflateMs = Optional<int64_t>(),
            const std::string& segmentType = std::string(),
            const Optional<int32_t>& status = Optional<int32_t>());

        virtual void fromJson(const Json::Value& json);

        virtual Json::Value toJson() const;

        virtual bool isValid() const;

        const std::string& getOp() const;
        void setOp(const std::string& op);

        const Optional<int32_t>& getId() const;
        void setId(const Optional<int32_t>& id);

        const std::string& getCt() const;
        void setCt(const std::string& ct);

        const std::string& getClk() const;
        void setClk(const std::string& clk);

        const Optional<int64_t>& getHeartbeatMs() const;
        void setHeartbeatMs(const Optional<int64_t>& heartbeatMs);

        const Optional<int64_t>& getPt() const;
        void setPt(const Optional<int64_t>& pt);

        const std::string& getInitialClk() const;
        void setInitialClk(const std::string& initialClk);

        const std::vector<MarketChange>& getMc() const;
        void setMc(const std::vector<MarketChange>& mc);

        const Optional<int64_t>& getConflateMs() const;
        void setConflateMs(const Optional<int64_t>& conflateMs);

        const std::string& getSegmentType() const;
        void setSegmentType(const std::string& segmentType);

        const Optional<int32_t>& getStatus() const;
        void setStatus(const Optional<int32_t>& status);


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
         * Change Type - set to indicate the type of change - if null this is a delta)
         */
        std::string ct;
        /**
         * Token value (non-null) should be stored and passed in a MarketSubscriptionMessage to
         * resume subscription (in case of disconnect)
         */
        std::string clk;
        /**
         * Heartbeat Milliseconds - the heartbeat rate (may differ from requested: bounds are 500
         * to 30000)
         */
        Optional<int64_t> heartbeatMs;
        /**
         * Publish Time (in millis since epoch) that the changes were generated
         */
        Optional<int64_t> pt;
        /**
         * Token value (non-null) should be stored and passed in a MarketSubscriptionMessage to
         * resume subscription (in case of disconnect)
         */
        std::string initialClk;
        /**
         * MarketChanges - the modifications to markets (will be null on a heartbeat
         */
        std::vector<MarketChange> mc;
        /**
         * Conflate Milliseconds - the conflation rate (may differ from that requested if
         * subscription is delayed)
         */
        Optional<int64_t> conflateMs;
        /**
         * Segment Type - if the change is split into multiple segments, this denotes the beginning
         * and end of a change, and segments in between. Will be null if data is not segmented
         */
        std::string segmentType;
        /**
         * Stream status: set to null if the exchange stream data is up to date and 503 if the
         * downstream services are experiencing latencies
         */
        Optional<int32_t> status;
};

}
}

#endif // STREAM_MARKETCHANGEMESSAGE_H
