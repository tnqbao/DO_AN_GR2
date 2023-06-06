#include "Pc.h"

void PC::input()
{
    cout << "ID: ";
    getline(cin, this->id);
    cout << "Ten: ";
    getline(cin, this->name);
    cout << "Loai may: ";
    getline(cin, this->model);
    cout << "He dieu hanh: ";
    getline(cin,this->operatingSystem);
}
void PC::input(fstream &inf)
{
    getline(inf, this->name);
    getline(inf, this->model);
    getline(inf, this->operatingSystem);
}
void PC::GeneralView()
{
    cout <<endl<<setfill(' ') << left <<"|" << setw(7) << this->id<<" |"
    << setw(30) <<this->name<<" |"
    << setw(12) <<this->model<<" |"
    << setw(12) <<this->operatingSystem<<" |";
}
void PC::TypeView()
{
    cout<<"\nID: "<<this->id
        <<"\nName: "<<this->name
        <<"\nModel: "<<this->model
        <<"\nOperatingSystem: "<<this->operatingSystem;
}
void PC::exportList(fstream &inf, string file)
{
    inf << this->id << endl;
    inf << this->name << endl;
    inf << this->model << endl;
    inf << this->operatingSystem << endl;
    inf << this->price << endl;
}
string PC::get_id()
{
    return this->id;
}
string PC::get_name()
{
    return this->name;
}
string PC::get_model()
{
    return this->model;
}
string PC::get_operatingSystem()
{
    return this->operatingSystem;
}
double PC::calculatePrice()
{
    return 0;
}
void PC::change_id(string id)
{
    this->id = id;
}
void PC::change_name(string name)
{
    this->name = name;
}
void PC::change_price(double price)
{
    this->price = price;
}




Laptop::Laptop()
{

}
Laptop::Laptop(string id)
{
    this->id = id;
}
void Laptop::input()
{
    PC::input();
    cout<<"Brand: "; getline(cin,this->brand);
    cout<<"Webcam(Y/N?): "; cin>>this->webcam;
    cout<<"Wifi(Y/N?) "; cin>>this->wifi;
    cout<<"Bluetooh(Y/N?): "; cin>>this->bluetooh;
    cout<<"Battery: "; cin>>this->battery;
    cout<<"Basic Price: "; cin>>this->basic_price; cin.ignore();
}
void Laptop::input(fstream &inf)
{
    PC::input(inf);
    inf>>this->brand;
    inf>>this->bluetooh;
    inf>>this->wifi;
    inf>>this->webcam;
    inf>>this->battery;
    inf>>this->basic_price; inf.ignore();
    Laptop::calculatePrice();
}
void Laptop::GeneralView()
{
    PC::GeneralView();
    cout<<setw(20)<<this->price<<" |";
}
void Laptop::TypeView()
{
    PC::TypeView();
    cout<<"\nBrand: "<<this->brand
        <<"\nBluetooh: "<<this->bluetooh
        <<"\nWifi: "<<this->wifi
        <<"\nWebcam: "<<this->webcam
        <<"\nBasicPrice: "<<this->basic_price
        <<"\nPrice: "<<calculatePrice();
}
void Laptop::exportList(fstream &inf,string file)
{
    PC::exportList(inf,file);
    inf<<this->brand;
    inf<<this->bluetooh;
    inf<<this->wifi;
    inf<<this->webcam;
    inf<<this->battery;
    inf<<this->basic_price;
}
double Laptop::calculatePrice()
{
    double sale = 0;
    if (this->bluetooh==false) sale += 0.1;
    if (this->webcam==false) sale += 0.1;
    if (this->wifi==false) sale += 0.1;
    if (this->battery<10000) sale +=0.1;
    this->price = this->basic_price * (1.0-sale);
    return this->price;
}
double Laptop::get_battery()
{
    return this->battery;
}
void Laptop::change_battery(double battery)
{
    this->battery = battery;
}
void Laptop::change_Price(double Price)
{
    this->price = price;
}



