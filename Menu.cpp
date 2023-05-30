#include "Menu.h"

void MainMenu()
{   while(1)
    {
        system("cls");
        vector<string> arr;
        arr = {"STAFF","USER","DEVICE","BREAKFAST"};
        int count = 0;
        cout<<endl << "\t\t"; line(60,'_');
        cout<<"\n\t\t|\t\t\t "<<" MANAGER MODE"  << setfill(' ')  << setw(22)<<"|";
        cout<<endl << "\t\t"; line(60,'_');
        cout<< endl << setfill(' ');
        while(count<arr.size())
        {
            cout<< "\n\t\t|"<< setw(3) << count + 1  <<" |" << arr[count] << " MANAGEMENT"  <<  setfill(' ') << setw(43-arr[count].size()) <<"|";
            count++;
        }
        cout<<endl << "\t\t"; line(60,'_');
        int a;
        int choose;  cout<<"\n\nMoi ban nhap lua chon(1-4): "; cin>>choose; cin.ignore();
        if (choose<1||choose>5) return;
        switch (choose)
        {
            case 1:
            {
                ListStaff list;
                void (ListStaff::*FunctionSortArr[])() = {
                        &ListStaff::IncreSortbyID,
                        &ListStaff::DecreSortbyID,
                        &ListStaff::IncreSortbyName,
                        &ListStaff::DecreSortbyName,
                        &ListStaff::IncreSortbyTell,
                        &ListStaff::DecreSortbyTell,
                        &ListStaff::IncreSortbySex,
                        &ListStaff::DecreSortbySex,
                        &ListStaff::IncreSortbyCCCD,
                        &ListStaff::DecreSortbyCCCD,
                        &ListStaff::IncreSortbyBirthday,
                        &ListStaff::DecreSortbyBirthday,
                        &ListStaff::IncreSortbySalary,
                        &ListStaff::DecreSortbySalary,
                        &ListStaff::IncreSortbyPermit,
                        &ListStaff::DecreSortbyPermit
                    };
                void (ListStaff::*FunctionFindArr[])() = {
                        &ListStaff::FindbyID,
                        &ListStaff::FindbyName,
                        &ListStaff::FindbyTell,
                        &ListStaff::FindbySex,
                        &ListStaff::FindbyCCCD,
                        &ListStaff::FindbyBirthday,
                        &ListStaff::FindbyPermit,
                        &ListStaff::FindbySalary
                    };
                void (ListStaff::*FunctionFilterArr[])() = {
                        &ListStaff::FilterbyInfor,
                        &ListStaff::FilterbySalary   
                    };
                arr = {"ID","NAME","TELL","SEX","CCCD","BIRTHDAY","PERMIT","SALARY"};
                ManagementMenu(list,"STAFF",arr,FunctionSortArr,FunctionFindArr,FunctionFilterArr);
                cout<<"\nBan muon tiep tuc lam viec khonng(1-YES/2-NO)? ";
                cin>>choose; cin.ignore();
                if (choose==1)
                {
                    ManagementMenu(list,"STAFF",arr,FunctionSortArr,FunctionFindArr,FunctionFilterArr); 
                    system("cls");
                }
                break;
            }
            case 2:
            {   ListUser list;
                void (ListUser::*FunctionSortArr[])() = {
                        &ListUser::IncreSortbyID,
                        &ListUser::DecreSortbyID,
                        &ListUser::IncreSortbyName,
                        &ListUser::DecreSortbyName,
                        &ListUser::IncreSortbyTell,
                        &ListUser::DecreSortbyTell,
                        &ListUser::IncreSortbySex,
                        &ListUser::DecreSortbySex,
                        &ListUser::IncreSortbyCCCD,
                        &ListUser::DecreSortbyCCCD,
                        &ListUser::IncreSortbyBirthday,
                        &ListUser::DecreSortbyBirthday,
                        &ListUser::IncreSortbyUsername,
                        &ListUser::DecreSortbyUsername,
                        &ListUser::IncreSortbyRank,
                        &ListUser::DecreSortbyRank
                    };
                void (ListUser::*FunctionFindArr[])() = {
                        &ListUser::FindbyID,
                        &ListUser::FindbyName,
                        &ListUser::FindbyTell,
                        &ListUser::FindbySex,
                        &ListUser::FindbyCCCD,
                        &ListUser::FindbyBirthday,
                        &ListUser::FindbyUsername,
                        &ListUser::FindbyRank
                    };
                void (ListUser::*FunctionFilterArr[])() = {
                        &ListUser::FilterbyInfor,
                        &ListUser::FilterbyRank  
                    };
                arr = {"ID","NAME","TELL","SEX","CCCD","BIRTHDAY","USERNAME","RANK"};
                ManagementMenu(list,"USER",arr,FunctionSortArr,FunctionFindArr,FunctionFilterArr);
                cout<<"\nBan muon tiep tuc lam viec khonng(1-YES/2-NO)? ";
                cin>>choose; cin.ignore();
                if (choose==1)
                {
                    ManagementMenu(list,"USER",arr,FunctionSortArr,FunctionFindArr,FunctionFilterArr); 
                    system("cls");
                }
                break;
            }
            case 3:
            {   ListPC list;
                void (ListPC::*FunctionSortArr[])() = {
                        &ListPC::IncreSortbyID,
                        &ListPC::DecreSortbyID,
                        &ListPC::IncreSortbyName,
                        &ListPC::DecreSortbyName,
                        &ListPC::IncreSortbyModel,
                        &ListPC::DecreSortbyModel,
                        &ListPC::IncreSortbyOperatingSystem,
                        &ListPC::DecreSortbyOperatingSystem,
                        &ListPC::IncreSortbyPrice,
                        &ListPC::DecreSortbyPrice
                    };
                void (ListPC::*FunctionFindArr[])() = {
                        &ListPC::FindbyID,
                        &ListPC::FindbyName,
                        &ListPC::FindbyModel,
                        &ListPC::FindbyOperatingSystem,
                        &ListPC::FindbyPrice,
                    };
                void (ListPC::*FunctionFilterArr[])() = {
                        &ListPC::FilterbyInfor,
                        &ListPC::FilterbyPrice
                };
                arr = {"ID","NAME","MODEL","OPERATINGSYSTEM","PRICE"};
                ManagementMenu(list,"PC",arr,FunctionSortArr,FunctionFindArr,FunctionFilterArr);
                cout<<"\nBan muon tiep tuc lam viec khonng(1-YES/2-NO)? ";
                cin>>choose; cin.ignore();
                if (choose==1)  
                {
                    ManagementMenu(list,"PC",arr,FunctionSortArr,FunctionFindArr,FunctionFilterArr); 
                    system("cls");
                }
                break;
            }
            case 4:
            {   ListBreakfast list;
                void (ListBreakfast::*FunctionSortArr[])() = {
                        &ListBreakfast::IncreSortbyID,
                        &ListBreakfast::DecreSortbyID,
                        &ListBreakfast::IncreSortbyName,
                        &ListBreakfast::DecreSortbyName,
                        &ListBreakfast::IncreSortbyBrand,
                        &ListBreakfast::DecreSortbyBrand,
                        &ListBreakfast::IncreSortbySize,
                        &ListBreakfast::DecreSortbySize,
                        &ListBreakfast::IncreSortbyPrice,
                        &ListBreakfast::DecreSortbyPrice
                    };
                void (ListBreakfast::*FunctionFindArr[])() = {
                        &ListBreakfast::FindbyID,
                        &ListBreakfast::FindbyName,
                        &ListBreakfast::FindbyBrand,
                        &ListBreakfast::FindbySize,
                        &ListBreakfast::FindbyPrice
                    };
                void (ListBreakfast::*FunctionFilterArr[])() = {
                        &ListBreakfast::FilterbyInfor,
                        &ListBreakfast::FilterbyPrice    
                    };
                arr = {"ID","NAME","BRAND","SIZE","PRICE"};
                ManagementMenu(list,"BREAKFAST",arr,FunctionSortArr,FunctionFindArr,FunctionFilterArr);
                cout<<"\nBan muon tiep tuc lam viec khonng(1-YES/2-NO)? ";
                cin>>choose; cin.ignore();
                if (choose==1)
                {
                    ManagementMenu(list,"BREAKFAST",arr,FunctionSortArr,FunctionFindArr,FunctionFilterArr); 
                    system("cls");
                }
                break;
            }
        default:
            break;
        }
        cout<<"\nBan muon tro lai man hinh chinh khonng(1-YES/2-NO)? ";
                cin>>choose; cin.ignore();
                if (choose==1)
                {
                    MainMenu();
                    system("cls");
                }
        return;
    }
    return;
}

