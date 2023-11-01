#include<iostream>
using namespace std ; 
#include<cmath>


float media (int valori[], int N) {
    int somma = 0 ;
    float res ;
    for (int i = 0; i < N; i++)
    {
     somma = somma + valori [i] ;
    }
    res = (float)somma / N ;

    return res ; 
} 

float stnd (int valori[], int N, float m) {
    float sum_scarto = 0 ; 
    float res ;
    for (int i = 0; i < N; i++)
    {
     sum_scarto = pow(valori [i] - m,2) + sum_scarto ;
    }
    res = sqrt(sum_scarto / (-1)) ;
    return res ;
}

bool isOutlier (int valore, float m,float stnd) {

    float abs, c ; 
    abs = fabs(valore - m) ; 
    c = 3*stnd ;

    return abs > c ;

}

void scambia(int a[], int v1, int  v2) {
    int appoggio;
    appoggio = a[v1];
    a[v1] = a[v2];
    a[v2] = appoggio;
}

void print_array (int valori[], int num_elementi) {

    cout << "{ " ;
    for (int i = 0; i < num_elementi-1; i++) {
         cout << valori [i] << " , " ;
    }
    cout << valori [num_elementi-1] << " }" << endl ;
}

void define_array (int voti[],int n) {
    for (int i = 0; i < n ; i++) {
        cout << endl << "inserisci qua il valore "<< i + 1 << ": "<< endl ;
        cin >> voti [i] ; 
        cout << endl;
    }    
}

int resto (int Num, int Den) {
    int q, r ;
    q =  Num/Den ; 
    r = Num - q*Den ;
    return r ; 

}

int MCD ( int p , int q) {
    int mcd, r ;
    do {
        r = resto (p,q) ;
        p = q ; 
        q = r ; 
    } while (q != 0) ; 
    return p ; 
} 

int posmin(int a[], int p, int j) {
    int s = a[p];
    int posmin = p;
    for (int i = p + 1; i < j; i++) {
        if (s > a[i]) {
            s = a[i];
            posmin = i;
        }
    }
    return posmin;
}

int deleteEntrySwap(int v[], int size, int used, int where) {
    for (int i = where; i < used; i++)
    {
      v [i] = v [i + 1] ;
    }
    used = used - 1 ;
    return used ; 
}

void ordcrescente(int a[], int n) {
    int p = 0;
    for (int i = 0; i < n; i++) {
        p = posmin(a, i, n);
        scambia(a, i, p);
    }
}