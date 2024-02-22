#ifndef LOG_H
#define LOG_H

#include "../Includes/ChronoDateImpl.h"
#include "../Includes/FileHelper.h"
#include <string>
#include <fstream>
#include <iostream>

namespace Util {
    

    class Log {
    public:
        enum class Level {
            LevelError = 0,
            LevelWarning,
            LevelInfo
        };

        Level getLevel() const {
            return m_LogLevel;
        }

        explicit Log(std::string name, const Level& level = Level::LevelWarning) : m_Name{ name }, m_LogLevel{ level }, isFileDumpingTrue{ false } {}
        explicit Log(std::string name, const Level& level, const std::string& filename) : m_Name{ name }, m_LogLevel{ level }, m_Filename{ filename }, isFileDumpingTrue{ true } {}


        ~Log() {
            if (m_OutStream.is_open()) {
                m_OutStream.close();
            }
        }

        std::string getLevelStringColored(const Level& level) const ;
        std::string getLevelString(const Level& level) const;

        template<typename... Args>
        void error(const std::string& message, Args&&... args) const {
            if (m_LogLevel <= Level::LevelError) {
                log(Level::LevelError, message, std::forward<Args>(args)...);
            }
        }

        template<typename... Args>
        void warn(const std::string& message, Args&&... args) const {
            if (m_LogLevel <= Level::LevelWarning) {
                log(Level::LevelWarning, message, std::forward<Args>(args)...);
            }
        }

        template<typename... Args>
        void info(const std::string& message, Args&&... args) const {
            if (m_LogLevel <= Level::LevelInfo) {
                log(Level::LevelInfo, message, std::forward<Args>(args)...);
            }
        }

    private:
        template<typename... Args>
        void log(const Level& level, const std::string& message, Args&&... args) const {
            if (isFileDumpingTrue) {
                m_OutStream.open(m_Filename, std::ios_base::app);
                if (!m_OutStream) {
                    // Failed to open the file, create a new one
                    m_OutStream.open(m_Filename, std::ios_base::out);
                    if (!m_OutStream) {
                        std::cerr << "Error: Failed to create the log file." << std::endl;
                        return;
                    }
                }

                // Log to file
                if (m_OutStream.is_open()) {
                    m_OutStream << m_date.getStrDate() + ": [" + m_Name + "] [" + getLevelString(level) + "]: " << message << " ";
                }
                //if (m_OutStream) {
                //    //m_fileHelper.write(m_filename, "DATE: " + m_date.getStrDate() + " " + logLevelStr + message + "\n");
                //    m_OutStream << m_date.getStrDate() + ": [" + m_Name + "] [" + getLevelString(level) + "]: " << message << " ";
                //}
            }
            std::cout << m_date.getStrDate() << ": [" << m_Name << "] [" << getLevelStringColored(level) << "] : " << message << " ";
            printArgs(std::forward<Args>(args)...);

            if (m_OutStream.is_open()) {
                m_OutStream.close();
            }
        }

        void printArgs() const {
            std::cout << std::endl;
        }


        template<typename T, typename... Args>
        void printArgs(T&& arg, Args&&... args) const {
            if (m_OutStream) {
                m_OutStream << arg << " ";
            }
            std::cout << arg << " ";
            printArgs(std::forward<Args>(args)...);
        }

        std::string m_Name;
        Level m_LogLevel;
        Date m_date{};
        FileHelper m_fileHelper;
        std::string m_Filename;
        bool isFileDumpingTrue;
        mutable std::ofstream m_OutStream;
    };
    //template<typename... Args>
    //inline void Log::error(const std::string& message, Args&&... args) const {
    //    if (m_LogLevel <= Level::LevelError) {
    //        log(Level::LevelError, message, std::forward<Args>(args)...);
    //    }
    //}

    //template<typename... Args>
    //inline void Log::warn(const std::string& message, Args&&... args) const {
    //    if (m_LogLevel <= Level::LevelWarning) {
    //        log(Level::LevelWarning, message, std::forward<Args>(args)...);
    //    }
    //}

    //template<typename... Args>
    //inline void Log::info(const std::string& message, Args&&... args) const {
    //    if (m_LogLevel <= Level::LevelInfo) {
    //        log(Level::LevelInfo, message, std::forward<Args>(args)...);
    //    }
    //}

    //template<typename... Args>
    //inline void Log::log(const Level& level, const std::string& message, Args&&... args) const {
    //    if (isFileDumpingTrue) {
    //        m_OutStream.open(m_Filename, std::ios::app);
    //        if (m_OutStream) {
    //            //m_fileHelper.write(m_filename, "DATE: " + m_date.getStrDate() + " " + logLevelStr + message + "\n");
    //            m_OutStream << m_date.getStrDate() + ": [" + m_Name + "] [" + getLevelString(level) + "]: " << message << " ";
    //        }
    //    }
    //    std::cout << m_date.getStrDate() << ": [" << m_Name << "] [" << getLevelStringColored(level) << "] : " << message << " ";
    //    printArgs(std::forward<Args>(args)...);

    //    if (m_OutStream.is_open()) {
    //        m_OutStream.close();
    //    }
    //}

    //template<typename T, typename... Args>
    //inline void Log::printArgs(T&& arg, Args&&... args) const {
    //    if (m_OutStream) {
    //        m_OutStream << arg << " ";
    //    }
    //    std::cout << arg << " ";
    //    printArgs(std::forward<Args>(args)...);
    //}
}

#endif 
