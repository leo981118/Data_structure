#include <stdio.h> 
#include <stdlib.h>
#define MAX_SIZE 100							

typedef struct{										
    int coef;												
    int exp;												
}NonZeroTerm;

typedef struct{										
    int count;											
    NonZeroTerm terms[MAX_SIZE];		
}Polynomial;

void attach(Polynomial* ptr, int coef, int exp)
{
    if (ptr->count >= MAX_SIZE){
        return;
    }
    ptr->terms[ptr->count].coef = coef;
    ptr->terms[ptr->count].exp = exp;
    ptr->count++;       
    return;
}


int Compare(int x, int y) {
    if (x < y){
        return -1;
    }
    else if (x == y){
        return 0;
    }
    else{
        return 1;
    }
}




void PolyAdd(Polynomial* pA, Polynomial* pB, Polynomial* pC)
{
    int currentA = 0, currentB = 0;
    pC->count = 0;                
    while(currentA < pA->count && currentB < pB->count){ //to know it is end of not
        switch(Compare(pA->terms[currentA].exp, pB->terms[currentB].exp)){  
        case -1:       // A < B
            attach(pC, pB->terms[currentB].coef, pB->terms[currentB].exp);
            currentB++;
            break;
        case 0:       // A == B
            if((pA->terms[currentA].coef + pB->terms[currentB].coef) != 0){
                attach(pC, pA->terms[currentA].coef + pB->terms[currentB].coef, pA->terms[currentA].exp);
                currentA++;
                currentB++;
                break;
            }
        case 1:      // A > B
            attach(pC, pA->terms[currentA].coef, pA->terms[currentA].exp);
            currentA++;
            break;
        }
    }  

    while(currentA < pA->count){  
        attach(pC, pA->terms[currentA].coef, pA->terms[currentA].exp);
        currentA++;
    }                

    while(currentB < pB->count){  
        attach(pC, pB->terms[currentB].coef, pB->terms[currentB].exp);
        currentB++;
    }      
}       



int main()
{
    Polynomial A, B, C; 
    A.count = 0;    //A: 5X^5+7^X3+2X+6 count:4
    attach(&A, 5, 5);
    attach(&A, 7, 3); 
    attach(&A, 2, 1);
    attach(&A, 6, 0);
    
    B.count = 0;   //B: 6X^5+3^X4-6X^2 count:3
    attach(&B,  6, 5);
    attach(&B,  3, 4); 
    attach(&B, -6, 2);

    PolyAdd(&A, &B, &C);

    printf("non zero terms in polynominal C(X) = %d\n", C.count);
    for(int i = 0; i < C.count; i++){
        printf("coef = %d exp = %d\n", C.terms[i].coef, C.terms[i].exp);
    }

    system("pause");
    return 0;
}
  




       

