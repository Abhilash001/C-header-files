/*
* Author: Abhilash Misra 
* Version: v1.1
* 
* Created: Monday, August 08, 2016, 6:01:43 AM
* Copyright (C) 2016 under the GNU General Public License. All rights reserved.
* 
*/

#ifndef LINK_H_
#define LINK_H_

/*
* The following functions have been implemented:
*
* 1) getNode(): 								return type struct link *.
* 2) putData(struct link *node): 						return type void.
* 3) Continue(): 								return type int.
* 4) display(struct link *node): 						return type void.
* 5) len(struct link *node): 							return type int.
* 6) pop(struct link *head): 							return type void.
* 7) append(struct link *head, int data): 					return type void.
* 8) indexOf(struct link *head, int n): 					return type int.
* 9) inList(struct link *head, int n):						return type int.
* 10) data_in(struct link *head, int pos): 					return type int.
* 11) clone(struct link *head): 						return type struct link *.
* 12) sublist(struct link *head, int lb, int ub): 				return type struct link *.
* 13) sort(struct link *head): 							return type void.
* 14) sorted(struct link *head):						return type struct link *.
* 15) reverse(struct link *head): 						return type struct link *.
* 16) insert(struct link *head, int data, int pos): 				return type void.
* 17) delete(struct link *head, int pos):					return type void.
* 18) concat(struct link *l1, struct link *l2):					return type struct link *.
* 19) getInput():								return type struct link *.
* 20) newList(char *s):								return type struct link *.
* 21) sum(struct link *head):							return type int.
* 22) max(struct link *head):							return type int.
* 23) min(struct link *head):							return type int.
* 24) count(struct link *head, int n):						return type int.
* 25) equal(struct link *l1, struct link *l2):					return type int.
* 26) set(struct link *head):							return type struct link *.
* 27) intersect(struct link *l1, struct link *l2):				return type struct link *.
* 28) Union(struct link *l1, struct link *l2):					return type struct link *.
*
* More functions may get added as required.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Linked list structure containing data and next node.
*/
struct link 
{
	int data;
	struct link *next;
};

/*
* Returns an allocated memory address and sets next node as NULL.
*/
struct link *getNode()
{
	struct link *node;
	node = (struct link *)malloc(sizeof(struct link *));
	node->next = NULL;
	return node;
}

/*
* Returns user choice to continue or not.
* Basically 0 to stop else continue adding elements.
*/
int Continue()
{
	int ch;
	printf("Enter 0 to stop or non zero to continue: ");
	scanf("%d", &ch);
	return ch;
}

/*
* Takes input and adds data to node.
*/
void putdata(struct link *node)
{
	int data;
	scanf("%d", &data);
	node->data = data;
}

/*
* Displays the list in box brackets.
*/
void display(struct link *node)
{
	printf("List = [");
	while(node!=NULL)
	{
		if(node->next!=NULL) printf("%d, ", node->data);
		else printf("%d", node->data);
		node = node->next;
	}
	printf("]\n");
}

/*
* Returns length of list.
*/
int len(struct link *node)
{
	int n = 0;
	while(node!=NULL&&++n) node = node->next;
	return n;
}

/*
* Deletes the last node of the list.
*/
void pop(struct link **head)
{
	if((*head)!=NULL)
	{
		struct link *temp;
		struct link *t;
		if((*head)->next==NULL)
		{
			free((*head));
			(*head) = NULL;
		}
		else
		{
			temp = *head;
			while(temp->next!=NULL)
			{
				t = temp;
				temp = temp->next;
			}
			free(temp);
			t->next = NULL; 
		}
	}
}

/*
* Inserts data at the end of the list.
*/
void append(struct link **head, int data)
{
	struct link *node = *head;
	if((*head)==NULL)
	{
		(*head) = getNode();
		node = (*head);
	}
	else
	{
		while(node->next!=NULL) node = node->next;
		node->next = getNode();
		node = node->next;
	}
	node->data = data;
	node->next = NULL;
}

/*
* Returns index of an integer n in a list.
* -1 otherwise.
*/
int indexOf(struct link *head, int n)
{
	struct link *node = head;
	int i = 0;
	while(node!=NULL)
	{
		if(node->data==n) return i;
		node = node->next;
		i++;
	}
	return -1;
}

