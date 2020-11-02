#include <string>
#include <iostream>
using namespace std;

class Generator {
public:
    vector<string>
    combineWithCommon(vector<string> , vector<string>),
    permutations(vector<string>);
};

vector<string> Generator::permutations(vector <string> informations){
    vector<string> PGA;
    const int len = informations.size();

    for ( int i=0 ; i < len ; i++ ){
        for ( int j = 0 ; j < len ; j++ ){
            string generated = informations[i] + informations[j];
            PGA.push_back(generated);
        };
    };

    vector<string>().swap(informations);
    return PGA;
};

vector<string> Generator::combineWithCommon(vector <string> informations , vector <string> common_passwords ){
    vector<string> PGA;
    const int inf_len = informations.size();
    const int cp_len = common_passwords.size();

    for ( int i=0 ; i < inf_len ; i++ ){
        for ( int j = 0 ; j < cp_len ; j++ ){
            string generated = informations[i] + common_passwords[j];
            PGA.push_back(generated);
        };
    };

    vector<string>().swap(informations);
    vector<string>().swap(informations);

    return PGA;
};
