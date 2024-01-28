#pragma once

namespace Utility
{
    string ToString(wstring str);
    wstring ToWString(string str);

    vector<string> SplitString(string origin, const string& tok, const bool& includeLast = true);

    bool ExistDirectory(string file);

    wstring GetExtension(wstring file);
    string GetFileName(string file);
    string GetFileNameWithoutExtension(string file);

    void CreateFolders(string file);
}