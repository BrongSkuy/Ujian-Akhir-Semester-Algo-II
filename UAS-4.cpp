#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void profile(){
cout <<"Nama: Muhammad Faiz Rabbani"<< endl;
cout <<"NIM : 231011402539"<< endl;
cout <<"Kelas: 03TPLP029"<< endl<< endl;
}


// Radix Sort
void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};

    // Hitung frekuensi digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Akumulasi count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Bangun array output
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Salin output ke array asli
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr) {
    int maxVal = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Quick Sort
template <typename T>
std::vector<T> quickSort(const std::vector<T>& arr) {
    if (arr.size() <= 1) return arr;

    T pivot = arr[0];
    std::vector<T> less, greater;

    std::copy_if(arr.begin() + 1, arr.end(), std::back_inserter(less), [pivot](T x) { return x <= pivot; });
    std::copy_if(arr.begin() + 1, arr.end(), std::back_inserter(greater), [pivot](T x) { return x > pivot; });

    auto sortedLess = quickSort(less);
    auto sortedGreater = quickSort(greater);

    sortedLess.push_back(pivot);
    sortedLess.insert(sortedLess.end(), sortedGreater.begin(), sortedGreater.end());

    return sortedLess;
}

// Merge Sort
template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Main Function
int main() {
	profile();
    std::vector<int> data = {170, 45, 75, 90, 802, 24, 2, 66};

    std::vector<int> data1 = data;
    std::vector<int> data2 = data;
    std::vector<int> data3 = data;

    // Radix Sort
    radixSort(data1);
    std::cout << "Radix Sort: ";
    for (int num : data1) std::cout << num << " ";
    std::cout << "\n";

    // Quick Sort
    data2 = quickSort(data2);
    std::cout << "Quick Sort: ";
    for (int num : data2) std::cout << num << " ";
    std::cout << "\n";

    // Merge Sort
    mergeSort(data3, 0, data3.size() - 1);
    std::cout << "Merge Sort: ";
    for (int num : data3) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}

