#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<dos.h>
using namespace std;
void setcolor(unsigned short color)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,color);
}
COORD c={0,0};
void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int z=0,pnr=1000;
int top=-1;
int front =-1;
int seatbook[72],tatkalarr[20];
char wlqueue[30][20];
char week[7][10] ;
char wlname[20],wlgender[2];
int wlage;
void booking();
int main();
class railway{
	public:
	char name[20];
	long long int phone;
	int age;
	char c;
	char pass[20];
    int tno;
	public:
		void add_passenger()
		{

		cout<<"\n\tEnter Name:\t";
		cin>>name;
		cout<<"\n\tEnter Password(Only Letters and Numbers):\t";
		while((c=getch())!=13)
     	{
     		if(isalnum(c))
     		{
    	  		pass[z++]=c;
    	  		cout<<"*";
    		}
    	}
    	pass[z]='\0';
		cout<<"\n\n\tEnter Age:\t";
		cin>>age;
		cout<<"\n\tEnter phone:\t";
		cin>>phone;
}
	void get_data()
		{
		cout<<"\n Name:\t";
		cout << name;
		cout<<"\n password:\t";
		cout << pass;
		cout<<"\nAge:\t";
		cout << age;
		cout<<"\n phone:\t";
		cout << phone;
		}
};
class passanger
{
	public:
		int mobileno,age;
		int page,seatno;
		string name,password,pname,pgender;
	public:

		void book(char traino[20],char source[20],char target[20])
		{
            fstream booking;
            booking.open("passengers.txt",ios::out|ios::app);
            booking<<pnr<<"\t";
            booking<<traino<<"\t";
            booking<<seatno;
            cout <<"\n\tEnter name:\t";
			cin >> pname;
			booking<<"\t"<<pname;
			cout <<"\n\tAge:\t";
			cin >>page;
			booking<<"\t"<<page;
			cout <<"\n\tGender:\t";
			cin>>pgender;
			booking<<"\t"<<pgender;
			booking<<"\t"<<source;
			booking<<"\t"<<target;
			booking<<"\n";
			booking.close();

		}

};
passanger p[100];


class train
{
	public:
	char tname[20];
	char start[20];
	char dest[20];
	char no[20];
	int st_num,i;
	int seat;
	int numdays,days[7];
	char stopage[30][30];
	public:
		void train_addition()
		{
			cout<<"\n\tTrain Name: ";
			cin>>tname;
			cout<<"\tTrain No: ";
            cin>>no;
			cout<<"\tStart From: ";
            cin>>start;
			cout<<"\tDestination: ";
			cin>>dest;
			cout<<"\tNo of seats: ";
			cin>>seat;
			cout << "\tNo.of Stops: ";
			cin>>st_num;
			for(i=0; i<st_num; i++)
			{
				cout << "\tEnter "<<i+1<< "stop: ";
				cin>>stopage[i];
			}

            	cout << "\tNo.of days: ";
		        cin>>numdays;
		    for(i=0; i<numdays; i++)
			{
				cout << "\tEnter "<<i+1<< "day: ";
				cin>>days[i];
			}
		}
	
		void showtrain()
		{
			
			cout<<no<<"\t\t"<<tname<<"\t\t"<<start<<"\t\t"<<dest<<"\t\t";
			cout<<seat<<"\t\t"<<numdays<<"\t\t";
				for(i=0; i<numdays; i++)
			{
				cout<<days[i];
				cout << "-";
			}
			cout<<"\t"<<st_num<<"\t\t";
			for(i=0; i<st_num; i++)
			{
				cout<<stopage[i];
				cout << "\t";
			}
			
			
		}
};

struct tr
{
char name[20],num[20];
	char start[20];
	char dest[20];
	int st_num,i;
	int seat;
	int numdays,days[7];
	char stopage[30][30];
	
}s[100];

void ticketbox()
{
	int x;
	for(x=1;x<=30;x++)
	{
		gotoxy(21,x);
		cout<<"|o|";
		gotoxy(107,x);
		cout<<"|o|";
	}
	getch();
	system("cls");
}


void dynamic()
{
	system("cls");
	int q=0;
int flag=0,f=0;
			train t;
			fstream train_file;
			char c,trainno[20];
int z=0,i=0;
	train_file.open("trains.txt",ios::in|ios::binary);
while(1)
{//system("cls");
	cout<<"\nEnter Train Number:\t";
while(c=getch())
             	{
             		cout<<c;
             		if(c=='!')
             		{
             			char ch;
             			cin>>ch;
             			if(ch=='m' || ch=='M')
             			{
             				system("cls");
             				main();
						 }
						 else if(ch=='d' || ch=='D')
						 {
						 	dynamic();
						 }
						 else
             				dynamic();
             		}
             		cout<<"\n\nTrainNo"<<"\t\t"<<"TrainName"<<"\t"<<"Source"<<"\t\t"<<"Dest"<<"\t\t"<<"Seats"<<"\t\t"<<"NoOfDays"<<"\t"<<"Days"<<"\t"<<"NoOfStops"<<"\t"<<"Stops..."<<endl<<endl;
				while(!train_file.eof())
				{
				train_file.read((char *)&t,sizeof(t));	 
					    if(t.no[0]==c || t.tname[0]==c)
					     {
					     	cout<<endl;
					     	strcpy(s[i].name,t.tname);
					     	strcpy(s[i].num,t.no);
					     	strcpy(s[i].start,t.start);
							 strcpy(s[i].dest,t.dest);
							s[i].seat=t.seat;
							 s[i].numdays=t.numdays;
							 for(int x=0; x<t.numdays; x++)
			{
				s[i].days[x]=t.days[x];
			}
                   s[i].st_num=t.st_num;
				   for(int x=0; x<t.st_num; x++)
			{
				strcpy(s[i].stopage[x],t.stopage[x]);
			}
				   
				          t.showtrain();
				          f=1;
						 }
						 
					i++;
						 	}
						if(f!=1)
						 {
						 	cout<<"\n\t\t**No Train Found**";
						 }
							 Sleep(4000);
				system("cls");
						 cout<<"\nEnter Train Number:\t";	cout<<c;
							 break;	
             	}
train_file.close();
f=3;
int k=0;
int j=0;
int w=0;
char ch5[10];
for(int q=0;q<4;q++)
{fflush(stdin);
	while(ch5[q]=getch())
	{
	cout<<ch5[q];
					if(ch5[q]=='!')
             		{
             			char ch;
             			cin>>ch;
             			if(ch=='m' || ch=='M')
             			{
             				main();
						 }
						 else if(ch=='d' || ch=='D')
						 {
						 	dynamic();
						 }
						 else
             				dynamic();
             		}
	k=0;
	cout<<"\n\nTrainName"<<"\t"<<"TrainNo"<<"\t\t"<<"Source"<<"\t\t"<<"Dest"<<"\t\t"<<"Seats"<<"\t\t"<<"NoOfDays"<<"\t"<<"Days"<<"\t"<<"NoOfStops"<<"\t"<<"Stops..."<<endl<<endl;
	 while(k<i)
	  {
	  	
				  	if(s[k].num[q+1]==ch5[q] || s[k].name[q+1]==ch5[q])
				  	{
				  			
				  	cout<<endl<<s[k].name<<"\t\t";
				  	cout<<s[k].num<<"\t\t";
				  	cout<<s[k].start<<"\t\t"<<s[k].dest<<"\t\t";
			cout<<s[k].seat<<"\t\t"<<s[k].numdays<<"\t\t";
				for(j=0; j<s[k].numdays; j++)
			{
				cout<<s[k].days[j];
				cout << "-";
			}
			cout<<"\t"<<s[k].st_num<<"\t\t";
			for(j=0; j<s[k].st_num; j++)
			{
				cout<<s[k].stopage[j];
				cout << "\t";
			}
			f=4;
					}
					
						 k++;
						 
				}
				if(f!=1)
						 {
						 	cout<<"\n\t\t**No Train Found**";
						 }
				Sleep(4000);
				system("cls");
				
				cout<<"\nEnter Train Number:\t"<< c;
				for(int p=0; p<q+1;p++)
					cout  << ch5[p];			
				break;
	}
	
	
}

				   
}

}

