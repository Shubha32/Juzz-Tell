/*This is the file that contains all classes related to the package and the respective member functions that they contain.There are 5 main classe:User,Jobseeker,HRMan,JobRequirement,Admin,User and 2 small classes:dob and company....*/   

//All header files used....
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;

class Jobseeker;

class User
{
	protected:
	char name[20];
	char email_id[25];
	char passwd[10];
	public :
		//CONCEPT:USAGE OF CONSTRUCTORS....
		User()
		{

		}
		User(char *mailid,char *nam,char *password )
		{
			strcpy(name,nam);
			strcpy(email_id,mailid);
			strcpy(passwd,password);
		}
		char *emailret()
		{
			return email_id;
		}

		//CONCEPT:FRIEND FUNCTION...
		friend void appop2(Jobseeker);
		virtual void DisplayUser() = 0;		//Pure Virtual Function				
};

class dob
{
	char  d[11];
	public:
		void accept();
		void display();
};

//CONCEPT:INLINE....
void dob::accept()
{
	int i,j,knt=0,n1,n2,n3;
	j=0;
	char str1[5];
	char str2[5];
	char str3[5];
	cin>>d;
	//cout<<d<<endl;
	//VALIDATION FOR DOB...
	/*for(i=0;d[i]!='\0';i++)
	{
		if(knt==0)
		{
			if(d[i]=='.')
			{
				str1[j]='\0';
				n1=atoi(str1);
				knt=1;
				j=0;
			}
			else
			{
				str1[j]=d[i];
				j++;
			}	
		}

		else if(knt==1)
                {
                        if(d[i]=='.')
                       	{       str2[j]='\0';
                                n2=atoi(str2);
                                knt=2;
                                j=0;
                       	}
			else
			{
				str2[j]=d[i];
				j++;
			}
                }

		else if(knt==2)
                {
			if(d[i]!='.')
			{
                        	str3[j]=d[i];
                       		j++;
			}
                }

		cout<<knt<<" "<<d[i]<<" "<<endl;
	}
	str3[j]='\0';
	n3=atoi(str3);
	cout<<n1<<endl<<n2<<endl<<n3<<endl;
	if(n1>0&&n1<32&&n2>0&&n2<13)
	{
		if(n3%4==0)
		{
			if(n3%100==0)
			{
				if(n3%400==0)
				{
					ly=1;
				}
				else
				{
					ly=0;
				}
			}
			else
			{
				ly=1;
			}
		}
		else
		{
			ly=0
			

	}
	
	else
	{
		cout<<"Invalid";
	}*/
}

void dob::display()
{
	cout<<d;
}

class company
{
	char compname[20];
	float exp;
	char title[15];
	float salary;

	public:
		void accept();
		void display();
		friend class Admin;
};

void company::accept()
{ 
   try {
	cout<<"\t\tCompany Name : ";
	cin>>compname;
	cout<<"\t\tExperience(years) : ";
	cin>>exp;
	cout<<"\t\tTitle : ";
	cin>>title;
	cout<<"\t\tSalary : ";
	cin>>salary;

	//CONCEPT:EXCEPTION HANDLING....
	if (salary<=0)
		throw "Salary Cannot be Negative";
	cout<<endl<<endl;
    }
    catch(exception& e)
    {
        cout <<e.what()<<"Invalid Data";
    }
}	

void company::display()
{
	cout<<"\t\tCompany Name : ";
        cout<<compname<<endl;
        cout<<"\t\tExperience(years) : ";
        cout<<exp<<endl;
        cout<<"\t\tTitle : ";
        cout<<title<<endl;
        cout<<"\t\tSalary : ";
        cout<<salary<<endl;
        cout<<endl<<endl;
}

