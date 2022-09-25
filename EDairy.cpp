#include<bits/stdc++.h>
#include<conio.h>
#define size 40
using namespace std;

const string Dudh="Dudh";
const string Ghee="Ghee";

void SearchCustomer();
void addCustomer();
void ListOfCustomer();
void SellProduct();
void title();
void ProductBill();
void ListOfSells();
void MainScreen();
void Exit_program();

/*
ID : Vaibhav123
Pass : 123      
Change it from line 45 and 46
*/
void welcome()
{

	cout<<"\n\n\n\n\n\n\n\t\t\t\t#########################################";
	cout<<"\n\t\t\t\t\t\t WELCOME TO\t\t";
	cout<<"\n\t\t\t\t             MADHAV DAIRY SYSTEM         ";
	cout<<"\n\t\t\t\t#########################################";
	cout<<"\n\n\n\n\n Press any key to continue......\n";
	getch();
	system("cls");

}

void title()
{
    cout<<"\n\n\n\t\t\t\t---------------------------------------------";
    cout<<"\n\t\t\t\t             MADHAV DAIRY SYSTEM         ";
    cout<<"\n\t\t\t\t---------------------------------------------\n\n\n\n";
}

void LockScreen()
{
    char orignalID[20]="Vaibhav123";
    char orignalPass[20]="123";
    char ID[20],Pass[20];
    int e=0;
    do
    {
        system("cls");
        title();
        cout<<"\n\n\t\t\t\tEnter User Id: ";
        cin>>ID;
        cout<<"\n\n\t\t\t\tEnter Passward: ";
        cin>>Pass;
            if(strcmp(ID,orignalID) == 0 && strcmp(Pass,orignalPass) == 0)
            {
                cout<<"\n\n\t\t\t\tLogin succsessful :)\n\n\t\t\t\t<--Press Any key to continue -->";
                getch();
                MainScreen();
                break;
            }
            else
            {
                cout<<"\n\n\t\t\t\tWrong id or passward :( Try again";
                e++;
                getch();
            }
    }while(e<=2);
    if(e>2)
    {
        cout<<"\n\n\t\t\t\tYou have cross the limit. You can't login any more :(";
        getch();
        Exit_program();
    }
    cout<<e;
}

class dairy
{
    public:
    string name;
    string product;
    int price;
    int quantity;
    int total;
    void get_data();
}d1;

void dairy::get_data()
{
    cout<<"\n\t\t\t\tEnter custemor's name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"\n\n\t\t\t\tEnter Product which he/she want: "<<endl;
    cout<<"\n\n\t\t\t\t--Dudh--"<<endl;
    cout<<"\n\n\t\t\t\t--Ghee--"<<endl;
    cout<<"\n\t\t\t\t-->";
    cin>>product;

    if(product==Dudh)
    price=60;
    if(product==Ghee)
    price=100;
    
    cout<<"\n\n\t\t\t\tEnter Quantity of product: ";
    cin>>quantity;
    total=price*quantity;
}

class customer
{
    public:
    string customername;
    char phoneno[10];
    string Address;

    void getCustomerData();
}c1;

void customer::getCustomerData()
{
    cout<<"\n\t\t\t\tEnter Name of customer: ";
    cin.ignore();
    getline(cin,customername);
    int i,valid;
    do{
        A:
        cout<<"\n\n\t\t\t\tEnter phone number of "<<customername<<": ";
        cin>>phoneno;
        if(strlen(phoneno)!=10)
        {
            cout<<"\n\n\t\t\t\tPlease enter 10 digit number\n\n";
            goto A;
        }
        else
        {
            for(i=0;i<strlen(phoneno);i++)
            {
                if(isdigit(phoneno[i])!=0)         //non-zero value if ch is an digit -- zero if ch is not a digit
                {
                    valid=1;
                }
                else
                {
                    valid=0;
                    break;
                }
            }
            if(valid==0)
            {
                cout<<"\n\n\t\t\t\tPhone number contains Invalid charcters -- Please try again\n\n";
                goto A;
            }
        }
    }while(valid==0);

    cout<<"\n\n\t\t\t\tEnter address: ";
    cin.ignore();
    getline(cin,Address);
}

void MainScreen()
{
    int ch;
    system("cls");
    title();
	cout<<"\n\t\t\t\t1. Add Custemor details\n";
	cout<<"\n\t\t\t\t2. List Of Customers\n";
	cout<<"\n\t\t\t\t3. Search Customer Record\n";
	cout<<"\n\t\t\t\t4. Sell Product to Customer\n";
    cout<<"\n\t\t\t\t5. List Of Sells\n";
	cout<<"\n\t\t\t\t6. Exit\n";
    cout<<"Enter Your choise Here: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        addCustomer();
        break;
        case 2:
        ListOfCustomer();
        break;
        case 3:
        SearchCustomer();
        break;
        case 4:
        SellProduct();
        break;
        case 5:
        ListOfSells();
        break;
        case 6:
        Exit_program();
        break;
    }
}

void Exit_program()
{
    system("cls");
    title();
    cout<<"\n\n\t\t\t\tThanks for Visiting :)";
    getch();
}