void train_search_by_name()
{system("cls");
		    int flag=0;
			char train_name_num[20];
			char train_num[20];
			train t;
			char ch5;
			fstream train_file;
			cout<<"\n\t\tEnter train number or name:\t";
			cin>>train_name_num;
			train_file.open("trains.txt",ios::in|ios::binary);
			// ch5=train_file.get();
			system("cls");
			cout<<"TrainNo"<<"\t\t"<<"TrainName"<<"\t"<<"Source"<<"\t\t"<<"Dest"<<"\t\t"<<"Seats"<<"\t\t"<<"NoOfDays"<<"\t"<<"Days"<<"\t"<<"NoOfStops"<<"\t"<<"Stops..."<<endl<<endl;
			while(!train_file.eof())
				{
					     //train_file.seekg(-1,ios::cur);
						 train_file.read((char *)&t,sizeof(t));
						 //t.showtrain();
						 
					    if( strcmp(t.tname,train_name_num)==0  || strcmp(t.no,train_name_num)==0)
					     {
                          t.showtrain();
                          cout<<endl;
                          flag=1;
					     	break;
						 }
						 /*else
						 {
						 	flag=1;
						 }*/
					     //ch5=train_file.get();
				     	}
				    if(flag!=1)
				    {
				    	cout << "\n\t....***No Train Found With This Name or Number***....\n";
					}
			train_file.close();

}

int wlpnr[30];


void train_search_by_place()
{
system("cls");
    ifstream train_file;
    train t;
	int flag=0;
		char source[20];
		char target[20];
		int k;
			cout<<"\n\tEnter The Valid Places\n\n";
			cout<<"\tBording At:\t";
			cin>>source;
            cout<<"\tDestination:\t";
		    cin>>target;

					    train_file.open("trains.txt",ios::in|ios::binary);
						char ch=train_file.get();
						system("cls");
						cout<<"TrainNo"<<"\t\t"<<"TrainName"<<"\t"<<"Source"<<"\t\t"<<"Dest"<<"\t\t"<<"Seats"<<"\t\t"<<"NoOfDays"<<"\t"<<"Days"<<"\t"<<"NoOfStops"<<"\t"<<"Stops..."<<endl<<endl;
			 			while(ch!=EOF)
						{
						 train_file.seekg(-1,ios::cur);
						 train_file.read((char *)&t,sizeof(t));
					     if( strcmp(t.start,source)==0  )
					     {
					     		int stop=0;
						 		for(k=stop;k<=t.st_num;k++)
						 		{
						 			 if(strcmp(t.stopage[k],target)==0 || strcmp(t.dest,target)==0)
						    		{
						 				t.showtrain();
						 				 cout << endl;
						 				 break;
						 			}
								}
					
						 }
						
						 else
						 {
						 	for(int i=0;i<t.st_num;i++)
						 	{
							     if(strcmp(t.stopage[i],source)==0)
						    	{
						 		//t.showtrain();
						 		//cout<<"LEt  destination:";
						 		int stop=i+1;
						 		for(k=stop;k<=t.st_num;k++)
						 		{
						 			 if(strcmp(t.stopage[k],target)==0 || strcmp(t.dest,target)==0)
						    		{
						 				t.showtrain();
						 				cout << endl;
						 			}
								 }
						    	}
						    	else {
						    		flag=2;
								}
					    	}
							 	flag=1;
						 }
					     ch=train_file.get();
				     	}
				if(flag==2)
				cout<<"Train Not Found";
				//else if(flag==1)
				//cout<<"Your station is not a source station of Train";
				     	train_file.close();

}

void cancel()
{system("cls");
		int pnrc,c=0,i=0;
	char traino[20],fettno[20];
	int sno,age,sstore[10];
	char name[20];
	char gender[2];
		FILE *fp,*fp1;
cout<<"Enter PNR number:";
cin >> pnrc;
fstream pass1;
pass1.open("p1.txt",ios::out);
	fp=fopen("passengers.txt","a+");
	while(fscanf(fp,"%d %s %d %s %d %s",&pnr,traino,&sno,name,&age,gender)!=EOF)
{
	cout<<pnr<<"\t"<<traino<<"\t"<<sno<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<endl;
	if(pnr!=pnrc){
			cout<<pnr<<"\t"<<traino<<"\t"<<sno<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<endl;
				pass1<<pnr<<"\t"<<traino<<"\t"<<sno<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<endl;
	}
	else
			{
			strcpy(fettno,traino);
			sstore[i]=sno;
				i=i+1;
				
			}
}
 	fclose(fp);
 	pass1.close();
	int status=remove("passengers.txt");
	if(status==0)
	{
		cout<<"file "<<" deleted successfully..!!\n";
	}
	else
	{
		cout<<"Unable to delete file "<<"\n";
		perror("Error Message ");
	}
	int status1=rename("p1.txt","passengers.txt");
	cout<<"\n\n\n\n";
	fstream waitup;
	fstream waitup1;
	fstream pass2;
	fp1=fopen("wl.txt","a+");
	waitup1.open("w2.txt",ios::out);
	pass2.open("passengers.txt",ios::out|ios::app);
	int j=0,k=0,wl=0,wlc=0;
	while(fscanf(fp1,"%d %s %s %d %s %d",&pnr,traino,name,&age,gender,&status)!=EOF)
		 {
		 if(wl<i && strcmp(fettno,traino)==0)
		 {
		 	cout<<"WAITING LIST CONFIRMED OF\n";
		 	cout<<pnr<<"\t"<<traino<<"\t"<<sstore[k]<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<endl;
		    pass2<<pnr<<"\t"<<traino<<"\t"<<sstore[k]<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<endl;
		    cout<<"\n";
		 	wl++;
		 	k++;
		 }
		 else if(strcmp(fettno,traino)==0)
		 {
		 waitup1<<pnr<<"\t"<<traino<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<"\t"<<status-1<<endl;
	}
	 else
		 {
		 waitup1<<pnr<<"\t"<<traino<<"\t"<<name<<"\t"<<age<<"\t"<<gender<<"\t"<<status<<endl;
	}
		 } 
		pass2.close();
		waitup1.close();
		fclose(fp1);
	 int stat=remove("wl.txt");
	 cout<<stat;
	if(stat==0)
	{
		cout<<"file "<<" deleted successfully..!!\n";
	}
	else
	{
		cout<<"Unable to delete file "<<"\n";
		perror("Error Message ");
	}
int	status2=rename("w2.txt","wl.txt");

}


