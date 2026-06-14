#ifndef IO_DESTRUCTION_CONTROLLER_H
#define IO_DESTRUCTION_CONTROLLER_H

#include <controllers/IoReadController.h>
#include <psp2/io/fcntl.h> 
#include <psp2/io/dirent.h> 

class IoDestructionController 
{
    public: 
        /* @name: deleteFile
         * @description: "deletes a single file"
         * @params: [
                directoryPath  string  "full path to directory"
            ]
         * @return: int
                0   "successful"
                <1  "error code"
        */
        static int deleteFile (const std::string & filePath);

        /* @name: deleteDirectory
         * @description: "deletes a directory recursively"
         * @params: [
                directoryPath  string  "full path to directory"
            ]
         * @return: bool
                true   "successfully to delete entire directory"
                false  "failed to delete entire directory"
        */
        static bool deleteDirectory (const std::string & directoryPath);
};

#endif