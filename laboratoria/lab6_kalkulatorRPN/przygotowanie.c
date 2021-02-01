void inicjuj (struct stos *glowa){
 glowa = NULL;
}

struct stos *push (struct stos *glowa, int informacja){
 struct stos *tmp = (struct stos*)malloc(sizeof(struct stos));
 if (tmp==NULL) {
  exit(0); 
 }
 tmp->informacja = informacja;
 tmp->nastepny = glowa;
 glowa = tmp;
 return glowa;
}

struct stos *pop (struct stos *glowa, int *element){
 struct stos *tmp = glowa;
 *element = glowa->informacja;
 glowa = glowa->nastepny;
 free(tmp);
 return glowa;
}

void print (struct stos *glowa){
 struct stos *obecny;
 obecny = glowa;
 if (obecny != NULL) {
  do {
   printf("%d\n",obecny->informacja);
   obecny = obecny->nastepny;
  } while (obecny!=NULL);
 }
 else
  printf("dc: stack empty\n");
}

int empty(struct stos *glowa)
{
    return glowa == NULL ? 1 : 0;
}