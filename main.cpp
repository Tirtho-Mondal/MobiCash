//Tirtho Mondal
//CSE,KUET
//2007117

#include<bits/stdc++.h>
using namespace std;

int main();
class MobiCash      // Using Abstract Class
{
public:
    void virtual In()=0;
};

class Balance: public MobiCash
{
    double balance;
public:
    Balance()                           //Using Default Constructor
    {

    }
    Balance(double x)                  ////Using parameterized Constructor
    {
        balance =x ;
    }
    void putBal(double x);

    void Showbalance(string user)
    {
        ifstream ba;
        ba.open("Balance"+user+".txt");
        //double balanc;
        ba>>balance;
        cout<<"Current balance is: "<< balance <<endl;
    }
    void In()
    {
        cout<<"In int Balance Class"<<endl;
    }
};
void Balance::putBal(double x)
{
    Balance obj(x);
    ofstream fp1;
    fp1.open("Balance.txt");
    fp1<<balance;
    fp1.close();
}
class CashIn:public MobiCash
{
    double in;

public:
    CashIn() {}
    CashIn(double x)
    {
        in=x;
    }
    void Diposit(double x,string user,string number)
    {
        CashIn obj(x);
        ifstream fp;
        fp.open("Balance"+user+".txt");
        // in=x;
        fp>>in;
        fp.close();
        ofstream fp1,tra;
        fp1.open("Balance"+user+".txt");
        tra.open("Tran"+user+".txt",ios::app);
        tra<<"Cash In from "<<number<<" TK "<<x<<"  & Balance is : TK "<<in+x<<endl;
        fp1<<(in+x)<<endl;
        fp1.close();

    }
    void In()
    {
        ;
    }
};
class MobileRecharge: public MobiCash
{
    double recharge;

public:
    void mobile_recharge(double x, string monum,string user)
    {
        recharge=x;
        ifstream fp;
        fp.open("Balance"+user+".txt");

        fp>>recharge;
        fp.close();

        ofstream fp1,tra;
        fp1.open("Balance"+user+".txt");
        tra.open("Tran"+user+".txt",ios::app);
        tra<<"Mobile Recharge to "<<monum<<" TK "<<x<<" & Balance is : TK "<<recharge-x<<endl;
        fp1<<(recharge-x)<<endl;
        fp1.close();

    }
    void In()
    {
        ;
    }
};
class SendMoney: public Balance
{
    double out;
public:
    void SendMon(double z, string number,string user)
    {
        ifstream fp;
        fp.open("Balance"+user+".txt");
        double mon;
        fp>>mon;
        fp.close();
        ofstream fp1,tra;
        fp1.open("Balance"+user+".txt");
        tra.open("Tran"+user+".txt",ios::app);
        tra<<"Send money to "<<number<<" TK "<<z<<" & Balance is : TK "<<mon-z<<endl;
        fp1<<(mon-z)<<endl;
        fp1.close();
    }
};

class MobiCashAgent
{
    string agent;
public:
    void regestrationagent(string s)
    {
        agent=s;
        getagent();
    }
    void getagent()
    {
        ofstream fp1;
        fp1.open("Agent.txt",ios::app);
        fp1<<agent<<endl;
        fp1.close();
    }

};
class CashOut: public Balance
{
    double out;
public:
    void cash_out(double z, string num,string user)
    {
        ifstream fp;
        fp.open("Balance"+user+".txt");
        // double mon;

        fp>>out;
        fp.close();
        //int z;
        ofstream fp1,tra;
        fp1.open("Balance"+user+".txt");
        tra.open("Tran"+user+".txt",ios::app);
        tra<<"Cash Out to "<<num<<" TK "<<z<<" & Balance is : TK "<<out-z<<endl;
        fp1<<(out-z)<<endl;
        fp1.close();

        cout<<"\t\tSuccessfully CashOut Done "<<endl;
    }
};


bool isloggedin(string usname, string password)
{
    string usernum,pass,usna;

    ifstream read("data" + usname +".txt");
    read>>usernum>>usna>>pass;
    if(usernum == usname and pass==password)
    {
        return true;
    }
    else return false;

}

