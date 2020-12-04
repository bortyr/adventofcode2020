#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <chrono>
#include <memory>

class passport {
	
	public:

	std::unordered_map<std::string, std::string> map;

	passport()
	{
		map.insert(std::make_pair("byr", ""));
		map.insert(std::make_pair("iyr", ""));
		map.insert(std::make_pair("eyr", ""));
		map.insert(std::make_pair("hgt", ""));
		map.insert(std::make_pair("hcl", ""));
		map.insert(std::make_pair("ecl", ""));
		map.insert(std::make_pair("cid", ""));
	}

	private:
};

int main()
{
	std::unique_ptr<passport> p(new passport());

	p->map.insert_or_assign("byr", "key-new");
	
	for(auto& i : p->map )
	{
		std::cout << i.first << " " << i.second << "\n";
	}

	return 0;
}
