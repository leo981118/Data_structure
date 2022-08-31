#include <stdio.h> 
#include <stdlib.h>
#define MAX_SIZE 100	

typedef struct{						
    int row;								
    int col;								
    int value;							
}SparseTerm;

void attach(SparseTerm* term, int row, int col, int value){
    term->row = row;
    term->col = col;
    term->value = value;                 
}

void SparseTranspose(SparseTerm A[], SparseTerm B[]){
    int i, j, currentB;
    B[0].row = A[0].col;
    B[0].col = A[0].row;
    B[0].value = A[0].value;
    if(B[0].value == 0){ // it means no none_zero_term
        return;  
    }  

    currentB = 1;
    for(int i = 0; i < A[0].col; i++){
        for(int j = 1; j <= B[0].value; j++)
        if (A[j].col == i){
            B[currentB].row = A[j].col;
            B[currentB].col = A[j].row;
            B[currentB].value = A[j].value;
            currentB++;
        }    
    }
}

int main()
{
    SparseTerm A[MAX_SIZE], B[MAX_SIZE];   
    attach(&A[0], 4, 5, 6);                
    attach(&A[1], 0, 1, 1);               
    attach(&A[2], 0, 4, 2);                
    attach(&A[3], 1, 3, 3);
    attach(&A[4], 2, 0, 4);
    attach(&A[5], 2, 2, 5);
    attach(&A[6], 3, 4, 6);    
    SparseTranspose(A, B);
 

    for(int i = 0; i <= B[0].value; i++){
        printf("%d\t%d\t%d\n", B[i].row, B[i].col, B[i].value);
    }
    

    system("pause");
    return 0;
}



