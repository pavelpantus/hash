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