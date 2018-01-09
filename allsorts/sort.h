#ifndef SEQUENCIALS_SORTS_H
#define SEQUENCIALS_SORTS_H
#include <vector>
#include <iostream>
using namespace std;
class sSorts
{

public:
    sSorts();
    ~sSorts();
    void BubleSort(int *a, int tam);
    void InsertSort(int *a, int tam);
    void SelectSort(int *a, int tam);

    void QuickSort(int *a, int ini, int fin);
    int Particion(int*a, int ini, int fin);

    void CocktailSort(int *a, int tam);

    void heapSort(int *a, int tam);
    void construirHeapMax(int* lista, int tam);
    int parent(int pos);
    int left(int pos);
    int right(int pos);

    vector<int> mergeSort(vector<int>& a);
    vector<int> mezcla(vector<int>& left, vector<int>& right);
    void print(vector<int> v);
};

#endif //SEQUENCIALS_SORTS_H
