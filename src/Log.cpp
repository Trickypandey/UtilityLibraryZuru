#include "../Includes/Log.h"

using  Util::Log;
    //Log::Log(std::string name, const Level& level)
        

    //Log::Log(std::string name, const Level& level, const std::string& filename)
       
    //Log::~Log() 

   

 /*   void Log::printArgs() const {
        std::cout << std::endl;
    }*/

    

    std::string Log::getLevelStringColored(const Level& level) const  {
        std::string strLevel;

        switch (level) {
        case Log::Log::Level::LevelError:
            strLevel = "\033[0;31mError\033[0m"; // Red color
            break;
        case Log::Level::LevelWarning:
            strLevel = "\033[1;35mWarning\033[0m"; // Magenta color
            break;
        case Log::Level::LevelInfo:
            strLevel = "\033[1;36mInfo\033[0m"; // Cyan color
            break;
        }

        return strLevel;
    }

    std::string Log::getLevelString(const Level& level) const {
        std::string strLevel;

        switch (level) {
        case Level::LevelError:
            strLevel = "Error";
            break;
        case Level::LevelWarning:
            strLevel = "Warning";
            break;
        case Level::LevelInfo:
            strLevel = "Info";
            break;
        }

        return strLevel;
    }