template <class T>
void ManagementMenu(T& list,string file, std::vector<string> arr,void(T::*FunctionSortArr[])(), void(T::*FunctionFindArr[])(), void (T::*FunctionFilterArr[])())
{  system("cls");
    int a;
   int choose; int chon; string end;
   list.inList();
   MenuFunctionTable(file);
   cout<<"\n\nMoi ban nhap lua chon: "; cin>>choose; cin.ignore();
   while(choose<1)
   {
       cout << " \nKhong hop le, moi nhap lai";
       cin >> choose; cin.ignore();
   }
    switch (choose)
    {
        case 1:
            system("cls");
            list.GeneralViewList();
            cout<<endl;
            system("pause"); 
            break;
        case 2:
            system("cls");
            list.deleteObject();
            list.exportList("Temporary.txt");
            list.GeneralViewList();
            cout<<"\nBan chac chan muon xoa chu(1-Co/2-Khong)? "; 
            cin>>chon; cin.ignore();
            if (chon==1) list.exportList(file+".txt");
            break;
        case 3:
            system("cls");
            list.insertObject();
            list.exportList("Temporary.txt");
            list.GeneralViewList();
            cout<<"\nBan chac chan muon them chu(1-Co/2-Khong)? "; 
            cin>>chon; cin.ignore();
            if (chon==1) list.exportList(file+".txt");
            break;
        case 4:
            system("cls");
            SortMenu(list,file,arr,FunctionSortArr);
            break;
        case 5:
            system("cls");
            FindMenu(list,file,arr,FunctionFindArr);
            break;
        case 6:
            system("cls");
            end = arr[arr.size()-1];
            arr.clear();
            arr = {"FILTER",end};
            FilterMenu(list,file,arr,FunctionFilterArr);
            break;
        default:
            break;
    }
    return;
}

