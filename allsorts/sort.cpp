#include "sort.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

 sSorts::sSorts(){}

 sSorts::~sSorts(){}

void sSorts::BubleSort(int *a, int tam)
{
    int i,j,tmp;
    for(i=0; i<tam-1 ; i++){

        for(j=0; j<tam-i-1; j++){
            if( a[j]> a[j+1] ){
                swap(a[j],a[j+1]);
            }
        }
    }
}

void sSorts::InsertSort(int* list,int tam)
{
    cout<<" 'InsertSort' "<<endl;
	int i,j;
	for( i=0;i<tam-1;i++){
		int min=i;
		for( j=i+1; j<tam; j++)
			if(*(list + j)<*(list + min))
				min = j;

		if(min != i)
			swap(*(list + i),*(list + min));
	}
}

void sSorts::SelectSort(int* list, int tam)
{
	cout << "SelectionSort" <<endl;
	int i,j,IndexMin;

	for( i=0 ; i<tam-1 ; i++)
	{
		//Buscamos la posicion del elmento menor,con la q vamos a hacer swap
		IndexMin = i ;
		for( j=i ; j<tam ; j++)
			if( *(list+j+1)> *(list+IndexMin) )
				IndexMin = j+1;
		//hacemos el swap
		if(IndexMin != i)
            swap(*(list+i),*(list+IndexMin));
	}
}


int sSorts::Particion(int *list, int start, int end)
{
    int left , right, pivot;

    pivot = *(list+start);
    left = start;
    right = end;

    // Mientras no se cruzen los índices
    while (left < right){
        while ( *(list+right) > pivot ) // para los menores
            right--;

        while ( left < right and *(list+left)<=pivot )
            left++;

        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right)
            swap(*(list+left),*(list+right));
    }

    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    swap(*(list+right),*(list+start));

    // La nueva posición del pivot
    return right;
}

// Función recursiva para hacer el ordenamiento
void sSorts::QuickSort(int *list, int start, int end)
{
	//cout << " \t ****************  QuickSort  ********************"<< endl;
    int pivot;

    if (start < end)
    {
        pivot = Particion(list, start, end);

        // Ordeno la lista de los menores
        QuickSort(list, start, pivot - 1);

        // Ordeno la lista de los mayores
        QuickSort(list, pivot + 1, end);
    }
}



void sSorts::CocktailSort(int* list,int tam)
{
cout<<"<= 'CocktailSort' => "<<endl;
for ( int i = 1; i < tam; i++)
{
    for (int j = i - 1; j < tam - i; j++)
		if ( *(list+j)>*(list+j+1))
			swap ( *(list + j) , *(list + j + 1) );

    for (int j = tam - i - 1; j >= i; j--)
		if (*(list+j)<*(list+j-1))
			swap (*(list + j), *(list + j - 1));

  }
}



int sSorts::parent(int pos) { return (pos-1)/2; } // creo que estas mal :(
int sSorts::left(int pos) { return (2*pos)+1; }
int sSorts::right(int pos) { return (2*pos)+2; }

void sSorts::construirHeapMax(int* lista, int tam)
{
    int posUP = parent(tam-1); // position Ultimate Parent
    int l,r;
    for(int i=posUP; i>=0; i--){
        l=left(i);  r=right(i);
        if( l<tam and r<tam){// caso1: has two children
            if(*(lista+l) > *(lista+r) and *(lista+l)> *(lista+i)){
                //cout << "swap( "<< i <<" , "<< l  <<" )" << endl;
                //cout << "swap( "<< *(lista+i)<<" , "<< *(lista+l) <<" )" << endl;
                swap(*(lista+i),*(lista+l));
            }
            else if (*(lista+r)> *(lista+i)){
                //cout << "swap( "<< i <<" , "<< r  <<" )" << endl;
                //cout << "swap( "<< *(lista+i)<<" , "<< *(lista+r)<< " )"<<endl;
                swap(*(lista+i),*(lista+r));
            }
        }
        else{ //caso2: Ultimate parent just has left child
            if( *(lista+l)<tam and *(lista+l)> *(lista+i)){
                //cout << "swap( "<< i <<" , "<< l  <<" )" << endl;
                //cout << "swap( "<< *(lista+i)<<" , "<< *(lista+l)<< " )"<<endl;
                swap(*(lista+i),*(lista+r));
            }
        }
    }
}

void sSorts::heapSort(int* lista, int tam)
{
    int iteraciones = tam;
    construirHeapMax(lista, tam);


    for(int i=1; i<iteraciones ;i++){
        construirHeapMax(lista, tam);
        swap(*lista, *(lista+tam-1));
        tam--;
        //cout <<"Lista antes del swap: ";print(lista,10);
        //cout <<"Lista despues del swap: ";print(lista,10);
        //cout <<"---------------------------------------------"<<endl;
    }

}

vector<int> sSorts::mezcla(vector<int>& left,vector<int>& right)
{
    vector<int> res;
    int i=0,j=0,rSize=right.size(),lSize=left.size();
    while(lSize>0 and rSize>0){
        if(left[i]<=right[j]){
            res.push_back(left[i]);
            i++; lSize--;
        }
        else{
            res.push_back(right[j]);
            j++; rSize--;
        }
    }
    if(lSize>0)
        for(int k=0; k< lSize;k++)
            res.push_back(left[left.size()-lSize+k]);
    else if(rSize>0)
        for(int m=0; m< rSize;m++)
            res.push_back(right[right.size()-rSize+m]);
    return res;
}

vector<int> sSorts::mergeSort(vector<int>& lista)
{
    int tam = lista.size();
    if(tam < 2) // lista ordenada
        return lista;
    else{
        int medio= tam/2;
        vector<int> left(lista.begin(), lista.begin()+ medio);
        vector<int> right(lista.begin()+medio, lista.end());
        left = mergeSort(left);
        right = mergeSort(right);

        return mezcla(left,right);
    }
}

void sSorts::print(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
