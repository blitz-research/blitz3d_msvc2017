#include "std.h"
#include "gxutf8.h"

string ansi_to_utf8(string);
char* ansi_to_utf8(char*);

int UTF8::measureCodepoint(char chr) {
    if ((chr & 0x80) == 0x00) {
        //first bit is 0: treat as ASCII
        return 1;
    }

    //first bit is 1, number of consecutive 1 bits at the start is length of codepoint
    int len = 0;
    while (((chr >> (7 - len)) & 0x01) == 0x01) {
        len++;
    }
    return len;
}

int UTF8::decodeCharacter(const char* buf, int index) {
    int codepointLen = measureCodepoint(buf[index]);

    if (codepointLen == 1) {
        return buf[index];
    }
    else {
        //decode first byte by skipping all bits that indicate the length of the codepoint
        int newChar = buf[index] & (0x7f >> codepointLen);
        for (int j = 1; j < codepointLen; j++) {
            //decode all of the following bytes, fixed 6 bits per byte
            newChar = (newChar << 6) | (buf[index + j] & 0x3f);
        }
        return newChar;
    }
}

std::wstring UTF8::convertToUtf16(const std::string& str) {
    std::wstring result = L"";

    for (int i = 0; i < str.size();) {
        result.push_back(decodeCharacter(str.c_str(), i));
        i += measureCodepoint(str[i]);
    }

    return result;
}

void UTF8::ANSItoUTF8(CString& strAnsi) {
    UINT nLen = MultiByteToWideChar(GetACP(), NULL, strAnsi, -1, NULL, NULL);
    WCHAR* wszBuffer = new WCHAR[nLen + 1];
    nLen = MultiByteToWideChar(GetACP(), NULL, strAnsi, -1, wszBuffer, nLen);
    wszBuffer[nLen] = 0;

    nLen = WideCharToMultiByte(CP_UTF8, NULL, wszBuffer, -1, NULL, NULL, NULL, NULL);
    CHAR* szBuffer = new CHAR[nLen + 1];
    nLen = WideCharToMultiByte(CP_UTF8, NULL, wszBuffer, -1, szBuffer, nLen, NULL, NULL);
    szBuffer[nLen] = 0;

    strAnsi = szBuffer;
    delete[] wszBuffer;
    delete[] szBuffer;
}