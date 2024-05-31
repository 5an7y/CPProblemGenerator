#include <bits/stdc++.h>

using namespace std;

#define FIN ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
int main(){FIN;
    int n;
    
    cin>>n;
    vector<int> alumnos(n);
    for(int i =0; i<n; i++){
        cin>>alumnos[i];
    }
    sort(alumnos.begin(),alumnos.end());
    long long k;
    cin>>k;    
    int m = (n-1)/2;
    int actual = m;
    int sig = m+1;
    long long dif = 0;
    long long valorActual = alumnos[m];
    int suma;
    alumnos.push_back(INT_MAX);
    while(k > 0){
        if(alumnos[actual] < alumnos[sig] && sig < n){
            dif = alumnos[sig]-alumnos[actual];
            if(k-((sig-m)*dif) >= 0){
                long long suma = dif;
                valorActual += suma;
                k-=((sig-m)*dif);
            }
            else{
                break;
            }
        }else  if (sig >= n) break;
        actual++;
        sig++;

    }
    if( k > 0)
    valorActual += k/(sig-m);
    
    cout<<valorActual;
   
}