// representing the 3-column of sparse matrix with the help of structs.
#include<stdio.h>
#include<stdlib.h>
struct Element{
    int i;// row
    int j;// column
    int x;// value
};
struct Sparse{
    int m;
    int n;// n and m are dimensions.
    int num;// no of non zero elements.
    struct Element *e;// used for creating the array of Elements.
};

void create(struct Sparse *s){
    printf("Enter the dimensions of the sparse matrix :");
    scanf("%d %d",&s->m,&s->n);
    printf("Enter no of non-zero elements :");
    scanf("%d",&s->num);
    s->e = (struct Element*)malloc(s->num*sizeof(struct Element));
    printf("Enter the row column value for the non zero elements:\n");
    for(int i =0;i<s->num;i++){
        scanf("%d %d %d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    }
}

void display(struct Sparse *s){
    int i,j,k;
    i = k = j = 0;
    for(i =1;i<=s->m;i++){
        for(j=1;j<=s->n;j++){
            
            if(i == s->e[k].i && j == s->e[k].j){
                printf("%d ",s->e[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void main(){
    struct Sparse s;
    create(&s);
    printf("\n");
    display(&s);
}