void InterfaceMobicash()
{
    cout<<"\t\t\t\t|**************|\t\t\t\t\t\n";
    cout<<"\t\t\t\t||  MobiCash  ||\t\t\t\t\n";

    cout<<"\t\t\t\t|**************|\t\t\t\t\t\n";
    cout<<"\n\t\t\tWelcome to Mobile Banking System\n\n";

}
void AdmnInterface()
{
    cout<<"\t\t1 : Users "<<endl;
    cout<<"\t\t2 : Agents "<<endl;
    cout<<"\t\t3 : Log out  "<<endl;
}

class LoginInterface
{
public:
    friend ostream& operator<<(ostream &cout, LoginInterface &obj);         // Using operator overloading
};
ostream& operator<<(ostream &cout, LoginInterface &obj)
{
    cout<<"\t\t1 : Send Money\n";
    cout<<"\t\t2 : Cash In\n";
    cout<<"\t\t3 : Cash Out\n";
    cout<<"\t\t4 : Mobile Recharge\n";
    cout<<"\t\t5 : Check Balance\n";
    cout<<"\t\t6 : Transaction Details\n";
    cout<<"\t\t7 : Log Out\n";

}


void Admin()
{
    AdmnInterface();
    cout<<"Enter your option : ";
    int n;
    cin>>n;
    switch(n)
    {
    case 1:
    {
        cout<<"MobiCash Users are: \n";
        ifstream t;
        t.open("User.txt");
        vector<string>v;
        string s;
        while(getline(t,s))
        {
            v.push_back(s);
        }
        if(v.size()==0)
        {
            cout<<"\t\tNo Users are present.\n";
        }
        for(auto &i: v)
        {
            cout<<i<<endl;
        }
        cout<<endl;
        Admin();
        break;
    }
    case 2:
    {

        cout<<"\t\tMobiCash Agents are: \n";
        ifstream t;
        t.open("Agent.txt");
        vector<string>v;
        string s;
        while(getline(t,s))
        {
            v.push_back(s);
        }
        if(v.size()==0)
        {
            cout<<"\t\tNo Agents are present.\n";
        }
        for(auto &i: v)
        {
            cout<<i<<endl;
        }
        cout<<endl;
        Admin();
        break;
    }

    case 3:
    {
        cout << "\t\tSuccesfully logged Out!" <<endl;
        cout<<endl<<endl;
        main();

    }
    default:
    {
        cout<<"\t\tWrong pressed!!"<<endl;
        Admin();

    }
    }

}

template <typename T>                                               //Using Template function
bool searchString(const std::vector<T>& vec, const T& searchStr)
{
    auto it = std::find(vec.begin(), vec.end(), searchStr);
    return (it != vec.end());
}

void ForgotPssward()
{

    string forgetuser;
    cout<<"\n\t\tEnter the User's Mobile Number : ";
    cin>>forgetuser;

    ifstream t;
    t.open("UserMobile.txt");
    vector<string>v;
    string s;
    while(getline(t,s))
    {
        v.push_back(s);
    }
    if(searchString(v,forgetuser))
    {
        string userumber,usname,upass, mobile;
        ifstream fp;
        fp.open("data" +forgetuser+ ".txt");
        fp >>userumber>> usname >>upass;
        cout<<"\t\tEnter User's Name : ";
        cin>>mobile;
        if(usname==mobile)
        {
            cout<<"\t\tPassward is :"<<upass<<endl;
        }
        else
        {
            cout<<"\t\tSorry you are not the account owner !!"<<endl;

            main();
        }
    }
    else
    {
        cout<<"\t\tInvalid User Id !!!"<<endl;
    }
    main();

}
class BeforeLogin
{
public:
    friend ostream& operator<<(ostream & cout, BeforeLogin &obj);
};
ostream& operator<<(ostream &cout, BeforeLogin &obj)
{
    cout<<"\t\t1 : Register User\n";
    cout<<"\t\t2 : Register Agent\n";
    cout<<"\t\t3 : Login\n";
    cout<<"\t\t4 : Forgot password\n";
    cout<<"\t\t5 : Admin of MobiCash\n";
    cout<<"\t\t6 : Exit\n";

}



