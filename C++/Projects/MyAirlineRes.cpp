#include<bits/stdc++.h>
using namespace std;

class Airline{
public:
    int flight_id;
    string flight_name;
    int seats;
    string source;
    string destination;
    float ticket_charge;
    float time_taken;

    void getDate(){
        cout<<"\n\n\t\t ***********************";
        cout<<"\n\n\t\t # ENTER FLIGHT RECORD #";
        cout<<"\n\n\t\t ***********************";
        cout<<"\n\n\t\t # Flight id      :-->";
        cin>>flight_id;
        cout<<"\n\n\t\t # Flight name    :-->";
        getline(cin, flight_name);
        cout<<"\n\n\t\t # No of seats    :--> ";
        cin>>seats;
        cout<<"\n\n\t\t # Source         :-->   ";
        getline(cin, source);
        cout<<"\n\n\t\t # Destination    :-->   ";
        getline(cin, destination);
        cout<<"\n\n\t\t # Ticket charges :-->Rs.";
        cin>>ticket_charge;
        cout<<"\n\n\t\t # Time taken     :-->";
        cin>>time_taken;
    }

    void showDate(){
        cout<<"\n\n\t\t *****************";
        cout<<"\n\n\t\t # FLIGHT RECORD #";
        cout<<"\n\n\t\t *****************";
        cout<<"\n\n\t\t # Flight id is     :-->"<<flight_id;
        cout<<"\n\n\t\t # Flight name is   :-->"<<flight_name;
        cout<<"\n\n\t\t # No of seats      :-->"<<seats;
        cout<<"\n\n\t\t # Source           :-->"<<source;
        cout<<"\n\n\t\t # Destination      :-->"<<destination;
        cout<<"\n\n\t\t # Ticket charges   :-->"<<ticket_charge;
        cout<<"\n\n\t\t # Time taken       :-->"<<time_taken;
        cout<<"\n\n\t\t #######################";
        cin.ignore();
        cin.get();
    }

    void showAll(){
        cout<<"\n\n\t# "<<flight_id<<"     "<<flight_name<<"     ";
        cout<<source<<"     "<<destination<<"     ";
        cout<<ticket_charge <<endl;
    }
};


class Customer{
public:
    string customer_name;
    float customer_id;
    int age;
    string address;
    string country;
    long phoneNumber;
    long mobileNumber;

    void getData(){
        cout<<"\n\n\t\t ***********************";
        cout<<"\n\n\t\t # ENTER FLIGHT RECORD #";
        cout<<"\n\n\t\t ***********************";
        cout<<"\n\n\t\t # Customer ID    :-->   ";
        cin>>customer_id;
        cout<<"\n\n\t\t # Customer name  :-->   ";
        getline(cin, customer_name);
        cout<<"\n\n\t\t # Age            :-->   ";
        cin>>age;
        cout<<"\n\n\t\t # Address        :-->   ";
        getline(cin, address);
        cout<<"\n\n\t\t # Nationallity   :-->   ";
        getline(cin, country);
        cout<<"\n\n\t\t # Phone no       :-->   ";
        cin>>phoneNumber;
        cout<<"\n\n\t\t # Mobile no.     :-->";
        cin>>mobileNumber;
    }
    
    void showData(){
        cout<<"\n\n\t\t *****************";
        cout<<"\n\n\t\t # CUSTOMER RECORD #";
        cout<<"\n\n\t\t *****************";
        cout<<"\n\n\t\t # Customer ID      :-->"<<customer_id;
        cout<<"\n\n\t\t # Customer Name    :-->"<<customer_name;
        cout<<"\n\n\t\t # Age              :-->"<<age;
        cout<<"\n\n\t\t # Address          :-->"<<address;
        cout<<"\n\n\t\t # Nationallity     :-->"<<country;
        cout<<"\n\n\t\t # Phone No.        :-->"<<phoneNumber;
        cout<<"\n\n\t\t # Mobile No.       :-->"<<mobileNumber;
        cout<<"\n\n\t\t #######################";
        cin.ignore();
        cin.get();
    }

    void showALl(){
        cout<<"\n\n\t# "<<customer_id<<"     "<<customer_name<<"     "<<age;
        cout<<address<<"     "<<country<<"     ";
        cout<<phoneNumber<<"     "<<mobileNumber<<endl;
    }
};


class Booking{
public:
    int seat_no;
    int flight_no;
    int customer_id;
    int day;
    int month;
    int year;

