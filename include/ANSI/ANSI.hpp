#pragma once

#include <string>
#include <stdint.h>

class ANSI{
    public:
        ANSI() = delete;
        ANSI(ANSI&) = delete;
        ANSI(ANSI const&) = delete;
        /**
         * @brief 4-Bit ANSI colors
         * 
         * Only contains the foreground color. Background variants are optained by adding 10.
         * 
         */
        enum Color4Bit{
            Black = 30,
            Red = 31,
            Green = 32,
            Yellow = 33,
            Blue = 34,
            Magenta = 35,
            Cyan = 36,
            White = 37,
            Gray = 90,
            BrightRed = 91,
            BrightGreen = 92,
            BrightYellow = 93,
            BrightBlue = 94,
            BrightMagenta = 95,
            BrightCyan = 96,
            BrightWhite = 97,

            Default = 39,
        };

        /**
         * @brief Where to apply a color
         * 
         */
        enum ColorLocation{
            Foreground,
            Background,
        };

        /**
         * @brief Set the terminal color (24-bit / RGB)
         * 
         * Set the terminal color to any 24-bit RGB value
         * 
         * @param red
         * @param green
         * @param blue
         * @param loc foreground or background color
         * @return std::string the escape sequence to produce this color
         */
        static std::string set24BitColor(uint8_t red, uint8_t green, uint8_t blue, ColorLocation loc);

        /**
         * @brief Set the terminal color (8-bit)
         * 
         * Set the terminal color to something from https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit
         * 
         * @param color the color number
         * @param loc foreground or background color
         * @return std::string the escape sequence to produce this color
         */
        static std::string set8BitColor(uint8_t color, ColorLocation loc);

        /**
         * @brief Set the terminal color (4-bit)
         * 
         * Set the terminal color
         * 
         * @param color the color
         * @param loc foreground or background color
         * @return std::string the escape sequence to produce this color
         */
        static std::string set4BitColor(Color4Bit color, ColorLocation loc);

        /**
         * @brief Reset the terminal color
         * 
         * @param loc foreground or background color
         * @return std::string the escape sequence to produce this color
         */
        static std::string reset(ColorLocation loc);

        /**
         * @brief Reset all terminal colors
         * 
         * @return std::string the escape sequence to produce this color
         */
        static std::string reset();

};