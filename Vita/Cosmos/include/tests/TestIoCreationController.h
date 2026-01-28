#ifndef TEST_IO_CREATION_CONTROLLER_H
#define TEST_IO_CREATION_CONTROLLER_H

#include <tests/Test.h>
#include <controllers/IoCreationController.h>
#include <controllers/IoDestructionController.h>

class TestIoCreationController  : public Test
{
    public:
        std::string getName (void) const;
        void run (Logger & log);

    private:
        /* testing: createFile()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: int  <0  "failed to create new file"
        */
        void createFile_whenCalledWithInvalidPath_returnsIntLessThanZero (Logger & log);

        /* testing: createFile()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: int  0  "successfully created new file"
        */
        void createFile_whenCalledWithValidPath_returnsZero (Logger & log);

        /* testing: createDirectory()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: false  "failed to create new directory"
        */
        void createDirectory_whenCalledWithInvalidPath_returnsFalse (Logger & log);

        /* testing: createDirectory()
         * params: [
                directoryPath: "path that does exist"
            ]
         * expected: true  "successfully created new directory"
        */
        void createDirectory_whenCalledWithValidPath_returnsTrue (Logger & log);
};

#endif