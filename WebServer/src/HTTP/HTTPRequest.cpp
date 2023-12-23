#include "HTTPRequest.h"

#include <algorithm>
#include <sstream>

namespace WS
{
    HTTPRequest::HTTPRequest()
    {
        mMethod = HTTPMethod::GET;
    }

    HTTPRequest::~HTTPRequest()
    {
        // NOTE: Currently does nothing
    }

    std::string toString(const HTTPRequest &request)
    {
        std::ostringstream oss;

        oss << toString(request.GetMethod()) << " ";
        oss << request.GetURI().GetPath() << " ";
        oss << toString(request.GetVersion()) << "\r\n";

        for (const auto &header : request.GetHeaders())
            oss << header.first << ": " << header.second << "\r\n";

        oss << "\r\n";
        oss << request.GetBody();

        return oss.str();
    }

    HTTPRequest strToRequest(const std::string &str)
    {
        HTTPRequest request;

        std::string startLine;
        std::string headerLines;
        std::string body;
        size_t lpos = 0;
        size_t rpos = 0;

        rpos = str.find("\r\n", lpos);
        if (rpos == std::string::npos)
            throw std::invalid_argument("Could not find request start line");

        startLine = str.substr(lpos, rpos - lpos);
        lpos = rpos + 2;
        rpos = str.find("\r\n\r\n", lpos);
        if (rpos != std::string::npos)
        {
            headerLines = str.substr(lpos, rpos - lpos);
            lpos = rpos + 4;
            rpos = str.length();
            if (lpos < rpos)
                body = str.substr(lpos, rpos - lpos);
        }

        // Parse the start line
        std::string line;
        std::string method;
        std::string path;
        std::string version;
        std::istringstream iss;
        iss.clear();
        iss.str(startLine);
        iss >> method >> path >> version;
        if (!iss.good() && !iss.eof())
            throw std::invalid_argument("Invalid start line format");
        request.SetMethod(strToMethod(method));
        request.SetURI(URI(path));
        if (strToVersion(version) != HTTPVersion::HTTP_1_1)
            throw std::invalid_argument("Unsupported HTTP version");

        // Parse header fields
        std::string key;
        std::string value;
        iss.clear();
        iss.str(headerLines);
        while (std::getline(iss, line))
        {
            std::istringstream headerStream(line);
            std::getline(headerStream, key, ':');
            std::getline(headerStream, value);

            key.erase(std::remove_if(key.begin(), key.end(),
                                     [](char c)
                                     { return std::isspace(c); }),
                      key.end());

            value.erase(std::remove_if(value.begin(), value.end(),
                                       [](char c)
                                       { return std::isspace(c); }),
                        value.end());

            request.SetHeader(key, value);
        }

        request.SetBody(body);

        return request;
    }
}