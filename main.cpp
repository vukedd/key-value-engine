#include <iostream>
#include "kv/kv_store.h"

int main() {
    kv::KVStore store;

    store.put("name", "lsm");

    if (auto val = store.get("name")) {
        std::cout << "found: " << *val << std::endl;
    }

    store.del("name");
    if (!store.get("name")) {
        std::cout << "deleted" << std::endl;
    }

    return 0;
}