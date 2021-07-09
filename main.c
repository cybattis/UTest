/*
 * File         : main.c
 * Project      : UTest
 * Author       : Stb47 (contact@cbgr.anonaddy.com)
 * -----
 * Created Date : 08.07.2021, 14:54:41
 * Last Modified: 10.07.2021, 00:19:40
 */

#include "src/utest.h"

int main(void)
{
    int i = 5, j = 10;
    char str[] = "le test";
    char str_fail[] = "pas bon";
    char expected[] = "le test";
    
    UTEST_BEGIN();

    RUN_TEST(STR_SUITE(str, expected, "Comparaison string"), TEST_IGNORE());
    RUN_TEST(STR_SUITE(str_fail, expected, "Comparaison string"));

    RUN_TEST(INT_SUITE(i, 5, "name of test"));
    RUN_TEST(INT_SUITE(i, j, "name of test"));

    RUN_TEST(ASSERT_SUITE(i < 10));
    RUN_TEST(ASSERT_SUITE(i > 10), TEST_IGNORE());

    UTEST_END();
    putchar('\n');
    ASSERT(i > 10);
    ASSERT_MSG(i > 10, "C'est le message!");
    
    return 0;
}