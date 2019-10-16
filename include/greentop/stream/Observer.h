/**
 * Copyright 2019 Colin Doig.  Distributed under the MIT license.
 */
#ifndef STREAM_OBSERVER_H
#define STREAM_OBSERVER_H

#include "greentop/stream/ResponseMessage.h"

namespace greentop {
namespace stream {

class Observer {
    public:
        /**
         * Called when a message is received.
         *
         * @param message The message that has been received.
         */
        virtual void update(const ResponseMessage& message) const = 0;
};

}
}

#endif // STREAM_OBSERVER_H
