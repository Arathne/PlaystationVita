#ifndef TEST_UNIT_H
#define TEST_UNIT_H

#include <Logger.h>

// templates keep telling me its undefined. rip

class UnitTest
{
    public:
        /* @name: equals
         * @description: "compares two values and updates log depending on result"
         * @params: [
                expected      bool     "target"
                actual        bool     "value received from tests"
                functionName  string   "name of function"
                log           Logger   "output for test result"
            ]
         * @return: none
        */
        static void equals (bool expected, bool actual, std::string functionName, Logger & log);
};

#endif