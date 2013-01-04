#include "stdafx.h"

#include "HashContainer.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <boost\chrono.hpp>

std::vector<string> keysForTestThreads;
const string inputFileName = "input.txt";

enum OperationTypes
{
	OP_GET = 0,
	OP_INSERT = 1,
	OP_REMOVE = 2,
	OP_SMALLEST_GREATEST = 3
};

void separateThreadWorkflow(HashContainer* hash, OperationTypes opInd)
{
	unsigned int operationIndex = opInd; //what to do: delete, insert or get
	unsigned int randomKeyToRead;
	string s;

	for(int i = 0; i < 5000; i++)
	{
		randomKeyToRead = rand() % keysForTestThreads.size();
		s = keysForTestThreads.at(randomKeyToRead);

		switch(operationIndex)
		{
		case OP_GET:
			{
				double val = hash->get(s, true);
				break;
			}
		case OP_REMOVE:
			hash->remove(s, true);
			break;
		case OP_INSERT:
			{
				double val = rand() % 10;
				val = val + 1.999;
				hash->insert(s, val, true);
			break;
			}
		case OP_SMALLEST_GREATEST:
			{
				unsigned int n = rand() % 20;
				hash->getNthTheSmallestValue(n);
				hash->getNthTheGreatestValue(n);
			}
			break;
		default:
			cout << "Unknown operation index " << operationIndex << "\n";
			break;
		}
	}
}

void smallestGreatestTest(HashContainer& hash)
{
	cout << "the smallest value 0 = " << hash.getNthTheSmallestValue(0) << "\n";
	cout << "the smallest value 1 = " << hash.getNthTheSmallestValue(1) << "\n";
	cout << "the smallest value 2 = " << hash.getNthTheSmallestValue(2) << "\n";
	cout << "the smallest value 3 = " << hash.getNthTheSmallestValue(3) << "\n";
	cout << "the smallest value 4 = " << hash.getNthTheSmallestValue(4) << "\n";
	cout << "the smallest value 5 = " << hash.getNthTheSmallestValue(5) << "\n";
	cout << "the smallest value 6 = " << hash.getNthTheSmallestValue(0) << "\n";
	cout << "the smallest value 7 = " << hash.getNthTheSmallestValue(1) << "\n";
	cout << "the smallest value 8 = " << hash.getNthTheSmallestValue(2) << "\n";
	cout << "the smallest value 9 = " << hash.getNthTheSmallestValue(3) << "\n";
	cout << "the smallest value 10 = " << hash.getNthTheSmallestValue(10) << "\n";
	cout << "the smallest value 11 = " << hash.getNthTheSmallestValue(11) << "\n";
	cout << "the smallest value 12 = " << hash.getNthTheSmallestValue(12) << "\n";
	cout << "the smallest value 13 = " << hash.getNthTheSmallestValue(13) << "\n";
	cout << "the smallest value 14 = " << hash.getNthTheSmallestValue(14) << "\n";
	cout << "the smallest value 15 = " << hash.getNthTheSmallestValue(15) << "\n";
	cout << "the smallest value 16 = " << hash.getNthTheSmallestValue(16) << "\n";
	cout << "the smallest value 17 = " << hash.getNthTheSmallestValue(17) << "\n";
	cout << "the smallest value 18 = " << hash.getNthTheSmallestValue(18) << "\n";
	cout << "the smallest value 19 = " << hash.getNthTheSmallestValue(19) << "\n";
	cout << "the smallest value 20 = " << hash.getNthTheSmallestValue(20) << "\n";
	
	cout << "the greatest value 0 = " << hash.getNthTheGreatestValue(0) << "\n";
	cout << "the greatest value 1 = " << hash.getNthTheGreatestValue(1) << "\n";
	cout << "the greatest value 2 = " << hash.getNthTheGreatestValue(2) << "\n";
	cout << "the greatest value 3 = " << hash.getNthTheGreatestValue(3) << "\n";
	cout << "the greatest value 4 = " << hash.getNthTheGreatestValue(4) << "\n";
	cout << "the greatest value 5 = " << hash.getNthTheGreatestValue(5) << "\n";
	cout << "the greatest value 6 = " << hash.getNthTheGreatestValue(6) << "\n";
	cout << "the greatest value 7 = " << hash.getNthTheGreatestValue(7) << "\n";
	cout << "the greatest value 8 = " << hash.getNthTheGreatestValue(8) << "\n";
	cout << "the greatest value 9 = " << hash.getNthTheGreatestValue(9) << "\n";
	cout << "the greatest value 10 = " << hash.getNthTheGreatestValue(10) << "\n";
	cout << "the greatest value 11 = " << hash.getNthTheGreatestValue(11) << "\n";
	cout << "the greatest value 12 = " << hash.getNthTheGreatestValue(12) << "\n";
	cout << "the greatest value 13 = " << hash.getNthTheGreatestValue(13) << "\n";
	cout << "the greatest value 14 = " << hash.getNthTheGreatestValue(14) << "\n";
	cout << "the greatest value 15 = " << hash.getNthTheGreatestValue(15) << "\n";
	cout << "the greatest value 16 = " << hash.getNthTheGreatestValue(16) << "\n";
	cout << "the greatest value 17 = " << hash.getNthTheGreatestValue(17) << "\n";
	cout << "the greatest value 18 = " << hash.getNthTheGreatestValue(18) << "\n";
	cout << "the greatest value 19 = " << hash.getNthTheGreatestValue(19) << "\n";
	cout << "the greatest value 20 = " << hash.getNthTheGreatestValue(20) << "\n";
}

