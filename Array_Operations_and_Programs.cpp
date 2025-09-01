#include <iostream>
using namespace std;

// Q1) Menu-Driven Program for Array Operations
void menuDrivenArrayOperations() {
    int arr1[100], n1=0, choice1, pos1, val1, key1;
    while (true) {
        std::cout << "\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\nEnter choice: ";
        cin >> choice1;
        switch(choice1) {
            case 1:
                std::cout << "Enter size: "; cin >> n1;
                std::cout << "Enter elements: " << std::endl;
                for(int i=0;i<n1;i++) std::cin >> arr1[i];
                break;
            case 2:
                for(int i=0;i<n1;i++) std::cout << arr1[i] << " ";
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Enter position & value: "; std::cin >> pos1 >> val1;
                for(int i=n1;i>pos1;i--) arr1[i]=arr1[i-1];
                arr1[pos1]=val1; n1++;
                break;
            case 4:
                std::cout << "Enter position: "; std::cin >> pos1;
                for(int i=pos1;i<n1;i++) arr1[i]=arr1[i+1];
                n1--;
                break;
            case 5:
                std::cout << "Enter key: "; std::cin >> key1;
                for(int i=0;i<n1;i++) {
                    if(arr1[i]==key1) { std::cout << "Found at index " << i << std::endl; break; }
                    if(i==n1-1) std::cout << "Not Found\n";
                }
                break;
            case 6:
                return;
        }
    }
}

// Q2) Remove Duplicates
void removeDuplicates() {
    int n2; cin >> n2;
    int arr2[100];
    for(int i=0;i<n2;i++) cin >> arr2[i];
    for(int i=0;i<n2;i++) {
        for(int j=i+1;j<n2;j++) {
            if(arr2[i]==arr2[j]) {
                for(int k=j;k<n2-1;k++) arr2[k]=arr2[k+1];
                n2--; j--;
            }
        }
    }
    for(int i=0;i<n2;i++) std::cout << arr2[i] << " ";
    std::cout << std::endl;
}

// Q3) Predict Output => 10000
void predictOutput() {
    std::cout<< "Output of given program: 10000" << endl;
}


// Q4a) Reverse Array
void reverseArray() {
    int n4a; cin >> n4a;
    int arr4a[100];
    for(int i=0;i<n4a;i++) cin >> arr4a[i];
    for(int i=0,j=n4a-1;i<j;i++,j--) swap(arr4a[i],arr4a[j]);
    for(int i=0;i<n4a;i++) cout << arr4a[i] << " ";
    cout << endl;
}

// Q4b) Matrix Multiplication
void matrixMultiplication() {
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if(c1!=r2) {
        cout << "Invalid dimensions" << endl;
        return;
    }
    int a[100][100], b[100][100], c[100][100]={0};
    for(int i=0;i<r1;i++) for(int j=0;j<c1;j++) cin >> a[i][j];
    for(int i=0;i<r2;i++) for(int j=0;j<c2;j++) cin >> b[i][j];
    for(int i=0;i<r1;i++)
        for(int j=0;j<c2;j++)
            for(int k=0;k<c1;k++)
                c[i][j]+=a[i][k]*b[k][j];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++) cout<<c[i][j]<<" ";
        cout<<endl;
    }
}

// Q4c) Transpose of Matrix
void transposeMatrix() {
    int r4c,c4c; cin >> r4c >> c4c;
    int a4c[100][100];
    for(int i=0;i<r4c;i++) for(int j=0;j<c4c;j++) cin >> a4c[i][j];
    for(int i=0;i<c4c;i++){
        for(int j=0;j<r4c;j++) cout << a4c[j][i] << " ";
        cout << endl;
    }
}

// Q5) Row & Column Sum
void rowColSum() {
    int r5,c5;
    cin >> r5 >> c5;
    int a5[100][100];
    for(int i=0;i<r5;i++) for(int j=0;j<c5;j++) cin >> a5[i][j];
    for(int i=0;i<r5;i++){
        int sum=0;
        for(int j=0;j<c5;j++) sum+=a5[i][j];
        cout<<"Row "<<i<<" Sum: "<<sum<<endl;
    }
    for(int j=0;j<c5;j++){
        int sum=0;
        for(int i=0;i<r5;i++) sum+=a5[i][j];
        cout<<"Col "<<j<<" Sum: "<<sum<<endl;
    }
}

int main() {
    cout << "Choose a function to run:\n";
    cout << "1. Menu-driven Array Operations\n";
    cout << "2. Remove Duplicates\n";
    cout << "3. Predict Output\n";
    cout << "4. Reverse Array\n";
    cout << "5. Matrix Multiplication\n";
    cout << "6. Matrix Transpose\n";
    cout << "7. Row & Column Sum\n";
    cout << "8. Exit\n";
    int ch;
    while(true) {
        cout << "\nEnter choice: ";
        cin >> ch;
        switch(ch) {
            case 1: menuDrivenArrayOperations(); break;
            case 2: removeDuplicates(); break;
            case 3: predictOutput(); break;
            case 4: reverseArray(); break;
            case 5: matrixMultiplication(); break;
            case 6: transposeMatrix(); break;
            case 7: rowColSum(); break;
            case 8: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