//CONCEPT:IS A RELATIONSHIP
class Jobseeker:public User
{
	//CONCEPT:HAS A RELATIONSHIP
	dob d;
	char street[30],city[10],state[10],pin[8];
	char phone[11];
	char ugdeg[10],ugmajor[20],ugcollege[20];
	char pgdeg[10],pgmajor[20],pgcollege[20];
	char addndegree[30];
	float ugcgpa,pgcgpa;
	int no_companies;
	company c[10];
	char skills[50];
	char reference1[50],reference2[50];
	char applcn_no[8];
	char status[15];
	//CONCEPT:STATIC DATA MEMBER FOR TOTAL APPLICATIONS...
	static int no_candidates;

	public:
		
		char * appnoret()
		{
			return applcn_no;
		}
		char * nameret()
		{
			return name;
		}
		Jobseeker()
		{

		}
		//CONCEPT:INITILALISER LIST(CONSTRUCTOR),(INHERITANCE)
		Jobseeker(char *mailid,char *name,char *password):User(mailid,name,password)
		{
			strcpy(email_id,mailid);
			strcpy(name,name);
			strcpy(passwd,password);

		}
		
		void DisplayUser()
		{
			viewform();
		}
		char *applcnstatret()
		{
			return status;
		}

		void fillform();
		void deleteform();
		void viewform();
		void updateform();
		void appstatus();
		char * applcn_noret()
		{
			return applcn_no;
		}
		char * passwdret()
		{
			return passwd;
		}

		static void incre()
		{
			no_candidates++;
		}

		static void decre()
		{
			no_candidates--;
		}

		static int nocandret()
		{
			return no_candidates;
		}
				
		//CONCEPT:FRIEND CLASS
		friend class Admin;
		friend void PDFCandidateList();
};

int Jobseeker::no_candidates=0;


inline void Jobseeker::fillform()
{
	int key,i;
	
	cout<<"\033[2J\033[1;1H";

	cout<<"\t\tNAME: "<<name<<"\t\t";
	cout<<"APPCN NO. :";
	applcngen(applcn_no);
	cout<<applcn_no<<endl<<endl;
	
	//EXCEPTION HANDLING....
  try
  {
	cout<<"PERSONAL INFORMATION : "<<endl<<endl;
	cout<<"\t\tDate of Birth : ";
	d.accept();
	cout<<"\t\tAddress : \n\t\t\tStreet : ";
	cin>>street;
	cout<<"\t\t\tCity : ";
	cin>>city;

	cout<<"\t\t\tState : ";
	cin>>state;

	cout<<"\t\t\tPIN Code : ";
	cin>>pin;

	cout<<"\t\tMobile No. : ";
	cin>>phone;

	cout<<endl<<endl<<"EDUCATION : "<<endl<<endl;
	cout<<"\t\tUG Degree : ";
	cin>>ugdeg;
	cout<<"\t\tMajor : ";
	cin>>ugmajor;
	cout<<"\t\tCollege : ";
	cin>>ugcollege;
	cout<<"\t\tCGPA :";
	cin>>ugcgpa;

	if(ugcgpa>10.0)
		throw(0);
	
	
	cout<<endl;
	
	cout<<"\t\tPG Degree : ";
        cin>>pgdeg;
        cout<<"\t\tMajor : ";
        cin>>pgmajor;
        cout<<"\t\tCollege : ";
        cin>>pgcollege;
        cout<<"\t\tCGPA :";
        cin>>pgcgpa;
        cout<<endl;

	cout<<"\t\tAdditional Degrees : ";
	cin>>addndegree;

	cout<<endl<<endl<<"WORK :"<<endl<<endl;
	cout<<"\t\tNo. of companies worked in : ";
	cin>>no_companies;

	for(i=0;i<no_companies;i++)
		c[i].accept();

	cout<<"ADDITIONAL DETAILS : "<<endl<<endl;
	cout<<"\t\tProgramming Skills : ";
	cin>>skills;

	cout<<endl<<endl<<"REFERENCES :"<<endl<<endl;
	cout<<"\t\tReference 1 : ";
	cin>>reference1;
	cout<<endl<<"\t\tReference 2 : ";
	cin>>reference2;
	strcpy(status,"Under Process");
	cout<<endl<<endl;
   }

  catch(int a)
  {
	cerr<<"CGPA exceeded 10.0"<<endl;
  }

  catch(char *e)
  {
	cerr<<e<<endl;
  }
  
}


