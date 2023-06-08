#include <bits/stdc++.h>
#include "Staff.h"


ContractStaff::ContractStaff() {}
ContractStaff::ContractStaff(string id)
{
    this->id = id;
}
void ContractStaff::input()
{
    Person::input();
    cout << "ChucVu: ";
    getline(cin, this->permit);
    cout << "LuongCoBan: ";
    cin >> this->basic_salary;
    cin.ignore();
    bonus = this->find_bonus();
    salary = this->calculate_salary();
}
void ContractStaff::input(fstream &inf)
{
    Person::input(inf);
    getline(inf, this->permit);
    inf >> this->basic_salary;
    inf.ignore();
    bonus = this->find_bonus();
    salary = this->calculate_salary();
}
void ContractStaff::GeneralView() 
{
    Person::GeneralView();
    cout<<setw(12)<<this->permit<<" |";
    cout<<setw(15)<<fixed<<setprecision(2)<<this->salary<<" |";
}
void ContractStaff::TypeView()
{
    Person::TypeView();
    cout<<"\nPermit: "<<setw(15)<<this->permit
        <<"\nBasicSalary: "<<setw(15)<<this->basic_salary
        <<"\nBonus: "<<setw(15)<<this->bonus
        <<"\nSalary: "<<setw(15)<<this->salary;
}
void ContractStaff::exportList(fstream &inf,string file)
{   
    Person::exportList(inf,file);
    inf << this->permit << endl; 
    inf << fixed << setprecision(0) << this->basic_salary;
}
float ContractStaff::find_bonus()
{
    if (this->permit == "Quan Ly")
        return this->basic_salary * 0.1;
    else if (this->permit == "Nhan Vien")
        return this->basic_salary * 0.05;
    else
        return 0;
}
float ContractStaff::calculate_salary()
{
    return this->salary = this->basic_salary + this->bonus;
}
float ContractStaff::get_salary()
{
    return this->salary;
}
string ContractStaff::get_permit()
{
    return this->permit;
}
void ContractStaff::change_basicsalary(float basic_salary)
{
    this->basic_salary = basic_salary;
}
void ContractStaff::change_permit(string permit)
{
    this->permit = permit;
}




RegularStaff::RegularStaff() {}
RegularStaff::RegularStaff(string id)
{
    this->id = id;
}
void RegularStaff::input()
{
    Person::input();
    cout << "LuongCoBan: ";
    cin >> this->basic_salary;
    cin.ignore();
    cout<<"Ngay cong: "; cin>>this->workday; cin.ignore();
    salary = this->calculate_salary();
}
void RegularStaff::input(fstream &inf)
{
    Person::input(inf);
    inf >> this->workday;
    inf >> this->basic_salary;
    inf.ignore();
    salary = this->calculate_salary();
}
void RegularStaff::GeneralView()
{
    Person::GeneralView();
    cout<<setw(12)<<"PartTime"<<" |";
    cout<<setw(15)<<fixed<<setprecision(2)<<this->salary<<" |";
}
void RegularStaff::TypeView()
{
    Person::TypeView();
        cout<<"\nWorkday: "<<setw(15)<<this->workday
        <<"\nBasicSalary: "<<setw(15)<<this->basic_salary
        <<"\nSalary: "<<setw(15)<<this->salary;
}
void RegularStaff::exportList(fstream &inf,string file)
{   
    Person::exportList(inf,file);
    inf << this->workday << endl; 
    inf << fixed << setprecision(0) << this->basic_salary;
}
float RegularStaff::calculate_salary()
{
    return this->salary = this->basic_salary * this->workday;
}
float RegularStaff::get_salary()
{
    return this->salary;
}
string RegularStaff::get_permit()
{
    return "PARTTIME";
}
void RegularStaff::change_basicsalary(float basic_salary)
{
    this->basic_salary = basic_salary;
}
void RegularStaff::change_workday(int workday)
{
    this->workday = workday;
}




