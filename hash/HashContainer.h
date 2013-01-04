#pragma once

#include "Element.h"
#include <boost\thread\shared_mutex.hpp>
#include <boost\thread\thread.hpp>
#include <boost\thread\locks.hpp>
#include <set>

class HashContainer
{
public:
	HashContainer(void);
	~HashContainer(void);

	void insert(const string& key, double val, bool withTimeMeasPrintout = false); //insert or update
	double get(const string& key, bool withTimeMeasPrintout = false);
	void remove(const string& key, bool withTimeMeasPrintout = false);

	double getNthTheSmallestValue(unsigned int n);
	double getNthTheGreatestValue(unsigned int n);

	typedef boost::unique_lock<boost::shared_mutex> WriteLock;
    typedef boost::shared_lock<boost::shared_mutex> ReadLock;
	typedef boost::shared_mutex SharedMutex;
	typedef boost::chrono::steady_clock::time_point TimePoint;

	//debug printouts
	void debugPrint();
	void recursiveElementPrintout(Element* el);
	void printValues();
private:
	const static unsigned int HASH_TABLE_LENGTH = 50000;
	const static unsigned int MULTIPLIER = 31;

	Element* bucket[HASH_TABLE_LENGTH];
	SharedMutex* bucketLocker[HASH_TABLE_LENGTH];

	SharedMutex valuesLocker;
	typedef std::multiset<double> ValuesSet;
	ValuesSet values;
	void removeOneValueFromValues(double val);

	void updateOrAppend(Element* el, const string& key, double val);
	double recursiveSearch(Element* el, const string& key);
	void recursiveDelete(Element* el, const string& key);
	void recursiveClearBucket(Element* el);

	unsigned int hash(const string& key);
};
