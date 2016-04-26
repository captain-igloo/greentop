#include "greentop/curl/SList.h"

namespace greentop {

SList::SList(curl_slist* slist) : slist(slist) {
}

void SList::append(const std::string& s) {
    slist = curl_slist_append(slist, s.c_str());
}

void SList::set(curl_slist* slist) {
    this->slist = slist;
}

const curl_slist* SList::get() const {
    return slist;
}

SList::~SList() {
    if (slist) {
        curl_slist_free_all(slist);
    }
}

}
