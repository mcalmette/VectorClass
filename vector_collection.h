//----------------------------------------------------------------------
// Author: Michael Calmette
// File:   vector_collection.h
//
// Description:  A collection object associated with a key and an 
// associated value.  All pairs have to be of the same data type.  The
// vector collection class implements the abstract collection class
// using vector objects.  The Collection class uses template types. This
// file includes the public/private members with the implementation
//----------------------------------------------------------------------

#ifndef VECTOR_COLLECTION_H
#define VECTOR_COLLECTION_H

#include <vector>
#include <algorithm>            
#include "collection.h"


template<typename K, typename V>
class VectorCollection : public Collection<K,V>
{
public:

  // add a new key-value pair into the collection 
  void add(const K& a_key, const V& a_val);

  // remove a key-value pair from the collectiona
  void remove(const K& a_key);

  // find and return the value associated with the key
  bool find(const K& search_key, V& the_val) const;

  // find and return the values with keys >= to k1 and <= to k2 
  void find(const K& k1, const K& k2, std::vector<V>& vals) const;
  
  // return all of the keys in the collection 
  void keys(std::vector<K>& all_keys) const;

  // return all of the keys in ascending (sorted) order
  void sort(std::vector<K>& all_keys_sorted) const;

  // return the number of key-value pairs in the collection
  int size() const;

private:
  std::vector<std::pair<K,V>> kv_list;
};


//returns the number of kv pairs in the collection
template <typename K, typename V>
int VectorCollection<K,V>::size() const
{
   return kv_list.size();
}


//adds a new key value pair by pushing it to the vector
template <typename K, typename V>
void VectorCollection<K,V>::add(const K& a_key,const V& a_val)
{
   std::pair<K,V> p(a_key,a_val);  
   kv_list.push_back(p);
}


//removes kv pair by reference
template <typename K, typename V>
void VectorCollection<K,V>::remove(const K& a_key)
{
   int i = 0;
   for(std::pair<K,V> p : kv_list) //loops through vector
   { 
       if(p.first == a_key)
       {
	   kv_list.erase(kv_list.begin() + i); //erase key
       }
      i++;
   }
}

//finds value associated with key and returns a bool
template <typename K, typename V>
bool VectorCollection<K,V>::find(const K& search_key, V& the_val) const
{
  
   for(std::pair<K,V> p : kv_list) //loop through vector
   {
	if(p.first == search_key)
	{
	     the_val = p.second;
	     return true; //value has been found
	}
   }

   return false;
}


//finds value between two sets of keys (k1 and k2)
template <typename K, typename V>
void VectorCollection<K,V>::find(const K& k1, const K& k2, std::vector<V>& vals) const
{
   
   for(std::pair<K,V> p : kv_list)
   {
	if(p.first >= k1 && p.first <= k2)
	{
	     vals.push_back(p.second);
	}	
	
   }
}


//return all keys in collections
template <typename K, typename V>
void VectorCollection<K,V>::keys(std::vector<K>& all_keys) const
{
   for(std::pair<K,V> p : kv_list)
   {
        all_keys.push_back(p.first); //push keys
   }

}


//Sort keys by using built in function
template <typename K, typename V>
void VectorCollection<K,V>::sort(std::vector<K>& all_keys_sorted) const
{
   if(kv_list.size() == 0) //makes sure it does not sort an empty list
	return;
    
   for(std::pair<K,V> p : kv_list)
   {
      all_keys_sorted.push_back(p.first);
   }

   std::sort(all_keys_sorted.begin(), all_keys_sorted.end());
}


#endif
