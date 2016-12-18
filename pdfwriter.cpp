/*Used for generating the report in PDF format.There are 4 sections for the beginning,then your commands after which comes 6 sections....This is used for genearting 3 PDF Reports....*/

void PDFJobList()
{
        char str[100];
        JobRequirement x;
        int i,sno;
        ofstream f1;
        f1.open("Job_list.pdf");
        if (f1.fail())
        {
              system("clear");
              cerr<<"Error in Opening File";
              exit(0);
        }

        ifstream f2,f3;
        f2.open("pdftemplate_beg.txt");
        if (f2.fail())
        {
              system("clear");
              cerr<<"Error in Opening File";
              exit(0);
        }
        
	while (f2.getline(str,100))
        {
                f1<<str<<"\n";
        }
	f2.close();
        f3.open("JobDetails.dat");
        if (f3.fail())
        {
               system("clear");
               cerr<<"Error in Opening File";
               exit(0);
        }
      
	f1<<"BT\n/F1 24 Tf\n";
        f1<<"120  750 Td\n";
        f1 << "( List of Jobs ) Tj\n";
        f1<< "BT\n";
        f1<<"/F1  12 Tf\n";
        f1<<"80  700 Td\n";
        f1<<"( ------------------------------------------------------------------------------------------------------------- ) Tj\n";
        f1<<"BT\n";
        f1<<"80  690 Td\n";
        f1<<"( S.No.	   JobNo.    Desig      Exp      Qualification    CGPA     Skills   Threshold Value ) Tj\n";

        f1<<"BT\n";
        f1<<"80  680  Td\n";
        f1<<"( ------------------------------------------------------------------------------------------------------------- ) Tj\n";
        i=675;
	sno=1;
	while(f3.read((char*)&x,sizeof(x)))
        {
                f1<<"BT\n";
                f1<<"80  "<<i<<"  Td\n";
                i-=15;
                f1<<"( "<<sno<<"          " <<x.job_id<<"        "<<x.desig<<"              "<<x.exp<<"       "<<x.Qualification<<"              "<<x.CGPA<<"          "<<x.skills<<"     "<<x.th_value<<")  Tj\n";
                sno+=1;
        }

	f1<<"ET\n";
        f1<<"endstream\n";
        f1<<"endobj\n";

        f2.open("pdftemplate_end.txt");
        if (f2.fail())
        {
               system("clear");
               cerr<<"Error in Opening File";
               exit(0);
        }

	while (f2.getline(str,100))
        {
                f1<<str<<"\n";
        }
	f2.close();
        f1.close();
        try{
	system ("evince  Job_list.pdf");
      //  cout<<"Hai";

        }
	catch (exception& e)
        {
              cout<<"Failed to open PDF";
        }
}
void PDFCandidateList()
{
        char str[100];
        Jobseeker x;
        int i,sno;
        ofstream f1;
        f1.open("Candidate_list.pdf");
        if (f1.fail())
        {
               system("clear");
               cerr<<"Error in Opening File";
               exit(0);
        }

	ifstream f2,f3;
        f2.open("pdftemplate_beg.txt");
        if (f2.fail())
        {
              system("clear");
              cerr<<"Error in Opening File";
              exit(0);
        }

	while (f2.getline(str,100))
        {
                f1<<str<<"\n";
        }
	f2.close();
        f3.open("candidates.dat");
        if (f3.fail())
        {
              system("clear");
              cerr<<"Error in Opening File";
              exit(0);
        }
        
	f1<<"BT\n/F1 24 Tf\n";
        f1<<"120  750 Td\n";
        f1 << "( List of  Candidates ) Tj\n";
        f1<< "BT\n";
	f1<<"BT\n/F1 16 Tf\n";
	f1<<"80 720 Td\n";
	f1<<"(Total No. of Applications :"<<Jobseeker::nocandret()<<") Tj\n";
	f1<<"BT\n";
        f1<<"/F1  12 Tf\n";
        f1<<"80  700 Td\n";
        f1<<"( ------------------------------------------------------------------------------------------------------------- ) Tj\n";
        f1<<"BT\n";
        f1<<"80  690 Td\n";
        f1<<"( S.No.	   Application Number                        Name                           ) Tj\n";

        f1<<"BT\n";
        f1<<"80  680  Td\n";
        f1<<"( ------------------------------------------------------------------------------------------------------------- ) Tj\n";
        i=675;
	sno=1;
	while(f3.read((char*)&x,sizeof(x)))
        {
                f1<<"BT\n";
                f1<<"80  "<<i<<"  Td\n";
                i-=15;
                f1<<"( "<<sno<<"                             " <<x.appnoret()<<"                               "<<x.nameret()<<")  Tj\n";
                sno+=1;
        }

	f1<<"ET\n";
        f1<<"endstream\n";
        f1<<"endobj\n";

        f2.open("pdftemplate_end.txt");
        if (f2.fail())
        {
               system("clear");
               cerr<<"Error in Opening File";
               exit(0);
        }

	while (f2.getline(str,100))
        {
                f1<<str<<"\n";
        }
	f2.close();
        f1.close();
	try{
	system ("evince  Candidate_list.pdf");
	cout<<"Hai";

	}
	catch (exception& e)
	{
              cout<<"Failed to open PDF";
	}
}

void PDFSelectList()
{
	char str[100];
	Jobseeker x;
	int i,sno;
	ofstream f1;
	f1.open("Selection_list.pdf");
        if (f1.fail())
        {
              system("clear");
              cerr<<"Error in Opening File";
              exit(0);
        }
	
	ifstream f2,f3;
	f2.open("pdftemplate_beg.txt");
        if (f2.fail())
        {
              system("clear");
              cerr<<"Error in Opening File";
              exit(0);
        }

	while (f2.getline(str,100))
	{
		f1<<str<<"\n";
	}
	f2.close();
	f3.open("selected.dat");
        if (f3.fail())
        {
               system("clear");
               cerr<<"Error in Opening File";
               exit(0);
        }

	f1<<"BT\n/F1 24 Tf\n";
	f1<<"120  750 Td\n";
	f1 << "( List of Selected Candidates ) Tj\n";
	f1<< "BT\n";
	f1<<"/F1  12 Tf\n";
	f1<<"80  700 Td\n";
	f1<<"( ------------------------------------------------------------------------------------------------------------- ) Tj\n";
	f1<<"BT\n";
	f1<<"80  690 Td\n";
	f1<<"( S.No.       Application Number                        Name                           ) Tj\n";

	f1<<"BT\n";
	f1<<"80  680  Td\n";
	f1<<"( ------------------------------------------------------------------------------------------------------------- ) Tj\n";
	i=675;
	sno=1;
	while(f3.read((char*)&x,sizeof(x)))
	{
		f1<<"BT\n";
		f1<<"80  "<<i<<"  Td\n";
		i-=15;
		f1<<"( "<<sno<<"                             " <<x.appnoret()<<"                               "<<x.nameret()<<")  Tj\n";
		sno+=1;
	}
	
	f1<<"ET\n";
	f1<<"endstream\n";
	f1<<"endobj\n";

	f2.open("pdftemplate_end.txt");
                if (f2.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }

	while (f2.getline(str,100))
	{
		f1<<str<<"\n";
	}
	f2.close();
	f1.close();
	try{
	system ("evince  Selection_list.pdf");
	cout<<"Hai";

	}
	catch (exception& e)
	{
		cout<<"Failed to open PDF";
	}
}
