// WordCount.cpp
// Written by Richert Wang for CS 32, F18.

#include "WordCount.h"
#include <queue>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <functional>
#include <vector>
#include <cctype>
#include <bits/stdc++.h>
#include <fstream>

// Default constructor
WordCount::WordCount()
{
   for(unsigned int i=0;i<CAPACITY;i++)
     table[i].clear();
}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
  int count = 0;
  for(unsigned i=0;i<CAPACITY;i++)
    {
      for(unsigned j=0;j<table[i].size();j++)
	{
	  count += static_cast<int>((table[i].at(j)).second);
	}
    }
  return count;
}

int WordCount::getNumUniqueWords() const {
  int count = 0;
  for(unsigned i=0;i<CAPACITY;i++)
    {
      for(unsigned j=0;j<table[i].size();j++)
	{
	  count++;
	}
    }
  return count;
}

int WordCount::getWordCount(std::string word) const {
  std::string search = stripWord(word);
  size_t index = hash(search);
  for(unsigned j=0;j<table[index].size();j++)
    {
      if(((table[index].at(j)).first).compare(search)==0)
	{
	  return static_cast<int>((table[index].at(j)).second);
	}
    }
  return 0;
}
	

int WordCount::incrWordCount(std::string word) {
  std::string search = stripWord(word);
  std::string nword = "";
  for(unsigned i=0;i<search.length();i++)
    {
      nword += toupper(search[i]);
    }
  size_t index = hash(nword);
  int nIndex = 0;
  if(nword.compare("")!=0)
    {
      if(getWordCount(nword)!=0)
	{
	  for(unsigned j=0;j<table[index].size();j++)
	    {
	      if(((table[index].at(j)).first).compare(nword)==0)
		{
		  nIndex = j;
		}
	    }
	  (table[index].at(nIndex)).second++;
	  return (table[index].at(nIndex)).second;
	}
      else
	{
	  std::pair<std::string,size_t> ins;
	  ins.first = nword;
	  ins.second = 1;
	  table[index].push_back(ins);
	  return 1;
	}
    }
  return 0;
}


bool WordCount::isWordChar(char c) {
  return isalpha(c);
}


std::string WordCount::stripWord(std::string word) {
  std::string res ="";
  for(unsigned i=0;i<word.length();i++)
    {
      if(isalpha(word[i]))
	{
	  res+=word[i];
	}
      else if(word[i]=='/' || word[i]=='-')
	{
	  if(i==0 || i==word.length()-1)
	    {

	    }
	  else if(!isalpha(word[i-1])||!isalpha(word[i+1]))
	    {

	    }
	  else
	    {
	      res+=word[i];
	    }
	}
    }
  return res;
}

struct wordCompare
{
  bool operator()(const std::pair<std::string,size_t>&one, const std::pair<std::string, size_t>&two)
  {
    return two.first < one.first;
  }
};

struct occuranceCompare
{
  bool operator()(const std::pair<std::string,size_t>&one, const std::pair<std::string, size_t>&two)
  {
    if(one.second != two.second)
      {
	return two.second > one.second;
      }
    return two.first < one.first;
  }
};

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
  std::priority_queue<std::pair<std::string,size_t>,std::vector<std::pair<std::string, size_t>>,wordCompare> pq;
  for(unsigned i = 0;i<CAPACITY;i++)
    {
      for(unsigned j=0;j<table[i].size();j++)
	{
	  pq.push(table[i].at(j));
	}
    }
  while(!pq.empty())
    {
      out << (pq.top()).first << "," << (pq.top()).second << std::endl;
      pq.pop();
    }
	return;
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
  std::priority_queue<std::pair<std::string,size_t>,std::vector<std::pair<std::string, size_t>>,occuranceCompare> pq;
  for(unsigned i=0;i<CAPACITY;i++)
    {
      for(unsigned j=0;j<table[i].size();j++)
	{
	  pq.push(table[i].at(j));
	}
    }
  while(!pq.empty())
    {
      out << (pq.top()).first << "," << (pq.top()).second << std::endl;
      pq.pop();
    }
	return;
}

void WordCount::addAllWords(std::string text) {
  int x=0;
  std::string res = "";
  for(int i=0;i<text.size();i++)
    {
      if(x > -1)
	{
	  if(text[i]== ' ' || text[i] == '\n')
	    {
	      std::string temp = stripWord(res);
	      x = incrWordCount(temp);
	      res = "";
	    }
	  else
	    {
	      res+=text[i];
	    }
	}
    }
  x = incrWordCount(stripWord(res));
	return;
}
