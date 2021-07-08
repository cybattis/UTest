/*
 * File         : utest.c
 * Project      : Lists
 * Author       : Stb47 (contact@cbgr.anonaddy.com)
 * -----
 * Created Date : 06.07.2021, 19:49:30
 * Last Modified: 08.07.2021, 16:13:11
 */

#ifndef UTEST_H
#define UTEST_H

#include <stdio.h>
#include <assert.h>
#include <string.h>

#define PASS "\033[32mPASS\033[00m"
#define FAIL "\033[31mFAIL\033[00m"

#define UTEST_BEGIN() 

#define ASSERT(chk) (chk ? (void) (0) : \
    fprintf(stderr,"%s:%d %s: assert (%s) %s.\n", __FILE__ , __LINE__ , __func__ , #chk, FAIL))

#define UTEST_ASSERT(chk, id) (chk ? printf("Test %c %s\n", id, PASS) : printf("Test %c %s\n", id, FAIL))

#define UTEST_STR(actual, expected, id) \
    (!strcmp(actual, expected) ? fprintf(stderr, "Test %s %s\n", id, PASS) : \
    fprintf(stderr, "Test %s %s expected '%s' was '%s'\n", id, FAIL, expected, actual))

#define UTEST_INT(actual, expected, id) \
    (actual == expected ? fprintf(stderr, "Test %c %s\n", id, PASS) : \
    fprintf(stderr, "Test %c %s expected '%d' was '%d'\n", id, FAIL, expected, actual))
    
#define UTEST_END() 

void string_test (char const *actual, char const *expected) 
{
    UTEST_STR(actual, expected, __func__);
}

#endif /* UTEST_H */