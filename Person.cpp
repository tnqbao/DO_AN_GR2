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
    string efile = "Data\\" + file + ".txt";
    inf.open(efile.c_str(), ios::out);
    for (int i = 0; i < list.size(); i++)
    {
        list[i]->exportList(inf,file);
        if (i < list.size() - 1)
        {
            inf << endl;
        }
    }
}
void ListPerson::deleteObject(string text)
{   cout << "\nChon so luong "<<text<<"  can xoa: "; 
    int n; 
    cin >> n; 
    while(n > list.size())
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
            list.erase(list.begin() + *i);
        }
    }
}
void ListPerson::IncreSortbyID()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (list[j]->get_id()>list[j+1]->get_id())
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::DecreSortbyID()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (list[j]->get_id()<list[j+1]->get_id())
            swap(list[j],list[j+1]);
        }
    }
}  
void ListPerson::IncreSortbyName()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (list[j]->get_name()>list[j+1]->get_name())
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::DecreSortbyName()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (list[j]->get_name()<list[j+1]->get_name())
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::IncreSortbyTell()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (list[j]->get_tell()>list[j+1]->get_tell())
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::DecreSortbyTell()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (list[j]->get_tell()<list[j+1]->get_tell())
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::IncreSortbySex()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (list[j]->get_sex()>list[j+1]->get_sex())
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::DecreSortbySex()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (list[j]->get_sex()<list[j+1]->get_sex())
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::IncreSortbyCCCD()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (list[j]->get_cccd()>list[j+1]->get_cccd())
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::DecreSortbyCCCD()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (list[j]->get_cccd()<list[j+1]->get_cccd())
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::IncreSortbyBirthday()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (SortDay(list[j]->get_birthday(),list[j+1]->get_birthday())==1)
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::DecreSortbyBirthday()
{
    for (int i = list.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (SortDay(list[j]->get_birthday(),list[j+1]->get_birthday())==2)
            swap(list[j],list[j+1]);
        }
    }
}
void ListPerson::FindbyID()
{   int count = 0;
    cout<<"\nMoi nhap ID can tim: "; 
    string substring;
    getline(cin,substring);
    cout<<endl; line(112,'_');
    for (int i = 0; i<list.size();i++)
    {
        if (check_substring(substring,list[i]->get_name())==true)
        {   
            list[i]->GeneralView();
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
    for (int i = 0; i<list.size();i++)
    {
        if (check_substring(substring,list[i]->get_name())==true)
        {   cout<<endl; line(112,'_');
            list[i]->GeneralView();
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
    for (int i = 0; i<list.size();i++)
    {
        if (check_substring(substring,list[i]->get_tell())==true)
        {  cout<<endl; line(112,'_');
            list[i]->GeneralView();
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
    for (int i = 0; i<list.size();i++)
    {
        if (check_substring(substring,list[i]->get_birthday())==true)
        {   cout<<endl; line(112,'_');
            list[i]->GeneralView();
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
    for (int i = 0; i<list.size();i++)
    {
        if (check_substring(substring,list[i]->get_sex())==true)
        {   cout<<endl; line(112,'_');
            list[i]->GeneralView();
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
    for (int i = 0; i<list.size();i++)
    {   int count = 0;
        if (check_substring(substring,list[i]->get_cccd())==true)
        {   cout<<endl; line(112,'_');
            list[i]->GeneralView();
            count++;
        }
    }
    if (count==0) cout<<"\nNOT FOUND";     
    cout<<endl; line(112,'_');
}
void ListPerson::FilterbyInfor()
{   int count = 0;
    cout<<"\nNhap thong tin can loc: (Enter->Bo qua)\n";
    ps= new Person;
    ps->input();
    for (int i = 0; i<list.size();i++)
    {   
        if (check_substring(ps->get_id(),list[i]->get_id())==false) continue;
        if (check_substring(ps->get_name(),list[i]->get_name())==false) continue;
        if (check_substring(ps->get_tell(),list[i]->get_tell())==false) continue;
        if (check_substring(ps->get_birthday(),list[i]->get_birthday())==false) continue;
        if (check_substring(ps->get_sex(),list[i]->get_sex())==false) continue;
        if (check_substring(ps->get_cccd(),list[i]->get_cccd())==false) continue;
        cout<<endl; line(112,'_');
        list[i]->GeneralView();
        count++;
    }
    if (count==0) cout<<"\nNOT FOUND";     
    cout<<endl; line(112,'_');
}  