void login()
{
	char name[20];
	char pass[20];
	char c;
	int ch,z=0,f;
	char ch2;
	railway yatri;
	int flag=0;
	fstream rail_user;
				system("cls");
                cout<<"\n\n\t\t----------Login Page----------\n";
                cin.ignore();
		        cout<<"\n\tEnter Name:\t";
		        cin>>name;
		        cout<<"\n\tEnter Password:\t";
	        	while((c=getch())!=13)
             	{
             		if(isalnum(c))
             		{	 
            	  		pass[z++]=c;
            	  		cout<<"*";
            		}
             	}
				 pass[z]='\0';
		        rail_user.open("registeration.txt",ios::in|ios::binary);
			    ch2=rail_user.get();
				 while(ch2!=EOF)
				{
				rail_user.seekg(-1,ios::cur);
				rail_user.read((char *)&yatri,sizeof(yatri));
				if(strcmp(name,yatri.name)==0 && strcmp(pass,yatri.pass)==0 )
				{system("cls");
					cout<<"\n\t---Login Successful !!---\n\n";
				while(1)
				{
					
				    cout<<"\n\t\tWELCOME\t"<<yatri.name<<"\n\n\t\tChoose One\n\n";
                    cout<<"\t1-> Search Train By Name";
                    cout<<"\n\t2-> Search Train By Place";
                    cout<<"\n\t3-> Book Directly";
					cout<<"\n\t4-> Cancel Directly";
                    cout<<"\n\t5-> Logout\n";
                    char cho;
                    cout<<"\tEnter your choice:\t";
                    cin>>cho;
                    if(cho=='m' || cho=='M')
             			{
             				system("cls");
             				main();
						 }
                switch(cho)
                {
                	case '1':
                		{
                			train_search_by_name();
                			break;
						}
					case '2':
						{
							train_search_by_place();
							break;
						}
					case '3':
						{
							booking();
							break;
						}
						case '4':
						{
							cancel();
							break;
						}
					case '5':
						{system("cls");
							main();
							break;
						}
					default:
						{
							cout<<"\n\t\tWrong choice...Please Enter a Valid Option...\n\n";
						}
				}
            }
            flag=0;
                break;
				}
				else{
					flag=1;
				}
				ch2=rail_user.get();
			}
			if(flag==1)
			{
			cout<<"\n\n\t***Username Password Combination isn't Correct***\n";
			cout<<"\n\t\tSorry....Access Denied\n\n\n";	
		}
				rail_user.close();
}


void train_search_by_plac(char source[20],char target[20],int day)
{
    ifstream train_file;
    train t;
	int flag=0,f=0;
		int k;
			
						cout<<"\n\n\t\t----------Trains Running On "<<week[day]<<"----------\n\n";
						 cout<<"TrainNo"<<"\t\t"<<"TrainName"<<"\t"<<"Source"<<"\t\t"<<"Dest"<<"\t\t"<<"Seats"<<"\t\t"<<"NoOfDays"<<"\t"<<"Days"<<"\t"<<"NoOfStops"<<"\t"<<"Stops..."<<endl<<endl;
					    train_file.open("trains.txt",ios::in|ios::binary);
						char ch=train_file.get();
			 			while(ch!=EOF)
						{
						 train_file.seekg(-1,ios::cur);
						 train_file.read((char *)&t,sizeof(t));
						 //cout<<"TrainNo"<<"\t\t"<<"TrainName"<<"\t"<<"Source"<<"\t\t"<<"Dest"<<"\t\t"<<"Seats"<<"\t\t"<<"NoOfDays"<<"\t"<<"Days"<<"\t"<<"NoOfStops"<<"\t"<<"Stops..."<<endl<<endl;
					     if( strcmp(t.start,source)==0  )
					     {
					     		int stop=0;
						 		for(k=stop;k<=t.st_num;k++)
						 		{
						 			 if(strcmp(t.stopage[k],target)==0 || strcmp(t.dest,target)==0)
						    		{
						    			for(k=0; k<t.numdays; k++)
						    			{
						    				if(day==t.days[k])
						    				{
						    					t.showtrain();
						 				 		cout << endl;
						 				 		flag=1;
						 				 		break;
											}
										}
						 				
						 				 break;
						 			}
								}
						 }
						
						 else
						 {
						 	for(int i=0;i<t.st_num;i++)
						 	{
							     if(strcmp(t.stopage[i],source)==0)
						    	{
						 		int stop=i+1;
						 		for(k=stop;k<=t.st_num;k++)
						 		{
						 			 if(strcmp(t.stopage[k],target)==0 || strcmp(t.dest,target)==0)
						    		{
						    			for(k=0; k<t.numdays; k++)
						    			{
						    				if(day==t.days[k])
						    				{
						    					t.showtrain();
						 				 		cout << endl;
						 				 		flag=1;
						 				 		break;
											}
													
										}
										break;
						 			}
								 }
						    	}
						    	else {
						    		flag=2;
								}
					    	}
						 }
					     ch=train_file.get();
				     	}
				     	
				if(flag!=1 && flag!=2)
				{
					cout<<"\n\t\t***No other Train Found on the given date***\n";
					//cout<<"\n\tThis Train's Not Running on "<<week[day];
					//cout<<"\n\n\tRuns On...(try with the dates of these week days)\n";
					/*for(int i=0;i<t.numdays;i++)
						cout<<"\t"<<week[t.days[i]]<<"\t";*/
					cout<<endl;
					getch();
					system("cls");
					cin.ignore();
					//login();
					fflush(stdin);
				}
				     	train_file.close();

}



int dayofjourney(int date,int mon, int year)
{
 int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
 
 int i, r, s = 0 ;  
 strcpy(week[0], "Sunday") ; 
 strcpy(week[1], "Monday") ; 
 strcpy(week[2], "Tuesday") ; 
 strcpy(week[3], "Wednesday") ; 
 strcpy(week[4], "Thursday") ; 
 strcpy(week[5], "Friday") ; 
 strcpy(week[6], "Saturday") ; 
 //printf("Enter a valid date (dd/mm/yyyy) : ") ; 
 //scanf("%d / %d / %d", &date, &mon, &year) ; 
 if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)) ) 
  month[1] = 29 ; 
 for(i = 0 ; i < mon - 1 ; i++) 
  s = s + month[i] ; 
 s = s + (date + year + (year / 4) - 2) ; 
 s = s % 7 ; 
 printf("\n\tThe Entered day is : %s\n\n", week[s]) ; 
 getch();
 system("cls");
 return s;

}