    void getData(){
        cout<<"\n\n\t\t *********************************";
        cout<<"\n\n\t\t # ENTER SEAT BOOKING RECORD #";
        cout<<"\n\n\t\t *********************************";
        cout<<"\n\n\t\t # Seat number    :-->   ";
        cin>>seat_no;
        cout<<"\n\n\t\t # Day            :-->   ";
        cin>>day;
        cout<<"\n\n\t\t # Month          :-->   ";
        cin>>month;
        cout<<"\n\n\t\t # Year           :-->   ";
        cin>>year;
    }

    void showDate(){
        cout<<"\n\n\t\t *****************************";
        cout<<"\n\n\t\t # SEAT BOOKING RECORD #";
        cout<<"\n\n\t\t *****************************";
        cout<<"\n\n\t\t # Customer ID      :-->"<<customer_id;
        cout<<"\n\n\t\t # Seat number      :-->"<<seat_no    ;
        cout<<"\n\n\t\t # Flight number    :-->"<<flight_no  ;
        cout<<"\n\n\t\t # Day              :-->"<<day	     ;
        cout<<"\n\n\t\t # Month            :-->"<<month	     ;
        cout<<"\n\n\t\t # Year             :-->"<<year	     ;
        cout<<"\n\n\t\t ####################################";
        cin.ignore();
        cin.get();
    }

    void showAll(){
        cout<<"\n\n\t# "<<customer_id<<"     "<<seat_no<<"     "<<flight_no;
	    cout<<day<<"     "<<month<<"     "<<year;
    }
};

//********** FUNCTION OF FLIGHT RECORD **********

void flight_record(){
	system("cls");
    int fch;
    do
    {
        cout<<"\n\n\t\t**************";
        cout<<"\n\n\t\tOption-Flights";
        cout<<"\n\n\t\t**************\n\n\t\t";
        cout<<"\n\n\t\t 1.Add a flight ";
        cout<<"\n\n\t\t 2.List all flights ";
        cout<<"\n\n\t\t 3.Search for a flight";
        cout<<"\n\n\t\t 4.Update a flight";
        cout<<"\n\n\t\t 5.Delete a flight";
        cout<<"\n\n\t\t 6.Back to main menu";
        cout<<"\n\n\t\t Enter your choice:-->";
        cin>>fch;
        switch(fch)
        {
        case 1:
            system("cls");
            add_flights();
            break;
        case 2:
            system("cls");
            list_flights();
            break;
        case 3:
            system("cls");
            search_flight();
            break;
        case 4:
            system("cls");
            update_flight();
            break;
        case 5:
            system("cls");
            delete_flight();
            break;
        case 6:
            system("cls");
            break;
        default:
            cout<<"\n\n\t\t Invalid choice"<<endl;
            cin.ignore();
            cin.get();
            break;
        }

    }while(fch != 6);
    system("cls");
}

void add_flights(){
    char yn;
    f1.open("abc2.dat",ios::in|ios::out|ios::ate);
    ob1.getdata();

    cout<<"\n\n\t\t # Do you want to store the data (y/n):-->";
    cin>>yn;
    if(yn=='y' || yn=='Y')
    {
        f1.write((char*) &ob1,sizeof(ob1));
        cout<<"\n\n\t\t***// DATA IS STORED \\***";
    }
    else
        cout<<"\n\n\t\t***// DATA IS NOT STORED \\***";

    f1.close();
    cin.ignore();
    cin.get();
    system("cls");
}

void list_flights(){
    system("cls");
    f1.open("abc2.dat",ios::in);
    while(f1.read((char*)&ob1,sizeof(ob1)))
    {
        ob1.showall();
    }
    cin.ignore();
    cin.get();
    f1.close();
    system("cls");
}

void search_flight(){
    int c=0;
    float fno;
    cout<<"\n\n\t\t  # Enter flight no :-->";
    cin>>fno;
    f1.open("abc2.dat",ios::in);

    while(f1.read((char*)&ob1,sizeof(ob1)))
    {
        if(fno==ob1.flight_no)
        {
            c=1;
            break;
        }
    }
    if(c==0)
    {
        cout<<"\n\n\t\t **// Not found \\**";

        cin.ignore();
        cin.get();
        f1.close();
        return;
    }
    ob1.showdata();
    cin.ignore();
    cin.get();
    f1.close();
    system("cls");
}

