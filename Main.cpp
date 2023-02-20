/*
`....
`..   `..     `..        `..
`..            `..        `..
`..       `... `.....`... `.....
`..            `..        `..
`..   `..     `..        `..
`....
Aidan Shields
https://www.joelonsoftware.com/2003/10/08/the-absolute-minimum-every-software-developer-absolutely-positively-must-know-about-unicode-and-character-sets-no-excuses/
https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/setmode?view=msvc-160
(https://stackoverflow.com/questions/2492077/output-unicode-strings-in-windows-console-app)
(http://archives.miloush.net/michkap/archive/2008/03/18/8306597.html)
*/

#include <iostream>     // wcout
#include <cstdlib>      // system
#include <io.h>         // _setmode()
#include <fcntl.h>      // _setmode()

int TestSystemColours()
{
    //std::system("COLOR FFF");
    //std::system("COLOR 0A");
    std::system("COLOR 02");
    //std::system("COLOR 07");
    //std::system("CLS");
    return 0;
}

int TestUnicodeOutputs()
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    // https://unicodemap.org/range/9/Cyrillic/
    std::wcout << L"\x010a\n"; // ok
    // https://unicodemap.org/range/3/Latin_Extended-A/
    std::wcout << L"\x042d\n"; // ok
    // https://unicodemap.org/range/52/Box_Drawing/
    std::wcout << L"\x2517\n"; // ok
    // https://unicodemap.org/range/12/Arabic/
    std::wcout << L"\x060f\n"; // Not displaying
    // https://unicodemap.org/range/71/CJK_Unified_Ideographs/
    std::wcout << L"\x4e0d\n"; // Not displaying
    return 0;
}

int main(int argc, wchar_t* argv[])
{
    TestSystemColours();
    TestUnicodeOutputs();

    return 0;
}