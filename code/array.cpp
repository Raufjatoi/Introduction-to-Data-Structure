#include <iostream>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};
    
    for(int i = 0; i < 5;i++){
        cout << "location: " << &arr[i] << " value: " << arr[i] << endl;
    }
    cout << "size of array: " << sizeof(arr) << endl;
    cout << "size of element: " << sizeof(arr[0]) << endl;
    cout << "length of array: " << sizeof(arr)/sizeof(arr[0]) << endl;
    cout << "arr[6]: " << arr[6] << endl;
    cout << "location of arr[6]:" << &arr[6] << endl;
}