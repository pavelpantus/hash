#include "StdAfx.h"
#include "HashContainer.h"
#include <boost\chrono.hpp>

HashContainer::HashContainer(void)
{
	for(int i = 0; i < HASH_TABLE_LENGTH; i++)
		bucketLocker[i] = new SharedMutex();

	for(int i = 0; i < HASH_TABLE_LENGTH; i++)
		bucket[i] = 0;
}

HashContainer::~HashContainer(void)
{
	for(int i = 0; i < HASH_TABLE_LENGTH; i++)
	{
		SharedMutex* bucketMutex = bucketLocker[i];
		delete bucketMutex;
		bucketLocker[i] = 0;

		Element* el = bucket[i];
		if(el)
		{
			recursiveClearBucket(el);
			bucket[i] = 0;
		}
	}
}

void HashContainer::insert(const string& key, double val, bool withTimeMeasPrintout)
{
	HashContainer::TimePoint tStart;
	if(withTimeMeasPrintout)
		tStart = boost::chrono::high_resolution_clock::now();

	unsigned int hashIndex = hash(key);
	SharedMutex* lock = bucketLocker[hashIndex];
	WriteLock writeLock(*lock);

	Element* el = bucket[hashIndex];

	if(el)
	{
		updateOrAppend(el, key, val);
	}
	else
	{
		Element* newEl = new Element();
		newEl->setKey(key);
		newEl->setValue(val);
		bucket[hashIndex] = newEl;
	}

	WriteLock valuesWriteLock(valuesLocker);
	values.insert(val);

	if(withTimeMeasPrintout)
	{
		HashContainer::TimePoint tFinish = boost::chrono::high_resolution_clock::now();
		std::cout << "Inserting el with key = " << key << "; val = " << val << " took " << boost::chrono::duration_cast<boost::chrono::microseconds>(tFinish - tStart).count() << " microseconds\n";
	}
}

double HashContainer::get(const string& key, bool withTimeMeasPrintout)
{
	HashContainer::TimePoint tStart;
	if(withTimeMeasPrintout)
		tStart = boost::chrono::high_resolution_clock::now();

	double rez = 0;

	unsigned int hashIndex = hash(key);
	SharedMutex* lock = bucketLocker[hashIndex];
	ReadLock readLock(*lock);
	
	Element* el = bucket[hashIndex];

	if(el)
	{
		if(el->getKey() == key)
		{
			rez = el->getValue();
		}
		else
		{
			rez = recursiveSearch(el, key);
		}
	}


	if(withTimeMeasPrintout)
	{
		HashContainer::TimePoint tFinish = boost::chrono::high_resolution_clock::now();
		std::cout << "Getting el with key = " << key << "; val = " << rez << " took " << boost::chrono::duration_cast<boost::chrono::microseconds>(tFinish - tStart).count() << " microseconds\n";
	}

	return rez;
}

void HashContainer::remove(const string& key, bool withTimeMeasPrintout)
{
	HashContainer::TimePoint tStart;
	if(withTimeMeasPrintout)
		tStart = boost::chrono::high_resolution_clock::now();

	unsigned int hashIndex = hash(key);
	SharedMutex* lock = bucketLocker[hashIndex];
	WriteLock writeLock(*lock);

	Element* el = bucket[hashIndex];

	if(el)
	{
		if(el->getKey() == key)
		{
			Element* nextEl = el->getNextElement();
			if(nextEl)
			{
				bucket[hashIndex] = nextEl;
			}
			else
			{
				bucket[hashIndex] = 0;
			}

			removeOneValueFromValues(el->getValue());

			delete el;
		}
		else
		{
			recursiveDelete(el, key);
		}
	}

	if(withTimeMeasPrintout)
	{
		HashContainer::TimePoint tFinish = boost::chrono::high_resolution_clock::now();
		std::cout << "Removing el with key = " << key << " took " << boost::chrono::duration_cast<boost::chrono::microseconds>(tFinish - tStart).count() << " microseconds\n";
	}
}

unsigned int HashContainer::hash(const string& key)
{
	// Brian W. Kernighan - The Practice Of Programming

	unsigned int accumulator = 0;
	const char* p;

	for(p = key.c_str(); *p != '\0'; p++)
	{
		accumulator = MULTIPLIER * accumulator + *p;
	}

	return accumulator % HASH_TABLE_LENGTH;
}

