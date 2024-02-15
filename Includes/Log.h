#include "../Includes/Date.h"
#include "../Includes/String.h"
#ifndef LOG_H
#define LOG_H
using namespace Util;
namespace Util
{
    class Log
    {
    public:
        enum class Level
        {
            LevelError = 0,
            LevelWarning,
            LevelInfo
        };
    private:
        String message;
        Level m_LogLevel;
        Date m_date;


    public:
        Level getLevel() {
            return m_LogLevel;
        }
        Log(const Level& level = Level::LevelError, const Date& date = { 20,12,2023 });
        void SetLogLevel(Level&& level);


        void Warn(const String& message)const;
        void Error(const String&  message)const;
        void Info(const String& message)const;
        void ChangeDate(const Date& date);
    };
}
#endif