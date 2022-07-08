#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include<algorithm>
using namespace std;

//#################### These are so I don't get lost in my code.
class Address {     //"created a class to store one address in."
public:
    string wholeAddress;
    string network;
    string host;
    //this is so the non abc classes don't get called.
    string addressClass = "temp";  //"throws away/ignores D and E class addresses"
    int octetOne, octetTwo, octetThree, octetFour;
    
//this was a constructor but then I realized no values were passed to it yet
//until the overloaded >> operater passed the values. Now it is called after.
    void build() { 
        vector<string> result;
        stringstream s_stream(wholeAddress); //create string stream from the string
        while(s_stream.good()) {
          string substr;
          getline(s_stream, substr, '.'); //get first string delimited by comma
          result.push_back(substr);
        }
        //I did this beceause it got mad when converting string to int
        //and I found out there was whitespace making it mad.
        for (int i = 0; i < 4; i++) {   
          remove(result[i].begin(), result[i].end(), ' ');
        }
        //this assigns the octets for later use.
        stringstream temp1(result[0]);
        temp1 >> octetOne;
        stringstream temp2(result[1]);
        temp2 >> octetTwo;
        stringstream temp3(result[2]);
        temp3 >> octetThree;
        stringstream temp4(result[3]);
        temp4 >> octetFour;
        //this will determint which class the address is 
        if (octetOne < 128) {
            addressClass = "A";
            network = (to_string(octetOne));
            host = (to_string(octetTwo)+"."+to_string(octetThree)+"."+to_string(octetFour));
        }
        if (octetOne > 127 && octetOne < 192) {
            addressClass = "B";
            network = (to_string(octetOne)+"."+to_string(octetTwo));
            host = (to_string(octetThree)+"."+to_string(octetFour));
        }
        if (octetOne > 191 && octetOne < 224){
            addressClass = "C";
            network = (to_string(octetOne)+"."+to_string(octetTwo)+"."+to_string(octetThree));
            host = (to_string(octetFour));
        }
        return;
    }
    string getClass(){
        return addressClass;
    }
};
//####################
istream& operator >> (istream& is, Address& addrs)      //"overloaded the operators >> and << for reading and writing an address."
{
    getline(is, addrs.wholeAddress);
    return is;
}
//####################
ostream& operator<<(ostream& os, Address& addrs)        //"overloaded the operators >> and << for reading and writing an address."
{
    os << "Network: " << addrs.network << " Host: " << addrs.host << "\n";
    return os;
}
//####################
struct sortByFirstOctal     //"each list of addresses is sorted by first octet"
{
    inline bool operator() (const Address& add1, const Address& add2)
    {
        return (add1.octetOne < add2.octetOne);
    }
};
//####################
int main(void) {
    vector<Address> aVect;  //"created vectors of addresses for each class (A, B, and C)."
    vector<Address> bVect; 
    vector<Address> cVect; 
    fstream newfile;
    newfile.open("/public/lab7/addresses.txt",ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){   //checking whether the file is open
        string tp;
        while(!newfile.eof()) {
            Address address;
            newfile >> address;     //"read each address from a file"
            address.build();
            if (address.getClass() == "A") {
                aVect.push_back(address);
            }
            if (address.getClass() == "B") {
                bVect.push_back(address);
            }
            if (address.getClass() == "C") {
                cVect.push_back(address);
            }
        }

        newfile.close(); //close the file object.
    }
    sort(aVect.begin(), aVect.end(), sortByFirstOctal());
    sort(bVect.begin(), bVect.end(), sortByFirstOctal());
    sort(cVect.begin(), cVect.end(), sortByFirstOctal());
    // This will pring the following vecters for each class.
    cout << "Class A has " << aVect.size() << " network addresses: \n"; //"print out the number of addresses in each class"
    int a = aVect.size();
    for(int i=0; i < a; i++){    //"print out the list of addresses in each class"
        cout << aVect[i];
    }
    cout << "Class B has " << bVect.size() << " network addresses: \n";
    int b = bVect.size();
    for(int i=0; i < b; i++){
        cout << bVect[i];
    }
    cout << "Class C has " << cVect.size() << " network addresses: \n";
    int c = cVect.size();
    for(int i=0; i < c; i++){
        cout << cVect[i];
    }
    return 0;
}