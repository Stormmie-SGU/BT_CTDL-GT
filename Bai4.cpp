#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;
const int size = 30000;
// Hàm đọc mảng từ file
void readArrayFromFile(const char* filename, int arr[], int &size) {
    ifstream file(filename);
    if (!file) {
        cout << "Không thể mở file!\n";
        exit(1);
    }
    file >> size;  // Đọc kích thước mảng
    arr = new int[size]; // Cấp phát sau khi biết size
    for (int i = 0; i < size; i++) {
        file >> arr[i];  // Đọc từng phần tử
    }
    file.close();
}

// Hàm ghi mảng ra file
void writeArrayToFile(const char* filename, int arr[], int size) {
    ofstream file(filename);
    if (!file) {
        cout << "Không thể mở file để ghi!\n";
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        file << arr[i] << " ";
    }
    file.close();
}

 //1. Interchange Sort
 void InterchangeSort(int arr[], int n){
    for (int i=0; i < n-1; i++){
        for(int j=i+1; j < n; j++){
            if (arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
 }

 //2. Selection Sort
 void SelectionSort(int arr[], int n){
    for(int i=0; i < n-1;i++){
        int Min = i; // lưu vị trí nhỏ nhất chưa sắp xếp 
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[Min]){
                Min = j;
            }
        }    
        swap(arr[i], arr[Min]);
    }
 }

 //3. Insertion Sort
 void InsertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key= arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
 }

 //4. Bubble Sort
 void BubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j= 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
 }

//5.Heap sort
void Heapify(int arr[],int n,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && arr[left]>arr[largest]) largest = left;
    if(right<n && arr[right]>arr[largest]) largest =right;
    // Nếu largest thay đổi, hoán đổi và đệ quy
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

    //6.Ham sap xep Heap
void HeapSort(int arr[],int n)
{
    for(int i=(n/2)-1;i>=0;i--) Heapify(arr,n,i);
    //doi cho node dau tien voi node cuoi cung
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        Heapify(arr,i,0);
    }
}
    //ham
void Merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;   // Kích thước mảng con bên trái
    int n2 = high - mid;      // Kích thước mảng con bên phải

    int left[n1], right[n2];  // Tạo mảng tạm để lưu hai mảng con

    // Sao chép phần tử vào mảng tạm left[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];

    // Sao chép phần tử vào mảng tạm right[]
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;  // Chỉ số cho mảng left, right và mảng gốc arr

    // Trộn hai mảng con lại theo thứ tự tăng dần
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {  // Chọn phần tử nhỏ hơn để đưa vào arr[k]
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng left[] nếu có
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng right[] nếu có
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

    //6.Ham sap xep Merge
void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

//Phan vung mang
int Partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Chọn phần tử cuối làm pivot
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Đưa pivot về đúng vị trí
    return i + 1; // Trả về vị trí mới của pivot
}

//7.Ham sap xep QuickSort
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = Partition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

//Hàm đo thời gian chạy
void MeasureTime(int size)
{

    int* arr=new int[30000];


    readArrayFromFile("input.txt", arr, size); // Đọc dữ liệu gốc từ file
    clock_t start, end;


    double  time_use_Heap,time_use_Merge,time_use_Quick,time_use_Interchange,time_use_Bubble,time_use_Selection,time_use_Insertion;
    //Đo thời gian thực hiện heap sort
    int *arr_Heap=new int [size];//cấp phát mảng động
    //Cấp phát mảng ngẫu nhiên
    copy(arr,arr+size,arr_Heap);// Sao chép nội dung của arr vào arr_heap để đảm bảo cùng dữ liệu ban đầu
    start=clock();//bắt đầu đo thời gian
    HeapSort(arr_Heap,size);//gọi hàm Heáport để sắp xếp mảng arr_Heap
    end =clock();//kết thúc đo thời gian
    time_use_Heap=(double)(end-start)/CLOCKS_PER_SEC;//tính thời gian chạy đổi sang giây
    delete[] arr_Heap;//giải phóng bộ nhớ

    //Đo thời gian thực hiện merge sort
    int *arr_Merge=new int [size];
    copy(arr,arr+size,arr_Merge);
    start=clock();
    MergeSort(arr_Merge,0,size-1);
    end=clock();
    time_use_Merge=(double)(end-start)/CLOCKS_PER_SEC;
    delete[] arr_Merge;

    //Đo thời gian thực hiện quick sort
    int * arr_Quick=new int [size];
    copy(arr,arr+size,arr_Quick);
    start=clock();
    QuickSort(arr_Quick,0,size-1);
    end=clock();
    time_use_Quick=(double)(end-start)/CLOCKS_PER_SEC;
    delete[] arr_Quick;

     //Đo thời gian thực hiện interchange sort
    int * arr_Interchange=new int [size];
    copy(arr,arr+size,arr_Interchange);
    start=clock();
    InterchangeSort(arr_Interchange,size);
    end=clock();
    time_use_Interchange=(double)(end-start)/CLOCKS_PER_SEC;
    delete[] arr_Interchange;

     //Đo thời gian thực hiện bubble sort
    int * arr_Bubble=new int [size];
    copy(arr,arr+size,arr_Bubble);
    start=clock();
    BubbleSort(arr_Bubble,size);
    end=clock();
    time_use_Bubble=(double)(end-start)/CLOCKS_PER_SEC;
    delete[] arr_Bubble;

    //Đo thời gian thực hiện selection sort
    int * arr_Selection=new int [size];
    copy(arr,arr+size,arr_Selection);
    start=clock();
    SelectionSort(arr_Selection,size);
    end=clock();
    time_use_Selection=(double)(end-start)/CLOCKS_PER_SEC;
    delete[] arr_Selection;

    //Đo thời gian thực hiện insertion sort
    int * arr_Insertion=new int [size];
    copy(arr,arr+size,arr_Insertion);
    start=clock();
    InsertionSort(arr_Insertion,size);
    end=clock();
    time_use_Insertion=(double)(end-start)/CLOCKS_PER_SEC;
    delete[] arr_Insertion;

    //Xuat thoi gian thuc hien
        cout<<"Size: "<<size<<endl;
    cout<<"Thoi gian thuc hien HeappSort: "<<time_use_Heap<<"s"<<endl;
    cout<<"Thoi gian thuc hien MergeSort: "<<time_use_Merge<<"s"<<endl;
    cout<<"Thoi gian thuc hien QuickSort: "<<time_use_Quick<<"s"<<endl;
    cout<<"Thoi gian thuc hien InterchangeSort: "<<time_use_Interchange<<"s"<<endl;
    cout<<"Thoi gian thuc hien BubbleSort: "<<time_use_Bubble<<"s"<<endl;
    cout<<"Thoi gian thuc hien SelectionSort: "<<time_use_Selection<<"s"<<endl;
    cout<<"Thoi gian thuc hien InsertionSort: "<<time_use_Insertion<<"s"<<endl;
    delete[] arr;
}



int main()
{
    
    // taoj kich thuoc cho mang ngau nhien
   
    cout<<"Đang chờ thời gian chạy ..."<<endl;
    int size=0;
    
    MeasureTime(size);
    
    return 0;
}
