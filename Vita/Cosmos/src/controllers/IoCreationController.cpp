#include <controllers/IoCreationController.h>

int IoCreationController::createFile (const std::string & filePath) 
{
    int id = sceIoOpen(filePath.c_str(), SCE_O_WRONLY|SCE_O_CREAT, 0777);
    int statusCode = (id >= 0) ? 0 : id;

    if (id >= 0) 
        sceIoClose(id);
   
    return statusCode;
}

bool IoCreationController::createDirectory (const std::string & filePath)
{
    return (sceIoMkdir(filePath.c_str(), 0777) == 0) ? true : false;
}