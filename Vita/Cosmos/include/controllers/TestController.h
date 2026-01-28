#ifndef TEST_CONTROLLER_H
#define TEST_CONTROLLER_H

#include <controllers/IoDestructionController.h>
#include <tests/Test.h>
#include <vector>

class TestController 
{
    public:
        TestController (void);
        ~TestController (void);

        /* @name: runAllTests
         * @description: runs all tests
         * @params: []
         * @return: none
        */
        void runAllTests (void);

    private:
        std::vector<Test*> testList_;
        Logger log_;
};

#include <tests/TestIoReadController.h>
#include <tests/TestIoWriteController.h>
#include <tests/TestIoCreationController.h>
#include <tests/TestIoDestructionController.h>
#include <tests/TestColor.h>

#endif