#include <controllers/IoReadController.h>

bool IoReadController::isDirectory (const std::string & directoryPath)
{
    SceIoStat stats;
    int statusCode = sceIoGetstat(directoryPath.c_str(), &stats);

    if (statusCode == 0)
        return IoReadController::isDirectory(stats.st_mode);

    return false;
}

bool IoReadController::isDirectory (const SceMode & mode)
{
    if ((mode & SCE_S_IFDIR) == SCE_S_IFDIR) // check to see if directory flag is set
        return true;

    return false;
}

std::string IoReadController::readText (const std::string & filePath)
{
    std::ifstream inputStream(filePath);
    std::stringstream stringStream;
    
    if (inputStream) 
        stringStream << inputStream.rdbuf();

    return stringStream.str();
}