void printticket(int n,char train_name_num[20],char source[20],char target[20],int date,int mon,int year,int day)
{
	
	
		    int i,phone;
		    char aname[20];
		    char ch2;
			   ofstream ticket;
			x:   cout<<"\n\n\t\t----------Re-confirm Details----------\n";
			   cout<<"\n\t\t\tName: ";
			   cin>>aname;
			   cout<<"\n\t\t\tPhone No: ";
			   cin>>phone;
			   	railway yatri;
             	int flag=0;
	            fstream rail_user;
                rail_user.open("registeration.txt",ios::in|ios::binary);
			    ch2=rail_user.get();
				 while(ch2!=EOF)
				{
				rail_user.seekg(-1,ios::cur);
				rail_user.read((char *)&yatri,sizeof(yatri));
				if(strcmp(aname,yatri.name)==0 && phone==yatri.phone )
				{
		   	   cout<<"\nWait Your Ticket Will Be Printing\n\n";
		   	   cout<<"Your PNR No is "<<pnr<<endl;
		   	   getch();
		   	   system("cls");
		   	   cout<<"\nPress any key to Show the Ticket\t\n\n";
		   	   getch();
		   	   system("cls");
		       ticket.open("ticket.txt");
		       ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
			   ticket<<"\n\t\t\t\t\t\t\tIRCTC RAILWAYS\n";
			   ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
			   ticket<<"\n\t\t\tE-ticket\t\t";
			   ticket<<"\t\t\t\t\t\tPNR NO:"<<pnr;
               ticket<<"\n\n\t\t\t\t\t\tACCOUNT NAME:\t";
               ticket<<aname;
			   ticket<<"\n\n\t\t\t\t\t\tPHONE NO. :\t"<<phone;
			   ticket<<"\n\n\t\t\t\t\t\tTRAIN NO. OR NAME :\t"<<train_name_num;
			   ticket<<"\n\n\t\t\t\t\t\tBOARDING STATION :\t"<<source;
			   ticket<<"\n\n\t\t\t\t\t\tDESTINATION :\t"<<target;
			   ticket<<"\n\n\t\t\t\t\t\tJOURNEY DATE  :\t"<<date<<"/"<<mon<<"/"<<year;
			   ticket<<"\n\n\t\t\t\t\t\tDAY OF JOURNEY :\t"<<week[day]<<endl;
			   ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
               ticket<<"\n\n\t\t\tPASSENGERS\t"<<"\tAGE\t"<<"\t\tGENDER\t\t\tSEAT NO\n";

                for(int i=0;i<n; i++)
	{
	ticket<<"\n\t\t\t"<<p[i].pname<<"\t\t\t"<<p[i].page<<"\t\t\t"<<p[i].pgender<<"\t\t\t"<<p[i].seatno;
	
	}
	ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
			   ticket.close();
			     flag=0;
                break;
				}
				else{
					flag=1;
					system("cls");
					goto x;
				}
				ch2=rail_user.get();
			}
			cout<<"Your Ticket\n";
			char c1;
			fstream fp;
			fp.open("ticket.txt",ios::in);
			while(!fp.eof())
			{
				c1=fp.get();
				cout<<c1;
			}
			ticketbox();
			fp.close();
			getch();
}

void printtickettk(int n,char train_name_num[20],char source[20],char target[20],int date,int mon,int year,int day)
{system("cls");
	
		    int i,phone;
		    char aname[20];
		    char ch2;
			   ofstream ticket;
			   cout<<"\n\n\t\t----------Re-confirm Details----------\n";
			   cout<<"\n\t\t\tNAME:\t";
			   cin>>aname;
			   cout<<"\n\t\t\tPHONE NO. :\t";
			   cin>>phone;
			   	railway yatri;
             	int flag=0;
	            fstream rail_user;
                rail_user.open("registeration.txt",ios::in|ios::binary);
			    ch2=rail_user.get();
				 while(ch2!=EOF)
				{
				rail_user.seekg(-1,ios::cur);
				rail_user.read((char *)&yatri,sizeof(yatri));
				if(strcmp(aname,yatri.name)==0 && phone==yatri.phone )
				{
		   	   cout<<"\nWAIT YOUR TICKET WILL BE PRINTING\n\n";
		   	   cout<<"Your PNR No is "<<pnr<<endl;
		   	   system("cls");
		   	   cout<<"\nPress any key to Show the Ticket\t\n\n";
		   	   getch();
		   	   system("cls");
		       ticket.open("ticket_tatkal.txt");
		       ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
			   ticket<<"\n\t\t\t\t\t\t\tIRCTC RAILWAYS\n";
			   ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
			   ticket<<"\n\t\t\tE-ticket\t\t";
			   ticket<<"TATKAL\t\t\t\tPNR NO:"<<pnr;
               ticket<<"\n\n\t\t\t\t\t\tACCOUNT NAME:\t";
               ticket<<aname;
			   ticket<<"\n\n\t\t\t\t\t\tPHONE NO. :\t"<<phone;
			   ticket<<"\n\n\t\t\t\t\t\tTRAIN NO. OR NAME :\t"<<train_name_num;
			   ticket<<"\n\n\t\t\t\t\t\tBOARDING STATION :\t"<<source;
			   ticket<<"\n\n\t\t\t\t\t\tDESTINATION :\t"<<target;
			   ticket<<"\n\n\t\t\t\t\t\tJOURNEY DATE  :\t"<<date<<"/"<<mon<<"/"<<year;
			   ticket<<"\n\n\t\t\t\t\t\tDAY OF JOURNEY :\t"<<week[day]<<endl;
			   ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
               ticket<<"\n\n\t\t\tPASSENGERS\t"<<"\tAGE\t"<<"\t\tGENDER\t\t\tSEAT NO\n";

                for(int i=0;i<n; i++)
	{
	ticket<<"\n\t\t\t"<<p[i].pname<<"\t\t\t"<<p[i].page<<"\t\t\t"<<p[i].pgender<<"\t\t\t"<<p[i].seatno<<"/TATKAL";
	
	}
	ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
			   ticket.close();
			     flag=0;
                break;
				}
				else{
					flag=1;
				}
				ch2=rail_user.get();
			}
			cout<<"Your Ticket\n";
			char c1;
			fstream fp;
			fp.open("ticket_tatkal.txt",ios::in);
			while(!fp.eof())
			{
				c1=fp.get();
				cout<<c1;
			}
			ticketbox();
			fp.close();
			getch();
}

