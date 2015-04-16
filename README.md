Greentop - C++ Betfair API Client
==========================

Introduction
------------
Sports betting exchange [Betfair](www.betfair.com) provides an API that allows you to:
 * read market information and prices
 * place / update / cancel bets
 * manage your account
and more.  Greentop is a C++ client for this API.

The API is documented at https://developer.betfair.com/.

License
-------

Greentop is released under the MIT license. See the LICENSE file for the full text.

Requirements
------------

* [jsoncpp](https://github.com/open-source-parsers/jsoncpp)
* [curlP](https://github.com/jpbarrette/curlpp)
* [libcurl](http://curl.haxx.se/libcurl/)

Build
-----

./configure --prefix=/usr
make
make install

Example Usage
-------------

See the "examples" directory.

-- Colin Doig
