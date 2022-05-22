#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>

using namespace std;

class Bus
{
private:
    string b_no, b_name, d_name;
    int b_seats;

public:
    void Menu();
    void new_bus();
    void view_bus();
    void viewSingleBus();
    void viewAllBus();
    void update_bus();
    void del_bus();
    void route_bus();
    void detail_bus();
    void booking();
    void renew_bus();
    void search_booking();
    void update_booking();
    void del_booking();
    void show_booking();
};

void Bus::Menu()
{
menu:
    system("cls");
    int choice;

    cout << "\n\t\t_______BUS RESERVATION SYSTEM_______";
    cout << "\n\n 1. ADD BUS RECORD";
    cout << "\n 2. VIEW BUS DETAILS";
    cout << "\n 3. DELETE BUS DETAILS";
    cout << "\n 4. UPDATE BUS DETAILS";
    cout << "\n 5. ROUTES OF BUSES";
    cout << "\n 6. SEAT DETAILS";
    cout << "\n 7. BOOK SEATS";
    cout << "\n 8. RENEW SEATS";
    cout << "\n 9. SEARCH BOOKING RECORD";
    cout << "\n 10. UPDATE BOOKING RECORD";
    cout << "\n 11. DELETE BOOKING RECORD";
    cout << "\n 12. SHOW ALL BOOKING RECORD";
    cout << "\n 13. EXIT";
    cout << "\n\n ENTER YOUR CHOICE: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        new_bus();
        break;
    case 2:
        view_bus();
        break;
    case 3:
        del_bus();
        break;
    case 4:
        update_bus();
        break;
    case 5:
        route_bus();
        break;
    case 6:
        detail_bus();
        break;
    case 7:
        booking();
        break;
    case 8:
        renew_bus();
        break;
    case 9:
        search_booking();
        break;
    case 10:
        update_booking();
        break;
    case 11:
        del_booking();
        break;
    case 12:
        show_booking();
        break;
    case 13:
        exit(0);
        break;
    default:
        cout << "\n\n***INVALID***";
    }
    getch();
    goto menu;
}

void Bus::new_bus()
{

addRec:
    system("cls");
    string tb_no, tb_name, td_name;
    int tb_seats, found = 0;
    fstream file;

    cout << "\n\t\t_______BUS RESERVATION SYSTEM_______";
    cout << "\n\n BUS NUMBER: ";
    cin >> b_no;
    cout << "\n\n BUS NAME: ";
    cin >> b_name;
    cout << "\n\n TOTAL SEATS: ";
    cin >> b_seats;
    cout << "\n\n DRIVER'S NAME: ";
    cin >> d_name;

    file.open("bus.txt", ios::in);
    if (!file)
    {
        file.open("bus.txt", ios::app | ios::out);
        file << b_no << " " << b_name << " " << b_seats << " " << d_name << "\n";
        file.close();
    }
    else
    {
        file >> tb_no >> tb_name >> tb_seats >> td_name;
        while (!file.eof())
        {
            if (b_no == tb_no)
            {
                found++;
            }
            file >> tb_no >> tb_name >> tb_seats >> td_name;
        }
        file.close();
        if (found == 0)
        {
            file.open("bus.txt", ios::app | ios::out);
            file << b_no << " " << b_name << " " << b_seats << " " << d_name << "\n";
            file.close();
        }
        else
        {
            cout << "\n\nRECORD ALREADY EXISTS";
            getch();
            goto addRec;
        }
    }
    cout << "\n\n NEW BUS RECORD INSERTED SUCCESSFULLY";
}

void Bus::view_bus()
{
    system("cls");
    int choice;
    cout << "\n\t\t_______BUS RESERVATION SYSTEM_______";
    cout << "\n\n 1. VIEW A SINGLE RECORD";
    cout << "\n 2. ALL BUSES";
    cout << "\n 3. GO BACK";
    cout << "\n\n ENTER YOUR CHOICE: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        viewSingleBus();
        break;
    case 2:
        viewAllBus();
        break;
    case 3:
        Menu();
        break;
    default:
        cout << "\n\n***INVALID***";
    }
}