void seatmap(int n)
{
	int j,k,f=0;
cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
	                      cout<<"LEFT LOWER:\t";
                          for( j=1;j<=n ;j=j+8)
                          {	
                          f=0;
                          for(k=0;k<top;k++)
                          {
                          	
                          	if(j==seatbook[k])
                          	{
                          		setcolor(76);
                          		cout<<"\t | "<<j<<"b | ";
								  setcolor(177);
								  f=1;
                          		continue;
							  }
						  }
						  if(f!=1)
						  {
						  	setcolor(163);
						  	cout<<"\t |  "<<j<<" | ";
						    setcolor(177);
						  }
						
							  
						  }
						  cout<<"\n";
						  f=0;
						  cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
						  cout<<"LEFT MIDDLE:\t";
                          for( j=2;j<=n;j=j+8)
                          {
                          	f=0;
                          	 for(k=0;k<=top;k++)
                          {
                          	if(j==seatbook[k])
                          	{
                          		setcolor(76);
                          	cout<<"\t | "<<j<<"b | ";
                          		setcolor(177);
								  f=1;
                          		continue;
							  }
						  }
						  if(f!=1)
						  {
						  	setcolor(163);
						  	cout<<"\t |  "<<j<<" | ";
						    setcolor(177);
						  }
                          //cout<<"\t |  "<<j<<" | ";
						  }
						  cout<<"\n";
						  f=0;
						  cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
						   cout<<"LEFT UPPER:\t";
                          for( j=3;j<=n;j=j+8)
                          {
                          	f=0;
                          	 for(k=0;k<=top;k++)
                          {
                          	if(j==seatbook[k])
                          	{
                          		setcolor(76);
                          	cout<<"\t | "<<j<<"b | ";
                          		setcolor(177);
								  f=1;
                          		continue;
							  }
						  }
						  if(f!=1)
						  {
						  	setcolor(163);
						  	cout<<"\t |  "<<j<<" | ";
						    setcolor(177);
						  }
                          //cout<<"\t |  "<<j<<" | ";
						  }
						  cout<<"\n";
						  f=0;
						  cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
						  cout<<"RIGHT LOWER:\t";
                          for( j=4;j<=n;j=j+8)
                          {
                          	f=0;
                          	 for(k=0;k<=top;k++)
                          {
                          	if(j==seatbook[k])
                          	{
                          		setcolor(76);
                          	cout<<"\t | "<<j<<"b | ";
                          		setcolor(177);
								  f=1;
                          		continue;
							  }
						  }
						  if(f!=1)
						  {
						  	setcolor(163);
						  	cout<<"\t |  "<<j<<" | ";
						  setcolor(177);
						  }
                          //cout<<"\t |  "<<j<<" | ";
						  }
						  cout<<"\n";
						  cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
						  cout<<"RIGHT MIDDLE:\t";
                          for( j=5;j<=n;j=j+8)
                          {
                          	f=0;
                          	 for(k=0;k<=top;k++)
                          {
                          	if(j==seatbook[k])
                          	{
                          		setcolor(76);
                          	cout<<"\t | "<<j<<"b | ";
                          		setcolor(177);
								  f=1;
                          		continue;
							  }
						  }
						  if(f!=1)
						  {
						  	setcolor(163);
						  	cout<<"\t |  "<<j<<" | ";
						  setcolor(177);
						  }
                          //cout<<"\t |  "<<j<<" | ";
						  }
						  cout<<"\n";
						  cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
						   cout<<"RIGHT UPPER:\t";
                          for( j=6;j<=n;j=j+8)
                          {
                          	f=0;
                          	 for(k=0;k<=top;k++)
                          {
                          	if(j==seatbook[k])
                          	{
                          		setcolor(76);
                          	cout<<"\t | "<<j<<"b | ";
                          		setcolor(177);
								  f=1;
                          		continue;
							  }
						  }
						  if(f!=1)
						  {
						  	setcolor(163);
						  	cout<<"\t |  "<<j<<" | ";
						  setcolor(177);
						  }
                          //cout<<"\t |  "<<j<<" | ";
						  }
						  cout<<"\n";
						  cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
						  cout<<"SIDE LOWER:\t";
                          for( j=7;j<=n;j=j+8)
                          {
                          	f=0;
                          	 for(k=0;k<=top;k++)
                          {
                          	if(j==seatbook[k])
                          	{
                          		setcolor(76);
                          	cout<<"\t | "<<j<<"b | ";
                          		setcolor(177);
								  f=1;
                          		continue;
							  }
						  }
						  if(f!=1)
						  {
						  	setcolor(163);
						  	cout<<"\t |  "<<j<<" | ";
						  setcolor(177);
						  }
                          //cout<<"\t |  "<<j<<" | ";
						  }
						  cout<<"\n";
						  cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
						  cout<<"SIDE UPPER:\t";
                          for( j=8;j<=n;j=j+8)
                          {
                          	f=0;
                          	 for(k=0;k<=top;k++)
                          {
                          	if(j==seatbook[k])
                          	{
                          		setcolor(76);
                          	cout<<"\t | "<<j<<"b | ";
                          		setcolor(177);
								  f=1;
                          		continue;
							  }
						  }
						  if(f!=1)
						  {
						  	setcolor(163);
						  	cout<<"\t |  "<<j<<" | ";
						  setcolor(177);
						  }
                          //cout<<"\t |  "<<j<<" | ";
						  }
						  cout<<"\n";
						  cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
	for(int x=4;x<=28;x++)
	{
		gotoxy(17,x);
		cout<<"|";
		gotoxy(35,x);
		cout<<"|";
		gotoxy(53,x);
		cout<<"|";
		gotoxy(71,x);
		cout<<"|";
		gotoxy(89,x);
		cout<<"|";
		gotoxy(107,x);
		cout<<"|";
	}
}

int update_booking(char trno[20])   // this function is to update the existing seat in a particular train 
{
	top=-1;
	char traino[20];
	int sno,age;
	char name[20];
	char gender[2],ch,source[20],destination[20];
	int i;
        fstream booking;
        booking.open("passengers.txt",ios::in);
        ch=booking.get();
        if(ch==EOF)
        {
        	return 0;
		}
		booking.seekg(0,ios::beg);
         while(!booking.eof())
         {
         	booking>>pnr;
         	booking>>traino;
            booking>>sno;
            booking>>name;
		    booking>>age;
		    booking>>gender;
		    booking>>source;
		    booking>>destination;
			if(strcmp(traino,trno)==0)
			{
			//	cout<<"ja rha h\n";
				seatbook[++top]=sno;
				pnr=pnr+1;
			}
		}
		cout<<"\n\t\tSeats that already booked in this train\n\n";
		cout<<"\t\t|| ";
	for (i=0;i<top;i++)
	{
		cout<<" | "<<seatbook[i];
	}
	cout<<"|END||\n";
			booking.close();
}

void tat()
{system("cls");
	int n;
	int delay;
	    int flag;
			char train_name_num[20];
			char train_num[20];
			train t;
			char ch5,gsource[20],gdestination[20];
			int j,day,date,mon,year,k=0;
			
			fstream train_file;
			/*cout<<"Wait for 10 seconds..\n";
			for(int i=10;i>0;i--)
			{
				system("cls");
				gotoxy(85,20);
				cout<<i;
				gotoxy(100,40);
				 Sleep(500);  
			}*/
			system("cls");
			cout <<"\n\tEnter Source:\t";
					     	cin>>gsource;
					     	cout <<"\n\tEnter Destination:\t";
					     	cin>>gdestination;
					     	 printf("\n\tEnter Day of Journey(dd/mm/yyyy): ") ; 
                scanf("%d / %d / %d", &date, &mon, &year) ;
                day=dayofjourney(date,mon,year);
					train_search_by_plac(gsource,gdestination,day);
			cout<<"\t\tEnter train number or name:\t";
			cin>>train_name_num;
			train_file.open("trains.txt",ios::in|ios::binary);
			cout<<"\n\n\t\t----------Your Selected Train----------\n\n";
			 ch5=train_file.get();
			while(ch5 != EOF)
				{
					     train_file.seekg(-1,ios::cur);
						 train_file.read((char *)&t,sizeof(t));
					    if( strcmp(t.tname,train_name_num)==0  || strcmp(t.no,train_name_num)==0)
					     {
					     	
                          t.showtrain();
	                        fstream check;
	                        check.open("passengers.txt",ios::in);
	                        if(!check.eof())
	                        {
	                          update_booking(t.no);
	                   }
	                   int counter=0;
	                   /*cout<<top<<endl;
	                   for(int q=0;q<top;q++)
	                   			cout<<seatbook[q]<<"-"<<q<<"\t";
	                   	cout << endl;*/
	                   int k=0;
	                   for(int i=1;i<=t.seat; i++)
	                   {counter=0;
	                   		for(int j=0; j<top; j++)
	                   		{
	                   			if(i!=seatbook[j])
	                   			{/*cout<<tatkalarr[k]<<"\t";
	                   				tatkalarr[k++]=i;*/
	                   				counter++;
	                   				
								   }
								   
							   }
							   if(counter==top)
							   {
							   	tatkalarr[k++]=i;
							   }  
							   		
					   }
					   cout<<"Vacant Seats: "<<endl;
					   for(int x=0; x<(t.seat-top); x++)
					   		cout<<tatkalarr[x]<<"\t";
					
					 k=0;
					 cout<<"Alloted Seat No is: "<<tatkalarr[0];
					   p[0].seatno=tatkalarr[k++];
	                             p[0].book(t.no,gsource,gdestination);
	                              update_booking(t.no);
					   printtickettk(1,train_name_num,gsource,gdestination,date,mon,year,day);
				}
				   ch5=train_file.get();
				     	}
				     	cout<<"\n\n\t\t--------------------------------------\n\n";
			train_file.close();
}

