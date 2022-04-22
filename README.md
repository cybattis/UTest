# Utest & Ulog
Small - *Header-only* - unit test framework

Usage: clone this repo and add ```-I Utest```in your Makefile, and you're good to go.

You can find all information inside the included [man_ulog.md](man_ulog.md) & [man_utest.md](man_utest.md) files.

### Exemple

#### Utest suite

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
