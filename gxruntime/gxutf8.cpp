#include "std.h"
#include "gxutf8.h"

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