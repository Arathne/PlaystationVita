#ifndef TEST_H
#define TEST_H

#include <tests/UnitTest.h>
#include <Logger.h>

class Test 
{
    public:
        virtual ~Test (void) {}

        /* @name: run
         * @description: runs tests associated with the class 
         * @params: [
                log  Logger  "test results will be added here"
            ]
         * @return: none
        */
        virtual void run (Logger & log) = 0;

        /* @name: getName
         * @description: get name of the test 
         * @params: []
         * @return: string
                "name of the test"
        */
        virtual std::string getName (void) const = 0;
};

#endif