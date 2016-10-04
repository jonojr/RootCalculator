#include <iostream>
#include <string>

bool isValid(std::string sroot){
	int numStops = 0;
	for (size_t i = 0; i < sroot.length(); i++){ // iterates through each character of the input string
		if (sroot[i] == '.'){
			numStops++;
		}
		if ((!isdigit(sroot[i]) && sroot[i] != '.') || sroot[i] == '-' || numStops > 1){ // checks each character to see if it is numeric or a decimal point, also checks that the number is not negative or contains multiple decimal points
			return false;
		}
	}
	return true;
}

double CalcRoot(float root) {
	double guess = 1;
	for (size_t i = 0; i < 1000000; i++){ // iterates a million times to get an accurate answer
		guess = 0.5*(guess+(root/guess));// performs the Babylonian method of root approximation
	}
	return guess;
}

int main() {
	std::string sroot;
	float root;
	std::cout << "What root would you like to approximate?" << std::endl;
	getline(std::cin, sroot); // gets the users input
	if (isValid(sroot) == false){//checks the validity of the input
		std::cout << "You did not enter a valid number" << std::endl;
		system("pause");
		return 1;
	}
	root = stof(sroot);// converts the input to a number
	std::cout<<CalcRoot(root)<<std::endl;// runs the calculation and outputs to the user
	system("pause");
	return 0;
}