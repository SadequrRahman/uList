#include <stdio.h>
#include <stdlib.h>
#include "../inc/uList.h"
#include "./CUnitTest-1.0/CUnitTest/CUnitTest.h"


#define MAX_ITEM_NUM    4

uList_t *list = NULL;
char strings[MAX_ITEM_NUM][20] = {
    "Test value 1",
    "Test value 2",
    "Test value 3",
    "Test value 4"
};


void uList_test_setup(void) 
{
	list = uList_createList();
}


int uList_checkListCreation(void)
{
    CUT_ASSERT_NOT_NULL(list);
    return 0;
}


int uList_createNodeaAndAppend(void)
{
    uNode_t *node = uList_createNode(strings[0], strlen(strings[0]), NODE_SELF_ALLOC);
    uList_append(list, node);
    int ret = memcmp(strings[0], node->value, node->len);
    CUT_ASSERT_EQUAL(ret, 0); 
    return 0;
}

void uList_addingNodes(void)
{
    for (size_t i = 0; i < MAX_ITEM_NUM; i++)
    {
        /* code */
        uNode_t *node = uList_createNode(strings[i], strlen(strings[i]), NODE_SELF_ALLOC);
        uList_append(list, node);
    }
}



void uList_test_teardown(void)
{
    if(list)
      uList_remove(list);
}

int uList_test_iterateFromTail()
{
    int i = 0;
    uList_addingNodes();
    uNode_t * it = list->tail;
    printf("Num item: %d\r\n", list->numItems);
    CUT_ASSERT_MESSAGE("More item then appended", list->numItems == MAX_ITEM_NUM);
    if (it == NULL)
        printf("tails is null\r\n");
    else
        printf("Tails not null\r\n");
    
    while (it)
    {
        printf("Value-> %s\r\n", (char*)it->value);
        int ret = memcmp(strings[i], it->value, it->len);
        CUT_ASSERT_EQUAL(ret, 0); 
        i++;
        it = it->nextNode;
    }
    
    return 0;
}


CUT_BEGIN_SUITE_F(uList_test, &uList_test_setup, &uList_test_teardown)
CUT_RUN_TEST(uList_checkListCreation);
CUT_RUN_TEST(uList_createNodeaAndAppend);
CUT_RUN_TEST(uList_test_iterateFromTail);
CUT_END_SUITE_F


CUT_BEGIN_TEST_HARNESS
CUT_RUN_SUITE_TESTS(uList_test);
CUT_END_TEST_HARNESS