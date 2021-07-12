/*
 * File         : main.c
 * Project      : UTest
 * Author       : Stb47 (contact@cbgr.anonaddy.com)
 * -----
 * Created Date : 08.07.2021, 14:54:41
 * Last Modified: 12.07.2021, 23:28:13
 */

#include "src/utest.h"

int main(void)
{
    int i = 5, j = 10;
    char str[] = "le test";
    char str_fail[] = "pas bon";
    char expected[] = "le test";
    
    
    int func_0()
    {
        return 0;
    }

    UTEST_BEGIN("Suite #1 - Test the tests\n");

    RUN_TEST(STR_S(str, expected, "Comparaison string"), IGNORE_TEST());
    RUN_TEST(STR_S(str_fail, expected, "Comparaison string"));

    RUN_TEST(INT_S(i, 5, "name of test"));
    RUN_TEST(INT_S(i, j, "name of test"));

    RUN_TEST(ASSERT_S(i < 10, "i below 10"));
    RUN_TEST(ASSERT_S(i > 10, "i more than 10"), IGNORE_TEST());

    RUN_TEST(ASSERT_S(func_0() == 1, "test name"));
    RUN_TEST(ASSERT_S(func_0() == 0, "test name"));

    UTEST_END();
    putchar('\n');
    ASSERT(i > 10);
    ASSERT_MSG(i > 10, "C'est le message!");

    char *ptr = malloc(sizeof(char));
    if(!ptr)
        printf("malloc fail\n");
    ASSERT_PTR_NULL(ptr);
    
    char *ptr2 = str;
    if(!ptr2)
        printf("Not NULL!\n");
    ASSERT_PTR_NULL(ptr2);
    
    return 0;
}