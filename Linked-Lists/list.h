/********************************************************************************
 * Shervin Oloumi
 * list.h
 * This file contains declarations of all the functions used by the client program
 *******************************************************************************/


/* This program uses code from "Algorithms in C, Third Edition,"
 *               by Robert Sedgewick, Addison-Wesley, 1998.
 * 
 * Updated 9/29/2015 - Alexandra Stefan
 */


#ifndef LIST_H
#define	LIST_H

typedef int Item;
typedef struct node_struct * link;
typedef struct list_struct * list;  // Use pointers to hide the list 

/* Creates a new link, that contains the value specified in the argument, 
 * and that points to next_in. 
 * C++ feature: "link next_in = 0"
 * because of it, we will be able to call this method both ways:
 *      newLink(5);
 *      newLink(5, some_ptr);
 */
link newLink(Item value, link next_in = 0);

void destroyLink(link the_link); 

void setLinkItem(link the_link, Item value);

void setLinkNext(link the_link, link next);

/*  Note that these functions do not have all the security checks.
E.g. all the functions reading and setting members of a node pointer, do not
check that the node is not NULL  */

Item getLinkItem(link the_link);

link getLinkNext(link the_link);


/* LIST  */

// Creates and returns an empty list.
list newList();

// Deallocates memory for all nodes in the list.
void destroyList(list the_list);

// Returns a pointer to the first node in the list.
link getFirst(list the_list);

// Uses the field variable.
int getLength(list my_list);  

// Iterates through list and counts nodes.
int computeLength(list my_list);  

/* Sets the data to empty (first is null, length is 0,...)
 * It does NOT free any memory.
 */ 
void setEmpty(list the_list);


// Inserts new_link to the specified list, at the position right after
// the link called "previous".
void insertLink(list my_list, link previous, link new_link);

/* Inserts new_link to the beginning of the list. */
void insertAtBeginning(list my_list, link new_link);

// Removes from the list and returns the link coming AFTER link x. 
// This function DOES NOT  remove the link x itself. 
link removeNext(list my_list, link x);

// Removes and returns the first node from the list.
link removeFirst(list my_list);

void reverse(list the_list);

void printList(list my_list);

void printListHoriz(list my_list);

list listDeepCopy(list input);

// returns a new list that contains all values of input1 and all values 
// of input2
list concatLists(list input1, list input2);

// modifies target, by inserting at the end of it all links from source.
void concatListsDestructive(list target, list source);

/********************************************************************************
 * New functions added to the program. Authored by Shervin Oloumi
 *******************************************************************************/
 
void insertAtPosition(list A, Item val, int pos);

void deleteOccurrences(list A, Item V);

list sublist(list A, list pos_list);

void moveAllMaxAtEnd(list A);


#endif	/* LIST_H */

