#include <iostream>
using namespace std;

// Hàm hoán vị 2 số nguyên
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm Bubble Sort dùng để sắp xếp tăng hoặc giảm
void BubbleSort(int arr[], int n, bool SoChan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] == 0 || arr[j + 1] == 0) continue; // Giữ nguyên số 0
            if (SoChan) { // Sắp xếp số chẵn tăng dần
                if (arr[j] > arr[j + 1]) {
                    Swap(arr[j], arr[j + 1]);
                }
            } else { // Sắp xếp số lẻ giảm dần
                if (arr[j] < arr[j + 1]) {
                    Swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}

// Hàm sắp xếp chẵn tăng, lẻ giảm, giữ nguyên số 0
void sapXepChanLe(int arr[], int n) {
    int chan[n], le[n]; // Mảng chứa số chẵn và số lẻ
    int viTriChan[n], viTriLe[n]; // Lưu vị trí của số chẵn và số lẻ trong mảng gốc
    int soLuongChan = 0, soLuongLe = 0;

    // Phân loại số chẵn và số lẻ
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && arr[i] != 0) { // Số chẵn
            chan[soLuongChan] = arr[i];
            viTriChan[soLuongChan] = i;
            soLuongChan++;
        } else if (arr[i] % 2 != 0) { // Số lẻ
            le[soLuongLe] = arr[i];
            viTriLe[soLuongLe] = i;
            soLuongLe++;
        }
    }

    // Sắp xếp số chẵn tăng dần
    BubbleSort(chan, soLuongChan, true);
    // Sắp xếp số lẻ giảm dần
    BubbleSort(le, soLuongLe, false);

    // Đưa số chẵn đã sắp xếp về vị trí cũ
    for (int i = 0; i < soLuongChan; i++) {
        arr[viTriChan[i]] = chan[i];
    }
    // Đưa số lẻ đã sắp xếp về vị trí cũ
    for (int i = 0; i < soLuongLe; i++) {
        arr[viTriLe[i]] = le[i];
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    
    int arr[n];
    cout << "Nhap cac phan tu cho mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Gọi hàm sắp xếp
    sapXepChanLe(arr, n);

    // In mảng sau khi sắp xếp
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}