#include <stdio.h>
#include <stdlib.h>
#include "input.c"
#include "datatime.c"
#include "convert.c"
#include "log.c"

DateTime dateTime;

int main() {

    do {
        init_logger(INFO, "log.txt");

        DateTime dateTime;
        dateTime.year = ask_int("Enter year: ", "Invalid year\n");
        dateTime.month = ask_int("Enter month: ", "Invalid month\n");
        dateTime.day = ask_int("Enter day: ", "Invalid day\n");
        dateTime.hour = ask_int("Enter hour: ", "Invalid hour\n");
        dateTime.minute = ask_int("Enter minutes: ", "Invalid minutes\n");
        dateTime.second = ask_int("Enter seconds: ", "Invalid seconds\n");
        dateTime.millisecond = ask_int("Enter milliseconds: ", "Invalid milliseconds\n");

        if (date_is_valid(dateTime)) {
            write_log(INFO, "[Date is valid]\n");
            char *datetime_str = get_datetime_str(dateTime);
            printf("%s\n", datetime_str);
            free(datetime_str);
        } else {
            write_log(ERROR, "[Date is invalid]\n");
        }
    } while (ask_yes_no("Do you want to enter new data?", "Invalid input") == YES);
    
    return 0;
}
