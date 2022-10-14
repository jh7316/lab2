#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

//Please read through the type declaration in htable.h
#include "htable.h"

// This function creates and initializes a new htable 
// It returns a pointer to the newly created htable struct (htable_t)
// The argument "capacity" specifies the size of 
// internal hash table array to allocate.
// Note that this function needs to perform 2 allocations;
// one for the htable struct, the other for the internal 
// hash table array.
// Note that you need to initialize the htable struct fields,
// including all the entries in the internal hash table array.
htable_t *htable_create(unsigned int capacity)
{
  //TODO: Your code here
  //2 memory allocations: one for htable, one for hash table array
  htable_t *table = malloc(sizeof(htable_t));
  lnode_t **int_arr = malloc(sizeof(lnode_t*) * capacity);
 
 //initializing the table struct fields 
  table->arr = int_arr;
  table->arr_capacity = capacity;

  return table;

}

// This function is used internally by the hash table to calculate 
// the hashcode for a string with n characters, s[0...n-1]
//
// We'll use the common formula for calculating a string's hashcode:
// hashcode = s[0]*31^(n-1) + s[1]*31^(n-2) + .... + s[n-1]
// where ^ means exponentiation.
unsigned int hashcode(char *s)
{ 
  //TODO: Your code here
  int i;
  unsigned int hcode= 0;
  int n=strlen(s);
  int j; int m=1;
 
 //calculate 31^(n-1) using for loop 
  for(j=0;j<n-1;j++) m*=31; 

  //calculate hcode using for loop
  for(i=0;i<n;i++){
    hcode  += s[i]*m; 
    m/=31; //decrease the exponent of 31  
  }
  return hcode;

}


// This function inserts a key value pair to the hash table.
// If the key already exists, accumulate the new value into the existing value 
// using the given function pointer "accum". 
//
// The insertion takes the following steps:
// 1) calculate the hashcode of the given key  "key"
// 2) use the calculated hashcode to index into the table's 
// array of linked list. i = hashcode % ht->arr_capacity
// 3) insert the key in the indexed list ht->arr[i] using 
// list_insert_with_accum that you've implmeneted in list.c
//
// Note that you should update the ht->size field accordingly
void htable_put(htable_t *ht, char *key, int val, 
    void (*accum)(int *existing_val, int new_val))
{
  //TODO: Your code here
  unsigned int hcode = hashcode(key); //step 1)
  unsigned int i = hcode % ht->arr_capacity; //step 2)
  list_insert_with_accum(&(ht->arr[i]), key, val, (*accum)); //step 3)


}

// This function finds "key" in the hash table
// and returns the pointer to its associated value.
// It takes the following steps:
// 1) calculate the hashcode of the given key  "key"
// 2) use the calculated hashcode to index into the table's 
// array of linked list. i = hashcode % ht->arr_capacity
// 3) find the value associated with key in the indexed list ht->arr[i] using 
// list_find that you've implmeneted in list.c 
int htable_get(htable_t *ht, char *key)
{
  //TODO: Your code here
  unsigned int hcode = hashcode(key); //step 1)
  unsigned int i = hcode % ht->arr_capacity; //step2)
  return list_find(ht->arr[i], key); //step 3)

}

// Traverse the hash table pointed to by "ht" and store 
// all the key-value tuples encountered in the hash table in the 
// array "tuples".  The capacity of the array "tuples" is "max". 
// Thus, the function should not store more than "max" entries
// in "tuples".
//
// Return the actual number of key-value tuples 
// written to "tuples".
int htable_get_all_tuples(htable_t *ht, kv_t *tuples, int max)
{
  //TODO: Your code here
  //cnt keeps track of tuples, int keeps track of ht
  int cnt = 0; int i = 0;

  //make sure it does not store more than "max" entries
  while(cnt<max && i<ht->arr_capacity){
    lnode_t* curr = ht->arr[i];

    //stores all key value pairs of current node into tuples 
    while(curr){
      tuples[cnt] = curr->tuple;
      curr = curr->next;
      cnt++;
    }
    i++;
  }
  return cnt;

}