ListStaff::ListStaff()
{
    this->inf.open("Data\\staff.txt", ios::in | ios::out);
}
void ListStaff::inList()
{   string checkid;
    while (!this->inf.eof())
    {   getline(this->inf,checkid);
        if (check_substring("CS",checkid)==true) a = new ContractStaff(checkid);
        else a = new RegularStaff(checkid);
        a->input(this->inf);
        b.push_back(a);
    }
    inf.close();
}
void ListStaff::GeneralViewList()
{   cout<<endl; line(113,'_');
    ListPerson::GeneralViewList();
    cout<<setw(12)<<"Permit"<<" |";
    cout<<setw(15)<<"Salary"<<" |";
    for (int i = 0; i < b.size(); i++)
    {   cout<<endl; line(113,'_');
        b[i]->GeneralView();
    }
    cout<<endl; line(113,'_');
}
void ListStaff::GeneralViewList(vector<Person*> staff)
{   cout<<endl; line(113,'_');
    ListPerson::GeneralViewList();
    cout<<setw(12)<<"Permit"<<" |";
    cout<<setw(15)<<"Salary"<<" |";
    for (int i = 0; i < staff.size(); i++)
    {   cout<<endl; line(113,'_');
        staff[i]->GeneralView();
    }
    cout<<endl; line(113,'_');
}
void ListStaff::exportList(string file)
{
    ListPerson::exportList(file);
}
void ListStaff::deleteObject()
{
    ListPerson::deleteObject("nhan vien");
}
void ListStaff::insertObject()
{
    cout<<"\nNhap so luong nhan vien can bo sung: "; int n; cin>>n; cin.ignore();
    if (n<1) return;
    cout<<"\nNhap loai nhan vien(1-ContractStaff/2-RegularStaff)?: ";
    string checkid;
    getline(cin,checkid);
    if (check_substring("CS",checkid)==true) a = new ContractStaff(checkid);
    else a = new RegularStaff(checkid);
   
    for (int i = 0; i<n;i++)
    {    bool check_tontai = false;
        cout<<"Nhan vien bo sung thu"<<i+1<<": ";
        a->input();
        for (int i = 0;i<b.size();i++)
        {
            if (a->get_id()==b[i]->get_id()||a->get_tell()==b[i]->get_tell()) 
            {
                cout<<"\nDu lieu da ton tai";
                check_tontai = true;
                break;
            }
        }

        if (check_tontai==false) b.push_back(a);
    }
}
void ListStaff::IncreSortbySalary()
{
    for (int i = b.size()-1; i>0;i--)
    {
        for (int j = 0 ; j<i;j++)
        if (b[j]->get_salary()>b[j+1]->get_salary())
        swap(b[j],b[j+1]);
    }
}
void ListStaff::DecreSortbySalary()
{
    for (int i = b.size()-1; i>0;i--)
    {
        for (int j = 0 ; j<i;j++)
        if (b[j]->get_salary()<b[j+1]->get_salary())
        swap(b[j],b[j+1]);
    }
}

void ListStaff::IncreSortbyPermit()
{
    for (int i = b.size()-1; i>0;i--)
    {
        for (int j = 0 ; j<i;j++)
        if (SortPermit(b[j]->get_permit())>SortPermit(b[j+1]->get_permit()))
        swap(b[j],b[j+1]);
    }
}
void ListStaff::DecreSortbyPermit()
{
    for (int i = b.size()-1; i>0;i--)
    {
        for (int j = 0 ; j<i;j++)
        if (SortPermit(b[j]->get_permit())<SortPermit(b[j+1]->get_permit()))
        swap(b[j],b[j+1]);
    }
}
void ListStaff::FindbySalary()
{
    int count = 0;
    cout<<"\nMoi nhap so luong can tim: "; 
    double money;
    cin>>money; cin.ignore();
    for (int i = 0; i<b.size();i++)
    {
        if (money==b[i]->get_salary())
        {   cout<<endl; line(112,'_');
            b[i]->GeneralView();
            count++;
        }
    }
    if (count==0) cout<<"\nNOT FOUND";
    cout<<endl; line(112,'_');
}
void ListStaff::FindbyPermit()
{
    int count = 0;
    cout<<"\nMoi nhap chuc vu can tim: "; 
    string substring;
    getline(cin,substring);
    for (int i = 0; i<b.size();i++)
    {
        if (check_substring(substring,b[i]->get_permit())==true)
        {   cout<<endl; line(112,'_');
            b[i]->GeneralView();
            count++;
        }
    }
    if (count==0) cout<<"\nNOT FOUND";
    cout<<endl; line(112,'_');
}
void ListStaff::TotalOfSalary()
{   float tong = 0;
    for (int i = 0; i<b.size();i++)
    {
        tong += b[i]->get_salary();
    }
    cout<<"\nTong tien luong cua nhan vien la: "<<fixed<<setprecision(0)<<tong<< "vnd";
}
void ListStaff::FilterbySalary()
{   staff.clear();
    cout<<"\nNhap muc luong thap nhat/cao nhat: \n";
    int min; int max;
    cout<<"\nMIN: "; cin>>min; cout<<"MAX: "; cin>>max;
    for (int i = 0; i<b.size();i++)
    {
        if (b[i]->get_salary()<min||b[i]->get_salary()>max) continue;
        staff.push_back(b[i]);
    }
    ListStaff::GeneralViewList(staff);
}

