#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void profile(){
cout <<"Nama: Muhammad Faiz Rabbani"<< endl;
cout <<"NIM : 231011402539"<< endl;
cout <<"Kelas: 03TPLP029"<< endl<< endl;
}

// Fungsi untuk menemukan pasangan yang jumlahnya sama dengan K
vector<pair<int, int>> findPairsWithSum(vector<int>& arr1, vector<int>& arr2, int K) {
    unordered_set<int> elements; // Hash set untuk menyimpan elemen dari arr1
    vector<pair<int, int>> result; // Menyimpan pasangan hasil

    // Tambahkan semua elemen dari arr1 ke dalam hash set
    for (int num : arr1) {
        elements.insert(num);
    }

    // Iterasi setiap elemen dari arr2
    for (int num : arr2) {
        int target = K - num; // Hitung elemen yang dibutuhkan dari arr1
        if (elements.count(target)) { // Jika ditemukan pasangan
            result.push_back({target, num});
        }
    }

    return result;
}

// Fungsi utama
int main() {
	profile();
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {4, 5, 6, 7, 8};
    int K = 9;

    // Panggil fungsi untuk menemukan pasangan
    vector<pair<int, int>> pairs = findPairsWithSum(arr1, arr2, K);

    // Cetak hasil
    cout << "Pasangan yang jumlahnya sama dengan " << K << ":\n";
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}

