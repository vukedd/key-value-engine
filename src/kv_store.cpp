#include "kv/kv_store.h"

namespace kv {
    void KVStore::put(std::string_view key, std::string_view value) {

    }

    std::optional<std::string> KVStore::get(std::string_view key) const {
        return std::nullopt;
    }

    void KVStore::del(std::string_view key) {

    }
}