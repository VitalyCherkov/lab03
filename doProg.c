#include "doProg.h"

int strcmpMask(const void* a, const void* b){
  return strcmp((const char*) a, (const char*) b);
}

struct listNode* inputList(FILE* fl, const size_t maxLen){
  if(!fl)
    return NULL;
  struct listNode* head = NULL;
  char tempStr[maxLen];
  while(fscanf(fl, "%s[^ \n\t\r\v\f]", tempStr) == 1){
    struct listNode* newNode = NULL;
    createNode(&newNode, tempStr, strlen(tempStr) + 1);
    int res = insertBeforeSmaller(&head, newNode, strcmpMask);
    if(res == EXIT_FAILURE){
      fprintf(stderr, "Word '%s' wasn't read corrent\n", tempStr);
    }
  }
  return head;
}

void printList(FILE *fl, struct listNode *head){
  if(!fl || !head)
    return;

  while(head){
    if(!head->data)
      fprintf(stderr, "Empty data %zu\n", (size_t)&(head->data));
    else
      fprintf(fl, "%s\n", (char*)head->data);
    head = getNextNode(head);
  }
}

void freeList(struct listNode **head){
  if(!head || !(*head))
    return;

  while(*head){
    freeNode(head);
  }
}

int doProg(const char* inFl, const char* outFl){
  if(!inFl || !outFl){
    printf("Empty name(s) of file(s)\n");
    return EXIT_FAILURE;
  }
  const int maxLen = 20;

  FILE* fin = fopen(inFl, "r");
  if(!fin){
    printf("Can not read file %s\n", inFl);
    return EXIT_FAILURE;
  }
  struct listNode* head = inputList(fin, maxLen);
  fclose(fin);
  if(!head){
    printf("File was not read\n");
    return EXIT_FAILURE;
  }

  FILE* fout = fopen(outFl, "w");
  if(!fout){
    printf("Can not write in file %s\n", outFl);
    freeList(&head);
  }
  printList(fout, head);
  fclose(fout);
  freeList(&head);

  return EXIT_SUCCESS;
}
