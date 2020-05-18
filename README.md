# VectorClass


## Class Setup
```
cmake CMakeLists.txt
make
```
To use the test file:
```
./vectortest
```

To use the performance test:
```
./vectorperf rand-10k.txt
```

## About this project
The vector is an abstract data type of an ordered list of items which automatically resizes itself. The vector class uses a key-value template with the typename definition. The vector class implements these functions:
- add
- remove
- find
- range find
- keys (returns all keys by reference)
- sort (ascending order)
- size


The test file is used as a way to ensure that each function works with different test cases.  The performance file is used to find the speed and number of calls for each function. This can be used with a randomly generated key-value pairs that ranges from 10k pairs to 50k pairs.
