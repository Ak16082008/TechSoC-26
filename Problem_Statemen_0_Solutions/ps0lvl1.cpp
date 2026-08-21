#include <iostream>
#include <climits>
using namespace std;
int main(){
int c;
int n;
int w[n];
int sum=0;
int min=INT_MAX;
int max=INT_MIN;
cin >> c;
cin >> n;
for (int i=0 ; i<n ;i++){
    cin >> w[i];
}
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
return 0;
}
