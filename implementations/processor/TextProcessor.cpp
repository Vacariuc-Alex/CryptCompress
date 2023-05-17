#include "../../classes/processor/TextProcessor.h"

TextProcessor::TextProcessor() {}

bool TextProcessor::startPlainTextFileProcessing(TextFile* textFile){
    int option;
    system("cls");
    cout << "Please, select what do you want to do with the file: " << endl;
    cout << "1. Show content" << endl;
    cout << "2. Encrypt" << endl;
    cout << "3. Archive" << endl;
    cout << "4. Return to previous menu" << endl;
    cout << "5. Exit the application" << endl;
    cout << "Selected option: ";

    cin >> option;
    if (cin.fail()) {
        Common::handleCinInvalidParameter();
    }

    system("cls");
    switch(option){
        case 1:{
            textFile->afisare();
            cout << endl;
            system("pause");
            system("cls");
            break;
        }
        case 2:{
            string encryptedContentFromFile = textFile->criptare();
            textFile->setFileEnding(Constants::FILE_ENDING_ENCRYPTED);
            textFile->salvare(encryptedContentFromFile);

            cout << "The file was successfully encrypted and saved!" << endl;
            sleep(2);
            cout << "Please check the following folder: " << textFile->getFilePath() << endl;

            system("pause");
            system("cls");
            break;
        }
        case 3:{
            string archivedContentFromFile = textFile->arhivare();
            textFile->setFileEnding(Constants::FILE_ENDING_ARCHIVED);
            textFile->salvare(archivedContentFromFile);

            cout << "The file was successfully archived and saved!" << endl;
            sleep(2);
            cout << "Please check the following folder: " << textFile->getFilePath() << endl;

            system("pause");
            system("cls");
            break;
        }
        case 4:{
            return false;
            break;
        }
        case 5:{
            Common::goodbyeMessage();
            break;
        }
        default:
            break;
    }
    return true;
}

bool TextProcessor::startEncryptedFileProcessing(TextFile* textFile){
    int option;
    system("cls");
    cout << "Please, select what do you want to do with the file: " << endl;
    cout << "1. Show content" << endl;
    cout << "2. Decrypt" << endl;
    cout << "3. Archive" << endl;
    cout << "4. Return to previous menu" << endl;
    cout << "5. Exit the application" << endl;
    cout << "Selected option: ";

    cin >> option;
    if (cin.fail()) {
        Common::handleCinInvalidParameter();
    }

    system("cls");
    switch(option){
        case 1:{
            textFile->afisare();
            system("pause");
            system("cls");
            break;
        }
        case 2:{
            string decryptedContentFromFile = textFile->decriptare();
            textFile->setFileEnding(Constants::FILE_ENDING_DECRYPTED);
            textFile->salvare(decryptedContentFromFile);

            cout << "The file was successfully decrypted and saved!" << endl;
            sleep(2);

            cout << "Please check the following folder: " << textFile->getFilePath() << endl;
            system("pause");
            system("cls");
            break;
        }
        case 3:{
            string archivedContentFromFile = textFile->arhivare();
            textFile->setFileEnding(Constants::FILE_ENDING_ARCHIVED);
            textFile->salvare(archivedContentFromFile);

            cout << "The file was successfully archived and saved!" << endl;
            sleep(2);
            cout << "Please check the following folder: " << textFile->getFilePath() << endl;

            system("pause");
            system("cls");
            break;
        }
        case 4:
            return false;
            break;
        case 5:
            Common::goodbyeMessage();
            break;
        default:
            break;
    }
    return true;
}

bool TextProcessor::startArchivedFileProcessing(TextFile* textFile){
    int option;
    system("cls");
    cout << "Please, select what do you want to do with the file: " << endl;
    cout << "1. Show content" << endl;
    cout << "2. Encrypt" << endl;
    cout << "3. Unarchive" << endl;
    cout << "4. Return to previous menu" << endl;
    cout << "5. Exit the application" << endl;
    cout << "Selected option: ";

    cin >> option;
    if (cin.fail()) {
        Common::handleCinInvalidParameter();
    }

    system("cls");
    switch(option){
        case 1:{
            textFile->afisare();
            system("pause");
            system("cls");
            break;
        }
        case 2:{
            string encryptedContentFromFile = textFile->criptare();
            textFile->setFileEnding(Constants::FILE_ENDING_ENCRYPTED);
            textFile->salvare(encryptedContentFromFile);

            cout << "The file was successfully encrypted and saved!" << endl;
            sleep(2);
            cout << "Please check the following folder: " << textFile->getFilePath() << endl;

            system("pause");
            system("cls");
            break;
        }
        case 3:{
            string unarchivedContentFromFile = textFile->dezarhivare();
            textFile->setFileEnding(Constants::FILE_ENDING_UNARCHIVED);
            textFile->salvare(unarchivedContentFromFile);

            cout << "The file was successfully unarchived and saved!" << endl;
            sleep(2);
            cout << "Please check the following folder: " << textFile->getFilePath() << endl;

            system("pause");
            system("cls");
            break;
        }
        case 4:
            return false;
            break;
        case 5:
            Common::goodbyeMessage();
            break;
        default:
            break;
    }
    return true;
}

TextProcessor::~TextProcessor() {}