void ListOfSells()
{
    string arr;
    system("cls");
    title();
    cout<<"\n\n\n";
    ifstream IFile("Custemor.txt");
    while(getline(IFile,arr))
    {
        if(arr!="")
        cout<<arr<<endl;
    }
    IFile.close();
    char ch;
    cout<<"\n\n\t\t\t\tWant to continue [Y/N]: ";
    cin>>ch;
    if(ch=='Y' || ch=='y')
        MainScreen();
    else if(ch=='N' || ch=='n')
        Exit_program();
    else
    {
        cout<<"-----Invalid choice-----";
        getch();
        Exit_program();
    }
}

void SearchCustomer()
{
    system("cls");
    title();
    
    Search:
    char CustomerName[size];
    cout<<"Enter customer customername to search: ";
    cin>>CustomerName;
    ifstream SEARCH("Customer Details.txt");
    int flag=0;
    string arr;
  
    cout<<"\n\n";
    while ( getline (SEARCH,arr) )    
    {
        if (arr.find(CustomerName, 0) != string::npos)  //arr.find(CustomerName, 0) != string::npos
        {
            cout<<arr<<endl;
            flag=1;
        }
    }
    char ch;
    if(flag==0)
    {
        cout<<"\t\t\t\tRecord Not Found :(\n";
        cout<<"\n\t\t\t\tSearch again [Y/N]: ";
        cin>>ch;
        if(ch=='Y'||ch=='y')
            goto Search;
        if(ch=='N' || ch=='n')
            Exit_program();
    }
    SEARCH.close();
    if(flag==1)
    {
        cout<<"\n\n\t\t\t\tWant to continue [Y/N]: ";
        cin>>ch;
        if(ch=='Y' || ch=='y')
            MainScreen();
        else if(ch=='N' || ch=='n')
            Exit_program();
        else
        {
            cout<<"-----Invalid choice-----";
            getch();
            Exit_program();
        }
    }
}

void SellProduct()
{
    system("cls");
    title();
    d1.get_data();

    ofstream OFile("Custemor.txt",ios::app);

    OFile<<d1.name<<"\t\t\t"<<d1.product<<"\t\t\t"<<d1.price<<"\t\t\t"<<d1.quantity<<"L"<<"\t\t\t"<<d1.total<<"\n";
    OFile.close();

    cout<<"\n\n\t\t\t\tBill Created Succsessfully.";

    char ch;
    cout<<"\n\n\t\t\t\tWant to continue [Y/N]: ";
    cin>>ch;
    if(ch=='Y' || ch=='y')
        MainScreen();
    else if(ch=='N' || ch=='n')
        Exit_program();
    else
    {
        cout<<"-----Invalid choice-----";
        getch();
        Exit_program();
    }
    OFile.open("Bill.csv");

    OFile<<"\n"",,""Madhav"",""Dairy"<<endl<<"Name:"<<","<<d1.name<<",,,"<<"Date:    "",""=TODAY()"<<endl<<",""Description"<<",,""Quantity"","<<"Price"","<<"Total"<<endl<<","<<d1.product<<",,"<<d1.quantity<<","<<d1.price<<","<<d1.total;

    // OFile<<endl<<d1.name<<"\t\t\t"<<d1.product<<"\t\t\t"<<d1.price<<"\t\t\t"<<d1.quantity<<"L"<<"\t\t\t"<<d1.total;
    OFile.close();
}

void ListOfCustomer()
{
    system("cls");
    title();

    cout<<"\n\n\n";
    string arr;
    ifstream IFile("Customer Details.txt");
    while(getline(IFile,arr))
    {
        if(strlen((char *) &arr)>0)
            cout<<arr<<endl;
    }
    IFile.close();
    char ch;
    cout<<"\n\n\t\t\t\tWant to continue [Y/N]: ";
    cin>>ch;
    if(ch=='Y' || ch=='y')
        MainScreen();
    else if(ch=='N' || ch=='n')
        Exit_program();
    else
    {
        cout<<"-----Invalid choice-----";
        getch();
        Exit_program();
    }
}
void addCustomer()
{
    system("cls");
    title();
    char ans;

    Add:
    c1.getCustomerData();
    ofstream Customerfile("Customer Details.txt",ios::app);
    Customerfile<<endl<<setw(10)<<"Name: "<<left<<setw(20)<<c1.customername<<setw(10)<<"Phone No. +91-"<<left<<setw(20)<<c1.phoneno<<setw(8)<<"Address: "<<left<<c1.Address;
    cout<<"\n\n\t\t\t\tNew Customer added succsessfully.\n\n";
    cout<<"\t\t\t\tYou want to add more customers? [Y/N]: ";
    cin>>ans;
    if(ans=='Y'||ans=='y')
    goto Add;
    else if(ans=='N'||ans=='n')
    {
        cout<<"\n\n\t\t\t\tOkay Thank You :)";
        Customerfile.close();
        getch();
        MainScreen();
    }
    else
    {
        cout<<"-----Invalid choice-----";
        getch();
        Exit_program();
    }
}

int main()
{
    welcome();
    LockScreen();
    return 0;
}