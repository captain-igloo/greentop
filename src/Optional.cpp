#include "greentop/Optional.h"

namespace greentop {

template<>
void Optional<bool>::fromJson(const Json::Value& json) {
    value = json.asBool();
    valid = true;
}

}
