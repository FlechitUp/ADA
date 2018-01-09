#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

using namespace std;

void printvect(vector <int> myvec){
    for(int i = 0 ; i < myvec.size() ; i++){
        cout<<myvec[i]<<", ";
    }
    cout<<endl;
}


vector<int> fill(int cont)
{
    int numrand;
    vector <int> myvect;
    srand (time(NULL));
    for(int i=0; i<cont;i++){
        numrand = abs(rand()%1000);
        //cout<<numrand<<". ";
        myvect.push_back(numrand);
    }
    return myvect;
}

vector <int> mediasPrefijas(vector <int> vec ){
    vector <int> vectAux (vec.size());
    int s = 0;
    int i = 0;
    while (i<vec.size()){
        s = s+vec[i];
        vectAux[i] = (s/(i+1));
        i++;
    }
    return vectAux;
}

int main()
{
    int nElem;
    vector <int> vectRes;
    cout<<"Ingresar cantidad de elementos ";
    cin >> nElem;
    vector <int> vect = fill(nElem);
    cout<<"Lista inicial ";
    printvect(vect);
    vectRes =  mediasPrefijas(vect);
    cout<<"Lista Final ";
    printvect(vectRes);
    return 0;
}
