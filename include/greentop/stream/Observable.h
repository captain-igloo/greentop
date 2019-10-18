/**
 * Copyright 2019 Colin Doig.  Distributed under the MIT license.
 */
#ifndef STREAM_OBSERVABLE_H
#define STREAM_OBSERVABLE_H

#include <map>
#include <set>
#include <string>

#include "greentop/stream/Observer.h"

namespace greentop {
namespace stream {

class Observable {
    public:
        /**
         * Add observer.
         *
         * @param type The type of message to observe.
         * @param observer The observer to add. 
         */
        void addObserver(const std::string& type, const Observer* observer);

        /**
         * Remove observer.
         *
         * @param type The type of message.
         * @param observer The observer to remove.
         */
        void removeObserver(const std::string& type, const Observer* observer);
    protected:
        /**
         * Notify observers that a message has been received.
         *
         * @param type The type of message.
         * @param response The message that has been received.
         */
        void notify(const std::string& type, const ResponseMessage& response) const;
    private:
        uint32_t count = 0;
        std::map<std::string, std::set<const Observer*>> callbacks;
};

}
}

#endif // STREAM_OBSERVABLE_H
