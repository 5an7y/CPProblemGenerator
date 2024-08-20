#include <bits/stdc++.h>
using namespace std;

long long n,k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    long long a[n];
    long long ans[k+1];

    for (int i=0;i<n;i++)
        cin>>a[i];

    //cubeta de frecuencia de veces que x>y

    long long freq[k+1];
    for(int i=1;i<=k;i++) {
        freq[i]=0;
        ans[k] = 0;
    }
    for(int i=0;i<n;i++) freq[a[i]]++;

    //pointers
    long long i=0,j=n-1;

    //iterar para cada cromo (k)
    for(int g=k;g>=1;g--){
        //aumentar i (pointer) mientras a[i] sea mayor al color actual (mover a la izquierda)
        while(i<n && a[i]>g){
            i++;
        }
        //disminuir j (pointer) mientras que a[j] sea mayor al color actual (mover derecha)
        while (j>=0 && a[j]>g){
            freq[a[j]]--;
            j--;
        }
        if(i>j) break; //i se pasó de la posición j y no vamos a encontrar nada bueno
        if(freq[g]>0)
            ans[g]=(j-i+1)*2; //fórmula para encontrar l+l del cuadrado, guardamos en el número del color
    }

    for(int K=1;K<=k;K++) cout << ans[K] << " ";

    return 0;
}