/**
 * DeLeon, Edward Jr
 *  First Code Fragment: Cost Analysis 
 *                       Empirical vs. Analytical
 * Code Fragment: 
 *   int sum = 1;
 *      for(int a=0; a<n; a++) 
 *      {
 *          sum = sum*2;
 *      }   
 *      while(sum>0) {
 *          sum--;
 *      }
 *  input: i03.dat -> values of n.
 *  output: o03.dat -> display cost analysis.
 * 
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

struct CommandLineExcep {
    CommandLineExcep(int m, int a) {
        cout << "Too many file names on command line." << endl 
              << m << "file names are permitted." << endl 
              << a << "file names are entered." << endl;
    }
};

struct FileException {
    FileException(const char* m) {
        cout << endl << "File " << m << "could not opened." << endl;
    }
};

int ef3(int n) {
    int c = 0;              
    int sum = 1;            c++;
    int a = 0;              c++;         
    while(a < n) {          c++;      
        sum = sum * 2;      c+=2;
        a++;                c++;
    }                       c++;                  
    while(sum > 0){         c++;
        sum--;              c++;
        }                   c++;
    return c;
}

int af3(int n) {
    return  4*n + 4 + 2*pow(2,n);
}

void Print(ostream& o, int n) {
    o << endl;
    o << setw(5) << n << " ";
    // o << setw(10) << e << " ";
    // o << setw(10) << a;
    o << setw(10) << ef3(n) << " ";
    o << setw(10) << af3(n);
}

void Title(ostream& o) { // param: Output File One
    o << endl;          
    o << setw( 5) << "n" << " ";
    o << setw(10) << "Empirical" << " ";
    o << setw(10) << "Analytical";
}

void Tn(istream& i, ostream& o){
    Title(o);
    for (;;){ 
        int n;
        i >> n;
        if(i.eof())
            break;
        // Print(o, n, ef3(n), af3(n));
        Print(o,n);
    }
    o << endl;
}

int main(int argc, char* argv[]) {
    try {
        char ifn2[255];
        char ofn[255];
        switch(argc) {
            case 1:
                cout << "Enter input file name 1. ";
                cin >> ifn2;
                cout << "Enter the output file name. ";
                cin >> ofn;
                break;
            case 2:
                strcpy(ifn2, argv[1]);
                cout << "Enter the output file name. ";
                cin >> ofn;
                break;
            case 3:
                strcpy(ifn2, argv[1]);
                strcpy(ofn, argv[2]);
                break;
            default:
                throw CommandLineExcep(2, argc-1);
        }
       ifstream i2(ifn2); 
        if(!i2) 
            throw FileException(ifn2);
        
        ofstream o(ofn); 
        if(!o) 
            throw FileException(ofn);
        Tn(i2,o);
        cout << endl;
        o.close();
        i2.close();
    } catch(...) {
        cout << endl << "Program terminated." << endl
                     << "I won't be back!" << endl;
        exit(EXIT_FAILURE);
    }
    
    return 0;
} 
