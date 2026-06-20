
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

    void getData(){
        cout<<"Package ID: "; cin>>packageID;
        cin.ignore();
        cout<<"Destination: "; getline(cin,destination);
        cout<<"Duration (days): "; cin>>duration;
        cout<<"Price: "; cin>>price;
        cout<<"Seats: "; cin>>seats;
        cin.ignore();
        cout<<"Transport: "; getline(cin,transport);
    }

    void showData() const{
        cout<<"\nID: "<<packageID
            <<"\nDestination: "<<destination
            <<"\nDuration: "<<duration
            <<"\nPrice: "<<price
            <<"\nSeats: "<<seats
            <<"\nTransport: "<<transport
            <<"\n-------------------------\n";
    }

    int getID() const { return packageID; }
    float getPrice() const { return price; }
    int getSeats() const { return seats; }
    string getDestination() const { return destination; }
    void setSeats(int s){ seats=s; }

    void updateData(){
        cin.ignore();
        cout<<"New Destination: "; getline(cin,destination);
        cout<<"New Duration: "; cin>>duration;
        cout<<"New Price: "; cin>>price;
        cout<<"New Seats: "; cin>>seats;
        cin.ignore();
        cout<<"New Transport: "; getline(cin,transport);
    }

    friend ofstream& operator<<(ofstream& out,const TourPackage& p){
        out<<p.packageID<<'\n'<<p.destination<<'\n'<<p.duration<<'\n'
           <<p.price<<'\n'<<p.seats<<'\n'<<p.transport<<'\n';
        return out;
    }

    friend ifstream& operator>>(ifstream& in,TourPackage& p){
        string tmp;
        if(!(in>>p.packageID)) return in;
        in.ignore();
        getline(in,p.destination);
        in>>p.duration;
        in>>p.price;
        in>>p.seats;
        in.ignore();
        getline(in,p.transport);
        return in;
    }
};

class Customer{
private:
    int customerID;
    string name,contact,email;
public:
    Customer(int id=0,string n="",string c="",string e=""){
        customerID=id; name=n; contact=c; email=e;
    }

    void getData(){
        cout<<"Customer ID: "; cin>>customerID;
        cin.ignore();
        cout<<"Name: "; getline(cin,name);
        cout<<"Contact: "; getline(cin,contact);
        cout<<"Email: "; getline(cin,email);
    }

    void showData() const{
        cout<<"\nID: "<<customerID
            <<"\nName: "<<name
            <<"\nContact: "<<contact
            <<"\nEmail: "<<email
            <<"\n-------------------------\n";
    }

    int getID() const { return customerID; }
    string getName() const { return name; }

    void updateData(){
        cin.ignore();
        cout<<"New Name: "; getline(cin,name);
        cout<<"New Contact: "; getline(cin,contact);
        cout<<"New Email: "; getline(cin,email);
    }

    friend ofstream& operator<<(ofstream& out,const Customer& c){
        out<<c.customerID<<'\n'<<c.name<<'\n'<<c.contact<<'\n'<<c.email<<'\n';
        return out;
    }

    friend ifstream& operator>>(ifstream& in,Customer& c){
        if(!(in>>c.customerID)) return in;
        in.ignore();
        getline(in,c.name);
        getline(in,c.contact);
        getline(in,c.email);
        return in;
    }
};

class Booking{
private:
    int bookingID,customerID,packageID,seatsBooked;
    string paymentStatus;
public:
    Booking(int b=0,int c=0,int p=0,int s=0,string pay=""){
        bookingID=b; customerID=c; packageID=p; seatsBooked=s; paymentStatus=pay;
    }

    int getID() const { return bookingID; }
    int getCustomerID() const { return customerID; }
    int getPackageID() const { return packageID; }
    int getSeatsBooked() const { return seatsBooked; }
    string getPaymentStatus() const { return paymentStatus; }

    void input(){
        cout<<"Booking ID: "; cin>>bookingID;
        cout<<"Customer ID: "; cin>>customerID;
        cout<<"Package ID: "; cin>>packageID;
        cout<<"Seats Booked: "; cin>>seatsBooked;
        cout<<"Payment Status (Paid/Pending): "; cin>>paymentStatus;
    }

