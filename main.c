/*
 * File         : main.c
 * Project      : UTest
 * Author       : Stb47 (contact@cbgr.anonaddy.com)
 * -----
 * Created Date : 08.07.2021, 14:54:41
 * Last Modified: 11.07.2021, 15:41:10
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

    RUN_TEST(STR_SUITE(str, expected, "Comparaison string"), IGNORE_TEST());
    RUN_TEST(STR_SUITE(str_fail, expected, "Comparaison string"));

    RUN_TEST(INT_SUITE(i, 5, "name of test"));
    RUN_TEST(INT_SUITE(i, j, "name of test"));

    RUN_TEST(ASSERT_SUITE(i < 10, "i below 10"));
    RUN_TEST(ASSERT_SUITE(i > 10, "i more than 10"), IGNORE_TEST());

    RUN_TEST(ASSERT_SUITE(func_0() == 1, "test name"));
    RUN_TEST(ASSERT_SUITE(func_0() == 0, "test name"));

    UTEST_END();
    putchar('\n');
    ASSERT(i > 10);
    ASSERT_MSG(i > 10, "C'est le message!");
    
    return 0;
}