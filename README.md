# Archived

I'm not really sure if this code is safe enough to use

Either way if you need HTTP client library you probably should use something else

# curlEr

curlEr is a simple async http client, created on top of curl (https://curl.se/).

## Features

* Simple to install - 2 files, 1 header and 1 source
* Simple to use - create a factory, create a builder, fill up the builder and push the request
* Supports C++17 and higher
* Efficient because utilizes a curl_multi_* API
* Thread-safe request interface
* Uses only STL and curl library
