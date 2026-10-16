#pragma once

#include <string>
#include <string_view>
#include <optional>
#include <unordered_map>

namespace kv {
    class KVStore {
    public:
        void put(std::string_view key, std::string_view value);
        std::optional<std::string> get(std::string_view key) const;
        void del(std::string_view key);
    private:
        std::unordered_map<std::string, std::string> data;
    };
}