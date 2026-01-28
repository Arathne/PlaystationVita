#include <controllers/TestController.h>

TestController::TestController (void) 
{
    testList_.push_back(new TestIoReadController());
    testList_.push_back(new TestIoWriteController());
    testList_.push_back(new TestIoCreationController());
    testList_.push_back(new TestIoDestructionController());
    testList_.push_back(new TestColor());
}

TestController::~TestController (void) 
{
    for(int i = 0; i < testList_.size(); i++)
    {
        Test* testObj = testList_.at(i);
        delete testObj;
    }
}

 void TestController::runAllTests (void) 
 {
    for(int i = 0; i < testList_.size(); i++)
    {
        Test* testObj = testList_.at(i);
        log_.add(testObj->getName());
        testObj -> run(log_);
        log_.add("");
    }
    IoDestructionController::deleteFile(TEMP_FILE);
    log_.writeToFile(std::string(DATA_FOLDER) + "/TestResults.txt");
 }