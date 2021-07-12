/*
 * File         : utest.h
 * Project      : UTEST
 * Author       : Stb47 (contact@cbgr.anonaddy.com)
 * -----
 * Created Date : 06.07.2021, 19:49:30
 * Last Modified: 12.07.2021, 22:24:08
 */

#ifndef UTEST_H
#define UTEST_H

#include <stdio.h>
#include <stdlib.h>
#ifndef EXCLUDE_LIMITS_H
    #include <limits.h>
#endif

/**********************************\
 *   macros to define test suite
 **********************************/

#define UTEST_BEGIN(name)                           utest_begin(utest, name);                                                                       /** @brief Set up a test suite @param name of the suite, 0 or NULL for empty */    
#define UTEST_END()                                 utest_end(utest)                                                                                /** @brief Set up a test suite */                                      
#define RUN_TEST(test, ...)                         utest.status = TEST_FAIL; utest.number++; __VA_ARGS__; if (utest.status != TEST_IGNORE) test    /** Set up and Run a test and add it to the pool */
#define IGNORE_TEST()                               utest.status = TEST_IGNORE; utest.ignored++

#define CLEANUP_PTR(ptr)                            utest_cleanup_ptr(ptr)

#define ASSERT_S(condition, name)                   CHECK(condition, utest.failed++) UTEST_PRINT(name)
#define INT_S(actual, expected, name)               CHECK(actual == expected, utest.failed++) UTEST_PRINT(name)
#define STR_S(actual, expected, name)               CHECK(!utest_strcmp(actual, expected), utest.failed++) UTEST_PRINT(name)
#define STR_LEN_S(actual, expected, name)           CHECK(!utest_strcmp_len(actual, expected), utest.failed++) UTEST_PRINT(name)

#ifndef NO_DEBUG
    #define ASSERT_MSG(condition, message, ...)     if(condition){} else { fprintf(stderr,"./%s:%d: %s %s\n", __FILE__, __LINE__, ERROR, message); __VA_ARGS__ }
    #define ASSERT(condition, ...)                  ASSERT_MSG(condition, #condition)
    #define ASSERT_PTR_NULL(ptr)                    ASSERT_MSG(!ptr, "pointer not NULL", CLEANUP_PTR(ptr);)

    #define INT_U(actual, expected)                 CHECK(actual == expected) UTEST_PRINT(NULL)
    #define STR_U(actual, expected)                 CHECK(!utest_strcmp(actual, expected) UTEST_PRINT(NULL)
    #define STR_LEN_U(actual, expected)             CHECK(!utest_strcmp_len(actual, expected) UTEST_PRINT(NULL)
#else
    #define ASSERT(condition)                       ((void)0)
    #define ASSERT_MSG(condition, message)          ((void)0)
    #define INT_U(actual, expected)                 ((void)0)
    #define STR_U(actual, expected)                 ((void)0)
    #define STR_LEN_U(actual, expected)             ((void)0)
#endif

#define UTEST_PRINT(name)                           utest_print_s(__FILE__, __LINE__, name)
#define CHECK(condition, update_suite)              if(condition) utest.status = TEST_PASS; else{ utest.status = TEST_FAIL; update_suite; }

/* struct holding data from test suite (name, number, failed, ignored) */
typedef struct UTEST_DATA_SUITE {
    int number;
    int failed;
    int ignored;
    int status;
}   UTEST_DATA;
/* struct holding data from test suite (name, number, failed, ignored) */
UTEST_DATA utest; 

void utest_print_s(char const *file, int line, char const *name);
void utest_begin(UTEST_DATA utest, char const *name);
void utest_end(UTEST_DATA utest);
int utest_strcmp_len(const char const *actual, char const *expected);
int utest_strcmp(char const *actual, char const *expected);
int utest_cleanup_ptr(void *ptr);

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

#endif /* UTEST_H */