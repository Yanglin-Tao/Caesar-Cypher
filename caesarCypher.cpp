//
//  main.cpp
//  hw01_new
//
//  Created by Yanglin Tao on 10/24/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

char decryptChar(int rotation, char aChar){
    if(aChar <= 'z' && aChar >= 'a' + rotation % 26){
        aChar -= rotation % 26;
    }
    else if(aChar >= 'a' && aChar < 'a' + rotation % 26){
        aChar = 'z' - rotation + aChar - 'a' + 1;
    }
    return aChar;
}

void decryptString(int rotation, string& aString){
    for(size_t i = 0; i < aString.size(); i++){
        aString[i] = decryptChar(rotation, aString[i]);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream ifs("encrypted.txt");
    if(!ifs){
        cout << "Could not open file.\n";
    }
    int rotation;
    ifs >> rotation;
    string line;
    vector<string> strings;
    
    while(getline(ifs, line)){
        strings.push_back(line);
    }
    
    for(size_t i = strings.size() - 1; i > 0; i--){
        decryptString(rotation, strings[i]);
    }
    
    for(size_t i = strings.size() - 1; i > 0; i--){
        cout << strings[i] << endl;
    }
    
    return 0;
}
