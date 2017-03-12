#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode{
  void* data;
  struct listNode* next;
};

void createNode(struct listNode** newNode, const void* data, const size_t sizeOfData);
struct listNode* getNextNode(const struct listNode* head);
int insertBeforeSmaller(struct listNode** head, struct listNode* newData,
  int (*cmp)(const void*, const void*));
void freeNode(struct listNode** head);

#endif
