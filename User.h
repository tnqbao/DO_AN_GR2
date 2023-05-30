#ifndef USER_H
#define USER_H
#include "Person.h"

class RegisteredUser : public Person
{
    private:
        string Account_username; // ten tai khoan
        string rank; // cap bac
        string gmail; 
    public:
        RegisteredUser();
        RegisteredUser(string id);
        void input();
        void input(fstream &inf);
        void GeneralView();
        void TypeView();
        void exportList(fstream &inf, string file);
        string get_Username();
        string get_rank();
        string get_gmail();
};

class GuestUser : public Person
{
    private:
        string dateOfPayment; // ngaythanhtoan
        string payments; // tien thanh toan
    public:
        GuestUser();
        GuestUser(string id);
        void input();
        void input(fstream &inf);
        void GeneralView();
        void TypeView();
        void exportList(fstream &inf,string file);
        string get_dateOfPayment();
        string get_rank();
        string get_Username();
        // string get_payments();
};

class ListUser : public ListPerson
{
    public:
        vector<Person*> user;
        ListUser();
        void inList();
        void GeneralViewList();
        void GeneralViewList(vector<Person*> users);
        void exportList(string file);
        void deleteObject();
        void insertObject();
        void IncreSortbyUsername();
        void DecreSortbyUsername();
        void IncreSortbyRank();
        void DecreSortbyRank();
        void FindbyUsername();
        void FindbyRank();
        void FilterbyRank();
};


#endif

