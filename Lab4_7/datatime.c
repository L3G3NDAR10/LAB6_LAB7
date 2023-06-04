#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "datatime.h"

bool date_is_valid(DateTime dateTime)
{
    struct tm tm = {0};
    tm.tm_year = dateTime.year - 1900;
    tm.tm_mon = dateTime.month - 1;
    tm.tm_mday = dateTime.day;
    time_t t = mktime(&tm);
    if (tm.tm_year != dateTime.year - 1900 &&
        tm.tm_mon != dateTime.month - 1 &&
        tm.tm_hour != dateTime.hour &&
        tm.tm_min != dateTime.minute &&
        tm.tm_sec != dateTime.second)
    {
        return false;
    }
    return (t != (time_t)-1);
}

WeekDay get_weekday(DateTime dateTime)
{
    struct tm tm = {0};
    tm.tm_year = dateTime.year - 1900;
    tm.tm_mon = dateTime.month - 1;
    tm.tm_mday = dateTime.day;
    time_t t = mktime(&tm);
    if (t == (time_t)-1)
    {
        errno = EINVAL;
        return -1;
    }
    return tm.tm_wday;
}

char *get_month(DateTime dateTime)
{
    static const char *months[] = {
        "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
        "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    if (dateTime.month < 1 || dateTime.month > 12)
    {
        errno = EINVAL;
        return NULL;
    }
    return (char *)months[dateTime.month - 1];
}

char *get_weekday_str(WeekDay weekDay)
{
    static const char *weekdays[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"};
    if (weekDay < SUNDAY || weekDay > SATURDAY)
    {
        errno = EINVAL;
        return NULL;
    }
    return (char *)weekdays[weekDay];
}

char *get_datetime_str(DateTime dateTime)
{
    char *result = (char *)malloc(30 * sizeof(char));
    if (result == NULL)
    {
        return NULL;
    }
    sprintf(result, "%s, %d %s %d %02d:%02d:%02d.%03d",
            get_weekday_str(get_weekday(dateTime)),
            dateTime.day,
            get_month(dateTime),
            dateTime.year,
            dateTime.hour,
            dateTime.minute,
            dateTime.second,
            dateTime.millisecond);
    return result;
}
