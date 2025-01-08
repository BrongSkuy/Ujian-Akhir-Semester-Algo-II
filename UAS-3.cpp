#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void profile(){
cout <<"Nama: Muhammad Faiz Rabbani"<< endl;
cout <<"NIM : 231011402539"<< endl;
cout <<"Kelas: 03TPLP029"<< endl<< endl;
}

template <typename T>
std::vector<T> quickSort(const std::vector<T>& arr) {
    // Basis: Jika array kosong atau memiliki satu elemen, kembalikan langsung.
    if (arr.size() <= 1) {
        return arr;
    }

    // Pilih elemen pivot.
    T pivot = arr[0];

    // Gunakan fungsi lambda untuk memisahkan elemen lebih kecil dan lebih besar dari pivot.
    std::vector<T> less, greater;
    std::copy_if(arr.begin() + 1, arr.end(), std::back_inserter(less), [pivot](T x) { return x <= pivot; });
    std::copy_if(arr.begin() + 1, arr.end(), std::back_inserter(greater), [pivot](T x) { return x > pivot; });

    // Rekursi untuk bagian kiri dan kanan, lalu gabungkan hasilnya.
    std::vector<T> sortedLess = quickSort(less);
    std::vector<T> sortedGreater = quickSort(greater);

    // Gabungkan hasil (less + pivot + greater).
    sortedLess.push_back(pivot);
    sortedLess.insert(sortedLess.end(), sortedGreater.begin(), sortedGreater.end());

    return sortedLess;
}

// Contoh penggunaan.
int main() {
	profile();
    std::vector<int> data = {10, 7, 8, 9, 1, 5};
    std::vector<int> sortedData = quickSort(data);

    for (int num : sortedData) {
        std::cout << num << " ";
    }

    return 0;
}

