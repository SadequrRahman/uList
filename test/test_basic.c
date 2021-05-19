#include <stdio.h>
#include <stdlib.h>
#include "../inc/uList.h"
#include "./CUnitTest-1.0/CUnitTest/CUnitTest.h"

uList_t *list = NULL;


void uList_test_setup(void) 
{
	list = uList_createList();
}


int uList_test1(void)
{
    CUT_ASSERT_NULL(list);
    return 0;
}



void uList_test_teardown(void)
{
    if(list)
        uList_remove(list);
}


CUT_BEGIN_SUITE_F(uList_test, &uList_test_setup, &uList_test_teardown)
CUT_RUN_TEST(uList_test1);
CUT_END_SUITE_F


CUT_BEGIN_TEST_HARNESS
CUT_RUN_SUITE_TESTS(uList_test);
CUT_END_TEST_HARNESS