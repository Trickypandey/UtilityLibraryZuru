#include "../Includes/FileHelper.h"

using namespace Util;

void FileHelper::open(const std::string& fname, bool truncate) {
    close();

    filename_ = fname;
    std::ios_base::openmode mode = std::ios_base::app;

    if (truncate) {
        
        mode = std::ios_base::out | std::ios_base::trunc;
    }

    fileStream.open(fname, mode);

    if (!fileStream.is_open()) {
        throw MyException("Failed opening file " + fname + " for writing");
    }
}

bool FileHelper::write(const std::string& data) {
    if (!fileStream.is_open()) {
        std::cerr << "Error: File is not open for writing: " << filename_ << std::endl;
        return false;
    }
    fileStream << data << "\n";
    return true;
}

void FileHelper::close() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

bool FileHelper::CreateFile(const std::string& filename) {
    std::ofstream file(filename);
    return file.is_open();
}

FileHelper& FileHelper::instance() {
    static FileHelper s_instance;
    return s_instance;
}
