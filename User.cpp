#include<bits/stdc++.h>
#include "User.h"

RegisteredUser::RegisteredUser(string id)
{
    this->id = id;
}
void RegisteredUser :: input()
{
    Person::input();
    cout<<"Ten tai khoan: "; getline(cin,this->Account_username);
    cout<<"Rank: "; getline(cin,this->rank);
    cout<<"Gmail: "; getline(cin,this->gmail);
}
void RegisteredUser :: input(fstream &inf)
{   Person::input(inf);
    getline(inf,this->Account_username);
    getline(inf,this->rank);
    getline(inf,this->gmail);
}
void RegisteredUser :: GeneralView()
{
    Person::GeneralView();
    cout<<setw(15)<<this->Account_username<<" |";
    cout<<setw(10)<<this->rank<<" |";
}
void RegisteredUser::TypeView()
{
    Person::TypeView();
    cout<<"\nAccount: "<<setw(15)<<this->Account_username
        <<"\nRank: "<<setw(15)<<this->rank
        <<"\nGmail: "<<setw(15)<<this->gmail;
}
void RegisteredUser :: exportList(fstream &inf, string file)
{
    Person::exportList(inf,file);
    inf<<this->Account_username<<endl;
    inf<<this->rank<<endl;
    inf<<this->gmail<<endl;
}
string RegisteredUser ::get_Username()
{
    return this->Account_username;
}
string RegisteredUser ::get_rank()
{
    return this->rank;
}
string RegisteredUser::get_gmail()
{
    return this->gmail;
}

GuestUser::GuestUser()
{
    
}
GuestUser::GuestUser(string id)
{
    this->id = id;
}
void GuestUser::input()
{
    Person::input();
    cout<<"Payments: "; cin>>this->payments; cin.ignore();
    cout<<"DateOfPayment: "; getline(cin,this->dateOfPayment);
}
void GuestUser ::input(fstream &inf)
{   Person::input(inf);
    inf>>this->payments; inf.ignore();
    getline(inf,this->dateOfPayment);
}
void GuestUser ::GeneralView()
{
    Person::GeneralView();
    cout<<setw(15)<<this->dateOfPayment<<" |";
    cout<<setw(10)<<"UNRANK"<<" |";
}
void GuestUser::TypeView()
{
    Person::TypeView();
    cout<<"\nPayments: "<<this->payments
        <<"\nDateOfPayment: "<<this->dateOfPayment;
}
void GuestUser ::exportList(fstream &inf,string file)
{
    Person::exportList(inf,file);
    inf<<this->dateOfPayment<<endl;
} 
string GuestUser::get_dateOfPayment()
{
    return this->dateOfPayment;
}
string GuestUser::get_rank()
{
    return "UNRANK";
}
string GuestUser::get_Username()
{
    return "�";
}
// string GuestUser::get_payments()
// {
//     return this->payments;
// }



ListUser::ListUser()
{
    this->inf.open("Data\\user.txt", ios::in | ios::out);
}
void ListUser::inList()
{
    string checkid;
        while (!this->inf.eof())
        {   getline(this->inf,checkid);
            if (check_substring("RU",checkid)==true)
            {
                a = new RegisteredUser(checkid);
                a->input(this->inf);
                b.push_back(a);
            }
            else if (check_substring("GU",checkid)==true)
            {
                a = new GuestUser(checkid);
                a->input(this->inf);
                b.push_back(a);
            }
        }
        inf.close();
}
void ListUser::GeneralViewList()
{
    cout<<endl; line(112,'_');
        ListPerson::GeneralViewList();
        cout<<setw(15)<<"Username/DoP"<<" |";
        cout<<setw(10)<<"Rank"<<" |";
        cout<<endl; line(112,'_');
        for (int i = 0; i < b.size(); i++)
        {   
            b[i]->GeneralView();
        }
        cout<<endl; line(112,'_');
}
void ListUser::GeneralViewList(vector<Person*> user)
{
    cout<<endl; line(112,'_');
        ListPerson::GeneralViewList();
        cout<<setw(15)<<"TenTK"<<" |";
        cout<<setw(10)<<"Rank"<<" |";
        cout<<endl; line(112,'_');
        for (int i = 0; i < user.size(); i++)
        {  
            user[i]->GeneralView();
        }
        cout<<endl; line(112,'_');
}
void ListUser::exportList(string file)
{
    ListPerson::exportList(file);
}
void ListUser::insertObject()
{
    cout<<"\nNhap so luong khach hang can bo sung: "; int n; cin>>n; cin.ignore();
    string checkid;
    getline(cin,checkid);
    if (check_substring("RS",checkid)==true) a = new RegisteredUser(checkid);
    else a = new GuestUser(checkid);
    for (int i = 0; i<n;i++)
    {   
        cout<<"Khach hang bo sung thu"<<i+1<<": ";
        a->input();
        b.push_back(a);
    }
}
void ListUser::deleteObject()
{
    ListPerson::deleteObject("nguoi dung");
}
void ListUser::IncreSortbyUsername()
{
    for (int i = b.size()-1; i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_Username()>b[j+1]->get_Username()) swap(b[j],b[j+1]);
        }
    }
}
void ListUser::DecreSortbyUsername()
{
    for (int i = b.size()-1; i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_Username()<b[j+1]->get_Username()) swap(b[j],b[j+1]);
        }
    }
}
void ListUser::IncreSortbyRank()
{
    for (int i = b.size()-1; i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (get_top(b[j]->get_rank())>get_top(b[j+1]->get_rank())) swap(b[j],b[j+1]);
        }
    }
}
void ListUser::DecreSortbyRank()
{
     for (int i = b.size()-1; i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (get_top(b[j]->get_rank())<get_top(b[j+1]->get_rank())) swap(b[j],b[j+1]);
        }
    }
}
void ListUser::FindbyUsername()
{   user.clear();
    int count = 0;
        cout<<"\nMoi nhap tai khoan can tim: "; 
        string substring;
        getline(cin,substring);
        for (int i = 0; i<b.size();i++)
        {
            if (check_substring(substring,b[i]->get_Username())==true)
            {
                user.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListUser::GeneralViewList(user);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListUser::FindbyRank()
{
    user.clear();
    int count = 0;
        cout<<"\nMoi nhap muc rank can tim: "; 
        string substring;
        getline(cin,substring);
        for (int i = 0; i<b.size();i++)
        {
            if (check_substring(substring,b[i]->get_rank())==true)
            {
                user.push_back(b[i]);
                count++;
            }
        }
        ListUser::GeneralViewList(user);
        if (count==0) cout<<"\nNOT FOUND";
}
void ListUser::FilterbyRank()
{
    user.clear();
    int count = 0;
        cout<<"\nMoi nhap muc rank cao nhat: "; 
        string maxrank;
        getline(cin,maxrank);
        cout<<"\nMoi nhap muc rank thap nhat: ";
        string minrank;
        getline(cin,minrank);
        for (int i = 0; i<b.size();i++)
        {
            if (get_top(b[i]->get_rank())<=get_top(maxrank)&&get_top(b[i]->get_rank())>=get_top(minrank))
            user.push_back(b[i]);
        }
        ListUser::GeneralViewList(user);
        if (count==0) cout<<"\nNOT FOUND";
}
