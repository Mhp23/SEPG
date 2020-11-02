#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <sstream>
#include <algorithm>

using namespace std;

class Initial {
private:
    int
    info_exist_count,
    info_count;

    string
    name,
    family,
    nationalCode,
    age,
    phoneNumber,
    birthday,
    partner,
    bestFriend,
    pet;

public:
    Initial();

    string
    getName(),
    getFamily(),
    getNationalCode(),
    getAge(),
    getPhoneNumber(),
    getBirthday(),
    getPartner(),
    getPet(),
    getBestFriend();

    vector<string>
    start();

    int
    getCountOfMethods();

    void
    enterInputText(string);

    bool
    isEmptyString(string),
    doYouNow(string),
    isValid(string x);

};

Initial::Initial(){

    this->info_count = 9;

    cout << "\n\t****************************************************************\n"
            "\t*                                                              *\n"
            "\t*       Welcome to Social Engineering Password Generator       *\n"
            "\t*                                                              *\n"
            "\t****************************************************************\n\n";
};

bool Initial::isEmptyString(string el){
    return el == "";
};

vector<string> Initial::start(){

    vector <string> informations;
    informations.push_back(getName());
    informations.push_back(getFamily());
    informations.push_back(getAge());
    informations.push_back(getBirthday());
    informations.push_back(getPhoneNumber());
    informations.push_back(getNationalCode());
    informations.push_back(getPartner());
    informations.push_back(getBestFriend());
    informations.push_back(getPet());

    const int len = informations.size();

    for ( int i=0 ; i < len ; i++ ) {
        const bool isEmpty = isEmptyString(informations[i]);
        if ( isEmpty )
            informations.erase( informations.begin() + i );

    };

    return informations;
};

bool Initial::doYouNow(string x){
    string answer;

    cout << "\nDo you know " << x << " of the person? (y/n) ";

    cin >> answer;

    if ( answer == "n" || answer == "N" ){
        return false;
    }

    else if ( answer == "y" || answer == "Y" ){
        return true;
    }

    return doYouNow(x);
};

void Initial::enterInputText(string x){
    cout << "\nEnter " << x << ": ";
};

string Initial::getName(){

    bool do_you_know = doYouNow("name");
    if ( !do_you_know ) return "";

    enterInputText("name");

    cin >> this->name;
    return this->name;
};

string Initial::getFamily(){

    bool do_you_know = doYouNow("family name");
    if ( !do_you_know ) return "";

    enterInputText("family name");

    cin >> this->family;
    return this->family;
};

string Initial::getNationalCode(){

    bool do_you_know = doYouNow("national code");
    if ( !do_you_know ) return "";

    enterInputText("national code");
    cin >> this->nationalCode;
    return this->nationalCode;
};

string Initial::getAge(){
    bool do_you_know = doYouNow("age");
    if ( !do_you_know ) return "";

    enterInputText("age");
    cin >> this->age;
    return this->age;
};

string Initial::getBirthday(){

    if ( this->age == "" ){
        this->birthday = "";
        return "";
    };

    time_t t = time(NULL);
    tm *currentTime = localtime(&t);

    int age_int;
    istringstream(this->age) >> age_int;

    int currentYear = currentTime->tm_year + 1900 - age_int;

    stringstream tmpYear;
    tmpYear << currentYear;
    tmpYear >> this->birthday;

    return this->birthday;
};

string Initial::getPhoneNumber(){

    bool do_you_know = doYouNow("phone number");
    if ( !do_you_know ) return "";

    enterInputText("phone number");
    cin >> this->bestFriend;
    return this->bestFriend;
};

string Initial::getBestFriend(){

    bool do_you_know = doYouNow("best friend name");
    if ( !do_you_know ) return "";

    enterInputText("best friend name");

    cin >> this->bestFriend;
    return this->bestFriend;
};

string Initial::getPartner(){

    bool do_you_know = doYouNow("partner name");
    if ( !do_you_know ) return "";

    enterInputText("partner name");
    cin >> this->partner;
    return this->partner;
};

string Initial::getPet(){

    bool do_you_know = doYouNow("pet name");
    if ( !do_you_know ) return "";

    enterInputText("pet name");
    cin >> this->pet;
    return this->pet;

};

bool Initial::isValid(string x){
    if ( x == "n" || x != "N" ) return false;
    return true;
};


