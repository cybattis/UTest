# UTest
Small - *Header-only* - unit test framework

## Setup Macro for test suite

```c
    /* Start and initialize a test suite and give it a name */
    UTEST_BEGIN(suite_name)

    /* Usage: RUN_TEST(test_name, function, option)
     *
     * Option:
     *  - UT_PRINT_TEST : Setup a test for a function who print to stdout
     *  - UT_IGNORE : Ignore test
     *
     *  ex: RUN_TEST("Test ko", utest_func_ko, UT_IGNORE);
     *      RUN_TEST("Test ko", utest_func_ko, UT_PRINT_TEST); */
    RUN_TEST(test_name, func, ...)  

    /* Print stats of the test suit */
    UTEST_END()
```

## Macro settings

```c
    /* Setup the output stream */
    UTEST_OUT	STDERR_FILENO
    /* Setup how many sec before timeout */
    UT_TIMEOUT	2
```

## Assert macro

```c
UTEST_ASSERT_STR_EQUAL(actual, expected)
UTEST_ASSERT_STR_NOT_EQUAL(actual, expected)

UTEST_ASSERT_TRUE(value)
UTEST_ASSERT_FALSE(value)

UTEST_ASSERT_INT_EQUAL(actual, expected)
UTEST_ASSERT_INT_NOT_EQUAL(actual, expected)
UTEST_ASSERT_INT_GREATER(actual, expected)
UTEST_ASSERT_INT_GREATER_EQUAL(actual, expected)
UTEST_ASSERT_INT_LESSER(actual, expected)
UTEST_ASSERT_INT_LESSER_EQUAL(actual, expected)

UTEST_ASSERT_PTR_NULL(actual)
UTEST_ASSERT_PTR_NOT_NULL(actual)

```

#### Exemple

```c
int main(void)
{
    UTEST_BEGIN("Suite #1 - Test the tests");
    RUN_TEST("Test ok", utest_func_ok);
    RUN_TEST("Test ko", utest_func_ko);
    RUN_TEST("Test ko", utest_func_ko, UT_IGNORE);
    RUN_TEST("Test sigsegv", utest_sigsegv);
    RUN_TEST("Test sigabort", utest_sigabort);
    RUN_TEST("Test sigfpe", utest_sigfpe);
    RUN_TEST("Test sigpipe", utest_sigpipe);
    RUN_TEST("Test sigill", utest_sigill);
    RUN_TEST("Test timeout", utest_func_timeout);
    UTEST_END();

    UTEST_BEGIN("Suite #2 - ReTest the tests");
    RUN_TEST("Test ok", utest_func_ok);
    RUN_TEST("Test ko", utest_func_ko);
    UTEST_END();

    return (0);
}
```
