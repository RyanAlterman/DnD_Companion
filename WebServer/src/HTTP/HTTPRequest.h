#pragma once

#include <string>
#include "../Resources/URI.h"
#include "HTTPMessage.h"

namespace WS
{
    class HTTPRequest : public HTTPMessage
    {
    public:
        HTTPRequest();
        ~HTTPRequest();

        // Method Getter and Setter
        inline HTTPMethod GetMethod() const { return mMethod; }
        inline void SetMethod(HTTPMethod method) { mMethod = method; }

        // URI Getter and Setter
        inline URI GetURI() const { return mURI; }
        inline void SetURI(const URI &uri) { mURI = std::move(uri); }

    protected:
    private:
        HTTPMethod mMethod;
        URI mURI;
    };

    std::string toString(const HTTPRequest &request);
    HTTPRequest strToRequest(const std::string &str);
}