#include <iostream>
#include <ctime>    //para rand()
using namespace std;
const int MAX=100;

void bubbleSort(int arr[],int n){
     for(int i=0;i<n-1;i++){
             for(int j=0;j<n - i - 1;j++){
                    if(arr[j]>arr[j+1])
                        swap(arr[j],arr[j+1]);//intercambia los elementos de las posiciones indicadas
            }
     }
}

void imprimir(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void aleatorio(int arr[],int n){
    srand(time(NULL));  //inicializar la semilla aleatoria
    for(int i=0;i<n;i++)
        arr[i]=rand()%MAX;  //genera aleatorios entre 0 y 99
}

int main()
{
    int arr[MAX];
    int n,k;
    cout << "Ingrese el tamaño del arreglo (MAX:" <<MAX<<"): ";
    cin>>n;
    aleatorio(arr,n);
    cout<<"arreglo original: ";
    imprimir(arr,n);

    bubbleSort(arr,n);
    cout<<"arreglo ordenado: ";
    imprimir(arr,n);

    cout << "Ingrese la posicion k: ";
    cin>>k;
    cout << "El elemento de la posicion "<<k<<" es: "<<arr[k-1]<<endl ;

    return 0;
}
