#include "../Includes/Log.h"
#include "../Includes/Date.h"
#include <iostream>

using namespace Util;

Log::Log(const Level& level, const Date& date) : m_date(date), m_LogLevel(level) {}
void Log::SetLogLevel(Level&& level)
{
    m_LogLevel = level;
}


void Log::Warn(const String& message) const
{
    if (m_LogLevel >= Level::LevelWarning)

        std::cout << "[Warning]: " << message << "DATE" << m_date.getStrDate() << std::endl;
}

void Log::ChangeDate(const Date& date)
{
    m_date = date;
}

void Log::Error(const String& message) const
{
    if (m_LogLevel >= Level::LevelError)
        std::cout << "[Error]: " << message << "DATE" << m_date.getStrDate() << std::endl;
}

void Log::Info(const String& message) const
{
    if (m_LogLevel >= Level::LevelInfo)
        std::cout << "[Info]: " << message << "DATE" << m_date.getStrDate() << std::endl;
}