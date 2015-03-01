#include <iostream>
#include <random>
#include <algorithm>

int main(int, char*[]) {
    //const int range_from  = 0;
    //const int range_to    = 10;
    //std::random_device                  rand_dev;
    //std::mt19937                        generator(rand_dev());
    //std::uniform_int_distribution<int>  distr(range_from, range_to);

    std::vector<int> vec = {4, 8, 15, 16, 23, 42};

	std::random_device random_dev;
	std::mt19937       generator(random_dev());

	std::shuffle(vec.begin(), vec.end(), generator);
 

    //for (int i = 0; i < 6; ++i)
        std::cout << vec[0] << ' ';
}