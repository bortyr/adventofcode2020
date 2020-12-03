#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// correct answer 306 ?
int main()
{
	// Get input
	std::ifstream f;
	f.open("input.txt");

	std::vector<std::string> vec;
	std::string input_value;
	
	// Get input values into lines
	while(std::getline(f,input_value))
	{
		vec.push_back(input_value);
	}

	uint16_t sum_matching_passwords = 0;
	uint16_t counter = 0;

	for(auto& i : vec)
	{
		// range ex. 5-9
		std::size_t pos = i.find("-");
		std::string range_b = i.substr(0, pos);
		uint16_t num_range_b = std::stoi(range_b);
		std::string range_e = i.substr(pos + 1, 2);
		uint16_t num_range_e = std::stoi(range_e);
		
		// char ex. g
		pos = i.find(" ");
		std::string key_char_in_str = i.substr(pos + 1, 1);
		char key_char = key_char_in_str.at(0);

		// password ex. ggccggmgn
		pos = i.rfind(" ");
		std::string passw = i.substr(pos + 1);

		// occurence
		auto occur = std::count(passw.begin(), passw.end(), key_char);	

		// does occurence match policy
		if(num_range_b <= occur and occur <= num_range_e)
		{
			sum_matching_passwords++;
		}
		counter++;
	}
	std::cout << "Matching passwords: " << sum_matching_passwords << " out of " << counter << std::endl;

	// Close opened input file
	f.close();

	return 0;
}
