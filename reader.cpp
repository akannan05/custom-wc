#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

int main(int argc, char* argv[]){
    if(argc < 2){
        cerr << "Invalid Arguments." << endl;
        return 1;
    }

    bool bflag = false;
    bool lflag = false;
    bool wflag = false;
    bool cflag = false;

    vector<string> filenames;

    for(int i = 1; i < argc; i++){
        string arg = argv[i];
       if(arg == "-c")
           bflag = true;
       else if(arg == "-l")
          lflag = true; 
       else if(arg == "-w")
          wflag = true; 
       else if(arg == "-m")
          cflag = true; 
       else
          filenames.push_back(arg);
    }

   vector<string> outputs;

   for(int i = 0; i < filenames.size(); i++){
       if(bflag){
          ifstream file(filenames[i], ios::binary | ios::ate);
          if(!file)
              cerr << "Error Opening File " << filenames[i] << "." << endl;

          streamsize fileSize = file.tellg();
          file.close();

          string output = "Size (bytes) of file " + filenames[i] + " is " + to_string(fileSize) + ".";
          outputs.push_back(output);
       }
       if(lflag){
          ifstream file(filenames[i]);
          if(!file)
              cerr << "Error Opening File " << filenames[i] << "." << endl;

          int linecnt = 0;
          string l;  

          while(getline(file, l))
              linecnt++;

          string output = "Size (lines) of file " + filenames[i] + " is " + to_string(linecnt) + ".";
          outputs.push_back(output);
       }
       if(wflag){
          ifstream file(filenames[i]);
          if(!file)
              cerr << "Error Opening File " << filenames[i] << "." << endl;

          int wordcnt = 0;
          string l;
          while(getline(file, l)){
              istringstream iss(l);
              string w;

              while(iss >> w)
                  wordcnt++;
          }

          string output = "Size (words) of file " + filenames[i] + " is " + to_string(wordcnt) + ".";
          outputs.push_back(output);
       }
       if(cflag){
          ifstream file(filenames[i], ios::ate);
          if(!file)
              cerr << "Error Opening File " << filenames[i] << "." << endl;
           
          streamsize filesize = file.tellg();
          file.close();

          string output = "Size (characters) of file " + filenames[i] + " is " + to_string(filesize) + ".";
          outputs.push_back(output);
       }
   }

   for(string o : outputs)
       cout << o << endl;

   return 0;
}
