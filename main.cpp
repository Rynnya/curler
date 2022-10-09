#include "curler.hh"

int main() {

    curl::Factory factory { /* maxAmountOfConcurrentConnections = 0 (unlimited), maxConnectionTimeoutInMilliseconds = 0 (300 seconds default) */ };

    curl::Builder blueprint = factory.createRequest("https://www.example.com/");
    blueprint
        .onDestroy([]() {
            /* do something that must be done when request is done (for example unlock condition variable) */
        })
        .onException([](curl::ExceptionType exType, std::exception_ptr exPtr) {
            /* do something with exType and exPtr, called when any of your callbacks caused an exception (except onDestroy) */
        })
        .onError([](curl::Response& resp) {
            /* do something with resp, called when internal error happend */
        })
        .preRequest([](const curl::Builder& builder, const std::string& url) {
            /* do something with builder which it `this` and url which is complete url with host, path and query */
        })
        .onComplete([](curl::Response& resp) {
            /* do something with resp, called when request fully done */
        });

    factory.pushRequest(blueprint);

    return 0;
}

