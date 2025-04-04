#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateDataFile(const char* filename, int size) {
    ofstream file(filename);
    if (!file) {
        cout << "Không thể tạo file!\n";
        return;
    }
    file << size << endl;  // Ghi kích thước mảng vào file
    srand(time(0));
    for (int i = 0; i < size; i++) {
        file << rand() % (size * 10) << " "; // Số ngẫu nhiên từ 0 -> size*10
    }
    file.close();
    cout << "Đã tạo file " << filename << " thành công!\n";
}

int main() {
    generateDataFile("input.txt", 30000);
    return 0;
}