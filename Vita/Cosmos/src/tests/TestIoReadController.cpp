#include <tests/TestIoReadController.h>

std::string TestIoReadController::getName (void) const 
{
    return "TestIoReadController";
}

void TestIoReadController::run (Logger & log)
{
    isDirectory_whenCalledWithInvalidPath_returnsFalse(log);
    isDirectory_whenCalledWithValidPath_returnsTrue(log);
    readText_whenCalledWithNonExistingFile_returnsEmptyString(log);
    readText_whenCalledWithExistingFile_returnsSingleWordFromFile(log);
    readText_whenCalledWithExistingFile_returnsSingleLineFromFile(log);
    readText_whenCalledWithExistingFile_returnsMultiLineFromFile(log);
} 

void TestIoReadController::isDirectory_whenCalledWithInvalidPath_returnsFalse (Logger & log) 
{
    std::string invalidPath = "a9/*!-*s8dyhpk;nd!}{}AS|D";

    bool expected = false;
    bool actual = IoReadController::isDirectory(invalidPath);

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestIoReadController::isDirectory_whenCalledWithValidPath_returnsTrue (Logger & log) 
{
    std::string validPath = "ux0:/app";

    bool expected = true;
    bool actual = IoReadController::isDirectory(validPath);

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestIoReadController::readText_whenCalledWithExistingFile_returnsSingleWordFromFile (Logger & log) 
{
    std::string validPath = TEMP_FILE;
    std::string expectedText = "abcdefg";
    IoWriteController::write(validPath, expectedText);

    std::string actualText = IoReadController::readText(validPath);

    UnitTest::equals(true, (expectedText == actualText), __FUNCTION__, log);
}

void TestIoReadController::readText_whenCalledWithExistingFile_returnsSingleLineFromFile (Logger & log) 
{
    std::string validPath = TEMP_FILE;
    std::string expectedText = "hello world lmao";
    IoWriteController::write(validPath, expectedText);

    std::string actualText = IoReadController::readText(validPath);

    UnitTest::equals(true, (expectedText == actualText), __FUNCTION__, log);
}

void TestIoReadController::readText_whenCalledWithExistingFile_returnsMultiLineFromFile (Logger & log) 
{
    std::string validPath = TEMP_FILE;
    std::string expectedText = "hello world\nplaystation vita\nza warudo";
    IoWriteController::write(validPath, expectedText);

    std::string actualText = IoReadController::readText(validPath);

    UnitTest::equals(true, (expectedText == actualText), __FUNCTION__, log);
}

void TestIoReadController::readText_whenCalledWithNonExistingFile_returnsEmptyString (Logger & log) 
{
    std::string invalidPath = "a9///*!-*s8dyhpk;nd!}{}AS|D";
    std::string expectedText = "";

    std::string actualText = IoReadController::readText(invalidPath);

    UnitTest::equals(true, (expectedText == actualText), __FUNCTION__, log);
}