void removeTest(HashContainer& hash)
{
	HashContainer::TimePoint tDeletionStart = boost::chrono::high_resolution_clock::now();

	hash.remove("because");
	hash.remove("crystal ball");
	hash.remove("inventive");
	hash.remove("North American");
	hash.remove("torrential");
	hash.remove("    necessary");
	hash.remove("Before using the shared variables (i.e., before entering its critical region), each process calls");
	hash.remove("Each slot in the process table is defined as a struct proc (lines 5516 to 5545). Each entry contains");
	hash.remove("A slight modification of this algorithm that has a smaller variance in response times is to always");
	hash.remove("pp. 152-156, 2005.");
	hash.remove("05006 /* M68000 specific types go here. */");
	hash.remove("15091 int enable; /* set timer if true, otherwise unset */");
	hash.remove("25672 /* 'position' can be located via the double indirect block. */");
	hash.remove("Although 3 GB is better than 2 GB, it’s still not enough virtual address space to map very");
	hash.remove("There are some limitations to the hotpatching functionality:");
	hash.remove("4. +0x080 ProcessLock : _EX_PUSH_LOCK");
	hash.remove("hera sebe, rebyat!");
	hash.remove("hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! ");
	hash.remove("4.1.6 Monitoring Registry Activity");
	hash.remove("One of the main goals behind the design of the Windows hypervisor was to have it as small");

	HashContainer::TimePoint tDeletionFinish = boost::chrono::high_resolution_clock::now();
	std::cout << "Deletion of 20 items took " << boost::chrono::duration_cast<boost::chrono::microseconds>(tDeletionFinish - tDeletionStart).count() << " microseconds\n";
}

void getTest(HashContainer& hash)
{
	HashContainer::TimePoint tSearchStart = boost::chrono::high_resolution_clock::now();

	hash.get("refused");
	hash.get("crystal ball");
	hash.get("inventive");
	hash.get("North American");
	hash.get("torrential");
	hash.get("    necessary");
	hash.get("Before using the shared variables (i.e., before entering its critical region), each process calls");
	hash.get("Each slot in the process table is defined as a struct proc (lines 5516 to 5545). Each entry contains");
	hash.get("A slight modification of this algorithm that has a smaller variance in response times is to always");
	hash.get("pp. 152-156, 2005.");
	hash.get("05006 /* M68000 specific types go here. */");
	hash.get("15091 int enable; /* set timer if true, otherwise unset */");
	hash.get("25672 /* 'position' can be located via the double indirect block. */");
	hash.get("Although 3 GB is better than 2 GB, it’s still not enough virtual address space to map very");
	hash.get("There are some limitations to the hotpatching functionality:");
	hash.get("4. +0x080 ProcessLock : _EX_PUSH_LOCK");
	hash.get("hera sebe, rebyat!");
	hash.get("hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! hera sebe, rebyat! ochen ochen ochen dlinniy kluch! ");
	hash.get("4.1.6 Monitoring Registry Activity");
	hash.get("One of the main goals behind the design of the Windows hypervisor was to have it as small");

	HashContainer::TimePoint tSearchFinish = boost::chrono::high_resolution_clock::now();
	std::cout << "Getting of 20 items took " << boost::chrono::duration_cast<boost::chrono::microseconds>(tSearchFinish - tSearchStart).count() << " microseconds\n";
}

