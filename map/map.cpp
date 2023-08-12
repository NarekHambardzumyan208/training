#include <iostream>
#include <map>
int main()
{
	std::map<std::string, std::string> a{ {"Armenia", ""}, { "Russia","" }, {"USA", ""}, { "France","" },{"Germany", ""}};
	a["Armenia"] = "Yerevan";
	std::cout << a["Armenia"] << std::endl;
	a["Russia"] = "Moscow";
	std::cout << a["Russia"] << std::endl;
	a["USA"] = "Washington";
	std::cout << a["USA"] << std::endl;
	a["France"] = "Paris";
	std::cout << a["France"] << std::endl;
	a["Germany"] = "Berlin";
	std::cout << a["Germany"] << std::endl;
}
