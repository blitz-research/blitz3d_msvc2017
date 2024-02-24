
#ifndef GXFONT_H
#define GXFONT_H

#include "std.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include <vector>
#include <map>

class gxCanvas;
class gxGraphics;

typedef IDirectDrawSurface7 ddSurf;

class gxFont {
public:
    gxFont(FT_Library ftLibrary, gxGraphics* gfx, const std::string& fn, int h, int flgs);
    ~gxFont();

    void render(gxCanvas* dest, unsigned color_argb, int x, int y, const std::string& t);

    int charWidth(int c);
    int charAdvance(int c);

    int stringWidth(const std::string& text);

    //ACCESSORS
    int getWidth()const;							//width of widest char
    int getHeight()const;							//height of font
    int getWidth(const std::string& text);	    //width of string
    bool isPrintable(int chr)const;				//printable char?

    std::vector<gxCanvas*> atlases;

    enum {
        FONT_BOLD = 1,
        FONT_ITALIC = 2,
        FONT_UNDERLINE = 4 //TODO: remove? who actually wants this
    };
private:
    gxFont();

    int maxWidth = 0;

    struct GlyphData {
        int atlasIndex;
        int drawOffset[2];
        int horizontalAdvance;
        int srcRect[4];
    };

    gxCanvas* tempCanvas;

    const int atlasDims = 1024;

    void renderAtlas(int chr);

    int flags;

    int height;
    FT_Face freeTypeFace;

    std::map<int, GlyphData> glyphData;

    gxGraphics* graphics;

    std::string filename;
};

#endif