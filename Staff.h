#ifndef STAFF_H
#define STAFF_H

#include <bits/stdc++.h>
#include "Person.h"

class ContractStaff  : public Person
{
    private:
        string permit; //quy?n h?n, ch?c v?
        float basic_salary; // luong co b?n
        float bonus; //thu?ng th�m
        float salary; //luong th�ng
    public:
        ContractStaff();
        ContractStaff(string id);
        void input();
        void input(fstream &inf);
        void GeneralView();
        void TypeView();
        void exportList(fstream &inf,string file);
        float find_bonus();
        float calculate_salary();
        float get_salary();
        string get_permit();
        void change_basicsalary(float basic_salary);
        void change_permit(string permit);
};

class RegularStaff  : public Person
{
    private:
        float basic_salary; 
        int workday; // ng�y c�ng
        float salary;
    public:
        RegularStaff();
        RegularStaff(string id);
        void input();
        void input(fstream &inf);
        void GeneralView();
        void TypeView();
        void exportList(fstream &inf,string file);
        float calculate_salary();
        float get_salary();
        string get_permit();
        void change_basicsalary(float basic_salary);
        void change_workday(int workday);
};

class ListStaff : public ListPerson
{
    public:
        vector<Person*> staff;
        ListStaff();
        void inList();
        void GeneralViewList();
        void GeneralViewList(vector <Person*> staff);
        void exportList(string file);
        void deleteObject();
        void insertObject();
        void IncreSortbySalary();
        void DecreSortbySalary();
        void IncreSortbyPermit();
        void DecreSortbyPermit();
        void FindbySalary();
        void FindbyPermit();
        void TotalOfSalary();
        void FilterbySalary();
};

#endif
