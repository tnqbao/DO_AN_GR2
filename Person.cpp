#include "Person.h"
using namespace std;


void Person::input()
{
    cout << "ID: ";
    getline(cin, this->id);
    cout << "Ten: ";
    getline(cin, this->name);
    cout << "SDT: ";
    getline(cin, this->tell);
    cout << "GioiTinh: ";
    getline(cin, this->sex);
    cout << "cccd: ";
    getline(cin, this->cccd);
    cout << "NgaySinh: ";
    getline(cin, this->birthday);
}
void Person::input(fstream &inf)
{
    getline(inf, this->name);
    getline(inf, this->tell);
    getline(inf, this->sex);
    getline(inf, this->cccd);
    getline(inf, this->birthday);
}
void Person::GeneralView()
{   
    cout <<endl<<setfill(' ') << left <<"|" << setw(7) << this->id<<" |"
    << setw(23) <<this->name<<" |"
    << setw(12) <<this->tell<<" |"
    << setw(12) <<this->cccd<<" |"
    << setw(5)  <<this->sex<<" |"
    << setw(10) <<this->birthday<<" |";
}
void Person::TypeView()
{
    cout<<setw(15)<<"\nID: "<<this->id
        <<setw(15)<<"\nName: "<<this->name
        <<setw(15)<<"\nTell: "<<this->tell
        <<setw(15)<<"\nCCCD: "<<this->cccd
        <<setw(15)<<"\nSEX: "<<this->sex
        <<setw(15)<<"\nBirthday: "<<this->birthday;
}
void Person::exportList(fstream &inf, string file)
{
    inf << this->id << endl;
    inf << this->name << endl;
    inf << this->tell << endl;
    inf << this->sex << endl;
    inf << this->cccd << endl;
    inf << this->birthday << endl;
}
float Person::get_salary()
{
    return 0;
}
string Person::get_rank()
{
    return "";
}
string Person::get_Username()
{
    return "";
}
string Person::get_id()
{
    return this->id;
}
string Person::get_name()
{
    return this->name;
} 
string Person::get_tell()
{
    return this->tell;
}
string Person::get_sex()
{
    return this->sex;
}
string Person::get_cccd()
{
    return this->cccd;
}
string Person::get_birthday()
{
    return this->birthday;
}
string Person::get_permit()
{
    return "";
}
void Person::change_tell(string tell)
{
    this->tell = tell;
}
void Person::change_sex(string sex)
{
    this->sex = sex;
}
void Person::change_cccd(string cccd)
{
    this->cccd = cccd;
}




