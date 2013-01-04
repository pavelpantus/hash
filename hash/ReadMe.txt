Realization of hash container (HashContainer).
Key - string; value - double.

Designed to be used with 1000 - 100000 elements inside.
To tune hash container for enother elements count simply adjust HASH_TABLE_LENGTH in HashContainer.h accordenly.

Container designed to be used in multithreading environment.
For this purpose boost shared mutex and unique / shared lock objects were used.
So that simultanious read operations are supported. Locks are managed on bucket level to support correct remove operation.

Implemented operations:
1) Insert / update operation ( void insert(const string& key, double val, bool withTimeMeasPrintout = false); );
2) Searching for an element ( double get(const string& key, bool withTimeMeasPrintout = false); );
3) Delete operation (   void remove(const string& key, bool withTimeMeasPrintout = false); );
4) Get n-th the smallest value in the hash container ( double getNthTheSmallestValue(unsigned int n); );
5) Get n-th the greatest value in the hash container ( double getNthTheGreatestValue(unsigned int n); ).

Element - is a class representing data element in hash container.

Idea of hash function was taken from great book: Brian W. Kernighan - 'The Practice Of Programming'.
Hash function can be adjusted to specific purpose, current hash is more general approach.

To test all implemented functionality test interface was implemented. Starting app user gets to the test menu.
Options of test menu:
1) quit the app - hash container to be cleaned and app finishes;
2) fill the hash with data - filling ~105000 elements to use container in real conditions;
3) get 20 values test - get 20 values which are scattered all over the container;
4) remove 20 values test - remove 20 values which are scattered all over the container;
5) find 20 the  smallest and 20 the greatest elements (operations 4 and 5);
6) multithreading test - starting 4 threads: 1 thread gets random vals; 1 thread inserts/updates random vals; 1 thread removes random vals and 1 thread getting n-th the smallest/greatest vals;

Peculiarities:
Development and testing has been done using msvc 2010 express edition, using boost 1.51.
To start app using msvc you must set environment variable BOOST_PATH to your boost dir (for example: C:\Program Files (x86)\boost).
To measure time intervals boost::chrono has been used.


========================================================
========================================================
========================================================


Measurement in the process of development:
read from file and insert into the hash:

HASH_TABLE_LENGTH | time of operations
100000 - ~3.02 sec insertion 105435 elements;   ~13 microsec/search;  ~12 microsec/deletion
50000  - ~3.2  sec insertion 105435 elements;   ~15 microsec/search;  ~13 microsec/deletion
30000  - ~3.38 sec insertion 105435 elements;   ~17 microsec/search;  ~15 microsec/deletion
20000  - ~3.54 sec insertion 105435 elements;   ~22 microsec/search;  ~19 microsec/deletion
10000  - ~4.15 sec insertion 105435 elements;   ~26 microsec/search;  ~25 microsec/deletion
5000   - ~5.28 sec insertion 105435 elements;   ~45 microsec/search;  ~42 microsec/deletion
2500   - ~7.36 sec insertion 105435 elements;   ~77 microsec/search;  ~74 microsec/deletion
1000   -~14.51 sec insertion 105435 elements;   ~163 microsec/search; ~160 microsec/deletion

100000 - ~0.03 sec insertion 1000 elements;  ~4 microsec/search;  ~3 microsec/deletion
50000  - ~0.03 sec insertion 1000 elements;  ~5 microsec/search;  ~4 microsec/deletion
30000  - ~0.03 sec insertion 1000 elements;  ~4 microsec/search;  ~4 microsec/deletion
20000  - ~0.03 sec insertion 1000 elements;  ~4 microsec/search;  ~4 microsec/deletion
10000  - ~0.03 sec insertion 1000 elements;  ~6 microsec/search;  ~5 microsec/deletion
5000   - ~0.04 sec insertion 1000 elements;  ~6 microsec/search;  ~5 microsec/deletion
2500   - ~0.04 sec insertion 1000 elements;  ~7 microsec/search;  ~6 microsec/deletion
1000   - ~0.04 sec insertion 1000 elements;  ~9 microsec/search;  ~7 microsec/deletion

boost shared mutex with unique and shared locks were added: +10-15% of time to search and delete operation on the single thread,
+7-10% of time to insertion operation on the single thread.