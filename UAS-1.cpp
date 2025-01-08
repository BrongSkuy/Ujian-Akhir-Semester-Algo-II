#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

void profile(){
cout <<"Nama: Muhammad Faiz Rabbani"<< endl;
cout <<"NIM : 231011402539"<< endl;
cout <<"Kelas: 03TPLP029"<< endl<< endl;
}

// Node untuk Pohon Huffman
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Operator untuk Priority Queue
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

// Fungsi untuk membuat pohon Huffman
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Masukkan setiap karakter dan frekuensinya ke dalam queue
    for (const auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Gabungkan node hingga tersisa satu
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    return pq.top();
}

// Fungsi untuk membuat tabel encoding
void buildEncodingTable(HuffmanNode* root, const string& str, unordered_map<char, string>& encodingTable) {
    if (!root) return;

    if (!root->left && !root->right) {
        encodingTable[root->ch] = str;
    }

    buildEncodingTable(root->left, str + "0", encodingTable);
    buildEncodingTable(root->right, str + "1", encodingTable);
}

// Fungsi untuk encoding string
string encode(const string& text, const unordered_map<char, string>& encodingTable) {
    string encodedStr;
    for (char ch : text) {
        encodedStr += encodingTable.at(ch);
    }
    return encodedStr;
}

// Fungsi untuk decoding string
string decode(const string& encodedStr, HuffmanNode* root) {
    string decodedStr;
    HuffmanNode* current = root;

    for (char bit : encodedStr) {
        current = (bit == '0') ? current->left : current->right;

        if (!current->left && !current->right) {
            decodedStr += current->ch;
            current = root;
        }
    }

    return decodedStr;
}

int main() {
	profile();
    string text;
    cout << "Masukkan string: ";
    cin >> text;

    // Hitung frekuensi karakter
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    // Bangun pohon Huffman
    HuffmanNode* root = buildHuffmanTree(freqMap);

    // Buat tabel encoding
    unordered_map<char, string> encodingTable;
    buildEncodingTable(root, "", encodingTable);

    // Encoding string
    string encodedStr = encode(text, encodingTable);
    cout << "Encoded String: " << encodedStr << endl;

    // Decoding string
    string decodedStr = decode(encodedStr, root);
    cout << "Decoded String: " << decodedStr << endl;

    return 0;
}

