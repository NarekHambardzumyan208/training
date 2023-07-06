#include <iostream>
#include <string>

enum class  Color 
{ 
red, 
green, 
blue,
black,
pink,
yellow
};
using namespace std;
class Converter {
public:
    static string Convert(Color color) {
        switch (color) {
        case Color::red:
            return "Red";
            break;
        case Color::green:
            return "Green";
            break;
        case Color::blue:
            return "Blue";
            break;
        case Color::black:
            return "Black";
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
};

int main() {
    Color color = Color::green;
   string colorString = Converter::Convert(color);
   std::cout << colorString;
    return 0;
}