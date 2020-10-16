// Linked list C-Code
// by Mehmet Akif Ortayagci


#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"
#include <sys/time.h>

typedef struct node node;

struct node {
  int data;
  node* next;
};


int list_length(node* n){

  int counter = 1;

  if (n == NULL)
    return 0;

  while (n->next != NULL){
    n = n->next;
    counter++;
  }

  return counter;

}



void add_element(node** n,int d) {

  if ((*n) == NULL) {
    (*n) = malloc(sizeof(node));
    (*n)->data=d;
    (*n)->next=NULL;
    }

  else{

      node* p = *n;                       /* notwendig, da der uebergebene Zeiger nicht "umgestellt" werden soll! */

      if (p->next == NULL)                /* Wenn nur ein Element vorhanden...*/
      {
        p->next = malloc(sizeof(node));
        p = p->next;
        p->data = d;
        p->next = NULL;
      }

      else
      {                               /* mehr als ein Element*/
        while (p->next != NULL)
        p = p->next;
        p->next = malloc(sizeof(node));
        p=p->next;
        p->data = d;
        p->next = NULL;
      }
    }

}


void print_list(node* n){

  if (n==NULL)
    printf("Die Liste ist leer!\n");

  else
    while (1){
      printf("%d\n",n->data);
      n = n->next;
      if(n == NULL)
        break;
      }

  printf("\n");

}



int main(int argc, char const *argv[]) {

  printf("Einfach verkettete Liste\n");

  node* list=NULL;

  add_element(&list,1);
  add_element(&list,9);
  add_element(&list,8);
  add_element(&list,7);
  add_element(&list,5);
  add_element(&list,3);
  print_list(list);
  printf("Die Liste enthaelt %d Elemente\n",list_length(list));

  return 0;
}
