#ifndef BREAKFAST_H
#define BREAKFAST_H
#include <bits/stdc++.h>
#include "Function.h"
using namespace std;
class Breakfast
{
    private:
        string id;
        string name;
        string brand;
        double basic_price;
        double price;
        string size;
        int quantity;
    public:
        Breakfast();
        void input();
        void input(fstream &inf);
        void inputFilter();
        void View();
        void exportList(fstream &inf);
        double calculatePrice();
        string get_id();
        string get_name();
        string get_brand();
        double get_basicPrice();
        int get_size();
        int get_quantity();
};

class ListBreakfast
{
    public:
        vector<Breakfast> list;
        vector<Breakfast> food;
        fstream inf, onf;
        Breakfast a;
        ListBreakfast();
        void inList();
        void GeneralViewList();
        void GeneralViewList(vector<Breakfast> food);
        void insertObject();
        void exportList(string file);
        void deleteObject();
        void IncreSortbyID();
        void DecreSortbyID();
        void IncreSortbyName();
        void DecreSortbyName();
        void IncreSortbyBrand();
        void DecreSortbyBrand();
        void IncreSortbySize();
        void DecreSortbySize();
        void IncreSortbyPrice();
        void DecreSortbyPrice();
        void FindbyID();
        void FindbyName();
        void FindbyBrand();
        void FindbySize();
        void FindbyPrice();
        void FilterbyInfor();
        void FilterbyPrice();
};
#endif