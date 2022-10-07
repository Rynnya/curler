#include "curl.hh"

int main() {

    curl::Factory factory { /* maxAmountOfConcurrentConnections = 0 (unlimited), maxConnectionTimeoutInMilliseconds = 0 (300 seconds default) */ };

    curl::Builder blueprint = factory.createRequest("https://www.example.com/");
    blueprint
        .setOnExceptionCallback([](curl::ExceptionType exType, std::exception_ptr exPtr) {
            /* do something with exType and exPtr, this will be called when any of your callbacks caused an exception */
        })
        .setOnErrorCallback([](curl::Response& resp) {
            /* do something with resp */
        })
        .setPreRequestCallback([](const curl::Builder& builder, const std::string& url) {
            /* do something with builder which is 'blueprint' and url which is complete url with host, path and query */
        })
        .setPostRequestCallback([](curl::Response& resp) {
            /* do something with resp */
        });

    factory.pushRequest(blueprint);

    return 0;
}

