#include <gtest/gtest.h>
#include "kv/kv_store.h"

TEST(KVStoreTest, PutThenGet) {
    kv::KVStore store;
    store.put("name", "lsm");

    auto val = store.get("name");
    ASSERT_TRUE(val.has_value());
    EXPECT_EQ(*val, "lsm");
}

TEST(KVStoreTest, DeleteExisting) {
    kv::KVStore store;
    store.put("name", "lsm");

    store.del("name");

    auto val = store.get("name");
    EXPECT_FALSE(val.has_value());
}

TEST(KVStoreTest, Overwrite) {
    kv::KVStore store;
    store.put("name", "lsm");
    store.put("name", "overwrite");

    auto val = store.get("name");

    ASSERT_TRUE(val.has_value());
    EXPECT_EQ(*val, "overwrite");
}

TEST(KVStoreTest, DeleteNonExisting) {
    kv::KVStore store;
    store.put("name", "lsm");
    
    store.del("dog");
    auto missingVal = store.get("dog");

    auto presentVal = store.get("name");

    EXPECT_FALSE(missingVal.has_value());

    ASSERT_TRUE(presentVal.has_value());
    EXPECT_EQ(*presentVal, "lsm");
}