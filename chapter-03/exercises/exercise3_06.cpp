#include <iostream>
#include <iomanip>

int main() {
    enum class Color: unsigned int {
        Red = 0xFF0000u, 
        Green = 0x00FF00u, 
        Yellow = 0xFFFF00u, 
        Purple = 0x800080u, 
        Blue = 0x0000FFu, 
        Black = 0x000000u
    };

    Color yellow {Color::Yellow}, purple {Color::Purple}, green {Color::Green};

    unsigned int yellow_r {
        (static_cast<unsigned int>(yellow) & static_cast<unsigned int>(Color::Red)) >> 16
    };
    unsigned int yellow_g {
        (static_cast<unsigned int>(yellow) & static_cast<unsigned int>(Color::Green)) >> 8
    };
    unsigned int yellow_b {
        static_cast<unsigned int>(yellow) & static_cast<unsigned int>(Color::Blue)
    };

    std::cout << "Value 'yellow' is (hex) : " << std::hex << static_cast<unsigned int>(yellow)
              << "\n                  (rgb) : (" << std::dec << yellow_r << " " << yellow_g << " " << yellow_b << ")"
              << std::endl;

    unsigned int purple_r {
        (static_cast<unsigned int>(purple) & static_cast<unsigned int>(Color::Red)) >> 16
    };
    unsigned int purple_g {
        (static_cast<unsigned int>(purple) & static_cast<unsigned int>(Color::Green)) >> 8
    };
    unsigned int purple_b {
        static_cast<unsigned int>(purple) & static_cast<unsigned int>(Color::Blue)
    };

    std::cout << "Value 'purple' is (hex) : " << std::hex << static_cast<unsigned int>(purple)
              << "\n                  (rgb) : (" << std::dec << purple_r << " " << purple_g << " " << purple_b << ")"
              << std::endl;


    unsigned int green_r {
        (static_cast<unsigned int>(green) & static_cast<unsigned int>(Color::Red)) >> 16
    };
    unsigned int green_g {
        (static_cast<unsigned int>(green) & static_cast<unsigned int>(Color::Green)) >> 8
    };
    unsigned int green_b {
        static_cast<unsigned int>(green) & static_cast<unsigned int>(Color::Blue)
    };

    std::cout << "Value 'green' is (hex) : " << std::hex << static_cast<unsigned int>(green)
              << "\n                  (rgb) : (" << std::dec << green_r << " " << green_g << " " << green_b << ")"
              << std::endl;
}