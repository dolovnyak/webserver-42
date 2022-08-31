#pragma once

#include <string>

#define CR                  (char) '\r'
#define LF                  (char) '\n'
#define CRLF                "\r\n"
#define CRLF_LEN            2
#define DELIMITERS          " \f\n\r\t\v" /// from std::isspace

#define CONTENT_LENGTH "content-length"

#define TRANSFER_ENCODING "transfer-encoding"
#define CHUNKED "chunked"
#define HOST "host"

namespace Http {

    class Header {
    public:
        Header(const std::string& key, const std::string& value)
                : key(key), value(value) {}

        std::string key;
        std::string value;
    };

    enum Code {
        OK = 200,
        BadRequest = 400,
        NotFound = 404,
        MethodNotAllowed = 405,
        PayloadTooLarge = 413,
        InternalServerError = 500,
        NotImplemented = 501,
    };
}
