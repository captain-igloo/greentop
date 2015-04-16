#include "greentop/enum/MatchProjection.h"

#include <stdexcept>

#include "greentop/Enum.h"

namespace greentop {

const std::string MatchProjection::NO_ROLLUP = "NO_ROLLUP";
const std::string MatchProjection::ROLLED_UP_BY_PRICE = "ROLLED_UP_BY_PRICE";
const std::string MatchProjection::ROLLED_UP_BY_AVG_PRICE = "ROLLED_UP_BY_AVG_PRICE";

MatchProjection::MatchProjection() {
    valid = false;
};

MatchProjection::MatchProjection(const std::string& v) {

    if (v != NO_ROLLUP &&
        v != ROLLED_UP_BY_PRICE &&
        v != ROLLED_UP_BY_AVG_PRICE) {
        throw std::invalid_argument("Invalid MatchProjection: " + v);
    }

    value = v;
    valid = true;
}

bool MatchProjection::operator<(const MatchProjection& other) const {
    return value < other.value;
}

bool MatchProjection::operator==(const MatchProjection& other) const {
    return value == other.value;
}

}