/*
* Returns 1 if integer n is in list.
* 0 otherwise.
*/
int inList(struct link *head, int n)
{
	struct link *node = head;
	while(node!=NULL)
	{
		if(node->data==n) return 1;
		node = node->next;
	}
	return 0;
}

/*
* Returns data at position pos of list.
* Returns last element if pos exceeds length of list.
*/
int data_in(struct link *head, int pos)
{
	int i=0;
	struct link *node;
	node = head;
	while(node!=NULL)
	{
		if(i++==pos) return node->data;
		node = node->next;
	}
	return NULL;
}

/*
* Returns an INDEPENDENT COPY of the list sent.
*/
struct link *clone(struct link *head)
{
	struct link *new_head;
	new_head = NULL;
	if(head!=NULL)
	{
		new_head = getNode();
		struct link *node = new_head, *temp = head;
		while(temp->next!=NULL)
		{
			node->data = temp->data;
			node->next = getNode();
			temp = temp->next;
			node = node->next;
		}
		node->data = temp->data;
		node->next = NULL;
	}
	return new_head;
}

/*
* Returns an INDEPENDENT COPY of the list sent, from index lb to ub, EXCLUDING data in ub.
* Returns till end of list if ub exceeds length of list.
*/
struct link *sublist(struct link *head, int lb, int ub)
{
	struct link *new_head;
	new_head = NULL;
	int i = 0;
	while(head!=NULL&&i<lb) {head = head->next; i++;}
	if(head!=NULL)
	{
		new_head = getNode();
		struct link *node = new_head, *temp = head;
		while(temp!=NULL&&i++<ub)
		{
			node->data = temp->data;
			if(temp->next!=NULL&&i<ub) node->next = getNode();
			else 					   node->next = NULL;
			temp = temp->next;
			node = node->next;
		}
	}
	return new_head;
}

/*
* Sorts the list, changes made are permanent.
*/
void sort(struct link *head)
{
	int i,j;
	for(i=0; i<len(head)-1; i++)
	{
		struct link *node;
		node = head;
		for(j=0; j<len(head)-i-1; j++)
		{
			if(node->data>node->next->data)
			{
				int t = node->data;
				node->data = node->next->data;
				node->next->data = t;
			}
			node = node->next;
		}
	}
}

/*
* Returns sorted form of list.
* No changes made to original list.
*/
struct link *sorted(struct link *head)
{
	struct link *copy = clone(head);
	sort(copy);
	return copy;
}

/*
* Reverses the linked list.
*/
struct link *reverse(struct link *head) 
{
	struct link *node = NULL, *temp;
	while(head!=NULL)
	{
		temp = head->next;
		head->next = node;
		node = head;
		head = temp;
	}
	return node;
}

/*
* Inserts data at specific given position pos.
* Inserts at end if pos exceeds length of list.
*/
void insert(struct link **head, int data, int pos)
{
	struct link *node = *head, *temp = NULL;
	if((*head)==NULL)
	{
		(*head) = getNode();
		node = (*head);
		node->next = NULL;
	}
	else if(pos!=0)
	{
		int i=0;
		while(node->next!=NULL&&++i<pos) node = node->next;
		temp = node->next;
		node->next = getNode();
		node = node->next;
		node->next = temp;
	}
	else
	{
		(*head) = getNode();
		(*head)->next = node;
		node = (*head);
	}
	node->data = data;
}

/*
* Deletes node at specific given position pos.
* Deletes last node if pos exceeds length of list.
*/
void delete(struct link **head, int pos)
{
	if((*head)!=NULL)
	{
		struct link *temp = *head;
		struct link *t;
		if((*head)->next==NULL)
		{
			free((*head));
			(*head) = NULL;
		}
		else if(pos!=0)
		{
			int i=0;
			while(temp->next!=NULL&&i++<pos)
			{
				t = temp;
				temp = temp->next;
			}
			t->next = temp->next;
			free(temp);
			temp = NULL;
		}
		else
		{
			(*head) = (*head)->next;
			free(temp);
			temp = NULL;
		}
	}
}

