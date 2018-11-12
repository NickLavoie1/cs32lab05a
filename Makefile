test: test.cpp WordCount.cpp tddFuncs.cpp
	g++ -std=c++11 test.cpp WordCount.cpp tddFuncs.cpp -o test

run: test
	./test

clean:
	/bin/rm -f test WordCount *.o
