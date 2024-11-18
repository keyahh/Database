#ifndef FONTSH
#define FONTSH
#include <SFML/Graphics.hpp>
#include <map>
class Fonts
{
public:
    enum fontEnum {
        OPEN_SANS_BOLD,
        OPEN_SANS_REGULAR,
        DEVANAGARI
    };
    static sf::Font& getFont(fontEnum font);

private:
    inline static std::map<fontEnum, sf::Font> fonts;
    static void loadFont(fontEnum font);
    static std::string getFontPath(fontEnum font);
};


#endif