void loginDone( string user )
{
    string usernum,us,pass;
    ifstream read("data" + user +".txt");
    read>>usernum>>us>>pass;


    cout<<"\n\t\tWelcome "<<us<<endl;
    cout<<"\t\t======================="<<endl;

    LoginInterface obj;
    cout<<obj;
    Balance a;
    CashIn iin;
    SendMoney out;
    MobileRecharge mob;
    MobiCashAgent m;
    CashOut outcash;

    int k;
    cout<<"Enter your option : ";
    cin>>k;
    switch(k)
    {
    case 1:
    {
        cout<<"\t\tEnter Which number: ";
        string nums;
        cin>>nums;
        cout<<"\t\tEnter the amount : ";
        double taka;
        cin>>taka;
        out.SendMon(taka, nums,user);
        cout<<"\t\tSuccessfully Money send to "<<nums<<endl;
        cout<<endl<<endl;
        loginDone(user);
        break;
    }
    case 2:
    {
        ifstream t;
        t.open("Agent.txt");
        vector<string>v;
        string s,number;
        while(getline(t,s))
        {
            v.push_back(s);
        }
        //for(auto &i: v){cout<<i<<endl;}
        cout<<"\t\tEnter agent Number: ";
        cin>>number;
        if(searchString(v,number))
        {
            cout<<"\t\tEnter the amount : ";
            double cain;
            cin>>cain;
            iin.Diposit(cain,user,number);
            cout<<"\t\tSuccessfully CashIn done."<<endl;
        }
        else
        {
            cout<<"\t\tInvalid agent !!!"<<endl;
        }
        cout<<endl<<endl;
        loginDone(user);
        break;
    }
    case 3:
    {

        ifstream t;
        t.open("Agent.txt");
        vector<string>v;
        string s,number;
        while(getline(t,s))
        {
            v.push_back(s);
        }
        //for(auto &i: v){cout<<i<<endl;}
        cout<<"\t\tEnter agent Number: ";
        cin>>number;
        if(searchString(v,number))
        {
            double outtk;
            cout<<"\t\tHow much TK do you want to out: ";
            cin>>outtk;
            outcash.cash_out(outtk,number,user);
        }
        else
        {
            cout<<"\t\tInvalid agent !!!"<<endl;
        }
        cout<<endl<<endl;
        loginDone(user);
        break;
    }
    case 4:
    {
        cout<<"\t\tEnter Mobile number: ";
        string nums;
        cin>>nums;
        cout<<"\t\tEnter the amount : ";
        double taka;
        cin>>taka;
        mob.mobile_recharge(taka, nums, user);
        cout<<"\t\tSuccessfully Mobile recharge done to "<<nums<<endl;
        cout<<endl<<endl;
        loginDone(user);
        break;
    }
    case 5:
    {
        a.Showbalance(user);
        cout<<endl<<endl;
        loginDone(user);
        break;
    }

    case 6:
    {

        ifstream t;
        t.open("Tran"+user+".txt");
        vector<string>v;
        string s;
        while(getline(t,s))
        {
            v.push_back(s);
        }
        reverse(v.begin(),v.end());
        for(auto &i: v)
        {
            cout<<i<<endl;
        }
        cout<<endl<<endl;
        loginDone(user);
        break;
    }

    case 7:
    {
        cout << "\t\tSuccesfully logged Out!" <<endl;
        cout<<endl<<endl;
        main();
        break;
    }
    default:
    {
        cout<<"\t\tWrong pressed!!"<<endl;
        cout<<endl<<endl;
        loginDone(user);
    }

    }

}