template<class T>
void SortMenu(T& list, string file, std::vector<string> arr ,void(T::*FunctionSortArr[])())
{
    MenuSortTable(arr);
    cout<<endl<<"\nMoi ban nhap lua chon: ";
    int choose; cin>>choose; cin.ignore();
    if (choose<1||choose>arr.size()*2) return;
    else cout<<"\nMang sau khi loc: ";
    (list.*FunctionSortArr[choose-1])();
    cout<<endl;
    list.GeneralViewList();
    cout<<endl;
    system("pause");
    cout<<"\nBan muon tiep tuc sap xep(1-YES/2-NO)?: "; int chon; cin>>chon; cin.ignore();  
    if(chon==1) SortMenu(list,file,arr,FunctionSortArr);
    return; 
}
template<class T>
void FindMenu(T& list, string file, std::vector<string> arr,void (T::*FunctionFindArr[])())
{
    MenuFindTable(arr);
    cout<<endl<<"\nMoi ban nhap lua chon: ";
    int choose; cin>>choose; cin.ignore();
    if (choose<1||choose>arr.size()) return;
    (list.*FunctionFindArr[choose-1])();
    cout<<endl;
    system("pause");
    cout<<"\nBan muon tiep tuc tim kiem(1-YES/2-NO)?: "; int chon; cin>>chon; cin.ignore();  
    if(chon==1) FindMenu(list,file,arr,FunctionFindArr);
    return;  
}
template<class T>
void FilterMenu(T& list, string file, std::vector<string> arr ,void (T::*FunctionFilterArr[])())
{
    MenuFilterTable(arr);
    cout<<endl<<"\nMoi ban nhap lua chon: ";
    int choose; cin>>choose; cin.ignore();
    if (choose<1||choose>arr.size()) return;
    (list.*FunctionFilterArr[choose-1])();
    cout<<endl;
    system("pause");
    cout<<"\nBan muon tiep tuc loc(1-YES/2-NO)?: "; int chon; cin>>chon; cin.ignore();  
    if(chon==1) FilterMenu(list,file,arr,FunctionFilterArr);
    return;  
}







// TABLE

