#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <fstream>
#include <iostream>
#include <string>
#include "../Includes/Exception.h"

namespace Util {

    class FileHelper {
    public:
        FileHelper() = default;
        explicit FileHelper(const std::string& filename) : filename_{ filename } {}
        ~FileHelper() { close(); }

        void open(const std::string& fname, bool truncate = false);
        void close();
        bool write(const std::string& data);
        std::string getFileName() const { return filename_; }

        static bool CreateFile(const std::string& filename);
        static FileHelper& instance();
    private:
        std::ofstream fileStream;
        std::string filename_;
    };

}

#endif