TabletPC::TabletPC()
{

}
TabletPC::TabletPC(string id)
{
    this->id = id;
}
void TabletPC::input()
{
    PC::input();
    cout<<"BasicPrice: "; cin>>this->basic_price; cin.ignore(); 
    cout<<"Proccessor: "; getline(cin,this->processor);
    cout<<"GraphicsCard: "; getline(cin,this->graphicsCard);
    cout<<"NumerConnectivity: "; cin>>this->NumerConnectivity; cin.ignore();
}    
void TabletPC::input(fstream &inf)
{
    PC::input(inf);
    inf>>this->basic_price; inf.ignore();
    getline(inf,this->processor);
    getline(inf,this->graphicsCard);
    inf>>this->NumerConnectivity; inf.ignore();
    TabletPC::calculatePrice();
}
void TabletPC::GeneralView()
{
    PC::GeneralView();
    cout<<setw(20)<<fixed<<setprecision(2)<<this->price<<" |";
}
void TabletPC::TypeView()
{
    PC::TypeView();
    cout<<"\nProcessor: "<<this->processor
        <<"\nGraphicCard: "<<this->graphicsCard
        <<"\nNumberConnectivity: "<<this->NumerConnectivity
        <<"\nBasic_Price: "<<fixed<<setprecision(2)<<this->basic_price
        <<"\nPrice: "<<fixed<<setprecision(2)<<this->price;
}
void TabletPC::exportList(fstream &inf,string file)
{
    PC::exportList(inf,file);
    inf<<this->basic_price<<endl;
    inf<<this->processor<<endl;
    inf<<this->graphicsCard<<endl;
    inf<<this->NumerConnectivity<<endl;
}
double TabletPC::calculatePrice()
{
    double VAT = 0;
    this->price = this->basic_price * (1.0+this->NumerConnectivity*0.1);
    return this->price;
}
string TabletPC::get_processor()
{
    return this->processor;
}
string TabletPC::get_graphicsCard()
{
    return this->graphicsCard;
}
int TabletPC::get_NumberConnetivity()
{
    return this->NumerConnectivity;
}




