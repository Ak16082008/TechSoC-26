#include <iostream>
#include <vector>
#include <chrono>
#include <thread>


using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
void clearscreen(){
    cout<<"\033[2J\033[1;1H";
    // \033[2J clears the screen
    // \033[1;1H moves the cursor to row 1 column 1
    sleep_for(seconds(3));
}


vector<vector<char>> copyvector(vector<vector<char>> v);
int population(vector<vector<char>> grid);
int condition(vector<vector<char>> grid,int x, int y, string feature);
void printvector2d(vector<vector<char>> arr, int R,int C);
vector<vector<char>> nextgrid(vector<vector<char>> grid,string mode);

pair<vector<vector<char>>,int> gen(vector<vector<char>> grid,int G,string mode);
void output(vector<vector<char>> grid, int R, int C, int G,string mode);




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
int condition(vector<vector<char>> grid,int x, int y, string feature){
         int r=grid.size();
   int c=grid[0].size();
    int deadn=0;
    int aliven=0;
      
    for(int dr=-1;dr<=1;dr++){
        for(int dc=-1;dc<=1;dc++){
           if(dc==0&&dr==0){continue;} 
           int adjx=x+dr;
           int adjy=y+dc; 
            
          
            if(adjx>=0&&adjx<r && adjy>=0&&adjy<c){
                   
                    if(grid[adjx][adjy]=='#'){
                        aliven++;
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
void printvector2d(vector<vector<char>> arr, int R,int C){
   for(int i=0; i<R;i++){
        for(int j=0; j<C ; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

vector<vector<char>> nextgrid(vector<vector<char>> grid,string mode){
         int r=grid.size();
   int c=grid[0].size();
   int count=0;
   vector<vector<char>> newgrid(r,vector<char>(c,'.'));
  
     for(int i=0; i<r;i++){
    for(int j=0;j<c ;j++){
        
        int val=condition(grid,i,j,mode);
        if(val==1){
           newgrid[i][j]='.'; 
        }
        else if(val==2){
           newgrid[i][j]='#'; 
        }
        else if(val==3){
           newgrid[i][j]='.'; 
        }
        else if(val==4){
           newgrid[i][j]='#'; 
        }
        else if(val==5){
             newgrid[i][j]='.';
        }
        else{
         //error
        }
       
        }
    }

    return newgrid;
}

void animate(vector<vector<char>> grid,int G,string mode){
    clearscreen();
         int r=grid.size();
   int c=grid[0].size();
   int currpopulation=population(grid);
   vector<vector<char>> v;
   
   //vec2dinarr(grid,r,c);
   
      
        cout<<"Generation:0"<<"     "<<"Population:"<<currpopulation<<endl;
        printvector2d(grid,r,c);
        clearscreen();
            for(int i=1;i<=G;i++){
                v=nextgrid(grid,mode); 
                grid=copyvector(v);
                currpopulation=population(grid);
                cout<<"Generation"<<i<<".      "<<"Population:"<<currpopulation<<endl;
                printvector2d(grid,r,c);
                if(i!=G){
                clearscreen();}
                }

}


int main(){
string mode;
cin>>mode;
int R;
int C;
int G;
cin>>R>>C;
cin>>G;

vector<vector<char> >grid(R,vector<char>(C));
for(int i=0; i<R;i++){
    for(int j=0; j<C ; j++){
       cin >> grid[i][j];
    }
}
if(mode=="animate"){
    animate(grid,G,mode);
}
else{
    return 0;
}
}