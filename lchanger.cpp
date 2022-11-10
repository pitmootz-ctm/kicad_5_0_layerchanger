#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream> 
#include "include/lchanger.h"

using namespace std;

bool confirm(){
    string inputline;
    cout << "Confirm changes on active file? (y/n): ";
    getline(cin, inputline);
    if (inputline.substr(0,1)=="y")
    {
        return true;
    }else{
        cout << "Exited program" << endl;
        return false;
    }
}


void change_layer(string filepath, string layer_to_change, string newlayer){
    ifstream infile;
    infile.open(filepath);

    std::string line;
    vector<string> input;

   // check if file is readable
    if(!infile){
        cerr << "Unable to open file.." << endl;
        exit(1);
    }

    while(getline(infile,line)){
        input.push_back(line);
    }
    
    // Find and replace the layers
    int counter=0;
    for (int i = 0; i < input.size(); i++)
    {
        if(input[i].find(layer_to_change)!=string::npos){

            input[i].replace(input[i].find(layer_to_change),layer_to_change.length(),newlayer);
            counter++;
        }
    }
    
    cout << "Replaced " << counter << " insertions" << endl;

    // write into new file

    // ENTER FILEPATH WITH FILENAME FOR OUTPUT FILE HERE
    ofstream outfile;
    outfile.open ("YOUR OUTPUT FILEPATH AND NAME");
    for(int i=0;i<input.size();i++){
        outfile << input[i] << endl;
    }
    outfile.close();

    cout << "Done" << endl;

    return;
}

void solver(){

    // ENTER FILEPATH AND LAYERS HERE
    string filepath = "FILEPATH OF THE INPUT FILE";
    string layer_to_change="Eco1.User";
    string newlayer= "F.Cu";

    if(confirm()){
    change_layer(filepath, layer_to_change, newlayer);
    }
    return;
}

