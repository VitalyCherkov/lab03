#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int strcmpMask(const void* a, const void* b);
struct listNode* inputList(FILE* fl, const size_t maxLen);
void printList(FILE *fl, struct listNode *head);
void freeList(struct listNode **head);
int doProg(const char* inFl, const char* outFl);
