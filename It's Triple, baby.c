//
//  It's Triple, baby.c
//  C
//  3.2(27)
//  Created by Kirill Rogov on 21/02/2020.
//  Copyright © 2020 Kirill Rogov. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
static int findError = 0;

void secure() {
    scanf("%*[^\n]");
}

void secureCheck(int massive[][100], int n, int m) {
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(massive[i][j] != 0 && massive[i][j] != 1) {
                findError = 1;
            }
        }
    }
}

void randomWay(int massive[][100], int count, int a, int b) {

    int value;
    int koef = count;
    printf("\nI generate this unique sh&t:");
        for(int n = 0; n<a; n++) {
            printf("\n");
            for(int m = 0; m<b; m++) {
                
                srand(time(NULL)*koef);
                int first = rand();
                int second = rand();
                if(first > second) {
                    value = 0;
                } else {
                    value = 1;
                }

                massive[n][m] = value;
                printf("\t%d", massive[n][m]);
                koef--;
                secure();
            }
        }

    printf("\n");
}

void enterWay(int massive[][100], int n, int m) {
    printf("\nEnter your value:");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("\nmatrix[%d][%d] = ",i,j);
            scanf("%d",&massive[i][j]);
            secure();
        }
    }
}



void searchStr(int massive[][100], int n, int m) {
    
    int storage[n];
    int q;
    for(int i=0; i<n; i++) {
        storage[i] = i;
    }
    
    //ищем пи&а&аса
    for(int i=0; i<n; i++) {
        for(int k=i+1; k<n; k++) {
            q = 0; // совпадений 0 / m;
            for(int j=0; j<m; j++) {
                if(massive[i][j] == massive[k][j]) {
                    q++;
                }
                
                if(q == m) {
                    storage[i] = -1;
                    storage[k] = -1;
                }
            }
        }
    }
    
    
    //чистим г&вно
    int deep = -1;
    for(int k=0; k<n; k++) {
        if(storage[k] != -1) {
            deep++;
            for(int j=0; j<m; j++) {
                massive[deep][j] = massive[k][j];
            }
        }
    }
    
    
    //перевод в десятичные
    n=deep+1;
    double result;
    int storageNum[n];
    int cloudM;
    for(int i=0; i<n; i++) {
        cloudM = m;
        result = 0;
        for(int j=0; j<m; j++) {
            result += massive[i][j]*pow(2,cloudM-1);
            cloudM--;
        }
        storageNum[i] = result;
    }
    
    //сортировка пузырьком
    for(int j=0; j<n-1; j++) {
    for(int i=0; i<n-j-1; i++) {
        if(storageNum[i]>storageNum[i+1]) {
            int tmp = storageNum[i];
            storageNum[i] = storageNum[i+1];
            storageNum[i+1] = tmp;
        }
    }
    }
    

    //перевод обрат но в двоичный
    for(int i=0; i<n; i++) {
        int nextNum = storageNum[i];
        for(int j=m-1; j>=0; j--) {
            massive[i][j] = nextNum % 2;
            nextNum = nextNum / 2;
        }
    }
    
    //вывод
    printf("\n\t\tResult: \n");
    for(int i=0; i<n; i++) {
        printf("\n");
        for(int j=0; j<m; j++) {
            printf("\t%d",massive[i][j]);
        }
    }
 
    printf("\n");
    
}



int main() {
    short choose, back = 0;
    int n, m, count;

    printf("Enter n: ");
    scanf("%d", &n);
    secure();
    
    printf("Enter m: ");
    scanf("%d", &m);
    secure();
    
    count = n*m;
    int massive[n][m];
    
    while(back == 0) {
        printf("\nChoose a way for fill massive:\n1. Random-way\n2. Enter-way\n- ");
        scanf("%hd", &choose);
        secure();
        if(choose == 1 || choose == 2) {
            back = 1;
        }
    }
    
    switch(choose) {
        case 1: randomWay(massive, count, n, m);
            break;
        case 2: enterWay(massive, n, m);
            break;
    }
    secureCheck(massive, n, m);
    
    if(findError == 0) {
    searchStr(massive, n, m);
    } else {
        printf("\nError 444. Please enter normal value!!\n");
    }
    
}
