#include "RuntimeDLLUpdate.h"

bool RuntimeDLLUpdate::LoadDLL() {
    _hGetProcIDDLL = LoadLibraryA(_tempDllFilePath.c_str());

    if (!_hGetProcIDDLL) {
        std::cout << "could not locate the dynamic library" << std::endl;
        return false;
    }

    for (auto& tempFunc : m_dllFunction)
    {
        tempFunc.second = (DllFunction)GetProcAddress(_hGetProcIDDLL, tempFunc.first.c_str());
        if (!tempFunc.second) {
            std::cout << "could not locate the function" << std::endl;
            return false;
        }
    }
    _tempDllCount++;
    return true;
}

void RuntimeDLLUpdate::CleanTempDLL()
{
    std::string command = "del /S /q ";
    system(command.append(_tempDllFolder).append("\\*").c_str());
}

void RuntimeDLLUpdate::ReloadScript()
{
    FreeLibrary(_hGetProcIDDLL);

    std::string fileName = _sourceDLLPath;

    const size_t last_slash_idx = fileName.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        fileName.erase(0, last_slash_idx + 1);
    }

    std::string filePath = _tempDllFolder;
    filePath = filePath.append("/").append(fileName);
    filePath.insert(filePath.length() - 4, std::to_string(_tempDllCount));
    CopyFileA(_sourceDLLPath.c_str(), filePath.c_str(), false);

    _tempDllFilePath = filePath;

    LoadDLL();
}