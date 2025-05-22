#include<iostream>
#include<cmath>
using namespace std;
const long long M=1e4+5;
long long x[M],y[M];
int g=1;
void zf(int n){
    for(int i=2;i*i<=n;i++){
        int c=0;
        while(n%i==0){
            n/=i;
            c++;
        }
        if(c){
            if(g==1) x[i]=c;
            else y[i]=c;
        }
    }
    if(n>1){
        if(g==1) x[n]=1;
        else y[n]=1;
    }
    g++;
}
int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b==0||d==0){
        cout<<"1 1";
        return 0;
    }
    zf(a);
    zf(c); 
    int p[M],e[M],k=0;
    for(int i=2;i<M;i++){
        if(x[i]&&y[i]){
            long long m=min(x[i]*b,y[i]*d);
            p[k]=i;
            e[k]=m;
            k++;
        }
    }
    if(k==0) cout<<"1 1";
    else for(int i=0;i<k;i++) cout<<p[i]<<" "<<e[i]<<endl;
    return 0;
}
