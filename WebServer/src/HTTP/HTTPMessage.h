#pragma once

#include <string>
#include <map>

#include "HTTPUtils.h"

namespace WS
{
    class HTTPMessage
    {
    public:
        HTTPMessage();
        virtual ~HTTPMessage();

        // Version functions
        inline HTTPVersion GetVersion() const { return mVersion; }
        inline void SetVersion(const HTTPVersion ver) { mVersion = ver; }

        // Headers functions
        inline std::map<std::string, std::string> GetHeaders() const { return mHeaders; }
        std::string GetHeader(const std::string &key) const;
        void SetHeader(const std::string &key, const std::string &value);
        void RemoveHeader(const std::string &key);
        void ClearHeaders();

        // Body functions
        inline std::string GetBody() const { return mBody; }
        inline size_t GetBodyLength() const { return mBody.length(); }
        void SetBody(const std::string &body);
        void ClearBody();

    protected:
        HTTPVersion mVersion;
        std::map<std::string, std::string> mHeaders;
        std::string mBody;

        void SetContentLength();

    private:
    };
}