#include <controllers/IoWriteController.h>

bool IoWriteController::write (const std::string & filePath, const std::string & content)
{
    return IoWriteController::write(filePath, content, std::ios_base::trunc);
}

bool IoWriteController::append (const std::string & filePath, const std::string & content)
{
    return IoWriteController::write(filePath, content, std::ios_base::app);
}

template <typename T>
bool IoWriteController::write (const std::string & filePath, T content, std::ios_base::openmode mode)
{
    bool success = false;
    std::ofstream output(filePath, mode);

    if (output) {
        output << content;
        output.close();
        success = true;
    }

    return success;
}