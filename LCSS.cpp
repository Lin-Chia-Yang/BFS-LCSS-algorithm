#include <iostream>
#include <vector>
using namespace std;
int arraysize=0;
string GETLCS(vector<vector<string>> b,string X,int i,int j){
    if(i==0 || j==0){
        return "";
    }
    if(b[i][j]=="leftup"){
        return GETLCS(b,X,i-1,j-1)+X[i-1];
    }
    else if(b[i][j]=="up"){
        return GETLCS(b,X,i-1,j);
    }
    else{
        return GETLCS(b,X,i,j-1);
    }
}
int main()
{
    int number;
    cin >> number;
    for(int a=0;a<number;a++){
        string x;
        string y;
        cin >>x>>y;
        int m=x.length();
        int n=y.length();
        int c[m+1][n+1];
        vector< vector<string> > b(m+1);
        for(int i=0;i<b.size();i++){
            b[i].resize(n+1);
        }
        c[0][0]=0;
        for(int i=1;i<=m;i++){
            c[i][0]=0;
        }
        for(int j=1;j<=n;j++){
            c[0][j]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1]){
                    c[i][j]=c[i-1][j-1]+1;
                    b[i][j]="leftup";
                }
                else if(c[i-1][j]>=c[i][j-1]){
                    c[i][j]=c[i-1][j];
                    b[i][j]="up";
                }
                else{
                    c[i][j]=c[i][j-1];
                    b[i][j]="left";
                }
            }
        }
        cout << c[m][n]<<endl;
        //cout <<GETLCS(b,x,m,n)<<endl;
    }
    return 0;
}
