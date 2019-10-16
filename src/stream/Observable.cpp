/**
 * Copyright 2019 Colin Doig.  Distributed under the MIT license.
 */

 #include "greentop/stream/Observable.h"

namespace greentop {
namespace stream {

void Observable::addObserver(const std::string& type, const Observer* observer) {
    callbacks[type].insert(observer);
}

void Observable::removeObserver(const std::string& type, const Observer* observer) {
    callbacks[type].erase(observer);
}

void Observable::notify(const std::string& type, const ResponseMessage& response) const {
    std::map<std::string, std::set<const Observer*>>::const_iterator it = callbacks.find(type);

    if (it != callbacks.end()) {
        for (auto const& element: it->second) {
            element->update(response);    
        }
    }
}

}
}
