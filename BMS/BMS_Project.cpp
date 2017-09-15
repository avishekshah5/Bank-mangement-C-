                    /* ************************* */
                    /* BANKING MANAGEMENT STSTEM */
                    /* ************************* */
#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cstring>
using namespace std;
const char* datafile="cat.dat";


class account
{
private:
    static int ac_no;
    char name[30];
    char address[30];
    char contact_no[10];
    long amount;
    char account_type[20];
    int account_no;
public:
    void read_data();
    void show_data();
    void write_rec();
    void read_all_rec();
    void read_one_rec();
    void edit_ac();
        void delete_rec();
        void edit_rec();
    void withdraw_amount();
        void withdraw();
    void deposit_amount();
        void deposit();
    void daily_transaction();
};
int account::ac_no = 0;

void account::read_data()
{

    cout<<"\n\tName : ";
    cin>>name;
    cout<<"\n\tAddress : ";
    cin>>address;
    cout<<"\n\tContact no : ";
    cin>>contact_no;
    cout<<"\n\tAcount Type : ";
    cin>>account_type;
    cout<<"\n\tInitial Deposit : ";
    cin>>amount;
    ac_no++;
    account_no = ac_no;

}

void account::show_data()
{

    cout<<"\t";
    cout.width(3);
    cout<<account_no;
    cout.width(15);
    cout<<name;
    cout.width(15);
    cout<<address;
    cout.width(10);
    cout<<"   "<<account_type;
    cout.width(13);
    cout<<""<<amount<<"\n";
}
void account::write_rec()
{
    ofstream outfile(datafile,ios::binary|ios::app);
    read_data();
    outfile.write(reinterpret_cast<char *>(this),sizeof(*this));
}
void account::read_all_rec()
{
    ifstream infile(datafile,ios::binary);
    if(!infile)
    {
        cout<<"File not Found : Store Record First"<<endl;
        return;
    }
    while(!infile.eof())
    {
        if(infile.read(reinterpret_cast<char *>(this),sizeof(*this))>0)
            show_data();

    }
}
void account::read_one_rec()
{
    int n;
    ifstream infile(datafile,ios::binary);
    if(!infile)
    {
        cout<<"File not found: store record first"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\nThere Are "<<count<<" record in this file";
    cout<<"Enter Record Number: ";
    cin>>n;
    infile.seekg((n-1)*sizeof(*this));
    infile.read(reinterpret_cast<char *>(this),sizeof(*this));
                cout<<"========================================================================================\n";
                cout<<"\t\t\t\t\tData Of User\n";
                cout<<"========================================================================================\n";
                cout<<"\tAC No. \t    Name \t  Address \t Account Type \t    Amount\n";
                cout<<"\t------ \t    ---- \t  ------- \t ------------ \t    ------\n\n";
    show_data();
}
void account::edit_ac()
{
    int choice;

    cin>>choice;
    switch(choice)
    {
        case 1:
            edit_rec();
            break;
        case 2:
            delete_rec();
            break;
        case 3:
            return ;
            break;

        default:
            cout<<"\n\nInvalid Choice.";
            cout<<"\n\n";
            return ;

    }
}


void account::daily_transaction()
{
    int choice;
    cout<<"\n\nWhat Do You Want";
    cout<<"\n================";
    cout<<"\n\t1 --> Deposit";
    cout<<"\n\t2 --> Withdraw";
    cout<<"\n\t3 --> Back";
    cout<<"\n\n\tEnter Your Choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        deposit_amount();
        break;
    case 2:
        withdraw_amount();
        break;
    case 3:
        return ;
        break;
    default:
        cout<<"Invalid Choice.";
    }
}
void account::withdraw()
{
    long n;
    cin>>n;
    if(amount<n)
    {
        cout<<"You Have Insufficient Balance\n\n";
    }
    else
    {amount = amount-n;
    }
}
void account::deposit()
{
    long n;
    cin>>n;
    amount = amount + n;
}

