#include<iostream>
#include<vector>
using namespace std;
vector<int>List[100];
int c[100];
int d[100];
int f[100];
int per[100];
int time=0;
int finals[100];






int project(int m){
if(m==0)return 0;
int q=per[m];
finals[m]=1;
project(q);

}






void dfs_visit(int m){

    int u=m;
    c[u]=1;
    ++time;
    d[u]=time;

   for(auto x:List[u]){
    if(c[x]==0){
        per[x]= u;
        dfs_visit(x);
        }
   }
   f[u]= ++time;
   c[u]=2;
}





int main(){

    for(int i=0;i<100;i++){
     finals[i]=0;
    }

for(int i=0;i<100;i++)
{   c[i]=0;
    d[i]=9999;
    f[i]=9999;
    per[i]=0;
}
    int m,n;
    cout<<" Enter maze size (should be given n*n size) ";
    cin>>m;
int ma[m][m];
cout<<endl<<" 0 is for block and 1 is for Open way "<<endl;
cout<<" 1st value is the starting point and destination is the last value "<<endl<<endl;
for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
        cin>>n;
        ma[i][j]= n;
    }
}
int counter=1;
for(int i=0;i<=m;i++){
    for(int j=0;j<m;j++){

            if(ma[i][j]==1){
        if(ma[i][j+1]==1&&j!=m-1){
            List[counter].push_back(counter+1);
        }
        if(ma[i+1][j]==1){
        List[counter].push_back(counter+m);
        }
    }
    counter++;
  }
}


dfs_visit(1);
project(m*m);


cout<<endl;
cout<<"--------------------------------------"<<endl;
cout<<"--------------------------------------"<<endl;
cout<<" The Solution of this maze "<<endl;

cout<<endl;

for(int i=1;i<=m*m;i++){
    cout<<finals[i]<<" ";
   if(i%m==0){
    cout<<endl;
    }
 }


}
