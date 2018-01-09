#include "sort.h"
#include <cstdlib>
#include <ctime>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
using namespace std;
void print(int *a, int tam)
{
    for(int i=0;i<tam;++i)
        cout << a[i] << ", " ;

    cout << endl;
}
void fill(int* a,int cont)
{
    int numrand;
    srand (time(NULL));
    for(int i=0; i<cont;i++){
        //*(a+i)=cont-i;
        numrand = abs(rand()%1000);
        cout<<numrand<<" ";
        a[i]= numrand;
    }
}

int menu()
{
    int n;
    cout << "\n\tMetodos de Ordenamiento\t\n";
    cout <<"[1] BubleSort" <<endl;
    cout <<"[2] InsertSort" <<endl;
    cout <<"[3] SelectSort" <<endl;
    cout <<"[4] CocktailSort" <<endl;
    cout <<"[5] heapSort" <<endl;
    cout <<"[6] mergeSort" <<endl;
    cout <<"[7] quickSort" <<endl;
    cout <<"[0] SALIR" <<endl;
    cout <<"-> Ingrese una opcion: "; cin>> n;

    return n;
}

int main()
{
    sSorts s=sSorts();
    int choose = menu();
    int *lista ;
    int tam,nElem;
    cout << "Ingrese {#Elementos] " ; cin >>nElem;
    tam = nElem;
    lista = new int[nElem];
    cout<<"********************"<<endl;
    fill(lista,nElem);
    switch(choose)
    {
        case 1:{
            print(lista,tam);
            s.BubleSort(lista,tam);
            cout <<"Lista Final:   "; print(lista,tam);
            break;
        }
        case 2:{
            s.InsertSort(lista,tam);
            cout <<"Lista Final:   "; print(lista,tam);
            break;
        }
        case 3:{
            s.SelectSort(lista,tam);
            cout <<"Lista Final:   "; print(lista,tam);
            break;
        }
        case 4:{
            s.CocktailSort(lista,tam);
            cout <<"Lista Final:   "; print(lista,tam);
            break;
        }
        case 5:{

            cout <<"Lista Inicial : ";
            print(lista,tam);
            s.heapSort(lista,tam);
            cout <<"Lista Final:    "; print(lista,tam);
            cout << endl;
            break;
        }
        case 6:{
            vector<int> l(lista,lista+nElem);
            vector<int> v= s.mergeSort(l);

            cout <<"Lista Final:   ";
            for(int i=0; i<v.size();i++)
              cout << v[i] << " ";
            cout << endl;

            break;
        }
        case 7:{
            s.QuickSort(lista,0,tam-1);

        }
        default:
            break;

    }

    return 0;
}