void printticketwl(char train_name_num[20],char source[20],char target[20],int wlno,int date,int mon,int year,int day)
{system("cls");
		    int i,phone;
		    char aname[20];
		    char ch2;
			   ofstream ticket;
			   cout<<"\n\n\t\t----------Re-confirm Details----------\n";
			   cout<<"\n\t\t\tNAME:\t";
			   cin.ignore();
			   cin>>aname;
			   cout<<"\n\t\t\tPHONE NO. :\t";
			   cin>>phone;
			   	railway yatri;
             	int flag=0;
	            fstream rail_user;
                rail_user.open("registeration.txt",ios::in|ios::binary);
			    ch2=rail_user.get();
				 while(ch2!=EOF)
				{
				rail_user.seekg(-1,ios::cur);
				rail_user.read((char *)&yatri,sizeof(yatri));
				if(strcmp(aname,yatri.name)==0 && phone==yatri.phone )
				{
		   	   cout<<"\nWAIT YOUR TICKET WILL BE PRINTING\n\n";
		   	   cout<<"Your PNR No is "<<pnr;
		   	   system("cls");
		   	   cout<<"\nPress any key to Show the Ticket\t\n\n";
		   	   getch();
		   	   system("cls");
		       ticket.open("ticket_wl.txt");
		       ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
			  ticket<<"\n\t\t\t\t\t\t\tIRCTC RAILWAYS\n";
			   ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
			   ticket<<"\n\t\t\tE-ticket\t\t";
			   ticket<<"WAITING TICKET\t\t\t\tPNR NO:"<<pnr;
               ticket<<"\n\n\t\t\t\t\t\tACCOUNT NAME:\t";
               ticket<<aname;
			   ticket<<"\n\n\t\t\t\t\t\tPHONE NO. :\t"<<phone;
			   ticket<<"\n\n\t\t\t\t\t\tTRAIN NO. OR NAME :\t"<<train_name_num;
			   ticket<<"\n\n\t\t\t\t\t\tBOARDING STATION :\t"<<source;
			   ticket<<"\n\n\t\t\t\t\t\tDESTINATION :\t"<<target;
			   ticket<<"\n\n\t\t\t\t\t\tJOURNEY DATE  :\t"<<date<<"/"<<mon<<"/"<<year;
			   ticket<<"\n\n\t\t\t\t\t\tDAY OF JOURNEY :\t"<<week[day]<<endl;
			   ticket<<"\n\t\t\t------------------------------------------------------------------------------------\n";
               ticket<<"\n\n\t\t\tPASSENGERS\t\tAGE\t\t\tGENDER\t\t\tSEAT NO\n";  
			   ticket<<"\n\t\t\t"<<wlname<<"\t\t\t"<<wlage<<"\t\t\t"<<wlgender<<"\t\t\t"<<"WL/"<<wlno;
			   ticket.close();
			     flag=0;
                break;
				}
				else{
					flag=1;
				}
				ch2=rail_user.get();
			}
			cout<<"Your Ticket\n";
			char c1;
			fstream fp;
			fp.open("ticket_wl.txt",ios::in);
			while(!fp.eof())
			{
				c1=fp.get();
				cout<<c1;
			}
			ticketbox();
			fp.close();
			getch();
}

void waiting_list(char trainno[20],char gsource[20],char gdestination[20],int wlno=1)
{system("cls");

cout<<"\n\n\t\t----------Waiting List Portal----------\n";
fstream wait;
wait.open("wl.txt",ios::out|ios::app);
cout<<"\n\tEnter Name: ";
cin>>wlname;
cout<<"\n\tAge: ";
cin>>wlage;
cout<<"\n\tGender: ";
cin>>wlgender;
wait<<pnr<<"\t"<<trainno<<"\t"<<wlname<<"\t"<<wlage<<"\t"<<wlgender<<"\t"<<wlno<<"\t"<<gsource<<"\t"<<gdestination<<"\n";
wait.close();
}

void update_queue(char trno[20])   // this function is to update the existing seat in a particular train 
{
	char traino[20];
	int sno,age;
	char name[20];
	char gender[2],status[4],source[20],destination[20];
	
	int i;
	front=-1;
	cout<<"\n\tWait Sometime updating queue\n";
        fstream booking;
        booking.open("wl.txt",ios::in);
         while(!booking.eof())
         {
         	booking>>pnr;
         	booking>>traino;
            booking>>name;
		    booking>>age;
		    booking>>gender;
		    booking>>status;
			if(strcmp(traino,trno)==0)
			{
			++front;
			strcpy(wlqueue[front],name);
			pnr++;
			}
		}
	for (i=0;i<front;i++)
	{
		cout<<"\n"<<wlqueue[i];
	}
	cout<<"\n";
			booking.close();
}

void train_add()
{system("cls");
			fstream rail_user;
			train t1;
			char nameadm[20],passadm[20],c;
			int num_of_train,z=0;
	cout<<"\n\n\t\t----------Train Add Portal----------\n\n";
				cout<<"\n\tEnter No.of Trains: ";
				cin>>num_of_train;
				while(num_of_train>0)
                {
                	
                t1.train_addition();
                rail_user.open("trains.txt",ios::app|ios::out);
                //cout << t1.seat << t1.stopage[0] << t1.dest[0]<<endl;
				rail_user.write((char*)&t1,sizeof(t1));
				//cout << t1.seat << t1.stopage[0] << t1.dest[0]<<endl;
				rail_user.close();
				num_of_train--;
				
                }
}

