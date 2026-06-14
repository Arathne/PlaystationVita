#include <controllers/IoDestructionController.h>

int IoDestructionController::deleteFile (const std::string & filePath) 
{
    return sceIoRemove(filePath.c_str());
}

bool IoDestructionController::deleteDirectory (const std::string & directoryPath)
{
    bool deleteSuccessful = false;
    
    if (IoReadController::isDirectory(directoryPath))
    {
        SceUID directoryId = sceIoDopen(directoryPath.c_str());

        SceIoDirent currentFile;
        while (sceIoDread(directoryId, &currentFile) > 0) // go through every child in directory
        {
            std::string fullPath = directoryPath + "/" + std::string(currentFile.d_name);

            if (IoReadController::isDirectory(currentFile.d_stat.st_mode)) // if directory -- delete recursively
            {
                IoDestructionController::deleteDirectory(fullPath);
            }
            else                                                           // if not directory -- delete
                IoDestructionController::deleteFile(fullPath);
        }

        sceIoDclose(directoryId);
        int statusCode = sceIoRmdir(directoryPath.c_str());
        deleteSuccessful = (statusCode == 0) ? true : false;
    }

    return deleteSuccessful;
}