    void showData() const{
        cout<<"\nBooking ID: "<<bookingID
            <<"\nCustomer ID: "<<customerID
            <<"\nPackage ID: "<<packageID
            <<"\nSeats Booked: "<<seatsBooked
            <<"\nPayment: "<<paymentStatus
            <<"\n-------------------------\n";
    }

    void updateData(){
        cout<<"New Customer ID: "; cin>>customerID;
        cout<<"New Package ID: "; cin>>packageID;
        cout<<"New Seats: "; cin>>seatsBooked;
        cout<<"New Payment Status: "; cin>>paymentStatus;
    }

    friend ofstream& operator<<(ofstream& out,const Booking& b){
        out<<b.bookingID<<'\n'<<b.customerID<<'\n'<<b.packageID<<'\n'
           <<b.seatsBooked<<'\n'<<b.paymentStatus<<'\n';
        return out;
    }

    friend ifstream& operator>>(ifstream& in,Booking& b){
        if(!(in>>b.bookingID)) return in;
        in>>b.customerID>>b.packageID>>b.seatsBooked;
        in.ignore();
        getline(in,b.paymentStatus);
        return in;
    }
};

TourPackage packages[50]; int packageCount=0;
Customer customers[50]; int customerCount=0;
Booking bookings[50]; int bookingCount=0;

void savePackages(){ ofstream f("packages.txt"); for(int i=0;i<packageCount;i++) f<<packages[i]; }
void saveCustomers(){ ofstream f("customers.txt"); for(int i=0;i<customerCount;i++) f<<customers[i]; }
void saveBookings(){ ofstream f("bookings.txt"); for(int i=0;i<bookingCount;i++) f<<bookings[i]; }

void loadPackages(){ ifstream f("packages.txt"); packageCount=0; while(f>>packages[packageCount]) packageCount++; }
void loadCustomers(){ ifstream f("customers.txt"); customerCount=0; while(f>>customers[customerCount]) customerCount++; }
void loadBookings(){ ifstream f("bookings.txt"); bookingCount=0; while(f>>bookings[bookingCount]) bookingCount++; }

int findPackage(int id){ for(int i=0;i<packageCount;i++) if(packages[i].getID()==id) return i; return -1; }
int findCustomer(int id){ for(int i=0;i<customerCount;i++) if(customers[i].getID()==id) return i; return -1; }
int findBooking(int id){ for(int i=0;i<bookingCount;i++) if(bookings[i].getID()==id) return i; return -1; }

void lowSeatReport(){
    cout<<"\nLOW SEAT PACKAGES\n";
    bool found=false;
    for(int i=0;i<packageCount;i++){
        if(packages[i].getSeats()<5){ packages[i].showData(); found=true; }
    }
    if(!found) cout<<"No Low Seat Packages\n";
}

void addBooking(){
    Booking b; b.input();

    int c=findCustomer(b.getCustomerID());
    if(c==-1){ cout<<"Customer Not Found\n"; return; }

    int p=findPackage(b.getPackageID());
    if(p==-1){ cout<<"Package Not Found\n"; return; }

    if(b.getSeatsBooked()>packages[p].getSeats()){
        cout<<"Not Enough Seats Available\n"; return;
    }

    packages[p].setSeats(packages[p].getSeats()-b.getSeatsBooked());

    bookings[bookingCount++]=b;
    saveBookings();
    savePackages();

    float total=b.getSeatsBooked()*packages[p].getPrice();

    cout<<"\n====== VOYAGECORE INVOICE ======\n";
    cout<<"Customer: "<<customers[c].getName()<<endl;
    cout<<"Destination: "<<packages[p].getDestination()<<endl;
    cout<<"Seats: "<<b.getSeatsBooked()<<endl;
    cout<<"Total Bill: PKR "<<total<<endl;
    cout<<"Payment: "<<b.getPaymentStatus()<<endl;
    cout<<"===============================\n";
}

