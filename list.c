#include "list.h"

void createNode(struct listNode** newNode, const void* data, const size_t sizeOfData){
  if(!newNode || !data || sizeOfData <= 0)
    return;

  (*newNode) = malloc(sizeof(struct listNode));
  if(!(*newNode))
    return;

  (*newNode)->data = malloc(sizeOfData);
  if(!(*newNode)->data){
    free(*newNode);
    *newNode = NULL;
    return;
  }

  if(!memcpy((*newNode)->data, data, sizeOfData)){
    freeNode(newNode);
    return;
  }
  (*newNode)->next = NULL;
}

struct listNode* getNextNode(const struct listNode* head){
  if(!head || head->next == NULL)
    return NULL;

  return head->next;
}

int insertBeforeSmaller(
  struct listNode** head, struct listNode* newData,
  int (*cmp)(const void*, const void*)
){
  if(!head || !newData)
    return EXIT_FAILURE;
  if(!(*head) || cmp((*head)->data, newData->data) <= 0){
    newData->next = (*head) ? (*head)->next : NULL;
    *head = newData;
    return EXIT_SUCCESS;
  }

  struct listNode* localHead = *head;
  while(localHead->next && cmp(localHead->next->data, newData->data) > 0){
    localHead = localHead->next;
  }
  newData->next = localHead->next;
  localHead->next = newData;

  return EXIT_SUCCESS;
}

void freeNode(struct listNode** head){
  if(!head || !(*head))
    return;

  if(!(*head)->next){
    free((*head)->data);
    free(*head);
    *head = NULL;
    return;
  }

  if((*head)->data)
    free((*head)->data);
  (*head)->data = (*head)->next->data;
  struct listNode* newNext = (*head)->next->next;
  free((*head)->next);
  ((*head)->next) = newNext;
}
