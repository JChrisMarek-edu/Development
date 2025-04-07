#include <iostream>

using std::cout;
using std::endl;

double* CreateArray(size_t size);

long long int globalVariable = 42;

int main() {
    cout << "globalVariable value =   " << globalVariable << endl;
    cout << "globalVariable address = " << &globalVariable << endl;

    int localVariable = 209;
    cout << "localVariable value =   " << localVariable << endl;
    cout << "localVariable address = " << &localVariable << endl;

    double* array = nullptr;
    cout << "Before Calling CreateArray" << endl;
    cout << "array value =   " << array << endl;
    cout << "array address = " << &array << endl;
    cout << "Calling Create Array" << endl;
    array = CreateArray(100);
    cout << "After Calling CreateArray" << endl;
    cout << "array value =   " << array << endl;
    cout << "array address = " << &array << endl;
    delete[] array;
    cout << "One More time..." << endl;
    cout << "Before Calling CreateArray" << endl;
    cout << "array value =   " << array << endl;
    cout << "array address = " << &array << endl;
    cout << "Calling Create Array" << endl;
    array = CreateArray(1000);
    cout << "After Calling CreateArray" << endl;
    cout << "array value =   " << array << endl;
    cout << "array address = " << &array << endl;
    delete[] array;

    return 0;
}

double* CreateArray(size_t size){
    cout << "Create Array Function Call" << endl << endl;
    cout << "\tsize value =   " << size << endl;
    cout << "\tsize address = " << &size << endl;
    double* retVal = nullptr;
    cout << "\tBefore Allocation --- " << endl;
    cout << "\tretVal value =   " << retVal << endl;
    cout << "\tretVal address = " << &retVal << endl;

    retVal = new double[size];
    cout << "\tAfter Allocation ---" << endl;
    cout << "\tretVal value =   " << retVal << endl;
    cout << "\tretVal address = " << &retVal << endl;
    cout << "---------------------------" << endl;
    return retVal;

}