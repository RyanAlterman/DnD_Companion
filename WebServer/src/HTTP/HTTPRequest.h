#pragma once

#include <string>
#include "HTTPMessage.h"

namespace WS
{
    class HTTPRequest : public HTTPMessage
    {
    public:
        HTTPRequest();
        ~HTTPRequest();

        // Method Getter and Setter
        inline std::string GetMethod() const { return mMethod; }
        inline void SetMethod(const std::string &method) { mMethod = method; }

        // URI Getter and Setter
        inline std::string GetURI() const { return mURI; }
        inline void SetURI(const std::string &uri) { mURI = uri; }

    protected:
    private:
        std::string mMethod;
        std::string mURI;
    };
}