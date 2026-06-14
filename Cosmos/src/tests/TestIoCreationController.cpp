#include <tests/TestIoCreationController.h>

std::string TestIoCreationController::getName (void) const 
{
    return "TestIoCreationController";
}

void TestIoCreationController::run (Logger & log)
{
    createFile_whenCalledWithInvalidPath_returnsIntLessThanZero(log);
    createFile_whenCalledWithValidPath_returnsZero(log);
    createDirectory_whenCalledWithInvalidPath_returnsFalse(log);
    createDirectory_whenCalledWithValidPath_returnsTrue(log);
}

void TestIoCreationController::createFile_whenCalledWithInvalidPath_returnsIntLessThanZero (Logger & log)
{
    std::string invalidPath = "//asldkma**&^%/1/";
    int statusCode = IoCreationController::createFile(invalidPath);

    int expected = true;
    int actual = (statusCode < 0) ? true : false;

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestIoCreationController::createFile_whenCalledWithValidPath_returnsZero (Logger & log)
{
    std::string validPath = TEMP_FILE;
    IoDestructionController::deleteFile(validPath);
    int statusCode = IoCreationController::createFile(validPath);

    int expected = true;
    int actual = (statusCode == 0) ? true : false;

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestIoCreationController::createDirectory_whenCalledWithInvalidPath_returnsFalse (Logger & log)
{
    std::string invalidPath = "//asldkma**&^%/1/";

    bool expected = false;
    bool actual = IoCreationController::createDirectory(invalidPath);

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestIoCreationController::createDirectory_whenCalledWithValidPath_returnsTrue (Logger & log)
{
    std::string validPath = std::string(DATA_FOLDER) + "/TestCreateDirectory";
    IoDestructionController::deleteDirectory(validPath);

    bool expected = true;
    bool actual = IoCreationController::createDirectory(validPath);
    IoDestructionController::deleteDirectory(validPath);
    
    UnitTest::equals(expected, actual, __FUNCTION__, log);
}