void check_status()
{
	system("cls");
	char traino[20];
	int sno,age;
	char name[20];
	char gender[2],status[4],source[20],destination[20];
	char trno[20];
	int flag;
	int i,gpnr;
	front=-1;
	//update_booking(trno);
	cout<<"\n\n\t\t----------Check Status Page----------\n";
	cout<<"\n\tEnter PNR Number: ";
	cin >>gpnr;
        fstream booking;
        booking.open("passengers.txt",ios::in);
         while(!booking.eof())
         {
         	booking>>pnr;
         	booking>>traino;
            booking>>sno;
            booking>>name;
		    booking>>age;
		    booking>>gender;
		    booking>>source;
		    booking>>destination;
			if(pnr==gpnr)
			{system("cls");
				cout<<"\n\t\t***Ticket Confirmed***\n\n";
				cout<<"PNR No\t\tTrain No\tName\t\tAge\t\tGender\t\tSeat No\t\tSource\t\tDestination\n";
				cout << pnr<<"\t\t" << traino<<"\t\t" <<name<<"\t\t" <<age<<"\t\t" <<gender<<"\t\t" <<sno<<"\t\t" <<source<<"\t\t" <<destination;
				flag=1;
			}
		}
		cout<<"\n";
			booking.close();
        booking.open("wl.txt",ios::in);
         while(!booking.eof())
         {
         	booking>>pnr;
         	booking>>traino;
            booking>>name;
		    booking>>age;
		    booking>>gender;
		    booking>>status;
		    booking>>source;
		    booking>>destination;
			if(pnr==gpnr)
			{system("cls");
				cout<<"\n\t\t***Waiting List Ticket***\n\n";
				cout<<"PNR No\t\tTrain No\tName\t\tAge\t\tGender\t\tW/L No\t\tSource\t\tDestination\n";
				cout << pnr<<"\t\t" << traino<<"\t\t" <<name<<"\t\t" <<age<<"\t\t" <<gender<<"\t\t" <<status<<"\t\t"<<source<<"\t\t" <<destination;
				flag=1;
			}
		}
	cout<<"\n";
			booking.close();
			if(flag!=1)
			{ system("cls");
				cout<<"\n\t\t***Invalid PNR***\n\n";
			}
        
}

void train_search_by_placegiven(char source[20],char target[20])
{
system("cls");
    ifstream train_file;
    train t;
	int flag=0;
		int k;
		

					    train_file.open("trains.txt",ios::in|ios::binary);
						char ch=train_file.get();
						system("cls");
						cout<<"TrainNo"<<"\t\t"<<"TrainName"<<"\t"<<"Source"<<"\t\t"<<"Dest"<<"\t\t"<<"Seats"<<"\t\t"<<"NoOfDays"<<"\t"<<"Days"<<"\t"<<"NoOfStops"<<"\t"<<"Stops..."<<endl<<endl;
			 			while(ch!=EOF)
						{
						 train_file.seekg(-1,ios::cur);
						 train_file.read((char *)&t,sizeof(t));
					     if( strcmp(t.start,source)==0  )
					     {
					     		int stop=0;
						 		for(k=stop;k<=t.st_num;k++)
						 		{
						 			 if(strcmp(t.stopage[k],target)==0 || strcmp(t.dest,target)==0)
						    		{
						 				t.showtrain();
						 				 cout << endl;
						 				 break;
						 			}
						 			
								}
						 }
						
						 else
						 {
						 	for(int i=0;i<t.st_num;i++)
						 	{
							     if(strcmp(t.stopage[i],source)==0)
						    	{
						 		//t.showtrain();
						 		//cout<<"LEt  destination:";
						 		int stop=i+1;
						 		for(k=stop;k<=t.st_num;k++)
						 		{
						 			 if(strcmp(t.stopage[k],target)==0 || strcmp(t.dest,target)==0)
						    		{
						 				t.showtrain();
						 				cout << endl;
						 			}
								 }
						    	}
						    	else {
						    		flag=2;
								}
					    	}
							 	flag=1;
						 }
					     ch=train_file.get();
				     	}
				if(flag==2)
				cout<<"Train Not Found";
				//else if(flag==1)
				//cout<<"Your station is not a source station of Train";
				     	train_file.close();

}



void booking() //This func is to be in railway class
{system("cls");
		int n;
	    int flag;
			char train_name_num[20];
			char train_num[20];
			train t;
			char ch5,gsource[20],gdestination[20];
			int j,day,date,mon,year;
			
			fstream train_file;
			cout <<"\n\tEnter Source:\t";
			cin>>gsource;
			cout <<"\n\tEnter Destination:\t";
			cin>>gdestination;
	     	train_search_by_placegiven(gsource,gdestination);
	     	cout<<"\n\tEnter Day of Journey(dd/mm/yyyy): "; 
            scanf("%d / %d / %d", &date, &mon, &year) ;
            day=dayofjourney(date,mon,year);
            train_search_by_plac(gsource,gdestination,day);
			cout<<"\n\tSelect train number or name:\t";
			cin>>train_name_num;
			cin.ignore();
			train_file.open("trains.txt",ios::in|ios::binary);
			getch();
			system("cls");
			cout<<"\n\n\t\t----------Your Selected Trains----------\n\n";
			cout<<"TrainNo"<<"\t\t"<<"TrainName"<<"\t"<<"Source"<<"\t\t"<<"Dest"<<"\t\t"<<"Seats"<<"\t\t"<<"NoOfDays"<<"\t"<<"Days"<<"\t"<<"NoOfStops"<<"\t"<<"Stops..."<<endl<<endl;
			 ch5=train_file.get();
			while(ch5 != EOF)
				{
					     train_file.seekg(-1,ios::cur);
						 train_file.read((char *)&t,sizeof(t));
					    if( strcmp(t.tname,train_name_num)==0  || strcmp(t.no,train_name_num)==0)
					     {
					     	
                          t.showtrain();
                          cout<<"\n\n\t\t--------------------------------------\n\n";
                          n=0;
                          fflush(stdin);
                         	cout <<"\nEnter no.of Passangers: ";
	                         cin>>n;
	                         fflush(stdin);
	                        fstream check;
	                        check.open("passenger.txt",ios::in);
	                        if(!check.eof())
	                        {
	                          update_booking(t.no);
	                   }
						     check.close();
						     int tatkal=t.seat*0.5;
	                         int remainseat=(t.seat-(top));
	                         cout<<endl;
	                         if(remainseat>tatkal)
	                         {
							 cout<<"\n\tHurry Up!! Seats Left:\t";
	                         cout << (t.seat-(top)-tatkal)<<endl;
	                         getch();
	                          fflush(stdin);
	                          
	                         for(int i=0;i<n; i++)
	                         {system("cls");
							 cout<<"\n\n\t\t\t----------Seat Map----------\n";
	                         	seatmap(t.seat);
	                         	cout<<"\n\tEnter Seat No: ";
	                         	pnr++;
	                         	 int sno;
	                         	 cin>>p[i].seatno;
	                             p[i].book(t.no,gsource,gdestination);
	                              update_booking(t.no);
	                              getch();
                             }
	                        	printticket(n,train_name_num,gsource,gdestination,date,mon,year,day);
					     }
					     
					     else { 
					     	
					       fstream check;
	                        check.open("wl.txt",ios::in);
	                        if(!check.eof())
	                        {
	                         // update_queue(t.no);
	                   }
						     check.close();
					     	int wlno=front+1;
					     	if(wlno==0)
					     	{
					     		wlno=1;
							 }
					     	cout<<"\n\t\t***Waiting List***"<<endl<<"\n\tCurrent Running Waiting List No: "<<wlno; 
					     	cout<<"\n\n\tContinue With Waiting List...Y OR N?\t";
					     	char ch9;
					     	cin>>ch9;
					     	if(ch9=='m' || ch9=='M')
             			{
             				system("cls");
             				main();
						 }
					     	if(ch9=='Y' || ch9=='y' )
					     	{
					     		waiting_list(t.no,gsource,gdestination,wlno);
					     		printticketwl(t.no,gsource,gdestination,wlno,date,mon,year,day);
							 }
							 else if(ch9=='N' || ch9=='n' )
					     	{
					     		char ch10;
					     		cout<<"\n\tWant to Book For Tatkal - T or Logout - E: \t";
					     		cin>>ch10;
					     		if(ch10=='m' || ch10=='M')
             			{
             				system("cls");
             				main();
						 }
					     		if(ch10=='T' || ch10=='t')
					     			tat();
					     		else if(ch10=='E' || ch10=='e')
					     		{
					     			system("cls");
					     			main();
								 }
								else
							 {
							 	cout<<"\n\n\t\tWrong choice...Please Enter a Valid Option...\n\n";
							 } 
					     			
							 }
							 else
							 {
							 	cout<<"\n\n\t\tWrong choice...Please Enter a Valid Option...\n\n";
							 }
						 }
						 	break;
						 }
						 else
						 {
						 	flag=1;
						 }
					     ch5=train_file.get();
				     	}
			train_file.close();

}


