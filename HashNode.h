#ifndef MY_HASH_NODE
#define MY_HASH_NODE
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

template <class KeyType, class ValueType>
class HashNode {
  KeyType key;     // The hash node's key
  ValueType value; // The key's associated data
  /* extend if necessary */

public:

  HashNode();  // constructor

  KeyType getKey() { return key; }
  ValueType getValue() { return value; }
  void assign(KeyType key, ValueType value); 

  // extend if necessary
};
template <class KeyType, class ValueType>
HashNode<KeyType,ValueType>::HashNode() 
{
  key = 'n';
  value = 'o';

}
template <class KeyType, class ValueType>
KeyType getkey();

template <class KeyType, class ValueType>
ValueType getValue();

template <class KeyType, class ValueType>
void HashNode<KeyType, ValueType>::assign(KeyType keyinput, ValueType valueIn)
{
  key = keyinput;
  value = valueIn;
}
/* 
   Implement the constructor, the assign method 
   and any methods that you may additionally need for the HashTable to work.
*/

#endif
