#include <iostream>
#include "kv/kv_store.h"

int main() {
    kv::KVStore store;
    store.put("name", "lsm");

    return 0;
}