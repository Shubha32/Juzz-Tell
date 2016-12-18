/*This is the file where all user-defined non member functions used for the package are used.Three important functions: Applicantportal(),HRportal(),Adminportal() are present which are called from the main throught the SignINProcess file(connected)...*/

//Header files used...

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iomanip>

using namespace std;

//to update application status of candidate(CONCEPT :GLOBAL VARIABLE)
int stat=0;

class Jobseeker;


struct NewUser
{
        char uname[20],mailid[25],password[10];
}U;


void appop1(Jobseeker);
void appop2(Jobseeker);
void applcngen(char[]);
void appop3();
void PDFSelectList();
void PDFCandidateList();
void PDFJobList();

//including 2 files which are called in this file...
#include "portalclass.cpp"
#include "pdfwriter.cpp"

//fn. used for random generation of application number...
void applcngen(char applcn[8])
{
	long int a,n;
        char b,c;

        srand(time(NULL));
        while(1)
        {
                n=random()%100;

                if(n>=65&&n<=90)
                {
                        b=n;
                        break;
                }
        }

	srand(time(NULL));
        a=random();
	
	//Converting the 6 digit randomly generated number into string and strcating using sprintf with the randomly generated character....
        n=sprintf(applcn, "%c%ld",b,a%1000000);
}
	

