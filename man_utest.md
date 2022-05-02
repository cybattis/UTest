# Utest

### Setup Macro for test suite

```c
/* Start and initialize a test suite and give it a name */
#define UTEST_BEGIN(suite_name)

/* Usage: RUN_TEST(test_name, function, option)
 *
 * Option:
 *  - UT_PRINT_TEST : Setup a test for a function who print to stdout
 *  - UT_IGNORE : Ignore test
 *
 *  ex: RUN_TEST("Test ko", utest_func_ko, UT_IGNORE);
 *      RUN_TEST("Test ko", utest_func_ko, UT_PRINT_TEST); */
#define RUN_TEST(test_name, func, ...)  

/* Print stats of the test suit */
#define UTEST_END()
```

### Macro settings

```c
/* Setup the output stream */
#define UTEST_OUT	STDERR_FILENO
/* Setup how many sec before timeout */
#define UT_TIMEOUT	2
```

### Assert macro

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

[Go back](https://github.com/cybattis/UTest)
