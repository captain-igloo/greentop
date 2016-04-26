#ifndef CURL_SLIST_H
#define CURL_SLIST_H

#include <curl/curl.h>
#include <memory>
#include <string>

namespace greentop {

class SList {
    public:
        SList(curl_slist* slist = NULL);

        void append(const std::string& s);

        void set(curl_slist* slist);

        const curl_slist* get() const;

        ~SList();

    private:
        curl_slist* slist;

        // no copying
        SList(const SList&);
        SList& operator=(const SList&);
};

}

#endif // CURL_SLIST_H
