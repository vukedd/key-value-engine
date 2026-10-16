#include "kv/kv_store.h"

namespace kv {
    void KVStore::put(std::string_view key, std::string_view value) {
        data[std::string(key)] = std::string(value);
    }

    std::optional<std::string> KVStore::get(std::string_view key) const {
        std::string k(key);
        auto it = data.find(k);
        if (it != data.end()) {
            return it->second;
        }

        return std::nullopt;
    }

    void KVStore::del(std::string_view key) {
        std::string k(key);
        data.erase(k);
    }
}