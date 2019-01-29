#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<dos.h>
using namespace std;
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

int main()
{
	char name[20];
	char pass[20];
	char ch;
	int z=0,f;
	system("COLOR B0");
system("cls");
			fstream rail_user;
			train t1;
			char nameadm[20],passadm[20],c;
			int num_of_train;
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
				else
				{
					system("cls");
					cout<<"\n\t\tPermission Denied...";
				}
	
			system("cls");
			cout<<"\n\n\t\tWrong choice...Please Enter a Valid Option...\n\n";

return 0;

}


