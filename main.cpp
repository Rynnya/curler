#include "curler.hpp"
#include <iostream>

int main() {

    curl::Factory factory { /* maxAmountOfConcurrentConnections = 0 (unlimited), maxConnectionTimeoutInMilliseconds = 0 (300 seconds default) */ };

    curl::Builder blueprint = factory.createRequest("https://www.example.com/");

    blueprint
        .preRequest([](const curl::Builder& builder) {
            /* do something with builder which is `this` */
        })
        .onException([](curl::ExceptionType exType, std::exception_ptr exPtr) {
            /* do something with exType and exPtr, called when any of your callbacks caused an exception (except onDestroy) */
        })
        .onError([](curl::Response& resp) {
            /* do something with resp, called when internal error happend */
        })
        .onComplete([](curl::Response& resp) {
            /* do something with resp, called when request fully done */
        })
        .onDestroy([]() {
            /* do something that must be done when request is done (for example unlock condition variable) */
        });

    /* do request asynchronously, get result through callbacks */
    factory.pushRequest(blueprint);

    /* do request synchronously, get result through raw response */
    curl::Response resp = factory.syncRequest(blueprint);

    std::cout << resp.body << '\n';

    return 0;
}

