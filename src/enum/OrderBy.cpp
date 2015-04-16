#include "greentop/enum/OrderBy.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string OrderBy::BY_BET = "BY_BET";
const std::string OrderBy::BY_MARKET = "BY_MARKET";
const std::string OrderBy::BY_MATCH_TIME = "BY_MATCH_TIME";
const std::string OrderBy::BY_PLACE_TIME = "BY_PLACE_TIME";
const std::string OrderBy::BY_SETTLED_TIME = "BY_SETTLED_TIME";
const std::string OrderBy::BY_VOID_TIME = "BY_VOID_TIME";

OrderBy::OrderBy() {
    valid = false;
};

OrderBy::OrderBy(const std::string& v) {

    if (v != BY_BET &&
        v != BY_MARKET &&
        v != BY_MATCH_TIME &&
        v != BY_PLACE_TIME &&
        v != BY_SETTLED_TIME &&
        v != BY_VOID_TIME) {
        throw std::invalid_argument("Invalid OrderBy: " + v);
    }

    value = v;
    valid = true;
}

bool OrderBy::operator<(const OrderBy& other) const {
    return value < other.value;
}

bool OrderBy::operator==(const OrderBy& other) const {
    return value == other.value;
}

}