void update_flight(){
    int c=0;
    float fno;
    cout<<"\n\n\t\t  # Enter flight no :-->";
    cin>>fno;
    f1.open("abc2.dat",ios::in|ios::out|ios::ate);
    f1.seekg(0);

    while(f1.read((char*)&ob1,sizeof(ob1)))
    {
        if(fno==ob1.flight_no)
        {
            c=1;
            break;
        }
    }
    f1.clear();

    if(c==0)
    {
        cout<<"\n\n\t\t **// Not found \\**";
        cin.ignore();
        cin.get();
        f1.close();
        return;
    }

    char yn;
    int pos=f1.tellp();
    f1.seekp(pos-sizeof(ob1));
    ob1.showdata();
    cout<<"\n\n\t\t # Do you want to modify the data (y/n):-->";
    cin>>yn;

    if(yn=='y' || yn=='Y')
    {
        float new_ticket;
        cout<<"\n\n\t\t Enter the new ticket charges:-->";
        cin>> new_ticket;
        ob1.ticket_charge=new_ticket;
        f1.write((char*) &ob1,sizeof(ob1));
        cout<<"\n\n\t\t***// DATA IS MODIFIED \\***";
    }
    else
        cout<<"\n\n\t\t***// DATA IS NOT MODIFIED \\***";

    cin.ignore();
    cin.get();
    f1.close();
    system("cls");
}

void delete_flight(){
    int c=0;
    int fno;
    cout<<"\n\n\t\t  # Enter flight no :-->";
    cin>>fno;
    f1.open("abc2.dat",ios::in);
    f2.open("temp.dat",ios::out);

    while(f1.read((char*)&ob1,sizeof(ob1)))
    {
        if(fno!=ob1.flight_no)
            f2.write((char*) &ob1,sizeof(ob1));
        else
            c=1;
    }
    f1.close();
    f2.close();
    if(c==0)
	{
        cout<<"\n\n\t\t **// Not found \\**";
        getch();
        return;
	}

	remove("abc2.dat");
	rename("temp.dat","abc2.dat");
	cout<<"\n\n\t\t***// DATA IS DELETED \\***";

    cin.ignore();
    cin.get();
	system("cls");
}

//********** FUNCTION OF CUSTOMER RECORD **********

void customer_record(){
    system("cls");
    int cch;
    do
    {
    cout<<"\n\n\t\t****************";
    cout<<"\n\n\t\tOption-Customer";
    cout<<"\n\n\t\t****************\n\n\t\t";
    cout<<"\n\n\t\t 1.Add a Customer ";
    cout<<"\n\n\t\t 2.List all Customer ";
    cout<<"\n\n\t\t 3.Search for a Customer";
    cout<<"\n\n\t\t 4.Update a Customer";
    cout<<"\n\n\t\t 5.Delete a Customer";
    cout<<"\n\n\t\t 6.Back to main menu";
    cout<<"\n\n\t\t Enter your choice:-->";
    cin>>cch;
    switch(cch) {
	case 1:
		   system("cls");

		   add_customer();
		   break;
	case 2:
		   system("cls");
		   list_customer();
		   break;
	case 3:
		   system("cls");
		   search_customer();
		   break;
	case 4:
		    system("cls");
		    update_customer();
		    break;
	case 5:
		    system("cls");
		    delete_customer();
		    break;
	case 6:
		    system("cls");
		    break;
	default:
		    cout<<"\n\n\t\t Invalid choice"<<endl;
		    getch();
		    break;
        }
   }while(cch!=6);
   system("cls");
}
void add_customer();
void list_customer();
void search_customer();
void update_customer();
void delete_customer();



void customer_id();
void seat_no();
void flight_no();
void day();
void month();
void year();
void seat_book();

void list();
void customer_id_wise();
void flight_wise();
void date_wise();


void main(){
    system("cls");
   	int ch;
   	do
   	{
	cout<<"\n\n\n\n\t\t**************************";
	cout<<"\n\t\tAirways Reservation System";
	cout<<"\n\t\t**************************\n\n\n";
	cout<<"\n\t\t 1.Flight record"<<endl;
	cout<<"\n\t\t 2.Customer record"<<endl;
	cout<<"\n\t\t 3.Seat Booking"<<endl;
	cout<<"\n\t\t 4.Listing"<<endl;
	cout<<"\n\t\t 5.Exit"<<endl;
	cout<<"\n\t\t Enter your choice:-->";
	cin>>ch;
	switch(ch)
	{
		case 1:
			system("cls");
			flight_record();
			break;
		case 2:
			system("cls");
			customer_record();
			break;
		case 3:
			system("cls");
			seat_book();
			break;
		case 4:
			system("cls");
			list();
			break;
		case 5:
			break;
		default:
			cout<<"\n\t\tInvalid choice";
			cin.ignore();
            cin.get();
			system("cls");
			break;
		}
   }while(ch!=5);
}