void Bus::viewSingleBus()
{
    system("cls");
    string t_no;
    fstream file;
    int found = 0;

    cout << "\n\t\t_______BUS RESERVATION SYSTEM_______";

    file.open("bus.txt", ios::in);
    if (!file)
    {
        cout << "\n\n FILE NOT FOUND";
    }
    else
    {
        cout << "\n\nENTER BUS NUMBER TO SEARCH: ";
        cin >> t_no;
        file >> b_no >> b_name >> b_seats >> d_name;
        while (!file.eof())
        {
            if (t_no == b_no)
            {   
                system("cls");
                cout << "\n BUS NO.: " << b_no << " | BUS NAME: " << b_name << " | NUMBER OF SEATS: " << b_seats << " | DRIVER'S NAME: " << d_name;
                found++;
            }
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n RECORD NOT FOUND";
        }
    }
}

void Bus::viewAllBus()
{
    system("cls");
    fstream file;

    cout << "\n\t\t_______BUS RESERVATION SYSTEM_______";

    file.open("bus.txt", ios::in);
    if (!file)
    {
        cout << "\n\n FILE NOT FOUND";
    }
    else
    {
        file >> b_no >> b_name >> b_seats >> d_name;
        while (!file.eof())
        {
            cout << "\n BUS NO.: " << b_no << " | BUS NAME: " << b_name << " | NUMBER OF SEATS: " << b_seats << " | DRIVER'S NAME: " << d_name;
            file >> b_no >> b_name >> b_seats >> d_name;
        }
        file.close();
    }
}

void Bus::update_bus(){
    system("cls");
    fstream file,file1;
    string t_no,no,t_name,td_name;
    int t_seats,found=0;
    cout << "\n\t\t_______BUS RESERVATION SYSTEM_______";
    file.open("bus.txt",ios::in);
    if(!file){
        cout<<"FILE NOT FOUND";
    }
    else{
        cout<<"\n\n ENTER BUS NO. TO UPDATE DETAILS: ";
        cin>>t_no;
        file1.open("bus1.txt",ios::app|ios::out);
        file>>b_no>>b_name>>b_seats>>d_name;
        while(!file.eof()){
            if(t_no==b_no){
                cout<<"\n\n NEW BUS NO.:  ";
                cin>>no;
                cout<<"\n\n NEW BUS NAME: ";
                cin>>t_name;
                cout<<"\n\n NEW NO. OF SEATS: ";
                cin>>t_seats;
                cout<<"\n\n NEW DRIVER NAME: ";
                cin>>td_name;
                file1<<no<<" "<<t_name<<" "<<t_seats<<" "<<td_name<<"\n";
                cout<<"\n\n\t\t RECORD UPDATED";
                found++;
            }
            else{
                file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
            }
            file>>b_no>>b_name>>b_seats>>d_name;
        }
        file.close();
        file1.close();
        remove("bus.txt");
        rename("bus1.txt","bus.txt");
        if(found==0){
            cout<<"\n\n RECORD NOT FOUND";
        }
    }
}

void Bus::del_bus(){
    system("cls");
    fstream file,file1;
    string t_no;
    int found=0;
    cout << "\n\t\t_______BUS RESERVATION SYSTEM_______";
    file.open("bus.txt",ios::in);
    if(!file){
        cout<<"FILE NOT FOUND";
    }
    else{
        cout<<"\n\n ENTER BUS NO. TO DELETE DETAILS: ";
        cin>>t_no;
        file1.open("bus1.txt",ios::app|ios::out);
        file>>b_no>>b_name>>b_seats>>d_name;
        while(!file.eof()){
            if(t_no==b_no){
                cout<<"\n\n\t\t RECORD DELETED";
                found++;
            }
            else{
                file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
            }
            file>>b_no>>b_name>>b_seats>>d_name;
        }
        file.close();
        file1.close();
        remove("bus.txt");
        rename("bus1.txt","bus.txt");
        if(found==0){
            cout<<"\n\n RECORD NOT FOUND";
        }
    }
}

