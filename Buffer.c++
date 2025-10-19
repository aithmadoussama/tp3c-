#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Buffer {
private:
    size_t size;
    unsigned char* data;

public:
    Buffer() : size(0), data(nullptr) {
        cout << "Buffer de 0 octet(s)" << endl;
    }

    Buffer(size_t n) : size(n), data(new unsigned char[n]) {
        memset(data, 0, n);
        cout << "Buffer de " << size << " octet(s) créé" << endl;
    }

    Buffer(const Buffer& other) : size(other.size), data(nullptr) {
        if (size > 0) {
            data = new unsigned char[size];
            memcpy(data, other.data, size);
        }
        cout << "Constructeur de copie appelé ("
             << size << " octet(s))" << endl;
    }

    Buffer& operator=(const Buffer& other) = delete;

    size_t getSize() const {
        return size;
    }

    void fill(unsigned char value) {
        if (data) memset(data, value, size);
    }

    void printHex() const {
        for (size_t i = 0; i < size; ++i)
            cout << setw(2) << setfill('0') << hex << uppercase
                 << static_cast<int>(data[i]) << " ";
        cout << dec << endl;
    }

    ~Buffer() {
        delete[] data;
        cout << "Destruction du buffer de " << size << " octet(s)" << endl;
    }
};

int main() {
    Buffer b1;
    Buffer b2(8);
    b2.fill(0xAA);
    Buffer b3 = b2;

    cout << "Buffer 1 : " << b1.getSize() << " octet(s)" << endl;
    cout << "Buffer 2 : " << b2.getSize() << " octet(s) : ";
    b2.printHex();
    cout << "Buffer 3 (copie) : " << b3.getSize() << " octet(s) : ";
    b3.printHex();

    return 0;
}
