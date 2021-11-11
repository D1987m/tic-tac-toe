#include<stdio.h>
#include<windows.h>
const int m=7;
const int n=5;
void XOSelection(int *ig,int *com, char name[]);
void GameField(int mas[][n]);
void HodIgr(int ig,int mas[][n]);
void  DisplayingTheStroke(int mas[][n]);
void HodCom(int ig,int com,int mas[][n]);
void SGame(int *StopGame,int com,int ig,int mas[][n]);
void checkHorCom(int *flag,int jcol, int com, int mas[][n]);
void checkHorCom1(int *flag,int jcol, int com, int mas[][n]);
void checkHorIg(int *flag,int jcol,int ig, int com, int mas[][n]);
void checkHorIg1(int *flag,int jcol,int ig, int com, int mas[][n]);
void checkVerCom(int *flag,int istr, int com, int mas[][n]);
void checkVerCom1(int *flag,int istr, int com, int mas[][n]);
void checkVerIg(int *flag,int istr,int ig, int com, int mas[][n]);
void checkVerIg1(int *flag,int istr,int ig, int com, int mas[][n]);
void checkDiag1Com(int *flag,int jcol, int com, int mas[][n]);
void checkDiag1Com1(int *flag,int jcol, int com, int mas[][n]);
void checkDiag2Com(int *flag,int jcol, int com, int mas[][n]);
void checkDiag2Com2(int *flag,int jcol, int com, int mas[][n]);
void checkDiag1Ig(int *flag,int jcol,int ig, int com, int mas[][n]);
void checkDiag1Ig1(int *flag,int jcol,int ig, int com, int mas[][n]);
void checkDiag2Ig(int *flag,int jcol,int ig, int com, int mas[][n]);
void checkDiag2Ig2(int *flag,int jcol,int ig, int com, int mas[][n]);
void InspectionHorCom(int **StopGame,int jcol, int com, int mas[][n]);
void InspectionVerCom(int **StopGame,int istr, int com, int mas[][n]);
void InspectionDiag1Com(int **StopGame,int jcol, int com, int mas[][n]);
void InspectionDiag2Com(int **StopGame,int jcol, int com, int mas[][n]);
void InspectionkHorIg(int **StopGame,int jcol,int ig, int com, int mas[][n]);
void InspectionVerIg(int **StopGame, int istr,int ig, int com, int mas[][n]);
void InspectionDiag1Ig(int **StopGame,int jcol,int ig, int com, int mas[][n]);
void InspectionDiag2Ig(int **StopGame,int jcol,int ig, int com, int mas[][n]);
main(){
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int mas[m][n],ig,com,StopGame=0;
    char name[20];
    printf("КРЕСТИКИ-НОЛИКИ\n");
    printf("Имя игрока: ");
    gets(name);
    XOSelection(&ig,&com,name);
    GameField(mas);
    while(StopGame==0){
    HodIgr(ig,mas);
    DisplayingTheStroke(mas);
    SGame(&StopGame,com,ig,mas);
    HodCom(ig,com,mas);
    DisplayingTheStroke(mas);
    SGame(&StopGame,com, ig, mas);
}
    printf("\n");
    if(StopGame==1){printf("%s ,Вы проиграли!", name);}
    else if(StopGame==2){printf("%s, Вы выиграли!",name);}
    else if(StopGame==3){printf("%s, у Вас ничья!",name);}
}
//Выбор игрока чем инрать
void XOSelection(int *ig,int *com,char name[]){
	*com=0;
	while(*com==0){	
	printf("%s, если хитите играть '0', нажмите 1.\n", name);
	printf("      Если хотите играть 'X', нажмите 2.\n",name);
	scanf("%i",&*ig);
	fflush(stdin);
	if(*ig==1){
		*com=2;
	}
	 if(*ig==2){
		*com=1;
	}
        }
        }
//Вывод игрового поля
void GameField( int mas[][n]){
	system("cls");
	int i,j;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	printf("КРЕСТИКИ-НОЛИКИ\n");
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	printf("  1  2  3  4  5\n");
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	for(i=0;i<m;i++){
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	printf ("%i",i+1);
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	for(j=0;j<n;j++){
		mas[i][j]=0;
	        SetConsoleTextAttribute(console, FOREGROUND_GREEN| FOREGROUND_RED);
		printf("[ ]",mas[i][j]);
		}
		printf("\n");	
	        } 
	         SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
                }
//Ход игрока
 void HodIgr(int ig,int mas[][n])
 {
int i,j,flag=0,col,str;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
while(flag==0){
printf("\n");	
printf("Укажите координаты ячейки\n");
printf("Строка:");
scanf("%i",&str);
fflush(stdin);
printf("Столбец:");
scanf("%i",&col);
fflush(stdin);
        for(i=0;i<m;i++){
        for(j=0;j<n;j++){
	  if(((str>=1&&str<=7)&&(col>=1&&col<=5))&&(mas[str-1][col-1]==0)){
	  flag=1;
	}	
	}
	}
	if(flag==0){
	SetConsoleTextAttribute(console, FOREGROUND_RED);
    printf("\nНекорректный ввод координат!\n\n");
   	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    
	}
        }
	for(i=0;i<m;i++){
	for(j=0;j<n;j++){
	mas[str-1][col-1]=ig;	
        }
        }   
        }
