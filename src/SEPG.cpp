#include <iostream>
#include <vector>
#include "initial.h"
#include "io.h"
#include "generator.h"

const char* predictable_password_file_path = "\\passwords\\predictable_password.txt";

using namespace std;

int main(){

    Initial *init = new Initial();
    IO *io = new IO;
    Generator *generator = new Generator();

    const vector <string> predictable_password = io->readFile(predictable_password_file_path);

    if ( predictable_password.size() == 0 ) return 0;

    const vector <string> available_information = init->start();
    const vector <string> permutations = generator->permutations(available_information);
    const vector <string> combine_with_common = generator->combineWithCommon(available_information,predictable_password);


    io->writeFile(permutations,predictable_password,combine_with_common);
    delete predictable_password_file_path;
};