/*
* Returns a merged list from merging lists l1 and l2.
* l1 and l2 remain intact so long as its not returned to either one of them.
* Eg: l1 = concat(l1, l2) would change l1.
*/
struct link *concat(struct link *l1, struct link* l2)
{
	struct link *head1 = clone(l1), *head2 = clone(l2);
	struct link *temp = head1, *node = head1;
	if(head1==NULL)
	{
		node = head2;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = head2;
	}
	return node;
}

/*
* Returns an allocated memory to be used as start node and adds nodes to list as required by user.
* Simply put, creates and returns a new list with user inputted data.
*/
struct link *getInput()
{
	struct link *head = getNode();
	int i = 0;
	printf("Enter data for node %d: ", (i++));
	putdata(head);
	struct link *node;
	node = head;
	while(Continue())
	{
		printf("Enter data for node %d: ", (i++));
		node->next = getNode();
		node = node->next;
		putdata(node);
	}
	return head;
}

/*
* Returns an allocated memory to be used as start node and adds nodes to list with data given in string s
* Simply put, creates and returns a new list with the integers in string s.
*/
struct link *newList(char *s)
{
	struct link *head = NULL;
	if(strlen(s)!=0)
	{
		int data, offset;
		head = getNode();
		sscanf(s, "%d %n", &data, &offset);
		head->data = data;
		s+=offset;
		struct link *node;
		node = head;
		while(sscanf(s, "%d %n", &data, &offset)==1)
		{
			node->next = getNode();
			node = node->next;
			node->data = data;
			s+=offset;
		}
	}
	return head;
}

/*
* Returns sum of all data in list.
*/
int sum(struct link *head)
{
	int s = 0;
	while(head!=NULL)
	{
		s+=head->data;
		head = head->next;
	}
	return s;
}

/*
* Returns maximum data in list.
*/
int max(struct link *head)
{
	int s = head->data;
	while(head->next!=NULL)
	{
		head = head->next;
		if(head->data>s) s = head->data;
	}
	return s;
}

/*
* Returns minimum data in list.
*/
int min(struct link *head)
{
	int s = head->data;
	while(head->next!=NULL)
	{
		head = head->next;
		if(head->data<s) s = head->data;
	}
	return s;
}

/*
* Counts and returns frequency of integer n in list.
*/
int count(struct link *head, int n)
{
	int c = 0;
	while(head!=NULL)
	{
		if(head->data==n) c++;
		head = head->next;
	}
	return c;
}

/*
* Returns 1 if lists are equal both lengthwise and datawise.
* 0 otherwise.
*/
int equal(struct link *l1, struct link *l2)
{
	if(len(l1)==len(l2))
	{
		while(l1!=NULL)
		{
			if(l1->data!=l2->data) return 0;
			l1 = l1->next;
			l2 = l2->next;
		}
		return 1;
	}
	return 0;
}

/*
* Return the set form of a list, i.e., without any duplicate elements,
* which fits the definition of a set. (Removes duplicate elements in a list.)
*/
struct link *set(struct link *head)
{
	struct link *no_repeat = NULL, *temp = clone(head);
	int i = 0, j = len(temp);
	while(temp!=NULL)
	{
		while(inList(sublist(temp, i+1, j), temp->data))
			delete(&temp, indexOf(sublist(temp, i+1, j), temp->data)+i+1);
		append(&no_repeat, temp->data);
		temp = temp->next;
		i++;
	}
	return no_repeat;
}

/*
* Returns the intersection of two lists, i.e., a list containing all the common elements 
* between l1 and l2.
*/
struct link *intersect(struct link *l1, struct link *l2)
{
	struct link *inter = NULL, *temp = set(l1);
	while(temp!=NULL)
	{
		if(inList(l2, temp->data))
			append(&inter, temp->data);
		temp = temp->next;
	}
	return inter;
}

/*
* Returns the Union of two lists, i.e., a list containing all the elements in 
* l1 and l2 without duplicate elements.
*/
struct link *Union(struct link *l1, struct link *l2)
{
	struct link *un, *temp = set(l1), *temp2 = set(l2);
	struct link *inter = intersect(temp, temp2);
	while(inter!=NULL)
	{
		delete(&temp2, indexOf(temp2, inter->data));
		inter = inter->next;
	}
	un = concat(temp, temp2);
	return un;
}

#endif
