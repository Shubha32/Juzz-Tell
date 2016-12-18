/*This is the files which is used when the user forgets his password and the password is printed in the dialog box...Again uses GTK.*/

//Necessary header files included...
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

//Checks with the respective portal.....using mail_id comares and tells the password of the user....
void CheckPass(GtkWidget *widget, gpointer data)
{
	fstream f;

	char *username,*mailid, *password, *repass;
	GtkWidget *dialog;

	mailid=	(char*)gtk_entry_get_text((GtkEntry*)entry1);
	
	if (isNull(mailid))
	{
	       	dialog = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK, "Data Not Entered");
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
				dialog = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK, U.password);
			        gtk_window_set_title(GTK_WINDOW(dialog), "Your Password is");
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
			dialog = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK, "Mail ID Not Found");
			gtk_window_set_title(GTK_WINDOW(dialog), "Information");
			gtk_dialog_run(GTK_DIALOG(dialog));
			gtk_widget_destroy(dialog);
				
		}
	}
}


int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *table;

  GtkWidget *label1;
 // GtkWidget *label2;
 // GtkWidget *label3;
 // GtkWidget *label4;

  GtkWidget *button1, *button2;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "Change Password");
  gtk_container_set_border_width(GTK_CONTAINER(window), 90);

  table = gtk_table_new(2, 2, FALSE);
  gtk_container_add(GTK_CONTAINER(window), table);

  label1 = gtk_label_new("Mail ID");
  gtk_table_attach_defaults(GTK_TABLE(table), label1, 0, 1, 0, 1);

  entry1 = gtk_entry_new();

  gtk_table_attach_defaults(GTK_TABLE(table), entry1, 0, 1, 1, 2);
  
  button1 = gtk_button_new_with_label("Submit");
    button2 = gtk_button_new_with_label("Cancel");
 
 gtk_table_attach_defaults(GTK_TABLE(table), button1, 0, 1, 4, 5);
  gtk_table_attach_defaults(GTK_TABLE(table),button2, 1, 2, 4, 5);
  
   //When the button is clicked....
    g_signal_connect (button1, "clicked", G_CALLBACK (CheckPass), (gpointer)window);
    g_signal_connect (button2, "clicked", G_CALLBACK (Cancel), (gpointer)window);
 
  gtk_widget_show_all(window);

  g_signal_connect(window, "destroy",G_CALLBACK(gtk_main_quit), NULL);

  gtk_main();

  return 0;
}