void HashContainer::debugPrint()
{
	printf("staring container print out!\n");
	for(int i = 0; i < HASH_TABLE_LENGTH; i++)
	{
		Element* el = bucket[i];
		if(!el)
		{
			printf("Column %d is empty! \n", i);
		}
		else
		{
			printf("Column %*d : ", 3, i);
			recursiveElementPrintout(el);
		}
	}
	printf("container print out is finished");
}

void HashContainer::recursiveElementPrintout(Element* el)
{
	if(el)
	{
		printf("Element's key: '%s'; value: '%f' | ", el->getKey().c_str(), el->getValue());

		printf("1");
		if(el->getNextElement())
		{
			recursiveElementPrintout(el->getNextElement());
		}
		else
		{
			printf("\n");
		}
	}
}

void HashContainer::updateOrAppend(Element* el, const string& key, double val)
{
	string elKey = el->getKey();
	if(elKey == key)
	{
		el->setValue(val);
	}
	else
	{
		Element* nextEl = el->getNextElement();
		if(nextEl)
		{
			updateOrAppend(nextEl, key, val);
		}
		else
		{
			Element* newEl = new Element();
			newEl->setKey(key);
			newEl->setValue(val);
			el->setNextElement(newEl);
		}
	}
}

double HashContainer::recursiveSearch(Element* el, const string& key)
{
	double rez = 0;
	if(el->getKey() == key)
	{
		rez = el->getValue();
	}
	else
	{
		Element* nextEl = el->getNextElement();
		if(nextEl)
		{
			rez = recursiveSearch(nextEl, key);
		}
	}
	return rez;
}

void HashContainer::recursiveDelete(Element* el, const string& key)
{
	Element* nextEl = el->getNextElement();

	if(!nextEl)
		return;

	if(nextEl->getKey() == key)
	{
		Element* nextAfterNextEl = nextEl->getNextElement();
		if(nextAfterNextEl)
		{
			el->setNextElement(nextAfterNextEl);
		}
		else
		{
			el->setNextElement(0);
		}

		removeOneValueFromValues(nextEl->getValue());

		delete nextEl;
	}
	else
	{
		recursiveDelete(nextEl, key);
	}
}

void HashContainer::recursiveClearBucket(Element* el)
{
	Element* nextEl = el->getNextElement();

	delete el;
	el = 0;

	if(nextEl)
	{
		recursiveClearBucket(nextEl);
	}
}

double HashContainer::getNthTheSmallestValue(unsigned int n)
{
	TimePoint tSearchSmStart = boost::chrono::high_resolution_clock::now();

	double rez = 0;
	unsigned int i = 0;

	ReadLock readLock(valuesLocker);

	ValuesSet::iterator iter = values.begin();
	
	if(iter != values.end())
		rez = *iter;

	while(iter != values.end())
	{
		if(rez != *iter)
			i++;

		rez = *iter;

		if(i >= n)
			break;

		iter++;
	}

	TimePoint tSearchSmFinish = boost::chrono::high_resolution_clock::now();
	std::cout << "Search of " << n << "-th the smallest item took " << boost::chrono::duration_cast<boost::chrono::milliseconds>(tSearchSmFinish - tSearchSmStart).count() << " milliseconds\n";

	return rez;
}

double HashContainer::getNthTheGreatestValue(unsigned int n)
{
	TimePoint tSearchGrStart = boost::chrono::high_resolution_clock::now();

	double rez = 0;
	unsigned int i = 0;

	ReadLock readLock(valuesLocker);

	ValuesSet::reverse_iterator iter = values.rbegin();

	if(iter != values.rend())
		rez = *iter;

	while(iter != values.rend())
	{
		if(rez != *iter)
			i++;

		rez = *iter;

		if(i == n)
			break;

		iter++;
	}

	TimePoint tSearchGrFinish = boost::chrono::high_resolution_clock::now();
	std::cout << "Search of " << n << "-th the greatest item took " << boost::chrono::duration_cast<boost::chrono::microseconds>(tSearchGrFinish - tSearchGrStart).count() << " microseconds\n";

	return rez;
}

void HashContainer::printValues()
{
	ValuesSet::iterator it = values.begin();

	cout << "values count = " << values.size() << "\n";

	cout << "Starting values printout:\n";
	while(it != values.end())
	{
		cout << *it++ << " | ";
	}
	cout << "\nValues printout is finished!\n";
}

void HashContainer::removeOneValueFromValues(double val)
{
	// Need to eraze only one entrance of the value

	WriteLock writeLock(valuesLocker);

	ValuesSet::iterator it = values.find(val);
	values.erase(it);
}