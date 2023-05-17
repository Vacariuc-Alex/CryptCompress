#ifndef COMMON_H
#define COMMON_H

#include "string"

using namespace std;

class Common {
public:
    inline static void handleCinInvalidParameter() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid Value!" << endl;
        sleep(1);
        system("cls");
    }

    inline static void goodbyeMessage() {
        cout << "Thank you for choosing CryptCompress!" << endl;
        sleep(3);
        cout << "Have a great day!" << endl;
        sleep(2);
        exit(0);
    }
};

#endif
