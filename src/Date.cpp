//#include <iostream>
//#include "../Includes/Date.h"
//#include "../Includes/Exception.h"
//
//
//using namespace Util;
//
//Date::Date(int newDay, int newMonth, int newYear) :day{ newDay }, month{ newMonth }, year{newYear} {
//	isLeapYear();
//	if (newYear < 1 || newMonth > 12 || newMonth < 1 || daysInMonth(newMonth) < newDay)
//	{
//		throw  MyException("Date: Provided Date format is not correct!");
//	}
//
//	if (isDateUpdated(*this)) {
//		previousDate = { day, month, year };
//		//convertTheString();
//		isCacheTrue = false;
//	}
//}
//
//const std::string Date::getStrDate()  {
//	if (!isCacheTrue)
//	{
//		convertTheString();
//	}
//	return cache;
//}
//
//void Date::convertTheString() {
//
//	/*cache[0] = '0' + day / 10;
//	cache[1] = '0' + day % 10;
//	cache[2] = '/';
//	cache[3] = '0' + month / 10;
//	cache[4] = '0' + month % 10;
//	cache[5] = '/';
//	cache[6] = '0' + year / 1000;
//	cache[7] = '0' + (year / 100) % 10;
//	cache[8] = '0' + (year / 10) % 10;
//	cache[9] = '0' + year % 10;*/
//	cache.clear();
//	cache.append(std::to_string( day));
//	cache.append("/");
//	cache.append(std::to_string(month));
//	cache.append("/");
//	cache.append(std::to_string(year));
//	isCacheTrue = true;
//
//}
//
//void Date::isLeapYear() {
//	isLeapYearFlag = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
//}
//
//bool Date::isDateUpdated(const Date& d) {
//	if (!previousDate.isFirstCallDone) {
//		previousDate.isFirstCallDone = true;
//		return true;
//	}
//	return ((previousDate.preDay == d.day) && (previousDate.preMonth == d.month) && (previousDate.preYear == d.year)) ? false : true;
//}
//void Date::addDays(int numDays) {
//
//	day += numDays;
//	std::cout << day << "\n";
//
//	while (day > daysInMonth(month)) {
//		day -= daysInMonth(month);
//		addMonths(1);
//	}
//}
//
//void Date::addMonths(int numMonths) {
//
//	month += numMonths;
//
//	while (month > 12) {
//		month -= 12;
//		addYears(1);
//	}
//}
//
//void Date::addYears(int numYears) {
//
//	year += numYears;
//}
//
//int Date::daysInMonth(int month) const {
//	switch (month) {
//	case 4:
//	case 6:
//	case 9:
//	case 11:
//		return 30;
//	case 2:
//		return isLeapYearFlag ? 29 : 28;
//	default:
//		return 31;
//	}
//}
//void Date::appendInstAsChar(const int& number) {
//	switch (number) {
//	case 1: {
//		cache.append("1");
//	} break;
//	case 2: {
//		cache.append("2");
//	} break;
//	case 3: {
//		cache.append("3");
//	} break;
//	case 4: {
//		cache.append("4");
//	} break;
//	case 5: {
//		cache.append("5");
//	} break;
//	case 6: {
//		cache.append("6");
//	} break;
//	case 7: {
//		cache.append("7");
//	} break;
//	case 8: {
//		cache.append("8");
//	} break;
//	case 9: {
//		cache.append("9");
//	} break;
//	case 0: {
//		cache.append("0");
//	} break;
//	default: {
//		cache.append("0");
//	} break;
//	}
//}
//void Date::operator=(const Date& newdate) {
//	isLeapYear();
//	if (isDateUpdated(newdate)) {
//		previousDate = { newdate.day, newdate.month, newdate.year };
//		previousDate.preMonth = newdate.day;
//		previousDate.preYear = newdate.day;
//		this->day = newdate.day;
//		this->month = newdate.month;
//		this->year = newdate.year;
//		//convertTheString();
//		previousDate.isFirstCallDone = true;
//		isCacheTrue = false;
//	}
//
//}
//