//Вывод сделанного хода
 void DisplayingTheStroke (int mas[][n]){
 	    system("cls");
    	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    	int i,j;
    	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
    	printf("КРЕСТИКИ-НОЛИКИ\n");
    	printf("  1  2  3  4  5\n");
    	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        for(i=0;i<m;i++){
 	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
 	printf ("%i",i+1);
 	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
 	for(j=0;j<n;j++){
    	if(mas[i][j]==0){
 	SetConsoleTextAttribute(console, FOREGROUND_GREEN| FOREGROUND_RED);
 		printf("[ ]");
 		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		 }
		 if(mas[i][j]==1){
		 SetConsoleTextAttribute(console, FOREGROUND_RED);
 		 printf("[O]");
 		 SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		 }
		 if(mas[i][j]==2){
		 SetConsoleTextAttribute(console, FOREGROUND_BLUE);
 		 printf("[X]");
 		 SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		 }
               	 }
	         printf("\n");
	         }
                 }
void checkHorCom(int *flag,int jcol, int com, int mas[][n])
{
int i=0,j;
while(i<7&&*flag==0){
for(j=jcol;j<jcol+4;j++){
if(mas[i][jcol]==com&&mas[i][jcol+1]==com&&mas[i][jcol+2]==com&&mas[i][jcol+3]==0&&*flag==0){
   mas[i][jcol+3]=com;*flag=1;return;}
if(mas[i][jcol]==com&&mas[i][jcol+1]==com&&mas[i][jcol+2]==0&&mas[i][jcol+3]==com&&*flag==0){
   mas[i][jcol+2]=com;*flag=1;return;}
if(mas[i][jcol]==com&&mas[i][jcol+1]==0&&mas[i][jcol+2]==com&&mas[i][jcol+3]==com&&*flag==0){
   mas[i][jcol+1]=com;*flag=1;return;}
if(mas[i][jcol]==0&&mas[i][jcol+1]==com&&mas[i][jcol+2]==com&&mas[i][jcol+3]==com&&*flag==0){
   mas[i][jcol]=com;*flag=1;return;}	 	 
 }
	i++;
 }
 }
