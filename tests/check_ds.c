#include <check.h>
#include <stdlib.h>
#include "../src/ds.h"

START_TEST (test_ds_create) {
    
    list_t* list;
    list = newList();
    ck_assert(isEmpty(list));

} END_TEST;
START_TEST (test_ds_insertions) {
    
    list_t* list;
    list = newList();

    char* pos1 = "item 1";
    char* pos2 = "item 2";
    char* pos3 = "item 3";
    char* pos4 = "item 4";
    char* pos5 = "item 5";
    char* pos6 = "item 6";
    char* pos7 = "item 7";
    char* pos8 = "item 8";

    ck_assert_int_eq(insertLast(list, (void*)pos6), 1);
    ck_assert_int_eq(insertLast(list, (void*)pos8), 1);
    ck_assert_int_eq(insertFirst(list, (void*)pos2), 1);
    ck_assert_int_eq(insertFirst(list, (void*)pos1), 1);
    ck_assert_pstr_eq((char *)getAt(list, 1)->data, "item 1");
    ck_assert_pstr_eq((char *)getAt(list, 2)->data, "item 2");
    ck_assert_pstr_eq((char *)getAt(list, 3)->data, "item 6");
    ck_assert_pstr_eq((char *)getAt(list, 4)->data, "item 8");
    ck_assert_int_eq(list->size, 4);

    ck_assert_int_eq(insertAt(list, (void*)pos3, 3), 1);
    ck_assert_int_eq(insertAt(list, (void*)pos4, 4), 1);
    ck_assert_pstr_eq((char *)getAt(list, 1)->data, "item 1");
    ck_assert_pstr_eq((char *)getAt(list, 2)->data, "item 2");
    ck_assert_pstr_eq((char *)getAt(list, 3)->data, "item 3");
    ck_assert_pstr_eq((char *)getAt(list, 4)->data, "item 4");
    ck_assert_pstr_eq((char *)getAt(list, 5)->data, "item 6");
    ck_assert_pstr_eq((char *)getAt(list, 6)->data, "item 8");
    ck_assert_int_eq(list->size, 6);

    ck_assert_int_eq(insertAt(list, (void*)pos5, 5), 1);
    ck_assert_int_eq(insertAt(list, (void*)pos7, 7), 1);
    ck_assert_pstr_eq((char *)getAt(list, 1)->data, "item 1");
    ck_assert_pstr_eq((char *)getAt(list, 2)->data, "item 2");
    ck_assert_pstr_eq((char *)getAt(list, 3)->data, "item 3");
    ck_assert_pstr_eq((char *)getAt(list, 4)->data, "item 4");
    ck_assert_pstr_eq((char *)getAt(list, 5)->data, "item 5");
    ck_assert_pstr_eq((char *)getAt(list, 6)->data, "item 6");
    ck_assert_pstr_eq((char *)getAt(list, 7)->data, "item 7");
    ck_assert_pstr_eq((char *)getAt(list, 8)->data, "item 8");
    ck_assert_int_eq(list->size, 8);

} END_TEST;
START_TEST (test_ds_removals) {
    
    list_t* list;
    list = newList();

    char* pos1 = (char*)malloc(6);
    char* pos2 = (char*)malloc(6);
    char* pos3 = (char*)malloc(6);
    char* pos4 = (char*)malloc(6);
    char* pos5 = (char*)malloc(6);
    char* pos6 = (char*)malloc(6);
    char* pos7 = (char*)malloc(6);
    char* pos8 = (char*)malloc(6);

    strcpy(pos1, "item 1");
    strcpy(pos2, "item 2");
    strcpy(pos3, "item 3");
    strcpy(pos4, "item 4");
    strcpy(pos5, "item 5");
    strcpy(pos6, "item 6");
    strcpy(pos7, "item 7");
    strcpy(pos8, "item 8");
 
    ck_assert_int_eq(insertLast(list, (void*)pos6), 1);
    ck_assert_int_eq(insertLast(list, (void*)pos8), 1);
    ck_assert_int_eq(insertFirst(list, (void*)pos2), 1);
    ck_assert_int_eq(insertFirst(list, (void*)pos1), 1);
    ck_assert_int_eq(insertAt(list, (void*)pos3, 3), 1);
    ck_assert_int_eq(insertAt(list, (void*)pos4, 4), 1);
    ck_assert_int_eq(insertAt(list, (void*)pos5, 5), 1);
    ck_assert_int_eq(insertAt(list, (void*)pos7, 7), 1);
    ck_assert_pstr_eq((char *)getAt(list, 1)->data, "item 1");
    ck_assert_pstr_eq((char *)getAt(list, 2)->data, "item 2");
    ck_assert_pstr_eq((char *)getAt(list, 3)->data, "item 3");
    ck_assert_pstr_eq((char *)getAt(list, 4)->data, "item 4");
    ck_assert_pstr_eq((char *)getAt(list, 5)->data, "item 5");
    ck_assert_pstr_eq((char *)getAt(list, 6)->data, "item 6");
    ck_assert_pstr_eq((char *)getAt(list, 7)->data, "item 7");
    ck_assert_pstr_eq((char *)getAt(list, 8)->data, "item 8");
    ck_assert_int_eq(list->size, 8);

    removeAt(list, 8);
    removeAt(list, 1);
    ck_assert_pstr_eq((char *)getAt(list, 1)->data, "item 2");
    ck_assert_pstr_eq((char *)getAt(list, 2)->data, "item 3");
    ck_assert_pstr_eq((char *)getAt(list, 3)->data, "item 4");
    ck_assert_pstr_eq((char *)getAt(list, 4)->data, "item 5");
    ck_assert_pstr_eq((char *)getAt(list, 5)->data, "item 6");
    ck_assert_pstr_eq((char *)getAt(list, 6)->data, "item 7");
    ck_assert_int_eq(list->size, 6);

    removeAt(list, 4);
    ck_assert_pstr_eq((char *)getAt(list, 1)->data, "item 2");
    ck_assert_pstr_eq((char *)getAt(list, 2)->data, "item 3");
    ck_assert_pstr_eq((char *)getAt(list, 3)->data, "item 4");
    ck_assert_pstr_eq((char *)getAt(list, 4)->data, "item 6");
    ck_assert_pstr_eq((char *)getAt(list, 5)->data, "item 7");
    ck_assert_int_eq(list->size, 5);

    destroy(list);
    ck_assert(isEmpty(list));
    
} END_TEST;
Suite *ds_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Data Structure Test Suite");
    tc_core = tcase_create("test");

    tcase_add_test(tc_core, test_ds_create);
    tcase_add_test(tc_core, test_ds_insertions);
    tcase_add_test(tc_core, test_ds_removals);

    suite_add_tcase(s, tc_core);

    return s;
}
int main(void) {

    int num_failed = 0;
    Suite *s;
    SRunner *runner;

    s = ds_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    num_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
