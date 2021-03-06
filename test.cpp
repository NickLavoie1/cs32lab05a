#include <iostream>
#include "tddFuncs.h"
#include "WordCount.h"
#include <vector>
#include <fstream>

using namespace std;

int main()
{
  string a = "sentence";
  string b = "is";
  string c = "a";
  string d = "sentence";
  vector<string> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  v.push_back(d);
  WordCount test;
  int x = 0;
  //  for(int i=0;i<v.size();i++)
  // {
  //   test.incrWordCount(v[i]);
  //     }
  //WordCount test;
  //test.incrWordCount(a);
  //int two = test.incrWordCount("is");
  //int three = test.incrWordCount("a");
  //int four = test.incrWordCount("sentence");
  test.addAllWords("Sentence is a a a sentence.");
  cout << test.getNumUniqueWords() << endl;
  cout << "Alphabetically:" << endl;
  test.dumpWordsSortedByWord(std::cout);
  cout << "By Occurance:" << endl;
  test.dumpWordsSortedByOccurence(std::cout);
  cout << endl;
  return 0;
}
