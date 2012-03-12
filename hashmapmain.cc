#include "hashmap.h"


int main(int argc, char** argv){

	std::cout << "Test!" << std::endl;
	HashMap hashmap(5);
	std::cout << hashmap.getNumBuckets() << std::endl;
	return 0;

}
