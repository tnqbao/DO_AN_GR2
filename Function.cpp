#include "Function.h"

bool check_substring(std::string substring, std::string text)
{
    int i = 0;
    int j = 0;
    while (i<substring.length()&&j<text.length())
    {
        if (substring[i]==text[j])
        {
            i+=1;
        }
        else 
        {
            i = 0;
        }
        j++;
    }
    return i==substring.length();
}

void line(int number, char line)
{
    
    std::cout <<std::setfill(line) << std::setw(number) << line; 
}

int get_top(std::string rank)
{
    if (rank=="Diamond") return 5;
    else if (rank=="Platinum") return 4;
    else if (rank=="Gold") return 3;
    else if (rank=="Silver") return 2;
    else if (rank=="Bronze") return 1;
    else return 0;
}

int SortPermit(string permit)
{
    if (permit=="Giam Doc") return 10;
    else if (permit=="Quan Ly") return 9;
    else if (permit=="Nhan Vien") return 5;
    else if (permit=="PARTTIME") return 1;
    else return 0;
}

int SortDay(string date1,string date2)
{
    if (stoi(date1.substr(6,4))>stoi(date2.substr(6,4))) return 1;
    else if (stoi(date1.substr(6,4))<stoi(date2.substr(6,4))) return 2;
    if (stoi(date1.substr(3,2))>stoi(date2.substr(3,2))) return 1;
    else if (stoi(date1.substr(3,2))<stoi(date2.substr(3,2))) return 2;
    if (stoi(date1.substr(0,2))>stoi(date2.substr(0,2))) return 1;
    else if (stoi(date1.substr(0,2))<stoi(date2.substr(0,2))) return 2;
    return 0;
}


void title_PC()
{
    std::cout << std::endl<<std::setfill(' ') << std::left <<"|" << std::setw(7) <<  "ID"<<" |"
    << std::setw(30) << "NAME"<<" |"
    << std::setw(12) << "MODEL"<<" |"
    << std::setw(12) << "OS"<<" |"
    << std::setw(20) << "PRICE"<<" |";
}

void title_Breakfast()
{
    std::cout << std::endl<<std::setfill(' ') << std::left <<"|" << std::setw(7) <<  "ID"<<" |"
    << std::setw(30) << "NAME"<<" |"
    << std::setw(35) << "Brand"<<" |"
    << std::setw(7) << "Size"<<" |"
    << std::setw(7) << "Quantity"<<" |"
    << std::setw(12) << "Price" << " |";
}

void choose_option()
{
    cout<<"\n(1.Continue// 2.Back // ELSE.MainMenu):  ";
} 