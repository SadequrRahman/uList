/*
 * sample.c -- a small example showing how to use CUnitTest
 */

#include "CUnitTest.h"
#include <stdlib.h>

/*
 * declaration of a global variable for the test functions 
 */
int *val = NULL; 

/*
 * function for setting up the state of the global before
 * EVERY test in the suite is run
 */
void setup(void) {
	val = malloc(sizeof(int));
	*val=255;
}

/*
 * function for tearing down the state of the global after
 * EVERY test in the suite is run
 */
void teardown(void) { 
	free(val);
	val = NULL;
}

/*
 * Sample test function that should always work
 */
int test1(void) {
	CUT_ASSERT(1==1);
	return 0;
}

/*
 * Sample test function that may or may not work depending
 * on the whether the global has been initialized
 */
int test2(void) {
	CUT_ASSERT_NULL(val);
	return 0;
}

/*
 * Sample test function that may or may not work depending
 * on the whether the global has been initialized
 */
int test3(void) {
	CUT_ASSERT_NOT_NULL(val);
	CUT_ASSERT(*val == 255);
	return 0;
}

/*
 * Definition of a test suite without fixtures consisting
 * of a single test
 */
CUT_BEGIN_SUITE(suite1) 
CUT_RUN_TEST(test2);
CUT_END_SUITE

/*
 * Definition of a test suite with fixtures consisting
 * of a single test
 */
CUT_BEGIN_SUITE_F(suite2, &setup, &teardown)
CUT_RUN_TEST(test3);
CUT_END_SUITE_F

/*
 * Definition of the test harness, which contains both
 * previously defined suites as well as a single test
 * which is not part of a suite
 */
CUT_BEGIN_TEST_HARNESS 
CUT_RUN_TEST(test1); 
CUT_RUN_SUITE_TESTS(suite1); 
CUT_RUN_SUITE_TESTS(suite2);
CUT_END_TEST_HARNESS
