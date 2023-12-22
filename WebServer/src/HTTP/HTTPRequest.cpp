#include "HTTPRequest.h"

namespace WS
{
    HTTPRequest::HTTPRequest()
    {
        mMethod = "";
        mURI = "";
    }

    HTTPRequest::~HTTPRequest()
    {
        // NOTE: Currently does nothing
    }
}