void checkHorIg(int *flag,int jcol,int ig, int com, int mas[][n])
{
int i=0, j;
while(i<7&&*flag==0){
for(j=jcol;j<4+jcol;j++){
if(mas[i][jcol]==ig&&mas[i][jcol+1]==ig&&mas[i][jcol+2]==ig&&mas[i][jcol+3]==0&&*flag==0){
   mas[i][jcol+3]=com;*flag=1;return;}
if(mas[i][jcol]==ig&&mas[i][jcol+1]==ig&&mas[i][jcol+2]==0&&mas[i][jcol+3]==ig&&*flag==0){
   mas[i][jcol+2]=com;*flag=1;return;}
if(mas[i][jcol]==ig&&mas[i][jcol+1]==0&&mas[i][jcol+2]==ig&&mas[i][jcol+3]==ig&&*flag==0){
   mas[i][jcol+1]=com;*flag=1;return;}
if(mas[i][j]==0&&mas[i][jcol+1]==ig&&mas[i][jcol+2]==ig&&mas[i][jcol+3]==ig&&*flag==0){
   mas[i][jcol]=com;*flag=1;return;}
	 	 
}
   i++;
}
}
void checkVerCom(int *flag,int istr, int com, int mas[][n])
{
int j=0,i;
while(j<5&&*flag==0){
for(i=istr;i<istr+4;i++){
if(mas[istr][j]==com&&mas[istr+1][j]==com&&mas[istr+2][j]==com&&mas[istr+3][j]==0&&*flag==0){
   mas[istr+3][j]=com;*flag=1;return;}
if(mas[istr][j]==com&&mas[istr+1][j]==com&&mas[istr+2][j]==0&&mas[istr+3][j]==com&&*flag==0){
   mas[istr+2][j]=com;*flag=1;return;}
if(mas[istr][j]==com&&mas[istr+1][j]==0&&mas[istr+2][j]==com&&mas[istr+3][j]==com&&*flag==0){
  mas[istr+1][j]=com;*flag=1;return;}
if(mas[istr][j]==0&&mas[istr+1][j]==com&&mas[istr+2][j]==com&&mas[istr+3][j]==com&&*flag==0){
   mas[istr][j]=com;*flag=1;return;}	 	 
}
   j++;
}	
}
void checkVerIg(int *flag,int istr,int ig, int com, int mas[][n])
{
  int j=0,i;
  while(j<5&&*flag==0){
  for(i=istr;i<istr+4;i++){
  if(mas[istr][j]==ig&&mas[istr+1][j]==ig&&mas[istr+2][j]==ig&&mas[istr+3][j]==0&&*flag==0){
     mas[istr+3][j]=com;*flag=1;return;}
  if(mas[istr][j]==ig&&mas[istr+1][j]==ig&&mas[istr+2][j]==0&&mas[istr+3][j]==ig&&*flag==0){
     mas[istr+2][j]=com;*flag=1;return;}
  if(mas[istr][j]==ig&&mas[istr+1][j]==0&&mas[istr+2][j]==ig&&mas[istr+3][j]==ig&&*flag==0){
     mas[istr+1][j]=com;*flag=1;return;}
  if(mas[istr][j]==0&&mas[istr+1][j]==ig&&mas[istr+2][j]==ig&&mas[istr+3][j]==ig&&*flag==0){
     mas[istr][j]=com;*flag=1;return;}	 	 
}
   j++;
}
}
    void checkDiag1Com(int *flag,int jcol, int com, int mas[][n])
 {
  int j=jcol,i;
  while(j<4+jcol&&*flag==0){
  for(i=0;i<4;i++){
  if(mas[i][jcol]==com&&mas[i+1][jcol+1]==com&&mas[i+2][jcol+2]==com&&mas[i+3][jcol+3]==0&&*flag==0){
     mas[i+3][jcol+3]=com;*flag=1;return;}
  if(mas[i][jcol]==com&&mas[i+1][jcol+1]==com&&mas[i+2][jcol+2]==0&&mas[i+3][jcol+3]==com&&*flag==0){
     mas[i+2][jcol+2]=com;*flag=1;return;}
  if(mas[i][jcol]==com&&mas[i+1][jcol+1]==0&&mas[i+2][jcol+2]==com&&mas[i+3][jcol+3]==com&&*flag==0){
     mas[i+1][jcol+1]=com;*flag=1;return;}
  if(mas[i][jcol]==0&&mas[i+1][jcol+1]==com&&mas[i+2][jcol+2]==com&&mas[i+3][jcol+3]==com&&*flag==0){
     mas[i][jcol]=com;*flag=1;return;}
   }
	j++;
   }
   }
  void checkDiag2Com(int *flag,int jcol, int com, int mas[][n])
  {
  int j=jcol,i;
  while(j<4+jcol&&*flag==0){
  for(i=6;i>=3;i--){
  if(mas[i][jcol]==com&&mas[i-1][jcol+1]==com&&mas[i-2][jcol+2]==com&&mas[i-3][jcol+3]==0&&*flag==0){
     mas[i-3][jcol+3]=com;*flag=1;return;}
  if(mas[i][jcol]==com&&mas[i-1][jcol+1]==com&&mas[i-2][jcol+2]==0&&mas[i-3][jcol+3]==com&&*flag==0){
     mas[i-2][jcol+2]=com;*flag=1;return;}
  if(mas[i][jcol]==com&&mas[i-1][jcol+1]==0&&mas[i-2][jcol+2]==com&&mas[i-3][jcol+3]==com&&*flag==0){
     mas[i-1][jcol+1]=com;*flag=1;return;}
  if(mas[i][jcol]==0&&mas[i-1][jcol+1]==com&&mas[i-2][jcol+2]==com&&mas[i-3][jcol+3]==com&&*flag==0){
     mas[i][jcol]=com;*flag=1;return;}
    }
       j++;
    }
    }
void checkDiag1Ig(int *flag,int jcol,int ig, int com, int mas[][n])
{
 int j=jcol,i;
 while(j<4+jcol&&*flag==0){
 for(i=0;i<4;i++){
 if(mas[i][jcol]==ig&&mas[i+1][jcol+1]==ig&&mas[i+2][jcol+2]==ig&&mas[i+3][jcol+3]==0&&*flag==0){
    mas[i+3][jcol+3]=com;*flag=1;return;}
 if(mas[i][jcol]==ig&&mas[i+1][jcol+1]==ig&&mas[i+2][jcol+2]==0&&mas[i+3][jcol+3]==ig&&*flag==0){
    mas[i+2][jcol+2]=com;*flag=1;return;}
 if(mas[i][jcol]==ig&&mas[i+1][jcol+1]==0&&mas[i+2][jcol+2]==ig&&mas[i+3][jcol+3]==ig&&*flag==0){
    mas[i+1][jcol+1]=com;*flag=1;return;}
 if(mas[i][jcol]==0&&mas[i+1][jcol+1]==ig&&mas[i+2][jcol+2]==ig&&mas[i+3][jcol+3]==ig&&*flag==0){
    mas[i][jcol]=com;*flag=1;return;}
    }
	j++;
    }	
    }
