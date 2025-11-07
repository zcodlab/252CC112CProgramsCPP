#include <iostream>
using namespace std;
const int MAX_INT=1<<30;    //2^30 -> apor 1'.....

int corteVarilla(int precio[],int n,int** dp){
        //caso base
        if(n==0) return 0;
        if(dp[n][n]!= -1) return dp[n][n];
        int maxValor= -MAX_INT;
        //probar con diferentes combinaciones de cortes
         for(int i=1; i<=n;i++){
                int p=precio[i-1];
                int cv=corteVarilla(precio,n-i,dp);
                int costo=p+cv;
                if(costo>maxValor)
                    maxValor=costo;
         }
         dp[n][n]=maxValor;
         return maxValor;
}

int main()
{
    int precio[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n=4;
    int** dp=new int*[n+1];
    for(int i=0; i<=n;i++){
            dp[i]=new int[n+1];
            for(int j=0; j<=n;j++)
                dp[i][j]=-1;
    }
    cout<<"El beneficio es: "<<corteVarilla(precio,n,dp)<<endl;
    //liberar memoria
    for(int i=0; i<=n;i++)
        delete[] dp[i];
    delete[] dp;
    return 0;
}
