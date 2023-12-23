#include "URI.h"

#include <algorithm>

namespace WS
{
    URI::URI()
    {
        mPath = "";
    }

    URI::URI(const std::string &path)
    {
        mPath = path;
        SetPathToLowercase();
    }

    URI::~URI()
    {
        // NOTE: Currently does nothing
    }

    void URI::SetPathToLowercase()
    {
        std::transform(mPath.begin(), mPath.end(), mPath.begin(),
                       [](char c)
                       { return tolower(c); });
    }
}