void checkDiag2Ig(int *flag,int jcol,int ig, int com, int mas[][n])
{
  int j=jcol,i;
    while(j<4+jcol&&*flag==0){
      for(i=6;i>=3;i--){
    if(mas[i][jcol]==ig&&mas[i-1][jcol+1]==ig&&mas[i-2][jcol+2]==ig&&mas[i-3][jcol+3]==0&&*flag==0){
         mas[i-3][jcol+3]=com;*flag=1;return;}
    if(mas[i][jcol]==ig&&mas[i-1][jcol+1]==ig&&mas[i-2][jcol+2]==0&&mas[i-3][jcol+3]==ig&&*flag==0){
         mas[i-2][jcol+2]=com;*flag=1;return;}
    if(mas[i][jcol]==ig&&mas[i-1][jcol+1]==0&&mas[i-2][jcol+2]==ig&&mas[i-3][jcol+3]==ig&&*flag==0){
         mas[i-1][jcol+1]=com;*flag=1;return;}
    if(mas[i][jcol]==0&&mas[i-1][jcol+1]==ig&&mas[i-2][jcol+2]==ig&&mas[i-3][jcol+3]==ig&&*flag==0){
         mas[i][jcol]=com;*flag=1;return;}
 }
  j++;
 }
 }
void checkHorCom1(int *flag,int jcol, int com, int mas[][n])
{
   int i=0,j;
   while(i<7&&*flag==0){
   for(j=jcol;j<4+jcol;j++){
   if(mas[i][jcol]==0&&mas[i][jcol+1]==com&&mas[i][jcol+2]==com&&mas[i][jcol+3]==0&&*flag==0){
      mas[i][jcol+3]=com;*flag=1;return;}
   if(mas[i][jcol]==0&&mas[i][jcol+1]==com&&mas[i][jcol+2]==0&&mas[i][jcol+3]==com&&*flag==0){
      mas[i][jcol+2]=com;*flag=1;return;}
   if(mas[i][jcol]==0&&mas[i][jcol+1]==0&&mas[i][jcol+2]==com&&mas[i][jcol+3]==com&&*flag==0){
      mas[i][jcol+1]=com;*flag=1;return;}
   if(mas[i][jcol]==com&&mas[i][jcol+1]==com&&mas[i][jcol+2]==0&&mas[i][jcol+3]==0&&*flag==0){
      mas[i][jcol+2]=com;*flag=1;return;}	
   if(mas[i][jcol]==com&&mas[i][jcol+1]==0&&mas[i][jcol+2]==com&&mas[i][jcol+3]==0&&flag==0){
      mas[i][jcol+1]=com;*flag=1;return;} 	
   if(mas[i][jcol]==com&&mas[i][jcol+1]==0&&mas[i][jcol+2]==0&&mas[i][jcol+3]==com&&flag==0){
      mas[i][jcol+1]=com;*flag=1;return;} 	
		  
		}
		i++;
		}	
}
void checkVerCom1(int *flag,int istr, int com, int mas[][n])
{
 int j=0,i;
 while(j<5&&*flag==0)
 {
 for(i=istr;i<4+istr;i++){
 if(mas[istr][j]==0&&mas[istr+1][j]==com&&mas[istr+2][j]==com&&mas[istr+3][j]==0&&*flag==0){
    mas[istr+3][j]=com;*flag=1;return;}
 if(mas[istr][j]==0&&mas[istr+1][j]==com&&mas[istr+2][j]==0&&mas[istr+3][j]==com&&*flag==0){
    mas[istr+2][j]=com;*flag=1;return;}
 if(mas[istr][j]==0&&mas[istr+1][j]==0&&mas[istr+2][j]==com&&mas[istr+3][j]==com&&*flag==0){
    mas[istr+1][j]=com;*flag=1;return;}
 if(mas[istr][j]==com&&mas[istr+1][j]==com&&mas[istr+2][j]==0&&mas[istr+3][j]==0&&*flag==0){
   mas[istr+2][j]=com;*flag=1;return;}	
 if(mas[istr][j]==com&&mas[istr+1][j]==0&&mas[istr+2][j]==com&&mas[istr+3][j]==0&&*flag==0){
    mas[istr+1][j]=com;*flag=1;return;}	 
  if(mas[istr][j]==com&&mas[istr+1][j]==0&&mas[istr+2][j]==0&&mas[istr+3][j]==com&&*flag==0){
     mas[istr+1][j]=com;*flag=1;return;}
  }
	j++;
  }
	
  }
  void checkDiag1Com1(int *flag,int jcol, int com, int mas[][n])
  {
   int j=jcol,i;
   while(j<4+jcol&&*flag==0){
   for(i=0;i<4;i++){
   if(mas[i][jcol]==0&&mas[i+1][jcol+1]==com&&mas[i+2][jcol+2]==com&&mas[i+3][jcol+3]==0&&*flag==0){
      mas[i+3][jcol+3]=com;*flag=1;return;}
   if(mas[i][jcol]==0&&mas[i+1][jcol+1]==com&&mas[i+2][jcol+2]==0&&mas[i+3][jcol+3]==com&&*flag==0){
      mas[i+2][jcol+2]=com;*flag=1;return;}
   if(mas[i][jcol]==0&&mas[i+1][jcol+1]==0&&mas[i+2][jcol+2]==com&&mas[i+3][jcol+3]==com&&*flag==0){
      mas[i+1][jcol+1]=com;*flag=1;return;}
   if(mas[i][jcol]==com&&mas[i+1][jcol+1]==com&&mas[i+2][jcol+2]==0&&mas[i+3][jcol+3]==0&&*flag==0){
      mas[i+2][jcol+2]=com;*flag=1;return;}
   if(mas[i][jcol]==com&&mas[i+1][jcol+1]==0&&mas[i+2][jcol+2]==com&&mas[i+3][jcol+3]==0&&*flag==0){
      mas[i+1][jcol+1]=com;*flag=1;return;}
   if(mas[i][jcol]==com&&mas[i+1][jcol+1]==0&&mas[i+2][jcol+2]==0&&mas[i+3][jcol+3]==com&&*flag==0){
      mas[i+1][jcol+1]=com;*flag=1;return;}
     }
	j++;
     }	
     }
     void checkDiag2Com2(int *flag,int jcol, int com, int mas[][n])
     {
	int j=jcol,i;
	 while(j<4+jcol&&*flag==0){
    	 for(i=6;i>=3;i--){
	 if(mas[i][jcol]==0&&mas[i-1][jcol+1]==com&&mas[i-2][jcol+2]==com&&mas[i-3][jcol+3]==0&&*flag==0){
            mas[i-3][jcol+3]=com;*flag=1;return;}
	 if(mas[i][jcol]==0&&mas[i-1][jcol+1]==com&&mas[i-2][jcol+2]==0&&mas[i-3][jcol+3]==com&&*flag==0){
	    mas[i-2][jcol+2]=com;*flag=1;return;}
	 if(mas[i][jcol]==0&&mas[i-1][jcol+1]==0&&mas[i-2][jcol+2]==com&&mas[i-3][jcol+3]==com&&*flag==0){
	    mas[i-1][jcol+1]=com;*flag=1;return;}
	 if(mas[i][jcol]==com&&mas[i-1][jcol+1]==com&&mas[i-2][jcol+2]==0&&mas[i-3][jcol+3]==0&&*flag==0){
            mas[i-2][jcol+2]=com;*flag=1;return;}
	 if(mas[i][jcol]==com&&mas[i-1][jcol+1]==0&&mas[i-2][jcol+2]==com&&mas[i-3][jcol+3]==0&&*flag==0){
	     mas[i-1][jcol+1]=com;*flag=1;return;}
	 if(mas[i][jcol]==com&&mas[i-1][jcol+1]==0&&mas[i-2][jcol+2]==0&&mas[i-3][jcol+3]==com&&*flag==0){
	     mas[i-1][jcol+1]=com;*flag=1;return;}
	}
	  j++;
        }
	}
	void checkHorIg1(int *flag,int jcol,int ig, int com, int mas[][n])
	{
	int i=0,j;
	while(i<7&&*flag==0){
	for(j=jcol;j<4+jcol;j++){
        if(mas[i][jcol]==0&&mas[i][jcol+1]==ig&&mas[i][jcol+2]==ig&&mas[i][jcol+3]==0&&*flag==0){
	   mas[i][jcol+3]=com;*flag=1;return;}
	if(mas[i][jcol]==0&&mas[i][jcol+1]==ig&&mas[i][jcol+2]==0&&mas[i][jcol+3]==ig&&*flag==0){
	   mas[i][jcol+2]=com;*flag=1;return;}
	if(mas[i][jcol]==0&&mas[i][jcol+1]==0&&mas[i][jcol+2]==ig&&mas[i][jcol+3]==ig&&*flag==0){
	   mas[i][jcol+1]=com;*flag=1;return;}
	if(mas[i][jcol]==ig&&mas[i][jcol+1]==ig&&mas[i][jcol+2]==0&&mas[i][jcol+3]==0&&*flag==0){
	   mas[i][jcol+2]=com;*flag=1;return;}
	if(mas[i][jcol]==ig&&mas[i][jcol+1]==0&&mas[i][jcol+2]==ig&&mas[i][jcol+3]==0&&*flag==0){
	   mas[i][jcol+1]=com;*flag=1;return;}
    	if(mas[i][jcol]==ig&&mas[i][jcol+1]==0&&mas[i][jcol+2]==0&&mas[i][jcol+3]==ig&&*flag==0){
	   mas[i][jcol+1]=com;*flag=1;return;}	 	
		  
	  }
		i++;
	  }
    	  }
	void checkVerIg1(int *flag,int istr,int ig, int com, int mas[][n])
	  {
	  int j=0,i;
	  while(j<5&&*flag==0){
	  for(i=istr;i<4+istr;i++){
	  if(mas[istr][j]==0&&mas[istr+1][j]==ig&&mas[istr+2][j]==ig&&mas[istr+3][j]==0&&*flag==0){
	     mas[istr+3][j]=com;*flag=1;return;}
	  if(mas[istr][j]==0&&mas[istr+1][j]==ig&&mas[istr+2][j]==0&&mas[istr+3][j]==ig&&*flag==0){
	     mas[istr+2][j]=com;*flag=1;return;}
	  if(mas[istr][j]==0&&mas[istr+1][j]==0&&mas[istr+2][j]==ig&&mas[istr+3][j]==ig&&*flag==0){
	     mas[istr+1][j]=com;*flag=1;return;}
	  if(mas[istr][j]==ig&&mas[istr+1][j]==ig&&mas[istr+2][j]==0&&mas[istr+3][j]==0&&*flag==0){
	     mas[istr+3][j]=com;*flag=1;return;}
	  if(mas[istr][j]==ig&&mas[istr+1][j]==0&&mas[istr+2][j]==ig&&mas[istr+3][j]==0&&*flag==0){
	     mas[istr+1][j]=com;*flag=1;return;}
	  if(mas[istr][j]==ig&&mas[istr+1][j]==0&&mas[istr+2][j]==0&&mas[istr+3][j]==ig&&*flag==0){
	     mas[istr+1][j]=com;*flag=1;return;}
	    }
		j++;
	    }
	    }
	void checkDiag1Ig1(int *flag,int jcol,int ig, int com, int mas[][n])
	{
	int j=jcol,i;
	while(j<4+jcol&&*flag==0){
    	for(i=0;i<4;i++){
	if(mas[i][jcol]==0&&mas[i+1][jcol+1]==ig&&mas[i+2][jcol+2]==ig&&mas[i+3][jcol+3]==0&&*flag==0){
           mas[i+3][jcol+3]=com;*flag=1;return;}
	if(mas[i][jcol]==0&&mas[i+1][jcol+1]==ig&&mas[i+2][jcol+2]==0&&mas[i+3][jcol+3]==ig&&*flag==0){
           mas[i+2][jcol+2]=com;*flag=1;return;}
	if(mas[i][jcol]==0&&mas[i+1][jcol+1]==0&&mas[i+2][jcol+2]==ig&&mas[i+3][jcol+3]==ig&&*flag==0){
	   mas[i+1][jcol+1]=com;*flag=1;return;}
	if(mas[i][jcol]==ig&&mas[i+1][jcol+1]==ig&&mas[i+2][jcol+2]==0&&mas[i+3][jcol+3]==0&&*flag==0){
           mas[i+2][jcol+2]=com;*flag=1;return;}	
	if(mas[i][jcol]==ig&&mas[i+1][jcol+1]==0&&mas[i+2][jcol+2]==ig&&mas[i+3][jcol+3]==0&&*flag==0){
           mas[i+1][jcol+1]=com;*flag=1;return;}	   
	if(mas[i][jcol]==ig&&mas[i+1][jcol+1]==0&&mas[i+2][jcol+2]==0&&mas[i+3][jcol+3]==ig&&*flag==0){
	   mas[i+1][jcol+1]=com;*flag=1;return;}	  
	}
	    j++;
	}
        }
    void checkDiag2Ig2(int *flag,int jcol,int ig, int com, int mas[][n])
	{
	 int j=jcol,i;
	 while(j<4+jcol&&*flag==0){
    	 for(i=6;i>=3;i--){
	 if(mas[i][jcol]==0&&mas[i-1][jcol+1]==ig&&mas[i-2][jcol+2]==ig&&mas[i-3][jcol+3]==0&&*flag==0){
            mas[i-3][jcol+3]=com;*flag=1;return;}
	 if(mas[i][jcol]==0&&mas[i-1][jcol+1]==ig&&mas[i-2][jcol+2]==0&&mas[i-3][jcol+3]==ig&&*flag==0){
	    mas[i-2][jcol+2]=com;*flag=1;return;}
	 if(mas[i][jcol]==0&&mas[i-1][jcol+1]==0&&mas[i-2][jcol+2]==ig&&mas[i-3][jcol+3]==ig&&*flag==0){
	    mas[i-1][jcol+1]=com;*flag=1;return;}
         if(mas[i][jcol]==ig&&mas[i-1][jcol+1]==ig&&mas[i-2][jcol+2]==0&&mas[i-3][jcol+3]==0&&*flag==0){
	    mas[i-2][jcol+2]=com;*flag=1;return;}
	 if(mas[i][jcol]==ig&&mas[i-1][jcol+1]==0&&mas[i-2][jcol+2]==ig&&mas[i-3][jcol+3]==0&&*flag==0){
	    mas[i-1][jcol+1]=com;*flag=1;return;}
	 if(mas[i][jcol]==ig&&mas[i-1][jcol+1]==0&&mas[i-2][jcol+2]==0&&mas[i-3][jcol+3]==ig&&*flag==0){
	    mas[i-1][jcol+1]=com;*flag=1;return;}
	  }
	     j++;
          }	
	  }
 //Ход бота
