#ifndef MY_HASH_TABLE
#define MY_HASH_TABLE
#include <iostream>
#include <string>
#include <vector>
#include "HashNode.h"
#include <string>
using namespace std;

enum HashTableError { OUT_OF_MEMORY, KEY_NOT_FOUND, DUPLICATE_KEY }; // extend if necessary

template <class KeyType, class ValueType>
class HashTable {
  typedef vector <HashNode<KeyType,ValueType> > Table;
  Table *table; // size of table (# of buckets) is stored in the Table data structure
  int num;   // number of entries stored in the HashTable;
  const int UNKNOWN_TYPE_FOUND = -1;
public:
  HashTable();        // constructor, initializes table of size 11;
  HashTable(int);  // constructor, requires size of table as arg
  ~HashTable();       // deconstructor
  int size();      // returns size of the hash table (number of buckets)
  template <typename L>
  int isType(L);
  int isType(string);
  int isType(char);
  int isType(int);
  int hash_function(KeyType);  // the table's hash function
  ValueType getValue(KeyType);    // find and return data associated with key

  void insert(KeyType,ValueType); // insert data associated with key into table
  void erase(KeyType);            // remove key and associated data from table

  void rehash(int); // sets a new size for the hash table, rehashes the hash table 
  // extend if necessary
  KeyType getKey();
};
// This method checks if the keytype is not a string or char.
template <class KeyType, class ValueType>
template <typename T>
int HashTable<KeyType, ValueType>::isType(T)
{ 
  return UNKNOWN_TYPE_FOUND; 
}

template <class KeyType, class ValueType>
int HashTable<KeyType, ValueType>::isType(char )
{ 
  return 1; 
}
template <class KeyType, class ValueType>
int HashTable<KeyType, ValueType>::isType(int f )
{ 
  return f; 
}

template <class KeyType, class ValueType>
int HashTable<KeyType, ValueType>::isType(string input)
{ 
  return input.size(); 
}


template <class KeyType, class ValueType>
int HashTable<KeyType, ValueType>:: hash_function(KeyType key )
{
hash<KeyType> hashy; 
int hashKey = (hashy(key)+isType(key)) % size();
return hashKey;
}

template <class KeyType, class ValueType>
void HashTable<KeyType, ValueType>::erase(KeyType key)
{
  int hash = hash_function(key);
  HashNode <KeyType, ValueType> newNode = HashNode<KeyType, ValueType>();
 table->at(hash) = newNode;
}   

template <class KeyType, class ValueType>
void HashTable<KeyType, ValueType>::rehash(int k)
{
  
  Table *tempTable = new Table(); 
  int length = table->size();
  tempTable->reserve(size());
  tempTable->resize(size());
  for (int i = 0; i < size(); i++)
  {
  // swap(table->at(i),tempTable->at(i));
  }
  
  table->clear();
  table->reserve(k);
  table->resize(k);

  for (int i = 0; i < length; i++)
  {
    swap(table->at(i),tempTable->at(i));
  }
  
}
template <class KeyType, class ValueType>
HashTable<KeyType,ValueType>::HashTable() 
{
  table = new Table(); 
  table->reserve(11);
  table->resize(11);
}

template <class KeyType, class ValueType>
HashTable<KeyType,ValueType>::HashTable(int size) 
{
  table = new Table(); 
  table->reserve(size);
  table->resize(size);
}
template <class KeyType, class ValueType>
HashTable<KeyType,ValueType>::~HashTable( ) 
{  
    delete(table);
}
template <class KeyType, class ValueType>
int HashTable<KeyType,ValueType>::size() {
  return table->size();
}
template <class KeyType, class ValueType>
void HashTable<KeyType, ValueType>::insert(KeyType key ,ValueType value)
{
  int hash = hash_function(key);
  HashNode <KeyType, ValueType> newNode = HashNode<KeyType, ValueType>();
  newNode.assign(key,value);
  table->at(hash) = newNode;
}
template <class KeyType, class ValueType>
ValueType HashTable<KeyType, ValueType>::getValue(KeyType key)
{
      return table->at(hash_function(key)).getValue();
  
}
/* Implement the 
- Constructors, Destructor
- hash_function, insert, getValue methods
- erase, and rehash methods 
*/
#endif