void Bus::route_bus(){
    p:
    system("cls");
    int choice;
    cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
    cout<<"\n\n 1. FIRST ROUTE";
    cout<<"\n 2. SECOND ROUTE";
    cout<<"\n 3. THIRD ROUTE";
    cout<<"\n\n ENTER YOUR CHOICE: ";
    cin>>choice;

    switch(choice){
        case 1:
            system("cls");
            cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
            cout<<"\n FROM SHIMLA TO KULLU";
            cout<<"\n 08:00 ..... 16:12 hrs";
            cout<<"\n 09:15 ..... 15:30 hrs";
            cout<<"\n 15:30 ..... 23:20 hrs";
            break;
        case 2:
            system("cls");
            cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
            cout<<"\n FROM PALAMPUR TO CHANDIGARH";
            cout<<"\n 05:00 ..... 13:00 hrs";
            cout<<"\n 06:00 ..... 14:50 hrs";
            cout<<"\n 10:20 ..... 17:00 hrs";
            break;
        case 3:
            system("cls");
            cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
            cout<<"\n FROM MANDI TO DELHI";
            cout<<"\n 08:00 ..... 12:50 hrs";
            cout<<"\n 09:30 ..... 14:30 hrs";
            cout<<"\n 12:50 ..... 16:00 hrs";
            break;
        default:
            cout<<"\n\n ***INVALID***";
        getch();
        goto p;
    }
}

void Bus::detail_bus(){
    system("cls");
    fstream file,file1;
    string t_no,s_b_no,s_no;
    int count=0,found=0;
    cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
    file.open("bus.txt",ios::in);
    file1.open("seats.txt",ios::in);
    if(!file || !file1){
        cout<<"\n\n\tFILE NOT FOUND";
    }
    else{
        cout<<"\n\n BUS NO.: ";
        cin>>t_no;
        file1>>s_b_no>>s_no;
        while(!file1.eof()){
            if(t_no==s_b_no){
                count++;
            }
            file1>>s_b_no>>s_no;
        }
        file1.close();
        file>>b_no>>b_name>>b_seats>>d_name;
        while(!file.eof()){
            if(t_no==b_no){
                system("cls");
                cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
                cout<<"\n\n TOTAL SEATS: "<<b_seats;
                cout<<"\n\n RESERVED SEATS: "<<count;
                cout<<"\n\n EMPTY SEATS: "<<b_seats-count;
                found++;
            }
            file>>b_no>>b_name>>b_seats>>d_name;    
        }
        file.close();
        if(found==0){
            cout<<"\n\n RECORD NOT FOUND";
        }
    }
}

void Bus::booking(){
    p:
    system("cls");
    fstream file;
    string t_no,s_b_no,customer_name,phone,from,to;
    int found=0,s_no,seats,count=0,s_s_no,ss_no[25],i=0,s_amount,total_amount;
    char x;
    cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
    file.open("bus.txt",ios::in);
    if(!file){
        cout<<"FILE NOT FOUND";
    }
    else{
        cout<<"\n\n BUS NO.: ";
        cin>>t_no;
        file.close();
        file.open("seats.txt",ios::in);
        if(file){
            file>>s_b_no>>s_s_no;
            while(!file.eof()){
                if(t_no==s_b_no){
                    count++;
                }
                file>>s_b_no>>s_s_no;
            }
            file.close();
        }
        file.open("bus.txt",ios::in);
        file>>b_no>>b_name>>b_seats>>d_name;  
        while(!file.eof()){
            if(t_no==b_no){
                seats=b_seats;
                found++;
            }
        file>>b_no>>b_name>>b_seats>>d_name; 
        }
        file.close();
        if(seats-count==0){
            cout<<"\n\n ALL SEATS HAVE BEEN BOOKED";
        }
        else if(found==1){
            do{
                h:
                cout<<"\n\n SEAT NO.: ";
                cin>>s_no;
                if(s_no>seats){
                    cout<<"\n\n INVALID SEAT NO.";
                    goto h; 
                }
                file.open("seats.txt",ios::in);
                if(!file){
                    file.open("seats.txt",ios::app|ios::out);
                    file<<t_no<<" "<<s_no<<"\n";
                    file.close();
                }
                else{
                    file>>s_b_no>>s_s_no;
                    while(!file.eof()){
                        if(t_no==s_b_no && s_no==s_s_no){
                            cout<<"\n\n SEAT ALREADY BOOKED";
                            file.close();
                            goto h;
                        }
                        file>>s_b_no>>s_s_no;
                    }
                    file.close();
                    file.open("seats.txt",ios::app|ios::out);
                    file<<t_no<<" "<<s_no<<"\n";
                    file.close();
                }
                ss_no[i]=s_no;
                i++;
                cout<<"\n\n BOOK ANOTHER SEAT (Y/N): ";
                cin>>x;
            }while(x=='Y' || x=='y');
            system("cls");
            cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
            cout<<"\n\n NAME: ";
            cin>>customer_name;
            cout<<"\n\n PHONE NO.: ";
            cin>>phone;
            cout<<"\n\n FROM: ";
            cin>>from;
            cout<<"\n\n TO: ";
            cin>>to;
            cout<<"\n\n SINGLE SEAT AMOUNT: ";
            cin>>s_amount;
            total_amount=s_amount*i;
            file.open("customer.txt",ios::app|ios::in);
            file<<customer_name<<" "<<t_no<<" "<<phone<<" "<<i<<" "<<total_amount<<"\n";        
            file.close();
            system("cls");
            cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
            cout<<"\n\n BOKING INFORMATION";
            cout<<"\n\n\t\t NAME:             "<<customer_name;
            cout<<"\n\t\t FROM:               "<<from;
            cout<<"\n\t\t TO:                 "<<to;
            cout<<"\n\t\t TOTAL SEATS:        "<<i;
            cout<<"\n\t\t RESERVED SEATS:     ";
            for(int a=0;a<i;++a){
                cout<<ss_no[a];
                cout<<" ";
            }
            cout<<"\n\t\t SINGLE SEAT AMOUNT: "<<s_amount;
            cout<<"\n\t\t TOTAL AMOUNT:       "<<total_amount;
            cout<<"\n\n\t\t ***THANK YOU***";
        }
        else{
            cout<<"\n\n RECORD NOT FOUND";
            getch();
            goto p;
        }
    }
}

