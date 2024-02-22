#ifndef CHRONODATE_H
#define CHRONODATE_H
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

namespace Util {
    class Date {
    private:
        mutable std::chrono::system_clock::time_point timePoint;

    public:
        Date() : timePoint(std::chrono::system_clock::now()) {}

        const std::string getStrDate() const  {
            std::time_t now = std::chrono::system_clock::to_time_t(timePoint);
            std::tm currentTime;
            localtime_s(&currentTime, &now);
            std::ostringstream oss;
            oss << std::put_time(&currentTime, "%d/%m/%Y %H:%M:%S");
            return oss.str();
        }
    };
}
#endif 
