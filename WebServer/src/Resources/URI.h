#pragma once

#include <string>
#include <cstdint>

namespace WS
{
    class URI
    {
    public:
        URI();
        URI(const std::string &path);
        ~URI();

        inline bool operator<(const URI &obj) const { return mPath < obj.mPath; }
        inline bool operator==(const URI &obj) const { return mPath == obj.mPath; }

        // Path Getter and Setter
        inline void SetPath(const std::string &path) { mPath = path; }
        inline std::string GetPath() const { return mPath; }

        // Scheme Getter
        inline std::string GetScheme() const { return mScheme; }

        // Host Getter
        inline std::string GetHost() const { return mHost; }

        // Port Getter
        inline std::uint16_t GetPort() const { return mPort; }

    protected:
    private:
        std::string mPath;
        std::string mScheme;
        std::string mHost;
        std::uint16_t mPort;

        void SetPathToLowercase();
    };
}