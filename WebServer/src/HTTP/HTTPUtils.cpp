#include "HTTPUtils.h"

#include <algorithm>
#include <stdexcept>

namespace WS
{
    std::string toString(HTTPMethod method)
    {
        switch (method)
        {
        case HTTPMethod::GET:
            return "GET";
        case HTTPMethod::HEAD:
            return "HEAD";
        case HTTPMethod::POST:
            return "POST";
        case HTTPMethod::PUT:
            return "PUT";
        case HTTPMethod::DELETE:
            return "DELETE";
        case HTTPMethod::CONNECT:
            return "CONNECT";
        case HTTPMethod::OPTIONS:
            return "OPTIONS";
        case HTTPMethod::TRACE:
            return "TRACE";
        case HTTPMethod::PATCH:
            return "PATCH";
        default:
            return std::string();
        }
    }

    std::string toString(HTTPVersion version)
    {
        switch (version)
        {
        case HTTPVersion::HTTP_0_9:
            return "HTTP/0.9";
        case HTTPVersion::HTTP_1_0:
            return "HTTP/1.0";
        case HTTPVersion::HTTP_1_1:
            return "HTTP/1.1";
        case HTTPVersion::HTTP_2_0:
            return "HTTP/2.0";
        default:
            return std::string();
        }
    }

    std::string toString(HTTPStatusCode status)
    {
        switch (status)
        {
        case HTTPStatusCode::Continue:
            return "Continue";
        case HTTPStatusCode::Ok:
            return "OK";
        case HTTPStatusCode::Accepted:
            return "Accepted";
        case HTTPStatusCode::MovedPermanently:
            return "Moved Permanently";
        case HTTPStatusCode::Found:
            return "Found";
        case HTTPStatusCode::BadRequest:
            return "Bad Request";
        case HTTPStatusCode::Forbidden:
            return "Forbidden";
        case HTTPStatusCode::NotFound:
            return "Not Found";
        case HTTPStatusCode::MethodNotAllowed:
            return "Method Not Allowed";
        case HTTPStatusCode::ImATeapot:
            return "I'm a Teapot";
        case HTTPStatusCode::InternalServerError:
            return "Internal Server Error";
        case HTTPStatusCode::NotImplemented:
            return "Not Implemented";
        case HTTPStatusCode::BadGateway:
            return "Bad Gateway";
        default:
            return std::string();
        }
    }

    HTTPMethod strToMethod(const std::string &str)
    {
        std::string upperStr;
        std::transform(str.begin(), str.end(),
                       std::back_inserter(upperStr),
                       [](char c)
                       { return toupper(c); });

        if (upperStr == "GET")
            return HTTPMethod::GET;

        if (upperStr == "HEAD")
            return HTTPMethod::HEAD;

        if (upperStr == "POST")
            return HTTPMethod::POST;

        if (upperStr == "PUT")
            return HTTPMethod::PUT;

        if (upperStr == "DELETE")
            return HTTPMethod::DELETE;

        if (upperStr == "CONNECT")
            return HTTPMethod::CONNECT;

        if (upperStr == "OPTIONS")
            return HTTPMethod::OPTIONS;

        if (upperStr == "TRACE")
            return HTTPMethod::TRACE;

        if (upperStr == "PATCH")
            return HTTPMethod::PATCH;

        throw std::invalid_argument("Unexpected HTTP method");
    }

    HTTPVersion strToVersion(const std::string &str)
    {
        std::string upperStr;
        std::transform(str.begin(), str.end(),
                       std::back_inserter(upperStr),
                       [](char c)
                       { return toupper(c); });

        if (upperStr == "HTTP/0.9")
            return HTTPVersion::HTTP_0_9;

        if (upperStr == "HTTP/1.0")
            return HTTPVersion::HTTP_1_0;

        if (upperStr == "HTTP/1.1")
            return HTTPVersion::HTTP_1_1;

        if (upperStr == "HTTP/2.0")
            return HTTPVersion::HTTP_2_0;

        throw std::invalid_argument("Unexpected HTTP version");
    }
}