int main()
{
    InterfaceMobicash();
    Balance a;
    CashIn iin;
    SendMoney out;
    MobileRecharge mob;
    MobiCashAgent m;
    CashOut outcash;
    string user;

    int choice;
    //BeforeLogin();
    BeforeLogin login;
    cout<<login;
    cout<<"Enter your option : ";
    cin >> choice;
    if(choice ==1)
    {
        cout<<"\n\t\t Welcome to the User Registration Form\n"<<endl;
        string mobilenum, usname,password;
        cout << "\t\tEnter Your Mobile Number : ";
        cin>>mobilenum;

        ifstream mob;
        mob.open("UserMobile.txt");
        vector<string>vmob;
        string s,us;
        while(mob>>s)
        {
            mob>>us;
            vmob.push_back(s);
        }

        ifstream t;
        t.open("User.txt");
        vector<string>v;
        // string s;
        while(getline(t,s))
        {
            v.push_back(s);
        }
        if(searchString(vmob,mobilenum)==0)
        {
            cout << "\t\tEnter an User Name: ";
            cin >> usname;


            if(searchString(v,usname)==0)
            {
                cout << "\t\tEnter your password: ";
                cin >> password;

                ofstream file, onlyuser, onlyuserNumber;
                file.open("data" + mobilenum + ".txt");
                onlyuser.open("User.txt", ios::app);
                onlyuserNumber.open("UserMobile.txt", ios::app);

                file <<mobilenum<<'\n'<< usname << '\n' << password;
                onlyuser<<usname<<endl;
                onlyuserNumber<<mobilenum<<'\n'<<usname<<endl;

                file.close();

                ofstream fp;
                fp.open("Balance"+mobilenum+".txt");
                fp<<0;
                fp.close();
                cout<<"\t\tRegistration is Complete.\n\t\tWelcome to our MobiCash Famaily\n\n";
            }
            else
            {
                cout<<"\t\tUser name exists !!!\n"<<endl;
                main();
            }
        }
        else
        {
            cout<<"\t\tThis Mobile Number is already registered  !!!\n"<<endl;

        }
        main();


    }
    else if(choice ==2)
    {

        cout<<"\n\t\t Welcome to the Agent Registration Form\n"<<endl;
        cout<<"\t\tEnter Number: ";
        string s;
        cin>>s;

        ifstream t;
        t.open("Agent.txt");
        vector<string>v;
        string s11;
        while(getline(t,s11))
        {
            v.push_back(s11);
        }
        if(searchString(v,s)==0)
        {
            m.regestrationagent(s);
            cout<<"\t\tRegistration is Complete.\n\t\tWelcome to our MobiCash Famaily\n\n";

        }
        else
        {
            cout<<"\t\tThis number is already registered !!!"<<endl;
        }

        main();
    }
    else if(choice==3)
    {
        string usname,password, mobileNum;
//        cout << "Enter username: ";
//        cin >> usname;

        cout<<"\n\t\tEnter Mobile Number : ";
        cin>>mobileNum;

        //user=mobileNum;
        ifstream t;
        t.open("UserMobile.txt");
        vector<string>v;
        string s,k;
        while(t>>s)
        {
            t>>k;
            v.push_back(s);
        }
        //for(auto &i: v){cout<<i<<"-->";}
        if(searchString(v,mobileNum)==0)
        {
            cout<<"\t\tInvalid User!!!"<<endl;
            main();
        }
        else
        {

            string usernum,pass;

            cout << "\t\tEnter password: ";
            cin >> password;
            ifstream read("data" + mobileNum +".txt");
            read>>usernum>>user>>pass;

            bool status=isloggedin(mobileNum,password);
            if(!status)
            {
                cout << "\t\tWrong Passward!" <<  '\n';
                system("PAUSE");
                main();
            }
            else
            {
                cout << "\n\t\tSuccesfully logged in!" <<endl;
                loginDone(mobileNum);
                system("PAUSE");
                return 1;
            }
        }
    }
    else if(choice==4)
    {
        ForgotPssward();
    }
    else if(choice==5)
    {
        cout<<"\t\tEnter the Admin Security Key: ";
        int key;
        cin>>key;
        if(key==2007117)
        {
            Admin();
        }
        else
        {
            cout<<"\t\tYou are not Admin!!"<<endl;
            main();
        }
    }
    else if(choice==6)
    {
        return 0;
    }
    else
    {
        cout<<"\t\tWrong pressed!!"<<endl;
        cout<<endl<<endl;
        main();
    }
}
