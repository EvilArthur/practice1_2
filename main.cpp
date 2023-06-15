#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FiboCipher {
private:
    vector<string> splitedText;
    vector<int> fiboSequence;
    vector<int> key;

    void splitText(const string& text) {
        string word;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                splitedText.push_back(word);
                word = "";
                continue;
            }
            word += text[i];
        }
        splitedText.push_back(word);
    }

    void generateFiboSequence() {
        int n1 = 1;
        int n2 = 2;
        for (int i = 0; i < splitedText.size(); i++) {
            fiboSequence.push_back(n1);
            n1 += n2;
            swap(n1, n2);
        }
    }
public:
    FiboCipher(string text , vector<int>& newKey) {
        splitText(text);
        key = newKey;
        generateFiboSequence();
    }

    void writeKey() {
        int num;
        key.clear();
        for (int i = 0; i < splitedText.size(); i++) {
            cin >> num;
            key.push_back(num);
        }
    }
    void showKey() {
        for (int i : key) {
            cout << i << " ";
        }
    }

    void encode() {
        for (int i = 0; i < splitedText.size(); i++) {
            for (int j = 0; j < splitedText.size(); j++) {
                if (key[i] == fiboSequence[j]) {
                    swap(fiboSequence[j], fiboSequence[i]);
                    swap(splitedText[j], splitedText[i]);
                }
            }
        }
    }

    void decode() {
        for (int i = 0; i < splitedText.size(); i++) {
            for (int j = 0; j < splitedText.size(); j++) {
                if (fiboSequence[i] < fiboSequence[j]) {
                    swap(fiboSequence[j], fiboSequence[i]);
                    swap(splitedText[j], splitedText[i]);
                }
            }
        }
    }

    void showText() {
        for (string word : splitedText) {
            cout << word << " ";
        }
        cout << endl;
    }
};
int main()
{
    vector<int> key = { 2, 8, 5, 1, 3 };
    FiboCipher message("Hello, my name is Ivan.", key);
    message.showText();
    message.encode();
    message.showText();
    message.decode();
    message.showText();


}

