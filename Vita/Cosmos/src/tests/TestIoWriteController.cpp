#include <tests/TestIoWriteController.h>

std::string TestIoWriteController::getName (void) const 
{
    return "TestIoWriteController";
}

TestIoWriteController::TestIoWriteController (void): 
    INVALID_PATH("a9/*!-*s8dyhpk;nd!}{}AS|D"),
    VALID_PATH(TEMP_FILE)
{}

void TestIoWriteController::run (Logger & log)
{
    write_whenCalledWithInvalidPath_returnsFalse(log);
    write_whenCalledWithValidPath_returnsTrue(log);
    append_whenCalledWithInvalidPath_returnsFalse(log);
    append_whenCalledWithValidPath_returnsTrue(log);
}

void TestIoWriteController::write_whenCalledWithInvalidPath_returnsFalse (Logger & log) 
{
    bool expected = false;
    bool actual = IoWriteController::write(INVALID_PATH, "");

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestIoWriteController::write_whenCalledWithValidPath_returnsTrue (Logger & log) 
{
    bool expected = true;
    bool actual = IoWriteController::write(VALID_PATH, "");

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestIoWriteController::append_whenCalledWithInvalidPath_returnsFalse (Logger & log) 
{
    bool expected = false;
    bool actual = IoWriteController::append(INVALID_PATH, "");

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}

void TestIoWriteController::append_whenCalledWithValidPath_returnsTrue (Logger & log)
{
    bool expected = true;
    bool actual = IoWriteController::append(VALID_PATH, "");

    UnitTest::equals(expected, actual, __FUNCTION__, log);
}