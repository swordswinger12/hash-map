#include "hashmap.h"




Bucket::~Bucket(){

	delete elements;
}

Bucket::Bucket() 
{
	std::cout << "Created!" << std::endl;
	elements = new ElementList;
}


HashMap::HashMap(uint32_t numberOfBuckets) : m_numberOfBuckets(numberOfBuckets)
{

	buckets = new Bucket[m_numberOfBuckets];
}


HashMap::~HashMap(){
	delete[] buckets;
}

uint32_t HashMap::getNumBuckets(){
	return m_numberOfBuckets;
}

uint32_t HashMap::lookupKey(uint32_t key){
	std::cout << "in lookupkey" << std::endl;
	return 0;
}

uint32_t HashMap::addElement(uint32_t key, uint32_t value){
	std::cout << "in addelement" << std::endl;
	return 0;
}
bool HashMap::removeElement(uint32_t key){
	std::cout << "in removeelement" << std::endl;
	return true;
}

uint32_t HashFunctor::operator()(uint32_t key)
{
	std::cout << "in operator ()" << std::endl;
	return 0;
}
