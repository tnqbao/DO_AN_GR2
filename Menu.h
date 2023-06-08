#ifndef MENU_H
#define MENU_H
#include "Staff.h"
#include "User.h"
#include "Breakfast.h"
#include "Pc.h"
#include "Game.h"
#include <vector>

//INTERFACE MENU
void MainMenu();
template<class T>
void ManagementMenu(T& list,string file,vector<string> arr, void (T::*FunctionSortArr[])(), void (T::*FunctionFindArr[])(), void (T::*FunctionFilterArr[])());
void UserMenu();

//FUNCTION MENU
template<class T>
void SortMenu(T& list, string file,vector<string> arr,void (T::*FunctionSortArr[])());
template<class T>
void FindMenu(T& list, string file,vector<string> arr,void (T::*FunctionFindArr[])());
template<class T>
void FilterMenu(T& list, string file,vector<string> arr,void (T::*FunctionFilterArr[])());
bool Login();
void SigninMenu();
void MenuFunctionTable(string name);
void MenuSortTable(vector<string> arr);
void MenuFindTable(vector<string> arr);
void MenuFilterTable(vector<string>arr);
#endif 
