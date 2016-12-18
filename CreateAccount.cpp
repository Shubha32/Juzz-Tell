/*This file is used for the creation of an account which again uses GTK...*/

//Necessary header files....
#include <gtk/gtk.h>
#include<iostream>
#include<fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;
struct User
{
	char uname[20],mailid[25],password[10];
}U;

  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
  GtkWidget *entry4;

void Cancel(GtkWidget *widget, gpointer data)
{
        gtk_main_quit();
}
int isNull (char *x)
{
	if (strlen(x)==0)
		return 1;
	else	
		return 0;
}

//Including all validations.....the account is created...taking into account that the account might already exiast or data was not entered etc....
void Create(GtkWidget *widget, gpointer data)
{
	fstream f;

	char *username,*mailid, *password, *repass;
	GtkWidget *dialog;

	username=(char*)gtk_entry_get_text((GtkEntry*)entry1);
	mailid=	(char*)gtk_entry_get_text((GtkEntry*)entry2);
	password=(char*)gtk_entry_get_text((GtkEntry*)entry3);
	repass=	(char*)gtk_entry_get_text((GtkEntry*)entry4);
	
	if (isNull(username)|| isNull(mailid)||isNull(password)||isNull(repass))
	{
	       	dialog = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK, "Data Not Entered");
        	gtk_window_set_title(GTK_WINDOW(dialog), "Information");
        	gtk_dialog_run(GTK_DIALOG(dialog));
        	gtk_widget_destroy(dialog);
	}	
	else if (strcmp(password,repass)!=0)
	{
		dialog = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK, "Password Incorrect");
 	       	gtk_window_set_title(GTK_WINDOW(dialog), "Information");
        	gtk_dialog_run(GTK_DIALOG(dialog));
        	gtk_widget_destroy(dialog);
	}
	else
	{
//		f.open("usermaster.dat",ios::out);
//		strcpy(U.uname,"Administrator");
//		strcpy(U.mailid,"admin@hana.com");
//		strcpy(U.password,"admin");
//		f.write((char*)&U,sizeof(U));
//f.close();
		f.open("usermaster.dat", ios::in);
                if (f.fail())
                {
                        system("clear");
                        cerr<<"Error in Opening File";
                        exit(0);
                }
		
		int flag=0;
               	f.read((char*)&U,sizeof(U));

		while(!f.eof())
		{
		//	f.read((char*)&U,sizeof(U));
			printf("hai");
			if (strcmp(mailid,U.mailid)==0)
			{
				dialog = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK, "Already Exists");
			        gtk_window_set_title(GTK_WINDOW(dialog), "Information");
			        gtk_dialog_run(GTK_DIALOG(dialog));
			        gtk_widget_destroy(dialog);		
				flag=1;
				printf("Hello");
				break;
			}
			f.read((char*)&U,sizeof(U));
		}
		f.close();
		if (flag==0)
		{
			f.open("usermaster.dat",ios::out|ios::app);
	                if (f.fail())
        	        {
                	        system("clear");
                        	cerr<<"Error in Opening File";
                        	exit(0);
                	}
			
			f.seekp(0,ios_base::end);
			strcpy(U.uname,username);
			strcpy(U.password,password);
			strcpy(U.mailid,mailid);
			f.write((char*)&U,sizeof(U));
			f.close();
			dialog = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK, "Account Created");
			gtk_window_set_title(GTK_WINDOW(dialog), "Information");
			gtk_dialog_run(GTK_DIALOG(dialog));
			gtk_widget_destroy(dialog);
			gtk_main_quit();	
		}
	}
}


int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *table;

  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label3;
  GtkWidget *label4;

  GtkWidget *button1, *button2;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "CREATE ACCOUNT");
  gtk_container_set_border_width(GTK_CONTAINER(window), 90);

  table = gtk_table_new(5, 2, FALSE);
  gtk_container_add(GTK_CONTAINER(window), table);

  label1 = gtk_label_new("Name");
  label2 = gtk_label_new(" Mail Id");
  label3 = gtk_label_new("    Password");
  label4 = gtk_label_new("\t       Retype Password");  


  gtk_table_attach_defaults(GTK_TABLE(table), label1, 0, 1, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(table), label2, 0, 1, 1, 2);
  gtk_table_attach_defaults(GTK_TABLE(table), label3, 0, 1, 2, 3);
  gtk_table_attach_defaults(GTK_TABLE(table), label4, 0, 1, 3, 4);

  entry1 = gtk_entry_new();
  entry2 = gtk_entry_new();
  entry3 = gtk_entry_new();
  entry4 = gtk_entry_new();

  gtk_table_attach_defaults(GTK_TABLE(table), entry1, 1, 2, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(table), entry2, 1, 2, 1, 2);
  gtk_table_attach_defaults(GTK_TABLE(table), entry3, 1, 2, 2, 3);
  gtk_table_attach_defaults(GTK_TABLE(table), entry4, 1, 2, 3, 4);
  
  button1 = gtk_button_new_with_label("Create");
  button2 = gtk_button_new_with_label("Cancel");
 
  gtk_table_attach_defaults(GTK_TABLE(table), button1, 0, 1, 4, 5);
  gtk_table_attach_defaults(GTK_TABLE(table),button2, 1, 2, 4, 5);
  
    //When button is clicked....
    g_signal_connect (button1, "clicked", G_CALLBACK (Create), (gpointer)window);
    g_signal_connect (button2, "clicked", G_CALLBACK (Cancel), (gpointer)window);
 
  gtk_widget_show_all(window);

  g_signal_connect(window, "destroy",G_CALLBACK(gtk_main_quit), NULL);

  gtk_main();

  return 0;
}
