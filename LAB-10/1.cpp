#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void encryptToFile(const string& filename, const string& text) {
    ofstream file(filename);
    for (size_t i = 0; i < text.size(); ++i) {
        file << char(text[i] + (i + 1));
    }
    file.close();
}
string decryptFromFile(const string& filename) {
    ifstream file(filename);
    string encrypted, decrypted;
    getline(file, encrypted);
    for (size_t i = 0; i < encrypted.size(); ++i) {
        decrypted += char(encrypted[i] - (i + 1));
    }
    file.close();
    return decrypted;
}
int main() {
    string input;
    cout << "Enter String = ";
    getline(cin, input);
    cout << "Normal Text:= " << input << endl;
    encryptToFile("encrypted.txt", input);
    cout << "Encrypted text inserted in file" << endl;
    string decrypted = decryptFromFile("encrypted.txt");
    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decrypted << endl;
    return 0;
}