void HodCom(int ig,int com,int mas[][n])
{
 int i=0,j,flag=0;
//Поиск выигрышного хода
  if(flag!=1) checkHorCom(&flag,0,com,mas);
  if(flag!=1) checkHorCom(&flag,1,com,mas);
  if(flag!=1) checkVerCom(&flag,0,com,mas);
  if(flag!=1) checkVerCom(&flag,1,com,mas);
  if(flag!=1) checkVerCom(&flag,2,com,mas);
  if(flag!=1) checkVerCom(&flag,3,com,mas);
  if(flag!=1) checkDiag1Com(&flag,0,com,mas);
  if(flag!=1) checkDiag1Com(&flag,1,com,mas);
  if(flag!=1) checkDiag2Com(&flag,0,com,mas);
  if(flag!=1) checkDiag2Com(&flag,1,com,mas);
// Блокировка выигрышного хода игрока
if(flag!=1)checkHorIg(&flag,0,ig,com,mas);
if(flag!=1)checkHorIg(&flag,1,ig,com,mas);
if(flag!=1)checkVerIg(&flag,0,ig,com,mas);
if(flag!=1)checkVerIg(&flag,1,ig,com,mas);
if(flag!=1)checkVerIg(&flag,2,ig,com,mas);
if(flag!=1)checkVerIg(&flag,3,ig,com,mas);
if(flag!=1)checkDiag1Ig(&flag,0,ig,com,mas);
if(flag!=1)checkDiag1Ig(&flag,1,ig,com,mas);
if(flag!=1)checkDiag2Ig(&flag,0,ig,com,mas);
if(flag!=1)checkDiag2Ig(&flag,1,ig,com,mas);
//Строение выигрышной комбинации
if(flag!=1)checkHorCom1(&flag,0,com,mas);
if(flag!=1)checkHorCom1(&flag,1,com,mas);
if(flag!=1)checkVerCom1(&flag,0,com,mas);
if(flag!=1)checkVerCom1(&flag,1,com,mas);
if(flag!=1)checkVerCom1(&flag,2,com,mas);
if(flag!=1)checkVerCom1(&flag,3,com,mas);
if(flag!=1)checkDiag1Com1(&flag,0,com,mas);
if(flag!=1)checkDiag1Com1(&flag,1,com,mas);
if(flag!=1)checkDiag2Com2(&flag,0,com,mas);
if(flag!=1)checkDiag2Com2(&flag,1,com,mas);
//Помеха строению выигрышной комбинации игрока
if(flag!=1)checkHorIg1(&flag,0,ig,com,mas);
if(flag!=1)checkHorIg1(&flag,1,ig,com,mas);
if(flag!=1)checkVerIg1(&flag,0,ig,com,mas);
if(flag!=1)checkVerIg1(&flag,1,ig,com,mas);
if(flag!=1)checkVerIg1(&flag,2,ig,com,mas);
if(flag!=1)checkVerIg1(&flag,3,ig,com,mas);
if(flag!=1)checkDiag1Ig1(&flag,0,ig,com,mas);
if(flag!=1)checkDiag1Ig1(&flag,1,ig,com,mas);
if(flag!=1)checkDiag2Ig2(&flag,0,ig,com,mas);
if(flag!=1)checkDiag2Ig2(&flag,1,ig,com,mas);
//Ход
for(i=0;i<m;i++){
for(j=0;j<n;j++){
if((i>0&&i<4)&&mas[i][1]==ig&&mas[i][2]==0&&mas[i][3]==0&&flag==0){mas[i][3]=com;flag=1;}
if(i==0&&mas[i][j]==ig&&mas[i+1][j+1]==0&&flag==0){mas[i+1][j+1]=com;flag=1;}
if(i!=0&&mas[i][j]==ig&&mas[i-1][j+1]==0&&flag==0){mas[i-1][j+1]=com;flag=1;}
if(i!=0&&mas[i][j]==ig&&mas[i-1][j+1]!=0&&mas[i+1][j+1]==0&&flag==0){mas[i+1][j+1]=com;flag=1;}
		}
	        }
	
	if(flag==0){
	for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
        if(mas[i][j]==0&&flag==0){mas[i][j]=com;flag=1;break;
		        }
    	                }
    	if(flag==1)break;
		        }
                        }
}
 void InspectionHorCom(int**StopGame,int jcol, int com, int mas[][n])
{
    int i=0,j=jcol;
    while(i<7&&**StopGame==0){
    for(j=jcol;j<4+jcol;j++) {
    if(mas[i][jcol]==com&&mas[i][jcol+1]==com&&mas[i][jcol+2]==com&&mas[i][jcol+3]==com&&**StopGame==0){**StopGame=1;} 	 
}
	i++;
}
}
 void InspectionVerCom(int **StopGame,int istr, int com, int mas[][n])
{
 int j=0,i=istr;
 while(j<5&&**StopGame==0){
 for(i=istr;i<6+istr;i++){
 if(mas[istr][j]==com&&mas[istr+1][j]==com&&mas[istr+2][j]==com&&mas[istr+3][j]==com&&**StopGame==0){**StopGame=1;} 	 
 }
   j++;
 }
 }
