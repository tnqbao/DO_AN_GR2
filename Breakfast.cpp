#include "Breakfast.h"

Breakfast::Breakfast()
{

}
void Breakfast::input()
{
    cout<<"\nID: "; getline(cin,this->id);
    cout<<"\nName: "; getline(cin,this->name);
    cout<<"\nBrand: "; getline(cin,this->brand);
    cout<<"\nBasicPrice: "; scanf("%f", this->basic_price);
    cout<<"\nSize: "; getline(cin,this->size);
    cout<<"\nQuantity: "; scanf("%d",this->quantity);
}
void Breakfast::inputFilter()
{
    cout<<"\nID: "; getline(cin,this->id);
    cout<<"\nName: "; getline(cin,this->name);
    cout<<"\nBrand: "; getline(cin,this->brand);
    cout<<"\nSize: "; getline(cin,this->size);
}
void Breakfast::input(fstream &inf)
{
    getline(inf,this->id);
    getline(inf,this->name);
    getline(inf,this->brand);
    inf>>this->basic_price; inf.ignore();
    getline(inf,this->size);
    inf>>this->quantity; inf.ignore(); 
}
void Breakfast::View()
{
    cout <<endl<<setfill(' ') << left <<"|" << setw(7) << this->id<<" |"
    << setw(30) <<this->name<<" |"
    << setw(35) <<this->brand<<" |"
    << setw(7) <<this->size<<" |"
    << setw(7) <<this->quantity <<" |"
    << setw(12) << fixed << setprecision(2) << this->calculatePrice()<<" |";
}
void Breakfast::exportList(fstream &inf)
{
    inf << this->id << endl;
    inf << this->name << endl;
    inf << this->brand << endl;
    inf << this->basic_price << endl;
    inf << this->size << endl;
    inf << this->quantity<<endl;
}
double Breakfast::calculatePrice()
{
    if (this->size=="M") this->price = this->basic_price;
    if (this->size=="L") this->price = this->basic_price * 1.25;
    if (this->size=="XL") this->price = this->basic_price * 1.5;
    return this->price;
}
string Breakfast::get_id()
{
    return this->id;
}
string Breakfast::get_name()
{
    return this->name;
}
string Breakfast::get_brand()
{
    return this->brand;
}
double Breakfast::get_basicPrice()
{
    return this->basic_price;
}
int Breakfast::get_size()
{   int num;
    if (this->size=="M") num = 1;
    else if (this->size=="S") num = 2;
    else if(this->size=="L") num = 3;
    else if (this->size=="XL") num = 4;
    return num;
}
int Breakfast::get_quantity() 
{
    return this->quantity;
}


