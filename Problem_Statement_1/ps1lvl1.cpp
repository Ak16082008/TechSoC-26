#include <iostream>
#include <vector>
#include <climits>
#include <utility>
using namespace std;
vector<vector<char>> copyvector(vector<vector<char>> v){
    return v;
}
int population(vector<vector<char>> grid){
   int r=grid.size();
   int c=grid[0].size();
   int count=0;
   for(int i=0; i<r;i++){
    for(int j=0;j<c ;j++){
        if(grid[i][j]=='#'){
            count=count +1;
        }
    }
   }
   return count;
}
int condition(vector<vector<char>> grid,int x, int y){
         int r=grid.size();
   int c=grid[0].size();
    int deadn=0;
    int aliven=0;
    for(int dr=-1;dr<=1;dr++){
        for(int dc=-1;dc<=1;dc++){
            int adjx=x+dr;
        int adjy=y+dc;
          if(dc==0&&dr==0){} 

        else{
                if(adjx>=0&&adjx<r && adjy>=0&&adjy<c){
                    if(grid[adjx][adjy]=='.'){
                    deadn++;
                    }
                    else if(grid[adjx][adjy]=='#'){
                        aliven++;
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
 
   }
      if(grid[x][y]=='#'){
            if (aliven<2){
                return 1;
            }
            else if (aliven>3){
                return 3;
            }
            else{
                return 2;
            }

    }
    else if(grid[x][y]=='.'){
            if(aliven==3){
                return 4;
            }
            else{
                return 5;
            }
    }
    else{
        return 0;
    }
} 




vector<vector<char>> nextgrid(vector<vector<char>> grid){
         int r=grid.size();
   int c=grid[0].size();
   int count=0;
   vector<vector<char>> newgrid(r,vector<char>(c));
   for(int i=0; i<r;i++){
    for(int j=0;j<c ;j++){
        newgrid[i][j]=grid[i][j];
        }
    }
     for(int i=0; i<r;i++){
    for(int j=0;j<c ;j++){
        char temp=grid[i][j];
        int val=condition(grid,i,j);
        if(val==1){
           grid[i][j]='.'; 
        }
        else if(val==2){
           grid[i][j]='#'; 
        }
        else if(val==3){
           grid[i][j]='.'; 
        }
        else if(val==4){
           grid[i][j]='#'; 
        }
        else if(val==5){
             grid[i][j]='.';
        }
        else{
            newgrid[i][j]='$';//error
        }
        newgrid[i][j]=grid[i][j];
        grid[i][j]=temp;
        }
    }
   
    
    return newgrid;
}


  pair<vector<vector<char>>,int> gen(vector<vector<char>> grid,int G){
         int r=grid.size();
   int c=grid[0].size();
   int maxpopulation=population(grid);
   vector<vector<char>> v=copyvector(grid);
if(G!=0){ 
   for(int i=0;i<G;i++){
    
     v=nextgrid(grid);
     maxpopulation=max(population(v),maxpopulation);
    for(int i=0; i<r;i++){
    for(int j=0;j<c ;j++){
        grid[i][j]=v[i][j];
        }
    }
    
   }
   return {v,maxpopulation};}
   else{
    return {grid,maxpopulation};
   }
}



int main(){
int R;
int C;
int G;
cin>>R>>C;
vector<vector<char>>grid(R,vector<char>(C));

cin>>G;
for(int i=0; i<R;i++){
    for(int j=0; j<C ; j++){
       cin >> grid[i][j];
    }
}


int ipop=population(grid);

auto result=gen(grid,G);
vector<vector<char>> finalgrid = result.first;
int peakpopulation = result.second;
int fpop=population(finalgrid);
cout<<"Initial Population: "<<ipop<<endl;
cout<<"Final Population: "<<fpop<<endl;
cout<<"Peak Population: "<<peakpopulation<<endl;
cout<<"Final Grid: "<<endl;
for(int i=0; i<R;i++){
    for(int j=0; j<C ; j++){
        cout<<finalgrid[i][j];
    }
     cout<<endl;
}
    return 0;
}