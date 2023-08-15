#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
    int value = 42;

    // Convert to binary
    stringstream binaryStream;
    binaryStream << bitset<8 * sizeof(value)>(value);
    string binaryString = binaryStream.str();
    cout << "Decimal " << value << " to binary: " << binaryString << endl;

    // Convert to hexadecimal
    stringstream hexStream;
    hexStream << "0x" << hex << value;
    string hexString = hexStream.str();
    cout << "Decimal " << value << " to hexadecimal: " << hexString << endl;

    // Convert to decimal from hexadecimal
    int decimalFromHex;
    stringstream(hexString) >> hex >> decimalFromHex;
    cout << "Hexadecimal " << hexString << " to decimal: " << decimalFromHex << endl;

    // Convert to decimal from binary
    bitset<8 * sizeof(value)> tempBitset;
    stringstream(binaryString) >> tempBitset;
    int decimalFromBinary = static_cast<int>(tempBitset.to_ulong());
    cout << "Binary " << binaryString << " to decimal: " << decimalFromBinary << endl;

    return 0;
}
