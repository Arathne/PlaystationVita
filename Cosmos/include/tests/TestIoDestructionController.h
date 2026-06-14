#ifndef TEST_IO_DESTRUCTION_CONTROLLER_H
#define TEST_IO_DESTRUCTION_CONTROLLER_H

#include <controllers/IoCreationController.h>
#include <controllers/IoDestructionController.h>
#include <tests/Test.h>

class TestIoDestructionController : public Test 
{
    public:
        std::string getName (void) const;
        void run (Logger & log);

    private:
        /* testing: deleteFile()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: true  "failed to delete file"
        */
        void deleteFile_whenCalledWithInvalidPath_returnsLessThanZero (Logger & log);

        /* testing: deleteFile()
         * params: [
                directoryPath: "path that does exist"
            ]
         * expected: true  "successfully deleted file"
        */
        void deleteFile_whenCalledWithValidPath_returnsZero (Logger & log);

        /* testing: deleteDirectory()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: false  "failed to delete directory"
        */
        void deleteDirectory_whenCalledWithInvalidPath_returnsFalse (Logger & log);

        /* testing: deleteDirectory()
         * params: [
                directoryPath: "path that does exist"
            ]
         * expected: true  "successfully deleted directory"
        */
        void deleteDirectory_whenCalledWithValidPath_returnsTrue (Logger & log);
};

#endif