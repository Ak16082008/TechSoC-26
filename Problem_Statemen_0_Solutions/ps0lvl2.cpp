#include <iostream>
#include <climits>
#include <fstream>
using namespace std;
void shipdata(int n,int c,int w[]);
void multipleshipsinput();
void multipleshipoutput();
void sorting(int n,int arr[]);
void kmax(int ar[],int n);
void search(int n,int arr[]);
void barchart(int n, int arr[]);  
void save(int n,int c,int w[]);

void shipdata(int n,int c,int w[]){

    int sum=0;
    int min=INT_MAX;
    int max=INT_MIN;
   
    for (int i=0 ; i<n ;i++){
    sum= sum+w[i];
    }
    for(int j=0 ; j<n; j++){
        if (w[j]< min){
            min = w[j];
        }
    }
    for(int j=0 ; j<n; j++){
        if (w[j]> max){
            max = w[j];
        }
    }

        cout<< "Total Shipment Weight: "<< sum <<endl;
        cout << "Average Container Weight: "<<(double(sum)/double(n))<<endl;
        cout<<"Heaviest Container: "<< max << endl;
        cout <<"Lightest Container:"<< min << endl;
            if(sum>=200){
                cout <<"Classification : "<<"HEAVY"<<endl;
            }
            else{
                cout <<"Classification : "<<"LIGHT"<<endl;
            }
            if (sum>c)
            {
                cout<< "Port Capacity: "<<c <<endl;
                cout<< "Status : Shipment exceeds port capacity"<<endl;
            }
            else{

                cout<< "Port Capacity: "<<c <<endl;
                cout<< "Status : Shipment can be unloaded "<<endl;
            }
          
        
}
void multipleshipsinput(){
    int n;
    int c;

    cin >>c;
   cin >>n;
   int we[n];
   for (int i=0 ; i<n ;i++){
        cin >> we[i];
    }
shipdata(n,c,we);
cout<<endl;
cout<<endl;
    save(n,c,we);          
           sorting(n,we);
           search(n,we);
           barchart(n,we);
}

void multipleshipoutput(){
    cout<< "Do you want to enter another shipment data? (Y/N): ";
char y;
cin>>y;
if(y=='Y'){
     multipleshipsinput();
     multipleshipoutput();
}
else if (y=='N'){
}
else{
    cout<< "Invalid input"<<endl;
    multipleshipoutput();
}
}
void search(int n,int arr[]){
    int x;
    int z;
    char y;
    cout <<"Do you want to search a container of given weight(Y/N): ";
    cin>> y;
    if(y=='Y'){
        cout<<"ENTER THE NUMBER TO BE SEARCHED: ";
        cin >> x;
        bool found=false;
        for (int i=0; i<n;i++){
        if(x==arr[i]){
            found=true;
            z=(i+1);
        }
        }
        if(found==true){
            cout<<"CONTAINER FOUND "<< "IT IS CONTAINER "<< z<<endl;
            search(n,arr);
        }
        else {
            cout<<"NOT FOUND"<<endl;
            search(n,arr);
        }
    }
    else if(y=='N'){
    }
    else{
        cout<< "INVALID INPUT"<<endl;
        search(n,arr);
    }

}
void sorting(int n,int arr[]){
    int arrcopy[n];
    for(int i=0;i<n;i++){
      arrcopy[i]=arr[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0 ; j<n;j++){
            if(j!=n-1){
            if(arrcopy[j]>arrcopy[j+1]){
                swap(arrcopy[j],arrcopy[j+1]);
            }}
        }

    }
     cout<<"The sorted array is: "<<endl;
     for (int i=0;i<n;i++){
        cout<< arrcopy[i]<<endl;
     } 
      kmax(arrcopy,n);
}
void kmax(int ar[],int n){
    cout<< "Do you want to find kth max in it(Y/N): ";    
     char y;
     cin>>y;
     int k;
    if(y=='Y'){
        cout<<"ENTER k: ";
        cin>> k;
        if (k>=1 && k<=n){
        cout<< "Kth Max is : "<< ar[n-k]<<endl;
         kmax(ar,n);
        }
        else{
            cout<<"INVALID K"<<endl;
            kmax(ar,n);
        }
    }
    else if (y=='N'){
    }
    else{
        cout<< "Invalid input"<<endl;
        kmax(ar,n);
    }
}
void barchart(int n, int arr[]){
    cout<<"Do you want to make bar chart(Y/N): ";
      
     char y;
     cin>>y;
     int k;
    if(y=='Y'){
        cout<<"* represents 5kg"<<endl<<endl;
        for(int i=0;i<n;i++){
             cout<<"CONTAINER "<<(i+1)<<"  ";
            for(int j=0;j<arr[i];j++){
             cout <<"*";
            }
            cout<<endl;
        }
    }
   
    
    else if (y=='N'){
    }
    else{
        cout<< "Invalid input"<<endl;
        barchart(n,arr);
    }
}
 void save(int n,int c,int w[]){   
   cout<< "Do you want to save file? (Y/N): ";
char y;
cin>>y;

if(y=='Y'){
    string name;
    cout<<"ENTER FILE NAME WITH EXTENSION: ";
    cin >>name;

    ofstream file(name);

    
    int sum=0;
    int min=INT_MAX;
    int max=INT_MIN;
   
    for (int i=0 ; i<n ;i++){
    sum= sum+w[i];
    }
    for(int j=0 ; j<n; j++){
        if (w[j]< min){
            min = w[j];
        }
    }
    for(int j=0 ; j<n; j++){
        if (w[j]> max){
            max = w[j];
        }
    }

        file<< "Total Shipment Weight: "<< sum <<endl;
        file<< "Average Container Weight: "<<(double(sum)/double(n))<<endl;
        file<<"Heaviest Container: "<< max << endl;
        file<<"Lightest Container:"<< min << endl;
            if(sum>=200){
                file<<"Classification : "<<"HEAVY"<<endl;
            }
            else{
                file<<"Classification : "<<"LIGHT"<<endl;
            }
            if (sum>c)
            {
                file<< "Port Capacity: "<<c <<endl;
                file<< "Status : Shipment exceeds port capacity"<<endl;
            }
            else{

                file<< "Port Capacity: "<<c <<endl;
                file<< "Status : Shipment can be unloaded "<<endl;
            }
            cout<<"File saved as : "<<name<<endl;
}
else if (y=='N'){
}
else{
    cout<< "Invalid input"<<endl;
}
}
int main(){
multipleshipsinput();  
multipleshipoutput();
return 0;
}