void ListPerson::inList() 
{

}
void ListPerson::GeneralViewList() 
{    
    
    cout << endl<<setfill(' ') << left <<"|" << setw(7) <<  "ID"<<" |"
    << setw(23) << "NAME"<<" |"
    << setw(12) << "TELL"<<" |"
    << setw(12) << "CMND"<<" |"
    << setw(5) << "SEX"<<" |"
    << setw(10) << "BIRTHDAY"<< " |";
}
void ListPerson::insertObject() 
{

}
void ListPerson::exportList(string file)
{
    if (this->inf.is_open())
    {
        this->inf.close();
    }
    string efile = "Data\\" + file;
    inf.open(efile.c_str(), ios::out);
    for (int i = 0; i < b.size(); i++)
    {
        b[i]->exportList(inf,file);
        if (i < b.size() - 1)
        {
            inf << endl;
        }
    }
}
void ListPerson::deleteObject(string text)
{   cout << "\nChon so luong "<<text<<"  can xoa: "; 
    int n; 
    cin >> n; 
    while(n > b.size())
    {
        cout << "\nKhong hon le, moi nhap lai ";
        cin >> n;
    }
    int vt[n];
    set<int> st;
    if (n>0)
    { 
        cout << "\nMoi nhap cac vi tri xoa du lieu: ";
        for (int i = 0; i < n; i++)
        {
            cin >> vt[i];
            st.insert(vt[i]-1);
        }
        for (set<int>::reverse_iterator i = st.rbegin(); i != st.rend(); i++)
        {
            b.erase(b.begin() + *i);
        }
    }
}
void ListPerson::IncreSortbyID()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_id()>b[j+1]->get_id())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::DecreSortbyID()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_id()<b[j+1]->get_id())
            swap(b[j],b[j+1]);
        }
    }
}  
void ListPerson::IncreSortbyName()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_name()>b[j+1]->get_name())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::DecreSortbyName()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_name()<b[j+1]->get_name())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::IncreSortbyTell()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_tell()>b[j+1]->get_tell())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::DecreSortbyTell()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_tell()<b[j+1]->get_tell())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::IncreSortbySex()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_sex()>b[j+1]->get_sex())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::DecreSortbySex()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_sex()<b[j+1]->get_sex())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::IncreSortbyCCCD()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_cccd()>b[j+1]->get_cccd())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::DecreSortbyCCCD()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_cccd()<b[j+1]->get_cccd())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::IncreSortbyBirthday()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (SortDay(b[j]->get_birthday(),b[j+1]->get_birthday())==1)
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::DecreSortbyBirthday()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (SortDay(b[j]->get_birthday(),b[j+1]->get_birthday())==2)
            swap(b[j],b[j+1]);
        }
    }
}
void ListPerson::FindbyID()
{   int count = 0;
    cout<<"\nMoi nhap ID can tim: "; 
    string substring;
    getline(cin,substring);
    cout<<endl; line(112,'_');
    for (int i = 0; i<b.size();i++)
    {
        if (check_substring(substring,b[i]->get_name())==true)
        {   
            b[i]->GeneralView();
            count++;
        }
    }
    if (count==0)cout<<"\nNOT FOUND";
    cout<<endl; line(112,'_');
}
void ListPerson::FindbyName()
{   int count = 0;
    cout<<"\nMoi nhap ten can tim: "; 
    string substring;
    getline(cin,substring);
    for (int i = 0; i<b.size();i++)
    {
        if (check_substring(substring,b[i]->get_name())==true)
        {   cout<<endl; line(112,'_');
            b[i]->GeneralView();
            count++;
        }
    }
    if (count==0) cout<<"\nNOT FOUND";
    cout<<endl; line(112,'_');
}
void ListPerson::FindbyTell()
{   int count = 0;
    cout<<"\nMoi nhap sdt can tim: "; 
    string substring;
    getline(cin,substring);
    for (int i = 0; i<b.size();i++)
    {
        if (check_substring(substring,b[i]->get_tell())==true)
        {  cout<<endl; line(112,'_');
            b[i]->GeneralView();
            count++;
        }
    }
    if (count==0) cout<<"\nNOT FOUND";     
    cout<<endl; line(112,'_');
}
void ListPerson::FindbyBirthday()
{   int count = 0;
    cout<<"\nMoi nhap ngay/thang/nam sinh : "; 
    string substring;
    getline(cin,substring);
    for (int i = 0; i<b.size();i++)
    {
        if (check_substring(substring,b[i]->get_birthday())==true)
        {   cout<<endl; line(112,'_');
            b[i]->GeneralView();
            count++;
        }
    }
    if (count==0) cout<<"\nNOT FOUND";     
    cout<<endl; line(112,'_');
}
void ListPerson::FindbySex()
{   int count = 0;
    cout<<"\nMoi nhap gioi tinh : "; 
    string substring;
    getline(cin,substring);
    for (int i = 0; i<b.size();i++)
    {
        if (check_substring(substring,b[i]->get_sex())==true)
        {   cout<<endl; line(112,'_');
            b[i]->GeneralView();
            count++;
        }
    }
    if (count==0) cout<<"\nNOT FOUND";     
    cout<<endl; line(112,'_');
}
void ListPerson::FindbyCCCD()
{   int count = 0;
    cout<<"\nMoi nhap ten can tim: "; 
    string substring;
    getline(cin,substring);
    for (int i = 0; i<b.size();i++)
    {   int count = 0;
        if (check_substring(substring,b[i]->get_cccd())==true)
        {   cout<<endl; line(112,'_');
            b[i]->GeneralView();
            count++;
        }
    }
    if (count==0) cout<<"\nNOT FOUND";     
    cout<<endl; line(112,'_');
}
void ListPerson::FilterbyInfor()
{   int count = 0;
    cout<<"\nNhap thong tin can loc: (Enter->Bo qua)\n";
    a = new Person;
    a->input();
    for (int i = 0; i<b.size();i++)
    {   
        if (check_substring(a->get_id(),b[i]->get_id())==false) continue;
        if (check_substring(a->get_name(),b[i]->get_name())==false) continue;
        if (check_substring(a->get_tell(),b[i]->get_tell())==false) continue;
        if (check_substring(a->get_birthday(),b[i]->get_birthday())==false) continue;
        if (check_substring(a->get_sex(),b[i]->get_sex())==false) continue;
        if (check_substring(a->get_cccd(),b[i]->get_cccd())==false) continue;
        cout<<endl; line(112,'_');
        b[i]->GeneralView();
        count++;
    }
    if (count==0) cout<<"\nNOT FOUND";     
    cout<<endl; line(112,'_');
}  

