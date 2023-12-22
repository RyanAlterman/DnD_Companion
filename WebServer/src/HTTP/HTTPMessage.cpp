#include "HTTPMessage.h"

namespace WS
{
    HTTPMessage::HTTPMessage()
    {
        mVersion = HTTPVersion::HTTP_1_1;
    }

    HTTPMessage::~HTTPMessage()
    {
        // NOTE: Currently does nothing
    }

    std::string HTTPMessage::GetHeader(const std::string &key) const
    {
        if (mHeaders.count(key) > 0)
            return mHeaders.at(key);

        return std::string();
    }

    void HTTPMessage::SetHeader(const std::string &key, const std::string &value)
    {
        mHeaders[key] = std::move(value);
    }

    void HTTPMessage::RemoveHeader(const std::string &key)
    {
        mHeaders.erase(key);
    }

    void HTTPMessage::ClearHeaders()
    {
        mHeaders.clear();
    }

    void HTTPMessage::SetBody(const std::string &body)
    {
        mBody = std::move(body);
        SetContentLength();
    }

    void HTTPMessage::ClearBody()
    {
        mBody.clear();
        SetContentLength();
    }

    void HTTPMessage::SetContentLength()
    {
        SetHeader("Content-Length", std::to_string(mBody.length()));
    }
}