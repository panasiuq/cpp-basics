#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

int main() {

	std::srand(std::time(nullptr));
	
	
	const int target_value = std::rand() % 100;
	const int max_value = 100;
    int current_value = 0;
	bool not_win = true;

	std::cout << "Guess The Number:The Incredible Miracle Game!" << std::endl;
	const std::string high_scores_filename = "high_scores.txt";
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;
	std::cout << "Enter your guess:" << std::endl;

	int attempts_count = 0;

	do {
		std::cin >> current_value;
        attempts_count++;

		if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}
	} while(true);
		

	{
		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		out_file << user_name << ' ';
		out_file << attempts_count;
		out_file << std::endl;
	} 

	{
		std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		std::cout << "High scores table:" << std::endl;

		std::string username;
		int high_score = 0;
		while (true) {
			in_file >> username;
			in_file >> high_score;
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			std::cout << username << '\t' << high_score << std::endl;
		}
	}

	return 0;
}