ListPC::ListPC()
{
    inf.open("Data\\Pc.txt", ios::in | ios::out);
}
void ListPC::inList()
{
     string checkid;
        while (!this->inf.eof())
        {   getline(this->inf,checkid);
            if (check_substring("LPC",checkid)==true)
            {
                a = new Laptop(checkid);
                a->input(this->inf);
                b.push_back(a);
            }
            else if (check_substring("TPC",checkid)==true)
            {
                a = new TabletPC(checkid);
                a->input(this->inf);
                b.push_back(a);
            }
        }
        inf.close();
}
void ListPC::GeneralViewList()
{
    cout<<endl; line(93,'_');
    title_PC();
    cout<<endl; line(93,'_');
    for (int i = 0;i<b.size();i++)
    {
        b[i]->GeneralView();
    }
    cout<<endl; line(93,'_');
}
void ListPC::GeneralViewList(vector<PC*> pc)
{
    cout<<endl; line(93,'_');
    title_PC();
    cout<<endl; line(93,'_');
    for (int i = 0;i<b.size();i++)
    {
        pc[i]->GeneralView();
    }
    cout<<endl; line(93,'_');
}
void ListPC::insertObject()
{
    cout<<"\nNhap so luong may tinh can bo sung: "; int n; cin>>n; cin.ignore();
    string checkid;
    getline(cin,checkid);
    if (check_substring("LPC",checkid)==true) a = new Laptop(checkid);
    else if(check_substring("TPC",checkid)==true) a= new TabletPC(checkid);
    for (int i = 0; i<n;i++)
    {   
        cout<<"May tinh bo sung thu"<<i+1<<": ";
        a->input();
        b.push_back(a);
    }
}
void ListPC::exportList(string file)
{
    if (this->inf.is_open())
    {
        this->inf.close();
    }
    string efile = "Data\\" + file + ".txt";
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
void ListPC::deleteObject()
{
    cout << "\nChon so luong may tinh can xoa: "; 
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
void ListPC::IncreSortbyID()
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
void ListPC::DecreSortbyID()
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
void ListPC::IncreSortbyName()
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
void ListPC::DecreSortbyName()
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
void ListPC::IncreSortbyModel()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_model()>b[j+1]->get_model())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPC::DecreSortbyModel()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_model()<b[j+1]->get_model())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPC::IncreSortbyOperatingSystem()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_operatingSystem()>b[j+1]->get_operatingSystem())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPC::DecreSortbyOperatingSystem()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->get_operatingSystem()<b[j+1]->get_operatingSystem())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPC::IncreSortbyPrice()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->calculatePrice()>b[j+1]->calculatePrice())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPC::DecreSortbyPrice()
{
     for (int i = b.size()-1;i>0;i--)
    {
        for (int j = 0; j<i;j++)
        {
            if (b[j]->calculatePrice()<b[j+1]->calculatePrice())
            swap(b[j],b[j+1]);
        }
    }
}
void ListPC::FindbyID()
{
    pc.clear();
    int count = 0;
        cout<<"\nMoi nhap ID can tim: "; 
        string substring;
        getline(cin,substring);
        for (int i = 0; i<b.size();i++)
        {
            if (check_substring(substring,b[i]->get_id())==true)
            {
                pc.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListPC::GeneralViewList(pc);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListPC::FindbyName()
{
     pc.clear();
    int count = 0;
        cout<<"\nMoi nhap ten may can tim: "; 
        string substring;
        getline(cin,substring);
        for (int i = 0; i<b.size();i++)
        {
            if (check_substring(substring,b[i]->get_name())==true)
            {
                pc.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListPC::GeneralViewList(pc);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListPC::FindbyModel()
{
     pc.clear();
    int count = 0;
        cout<<"\nMoi nhap loai may can tim: "; 
        string substring;
        getline(cin,substring);
        for (int i = 0; i<b.size();i++)
        {
            if (check_substring(substring,b[i]->get_model())==true)
            {
                pc.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListPC::GeneralViewList(pc);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListPC::FindbyOperatingSystem()
{
     pc.clear();
    int count = 0;
        cout<<"\nMoi nhap he dieu hanh can tim: "; 
        string substring;
        getline(cin,substring);
        for (int i = 0; i<b.size();i++)
        {
            if (check_substring(substring,b[i]->get_operatingSystem())==true)
            {
                pc.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListPC::GeneralViewList(pc);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListPC::FindbyPrice()
{
     pc.clear();
    int count = 0;
        cout<<"\nMoi nhap gia can tim: "; 
        double price;
        cin>>price; 
        for (int i = 0; i<b.size();i++)
        {
            if (b[i]->calculatePrice()==price)
            {
                pc.push_back(b[i]);
                count++;
            }
        }
        if (count>0) ListPC::GeneralViewList(pc);
        else if (count==0) cout<<"\nNOT FOUND";
}
void ListPC::FilterbyInfor()
{
    int count = 0;
    cout<<"\nNhap thong tin can loc: (Enter->Bo qua)\n";
    a = new PC;
    a->input();
    for (int i = 0; i<b.size();i++)
    {   
        if (check_substring(a->get_id(),b[i]->get_id())==false) continue;
        if (check_substring(a->get_name(),b[i]->get_name())==false) continue;
        if (check_substring(a->get_model(),b[i]->get_model())==false) continue;
        if (check_substring(a->get_operatingSystem(),b[i]->get_operatingSystem())==false) continue;
        cout<<endl; line(112,'_');
        b[i]->GeneralView();
        count++;
    }
    if (count==0) cout<<"\nNOT FOUND";     
    cout<<endl; line(112,'_');
}
void ListPC::FilterbyPrice()
{
    pc.clear();
    cout<<"\nNhap gia thue thap nhat/cao nhat: \n";
    int min; int max;
    cout<<"\nMIN: "; cin>>min; cout<<"MAX: "; cin>>max;
    for (int i = 0; i<b.size();i++)
    {
        if (b[i]->calculatePrice()<min||b[i]->calculatePrice()>max) continue;
        pc.push_back(b[i]);
    }
    ListPC::GeneralViewList(pc);
}
