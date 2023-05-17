#include "../../classes/operator/Operator.h"

Operator::Operator() {
    welcomeMessage();
    mainMenuDisplay();
}

void Operator::welcomeMessage(){
    cout << "Welcome to CryptCompress!!!" << endl;
    sleep(3);
    cout << "In this application you can easily archive your files and even crypt their content!" << endl;
    sleep(5);
    cout << "Let's dive in!" << endl;
    sleep(2);
    system("cls");
}

void Operator::mainMenuDisplay(){
    while(true){
        startTextFileProcessing();
    }
}

void Operator::startTextFileProcessing(){
    int option;
    cout << "Thank you for your choice!" << endl;
    cout << "Please, select one of the bellow options: " << endl;
    cout << "1. Your file is a plain text" << endl;
    cout << "2. Your file is encrypted" << endl;
    cout << "3. Your file is archived" << endl;
    cout << "4. Exit the application" << endl;
    cout << "Selected option: ";

    cin >> option;
    if (cin.fail()) {
        Common::handleCinInvalidParameter();
    }

    system("cls");
    switch(option){
        case 1: {
            try {
                textFile = new TextFile(Constants::FILE_PATH);
                textFile->citire();
                while(true){
                    textProcessor = new TextProcessor();
                    if(!textProcessor->startPlainTextFileProcessing(textFile)){
                        break;
                    }
                }
            } catch(exception& e) {
                cerr << e.what() << endl;
                system("pause");
                system("cls");
            }
            break;
        }
        case 2: {
            try {
                textFile = new TextFile(Constants::FILE_PATH);
                textFile->citire();
                while(true) {
                    textProcessor = new TextProcessor();
                    if(!textProcessor->startEncryptedFileProcessing(textFile)) {
                        break;
                    }
                }
            } catch(exception& e) {
                cerr << e.what() << endl;
                system("pause");
                system("cls");
            }
            break;
        }
        case 3: {
            try {
                textFile = new TextFile(Constants::FILE_PATH);
                textFile->citire();
                while(true){
                    textProcessor = new TextProcessor();
                    if(!textProcessor->startArchivedFileProcessing(textFile)){
                        break;
                    }
                }
            } catch (exception& e) {
                cerr << e.what() << endl;
                system("pause");
                system("cls");
            }
            break;
        }
        case 4:{
            Common::goodbyeMessage();
            break;
        }
        default:
            break;
    }
}

Operator::~Operator() {
    delete textFile;
    delete textProcessor;
}
