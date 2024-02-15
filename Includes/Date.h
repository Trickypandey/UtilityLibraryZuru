#include "../Includes/String.h"
#ifndef DATE_H
#define DATE_H

namespace Util {
    //char* getstringval(Date d1);
    class Date {
    private:
        struct PreviousDate {
            int preDay;
            int preMonth;
            int preYear;
            bool isFirstCallDone = false;
        };

        int day;
        int month;
        int year;
        String cache;
        bool isLeapYearFlag;
        PreviousDate previousDate;


    public:
        Date(int newDay = 1, int newMonth = 1, int newYear = 2000);

        int getDay() const {
            return day;
        }

        int getMonth() const {
            return month;
        }

        int getYear() const {
            return year;
        }

        void setDay(int newDay) {
            day = newDay;
        }

        void setMonth(int newMonth) {
            month = newMonth;
        }

        void setYear(int newYear) {
            year = newYear;
        }

        void isLeapYear();
        bool isDateUpdated();
        void convertTheString();
        const String getStrDate() const;
        void addDays(int numDays);
        void addMonths(int numMonths);
        void addYears(int numYears);
        void appendInstAsChar(const int& number);
        int daysInMonth(int month) const;
    };
}

#endif
