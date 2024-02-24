#pragma once
#ifndef GXUTF8_H
#define GXUTF8_H

class UTF8 {
private:
    UTF8() {}
    UTF8(const UTF8& o) {}
public:
    static int measureCodepoint(char chr);
    static int decodeCharacter(const char* buf, int index);
};

#endif