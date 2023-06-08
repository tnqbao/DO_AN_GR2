#ifndef GAME_H
#define GAME_H
#include<bits/stdc++.h>
#define HANG 3
#define COT 3 
using namespace std;

void X_O();
void khoitao_field(char field[][COT]);
void printfield(char field[][COT]);
bool check_row_colum(char field[][COT], int row, int colum);
int checkwin(char field[][COT]);
void chonchedo(int &chedo);
void player_turn(char field[][COT]);
void computer_turn(char field[][COT]);
void chedo1(char field[][COT]);
void chedo2(char field[][COT]);
bool check_prewin(char field[][COT]);
void loading(int time);

#endif