inline void Jobseeker::deleteform()
{
//	system("clear");

	cout<<"Application successfully deleted "<<endl<<endl;

	Jobseeker k;
	fstream f,f1;
	f.open("candidates.dat",ios::in);
                if (f.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f1.open("temp.dat",ios::out);
                if (f1.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f.read((char *)&k,sizeof(k));
	while(!f.eof())
	{
		if(strcmp(k.applcn_no,applcn_no)==0)
			break;
		else
			f1.write((char *)&k,sizeof(k));
		f.read((char *)&k,sizeof(k));
	}

	f.read((char *)&k,sizeof(k));
	while(!f.eof())
	{
		f1.write((char *)&k,sizeof(k));
		f.read((char *)&k,sizeof(k));
	}

	remove("candidates.dat");
	rename("temp.dat","candidates.dat");
			
	f.close();
	f1.close();
	getchar();

}

inline void Jobseeker::updateform()
{
//	system("clear");

	int op,op1,i;
//	system("clear");
//GET THE PARAMETER TO BE UPDATED....
	cout<<"1.Personal Information"<<endl<<endl;
	cout<<"2.Education"<<endl<<endl;
	cout<<"3.Work"<<endl<<endl;
	cout<<"4.Additional Details"<<endl<<endl;
	cout<<"5.References"<<endl;
	cout<<endl<<"Option : ";
	cin>>op;
	
	switch(op)
	{
		case 1:
			cout<<"1.Date of birth"<<endl;
			cout<<"2.Address"<<endl;
			cout<<"3.Mobile No."<<endl;
			cout<<endl<<"Option: ";
			cin>>op1;

			switch(op1)
			{
				case 1:
					cout<<"\tDate of birth : ";
					d.accept();
					break;
				case 2:
					cout<<"\tAddress : \n\t\tStreet : ";
				        cin>>street;
        				cout<<"\t\tCity : ";
        				cin>>city;
        				cout<<"\t\tState : ";
        				cin>>state;
					cout<<"\t\tPIN Code : ";
        				cin>>pin;
					break;	
				case 3:
					cout<<"\tMobile No. : ";
					cin>>phone;
					break;
				default:
					cout<<"Invalid Option"<<endl<<endl;
			}
			break;
		case 2:
			cout<<"1.UG Degree"<<endl;
			cout<<"2.PG Degree"<<endl;
			cout<<"3.Additional Degree"<<endl;
			cout<<endl<<"Option : ";
			cin>>op1;

			switch(op1)
			{
				case 1:
					cout<<"\tUG Degree : ";
				        cin>>ugdeg;
        				cout<<"\tMajor : ";
        				cin>>ugmajor;
        				cout<<"\tCollege : ";
        				cin>>ugcollege;
        				cout<<"\tCGPA :";
        				cin>>ugcgpa;
        				cout<<endl;
					break;
				case 2:
					cout<<"\tPG Degree : ";
                                        cin>>pgdeg;
                                        cout<<"\tMajor : ";
                                        cin>>pgmajor;
                                        cout<<"\tCollege : ";
                                        cin>>pgcollege;
                                        cout<<"\tCGPA :";
                                        cin>>pgcgpa;
                                        cout<<endl;
                                        break;		
				case 3:
					cout<<"\tAdditional Degrees : ";
					cin>>addndegree;
					break;
				default:
					cout<<"Invalid Option"<<endl<<endl;
			}
		case 3:
			cout<<"\t\tNo. of companies worked in : ";
		        cin>>no_companies;

        		for(i=0;i<no_companies;i++)
                		c[i].accept();

			break;			
		case 4:
			cout<<"\tProgramming Skills : ";
		        cin>>skills;
			break;
		case 5:	
			cout<<"1.Reference 1 "<<endl;
			cout<<"2.Reference 2 "<<endl;
			cout<<endl<<"Option : ";
			cin>>op1;

			switch(op1)
			{
				case 1:
					cout<<"\tReference 1 : ";
					cin>>reference1;
					break;
				case 2:
					cout<<"\tReference 2 : ";
					cin>>reference2;
					break;
				default:
					cout<<"Invalid Option"<<endl<<endl;
			}
		default:
			cout<<"Invalid Option"<<endl<<endl;
	}
	getchar();

}

inline void Jobseeker::viewform()
{
//	system("clear");

	int i,flag=0;
	Jobseeker k;
	fstream f;
	f.open("candidates.dat",ios::in);
                if (f.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f.seekg(0);
	cout<<applcn_no;
	f.read((char *)&k,sizeof(k));
	while(!f.eof())
	{
		if(strcmp(k.applcn_no,applcn_no)==0)
		{
			cout<<"\t\tNAME: "<<k.name<<"\t\t";
		        cout<<"APPCN NO. :";
        		cout<<k.applcn_no<<endl<<endl;

        		cout<<"PERSONAL INFORMATION : "<<endl<<endl;
        		cout<<"\t\tDate of Birth : ";
        		k.d.display();
        		cout<<"\n\t\tAddress : \n\t\t\tStreet : ";
        		cout<<k.street<<endl;
        		cout<<"\t\t\tCity : ";
        		cout<<k.city<<endl;

        		cout<<"\t\t\tState : ";
        		cout<<k.state<<endl;
	
			cout<<"\t\t\tPIN Code : ";
		        cout<<k.pin<<endl;

        		cout<<"\t\tMobile No. : ";
        		cout<<k.phone<<endl;

			getchar();

        		cout<<endl<<endl<<"EDUCATION : "<<endl<<endl;
        		cout<<"\t\tUG Degree : ";
        		cout<<k.ugdeg<<endl;
        		cout<<"\t\tMajor : ";
        		cout<<k.ugmajor<<endl;
        		cout<<"\t\tCollege : ";
        		cout<<k.ugcollege<<endl;
        		cout<<"\t\tCGPA :";
        		cout<<k.ugcgpa<<endl;
        		cout<<endl;

			cout<<"\t\tPG Degree : ";
		        cout<<k.pgdeg<<endl;
        		cout<<"\t\tMajor : ";
        		cout<<k.pgmajor<<endl;
        		cout<<"\t\tCollege : ";
        		cout<<k.pgcollege<<endl;
        		cout<<"\t\tCGPA :";
        		cout<<k.pgcgpa<<endl;
        		cout<<endl;

        		cout<<"\t\tAdditional Degrees : ";
        		cout<<k.addndegree<<endl;

			getchar();

			cout<<endl<<endl<<"WORK :"<<endl<<endl;
		        cout<<"\t\tNo. of companies worked in : ";
        		cout<<k.no_companies<<endl;

        		for(i=0;i<no_companies;i++)
                		k.c[i].display();

			getchar();

        		cout<<"ADDITIONAL DETAILS : "<<endl<<endl;
        		cout<<"\t\tProgramming Skills : ";
        		cout<<k.skills<<endl;

        		cout<<endl<<endl<<"REFERENCES :"<<endl<<endl;
        		cout<<"\t\tReference 1 : ";
        		cout<<k.reference1<<endl;
        		cout<<endl<<"\t\tReference 2 : ";
        		cout<<k.reference2<<endl;

        		cout<<endl<<endl;
			
			flag=1;
			break;
		}
		f.read((char*)&k,sizeof(k));
	}

	if(flag==0)
		cout<<"No applications submitted"<<endl<<endl<<endl;
	f.close();

}

//IF APPLICATION PRESENT:"UNDER PROCESS" ELSE "APPLICATIONS NOT SUBMITTED"
inline void Jobseeker::appstatus()
{
//	system("clear");

	int flag=0;
	Jobseeker k;
	fstream f;
	
	f.open("candidates.dat",ios::in);
                if (f.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

//	f.seekg(0);

	f.read((char *)&k,sizeof(k));

	while(!f.eof())
	{
		if(strcmp(k.applcn_no,applcn_no)==0)
		{
			cout<<"Under Process"<<endl<<endl;
			flag =1;
		}
		f.read((char *)&k,sizeof(k));
	}

	if(flag==0)
		cout<<"No applications submitted"<<endl<<endl;

	f.close();
	getchar();

}

class JobRequirement;

class HRMan:public User
{

	char compname[20];
	
	public :
		HRMan(char name1[], char pass[], char mailid[])
		{
			strcpy(name,name1);
			strcpy(passwd,pass);
			strcpy(email_id, mailid);
		}
		
		//CONCEPT:FRIENDS....
		friend void AddJob(HRMan&,JobRequirement&);
		friend void DeleteJob(HRMan&,JobRequirement&);
		friend void UpdateJob(HRMan&, JobRequirement&);
		friend void download(HRMan&, JobRequirement&);
		friend void DisplayJob(HRMan &, JobRequirement&);
 		void DisplayUser()
		{
			cout <<"Name : "<<name <<"\nMailID"<<email_id;
		}
};

class JobRequirement
{
        char JobDesc[10];
        char job_id[8];
        char desig[15];
        float  exp;
        float exp_weight;
	char Qualification[10];
	float Qual_weight;
        float CGPA;
	float CGPA_weight;
        char skills[20];
	float skills_weight;
	float th_value;
        public:
               	friend void AddJob(HRMan&, JobRequirement&);
                friend void DeleteJob(HRMan&, JobRequirement&);
                friend void UpdateJob(HRMan&,JobRequirement&);
		friend void DisplayJob(HRMan&, JobRequirement&);
                friend void download(HRMan&,JobRequirement&);
		friend class Admin;
		friend void PDFJobList();
};

void DisplayJob(HRMan &h, JobRequirement &Job1)
{
	char jid[10];
        cout << "Enter the Job ID ";
        cin>>jid;
	fstream f1;
        f1.open("JobDetails.dat", ios::in);
                if (f1.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

        int flag=0;
        f1.read((char*)&Job1,sizeof(Job1));
        while(!f1.eof())
        {
                if (strcmp(Job1.job_id,jid)==0)
		{
                        flag = 1;
			break;
		}
                f1.read((char*)&Job1,sizeof(Job1));
        }
	f1.close();
	if (flag)
	{
	        cout << "Designation : "<<Job1.desig<<endl;
	        cout << "Nature of Job : "<< Job1.JobDesc<<endl;
	        cout <<"Required Qualification"<<Job1.Qualification<<endl;
	        cout<< "Importance of Qualification (Weight)"<<Job1.Qual_weight<<endl;
        	cout <<"CGPA"<<Job1.CGPA<<endl;
	        cout<<"Importance of CGPA (weight)"<<Job1.CGPA_weight<<endl;
	        cout<<"Minimum Experience :"<<Job1.exp<<endl;
	        cout<<"Importance of Experience (weight)"<<Job1.exp_weight<<endl;
        	cout<<"Skills (Separated by comma:"<<Job1.skills<<endl;
	        cout<<"Importance of Skills (weight)"<<Job1.skills_weight<<endl;
	}
	else
		cout <<"Not found\n";
}

void AddJob(HRMan &h, JobRequirement &Job1)
{

	cout << "Enter the Company Name : ";
	cin>>h.compname;
	cout <<"Job ID : ";
	cin >>Job1.job_id;
	cout << "Enter the Designation : ";
	cin >>Job1.desig;
	cout << "Enter the Nature of Job : ";
	cin >> Job1.JobDesc;
	cout <<"Required Qualification (Separated by comma like MCA,BE) : ";
	cin>>Job1.Qualification;
	cout<< "Importance of Qualification (Weight) : ";
	cin>>Job1.Qual_weight;
	cout <<"CGPA : ";
	cin>>Job1.CGPA;
	cout<<"Importance of CGPA (weight) : ";
	cin>>Job1.CGPA_weight;
	cout<<"Minimum Experience : ";
	cin>>Job1.exp;
	cout<<"Importance of Experience (weight) : ";
        cin>>Job1.exp_weight;
	cout<<"Skills (Separated by comma) : ";
        cin>>Job1.skills;
        cout<<"Importance of Skills (weight) : ";
        cin>>Job1.skills_weight;
	Job1.th_value=0;
	fstream f1;
	f1.open("JobDetails.dat",ios::out|ios::app);
                if (f1.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f1.write((char*)&Job1, sizeof(Job1));
	f1.close();
	cout<<"\nAdded";

}

void DeleteJob(HRMan &h, JobRequirement &Job1)
{
	char j1[10];
	cout << "Enter the Job ID";
	cin >>j1;
	fstream f1,f2;
	f1.open("JobDetails.dat", ios::in);
                if (f1.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f2.open("temp",ios::out);
                if (f2.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	int flag=0;
	f1.read((char*)&Job1,sizeof(Job1));
	while(!f1.eof())
	{
		if (strcmp(Job1.job_id,j1)!=0)
			f2.write((char*)&Job1,sizeof(Job1));
		else
			flag=1;
		f1.read((char*)&Job1,sizeof(Job1));
	}
	f1.close();
	f2.close();
	system("mv temp JobDetails.dat");
	if(flag)
		cout<<"Deleted\n";
	else
		cout<<"Not Found\n";
}

void UpdateJob(HRMan &h, JobRequirement &Job1)
{
	char jid[10];
        cout <<"Job ID : ";
        cin >>jid;
       

	fstream f1,f2;
        f1.open("JobDetails.dat", ios::in);
                if (f1.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

        f2.open("temp",ios::out);
                if (f2.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	int flag=0;
        f1.read((char*)&Job1,sizeof(Job1));
        while(!f1.eof())
        {
                if (strcmp(Job1.job_id,jid)==0)
		{
			cout<< "Importance of Qualification (Weight) : ";
		        cin>>Job1.Qual_weight;
		        cout<<"Importance of CGPA (weight) : ";
			cin>>Job1.CGPA_weight;
		        cout<<"Importance of Experience (weight) : ";
		        cin>>Job1.exp_weight;	
		        cout<<"Importance of Skills (weight) : ";
		        cin>>Job1.skills_weight;
			flag=1;
		}

                f2.write((char*)&Job1,sizeof(Job1));

                f1.read((char*)&Job1,sizeof(Job1));
        }
	f1.close();
        f2.close();
        system("mv temp JobDetails.dat");
	if (flag)
		cout <<"Updated\n";
	else
		cout <<"Not Found\n";
}

class Admin:public User
{
	public:
		void Compute();

		void Fixthreshold();

		void CandidateReport()
		{
			PDFCandidateList();
		}
		void JobReport()
		{
			PDFJobList();
		}
		void SelectedReport()
		{
			PDFSelectList();
		}
		friend class JobRequirement;
		void DisplayUser()
		{
			cout <<"Name  : "<<name<<"\n Mail ID"<<email_id;
		}

		~Admin()
		{

		}
};

void Admin::Fixthreshold()
{
	char jobid[8];

	cout<<"Job Id : ";
	cin>>jobid;
	
	float thresh;
	JobRequirement t;
	int flag=0;
//AFTER FIXING THRESHOLD VALUE...WRITE THE RECORD INTO THE FILE:UPDATION
	fstream f,f1;
	f.open("JobDetails.dat",ios::in);
                if (f.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f1.open("temp.dat",ios::out);
                if (f1.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f.read((char *)&t,sizeof(t));

	while(!f.eof())
	{
		if(strcmp(t.job_id,jobid)==0)
		{
			flag=1;
			cout<<endl<<"Threshold value : ";
			cin>>thresh;
			t.th_value=thresh;
			//f1.write((char *)&t,sizeof(t));
			//break;
		}
		f1.write((char *)&t,sizeof(t));
		f.read((char *)&t,sizeof(t));
	}

	if(flag==0)
		cout<<"Job ID not found!"<<endl<<endl;
	else
		cout<<"Threshold value successfully fixed"<<endl<<endl;
	
	remove("JobDetails.dat");
	rename("temp.dat","JobDetails.dat");
	f.close();
	f1.close();
}

/*The sum of all the weights given by the HR are calculated and by using the computational formula,mvalue for every candidate is calculated.If the mvalue
is less than the threshold value fixed by the HR then he is "NOT SELECTED" else he is "SELECTED"...*/ 
void Admin::Compute()
{
	
	int i,t1;
	float totalwt=0.0;
	float jobexptot=0.0;
	float selcgpa=0.0;
	char jobid[10];

	fstream f_select,f_temp;
	f_select.open("selected.dat",ios::out);
                if (f_select.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f_temp.open("temp.dat",ios::out);
                if (f_temp.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	cout<<"Job Id : ";
        cin>>jobid;

        JobRequirement t;
	Jobseeker j;
	char *sk;
        int flag=0;
	float mval=0.0;
	int tell=0;
	
	char deg[8];
	char *att;
	char skill[50];
	char str[8],str1[10];

        fstream f,f1;
        f.open("JobDetails.dat",ios::in);
                if (f.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f1.open("candidates.dat",ios::in);
                if (f1.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	f.read((char *)&t,sizeof(t));
        while(!f.eof())
        {
                if(strcmp(t.job_id,jobid)==0)
                {
                        flag=1;
                        break;
                }
                f.read((char *)&t,sizeof(t));
        }
	
	if(t.th_value!=0&&flag==1)
	{
		totalwt=t.exp_weight+t.Qual_weight+t.CGPA_weight+t.skills_weight;

	f1.read((char *)&j,sizeof(j));
	while(!f1.eof())
	{
		{
	        	jobexptot=0.0;
        		selcgpa=0.0;

		        mval=0.0;
        		tell=0;
			t1=0;
			for(i=0;i<j.no_companies;i++)
				jobexptot+=j.c[i].exp;
				
			if(strcmp(j.pgdeg,"-")==0)
			{
				strcpy(deg,j.ugdeg);
				tell=0;
			}

			else
			{
				strcpy(deg,j.pgdeg);
				tell=1;
			}

			if(tell==0)
				selcgpa=j.ugcgpa;	
		
			else
				selcgpa=j.pgcgpa;
			
			strcpy(skill,j.skills);

			if(jobexptot>=t.exp)
				mval+=(1*t.exp_weight);

			if(selcgpa>=t.CGPA)
				mval+=(1*t.CGPA_weight);

			strcpy(str,t.Qualification);

			//strtok is a function used to extract substrings given a delimiter...
			att=strtok(str,",");
			
			while(att!=NULL)
			{
				if(strcmp(att,deg)==0)
				{
					mval+=(1*t.Qual_weight);
					break;
				}
				att=strtok(NULL,",");
			}
				
			sk=strtok(skill,",");
			while(sk!=NULL)
			{
				if(t1==1)
					break;
				
				strcpy(str1,t.skills);		
				att=strtok(str1,",");
                        	while(att!=NULL)
                        	{
                                	if(strcmp(att,sk)==0)
                                	{
                                        	mval+=(1*t.skills_weight);
						t1=1;
                                        	break;
					}
                                
                                	att=strtok(NULL,",");
				}
				sk=strtok(NULL,",");
                        }

			mval=mval/totalwt;

			if (mval>=t.th_value)
			{
				strcpy(j.status,"Selected");
				f_select.write((char*)&j,sizeof(j));
			}
			else
			{
				strcpy(j.status,"Not Selected");	
			}
			f_temp.write((char*)&j,sizeof(j));
	
		}
		f1.read((char *)&j,sizeof(j));
	}
	system("mv temp.dat candidates.dat");
	}
	else
		cout <<"Not Found or Threshold Value Not Set";
	f.close();
	f1.close();
	f_select.close();
	f_temp.close();	

}
