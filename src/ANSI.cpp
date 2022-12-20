#include "ANSI/ANSI.hpp"

std::string ANSI::set24BitColor(uint8_t red, uint8_t green, uint8_t blue, ANSI::ColorLocation loc){
    return std::string("\e[") + std::to_string(loc == ColorLocation::Foreground ? 38 : 48) + ";2;"
        + std::to_string(static_cast<int>(red)) + ";"
        + std::to_string(static_cast<int>(green)) + ";"
        + std::to_string(static_cast<int>(blue)) + "m";
}

std::string ANSI::set8BitColor(uint8_t color, ANSI::ColorLocation loc){
    return std::string("\e[") + std::to_string(loc == ColorLocation::Foreground ? 38 : 48) + ";5;" + std::to_string(static_cast<int>(color)) + "m";
}

std::string ANSI::set4BitColor(ANSI::Color4Bit color, ANSI::ColorLocation loc){
    if (loc == ColorLocation::Background)
        color = static_cast<Color4Bit>(static_cast<int>(color) + 10);

    return std::string("\e[") + std::to_string(static_cast<int>(color)) + "m";
}

std::string ANSI::reset(ColorLocation loc){
    return ANSI::set4BitColor(Color4Bit::Default, loc);
}

std::string ANSI::reset(){
    return reset(ColorLocation::Foreground) + reset(ColorLocation::Background);
}