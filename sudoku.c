#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          fscanf (file, "%d", &n->sudo[i][j]);
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int compare_submatrix(int matriz[9][9])
{
  /*int aux =0;
    for(int o=1;o<=9;o++)
    {
      int k=4,p; 
      for(p=0;p<9;p++)
      {
        //i = 4 + p/3    j = 3 + p%3
        int i=3*(k/3) + (p/3) ;
        int j=3*(k%3) + (p%3) ;
        if(matriz[i][j]==o)
        {
        aux++;
        }
        if (aux>1)
        {
          return(0);
        }
      }
      aux=0;
    }*/
  int i =0;
  int j =0;
  int aux =0;
  while(1)
  {
    for (int numeros =1;numeros<=9;numeros++)
    {
      aux =0;
      for (i=i;i<(i+3);i++)
      {
        for (j=j;j<(j+3);j++)
        {
          if (matriz[i][j]==numeros)
          {
            aux++;
          }
          printf("%d\n",j);
          if (aux>1)
          {
            return(0);
          }
        }
        j=(j-3);
      }
      i=(i-3);
    }
    j= (j+3);
    if (j>=9)
    {
      j=(0);
      i=(i+3);
      if (i>=9)
      {
        return(1);
      }
    }
  }
  return(1);
}

int is_valid(Node*n)
{
  int matriz[9][9];
  memcpy(matriz,(n->sudo),sizeof(matriz));
  int i =0;
  int j =0;
  int aux;
  int aux_2;
  for(i=0; i<9 ;i++) //comprobacion filas y columnas
    {
      aux =0;
      aux_2 =0;
      for(int valor=1;valor<=9;valor++)
      {
        for(j=0; j<9 ;j++)
        {
          if(matriz[i][j]==valor)
          {
            aux++;
          }
          if(matriz[j][i]==valor)
          {
            aux_2++;
          }
          if((aux>1)||((aux_2)>1))
          {
            return(0);
          }
        }
        aux =0;
        aux_2 =0;
      }
    }
  if((aux>1)||(aux_2>1))
  {
    
    return(0);
  }
  /*aqui comprobacion submatrices*/
  if(compare_submatrix(matriz)!=1)
  {
    return(0);
  }
  return(1);
}



List* get_adj_nodes(Node* n)
{
  int j;
   List* list=createList();
   int matriz [9][9];
   memcpy(matriz,(n->sudo),sizeof(matriz));
   for (int i =0;i<9;i++)
   {
    for (j =0;j<9;j++)
    {
      if(matriz[i][j]==0)
      {
        break;
      }
    }
    if(matriz[i][j]==0)
    {
      for(int valor=1;valor<=9;valor++)
      {
        matriz[i][j]=valor;
        Node* n_node =(Node*)calloc(1,sizeof(Node));
        memcpy(n_node->sudo,matriz,sizeof(matriz));
        if(is_valid(n_node)==1)
        {
          printf("%d\n",matriz[i][j]);
          pushBack(list,n_node);
        }
      }
      return(list);
    }
   }
  return(list);
}

int is_final(Node* n){
  int matriz[9][9];
  memcpy(matriz,(n->sudo),sizeof(matriz));
  for (int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(matriz[i][j]==0)
      {
        return(0);
      }
    }
  }
  return(1);
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/