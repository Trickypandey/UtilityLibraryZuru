#include <iostream>
#include <fstream>
#include <mutex>
#include "Log.h"

namespace Util {

    class LogHandler {
    private:
        std::ofstream m_fileStream;
        std::mutex m_mutex;

    public:
        LogHandler(const std::string& filename) {
            m_fileStream.open(filename, std::ios::app);
            if (!m_fileStream.is_open()) {
                std::cerr << "Failed to open log file: " << filename << std::endl;
            }
        }

        ~LogHandler() {
            if (m_fileStream.is_open()) {
                m_fileStream.close();
            }
        }

        void handleLog(const std::string& logMessage) {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (m_fileStream.is_open()) {
                m_fileStream << logMessage << std::endl;
            }
           
            std::cout << logMessage << std::endl; 
        }
    };

} 
