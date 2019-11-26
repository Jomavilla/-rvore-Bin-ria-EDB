

#include <stdio.h>
#include <stdlib.h>



typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;


/* Função que cria uma árvore */
Tree* createTree()
{

  return NULL;
}

/* Função que verifica se uma árvore é vazia */
int treeIsEmpty(Tree* t)
{
  
  return t == NULL;

}

/* Função que mostra a informação da árvore */
void showTree(Tree* t)
{ 
  if(!treeIsEmpty(t)) 
  {
   
    showTree(t->sae); 
     printf("◄ %d ► ", t->num);
    showTree(t->sad);
  }
   
}

/* Função que insere um dado na árvore */
void insertTree(Tree** t, int num)
{
  
  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree)); 
    (*t)->sae = NULL; 
    (*t)->sad = NULL; 
    (*t)->num = num; 
  } else {
    if(num < (*t)->num) 
    {
      
      insertTree(&(*t)->sae, num);
    }
    if(num > (*t)->num) 
    {
      
      insertTree(&(*t)->sad, num);
    }
  }
}

/* Função que verifica se um elemento pertence ou não à árvore */
int isInTree(Tree* t, int num) {
  
  if(treeIsEmpty(t)) { 
    return 0;
  }
  
 
  return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}

int main()
{
  Tree* t = createTree(); /* cria uma árvore */
  
  insertTree(&t, 4); 
  insertTree(&t, 6);
  insertTree(&t, 8); 
  insertTree(&t, 11);
  insertTree(&t, 7);
  insertTree(&t, 3);
  insertTree(&t, 5);
  insertTree(&t, 1);
  insertTree(&t, 9);
  insertTree(&t, 2);
  insertTree(&t, 12);
  insertTree(&t, 10);
 
   
  showTree(t); 
  
  if(treeIsEmpty(t)) 
  {
    printf("\n\nArvore vazia!!\n");
  } else {
    printf("\n\nArvore NAO vazia!!\n");
  }
  
  if(isInTree(t, 8)) { 
    printf("\nO numero 8 pertence a arvore!\n");
  } else {
     printf("\nO numero 8 NAO pertence a arvore!\n");
  }
  
  free(t); /* Libera a memória alocada pela estrutura árvore */
  
  return 0;
}