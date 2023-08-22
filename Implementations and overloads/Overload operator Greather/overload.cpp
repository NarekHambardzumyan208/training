#include <iostream>
#include <map>
using namespace std;

template <typename T>
struct key {
    T key1;

    bool operator<(const key& obj) const {
        return key1 < obj.key1;
    }

    bool operator==(const key& obj) const {
        return key1 == obj.key1;
    }
};

int main() {
    key<int> obj;
    obj.key1 = 8;

    std::map<key<int>, std::string> a;
    a.insert({ obj, "Five" });

    for (const auto& pair : a) {
        std::cout << "Key: " << pair.first.key1 << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
