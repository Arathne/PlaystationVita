#ifndef LOGGER_H
#define LOGGER_H

#include <controllers/IoWriteController.h>
#include <vector>

class Logger 
{
    public:
        Logger (void);
        Logger (size_t max_size);

        /* @name: add
         * @description: "adds a new message to log"
         * @params: [
                message  string  "entry to be added to log"
            ]
         * @return: none
        */
        void add (const std::string & message);

        /* @name: writeToFile
         * @description: "creates a text file containing log information"
         * @params: [
                filePath  string  "full path of text file to be written"
            ]
         * @return: none
        */
        void writeToFile (const std::string & filePath);

    private:
        std::vector<std::string> log_;
        size_t size_;

        /* @name: toString
         * @description: "creates a text file containing log information"
         * @params: []
         * @return: string  
                "all log information converted to a string"
        */
        std::string toString (void) const;
};

#endif