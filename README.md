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
* [libcurl](http://curl.haxx.se/libcurl/)

Build (Linux)
-------------

```
export CPPFLAGS=-I/usr/include/jsoncpp
./configure --prefix=/usr
make
make install
```

Build (Windows)
---------------

Instructions for building on Windows using Visual Studio can be found [here](https://github.com/captain-igloo/greentop/wiki/Build-(Windows)).

Ubuntu Binaries
---------------

Binaries for Ubuntu are available at [https://launchpad.net/~captain-igloo/+archive/ubuntu/greenthumb](https://launchpad.net/~captain-igloo/+archive/ubuntu/greenthumb)

Example Usage
-------------

See the "examples" directory.

Contact
-------

colindoig [at] gmail [dot] com

-- Colin Doig