void Bus::renew_bus(){
    system("cls");
    fstream file;
    char x;
    cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
    file.open("seats.txt",ios::in);
    if(!file){
        cout<<"\n\n FILE NOT FOUND";
    }
    else{
        cout<<"\n\n RENEW ALL SEATS (Y/N): ";
        cin>>x;
        if(x=='Y' || x=='y'){
            file.close();
            remove("seats.txt");
            cout<<"\n\n\t\t ALL SEATS RENEWED";
        }
        else{
            cout<<"\n\n DATA SAVED";
        }
    }
}

void Bus::search_booking(){
    system("cls");
    fstream file;
    string name,no,phone,t_name;
    int t_seats,t_amo,found=0;
    cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
    file.open("customer.txt",ios::in);
    if(!file){
        cout<<"\n\n FILE NOT FOUND";
    }
    else{
        cout<<"\n\nENTER CUSTOMER NAME: ";
        cin>>t_name;
        file>>name>>no>>phone>>t_seats>>t_amo;
        while(!file.eof()){
            
            if(t_name==name){
                if(found==0){
                    system("cls");
                    cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
                }
                cout<<"\n\n\n CUSTOMER NAME: "<<name;
                cout<<"\n\n BUS NO.: "<<no;
                cout<<"\n\n PHONE NO.: "<<phone;
                cout<<"\n\n RESERVED SEATS: "<<t_seats;
                cout<<"\n\n TOTAL AMOUNT: "<<t_amo;
                found++;
            }
            file>>name>>no>>phone>>t_seats>>t_amo;
        }
        file.close();
        if(found==0){
            cout<<"\n\n RECORD NOT FOUND";
        }
    }
}

void Bus::update_booking(){
    system("cls");
    fstream file,file1;
    string name,no,phone,t_phone,del_no;
    int t_seats,t_amo,found=0,del_seats,i=1;
    cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
    file.open("customer.txt",ios::in);
    if(!file){
        cout<<"\n\n FILE NOT FOUND";
    }
    else{
        cout<<"\n\n PHONE NO.: ";
        cin>>t_phone;
        file>>name>>no>>phone>>t_seats>>t_amo;
        while(!file.eof()){
            if(t_phone==phone){
                file.close();
                file.open("customer.txt",ios::in);
                file1.open("customer1.txt",ios::app|ios::out);
                file>>name>>no>>phone>>t_seats>>t_amo;
                while(!file.eof()){
                    if(t_phone==phone){
                        del_no=no;
                        del_seats=t_seats;
                    }
                    if(t_phone!=phone){
                        file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";
                    }
                    file>>name>>no>>phone>>t_seats>>t_amo;
                }
                file.close();
                file1.close();
                remove("customer.txt");
                rename("customer1.txt","customer.txt");
                file.open("seats.txt",ios::in);
                file1.open("seats1.txt",ios::app|ios::out);
                file>>no>>t_seats;
                while(!file.eof()){
                    if(!(del_no==no && i<del_seats)){
                        file1<<no<<" "<<t_seats<<"\n";
                    }
                    file>>no>>t_seats;
                }
                file.close();
                file1.close();
                remove("seats.txt");
                rename("seats1.txt","seats.txt");
                booking();
                found++;
                goto h;
            }
            file>>name>>no>>phone>>t_seats>>t_amo;
        }
        file.close();
        h:
        if(found=0){
            cout<<"\n\n PHONE NUMBER IS INVALID";
        }
    }
}

