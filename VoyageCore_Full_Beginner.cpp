
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TourPackage{
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

    void input(){
        cout<<"Package ID: "; cin>>packageID;
        cin.ignore();
        cout<<"Destination: "; getline(cin,destination);
        cout<<"Duration: "; cin>>duration;
        cout<<"Price: "; cin>>price;
        cout<<"Seats: "; cin>>seats;
        cin.ignore();
        cout<<"Transport: "; getline(cin,transport);
    }

    void display() const{
        cout<<"\nID: "<<packageID
            <<"\nDestination: "<<destination
            <<"\nDuration: "<<duration
            <<"\nPrice: "<<price
            <<"\nSeats: "<<seats
            <<"\nTransport: "<<transport
            <<"\n-----------------\n";
    }

    int getID() const { return packageID; }
    string getDestination() const { return destination; }
    int getDuration() const { return duration; }
    float getPrice() const { return price; }
    int getSeats() const { return seats; }
    string getTransport() const { return transport; }
    void setSeats(int s){ seats=s; }
};

class Customer{
private:
    int customerID;
    string name,contact,email;

public:
    Customer(int id=0,string n="",string c="",string e=""){
        customerID=id; name=n; contact=c; email=e;
    }

    void input(){
        cout<<"Customer ID: "; cin>>customerID;
        cin.ignore();
        cout<<"Name: "; getline(cin,name);
        cout<<"Contact: "; getline(cin,contact);
        cout<<"Email: "; getline(cin,email);
    }

    void display() const{
        cout<<"\nID: "<<customerID
            <<"\nName: "<<name
            <<"\nContact: "<<contact
            <<"\nEmail: "<<email
            <<"\n-----------------\n";
    }

    int getID() const { return customerID; }
    string getName() const { return name; }
    string getContact() const { return contact; }
    string getEmail() const { return email; }
};

class Booking{
private:
    int bookingID,customerID,packageID,seatsBooked;
    string paymentStatus;

public:
    Booking(int b=0,int c=0,int p=0,int s=0,string pay=""){
        bookingID=b; customerID=c; packageID=p; seatsBooked=s; paymentStatus=pay;
    }

    void input(){
        cout<<"Booking ID: "; cin>>bookingID;
        cout<<"Customer ID: "; cin>>customerID;
        cout<<"Package ID: "; cin>>packageID;
        cout<<"Seats Booked: "; cin>>seatsBooked;
        cout<<"Payment Status(Paid/Pending): "; cin>>paymentStatus;
    }

    void display() const{
        cout<<"\nBooking ID: "<<bookingID
            <<"\nCustomer ID: "<<customerID
            <<"\nPackage ID: "<<packageID
            <<"\nSeats Booked: "<<seatsBooked
            <<"\nPayment: "<<paymentStatus
            <<"\n-----------------\n";
    }

    int getID() const { return bookingID; }
    int getCustomerID() const { return customerID; }
    int getPackageID() const { return packageID; }
    int getSeatsBooked() const { return seatsBooked; }
    string getPaymentStatus() const { return paymentStatus; }
};

TourPackage packages[50];
Customer customers[50];
Booking bookings[50];

int packageCount=0, customerCount=0, bookingCount=0;

void savePackages(){
    ofstream f("packages.txt");
    for(int i=0;i<packageCount;i++){
        f<<packages[i].getID()<<endl;
        f<<packages[i].getDestination()<<endl;
        f<<packages[i].getDuration()<<endl;
        f<<packages[i].getPrice()<<endl;
        f<<packages[i].getSeats()<<endl;
        f<<packages[i].getTransport()<<endl;
    }
}

int findPackage(int id){
    for(int i=0;i<packageCount;i++)
        if(packages[i].getID()==id) return i;
    return -1;
}

int findCustomer(int id){
    for(int i=0;i<customerCount;i++)
        if(customers[i].getID()==id) return i;
    return -1;
}

void lowSeatReport(){
    cout<<"\nLOW SEAT REPORT\n";
    for(int i=0;i<packageCount;i++)
        if(packages[i].getSeats()<5)
            packages[i].display();
}

void addBooking(){
    Booking b;
    b.input();

    int c=findCustomer(b.getCustomerID());
    int p=findPackage(b.getPackageID());

    if(c==-1){ cout<<"Customer not found\n"; return; }
    if(p==-1){ cout<<"Package not found\n"; return; }

    if(b.getSeatsBooked()>packages[p].getSeats()){
        cout<<"Not enough seats available\n";
        return;
    }

    packages[p].setSeats(packages[p].getSeats()-b.getSeatsBooked());

    bookings[bookingCount++]=b;

    float total=b.getSeatsBooked()*packages[p].getPrice();

    cout<<"\n===== INVOICE =====\n";
    cout<<"Customer: "<<customers[c].getName()<<endl;
    cout<<"Destination: "<<packages[p].getDestination()<<endl;
    cout<<"Seats: "<<b.getSeatsBooked()<<endl;
    cout<<"Total Bill: "<<total<<endl;
    cout<<"===================\n";
}

int main(){
    int choice;

    do{
        cout<<"\n===== VOYAGECORE =====\n";
        cout<<"1. Add Package\n";
        cout<<"2. Display Packages\n";
        cout<<"3. Add Customer\n";
        cout<<"4. Display Customers\n";
        cout<<"5. Add Booking\n";
        cout<<"6. Display Bookings\n";
        cout<<"7. Low Seat Report\n";
        cout<<"0. Exit\n";
        cout<<"Choice: ";
        cin>>choice;

        switch(choice){

        case 1:
            packages[packageCount].input();
            packageCount++;
            break;

        case 2:
            for(int i=0;i<packageCount;i++)
                packages[i].display();
            break;

        case 3:
            customers[customerCount].input();
            customerCount++;
            break;

        case 4:
            for(int i=0;i<customerCount;i++)
                customers[i].display();
            break;

        case 5:
            addBooking();
            break;

        case 6:
            for(int i=0;i<bookingCount;i++)
                bookings[i].display();
            break;

        case 7:
            lowSeatReport();
            break;
        }

    }while(choice!=0);

    return 0;
}