void threadsTest(HashContainer& hash)
{
	cout << "Starting initialization of test environment (key lookup vector)!\n";
	ifstream fileTestEnvStream;
	fileTestEnvStream.open(inputFileName, ifstream::in);

	if(fileTestEnvStream.good())
	{
		string sTestEnv;
		while(!fileTestEnvStream.eof())
		{
			getline(fileTestEnvStream, sTestEnv);
			if(!sTestEnv.empty())
			{
				keysForTestThreads.push_back(sTestEnv);
			}
		}
		fileTestEnvStream.close();
	}
	else
	{
		printf("File stream is not good!\n");
	}
	cout << "Initialization done!\n";
	
	boost::thread t1(&separateThreadWorkflow, &hash, OP_GET);
	boost::thread t2(&separateThreadWorkflow, &hash, OP_INSERT);
	boost::thread t3(&separateThreadWorkflow, &hash, OP_REMOVE);
	boost::thread t4(&separateThreadWorkflow, &hash, OP_SMALLEST_GREATEST);
	/*
	boost::thread t5(&separateThreadWorkflow, &hash, OP_GET);
	boost::thread t6(&separateThreadWorkflow, &hash, OP_INSERT);
	boost::thread t7(&separateThreadWorkflow, &hash, OP_REMOVE);
	boost::thread t8(&separateThreadWorkflow, &hash, OP_SMALLEST_GREATEST);

	boost::thread t9(&separateThreadWorkflow, &hash, OP_GET);
	boost::thread t10(&separateThreadWorkflow, &hash, OP_INSERT);
	boost::thread t11(&separateThreadWorkflow, &hash, OP_REMOVE);
	boost::thread t12(&separateThreadWorkflow, &hash, OP_SMALLEST_GREATEST);

	boost::thread t13(&separateThreadWorkflow, &hash, OP_GET);
	boost::thread t14(&separateThreadWorkflow, &hash, OP_INSERT);
	boost::thread t15(&separateThreadWorkflow, &hash, OP_REMOVE);
	boost::thread t16(&separateThreadWorkflow, &hash, OP_SMALLEST_GREATEST);
	*/
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	/*
	t5.join();
	t6.join();
	t7.join();
	t8.join();

	t9.join();
	t10.join();
	t11.join();
	t12.join();

	t13.join();
	t14.join();
	t15.join();
	t16.join();
	*/
}

void insertionTest(HashContainer& hash)
{
	ifstream fileStream;
	fileStream.open(inputFileName, ifstream::in);
	unsigned int loadStopper = 0; //to test deletion correctness
	HashContainer::TimePoint tInsertionStart = boost::chrono::high_resolution_clock::now();
	if(fileStream.good())
	{
		string s;
		while(!fileStream.eof())
		{
			//if(loadStopper == 100)
			//	break;

			getline(fileStream, s);
			if(!s.empty())
			{
				double val = rand() % 1000;
				hash.insert(s, val + 1.999);		
			//	++loadStopper;
			}
		}
		fileStream.close();
	}
	else
	{
		printf("File stream is not good!\n");
	}
	HashContainer::TimePoint tInsertionFinish = boost::chrono::high_resolution_clock::now();
	std::cout << "Insertion of ~105000 items took " << boost::chrono::duration_cast<boost::chrono::milliseconds>(tInsertionFinish - tInsertionStart).count() << " milliseconds (with value generation)\n";
}

void printMenu()
{
	cout << "\n========================================\n";
	cout << "Welcome to the test menu for hash container!\n";
	cout << "Here are few options:\n";
	cout << "Type 'q' to quit program;\n";
	cout << "Type 'i' to fill the hash with the data;\n";
	cout << "Type 'g' to start 'get 20 values' test (you should fill the hash with data first);\n";
	cout << "Type 'r' to start 'remove 20 values' test (you should fill the hash with data first);\n";
	cout << "Type 's' to start 'get 20 smallest, 20 greatest' test (you should fill the hash with data first);\n";
	cout << "Type 't' to start 'multithread' test with 4 threads(test will take ~5 mins);\n";
	cout << "========================================\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
	HashContainer hash;
#if 0
	insertionTest(hash);
#endif
#if 0
	threadsTest(hash);
#endif
#if 0
	getTest(hash);
#endif
#if 0
	removeTest(hash);
#endif
#if 0
	smallestGreatestTest(hash);
#endif

	printMenu();
	
	while(char c = getchar())
	{
		if(c == '\n')
			continue;

		switch(c)
		{
		case 'q':
			cout << "Cleaning hash and quitting! Bye!\n";
			return 0;
		case 'i':
			cout << "Insertion test started.\n";
			insertionTest(hash);
			cout << "Insertion test finished.\n";
			break;
		case 'g':
			cout << "'Get 20 values' test started.\n";
			getTest(hash);
			cout << "'Get 20 values' test finished.\n";
			break;
		case 'r':
			cout << "'Remove 20 values' test started.\n";
			removeTest(hash);
			cout << "'Remove 20 values' test finished.\n";
			break;
		case 's':
			cout << "'Get 20 smallest, 20 greatest' test started\n";
			smallestGreatestTest(hash);
			cout << "'Get 20 smallest, 20 greatest' test finished\n";
			break;
		case 't':
			cout << "'Threads' test started\n";
			threadsTest(hash);
			cout << "'Threads' test finished\n";
			break;
		default:
			cout << "Unknown command '" << c << "' skipping...\n";
			break;
		}
		printMenu();
	}
	return 0;
}