void MenuFunctionTable(string name)
{
    cout<<endl << "\t\t"; line(49,'_');
    cout<<"\n\t\t| "<< setfill(' ') <<setw(name.length())<<name <<"' MANAGEMENT MENU" << setfill(' ') << setw(name.length()) <<"\t\t|";
    cout<<endl << "\t\t"; line(49,'_');
    cout<< endl << setfill(' ');
    cout<< "\n\t\t|1 " << setw(3) << "|" << "VIEW "<< name << setfill(' ') << setw(30-name.length()) <<"\t \t|"
        << "\n\t\t|2 " << setw(3) << "|" << "DELETE "<< name << setfill(' ') << setw(30-name.length()) << "\t \t|"
        << "\n\t\t|3 " << setw(3) << "|" << "INSERT "<< name << setfill(' ') << setw(30-name.length()) << "\t \t|"
        << "\n\t\t|4 " << setw(3) << "|" << "SORT " << name << setfill(' ') << setw(30-name.length()) << "\t \t|"
        << "\n\t\t|5 " << setw(3) << "|" << "FIND " << name << setfill(' ') << setw(30-name.length()) << "\t \t|" 
        << "\n\t\t|6 " << setw(3) << "|" << "FILTER " << name << setfill(' ') << setw(30-name.length()) << "\t \t|" ;  
    cout<<endl << "\t\t"; line(49,'_');
}

void MenuSortTable(std::vector<string> arr)
{
    int count = 0;
    int stt = 0;
    string str = "SORTING MENU";
    cout<<endl << "\t\t"; line(60,'_');  // THIEU CONG THUC
    cout<<"\n\t\t|\t\t "<<str << setfill(' ') <<setw(30-str.length()) <<"\t\t|";
    cout<<endl << "\t\t"; line(60,'_');
    cout<< endl << setfill(' ');
    while(count<arr.size())
    {
        cout<< "\n\t\t|"<< setw(3) << stt++ + 1  <<" |" << "INCRESORT BY " <<arr[count] <<  setfill(' ') << setw(30-arr[count].length()) <<"\t \t|";
        cout<< "\n\t\t|"<< setw(3) << stt++ + 1  <<" |" << "DECRESORT BY " <<arr[count] <<  setfill(' ') << setw(30-arr[count].length()) <<"\t \t|";
        count++;
    }
    cout<<endl << "\t\t"; line(60,'_');
}

void MenuFindTable(vector<string> arr)
{
    int count = 0;
    cout<<endl << "\t\t"; line(70,'_');
    cout<<"\n\t\t|\t\t\t\t "<<" FIND MENU"  <<"\t\t\t\t|";
    cout<<endl << "\t\t"; line(70,'_');
    cout<< endl << setfill(' ');
    while(count<arr.size())
    {
        cout<< "\n\t\t|"<< setw(3) << count + 1  <<" |" << "FIND BY " <<arr[count] <<  setfill(' ') << setw(40) <<"\t \t|";
        count++;
    }
    cout<<endl << "\t\t"; line(70,'_');
}

void MenuFilterTable(vector<string> arr)
{
    int count = 0;
    cout<<endl << "\t\t"; line(70,'_');
    cout<<"\n\t\t|\t\t\t\t "<<" FILTER MENU"  <<"\t\t\t\t|";
    cout<<endl << "\t\t"; line(70,'_');
    cout<< endl << setfill(' ');
    while(count<arr.size())
    {
        cout<< "\n\t\t|"<< setw(3) << count + 1  <<" |" << "FILTER BY " <<arr[count] <<  setfill(' ') << setw(40) <<"\t \t|";
        count++;
    }
    cout<<endl << "\t\t"; line(70,'_');
}

bool login(string user,string pass)
{
    fstream inf;
    inf.open("Data\\Account.txt", ios::in);
    vector<string> username, passwork;  int count = 0; string readfile;
    while(!inf.eof())
    {
        getline(inf,readfile);
        username.push_back(readfile);
        getline(inf,readfile);
        passwork.push_back(readfile);
    }
    for (int i = 0; i<username.size();i++)
    {
        if (username[i]==user)
           if (passwork[i]==pass) 
           return true;
    }
    return false;
}

void SigninMenu()
{   cout<<"XIN MOI DANG NHAP!";
    string username; string pass;
    cout<<"\nUSERNAME: "; getline(cin,username);
    cout<<"PASSWORK:" ; getline(cin,pass);
    while(login(username,pass)==false)
    {system("cls");
     cout<<"KHONG HOP LE, MOI NHAP LAI!";
     cout<<"\nUSERNAME: "; getline(cin,username);
     cout<<"PASSWORK:" ; getline(cin,pass);
    }
    if (login(username,pass)) MainMenu();
}