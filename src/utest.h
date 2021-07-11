/*
 * File         : utest.c
 * Project      : Lists
 * Author       : Stb47 (contact@cbgr.anonaddy.com)
 * -----
 * Created Date : 06.07.2021, 19:49:30
 * Last Modified: 11.07.2021, 15:37:37
 */

#ifndef UTEST_H
#define UTEST_H

#include <stdio.h>

/* struct holding data from test suite (name, number, failed, ignored) */
typedef struct UTEST_DATA_SUITE {
    char const *test_suite_name;
    int number;
    int failed;
    int ignored;
    int status;
}   UTEST_DATA;
/* struct holding data from test suite (name, number, failed, ignored) */
UTEST_DATA utest;    

#ifdef NO_COLOR
    #define OK      "OK"
    #define PASS    "PASS"
    #define IGNORE  "IGNORE"
    #define FAIL    "FAIL"
    #define ERROR   "ERROR"
#else
    #define OK      "\033[32mOK\033[00m"
    #define PASS    "\033[32mPASS\033[00m"
    #define IGNORE  "\033[34mIGNORE\033[00m"
    #define FAIL    "\033[31mFAIL\033[00m"
    #define ERROR   "\033[31mERROR\033[00m"
#endif

#define TEST_FAIL   0
#define TEST_PASS   1
#define TEST_IGNORE 2

#define UTEST_PRINT(name)                       utest_print(__FILE__, __LINE__, name)
#define CHECK(condition, update_suite)          if (condition) utest.status = TEST_PASS; else { utest.status = TEST_FAIL; update_suite; }


/* macros to define a test suite */

#define UTEST_BEGIN(name)                       utest_begin(utest, name);                                       /** @brief Set up a test suite @param name of the suite, 0 or NULL for empty */    
#define UTEST_END()                             utest_end(utest)                                                /** @brief Set up a test suite */
#define IGNORE_TEST()                           utest.status = TEST_IGNORE; utest.ignored++                                                   
#define RUN_TEST(test, ...)                     utest.status = TEST_FAIL; utest.number++; __VA_ARGS__; if (utest.status != TEST_IGNORE) test  /** Set up and Run a test and add it to the pool */

#define ASSERT_SUITE(condition, name)           CHECK(condition, utest.failed++) UTEST_PRINT(name)

#define INT_SUITE(actual, expected, name)       CHECK(actual == expected, utest.failed++) UTEST_PRINT(name)
#define INT_UNIT(actual, expected, name)        CHECK(actual == expected, (void *)) UTEST_PRINT(name)

#define STR_SUITE(actual, expected, name)       CHECK(!utest_strcmp(actual, expected), utest.failed++) UTEST_PRINT(name)
#define STR_UNIT(actual, expected, name)        CHECK(!utest_strcmp(actual, expected) UTEST_PRINT(name)

#ifndef NO_DEBUG
    #define ASSERT(condition)                   if(condition) {} else fprintf(stderr,"./%s:%d: assert (%s) %s\n", __FILE__, __LINE__ , #condition, ERROR)
    #define ASSERT_MSG(condition, message)      if(condition) {} else fprintf(stderr,"./%s:%d: %s %s\n", __FILE__, __LINE__, ERROR, message)
    #define ASSERT_UNIT(condition)              CHECK(condition, (void *)) UTEST_PRINT(#condition)
#else
    #define ASSERT(condition)                   ((void)0)
    #define ASSERT_MSG(condition, message)      ((void)0)
    #define ASSERT_UNIT(condition)              ((void)0)
#endif


/****************************\
 *    Test suit internal
 ****************************/

/* Print test log result */
void utest_print(char const *file, int line, char const *name)
{
    fprintf(stderr, "./%s:%d: %s: ", file , line, name);
    if (utest.status == TEST_IGNORE)
        printf("%s\n", IGNORE);
    else if (utest.status == TEST_PASS)
        printf("%s\n", PASS);
    else
        printf("%s\n", FAIL);
}

void utest_begin(UTEST_DATA utest, char const *name)
{
    if(name) 
        printf("%s\n", name);
    utest.number = 0;
    utest.failed = 0;
    utest.ignored = 0;
    utest.status = TEST_FAIL;
}

/* End a test suite and print the result */
void utest_end(UTEST_DATA utest)
{
    putchar('\n');
    printf("-------------------------\n");
    printf("%d Tests %d Failed %d Ignored\n", utest.number, utest.failed, utest.ignored);
    if (utest.failed == 0)
        printf("%s\n", OK);
    else if (utest.number == utest.ignored)
        printf("%s\n", IGNORE);
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