#include <gtest/gtest.h>

extern "C" {
    #include "menu.h"
    #include "no_procs.h"
    #include "with_procs.h"

    #include <cstring>
}
//
//
//const size_t inventory_number = 0;
//const size_t capacity = 1;
//const bool overwrite = 1;
//const char type[] = "HDD";
//
//const size_t size = 0;
//
//const size_t new_size = 1;
//
//void free_s(Storage *s) {
//    free(s->data);
//    free(s);
//    s = NULL;
//}
//
//TEST(create, storage_device_constructor) {
//Storage_device *my_sd = storage_device_constructor((char*)type, overwrite, capacity, inventory_number);
//EXPECT_TRUE(my_sd != NULL);
//
//Storage_device *sd = (Storage_device *)malloc(sizeof(Storage_device));
//EXPECT_TRUE(sd != NULL);
//
//sd->capacity = capacity;
//sd->overwrite = overwrite;
//sd->type = (char*)type;
//sd->inventory_number = inventory_number;
//
//ASSERT_EQ(sd->capacity, my_sd->capacity);
//ASSERT_EQ(sd->overwrite, my_sd->overwrite);
//ASSERT_EQ(sd->type, my_sd->type);
//ASSERT_EQ(sd->inventory_number, my_sd->inventory_number);
//
//free(sd);
//free(my_sd);
//
//}
//
//TEST(create, storage_constructor) {
//Storage *my_s = storage_constructor(capacity, size);
//EXPECT_TRUE(my_s != NULL);
//
//Storage *s = (Storage *)malloc(sizeof(Storage));
//EXPECT_TRUE(s != NULL);
//
//s->capacity = capacity;
//s->size = size;
//s->data = (Storage_device *)malloc(sizeof(Storage_device) * capacity);
//
//ASSERT_EQ(s->capacity, my_s->capacity);
//ASSERT_EQ(s->size, my_s->size);
//
//free_s(s);
//free_s(my_s);
//}
//
//TEST(create, add_storage_device) {
//Storage *my_s = storage_constructor(capacity, size);
//EXPECT_TRUE(my_s != NULL);
//
//Storage_device *my_sd = storage_device_constructor((char*)type, overwrite, capacity, inventory_number);
//EXPECT_TRUE(my_sd != NULL);
//
//
//Storage *s = (Storage *)malloc(sizeof(Storage));
//EXPECT_TRUE(s != NULL);
//
//Storage_device *sd = (Storage_device *)malloc(sizeof(Storage_device));
//EXPECT_TRUE(sd != NULL);
//
//s->capacity = capacity;
//s->size = size;
//s->data = (Storage_device *)malloc(sizeof(Storage_device) * capacity);
//
//sd->capacity = capacity;
//sd->overwrite = overwrite;
//sd->type = (char*)type;
//sd->inventory_number = inventory_number;
//
//
//ASSERT_EQ(add_storage_device(s, sd), add_storage_device(my_s, my_sd));
//ASSERT_EQ(s->capacity, my_s->capacity);
//ASSERT_EQ(s->size, my_s->size);
//
//for(int i = 0; i < new_size; ++i) {
//ASSERT_EQ(&s->data[i].capacity, &s->data[i].capacity);
//ASSERT_EQ(&s->data[i].inventory_number, &s->data[i].inventory_number);
//ASSERT_EQ(&s->data[i].overwrite, &s->data[i].overwrite);
//ASSERT_EQ(strcmp((char *)&s->data[i].type, (char *)&my_s->data[i].type), 0);
//}
//
//free(sd);
//free(my_sd);
//free_s(s);
//free_s(my_s);
//}
//
//
//TEST(delete, delete_storage) {
//Storage *my_s = storage_constructor(capacity, size);
//EXPECT_TRUE(my_s != NULL);
//ASSERT_EQ(1, delete_storage(&my_s));
//ASSERT_EQ(NULL, my_s);
//
//}