void cancelBooking(){
    int id; cout<<"Enter Booking ID: "; cin>>id;
    int b=findBooking(id);
    if(b==-1){ cout<<"Booking Not Found\n"; return; }

    int p=findPackage(bookings[b].getPackageID());
    if(p!=-1){
        packages[p].setSeats(packages[p].getSeats()+bookings[b].getSeatsBooked());
        float refund=bookings[b].getSeatsBooked()*packages[p].getPrice()*0.8f;
        cout<<"Refund Amount: PKR "<<refund<<endl;
    }

    for(int i=b;i<bookingCount-1;i++) bookings[i]=bookings[i+1];
    bookingCount--;

    saveBookings();
    savePackages();

    cout<<"Booking Cancelled Successfully\n";
}

int main(){
    loadPackages();
    loadCustomers();
    loadBookings();

    int choice;

    do{
        cout<<"\n====== VOYAGECORE ======\n";
        cout<<"1.Add Package\n2.Display Packages\n3.Search Package\n4.Update Package\n5.Delete Package\n";
        cout<<"6.Add Customer\n7.Display Customers\n8.Search Customer\n9.Update Customer\n10.Delete Customer\n";
        cout<<"11.Add Booking\n12.Display Bookings\n13.Search Booking\n14.Update Booking\n15.Delete Booking\n";
        cout<<"16.Low Seat Report\n17.Cancel Booking + Refund\n0.Exit\nChoice: ";
        cin>>choice;

        int id,pos;

        switch(choice){

        case 1:
            packages[packageCount].getData();
            packageCount++;
            savePackages();
            break;

        case 2:
            for(int i=0;i<packageCount;i++) packages[i].showData();
            break;

        case 3:
            cout<<"Package ID: "; cin>>id;
            pos=findPackage(id);
            if(pos!=-1) packages[pos].showData(); else cout<<"Not Found\n";
            break;

        case 4:
            cout<<"Package ID: "; cin>>id;
            pos=findPackage(id);
            if(pos!=-1){ packages[pos].updateData(); savePackages(); }
            else cout<<"Not Found\n";
            break;

        case 5:
            cout<<"Package ID: "; cin>>id;
            pos=findPackage(id);
            if(pos!=-1){ for(int i=pos;i<packageCount-1;i++) packages[i]=packages[i+1]; packageCount--; savePackages(); }
            else cout<<"Not Found\n";
            break;

        case 6:
            customers[customerCount].getData();
            customerCount++;
            saveCustomers();
            break;

        case 7:
            for(int i=0;i<customerCount;i++) customers[i].showData();
            break;

        case 8:
            cout<<"Customer ID: "; cin>>id;
            pos=findCustomer(id);
            if(pos!=-1) customers[pos].showData(); else cout<<"Not Found\n";
            break;

        case 9:
            cout<<"Customer ID: "; cin>>id;
            pos=findCustomer(id);
            if(pos!=-1){ customers[pos].updateData(); saveCustomers(); }
            else cout<<"Not Found\n";
            break;

        case 10:
            cout<<"Customer ID: "; cin>>id;
            pos=findCustomer(id);
            if(pos!=-1){ for(int i=pos;i<customerCount-1;i++) customers[i]=customers[i+1]; customerCount--; saveCustomers(); }
            else cout<<"Not Found\n";
            break;

        case 11:
            addBooking();
            break;

        case 12:
            for(int i=0;i<bookingCount;i++) bookings[i].showData();
            break;

        case 13:
            cout<<"Booking ID: "; cin>>id;
            pos=findBooking(id);
            if(pos!=-1) bookings[pos].showData(); else cout<<"Not Found\n";
            break;

        case 14:
            cout<<"Booking ID: "; cin>>id;
            pos=findBooking(id);
            if(pos!=-1){ bookings[pos].updateData(); saveBookings(); }
            else cout<<"Not Found\n";
            break;

        case 15:
            cout<<"Booking ID: "; cin>>id;
            pos=findBooking(id);
            if(pos!=-1){ for(int i=pos;i<bookingCount-1;i++) bookings[i]=bookings[i+1]; bookingCount--; saveBookings(); }
            else cout<<"Not Found\n";
            break;

        case 16:
            lowSeatReport();
            break;

        case 17:
            cancelBooking();
            break;
        }

    }while(choice!=0);

    return 0;
}
