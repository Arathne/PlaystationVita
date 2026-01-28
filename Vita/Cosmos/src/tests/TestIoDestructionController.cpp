#include <tests/TestIoDestructionController.h>

std::string TestIoDestructionController::getName (void) const 
{
    return "TestIoDestructionController";
}

void TestIoDestructionController::run (Logger & log)
{
    deleteFile_whenCalledWithInvalidPath_returnsLessThanZero(log);
    deleteFile_whenCalledWithValidPath_returnsZero(log);
    deleteDirectory_whenCalledWithInvalidPath_returnsFalse(log);
    deleteDirectory_whenCalledWithValidPath_returnsTrue(log);
}

void TestIoDestructionController::deleteFile_whenCalledWithInvalidPath_returnsLessThanZero (Logger & log) 
{
    std::string invalidPath = "lka/?!///!alskjdz";
    int statusCode = IoDestructionController::deleteFile(invalidPath);

    bool expected = true;
    bool actual = (statusCode < 0) ? true : false;

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestIoDestructionController::deleteFile_whenCalledWithValidPath_returnsZero (Logger & log)
{
    std::string validPath = TEMP_FILE;
    IoCreationController::createFile(validPath);
    int statusCode = IoDestructionController::deleteFile(validPath);

    bool expected = true;
    bool actual = (statusCode == 0) ? true : false;

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}
        
void TestIoDestructionController::deleteDirectory_whenCalledWithInvalidPath_returnsFalse (Logger & log)
{
    std::string invalidPath = "lka/?!///!alskjdz";

    bool expected = false;
    bool actual = IoDestructionController::deleteDirectory(invalidPath);
    
    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestIoDestructionController::deleteDirectory_whenCalledWithValidPath_returnsTrue (Logger & log)
{

    std::string validPath = std::string(DATA_FOLDER) + "/TestDeleteDirectory";
    IoCreationController::createDirectory(validPath);

    bool expected = true;
    bool actual = IoDestructionController::deleteDirectory(validPath);

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}