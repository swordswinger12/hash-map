/**\brief This is a hash map implementation that I'm writing for shits and giggles, and also because I don't know how to write one.
 *@author Paul Grubbs (3/11/2012)
 */

#include <iostream>
#include <list>
#include <utility>
#include <stdint.h>

typedef std::list<std::pair<uint32_t, uint32_t> >* ElementListPtr;
typedef std::list<std::pair<uint32_t, uint32_t> > ElementList;
/**
 *@note this is the bucket class, which will hold a list of elements whose keys are equal mod the number of buckets.
 */
class Bucket{
 public:
	const ElementListPtr getElementList(void) const;
	virtual ~Bucket();
	Bucket();
 private:
	ElementListPtr elements;
};
/**
 *@note The general procedure is this: An array of Buckets is allocated. Each bucket contains a list of elements whose keys match the index of that bucket mod the number of buckets.
 *@note To add an element, the element's key is hashed and its value mod the number of buckets is computed, which determines which bucket it goes into. 
 *@note To look up an element, hash the key and compute its value mod the number of buckets, this is the index into the bucket array. Then, the element list of that bucket is searched for that specific key. Finally, return the element with that key, or throw an exception.
 *@note To remove an element, look it up, then remove it from the element list of the bucket.
 */
class HashMap{

 public:

	HashMap(uint32_t);
	virtual ~HashMap(void);

	virtual uint32_t getNumBuckets();
	//Look up the element with this key
	virtual uint32_t lookupKey(uint32_t);
	//Add the element with this key
	virtual uint32_t addElement(uint32_t, uint32_t);
	//Remove the element with this key
	virtual bool removeElement(uint32_t);

 private:
	uint32_t m_numberOfBuckets;
	//Array of buckets, the size of the array is numberOfBuckets
	Bucket *buckets;
};
/**
 *@note This class is a functor which takes the key of an element, hashes it according to a TBD hash function, and returns its value mod the number of buckets.
 */
class HashFunctor{
	HashFunctor();
	virtual uint32_t operator()(uint32_t key);
};
