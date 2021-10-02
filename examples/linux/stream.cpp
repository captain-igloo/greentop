#include <iostream>

#include "greentop/stream/MarketChangeMessage.h"
#include "greentop/stream/MarketDataFilter.h"
#include "greentop/stream/MarketFilter.h"
#include "greentop/stream/MarketSubscriptionMessage.h"
#include "greentop/StreamApi.h"
#include "greentop/stream/Observer.h"
#include "greentop/stream/ResponseMessage.h"

using namespace greentop;

class MyListener : public stream::Observer {
    public:
        void update(const ResponseMessage& message) const {
            const stream::MarketChangeMessage* mcm = dynamic_cast<const stream::MarketChangeMessage*>(&message);
            std::cout << "update " << mcm->getId() << std::endl;
        }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <application-key> <session-id>" << std::endl;
        return 1;
    }

    MyListener myListener;

    StreamApi streamApi(argv[1]);
    streamApi.addObserver("mcm", &myListener);
    streamApi.connect();
    streamApi.authenticate(argv[2]);

    stream::MarketDataFilter marketDataFilter;
    marketDataFilter.setFields({"EX_BEST_OFFERS_DISP"});
    marketDataFilter.setLadderLevels(3);

    stream::MarketFilter marketFilter;
    marketFilter.setMarketIds({ "1.160846453" });
    stream::MarketSubscriptionMessage msm;
    msm.setOp("marketSubscription");
    msm.setId(99);
    msm.setMarketFilter(marketFilter);
    msm.setMarketDataFilter(marketDataFilter);
    streamApi.write(msm);
    streamApi.read();
    return 0;
}
