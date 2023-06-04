#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#define STR_logLevel(logLevel) logLevel == FATAL ? "FATAL" : \
    logLevel == ERROR ? "ERROR" : \
    logLevel == WARNING ? "WARNING" : \
    logLevel == INFO ? "INFO" : \
    logLevel == DEBUG ? "DEBUG" : "UNDEFINED"

logLevel CurrentlogLevel;
FILE *logfile;

void init_logger(logLevel logLevel, const char *logfilename)
{
    CurrentlogLevel = logLevel;
    logfile = fopen(logfilename, "a");
    if (logfile == NULL)
    {
        printf("FATAL: could not open log file");
        exit(1);
    }
}

void print_time() 
{
    time_t now;
    time(&now);
    struct tm *tm_info = localtime(&now);
    char buffer[26];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    fputs(buffer, logfile);
}

void write_log(logLevel logLevel, const char *format, ...)
{
    if (logLevel <= CurrentlogLevel)
    {
        print_time();
        va_list args;
        va_start(args, format);
        vfprintf(logfile, format, args);
        va_end(args);
        fflush(logfile);
    }
}