void InspectionDiag1Com(int **StopGame,int jcol, int com, int mas[][n])
 {
 int j=jcol,i;
 while(j<4&&**StopGame==0){
 for(i=jcol;i<=3+jcol;i++){
 if(mas[i][jcol]==com&&mas[i+1][jcol+1]==com&&mas[i+2][jcol+2]==com&&mas[i+3][jcol+3]==com&&**StopGame==0){**StopGame=1;}
 }
     j++;
 }	
 }
void InspectionDiag2Com(int **StopGame,int jcol, int com, int mas[][n])
 {
 int j=jcol,i=0;
 while(j<4+jcol&&**StopGame==0){
 for(i=6;i>=3;i--){
 if(mas[i][jcol]==com&&mas[i-1][jcol+1]==com&&mas[i-2][jcol+2]==com&&mas[i-3][jcol+3]==com&&**StopGame==0){**StopGame=1;}
  }
	j++;
  }	
		}	
   void InspectionHorIg(int **StopGame,int jcol,int ig, int com, int mas[][n])
  {
   int i=0,j;
   while(i<7&&**StopGame==0){
   for(j=jcol;j<4+jcol;j++){
   if(mas[i][jcol]==ig&&mas[i][jcol+1]==ig&&mas[i][jcol+2]==ig&&mas[i][jcol+3]==ig&&**StopGame==0){**StopGame=2;}	 	 
   }
     i++;
   }
   }
    void InspectionVerIg(int **StopGame,int istr,int ig, int com, int mas[][n])
   {
     int j=0,i;
     while(j<5&&**StopGame==0){
     for(i=istr;i<4+istr;i++){
     if(mas[istr][j]==ig&&mas[istr+1][j]==ig&&mas[istr+2][j]==ig&&mas[istr+3][j]==ig&&**StopGame==0){**StopGame=2;}	 	 
    }
      j++;
    }	
    }
    void InspectionDiag1Ig(int **StopGame,int jcol,int ig, int com, int mas[][n])
    {
    int j= jcol,i;
    while(j<5&&**StopGame==0){
    for(i= jcol;i<4+jcol;i++){
    if(mas[i][ jcol]==ig&&mas[i+1][ jcol+1]==ig&&mas[i+2][ jcol+2]==ig&&mas[i+3][ jcol+3]==ig&&**StopGame==0){**StopGame=2;}
     }
    	j++;
     }
     }
     void InspectionDiag2Ig(int **StopGame,int jcol,int ig, int com, int mas[][n])
     {
     int j=jcol,i;
     while(j<4+jcol&&**StopGame==0){
     for(i=6;i>=3;i--){
     if(mas[i][jcol]==ig&&mas[i-1][jcol+1]==ig&&mas[i-2][jcol+2]==ig&&mas[i-3][jcol+3]==ig&&**StopGame==0){**StopGame=2;}
      }
    	j++;
      }
      }
  void SGame(int*StopGame,int com,int ig,int mas[][n]){
  	//Проверка на выигрыш бота
  	 InspectionHorCom( &StopGame, 0,com,mas);
  	 InspectionHorCom( &StopGame, 1,com,mas);
  	 InspectionVerCom( &StopGame,0,com,mas);
  	 InspectionVerCom( &StopGame,1,com,mas);
  	 InspectionVerCom( &StopGame,2,com,mas);
  	 InspectionVerCom( &StopGame,3,com,mas);
  	 InspectionDiag1Com(&StopGame,0,com,mas);
  	 InspectionDiag1Com(&StopGame,1,com,mas);
  	 InspectionDiag1Com(&StopGame,0,com,mas);
  	 InspectionDiag1Com(&StopGame,0,com,mas);
  	 InspectionDiag2Com(&StopGame,0,com,mas);
  	 InspectionDiag2Com(&StopGame,1,com,mas);
    //Проверка на выигрыш игрока
    InspectionHorIg(&StopGame,0,ig,com,mas);
    InspectionHorIg(&StopGame,1,ig,com,mas);
    InspectionVerIg(&StopGame,0,ig,com,mas);
    InspectionVerIg(&StopGame,1,ig,com,mas);
    InspectionVerIg(&StopGame,2,ig,com,mas);
    InspectionVerIg(&StopGame,3,ig,com,mas);
    InspectionDiag1Ig(&StopGame,0,ig,com,mas);
    InspectionDiag1Ig(&StopGame,1,ig,com,mas);
    InspectionDiag2Ig(&StopGame,0,ig,com,mas);
    InspectionDiag2Ig(&StopGame,1,ig,com,mas);
    int i=0,j;
    //Проверка на ничью
	int k=0;
       if(*StopGame==0){
	for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    	 k+=mas[i][j];
	}
	}
	if(k==53||k==52){*StopGame=3;}
	}
        }

	
	


