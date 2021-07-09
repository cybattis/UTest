/*
 * File         : utest.c
 * Project      : Lists
 * Author       : Stb47 (contact@cbgr.anonaddy.com)
 * -----
 * Created Date : 06.07.2021, 19:49:30
 * Last Modified: 10.07.2021, 00:20:05
 */

#ifndef UTEST_H
#define UTEST_H

#include <stdio.h>

typedef struct utest_storage {
    int number;
    int failed;
    int ignored;
} utest_storage ;
/* struct holding stats of the test suite (nbr, failed, ignored) */
utest_storage utest;    

static int test_status;
static int test_ignored;

#define OK      "\033[32mOK\033[00m"
#define PASS    "\033[32mPASS\033[00m"
#define IGNORE  "\033[34mIGNORE\033[00m"
#define FAIL    "\033[31mFAIL\033[00m"
#define ERROR   "\033[31mERROR\033[00m"

#define UTEST_PRINT(name)   utest_print(__FILE__, __LINE__, name)
#define PRINT_PASS()        printf("%s\n", PASS)
#define PRINT_FAIL()        printf("%s\n", FAIL)
#define PRINT_IGNORE()      printf("%s\n", IGNORE)

#define TRUE    0
#define FALSE   1

#define CHECK(condition, test_suite)            if (condition) test_status = TRUE; else { test_status = FALSE; test_suite; }


/* macros to define a test suite */
#define UTEST_BEGIN()                           utest_begin(utest)                      // Set up the test suite variables
#define UTEST_END()                             utest_end(utest)                        // Print the stats and the result of the test suite
#define TEST_IGNORE()                           test_ignored = TRUE; utest.ignored++
#define RUN_TEST(test, ...)                     test_ignored = FALSE; utest.number++; __VA_ARGS__; test  // Run a test and add it to the pool

#define ASSERT(condition)                       if(condition) {} else fprintf(stderr,"./%s:%d: assert (%s) %s\n", __FILE__, __LINE__ , #condition, ERROR)
#define ASSERT_MSG(condition, message)          if(condition) {} else fprintf(stderr,"./%s:%d: %s %s\n", __FILE__, __LINE__, ERROR, message)
#define ASSERT_SUITE(condition)                 CHECK(condition, utest.failed++) UTEST_PRINT(#condition)
#define ASSERT_UNIT(condition)                  CHECK(condition, (void *)) UTEST_PRINT(#condition)

#define INT_SUITE(actual, expected, name)       CHECK(actual == expected, utest.failed++) UTEST_PRINT(name)
#define INT_UNIT(actual, expected, name)        CHECK(actual == expected, (void *)) UTEST_PRINT(name)

#define STR_SUITE(actual, expected, name)       CHECK(!utest_strcmp(actual, expected), utest.failed++) UTEST_PRINT(name)
#define STR_UNIT(actual, expected, name)        CHECK(!utest_strcmp(actual, expected) UTEST_PRINT(name)


/* Test suit internal */

/* Print test log result */
void utest_print(char const *file, int line, char const *name)
{
    fprintf(stderr, "./%s:%d: test %s: ", file , line, name);
    if (test_ignored == TRUE)
        PRINT_IGNORE();
    else if (test_status == TRUE)
        PRINT_PASS();
    else
        PRINT_FAIL();
}

/* Set up the test suite environment */
void utest_begin(utest_storage utest)
{
    test_ignored = FALSE;
    utest.number = 0;
    utest.failed = 0;
    utest.ignored = 0;
}

/* End the test by printing the stats of the test suite */
void utest_end(utest_storage utest)
{
    putchar('\n');
    printf("-------------------------\n");
    printf("%d Tests %d Failed %d Ignored\n", utest.number, utest.failed, utest.ignored);
    if (utest.failed == 0)
        printf("%s\n", OK);
    else if (utest.number == utest.ignored)
        printf("IGNORED\n");   
    else
        printf("%s\n", FAIL);
}

/* Compare strings */
int utest_strcmp(char const *actual, char const *expected)
{
    for (int i = 0 ; actual[i] && expected[i]; i++) {
		if (actual[i] != expected[i]) {
            return (unsigned char)actual[i] - (unsigned char)expected[i];
        }
    }
    return 0;
}

#endif /* UTEST_H */