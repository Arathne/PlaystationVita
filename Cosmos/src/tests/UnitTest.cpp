#include <tests/UnitTest.h>

void UnitTest::equals (bool expected, bool actual, std::string functionName, Logger & log)
{
    std::string result = (expected == actual) ? "success" : "failed";
    std::string output = result + " :: " + functionName;
    log.add(output);
}