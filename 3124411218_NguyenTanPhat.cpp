#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

// (1) Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// (2) Hàm sắp xếp mảng theo yêu cầu
void sortArray(int* arr, int n) {
    int primes[n], nonPrimes[n];
    int primeCount = 0, nonPrimeCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i]))
            primes[primeCount++] = arr[i];
        else
            nonPrimes[nonPrimeCount++] = arr[i];
    }
    
    for (int i = 0; i < primeCount - 1; i++) {
        for (int j = i + 1; j < primeCount; j++) {
            if (primes[i] > primes[j])
                swap(primes[i], primes[j]);
        }
    }
    for (int i = 0; i < nonPrimeCount - 1; i++) {
        for (int j = i + 1; j < nonPrimeCount; j++) {
            if (nonPrimes[i] > nonPrimes[j])
                swap(nonPrimes[i], nonPrimes[j]);
        }
    }
    
    int idx = 0;
    for (int i = 0; i < primeCount; i++) arr[idx++] = primes[i];
    for (int i = 0; i < nonPrimeCount; i++) arr[idx++] = nonPrimes[i];
}

// (3) Hàm đếm số lần xuất hiện của chuỗi x trong chuỗi s
int countOccurrences(const string& s, const string& x) {
    int count = 0, pos = s.find(x);
    while (pos != string::npos) {
        count++;
        pos = s.find(x, pos + x.length());
    }
    return count;
}

// (4) Hàm tìm từ dài nhất trong chuỗi s
string longestWord(const string& s) {
    stringstream ss(s);
    string word, longest;
    while (ss >> word) {
        if (word.length() > longest.length())
            longest = word;
    }
    return longest;
}

int main() {
    ifstream inFile("DE03.INP");
    ofstream outFile("DE03.OUT");
    
    if (!inFile) {
        cout << "Không thể mở file DE03.INP" << endl;
        return 1;
    }
    
    int n;
    inFile >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) inFile >> *(arr + i);
    inFile.ignore();
    
    string s, x;
    getline(inFile, s);
    getline(inFile, x);
    inFile.close();
    
    cout << "Mang: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nChuoi s: " << s << "\nChuoi x: " << x << endl;
    
    // (2) Sắp xếp mảng
    sortArray(arr, n);
    
    // (3) Đếm số lần xuất hiện của x
    int countX = countOccurrences(s, x);
    
    // (4) Tìm từ dài nhất
    string longest = longestWord(s);
    
    // (5) In kết quả ra console
    cout << "Mang sau sap xep: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nSo lan xuat hien cua x: " << countX;
    cout << "\nTu dai nhat: " << longest << endl;
    
    // (5) Ghi ra file
    for (int i = 0; i < n; i++) outFile << arr[i] << " ";
    outFile << "\n" << countX << "\n" << longest << "\n";
    outFile.close();
    
    delete[] arr;
    return 0;
}