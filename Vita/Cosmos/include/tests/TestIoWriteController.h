#ifndef TEST_IO_WRITE_CONTROLLER_H
#define TEST_IO_WRITE_CONTROLLER_H

#include <tests/Test.h>
#include <controllers/IoWriteController.h>
#include <controllers/IoDestructionController.h>

class TestIoWriteController : public Test 
{
    public:
        TestIoWriteController (void);

        std::string getName (void) const;
        void run (Logger & log);
    
    private:
        const std::string INVALID_PATH;
        const std::string VALID_PATH;

        /* testing: write()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: false  "write failed"
        */
        void write_whenCalledWithInvalidPath_returnsFalse (Logger & log);

        /* testing: write()
         * params: [
                directoryPath: "path that does exist"
            ]
         * expected: true  "write successful"
        */
        void write_whenCalledWithValidPath_returnsTrue (Logger & log);

        /* testing: append()
         * params: [
                directoryPath: "path that does not exist"
            ]
         * expected: false  "append failed"
        */
        void append_whenCalledWithInvalidPath_returnsFalse (Logger & log);

        /* testing: append()
         * params: [
                directoryPath: "path that does exist"
            ]
         * expected: true  "append successful"
        */
        void append_whenCalledWithValidPath_returnsTrue (Logger & log);
};

#endif