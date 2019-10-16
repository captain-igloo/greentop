/**
 * Copyright 2017 Colin Doig.  Distributed under the MIT license.
 */

#include "greentop/stream/RunnerChange.h"

namespace greentop {
namespace stream {


RunnerChange::RunnerChange(const Optional<double>& tv,
    const std::vector<std::vector<double>>& batb,
    const std::vector<std::vector<double>>& spb,
    const std::vector<std::vector<double>>& bdatl,
    const std::vector<std::vector<double>>& trd,
    const Optional<double>& spf,
    const Optional<double>& ltp,
    const std::vector<std::vector<double>>& atb,
    const std::vector<std::vector<double>>& spl,
    const Optional<double>& spn,
    const std::vector<std::vector<double>>& atl,
    const std::vector<std::vector<double>>& batl,
    const Optional<int64_t>& id,
    const Optional<double>& hc,
    const std::vector<std::vector<double>>& bdatb) :
    tv(tv),
    batb(batb),
    spb(spb),
    bdatl(bdatl),
    trd(trd),
    spf(spf),
    ltp(ltp),
    atb(atb),
    spl(spl),
    spn(spn),
    atl(atl),
    batl(batl),
    id(id),
    hc(hc),
    bdatb(bdatb) {
}

void RunnerChange::fromJson(const Json::Value& json) {
    if (json.isMember("tv")) {
        tv = json["tv"].asDouble();
    }
    if (json.isMember("batb")) {
        for (unsigned i = 0; i < json["batb"].size(); ++i) {
            std::vector<double> temp;
            for (unsigned j = 0; j < json["batb"][i].size(); ++j) {
                temp.push_back(json["batb"][i][j].asDouble());
            }
            batb.push_back(temp);
        }
    }
    if (json.isMember("spb")) {
        for (unsigned i = 0; i < json["spb"].size(); ++i) {
            std::vector<double> temp;
            for (unsigned j = 0; j < json["spb"][i].size(); ++j) {
                temp.push_back(json["spb"][i][j].asDouble());
            }
            spb.push_back(temp);
        }
    }
    if (json.isMember("bdatl")) {
        for (unsigned i = 0; i < json["bdatl"].size(); ++i) {
            std::vector<double> temp;
            for (unsigned j = 0; j < json["bdatl"][i].size(); ++j) {
                temp.push_back(json["bdatl"][i][j].asDouble());
            }
            bdatl.push_back(temp);
        }
    }
    if (json.isMember("trd")) {
        for (unsigned i = 0; i < json["trd"].size(); ++i) {
            std::vector<double> temp;
            for (unsigned j = 0; j < json["trd"][i].size(); ++j) {
                temp.push_back(json["trd"][i][j].asDouble());
            }
            trd.push_back(temp);
        }
    }
    if (json.isMember("spf")) {
        spf = json["spf"].asDouble();
    }
    if (json.isMember("ltp")) {
        ltp = json["ltp"].asDouble();
    }
    if (json.isMember("atb")) {
        for (unsigned i = 0; i < json["atb"].size(); ++i) {
            std::vector<double> temp;
            for (unsigned j = 0; j < json["atb"][i].size(); ++j) {
                temp.push_back(json["atb"][i][j].asDouble());
            }
            atb.push_back(temp);
        }
    }
    if (json.isMember("spl")) {
        for (unsigned i = 0; i < json["spl"].size(); ++i) {
            std::vector<double> temp;
            for (unsigned j = 0; j < json["spl"][i].size(); ++j) {
                temp.push_back(json["spl"][i][j].asDouble());
            }
            spl.push_back(temp);
        }
    }
    if (json.isMember("spn")) {
        spn = json["spn"].asDouble();
    }
    if (json.isMember("atl")) {
        for (unsigned i = 0; i < json["atl"].size(); ++i) {
            std::vector<double> temp;
            for (unsigned j = 0; j < json["atl"][i].size(); ++j) {
                temp.push_back(json["atl"][i][j].asDouble());
            }
            atl.push_back(temp);
        }
    }
    if (json.isMember("batl")) {
        for (unsigned i = 0; i < json["batl"].size(); ++i) {
            std::vector<double> temp;
            for (unsigned j = 0; j < json["batl"][i].size(); ++j) {
                temp.push_back(json["batl"][i][j].asDouble());
            }
            batl.push_back(temp);
        }
    }
    if (json.isMember("id")) {
        id = json["id"].asInt64();
    }
    if (json.isMember("hc")) {
        hc = json["hc"].asDouble();
    }
    if (json.isMember("bdatb")) {
        for (unsigned i = 0; i < json["bdatb"].size(); ++i) {
            std::vector<double> temp;
            for (unsigned j = 0; j < json["bdatb"][i].size(); ++j) {
                temp.push_back(json["bdatb"][i][j].asDouble());
            }
            bdatb.push_back(temp);
        }
    }
}

Json::Value RunnerChange::toJson() const {
    Json::Value json(Json::objectValue);
    if (tv.isValid()) {
        json["tv"] = tv.toJson();
    }
    if (batb.size() > 0) {
        for (unsigned i = 0; i < batb.size(); ++i) {
            Json::Value temp(Json::arrayValue);
            for (unsigned j = 0; j < batb[i].size(); ++j) {
                temp.append(json["batb"][i][j]);
            }
            json["batb"].append(temp);
        }
    }
    if (spb.size() > 0) {
        for (unsigned i = 0; i < spb.size(); ++i) {
            Json::Value temp(Json::arrayValue);
            for (unsigned j = 0; j < spb[i].size(); ++j) {
                temp.append(json["spb"][i][j]);
            }
            json["spb"].append(temp);
        }
    }
    if (bdatl.size() > 0) {
        for (unsigned i = 0; i < bdatl.size(); ++i) {
            Json::Value temp(Json::arrayValue);
            for (unsigned j = 0; j < bdatl[i].size(); ++j) {
                temp.append(json["bdatl"][i][j]);
            }
            json["bdatl"].append(temp);
        }
    }
    if (trd.size() > 0) {
        for (unsigned i = 0; i < trd.size(); ++i) {
            Json::Value temp(Json::arrayValue);
            for (unsigned j = 0; j < trd[i].size(); ++j) {
                temp.append(json["trd"][i][j]);
            }
            json["trd"].append(temp);
        }
    }
    if (spf.isValid()) {
        json["spf"] = spf.toJson();
    }
    if (ltp.isValid()) {
        json["ltp"] = ltp.toJson();
    }
    if (atb.size() > 0) {
        for (unsigned i = 0; i < atb.size(); ++i) {
            Json::Value temp(Json::arrayValue);
            for (unsigned j = 0; j < atb[i].size(); ++j) {
                temp.append(json["atb"][i][j]);
            }
            json["atb"].append(temp);
        }
    }
    if (spl.size() > 0) {
        for (unsigned i = 0; i < spl.size(); ++i) {
            Json::Value temp(Json::arrayValue);
            for (unsigned j = 0; j < spl[i].size(); ++j) {
                temp.append(json["spl"][i][j]);
            }
            json["spl"].append(temp);
        }
    }
    if (spn.isValid()) {
        json["spn"] = spn.toJson();
    }
    if (atl.size() > 0) {
        for (unsigned i = 0; i < atl.size(); ++i) {
            Json::Value temp(Json::arrayValue);
            for (unsigned j = 0; j < atl[i].size(); ++j) {
                temp.append(json["atl"][i][j]);
            }
            json["atl"].append(temp);
        }
    }
    if (batl.size() > 0) {
        for (unsigned i = 0; i < batl.size(); ++i) {
            Json::Value temp(Json::arrayValue);
            for (unsigned j = 0; j < batl[i].size(); ++j) {
                temp.append(json["batl"][i][j]);
            }
            json["batl"].append(temp);
        }
    }
    if (id.isValid()) {
        json["id"] = id.toJson();
    }
    if (hc.isValid()) {
        json["hc"] = hc.toJson();
    }
    if (bdatb.size() > 0) {
        for (unsigned i = 0; i < bdatb.size(); ++i) {
            Json::Value temp(Json::arrayValue);
            for (unsigned j = 0; j < bdatb[i].size(); ++j) {
                temp.append(json["bdatb"][i][j]);
            }
            json["bdatb"].append(temp);
        }
    }
    return json;
}

bool RunnerChange::isValid() const {
    return true;
}

const Optional<double>& RunnerChange::getTv() const {
    return tv;
}
void RunnerChange::setTv(const Optional<double>& tv) {
    this->tv = tv;
}

const std::vector<std::vector<double>>& RunnerChange::getBatb() const {
    return batb;
}
void RunnerChange::setBatb(const std::vector<std::vector<double>>& batb) {
    this->batb = batb;
}

const std::vector<std::vector<double>>& RunnerChange::getSpb() const {
    return spb;
}
void RunnerChange::setSpb(const std::vector<std::vector<double>>& spb) {
    this->spb = spb;
}

const std::vector<std::vector<double>>& RunnerChange::getBdatl() const {
    return bdatl;
}
void RunnerChange::setBdatl(const std::vector<std::vector<double>>& bdatl) {
    this->bdatl = bdatl;
}

const std::vector<std::vector<double>>& RunnerChange::getTrd() const {
    return trd;
}
void RunnerChange::setTrd(const std::vector<std::vector<double>>& trd) {
    this->trd = trd;
}

const Optional<double>& RunnerChange::getSpf() const {
    return spf;
}
void RunnerChange::setSpf(const Optional<double>& spf) {
    this->spf = spf;
}

const Optional<double>& RunnerChange::getLtp() const {
    return ltp;
}
void RunnerChange::setLtp(const Optional<double>& ltp) {
    this->ltp = ltp;
}

const std::vector<std::vector<double>>& RunnerChange::getAtb() const {
    return atb;
}
void RunnerChange::setAtb(const std::vector<std::vector<double>>& atb) {
    this->atb = atb;
}

const std::vector<std::vector<double>>& RunnerChange::getSpl() const {
    return spl;
}
void RunnerChange::setSpl(const std::vector<std::vector<double>>& spl) {
    this->spl = spl;
}

const Optional<double>& RunnerChange::getSpn() const {
    return spn;
}
void RunnerChange::setSpn(const Optional<double>& spn) {
    this->spn = spn;
}

const std::vector<std::vector<double>>& RunnerChange::getAtl() const {
    return atl;
}
void RunnerChange::setAtl(const std::vector<std::vector<double>>& atl) {
    this->atl = atl;
}

const std::vector<std::vector<double>>& RunnerChange::getBatl() const {
    return batl;
}
void RunnerChange::setBatl(const std::vector<std::vector<double>>& batl) {
    this->batl = batl;
}

const Optional<int64_t>& RunnerChange::getId() const {
    return id;
}
void RunnerChange::setId(const Optional<int64_t>& id) {
    this->id = id;
}

const Optional<double>& RunnerChange::getHc() const {
    return hc;
}
void RunnerChange::setHc(const Optional<double>& hc) {
    this->hc = hc;
}

const std::vector<std::vector<double>>& RunnerChange::getBdatb() const {
    return bdatb;
}
void RunnerChange::setBdatb(const std::vector<std::vector<double>>& bdatb) {
    this->bdatb = bdatb;
}


}
}