void account::withdraw_amount()
{
    int n;
    fstream iofile(datafile,ios::in|ios::binary);
    if(!iofile)
    {

        cout<<"File not found: Store Record First"<<endl;
        return;
    }
    iofile.seekg(0,ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"There are "<<count<<" record in the file\n";
    cout<<"\n";
    cout<<"Enter Record Number : ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char *>(this),sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
                cout<<"========================================================================================\n";
                cout<<"\t\t\t\t\tData Of User\n";
                cout<<"========================================================================================\n";
                cout<<"\tAC No. \t    Name \t  Address \t Account Type \t    Amount\n";
                cout<<"\t------ \t    ---- \t  ------- \t ------------ \t    ------\n\n";
            show_data();
        cout<<"\n====================================================================================\n\n";
    cout<<"\n";
    iofile.close();
    iofile.open(datafile,ios::out|ios::in|ios::binary);
    iofile.seekg((n-1)*sizeof(*this));
    cout<<"Withdraw Amount : ";
    withdraw();

    iofile.write(reinterpret_cast<char *>(this),sizeof(*this));
}

void account::deposit_amount()
{
    int n;
    fstream iofile(datafile,ios::in|ios::binary);
    if(!iofile)
    {

        cout<<"File not found: Store Record First"<<endl;
        return;
    }
    iofile.seekg(0,ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"There are "<<count<<" record in the file";
    cout<<"\n";
    cout<<"Enter Record Number : ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char *>(this),sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
                cout<<"========================================================================================\n";
                cout<<"\t\t\t\t\tData Of User\n";
                cout<<"========================================================================================\n";
                cout<<"\tAC No. \t    Name \t  Address \t Account Type \t    Amount\n";
                cout<<"\t------ \t    ---- \t  ------- \t ------------ \t    ------\n\n";
            show_data();
        cout<<"\n====================================================================================\n\n";
    cout<<"\n";
    iofile.close();
    iofile.open(datafile,ios::out|ios::in|ios::binary);
    iofile.seekg((n-1)*sizeof(*this));

    cout<<"Deposit Amount : ";
    deposit();

    iofile.write(reinterpret_cast<char *>(this),sizeof(*this));
}

void account::edit_rec()
{
    int n;
    fstream iofile(datafile,ios::in|ios::binary);
    if(!iofile)
    {

        cout<<"File not found: Store Record First"<<endl;
        return;
    }
    iofile.seekg(0,ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"There are "<<count<<" record in the file";
    cout<<"\nEnter Record Number to be Edited: ";
    cin>>n;
    iofile.seekg((n-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char *>(this),sizeof(*this));
    cout<<"Record "<<n<<" has following data"<<endl;
                cout<<"========================================================================================\n";
                cout<<"\t\t\t\t\tData Of User\n";
                cout<<"========================================================================================\n";
                cout<<"\tAC No. \t    Name \t  Address \t Account Type \t    Amount\n";
                cout<<"\t------ \t    ---- \t  ------- \t ------------ \t    ------\n\n";
            show_data();
        cout<<"\n====================================================================================\n\n";
    cout<<"\n";

    iofile.close();
    iofile.open(datafile,ios::out|ios::in|ios::binary);
    iofile.seekg((n-1)*sizeof(*this));
    cout<<"Enter Data To Modify : \n";
    cout<<"======================\n";
    read_data();
    iofile.write(reinterpret_cast<char *>(this),sizeof(*this));
}
void account::delete_rec()
{
    int n;
    char tempfile[]="temp.dat";
    ifstream infile(datafile,ios::binary);
    if(!infile)
    {
        cout<<"File not found: Store Record First";
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"There are "<<count<<" record in this file";
    cout<<"\nEnter record number to be deleted: ";
    cin>>n;

    fstream tmpfile(tempfile,ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0;i<count;i++)
    {
        infile.read(reinterpret_cast<char *>(this),sizeof(*this));
        if(i==(n-1))
            continue;
        tmpfile.write(reinterpret_cast<char *>(this),sizeof(this));
    }
    infile.close();
    ofstream outfile(datafile,ios::binary);
    tmpfile.close();
    tmpfile.open(tempfile,ios::in|ios::binary);
    for(int i=0;i<count-1;++i)
    {
        tmpfile.read(reinterpret_cast<char *>(this),sizeof(*this));
        outfile.write(reinterpret_cast<char *>(this),sizeof(*this));
    }
    tmpfile.close();
    remove(tempfile);
}


int main()
{
    account ac;
    int choice,choice1,choice2;
    char a_name[] = "avishek";
    char a_pass[5] = {12345};
    char s_name1[] = "dinesh";
    char s_pass1[5] = {54321};


//    clrscr();
    cout<<"\n";
    cout<<"\t ***  ***  ***   *********   ***              ******     ******     *****     *****  ********* \n";
    cout<<"\t ***  * *  ***   *********   ***             *******    ***  ***    *****     * ***  ********* \n";
    cout<<"\t *** ***** ***   *****       ***      ****  ***        ***    ***   *** **   ** ***  ***** \n";
    cout<<"\t ****** ******   *****       ***      ****  ***        ***    ***   ***  *****  ***  ***** \n";
    cout<<"\t *****   *****   *********   *******         *******    ***  ***    ***   ***   ***  *********\n" ;
    cout<<"\t ****     ****   *********   *******          ******     ******     ***         ***  ********* \n";
    cout<<"\n\n\n";
while(true)
 {
    cout<<"SELECT WHO YOU ARE ?: \n";
    cout<<"===================== \n\n";
    cout<<"\t 1...>ADMIN\t\t 2...>STAFF";
    cout<<"\n\npress any key for Exit.";
    cout<<"\n\nSelect one option...: ";
    cin>>choice1;
    if(choice1 == 1)
    {
        char name[20];
        char pass1[5];

        cout<<"=====================================\n";
        cout<<"\tPLEASE LOGIN FIRST...\n";
        cout<<"=====================================\n\n";
        cout<<"Name :\t";
        cin>>name;
        cout<<"\npassword: \t";
        int i;
        for(i=0; i<5; i++)
        {
           pass1[i] = getch();
           cout<<"*";
        }
        cout<<"\n";
        if(strcmp(name,a_name)!=0 && strcmp(pass1,a_pass)!=0)
        {
            cout<<"Invalid Name and Password...";

        }
        else
        {   while(true)
            {cout<<"==========================================\n";
            cout<<"\t\tWhat Do You Want To Do...\n";
            cout<<"==========================================\n\n";
            //cout<<"\t1...> Add staff\n";

            cout<<"\t1...> Add Account\n";
            cout<<"\t2...> Delete Account\n";
            cout<<"\t3...> Edit Account \n";
            cout<<"\n\t4...> Exit\n";
            cout<<"==========================================\n\n";
            cout<<"Enter your Choice : ";
            cin>>choice;
            switch(choice)
            {

            case 1:
                cout<<"==================================================================\n";
                cout<<"\t\t\tEnter Data Of User\n";
                cout<<"==================================================================\n";
                ac.write_rec();
                cout<<"==================================================================\n";
                break;
           case 2:
                ac.delete_rec();
                break;
            case 3:
                ac.edit_rec();
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"PLEASE ENTER VALID CHOICE...";

            }
            }
            }
    }
    else if(choice1 == 2)
     {
        char staff_name[20];
        char staff_password[5];
        int n,i;
        cout<<"=====================================\n";
        cout<<"\tPLEASE LOGIN FIRST...\n";
        cout<<"=====================================\n\n";
        cout<<" Name: \t";
        cin>>staff_name;
        cout<<"\n password : \t";
        for(i=0; i<5; i++)
        {
                staff_password[i] = getch();
                cout<<"*";
        }
        if(strcmp(staff_name,s_name1)!=0 && strcmp(staff_password,s_pass1)!=0)
             {cout<<"Invalid User name and password\n";
             }
        else
        {while(true)
          {
            cout<<"\n================================================\n";
            cout<<"\tWhat Do You Want To Do...\n";
            cout<<"================================================\n\n";
            cout<<"\t1...> Transaction\n";

            cout<<"\t2...> Show All Records \n";
            cout<<"\t3...> Show One Record \n";
            cout<<"\n\t4...> Exit\n";
            cout<<"================================================\n\n";
            cout<<"Enter Your Choice : ";
            cin>>choice2;
            switch(choice2)
            {
            case 1:
                ac.daily_transaction();
                break;
            case 2:
                cout<<"========================================================================================\n";
                cout<<"\t\t\t\t\tData Of User\n";
                cout<<"========================================================================================\n";
                cout<<"\tAC No. \t    Name \t  Address \t Account Type \t    Amount\n";
                cout<<"\t------ \t    ---- \t  ------- \t ------------ \t    ------\n\n";
                ac.read_all_rec();
                break;
            case 3:
                cout<<"========================================================================================\n";
                cout<<"\t\t\t\t\tData Of User\n";
                cout<<"========================================================================================\n";
                cout<<"\tAC No. \t    Name \t  Address \t Account Type \t    Amount\n";
                cout<<"\t------ \t    ---- \t  ------- \t ------------ \t    ------\n\n";
                ac.read_one_rec();
                break;
            case 4:
                return 0;
                break;
            default:
            cout<<"Please Enter Valid Choice : ";

            }
          }
        }
    }
    else
    {
        return 0;
    }

 }

getch();
return 0;
}
/*
    while(true)
    {
        cout<<"\nSELECT ONE OPTION BELOW :";
        cout<<"\n=========================\n";
        cout<<"\n\t2 --> Show List Of Account";
        cout<<"\n\t3 --> Individual Account";
        cout<<"\n\t4 --> Daily Transaction";

        cout<<"\n\t5 --> Edit Account";
        cout<<"\n\t6 --> Exit";
        cout<<"\n\n\nEnter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:

        case 2:
                cout<<"========================================================================================\n";
                cout<<"\t\t\t\t\tData Of User\n";
                cout<<"========================================================================================\n";
                cout<<"\tAC No. \t    Name \t  Address \t Account Type \t    Amount\n";
                cout<<"\t------ \t    ---- \t  ------- \t ------------ \t    ------\n\n";
            ac.read_all_rec();
                cout<<"\n========================================================================================\n\n";

            break;
        case 3:

            ac.read_one_rec();
            break;
       case 4:
            ac.daily_transaction();
            break;

        case 5:
                cout<<"\n What Do You Want To Do: ";
                cout<<"\n =======================";
                cout<<"\n\t1 --> Edit Record";
                cout<<"\n\t2 --> Delete Record"<<endl;
                cout<<"\n\n\t3 --> Back";
                cout<<"\n\n\nEnter Your Choice : ";
            ac.edit_ac();
            break;
        case 6:
            return 0;
            break;
        default:
            cout<<"Match Not Fount";


        }
    }
}
*/
