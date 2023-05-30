#ifndef PERSON_H
#define PERSON_H
#include <bits/stdc++.h>
#include "Function.h"
using namespace std;

class Person
{
    protected:
        string id;
        string name;
        string tell;
        string sex;
        string cccd; 
        string birthday;
    public:
        virtual void input();
        virtual void input(fstream &inf);
        virtual void GeneralView();
        virtual void TypeView();
        virtual void exportList(fstream &inf, string file);
        virtual float get_salary();
        virtual string get_rank();
        virtual string get_Username();
        virtual string get_permit();
        string get_id();
        string get_name();
        string get_tell();
        string get_sex();
        string get_cccd();
        string get_birthday();
        void change_tell(string tell);
        void change_sex(string sex);
        void change_cccd(string cccd);
};

class ListPerson
{
    public:
        vector<Person*> b;
        fstream inf, onf;
        Person *a;
        virtual void inList();
        virtual void GeneralViewList();
        virtual void insertObject();
        virtual void exportList(string file);
        virtual void deleteObject(string text);
        void IncreSortbyID();
        void DecreSortbyID();
        void IncreSortbyName();
        void DecreSortbyName();
        void IncreSortbyTell();
        void DecreSortbyTell();
        void IncreSortbySex();
        void DecreSortbySex();
        void IncreSortbyCCCD();
        void DecreSortbyCCCD();
        void IncreSortbyBirthday();
        void DecreSortbyBirthday();
        void FindbyID();
        void FindbyName();
        void FindbyTell();
        void FindbyBirthday();
        void FindbySex();
        void FindbyCCCD();
        void FilterbyInfor();
};

#endif
