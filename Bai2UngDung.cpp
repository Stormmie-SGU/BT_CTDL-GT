#include <iostream>

using namespace std;

// Định nghĩa struct SoHang để lưu số hạng của đa thức
struct SoHang {
    double heSo; // Hệ số
    int bac;     // Bậc
};

// Hàm hoán vị hai số hạng (đổi chỗ)
void swap(SoHang &a, SoHang &b) {
    SoHang temp = a;
    a = b;
    b = temp;
}

// Hàm sắp xếp theo bậc tăng dần (Interchange Sort)
void interchangeSort(SoHang arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].bac > arr[j].bac) { 
                swap(arr[i], arr[j]); 
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhập số lượng số hạng của đa thức: ";
    cin >> n;

    SoHang daThuc[n]; // Khai báo mảng động

    // Nhập từng số hạng
    for (int i = 0; i < n; i++) {
        cout << "Nhập hệ số của số hạng " << i + 1 << ": ";
        cin >> daThuc[i].heSo;
        cout << "Nhập bậc của số hạng " << i + 1 << ": ";
        cin >> daThuc[i].bac;
    }

    // Gọi hàm sắp xếp
    interchangeSort(daThuc, n);

    // In kết quả sau khi sắp xếp
    cout << "Đa thức sau khi sắp xếp theo bậc:\n";
    for (int i = 0; i < n; i++) {
    if (i > 0) cout << " + "; // Chỉ in " + " từ số hạng thứ 2 trở đi
    cout << daThuc[i].heSo << "x^" << daThuc[i].bac;
}
    cout << endl;

    return 0;
}
