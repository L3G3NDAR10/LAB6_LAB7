#ifndef LOGGER_H
#define LOGGER_H

typedef enum logLevel {FATAL, ERROR, WARNING, INFO, DEBUG} logLevel;

void init_logger(logLevel logLevel, const char *logfilename);

void write_log(logLevel logLevel, const char *format, ...);

#endif 