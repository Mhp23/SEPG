#include <fstream>
#include <iostream>
#include <dir.h>
#include <windows.h>
#include <string>
#include <algorithm>

const string outputsPath = "\\outputs\\";

using namespace std;

class IO {

private:
    string dir;

public:
    IO();

    string
    createNewFileName(),
    mergePath(string);

    vector <string> readFile(string);

    bool
    isReadyExsistFile(string);

    void
    setDir(string),
    writeFile(vector<string>,vector<string>,vector<string>),
    makeOutputsDirectory();
};

IO::IO(){

    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL , buffer , MAX_PATH);

    string::size_type index = string(buffer).find_last_of("\\/");

    string currentDir = string(buffer).substr(0,index);
    this->dir = currentDir;
};

string IO::mergePath(string path){
    return (dir + path);
};

bool IO::isReadyExsistFile(string path){
    if ( ifstream(mergePath(path).c_str()))
        return true;
    return false;
};

void IO::makeOutputsDirectory(){
    char* dirName = "outputs";
    int check = mkdir(dirName);
    delete dirName;
};

string IO::createNewFileName(){
    stringstream file_name_stream;
    time_t t = time(NULL);
    tm *currentTime = localtime(&t);

    file_name_stream
    << "SEPG_"
    << ( currentTime->tm_year + 1900 )
    << '_'
    << currentTime->tm_mon
    << '_'
    << currentTime->tm_mday
    << '_'
    << currentTime->tm_hour
    << '_'
    << currentTime->tm_min
    << '_'
    << currentTime->tm_sec
    << ".txt";

    return file_name_stream.str();
};

void IO::writeFile(vector<string>passwords,vector<string>predictable_password,vector<string> common_with_available_information){

    string file_name = createNewFileName();

    const string file_path = mergePath(outputsPath + file_name);

    ofstream output_file( file_path.c_str() );

    if ( output_file.is_open()){

        for ( int i = 0 ; i < predictable_password.size() ; i++ ){
            output_file << predictable_password[i] << endl;
        };

        for ( int i = 0 ; i < passwords.size() ; i++ ){
            output_file << passwords[i] << endl;
        };

        for ( int i = 0 ; i < common_with_available_information.size() ; i++ ){
            output_file << common_with_available_information[i] << endl;
        };

        output_file.close();

        cout << "\nYour passwords were created.\nYou can now access it from " << dir + file_path << endl;
    }

    else cout << "Can't create file" << endl;

    vector<string>().swap(passwords);
};

vector<string> IO::readFile(string filePath){
    const string path = mergePath(filePath);
    ifstream file( path.c_str() );
    string line;
    vector <string> contents;

    if ( file.is_open()){
        while ( !file.eof()){
            getline(file,line);
            contents.push_back(line);
        }
    }

    else cout << "Can't open "<< path << "file";

    file.close();
    return contents;

};

