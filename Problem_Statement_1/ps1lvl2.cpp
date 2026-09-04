#include <iostream>
#include <vector>
#include <climits>
#include <utility>

using namespace std;

void feature2(vector<vector<char>> grid,int R ,int C,int G);
void boundingbox(vector<vector<char>> v,int R ,int C);
void com(vector<vector<char>> v,int R ,int C);

vector<vector<char>> copyvector(vector<vector<char>> v);
int population(vector<vector<char>> grid);
int condition(vector<vector<char>> grid,int x, int y, string feature);
void printvector2d(vector<vector<char>> arr, int R,int C);
vector<vector<char>> nextgrid(vector<vector<char>> grid,string mode);
//void vec2dinarr(vector<vector<char>> grid,int R ,int C, vector<char> arr);
pair<vector<vector<char>>,int> gen(vector<vector<char>> grid,int G,string mode);
void output(vector<vector<char>> grid, int R, int C, int G,string mode);
vector<pair<int,int>> liveloc(vector<vector<char>> v, int R, int C);
bool same2dvector(vector<vector<char>> a,vector<vector<char>> b){
    int r1=a.size();
    int c1=a[0].size();
   int r2=b.size();
    int c2=b[0].size();
    if(r1!=r2||c1!=c2){return false;}
    else{
    for(int i=0; i<r1;i++){
        for(int j=0; j<c1;j++){
        if(a[i][j]!=b[i][j]){
        return false;
       }
    }
    }
    return true;
}
}


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
            if(feature=="toroidal"){
          adjx=(x+dr+r)%r;
         adjy=(y+dc+c)%c;
          if(grid[adjx][adjy]=='#'){
                        aliven++;
                    }
            }
            else{
            if(adjx>=0&&adjx<r && adjy>=0&&adjy<c){
                   
                    if(grid[adjx][adjy]=='#'){
                        aliven++;
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
// void vec2dinarr(vector<vector<char>> grid,int R ,int C){
//    vector<vector<char>> arr;
//   for(int i=0; i<R;i++){
//       for(int j=0; j<C;j++){
//         arr.push_back(grid[i][j]);
//       }
//   }
  
// }
pair<vector<vector<char>>,int> gen(vector<vector<char>> grid,int G,string mode){
         int r=grid.size();
   int c=grid[0].size();
   int maxpopulation=population(grid);
   vector<vector<char>> v;
  
    
   //vec2dinarr(grid,r,c);
   if(G!=0){
        for(int i=0;i<G;i++){
            v=nextgrid(grid,mode);
          
           
            maxpopulation=max(population(v),maxpopulation);
            
            grid=copyvector(v);
            }

   return {v,maxpopulation};
   }
   else{
    return {grid,maxpopulation};
   }
}
void output(vector<vector<char>> grid, int R, int C, int G,string mode){

int ipop=population(grid);

auto result=gen(grid,G,mode);
vector<vector<char>> finalgrid = result.first;
int peakpopulation = result.second;
int fpop=population(finalgrid);
cout<<"mode: "<<mode<<endl;

if(mode=="toroidal"){
    cout<<"Initial Population: "<<ipop<<endl;
    cout<<"Final Population: "<<fpop<<endl;
    cout<<"Final Grid: "<<endl;
     printvector2d(finalgrid,R,C); 
}

else if(mode=="classify"){
    
   feature2(grid,R,C,G);
   
}
 else if(mode=="metrics"){
 }
 else{}
}
vector<pair<int,int>> liveloc(vector<vector<char>> v, int R, int C){
    vector<pair<int,int>> loc;
    for(int i=0; i<R;i++){
         for(int j=0; j<C;j++){
    if(v[i][j]=='#'){
       loc.push_back(make_pair(i,j));
    }}}
    return loc;
}
void boundingbox(vector<vector<char>> v,int R ,int C){
  vector<pair<int,int>> loc=liveloc(v,R,C);
    int n=loc.size();
    if(n==0){
        cout<<"Bounding Box :0 x 0"<<endl;
        return;
    }
    else{
    int xmax=INT_MIN;
    int ymax=INT_MIN;
    for(int i=0; i<n;i++){
      xmax=max(loc[i].first,xmax);
       ymax=max(loc[i].second,ymax);
    }
    int xmin=INT_MAX;
    int ymin=INT_MAX;
    for(int i=0; i<n;i++){
      xmin=min(loc[i].first,xmin);
       ymin=min(loc[i].second,ymin);
    }

    int H= xmax-xmin+1;
    int V= ymax-ymin+1;
    
    cout<<"BOUNDING BOX: "<<H<<" x "<<V<<" (Rows "<<xmin<<"-"<<xmax <<"," <<" Cols "<<ymin<<"-"<<ymax<<")"<<endl;
    }
}
void com(vector<vector<char>> v,int R ,int C){
    vector<pair<int,int>> loc=liveloc(v,R,C);
    int n=loc.size();
    double N= n;
    int x=0;
    int y=0;
    pair<double,double> centermass;
    for(int i=0; i<n;i++){
      x=x+loc[i].first;
      y=y+loc[i].second;
    }
    if(n!=0){
        centermass = {x/N, y/N};
            cout<<"Center of Mass: "<<"("<<centermass.first<<","<<centermass.second<<")" <<endl;

    }
    else{
        centermass = {-1, -1};
       cout<<"Center of Mass: "<<"N/A"<<endl;  
    }
    
}
void feature2(vector<vector<char>> grid,int R ,int C,int G){
    vector<vector<vector<char>>> hash;
    vector<vector<char>> v;
    string mode="classify";
    hash.push_back(grid);
    vector<vector<char>> dead(R, vector<char>(C,'.'));
  for(int i=0;i<G;i++){
            v=nextgrid(grid,mode);
            hash.push_back(v);
            grid=copyvector(v);
            }
int period;
int a;
int b;
for(int i=0;i<G;i++){
    for(int j=i+1;j<=G;j++){
           
    if(same2dvector(hash[i],dead)==true){
             cout<<"Classification: Extinct"<<endl;
             cout<<"Extinction Step: "<<i<<endl;
             cout<< "Final Population: "<<population(hash[G])<<endl;
             return;
        }
    else if(same2dvector(hash[i],hash[j])==true){
        a=i;
        b=j;
        period=j-i;    
        if(period==1){
          cout<<"  Classification: Still Life"<<endl;
          cout<<"Stable at Step: "<<i<<endl;
          cout<<"Period: 1"<<endl;
          cout<<"Final Population: "<<population(hash[G]) <<endl;
          return ;}
          
        else{
            cout<<"Classification: Oscillator"<<endl;
          cout<<"First Repeat Step: "<<j<<"(matches Step "<<i<<" )"<<endl;
          cout<<"Period: "<<period<<endl;
          cout<<"Final Population: "<<population(hash[G]) <<endl;
          return;
        }

    }
    }
    }
      
            cout<<"Classification: Active"<<endl;
             cout<<"Final Population: "<<population(hash[G]) <<endl;
}



int main(){
string mode;
cin>>mode;
int R;
int C;
int G;

cin>>R>>C;
vector<vector<char> >grid(R,vector<char>(C));
    if(mode!="classify"){
    cin>>G;
    }
else if(mode=="classify"){
    G=10;
}
else{}
for(int i=0; i<R;i++){
    for(int j=0; j<C ; j++){
       cin >> grid[i][j];
    }
}
output(grid,R,C,G,mode);

    return 0;
}