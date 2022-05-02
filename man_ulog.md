# Ulog

### Macro settings

```c
/*
* Set the date and time format of log message
*
*     NO_DATE - 15:48:59:53 [INFO] lorem ipsum test
*     NO_TIME - [INFO] lorem ipsum test
*     DATE    - 2022:04:15 15:49:52:03 [INFO] lorem ipsum test
* */
#define TIME_FORMAT		NO_DATE

/*
* Set which log level to print
* All level below the set will not be print
*
*     LOG_OFF
*     NO_WARNING - Do not print Warning level and below
*     NO_DEBUG
*     NO_INFO
*     LOG_ALL
* */
#define LOG_LEVEL		LOG_ALL

/*
* Set the output stream
* */
#define ULOG_OUT		STDERR_FILENO
```

[Go back](https://github.com/cybattis/UTest)
