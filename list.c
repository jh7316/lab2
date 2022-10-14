#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "list.h"

// In this series of exercises, you'll implement a simple linked list storing 
// a collection of key/value pairs sorted alphabetically by key strings.
// You should read the type definition of linked list node in list.h file

// list_init initializes a sorted (linked) list.
// A linked list is identified by its head pointer. 
// To initialize a list, this function sets its head pointer to NULL.
// This function takes as its argument "headdp", a double pointer that 
// points to the head pointer to be initialized.
void list_init(lnode_t **headdp)
{
  //TODO: your code here
  *headdp=NULL;

}

// sum_accum is an accumulator function that adds "new_val" into the 
// current sum value pointed to by "existing_val".
// This function has already been implemented for you.
void sum_accum(int *existing_val, int new_val)
{
  (*existing_val) += new_val;
}

// Insert a key value pair into the linked list while maintaining sorted order. 
// Return true if the key does not already exists; false otherwise.
//
// If the key already exists, accumulate the new value into the existing value 
// using the given function pointer "accum".  The implementation of an example 
// accumulator function can be seen earlier (sum_accum)
//
//
// Notes: 1) you need to allocate space for a new linked list node, 
// but you do not need to allocate space to copy the entire key string; it's enough to 
// store the key string pointer in the linked list node.
// 2) since the new node may be inserted in the beginning of the list, 
// you may need to change the head pointer of the linked list.
// Therefore, this function takes as its arguments "headdp", a double pointer
// that points to the head pointer of the linked list, thereby allowing you to change 
// the head pointer.
//
// You may use strcmp from C library (instead of your own string_cmp in str.h).
bool list_insert_with_accum(lnode_t **headdp, char *key, int val, 
    void (*accum)(int *existing_val, int new_val))
{
  //TODO: Your code here
  lnode_t *curr=*headdp;
  
  //allocating space for new linked list node 
  lnode_t *newNode=malloc(sizeof(lnode_t));
  newNode->tuple.key=key;
  newNode->tuple.val=val;


  //Case 1:empty list or new node has smallest key
  //insert new node at beginning, change head pointer
  if(curr==NULL || strcmp(key,curr->tuple.key)<0){
     newNode->next = *headdp;
     *headdp=newNode;
     return true;
  }
  
 
	
   //traverse through list
   while(curr->next){
     if(strcmp(key,(curr->next)->tuple.key)>=0)
         curr=curr->next;
     else
         break; //traverse through list until the next key > current key 
   }

   //Case 3:key exists, accumulate value
   if(strcmp(key,curr->tuple.key)==0){
      (*accum)(&(curr->tuple.val),val);
      return false;
   }else{
      //Case 4: new node has largest key
      if(curr->next==NULL)
	  curr->next=newNode;
      else{
 	  //Case 5: new node has a key value in between the existing keys
          newNode->next=curr->next;
          curr->next=newNode;
	   }
      return true;
    }
     

  

}

// Find if a given key string exists in the sorted linked list.
// Return the value associated with the key if key is found.
// Otherwise, return -1.
// This function takes as argument headp, a single pointer that points to 
// the first linked list node
// 
// You may use strcmp from C library (instead of your own string_cmp in str.h).
int list_find(lnode_t *headp, char *key)
{
  // TODO: Your code here
  lnode_t *curr=headp; 
  while(curr!=NULL){

	if(strcmp(key,curr->tuple.key)==0){
	 return curr->tuple.val;
        }
      
        curr=curr->next;
  }
  return -1;

}

// Traverse the linked list starting from node pointed to by "headp" 
// and store all the encountered key-value tuples in the array "tuples".
// The capacity of the "tuples" array is "max", thus, the function should not 
// store more than "max" pointers in "tuples".
// Return value is the actual number of key-value tuples 
// written to "tuples".
int list_get_all_tuples(lnode_t *headp, kv_t *tuples, int max)
{
  // TODO: Your code here
  //curr keeps track of linked list
  //cnt keeps track of tuples array
  lnode_t *curr=headp;
  int cnt=0;
 
  //traverse while cnt and curr are within their range
  while(cnt<max && curr!=NULL){
	tuples[cnt]=curr->tuple;
       curr=curr->next;
	cnt++;
  }
  return cnt;
}

