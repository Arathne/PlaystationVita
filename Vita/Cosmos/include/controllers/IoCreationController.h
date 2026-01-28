#ifndef IO_CREATION_CONTROLLER_H
#define IO_CREATION_CONTROLLER_H

#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h> 
#include <string>

class IoCreationController 
{
    public:
        /* @name: createFile
         * @description: "creates empty file"
         * @params: [
                directoryPath  string  "full path to directory"
            ]
         * @return: int
                0   "successful"
                <1  "error code"
        */
        static int createFile (const std::string & filePath);

        /* @name: createDirectory
         * @description: "creates empty directory"
         * @params: [
                directoryPath  string  "full path to directory"
            ]
         * @return: bool
                true   "successfully created empty directory"
                false  "failed to create empty directory"
        */
        static bool createDirectory (const std::string & filePath);
};

#endif