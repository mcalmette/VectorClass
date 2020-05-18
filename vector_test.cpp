//----------------------------------------------------------------------
// Author: Michael Calmette
// File:   hw3_test.cpp
//----------------------------------------------------------------------

#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "vector_collection.h"

using namespace std;


// Test 1

TEST(BasicListTest, CorrectSize) {
  VectorCollection<string,double> c;
  ASSERT_EQ(0, c.size()); //eq means == 
  c.add("b", 10.0);
  ASSERT_EQ(1, c.size());
  c.add("a", 20.0);
  ASSERT_EQ(2, c.size());
  c.add("c", 20.0);
  ASSERT_EQ(3, c.size());
   
}

// Test 2
TEST(BasicListTest, SimpleFind) {
  VectorCollection<string,double> c;
  double v;
  ASSERT_EQ(false, c.find("b", v));
  c.add("b", 10.0);
  ASSERT_EQ(true, c.find("b", v));
  ASSERT_EQ(10.0, v);
  ASSERT_EQ(false, c.find("a", v));
  c.add("a", 20.0);
  ASSERT_EQ(true, c.find("a", v));
  ASSERT_EQ(20.0, v);
}

// Test 3
TEST(BasicListTest, SimpleRemoveElems) {
  VectorCollection<string,int> c;
  c.add("b", 10);
  c.add("a", 20);
  c.add("d", 30);
  c.add("c", 30);
  ASSERT_EQ(4, c.size());
  int v;
  c.remove("a");
  ASSERT_EQ(3, c.size());
  ASSERT_EQ(false, c.find("a", v));
  c.remove("b");
  ASSERT_EQ(2, c.size());
  ASSERT_EQ(false, c.find("b", v));  
  c.remove("c");
  ASSERT_EQ(1, c.size());
  ASSERT_EQ(false, c.find("c", v));  
  c.remove("d");
  ASSERT_EQ(0, c.size());
  ASSERT_EQ(false, c.find("c", v));  
}

// Test 4
TEST(BasicListTest, SimpleRange) {
  VectorCollection<int,string> c;
  c.add(50, "e");
  c.add(10, "a");
  c.add(30, "c");
  c.add(40, "d");
  c.add(60, "f");
  c.add(20, "b");
  vector<string> vs;
  c.find(20, 40, vs);
  ASSERT_EQ(3, vs.size());
  // note that the following "find" is a C++ built-in function
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "a"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "b")); //not equal
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "c"));
  ASSERT_NE(vs.end(), find(vs.begin(), vs.end(), "d"));
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "e"));  
  ASSERT_EQ(vs.end(), find(vs.begin(), vs.end(), "f"));  
}

// Test 5
TEST(BasicListTest, SimpleSort) {
  VectorCollection<string,int> c;
  c.add("a", 10);
  c.add("e", 50);
  c.add("c", 30);
  c.add("b", 20);
  c.add("d", 40);
  vector<string> sorted_ks;
  c.sort(sorted_ks);
  ASSERT_EQ(5, sorted_ks.size());
  // check if in sorted order
  for (int i = 0; i < int(sorted_ks.size()) -1; ++i)
    ASSERT_LE(sorted_ks[i], sorted_ks[i+1]);
}

//Test 6
TEST(BasicListTes, SimpleStocks) {
  VectorCollection<string,double> t;
  vector<string> sorted_tickers;
  t.sort(sorted_tickers); //test sort empty vector
  ASSERT_EQ(0, sorted_tickers.size()); //assert this test sort 
  t.add("AMZN", 2100); //add 5 stock tickers
  t.add("MSFT" , 189.20);
  t.add("APPL", 320);
  t.add("BA", 344.67);
  t.add("TSLA", 771.28); 
  ASSERT_EQ(5, t.size()); //check size
  double val = 771.28;
  string ticker = "TSLA";
  ASSERT_EQ(true, t.find("TSLA",val)); //check find
  ASSERT_EQ(true, t.find(ticker,val));
  t.sort(sorted_tickers); //sort alphabetically
  ASSERT_EQ(5, sorted_tickers.size());
  ASSERT_EQ(true, sorted_tickers.at(0) == "AMZN"); //check sort works
  ASSERT_EQ(true, sorted_tickers.at(1) == "APPL");
  ASSERT_EQ(true, sorted_tickers.at(2) == "BA");
  ASSERT_EQ(true, sorted_tickers.at(3) == "MSFT");
  ASSERT_EQ(true, sorted_tickers.at(4) == "TSLA");

  vector<string> keys1;
  t.keys(keys1); //test keys function by copying tickers
  ASSERT_EQ(5, keys1.size());
  ASSERT_EQ(true, keys1.at(0) == "AMZN");
  ASSERT_EQ(true, keys1.at(1) == "MSFT");
  
  vector<string> sorted_keys1;
  t.sort(sorted_keys1); //sort new vector
  ASSERT_EQ(5, keys1.size());
  ASSERT_EQ(true, sorted_keys1.at(0) == "AMZN");
  ASSERT_EQ(true, sorted_keys1.at(1) == "APPL");
  ASSERT_EQ(true, sorted_keys1.at(2) == "BA");
  ASSERT_EQ(5, sorted_keys1.size());
 
  t.remove("AMZN"); //check remove function
  ASSERT_EQ(4, t.size());
  double v;
  ASSERT_EQ(false, t.find("AMZN",v));
  ASSERT_EQ(true, t.find("MSFT",v));
}



int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


