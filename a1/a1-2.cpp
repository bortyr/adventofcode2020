#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	// Get input
	std::ifstream f;
	f.open("input.txt");

	std::vector<uint16_t> vec;
	uint16_t input_value;

	while(f >> input_value)
	{
		vec.push_back(input_value);
	}

	// Sort it 
	std::sort(vec.begin(), vec.end());

	// Declare sought entries
	uint16_t e1 = 0;
	uint16_t e2 = 0;
	uint16_t e3 = 0;

	// Find those entries
	/* In first iteration of the loop set the 
	 * first element of vector as e1 and then in second loop
	 * find e2 which added to e1 gives sum of 2020.
	 * If true then print those entries and break from loops
	 */
	for(auto& i : vec)
	{
		e1 = i;
		for(auto& i : vec)
		{
			e2 = i;
			for(auto& i : vec)
			{
				e3 = i;
				if ((e1 + e2 + e3) == 2020)
				{
					std::cout << "SUCCES!\n";
					std::cout << "e1 = " << e1 << "\n";
					std::cout << "e2 = " << e2 << "\n";
					std::cout << "e3 = " << e2 << "\n";
					std::cout << "Multiplication = " << e1 * e2 * e3 << "\n";
					break;
				}
			}
			if ((e1 + e2 + e3) == 2020) break;
		}
		if ((e1 + e2 + e3) == 2020) break;
	}

	// Close opened input file
	f.close();

	return 0;
}
