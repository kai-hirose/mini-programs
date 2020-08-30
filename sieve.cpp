#include <iostream>
#include <math.h>
#include <string>

int main(int argc, char** argv){
	int n = 0;
	std::string temp;
	if (argc < 2) {
		std::cout << "You did not enter a upper limit on prime numbers." << std::endl << "Please enter one: ";
		std::cin >> temp;
	}
	else {
		n = atoi(argv[1]);
	}
	while (n == 0 || atoi(temp.c_str()) == 0) {
		std::cout << "You did not enter a legitimate value." << std::endl << "Please enter a new value: ";
		std::cin >> temp;
		n = atoi(temp.c_str());
	}

	//Allocate the array and keep track of numbers by using index
	int* primeNums = new int[n + 1];

	//Initialize values
	primeNums[0] = 0;
	primeNums[1] = 0;
	for (int i = 2; i <= n; i++) {
		primeNums[i] = 1;
	}

	//Sieve
	for (int i = 2; i <= sqrt(n); i++) {
		if (primeNums[i] == 1) {
			for (int j = 2; i * j <= n; j++) {
				primeNums[i * j] = 0;
			}
		}
	}

	//Print
	std::cout << "Your list of prime numbers are: ";
	for (int i = 0; i <= n; i++) {
		if (primeNums[i] == 1) {
			std::cout << i << ", ";
		}
	}
	std::cout << std::endl;
	delete[] primeNums;
	
	return 0;
}