void Applicantportal(char *CurmailID,char *Curname,char *Curpassword)
{
	//CONCEPT:parameterised constructor
	Jobseeker j(CurmailID,Curname,Curpassword);

	//clrscr command using ANSI...
	cout<<"\033[2J\033[1;1H";

	int op,flag=0;
	char ch;

	//CHECKING FOR ADPPLICATION ALREADY PRESENT OR NOT USING EMAIL_ID MATCH....
	fstream f1;
	Jobseeker t;
	f1.open("candidates.dat",ios::in);
				
		//CONCEPT:FILE HANDLING EXCEPTION
                if (f1.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f1.read((char *)&t,sizeof(t));

	while(!f1.eof())
	{
		
		if(strcmp(t.emailret(),j.emailret())==0)
		{
			cout<<j.emailret()<<"\t"<<t.applcn_noret()<<"\t"<<t.applcnstatret()<<endl<<endl;
			flag =1;
			stat=1;
		
			j=t;
		
			break;
		}

		f1.read((char *)&t,sizeof(t));
	}

	if(flag==0)
	{
		cout<<j.emailret()<<"\t"<<"No applications submitted"<<endl<<endl;
	}

	f1.close();

	do
	{
//		system("clear");

		cout<<"\t1.Application Details and Status"<<endl<<endl;
		cout<<"\t2.Account Settings"<<endl<<endl;
		cout<<"\t3.Sign Out"<<endl<<endl;
		cout<<"\tOption : ";
		cin>>op;

		switch(op)
		{
			case 1:
				system("clear");
				appop1(j);
				break;
			case 2:
			
				appop2(j);
				getchar();
				break;
			case 3:
			
				
				break;
			default:
				cout<<"Invalid option";
				std::getchar();
		}
		
	//		cout<<"\033[2J\033[1;1H";
	}while(op!=3);
}

void appop1(Jobseeker j)
{
	//clrscr using ANSI...	
	cout<<"\033[2J\033[1;1H";

	int key,option;

	do
	{
	//	system("clear");

		cout<<"1.Fill Form"<<endl<<endl;
		cout<<"2.View Form"<<endl<<endl;
		cout<<"3.Update Form"<<endl<<endl;
		cout<<"4.Delete Form"<<endl<<endl;
		cout<<"5.Application Status"<<endl<<endl;
		cout<<"6.Go back"<<endl<<endl;
		cout<<"Enter option : ";
		cin>>option;
		
			if(option==1)
			{
				if(stat==1)
					cout<<"Application already submitted"<<endl<<endl;
				else
				{
					j.fillform();
				
					cout<<"\t1.SUBMIT"<<endl;
        				cout<<"\t2.CANCEL"<<endl;

        				cout<<"OPTION : ";
        				cin>>key;
					
					//IF SUBMITTED WRITTEN THE RECORD INTO THE FILE ELSE NOTHING IS DONE....
        				if(key==1)
                			{
						//CONCEPT:STATIC MEMBER FUNCTION CALLED...
						Jobseeker::incre();
                        			stat=1;
                        			fstream f;
	                       			f.open("candidates.dat",ios::out|ios::app);
        		                        if (f.fail())
                				{
                        				system("clear");
                        				cerr<<"Error in Opening File";
                        				exit(0);
                				}

			  			f.write((char *)&j,sizeof(Jobseeker));
                        			f.close();
                			}
        				else if(key==2);

        				else
                				cout<<"Invalid option";
				}
			}
			else if(option==2)
			{
				if(stat==1)
					j.viewform();
				else
					cout<<"No applications submitted"<<endl<<endl;
			}

			else if(option==3)
			{
				system("clear");

				if(stat==0)
					cout<<"No appplications submitted"<<endl<<endl;

				else
				{
					//UPDATING THAT RECORD IN THE FILE....
					j.updateform();
			
			        	fstream f;
					ofstream f3("temp.dat");
					Jobseeker k;

	       				f.open("candidates.dat",ios::in|ios::out);
        		                if (f.fail())
                			{
                        			system("clear");
                        			cerr<<"Error in Opening File";
                        			exit(0);
                			}
	
					f.seekg(0);

        				f.read((char *)&k,sizeof(k));
        				while(!f.eof())
        				{
						cout<<k.applcn_noret()<<endl<<j.applcn_noret()<<endl;
                				if(strcmp(k.applcn_noret(),j.applcn_noret())==0)
                				{
                        			
							//f.seekp(f.tellg()-sizeof(j),0);
                        				f3.write((char *)&j,sizeof(j));
						
						}
						else
							f3.write((char*)&k,sizeof(k));
						f.read((char *)&k,sizeof(k));
					}
					f.close();
					f3.close();
					
					//SYSTEM COMMAND FOR REPLACING FILE
					system("mv temp.dat candidates.dat");
				}

			}

			else if(option==4)
			{
				system("clear");
				if(stat==0)
					cout<<"No applications submitted"<<endl<<endl;
				else
				{
					j.deleteform();
					stat=0;
					//CONCEPT:STATIC MEMBER FUNCTION CALLED
					Jobseeker::decre();
				}
			}

			else if(option==5)
			{
				j.appstatus();
			}

			else if(option==6);
			
			else
				cout<<"Invalid option"<<endl;
//		std::getchar();
//		system("clear");
//		std::getchar();

		}while(option!=6);

}

void appop2(Jobseeker j)
{
	char ch,passwd[20],password1[10],password2[10];

	system("clear");

	cout<<"\tWant to change password? (y/n)";
	cin>>ch;

	if(ch=='y')
	{
		//TILL CURRENT PASSWORD CORRECTLY MATCHES WITH THE ONE ALREADY STORED...
		do
		{
			cout<<"\tCURRENT PASSWORD : ";
			cin>>passwd;
			
			

		}while(strcmp(j.passwd,passwd)!=0);
		
		//TILL NEW PASSWORD AND RETYPE PASSWORD MATCHES....
		do
		{
			cout<<"\n\tNEW PASSWORD : ";
			cin>>password1;

			cout<<"\n\tRETYPE PASSWORD : ";
			cin>>password2;
		
		}while(strcmp(password1,password2)!=0);
	
		strcpy(j.passwd,password1);
		cout<<j.passwd<<endl;
	
	//UPDATING PASSWORD IN THE FILE....
	fstream f1,f2;
	
	f1.open("usermaster.dat",ios::in);
        if (f1.fail())
        {
              system("clear");
              cerr<<"Error in Opening File";
              exit(0);
        }

	f1.read((char*)&U,sizeof(U));
	f2.open("temp",ios::out);
	while(!f1.eof())
	{
		if (strcmp(U.mailid,j.email_id)==0)
		{
			strcpy(U.password,j.passwd);
//			f.seekp(-1*sizeof(U),ios_base::cur);
		//	f2.write((char*)&U,sizeof(U));
			cout <<"Updated";
			
		}
		f2.write((char*)&U,sizeof(U));
		f1.read((char*)&U,sizeof(U));
	}
	f1.close();
	f2.close();
	system("mv temp usermaster.dat");
	}
}


void HRPortal(char uname[],char umail[],char upass[])
{
	int op;
	//CONCEPT:PARAMETERISED CONSTRUCTOR USED...
	HRMan h(uname,umail,upass);
	JobRequirement j1;
	
	do{
	system("clear");
	
	cout<<"\t1.Add Job\n\n";
	cout<<"\t2.Update Job\n\n";
	cout<<"\t3.Delete Job\n\n";
	cout<<"\t4.Display Job\n\n";
	cout<<"\t5.Download as PDF\n\n";
	cout<<"\t6.Sign out\n\n";

	cout<<"Option : ";
	cin>>op;

	switch(op)
	{
		case 1:
			AddJob(h,j1);
			getchar();
			getchar();
			break;
		case 2:
			UpdateJob(h,j1);
			getchar();
			getchar();
			break;
		case 3:
			DeleteJob(h,j1);
			getchar();
			getchar();
			break;
		case 4:
			DisplayJob(h,j1);
			getchar();
			getchar();
			break;
		case 5:
			PDFJobList();
			break;
		case 6:
			cout <<"Signing Out";
			break;
		default:
			cout<<"Invalid Input"<<endl;
	}
	}while(op!=6);
}

void AdminPortal()
{
	Admin *Ad;			// Pointer Variable 
	Ad = new Admin();		// Dynamic Memory Allocation
	int op;
        do{
		system("clear");

        	cout<<"\t1.Update Threshold Value\n\n";
        	cout<<"\t2.Map Candidate and Job Requirement\n\n";
	        cout<<"\t3.Generate Reports\n\n";
	        cout<<"\t4.Sign out\n\n";
	        cout<<"Option : ";
        	cin>>op;
	        switch(op)
        	{
                	case 1:
				Ad->Fixthreshold();
				getchar();
				getchar();
				break;
			case 2:
				Ad->Compute();
				getchar();
				getchar();
				break;
			case 3:
				int t;
				cout <<"\t1.List of Candidates\n";
				cout<<"\t2.Job List\n";
				cout<<"\t3.Selected Candidates\n";
				cout<<"Enter Choice";
				cin >> t;
				switch (t)
				{
					case 1:
						Ad->CandidateReport();
						break;
					case 2: Ad->JobReport();
						break;
					case 3: Ad->SelectedReport();
						break;
					default: cout <<"Invalid";
				}
			
		}
	} while (op!=4);
	
	delete Ad;
}
		
//CONCEPT:COMMAND LINE ARGUMENT....			
int main(int n, char *arg[30])
{
	if (n!=5)
	{
		cout <<"Invalid Arguments";
		exit(0);
	}
	if (strcmp(arg[1],"Admin")==0)
		AdminPortal();

	else if (strcmp(arg[1],"Applicant")==0)
		Applicantportal(arg[2],arg[3],arg[4]);
	else
		HRPortal(arg[2],arg[3],arg[4]);

	return 0;

}
