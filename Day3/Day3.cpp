#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

std::vector<std::string> readInput(std::string file)
{
	// Get input
	std::ifstream f;
	f.open(file);

	std::string input_value;
	std::vector<std::string> result_vec;
	
	// Get input values into lines
	while(std::getline(f,input_value))
	{
		result_vec.push_back(input_value);
	}

	f.close();

	return result_vec;
}

uint16_t encounters(std::vector<std::string> map, uint16_t right, uint16_t down)
{
	uint16_t encounters = 0;
	uint16_t x = 0;
	uint16_t y = 0;

	while(y < map.size())
	{
		// increment if tree encountered
		if(map[y][x] == '#')
			encounters++;

		// go down by given right and down value
		x += right;
		y += down; 

		// map repeats
		if(x >= map[y].size()) 
			x -= map[y].size();
	}

	return encounters;
}

int main()
{
	std::vector<std::string> map = readInput("input.txt");
	auto start = std::chrono::high_resolution_clock::now();

	std::cout << "Trees encountered: " << encounters(map, 3, 1) << "\n";

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Execution time: " << duration.count() << " microseconds\n";

	uint64_t multipliedTrees = (encounters(map, 1, 1) *
								encounters(map, 3, 1) *
								encounters(map, 5, 1) *
								encounters(map, 7, 1) *
								encounters(map, 1, 2) );

	std::cout << "Multiplied trees encountered: " << multipliedTrees << "\n";

	return 0;
}
