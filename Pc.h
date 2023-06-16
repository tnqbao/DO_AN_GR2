#ifndef PC_H
#define PC_H
#include <bits/stdc++.h>
#include "Function.h"
using namespace std;

class PC
{
    protected:
        string id;
        string name;
        string model;
        string operatingSystem; 
        double price;
    public:
        virtual void input();
        virtual void input(fstream &inf);
        virtual void GeneralView();
        virtual void TypeView();
        virtual void exportList(fstream &inf, string file);
        string get_id();
        string get_name();
        string get_model();
        string get_operatingSystem();
        virtual double calculatePrice();
        void change_id(string id);
        void change_name(string name);
        void change_price(double price);
};

class Laptop : public PC
{
    private:
        double basic_price;
        string brand;
        bool bluetooh;
        bool wifi;
        bool webcam;
        double battery;
    public:
        Laptop();
        Laptop(string id);
        void input();
        void input(fstream &inf);
        void GeneralView();
        void TypeView();
        void exportList(fstream &inf,string file);
        double calculatePrice();
        double get_battery();
        double get_basicPrice();
        void change_battery(double battery);
        void change_Price(double Price);
};

class TabletPC : public PC
{
    private: 
        string processor;
        string graphicsCard; 
        int NumerConnectivity; 
        double basic_price;
    public:
        TabletPC();
        TabletPC(string id);
        void input();
        void input(fstream &inf);
        void GeneralView();
        void TypeView();
        void exportList(fstream &inf,string file);
        double calculatePrice();
        string get_processor();
        string get_graphicsCard();
        int get_NumberConnetivity();
};


class ListPC
{
    public:
        vector<PC*> list;
        vector<PC*> pc;
        fstream inf, onf;
        PC *a;
        ListPC();
        void inList();
        void GeneralViewList();
        void GeneralViewList(vector<PC*>);
        void insertObject();
        void exportList(string file);
        void deleteObject();
        void IncreSortbyID();
        void DecreSortbyID();
        void IncreSortbyName();
        void DecreSortbyName();
        void IncreSortbyModel();
        void DecreSortbyModel();
        void IncreSortbyOperatingSystem();
        void DecreSortbyOperatingSystem();
        void IncreSortbyPrice();
        void DecreSortbyPrice();
        void FindbyID();
        void FindbyName();
        void FindbyModel();
        void FindbyOperatingSystem();
        void FindbyPrice();
        void FilterbyInfor();
        void FilterbyPrice();
};


#endif

