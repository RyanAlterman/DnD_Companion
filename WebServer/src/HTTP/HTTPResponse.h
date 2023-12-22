#pragma once

#include <string>
#include "HTTPMessage.h"

namespace WS
{
    class HTTPResponse : public HTTPMessage
    {
    public:
        HTTPResponse();
        ~HTTPResponse();

        // Status code Getter and Setter
        inline std::string GetStatusCode() const { return mStatus; }
        inline void SetStatusCode(const std::string &status) { mStatus = status; }

    protected:
    private:
        std::string mStatus;
    };
}