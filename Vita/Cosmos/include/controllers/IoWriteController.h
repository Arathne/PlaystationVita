#ifndef IO_WRITE_CONTROLLER_H
#define IO_WRITE_CONTROLLER_H

#include <fstream>
#include <ios>

class IoWriteController 
{
    public:
        /* @name: write
         * @description: "write text to a file"
         * @params: [
                filePath  string  "full path to directory"
                content   string  "text to be written into a file"
            ]
         * @return: bool
                true   "writing to file successful"
                false  "writing to file failed"
        */
        static bool write (const std::string & filePath, const std::string & content);

        /* @name: append
         * @description: "append text to a file"
         * @params: [
                filePath  string  "full path to directory"
                content   string  "text to be append to a file"
            ]
         * @return: bool
                true   "appending to file successful"
                false  "appending to file failed"
        */
        static bool append (const std::string & filePath, const std::string & content);

    private:
        /* @name: write
         * @description: "write data to a file"
         * @params: [
                filePath  string    "full path to directory"
                content   anything  "data to be append to a file"
                mode      openmode  "mode on how to write data to the file"
            ]
         * @return: bool
                true   "appending to file successful"
                false  "appending to file failed"
            ]
        */
        template <typename T>
        static bool write (const std::string & filePath, T content, std::ios_base::openmode mode);
};

#endif