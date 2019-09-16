#include<iostream>// I/O of console window
#include<fstream>// I/O of file
#include<sstream>// I/O of in-memory string
#include<string>
#include<vector>
using namespace::std;
// ----------------------------------------------
// Ex 8.1, read stream until end-of-file
istream &read_input(istream &is){
// reset all the conditions of istream
    is.clear();
    string temp;
// tie *is to ostream
    is.tie(&cout);// untie: is.tie(nullptr)
    while (getline(is, temp))
// flush output buffer: endl, ends, flush, unitbuff, tie to ostream
        cout<<temp;
// is.eof(): state of end-of-file, ends: add null char
    cout<<boolalpha<<is.eof()<<ends;
    is.clear(is.rdstate() & ~is.eofbit);//reset strm::eofbit
}
//-----------------------------------------------
// Ex 8.8, 8.10, 8.11, read line from file into a vector, then access each word
void read_file(const string ifile, vector<string> &vlin ){
// create a file stream and open file named "ifile"
    ifstream fin(ifile);// ifstream fin; fin.open(ifile)
    string line, word;
// operations of string stream, Table 8.5
    istringstream record;
    if(!fin){// fail to open file
        cerr<<"fail to open: "<<ifile<<unitbuf;
        return;
     }
// read each line from ifstream
    while(getline(fin, line))
        vlin.push_back(line);
    for (const auto &elin: vlin){
        record.clear();// reset sstream from end-of-file
        record.str(elin);// copy elin into record
// read word from istringstream
        while(record>>word)
            cout<<word<<'\0';
    }
// open file from ofstream, append mode, perseve data
    ofstream fout(ifile, ofstream::app);//trunc: default mode of ofstream
}
//------------------------------------------------
int main(int argc, char *argv[]){
// states of IO stream, Table 8.2, istream: input stream type, cin: istream object
    read_input(cin);
// operations of file stream, Table 8.3; stream mode, Table 8.4
    ifstream fin;
    vector<string> v;
    read_file(argv[1],v);
    return 0;
}
