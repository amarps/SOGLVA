#pragma once
#include "RuntimeDLLUpdate.h"

void ScriptLoader()
{

    std::map<std::string, DllFunction> myMap;
    myMap["UpdateMePlease"] = NULL;

    RuntimeDLLUpdate rtc("D:/projects/C++/RuntimeCompileScript/Debug/scripting/scripting.dll", myMap);

    while (true)
    {
        rtc.m_dllFunction["UpdateMePlease"]();
        std::string recompile = "";
        std::cin >> recompile;
        if (recompile == "a")
        {
            rtc.ReloadScript();
        }
    }
}
