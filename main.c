/*
 * File         : main.c
 * Project      : UTest
 * Author       : Stb47 (contact@cbgr.anonaddy.com)
 * -----
 * Created Date : 08.07.2021, 14:54:41
 * Last Modified: 08.07.2021, 16:11:29
 */

#include "src/utest.h"

int main(void)
{
    int i = 5, j = 10;
    char str[] = "le test";
    char str_fail[] = "pas bon";
    char expected[] = "le test";
    
    string_test(str_fail, expected);
    putchar('\n');
    UTEST_INT(i, 5, '3');
    UTEST_INT(i, j, '4');
    putchar('\n');
    UTEST_ASSERT(i < 10, '5');
    UTEST_ASSERT(i > 10, '6');
    putchar('\n');
    ASSERT(i > 10);

    return 0;
}