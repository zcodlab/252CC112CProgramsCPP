#include <iostream>
#include <string>
using namespace std;
const int MAX=10;

unsigned int strlen(const char* p){
    int i=0;
    while(*(p+i)!='\0')
        i++;
    return i;
}

void rev(char* a){
    int n=strlen(a);
    for(int i=0; i<n/2;i++)
        swap(*(a+i),*(a+n-i-1));
}

int main()
{
    char a[MAX]={};
    cout << "Ingrese la palabra:" << endl;
    cin>>a;
    rev(a);
    //imprimir la palabra invertida
    for(auto i : a) //auto infiere que i es un char
            cout << i;
    return 0;
}
