#include "Game.h"
#include <windows.h>
#include <ctime>
int row,colum;
int luotchoi = 0;
int ketqua = 0; int dem1 = 0; int dem2 = 0;
char field[HANG][COT];

//MAIN
void X_O()
{   cout<<"\t\t\t (USER MODE) \n\n\n";
	char choose;
	while(1)
    {
	system("cls");
	int chedo;
	chonchedo(chedo);
	if (chedo==1) 
	{ 
		system("cls");
		loading(3);
		khoitao_field(field);
		chedo1(field);
	}
	if (chedo==2) 
	{
		system("cls");
		loading(3);
		khoitao_field(field);
		chedo2(field);
	}
	cout<<"\nContinue(Y/N)?: "; cin>>choose; 
	}
    return;
}
//XU LY HAM
void chonchedo(int &chedo)
{   cout<<"Moi chon che do: "<<"\n(1):PvP"<<"\n(2):PvE"<<endl;
	cout<<"\nChe do: "; cin>>chedo;
	while (chedo<1||chedo>2)
	  {
	  	  cout<<"\nKhong hop le, moi lua chon che do lai: "; cin>>chedo;
	  }
}

void loading(int time)
{
	for (int i = time-1; i>=0; i--)
	  { 
	  	
	  	 cout<<"Loading...("<<i+1<<")";
	  	  Sleep(1000);
	  	 system("cls");
	  }
	 system("cls");
	 system("pause");
	 system("cls");
}
void khoitao_field(char field[][COT])
{  
	for (int i = 0; i<HANG; i++)
	  for (int j = 0; j<COT; j++)
	    {
	    	 field[i][j] = ' ';
		 }
}

bool check_row_colum(char field[][COT], int row, int colum)
{
	bool nhap = true;
	if (row<1|row>3&&colum<1|colum>3) nhap = false;
	if (field[row-1][colum-1]!=' ') nhap = false;
	return nhap;
}

void printfield(char field[][COT])
{
    for (int i = 0; i < HANG; i++)
    {   cout<<"|";
        for (int j = 0; j < COT; j++)
        {
            cout << field[i][j] << '|';
        }
        cout << endl;
    }
}
int checkwin(char field[][COT])
{
	//CHECK DUONG CHEO CHINH
	if (field[0][0]=='X'&&field[1][1]=='X'&field[2][2]=='X') return 1;
	if (field[0][0]=='O'&&field[1][1]=='O'&field[2][2]=='O') return 2;

	//CHECK DUONG CHEO PHU
	if (field[0][2]=='X'&&field[1][1]=='X'&&field[2][0]=='X') return 1;
	if (field[0][2]=='O'&&field[1][1]=='O'&&field[2][0]=='O') return 2;

	//CHECK NGANG
	for (int i = 0; i<HANG; i++)
	{
	  if (field[i][0]=='X'&&field[i][1]=='X'&&field[i][2]=='X') return 1;
	  if (field[i][0]=='O'&&field[i][1]=='O'&&field[i][2]=='O') return 2;
   }  
	//CHECK DOC
	for (int i = 0; i<COT; i++)
	{	  
	  if (field[0][i]=='X'&&field[1][i]=='X'&&field[2][i]=='X') return 1;
	  if (field[0][i]=='O'&&field[1][i]=='O'&&field[2][i]=='O') return 2;
   }
	//
	return 0;
}

void player_turn(char field[][COT])
{  system("cls");
	printfield(field);
	   cout<<"\nMoi nguoi choi nhap vi toa do diem can danh: (x,y)";
	   cout<<"\nx: ";cin>>row;
		cout<<"y: ";cin>>colum;
	   while (check_row_colum(field,row,colum)==false)
	   	{
	   		cout<<"Toa do da nhap khong hop le, moi nhap lai";
	   		cout<<"\nx: ";cin>>row;
	       	cout<<"y: ";cin>>colum;
			}
				if (luotchoi==0) 
		field[row-1][colum-1] = 'X';
		else field[row-1][colum-1] = 'O';
	}


void computer_turn(char field[][COT])
{  
   system("cls");
   printfield(field);
   Sleep(300);
   Sleep(300);
	srand(time(NULL));
	row = rand() % (3 - 1 + 1) + 1;
	colum = rand() % (3 - 1 + 1) + 1;
   while (check_row_colum(field,row,colum)==false)
	   {
	   	row = rand() % (3 - 1) + 1;
	      colum = rand() % (3 - 1) + 1;
		}
	field[row-1][colum-1] = 'O';
		}				


