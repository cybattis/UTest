/*
 * File         : utest.c
 * Project      : src
 * Author       : Stb47 (contact@cbgr.anonaddy.com)
 * -----
 * Created Date : 08.07.2021, 16:05:47
 * Last Modified: 13.07.2021, 11:39:13
 */

#include "utest.h"

/****************************\
 *    Test suit internal
 ****************************/

/* Print test log result */
void utest_print_s(char const *file, int line, char const *actual, char const *expected, char const *name)
{
    fprintf(stderr, "./%s:%d: %s: ", file , line, name);
    if (utest.status == TEST_IGNORE)
        fprintf(stderr, "%s\n", IGNORE);
    else if (utest.status == TEST_PASS)
        fprintf(stderr, "%s\n", PASS);
    else 
        fprintf(stderr, "%s Expected '%s' was '%s'\n", FAIL, expected, actual);
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

int utest_strcmp_len(const char const *actual, char const *expected)
{
    
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

/****************************\
 *    Function test tools 
 ****************************/

void utest_cleanup_ptr(void *ptr)
{
    ptr = NULL;
    free(ptr);
    return ;
}