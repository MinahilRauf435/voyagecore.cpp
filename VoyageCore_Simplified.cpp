// VoyageCore_Simplified.cpp
// Beginner-Friendly Template (No friend / operator overloading)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TourPackage {
private:
    int packageID;
    string destination;
    int duration;
    float price;
    int seats;
    string transport;

public:
    TourPackage(int id=0,string d="",int dur=0,float p=0,int s=0,string t=""){
        packageID=id; destination=d; duration=dur; price=p; seats=s; transport=t;
    }

    int getID() const { return packageID; }
    string getDestination() const { return destination; }
    int getDuration() const { return duration; }
    float getPrice() const { return price; }
    int getSeats() const { return seats; }
    string getTransport() const { return transport; }
    void setSeats(int s){ seats=s; }
};

int main(){
    cout << "VoyageCore Simplified Template Loaded!" << endl;
    return 0;
}