ListBreakfast::ListBreakfast()
{
    inf.open("Data\\BREAKFAST.txt", ios::in | ios::out);
}
void ListBreakfast::inList()
{
    string checkid;
        while (!this->inf.eof())
        {  
            a.input(this->inf);
            b.push_back(a);
        }
    inf.close();
}
void ListBreakfast::GeneralViewList()
{   cout<<endl; line(113,'_');
    title_Breakfast();
    cout<<endl; line(113,'_');
    for (int i = 0; i<b.size();i++)
    {
        b[i].View();
    }
    cout<<endl; line(113,'_');
}
void ListBreakfast::GeneralViewList(vector<Breakfast> food)
{   cout<<endl; line(113,'_');
    title_Breakfast();
    cout<<endl; line(113,'_');
    for (int i = 0; i<food.size();i++)
    {
        food[i].View();
    }
    cout<<endl; line(113,'_');
}
void ListBreakfast::insertObject()
{
    cout<<"\nNhap so luong thong tin mon an can bo sung vao menu: "; int n; cin>>n; cin.ignore();
    for (int i = 0; i<n;i++)
    {   
        cout<<"Mon an bo sung thu"<<i+1<<": ";
        a.input();
        b.push_back(a);
    }
}
void ListBreakfast::exportList(string file)
{
     if (this->inf.is_open())
    {
        this->inf.close();
    }
    string efile = "Data\\" + file;
    inf.open(efile.c_str(), ios::out);
    for (int i = 0; i < b.size(); i++)
    {
        b[i].exportList(inf);
        if (i < b.size() - 1)
        {
            inf << endl;
        }
    }
}
void ListBreakfast::deleteObject()
{
     cout << "\nChon so mon an can xoa: "; 
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
void ListBreakfast::IncreSortbyID()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j].get_id()>b[j+1].get_id())
            swap(b[j],b[j+1]);
        }
    }
}
void ListBreakfast::DecreSortbyID()
{
    for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j].get_id()<b[j+1].get_id())
            swap(b[j],b[j+1]);
        }
    }
}
void ListBreakfast::IncreSortbyName()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j].get_name()>b[j+1].get_name())
            swap(b[j],b[j+1]);
        }
    }
}
void ListBreakfast::DecreSortbyName()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j].get_name()<b[j+1].get_name())
            swap(b[j],b[j+1]);
        }
    }
}
void ListBreakfast::IncreSortbyBrand()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j].get_brand()>b[j+1].get_brand())
            swap(b[j],b[j+1]);
        }
    }
}
void ListBreakfast::DecreSortbyBrand()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j].get_brand()<b[j+1].get_brand())
            swap(b[j],b[j+1]);
        }
    }
}
void ListBreakfast::IncreSortbySize()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j].get_size()>b[j+1].get_size())
            swap(b[j],b[j+1]);
        }
    }
}
void ListBreakfast::DecreSortbySize()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j].get_size()<b[j+1].get_size())
            swap(b[j],b[j+1]);
        }
    }
}
void ListBreakfast::IncreSortbyPrice()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j].calculatePrice()>b[j+1].calculatePrice())
            swap(b[j],b[j+1]);
        }
    }
}
void ListBreakfast::DecreSortbyPrice()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j].calculatePrice()<b[j+1].calculatePrice())
            swap(b[j],b[j+1]);
        }
    }
}
void ListBreakfast::FindbyID()
{
    food.clear();
    int count = 0;
        cout<<"\nMoi nhap ID can tim: "; 
        string substring;
        getline(cin,substring);
        for (int i = 0; i<b.size();i++)
        {
            if (check_substring(substring,b[i].get_id())==true)
            {
                food.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListBreakfast::GeneralViewList(food);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListBreakfast::FindbyName()
{
    food.clear();
    int count = 0;
        cout<<"\nMoi nhap ten mon an can tim: "; 
        string substring;
        getline(cin,substring);
        for (int i = 0; i<b.size();i++)
        {
            if (check_substring(substring,b[i].get_name())==true)
            {
                food.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListBreakfast::GeneralViewList(food);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListBreakfast::FindbyBrand()
{
    food.clear();
    int count = 0;
        cout<<"\nMoi nhap nhan hang can tim: "; 
        string substring;
        getline(cin,substring);
        for (int i = 0; i<b.size();i++)
        {
            if (check_substring(substring,b[i].get_brand())==true)
            {
                food.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListBreakfast::GeneralViewList(food);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListBreakfast::FindbySize()
{
    food.clear();
    int count = 0;
        cout<<"\nMoi nhap size can tim(1-M/2-S/3-L/3-XL): "; 
        int size;
        cin>>size; cin.ignore();
        for (int i = 0; i<b.size();i++)
        {
            if (b[i].get_size()==size)
            {
                food.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListBreakfast::GeneralViewList(food);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListBreakfast::FindbyPrice()
{
    food.clear();
    int count = 0;
        cout<<"\nMoi nhap gia mon an can tim(1-M/2-L/3-XL): "; 
        double price;
        cin>>price; cin.ignore();
        for (int i = 0; i<b.size();i++)
        {
            if (b[i].calculatePrice()==price)
            {
                food.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListBreakfast::GeneralViewList(food);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListBreakfast::FilterbyInfor()
{
    int count = 0;
    cout<<"\nNhap thong tin can loc: (Enter->Bo qua)\n";
    a.inputFilter();
    for (int i = 0; i<b.size();i++)
    {   
        if (check_substring(a.get_id(),b[i].get_id())==false) continue;
        if (check_substring(a.get_name(),b[i].get_name())==false) continue;
        if (check_substring(a.get_brand(),b[i].get_brand())==false) continue;
        if (a.get_size()!=b[i].get_size()) continue;
        cout<<endl; line(112,'_');
        b[i].View();
        count++;
    }
    if (count==0) cout<<"\nNOT FOUND";     
    cout<<endl; line(112,'_');
}
void ListBreakfast::FilterbyPrice()
{
    food.clear();
    cout<<"\nNhap gia thap nhat/cao nhat: \n";
    int min; int max;
    cout<<"\nMIN: "; cin>>min; cout<<"MAX: "; cin>>max;
    for (int i = 0; i<b.size();i++)
    {
        if (b[i].calculatePrice()<min||b[i].calculatePrice()>max) continue;
        food.push_back(b[i]);
    }
    ListBreakfast::GeneralViewList(food);
}