bool batbai_cc(char field[][COT])
{  int count = 0;
   for (int i = 0; i<COT; i++)
     {
     	  if (field[i][i]=='X') count++;
	  }
	if (count==2)
	   {
	   	for (int i = 0; i<COT; i++)
	   	  { 
	   	     if (field[i][i]==' ') 
				   {
					  field[i][i] = 'O';
					  return true;
               }
			  }
		}
	return false;
}


bool batbai_cp(char field[][COT])
{  int count = 0;
   for (int i = 0; i<COT; i++)
	   if (field[i][COT-i-1]=='X') count++; 
	if (count==2)
	 {
	 	  	for (int i = 0; i<COT; i++)
	   	  { 
	   	     if (field[i][COT-i-1]==' ') 
				   {
					  field[i][COT-i-1] = 'O';
					  return true;
               }
			  }
	 }
	return false;
}

bool batbai_ngang(char field[][COT])
{  
   for (int i = 0; i<COT; i++)
	  {  int count = 0;
	    for (int j = 0; j<COT; j++)
		   {
		   	if (field[i][j]=='X') count++;
				  }
	    if (count==2)
	     {
	 	  	for (int j = 0; j<COT; j++) 
	   	     if (field[i][j]==' ') 
				   {
					  field[i][j] = 'O';
					  return true;
               }
	      }
	 }
	return false;
}

bool batbai_doc(char field[][COT])
{  
   for (int i = 0; i<COT; i++)
	  {  int count = 0;
	    for (int j = 0; j<COT; j++)
		   {
		   	if (field[j][i]=='X') count++;
				  }
	    if (count==2)
	     {
	 	  	for (int j = 0; j<COT; j++) 
	   	     if (field[j][i]==' ') 
				   {
					  field[j][i] = 'O';
					  return true;
               }
	      }
	 }
	return false;
}
bool check_prewin(char field[][COT])
{  
   bool stop = false;
   if (stop == false)
   stop = batbai_cc(field);
   if (stop ==false)
   stop = batbai_cp(field);
   if (stop ==false)
   stop = batbai_ngang(field);      
	if (stop ==false)
   stop = batbai_doc(field);
   return stop;
 }


void chedo1(char field[][COT])
{ 
	while (checkwin(field)==0)
   {  
	   printfield(field);
	   cout<<"\nMoi nguoi choi "<<luotchoi+1<<" nhap vi toa do diem can danh: (x,y)";
	   cout<<"\nx: ";cin>>row;
		cout<<"y: ";cin>>colum;
	   while (check_row_colum(field,row,colum)==false)
	   	{
	   		cout<<"Toa do da nhap khong hop le, moi nhap lai";
	   		cout<<"\nx: ";cin>>row;
	       	cout<<"y: ";cin>>colum;
			}
		if (luotchoi==0) 
		field[row-1][colum-1] = 'X';
		else field[row-1][colum-1] = 'O';
		dem1++;
		if (dem1>=9) 
		{
		  cout<<"Van nay hoa; "<<endl;
		  printfield(field);
		  cout<<"\nBat dau van moi: "<<endl; 
		  khoitao_field(field);
		  dem1 = 0;
		}				
	   
		luotchoi = (luotchoi+1)%2;
     }
		   
	cout<<"\nNguoi choi chien thang la: ";
	if (checkwin(field)==1) 
	    {
	   	 cout<<"nguoi choi thu nhat (X)";
		 }
	else 
	     {
	      	cout<<"nguoi choi hai (O)";
		}
	cout<<endl;
	printfield(field);
}

void chedo2(char field[][COT])
{  try{
   bool pre_win = false;
   dem2 = 0;
	while (checkwin(field)==0)
   {  	if (dem2>8) 
		{
		  cout<<"Van nay hoa; "<<endl;
		  printfield(field);
		  cout<<"\nBat dau van moi: "<<endl; 
		  system("pause");
		  khoitao_field(field);
		  dem2 = 0;
		}				
	   if (luotchoi==0)
	     {
	     	  player_turn(field);
		  }
		else 
		  { 
		    pre_win = check_prewin(field);
		    
		  	if (pre_win==false) 
				 computer_turn(field);
			 pre_win = true; 
		  }
		dem2++;
		luotchoi = (luotchoi+1)%2;
     }
	if (checkwin(field)==1)
	  cout<<"\nNguoi choi chien thang ";
   else if (checkwin(field)==2) cout<<"\nMay chien thang";
   cout<<endl;
	printfield(field);
	}catch(exception& e)
	{
		cout<<"\nError!!";
	}
}


