#pragma once
#include <iostream>
#include <windows.h>
#include <stdexcept>
#include <string>
#include <map>

typedef void(__stdcall* DllFunction)();

class RuntimeDLLUpdate
{
private:
    /// <summary>
    /// dll handler
    /// </summary>
    HINSTANCE _hGetProcIDDLL;

    /// <summary>
    /// count of your temp dll
    /// </summary>
    int _tempDllCount;

    std::string _tempDllFolder = "TempDLL";

    /// <summary>
    /// Your dll file
    /// </summary>
    std::string _sourceDLLPath;

    std::string _tempDllFilePath;

public:
    RuntimeDLLUpdate(const std::string& sourceDLLPath, std::map<std::string, DllFunction>mapDllFunction) : _sourceDLLPath(sourceDLLPath), m_dllFunction(mapDllFunction)
    {
        CreateDirectoryA(_tempDllFolder.c_str(), NULL);
        std::cout << GetLastError() << std::endl;

        CleanTempDLL();
        ReloadScript();
    }

    /// <summary>
    /// Load dll file from _sourceDLLPath to and assign to _hGetProcIDDLL
    /// </summary>
    /// <returns>return false if fail and true if success</returns>
    bool LoadDLL();

    /// <summary>
    /// Remove Previous assigned dll and assign new dll file
    /// </summary>
    void ReloadScript();

    /// <summary>
    /// Delete all copied dll inside _tempDllFolder = "TempDLL"
    /// </summary>
    void CleanTempDLL();

    /// <summary>
    /// Your dll function
    /// </summary>
    std::map<std::string, DllFunction> m_dllFunction;
};
