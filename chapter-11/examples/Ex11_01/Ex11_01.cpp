// Defining a class constructor
#include <iostream>

class Box
{
private:
    double length{1.0};
    double width{1.0};
    double height{1.0};

public:
    Box(double lengthValue, double widthValue, double heightValue)
    {
        std::cout << "Box constructor called" << std::endl;
        length = lengthValue;
        width = widthValue;
        height = heightValue;
    }

    double volume()
    {
        return length * width * height;
    }
};

int main()
{
    Box firstBox{80.0, 50.0, 40.0};
    double firstBoxVolume{firstBox.volume()};
    std::cout << "Volume of Box object is " << firstBoxVolume << std::endl;
}
