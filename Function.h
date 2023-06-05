#ifndef FUNCTION_H
#define FUNCTION_H

#include <bits/stdc++.h>
#include <string>
using namespace std;

bool check_substring(std::string substring, std::string text); // kiem tra chuoi con
void line(int number, char line); // ke duong ke ngang
int get_top(std::string rank); // tra ve gia tri dua tren xep hang
int SortPermit(string permit);
int SortDay(string date1, string date2);
template<class T>
void Sort(vector<T> a, void (*Function)());
void title_PC();
void title_Breakfast();
void choose_option(); 
int strtoint(string str);
#endif  