int main()
{
	char name[20];
	char pass[20];
	char c;
	char ch;
	int z=0,f;
	system("COLOR B0");
	while(1)
	{
	cout<<"\n\t\t\tIRCTC\t\n";
	cout<<"\n\t\tWELCOME TO INDIAN RAIlWAY\n";
	cout<<"\n\t1-> Login\n\t2-> Register\n\t3-> Enquiry\n\t4-> Cancel Ticket\n\t5-> Direct Book Ticket\n\t6-> Admin Portal\n\t7-> Check Status\n\t8-> Show All Trains\n\t9-> Dynamic Search\n\t0-> Exit\n";
	cout<<"\tEnter your choice:\t";
	cin>>ch;
	if(ch=='m' || ch=='M')
    {
    	system("cls");
        main();
	}
	switch(ch)
	{
		case '1':
			{
			 system("cls");
				login();
				break;
	    	}

		case '2':
			{system("cls");
				railway reg;
				fstream rail_user;
				cout<<"\n\n\t\t----------Register Page----------\n";
				reg.add_passenger();
				rail_user.open("registeration.txt",ios::app|ios::out);
				rail_user.write((char *)&reg,sizeof(reg));
				rail_user.close();
				system("cls");
				break;

			}
		case '3':
		{system("cls");
			char choice;
			cout<<"\n\n\t\t----------Enquiry Page----------\n";
			cout<<"\n\n\t1-> Search by Train Name Or Number\n";
			cout<<"\t2-> Train Between Places\n\tEnter your choice:\t";
			cin>>choice;
			if(choice=='m' || choice=='M')
             			{
             				system("cls");
             				main();
						 }
			switch(choice)
			{
			case '1':
				{
               train_search_by_name();
		     break;
	        	}
		    case '2':
		    	{
			   train_search_by_place();
			break;
	     		}
	     		default:
	     			{
	     				system("cls");
	     				cout<<"\n\n\t\tWrong choice...Please Enter a Valid Option...\n\n";
					 }
			}
		break;
		}
		case '0':
		{
			exit(0);
			break;
		}
		case '8':
		{system("cls");
			fstream train_file;
    		train t;
    		train_file.open("trains.txt",ios::in|ios::binary);
						char ch=train_file.get();
						system("cls");
						cout<<"TrainNo"<<"\t\t"<<"TrainName"<<"\t"<<"Source"<<"\t\t"<<"Dest"<<"\t\t"<<"Seats"<<"\t\t"<<"NoOfDays"<<"\t"<<"Days"<<"\t"<<"NoOfStops"<<"\t"<<"Stops..."<<endl<<endl<<endl;
			 			while(ch!=EOF)
						{
						 train_file.seekg(-1,ios::cur);
						 train_file.read((char *)&t,sizeof(t));
						 t.showtrain();
						 cout << endl<<endl;
						 ch=train_file.get();
						}
						
			train_file.close();
			getch();
			system("cls");
			break;
		}
		case '5':{system("cls");
		   booking();
			break;
		}
		case '6':
		{system("cls");
			fstream rail_user;
			train t1;
			char nameadm[20],passadm[20],c;
			int num_of_train,z=0;
			cout<<"\n\n\t\t----------Admin Portal----------\n\n";
				cout<<"\n\tEnter Name:\t";
				cin>>nameadm;
				cout<<"\n\tEnter Password:\t";
				while((c=getch())!=13)
             	{
             		if(isalnum(c))
             		{	 
            	  		passadm[z++]=c;
            	  		cout<<"*";
            		}
             	}
             	passadm[z]='\0';
					if(strcmp(nameadm,"admin")==0 && strcmp(passadm,"admin")==0)
				{
					cout<<"\n\n\t\t----------Admin Login Successfull !!----------\n";
					while(1)
					{
						cout<<"\n\n\t1-> Train Addition\n\t2-> Confirmed Passengers List\n\t3-> Waiting List Passengers\n";
						char ch;
						cout<<"\n\n\tEnter a Choice: ";
						cin>>ch;
						
             			if(ch=='m' || ch=='M')
             			{
             				system("cls");
             				main();
						 }
						 
						switch(ch)
						{
							case '1':
								{
								
								train_add();
								break;
							}
							case '2':
								{
									system("cls");
									cout<<"\n\n\t\t----------Confirmed List Of Passengers----------\n\n";
									char p1;
									cout<<"PNR-No"<<"\t"<<"TrNo"<<"\t"<<"SeatNo"<<"\t"<<"PName"<<"\t"<<"Age"<<"\t"<<"Gndr"<<"\t"<<"Scr"<<"\t"<<"Dst"<<endl<<endl;
									fstream pass;
									pass.open("passengers.txt",ios::in);
									while(!pass.eof())
									{
										p1=pass.get();
										cout<<p1;
									}
									pass.close();
									getch();
									system("cls");
									break;
								}
								
							case '3':
								{
									system("cls");
									cout<<"\n\n\t\t----------Waiting List Passengers----------\n\n";
									char p1;
									cout<<"PNR-No"<<"\t"<<"TrNo"<<"\t"<<"PName"<<"\t"<<"Age"<<"\t"<<"Gndr"<<"\t"<<"WL/No"<<"\t"<<"Scr"<<"\t"<<"Dst"<<endl<<endl;
									fstream pass;
									pass.open("wl.txt",ios::in);
									while(!pass.eof())
									{
										p1=pass.get();
										cout<<p1;
									}
									pass.close();
									getch();
									system("cls");
									break;
								}
							default:
								cout<<"\n\n\t\tWrong choice...Please Enter a Valid Option...\n\n";
								
						}
					}
                
				
				}
				else
				{
					system("cls");
					cout<<"\n\t\tPermission Denied...";
				}
	break;
				
		}
		case '7':
			{system("cls");
				check_status();
				break;
			}
		case '4':
			{system("cls");
				cancel();
				break;
			}
			case '9':
				{
					dynamic();
					break;
				}
		default:{
			system("cls");
			cout<<"\n\n\t\tWrong choice...Please Enter a Valid Option...\n\n";
		}
	}


}
return 0;

}