void Bus::del_booking(){
    system("cls");
    fstream file,file1;
    string name,no,phone,t_phone,del_no;
    int t_seats,t_amo,found=0,del_seats,i=1;
    cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
    file.open("customer.txt",ios::in);
    if(!file){
        cout<<"\n\n FILE NOT FOUND";
    }
    else{
        cout<<"\n\n PHONE NO.: ";
        cin>>t_phone;
        file>>name>>no>>phone>>t_seats>>t_amo;
        while(!file.eof()){
            if(t_phone==phone){
                file.close();
                file.open("customer.txt",ios::in);
                file1.open("customer1.txt",ios::app|ios::out);
                file>>name>>no>>phone>>t_seats>>t_amo;
                while(!file.eof()){
                    if(t_phone==phone){
                        del_no=no;
                        del_seats=t_seats;
                    }
                    if(t_phone!=phone){
                        file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";
                    }
                    file>>name>>no>>phone>>t_seats>>t_amo;
                }
                file.close();
                file1.close();
                remove("customer.txt");
                rename("customer1.txt","customer.txt");
                file.open("seats.txt",ios::in);
                file1.open("seats1.txt",ios::app|ios::out);
                file>>no>>t_seats;
                while(!file.eof()){
                    if(!(del_no==no && i<del_seats)){
                        file1<<no<<" "<<t_seats<<"\n";
                    }
                    file>>no>>t_seats;
                }
                file.close();
                file1.close();
                remove("seats.txt");
                rename("seats1.txt","seats.txt");
                found++;
                goto h;
            }
            file>>name>>no>>phone>>t_seats>>t_amo;
        }
        file.close();
        h:
        if(found=0){
            cout<<"\n\n PHONE NUMBER IS INVALID";
        }
    }
}

void Bus::show_booking(){
    system("cls");
    fstream file;
    string name,no,phone;
    int t_seats,t_amo,found=0;
    cout<<"\n\t\t_______BUS RESERVATION SYSTEM_______";
    file.open("customer.txt",ios::in);
    if(!file){
        cout<<"\n\n FILE NOT FOUND";
    }
    else{
        file>>name>>no>>phone>>t_seats>>t_amo;
        while(!file.eof()){
            
                cout<<"\n\n\n CUSTOMER NAME: "<<name;
                cout<<"\n\n BUS NO.: "<<no;
                cout<<"\n\n PHONE NO.: "<<phone;
                cout<<"\n\n RESERVED SEATS: "<<t_seats;
                cout<<"\n\n TOTAL AMOUNT: "<<t_amo;
                found++;
                file>>name>>no>>phone>>t_seats>>t_amo;
        }
        file.close();
        if(found==0){
            cout<<"\n\n RECORD NOT FOUND";
        }
    }
}

int main()
{

    Bus b;
    char ch;
    string email, pass;

pass:
    system("cls"); // Clears the previous screen
    cout << "\n\n\t\t\t****ENTER YOUR LOGIN DETAILS****";
    cout << "\n\n Email: ";
    cin >> email;
    cout << "\n\n Password: ";

    for (int i = 0; i <= 6; i++)
    {
        ch = getch();
        pass += ch;
        cout << "*";
    }

    if (email == "BusSys@gmail.com" && pass == "pwd1234")
    {
        cout << "\n\n\n\t\t\tLoading";
        for (int i = 1; i <= 5; i++)
        {
            Sleep(500);
            cout << ".";
        }
        b.Menu();
    }

    else
    {
        cout << "\n\n\t\tWrong Details";
        getch();
        goto pass;
    }

    return 0;
}