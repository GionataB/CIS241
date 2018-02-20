#include<stdio.h>
#include<stdlib.h>

#ifndef LAB3_H
#define LAB3_H

struct node
{
	int data;
	struct node *next;
};

struct node *init (); //initialize: create an empty head node (whose "data" is intentionally missing); This head node will not be used to store any data;

void insert(struct node *head, int data); //Create a new node to store data and insert it to the end of current linked list; the head node will still be empty and data in the array are not stored in head node

void display (struct node *head); //print data for all nodes in the linked list except the head node (which is empty)

void deleteAll (struct node *head); //delete the entire linked list including the head node

#endif
