#include <iostream>
#include <string>
using namespace std;
class Converter {
public:
    enum class  Color
    {
        red,
        green,
        blue,
        black,
        pink,
        yellow,
        Unknown
    };
    static string Convert(Color color) {
        switch (color) {
        case Color::red:
            return "red";
            break;
        case Color::green:
            return "green";
            break;
        case Color::blue:
            return "blue";
            break;
        case Color::black:
            return "black";
            break;
        case Color::pink:
            return "pink";
            break;
        case Color::yellow:
            return "yellow";
            break;
        default:
            return "Unknown";
            break;
        }
    }
    static Color Convert(const string color)
    {
        if (color == "red")
        {
            return Color::red;
        }
        else if (color == "green")
        {
            return Color::green;
        }
        else if (color == "blue")
        {
            return Color::blue;
        }
        else if (color == "black")
        {
            return Color::black;
        }
        else if (color == "pink")
        {
            return Color::pink;
        }
        else if (color == "yellow")
        {
            return Color::yellow;
        }
        else {
            return Color::Unknown;
        }
    }
};

int main() {
    Converter::Color color = Converter::Color::green;
    string colorString = Converter::Convert(color);
    std::cout << colorString;
    Converter::Color colour = Converter::Convert(colorString);
    return 0;
}