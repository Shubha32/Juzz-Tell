/*This is the file used for the Sign in process using gtk....GTK has its own class and attributes....and widgets and signal connections can be easily given through it...*/

//Necessary header files....
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

using namespace std;


struct User
{
        char uname[20],mailid[25],password[10];
}U;

    GtkWidget *name;
    GtkWidget *passwd;

int isNull (char *x)
{
        if (strlen(x)==0)
                return 1;
        else
            	return 0;
}

/* This callback quits the program */
gint delete_event( GtkWidget *widget, GdkEvent  *event, gpointer   data )
{
    gtk_main_quit ();
    return(FALSE);
}


void SignIn( GtkWidget *widget, gpointer   data )
{
      	fstream f;

        char *mailid, *password;
        GtkWidget *dialog;
	
	//The 2 entries...
        mailid= (char*)gtk_entry_get_text((GtkEntry*)name);
        password=(char*)gtk_entry_get_text((GtkEntry*)passwd);
	
	//IF NOTHING IS ENTERED....
        if (isNull(mailid)||isNull(password))
        {
                dialog = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK, "Data Not Entered");
                gtk_window_set_title(GTK_WINDOW(dialog), "Information");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(dialog);
        }
	else
	{
		f.open("usermaster.dat", ios::in);
		if (f.fail())
		{
			system("clear");
			cerr<<"Error in Opening File";
			exit(0);
		}
                int flag=0;
                f.read((char*)&U,sizeof(U));
		
		//CHECKING IF ACCOUNT IS ALREADY PRESENT FOR LOGGING IN.....IF IT IS FINE AFTER COMPARISON..."LOGIN IS SUCCESSFUL" ELSE "LOGIN FAILS"
                while(!f.eof())
                {
                //	f.read((char*)&U,sizeof(U));
                     
                        if (strcmp(mailid,U.mailid)==0 && strcmp(password,U.password)==0)
                        {
                                dialog = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK, "Login Success");
                                gtk_window_set_title(GTK_WINDOW(dialog), "Information");
                                gtk_dialog_run(GTK_DIALOG(dialog));
                                gtk_widget_destroy(dialog);
                                flag=1;
                              
                                gtk_main_quit();
				//g_signal_connect (data, " ", G_CALLBACK (delete_event), (gpointer)data);
		
				if (strcmp(U.mailid,"admin@hana.com")==0)
				{
					char s[30]="./portal Admin ";
                                        strcat(s, U.mailid);
                                        strcat(s," ");
                                       	strcat(s,U.uname);
                                       	strcat(s," ");
                                        strcat(s,U.password);
                                       	system(s);
				}
					
				else if (strcmp(U.mailid,"hr@ags.com")==0)
				{
					char s[30]="./portal HR ";
					strcat(s, U.mailid);
                                        strcat(s," ");
                                        strcat(s,U.uname);
                                        strcat(s," ");
                                        strcat(s,U.password);
                                        system(s);
				}
				else
				{
					char s[30]="./portal Applicant  ";
					strcat(s, U.mailid);
					strcat(s," ");
					strcat(s,U.uname);
					strcat(s," ");
					strcat(s,U.password);
					system(s);
				}
				break;
                        }
                        f.read((char*)&U,sizeof(U));
                }
                f.close();
                if (flag==0)
                {
			dialog = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO,GTK_BUTTONS_OK, "Login Failed");
                        gtk_window_set_title(GTK_WINDOW(dialog), "Information");
                        gtk_dialog_run(GTK_DIALOG(dialog));
                        gtk_widget_destroy(dialog);
		}
	}    
}

void Cancel(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}
void ChangePassword(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
	system("./ForgotPassword");
}

void CreateAccount(GtkWidget *widget, gpointer data)
{
	g_print("Hai");
	
	gtk_main_quit();
	system("./CreateAccount");
}



int main(int argc, char *argv[])
{

    GtkWidget *window;
    GtkWidget *table;
    GtkWidget *table1;
    GtkWidget *label1;
    GtkWidget *label2;
    GtkWidget *label3;
	


    GtkWidget *button;
    GtkWidget *button1;
    GtkWidget *button2, *button3, *button4;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window),220,150);
    gtk_window_set_title(GTK_WINDOW(window), "JUZZ TELL");
    gtk_container_set_border_width(GTK_CONTAINER(window), 90);

    table = gtk_table_new(4, 2, TRUE);
    gtk_table_set_row_spacings(GTK_TABLE(table),4);
    gtk_table_set_col_spacings(GTK_TABLE(table),2);
    gtk_container_add(GTK_CONTAINER(window), table);

    label1 = gtk_label_new("User Name");
    label2 = gtk_label_new("Password");
    button1 = gtk_button_new_with_label("Sign In");
    button2 = gtk_button_new_with_label("Cancel");
    button3 = gtk_button_new_with_label("Forgot Password?");
    button4 = gtk_button_new_with_label("New User? Create Account.");
    
    name = gtk_entry_new();
    passwd = gtk_entry_new();

    gtk_table_attach_defaults(GTK_TABLE(table), label1, 0, 1, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), label2, 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), name, 1, 2, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), passwd, 1, 2, 1, 2);
 
    gtk_table_attach_defaults(GTK_TABLE(table), button1, 0, 1, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), button2, 1, 2, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(table), button3, 0, 1, 3, 4);
    gtk_table_attach_defaults(GTK_TABLE(table), button4, 1, 2, 3, 4);


    gtk_container_add(GTK_CONTAINER(window), table);

    //SIGNAL CONNECTIONS WHEN THE BUTTONS ARE CLICKED....
    g_signal_connect (button1, "clicked", G_CALLBACK (SignIn), (gpointer)window);
    g_signal_connect (button2, "clicked", G_CALLBACK (Cancel), (gpointer)window);
    g_signal_connect (button3, "clicked", G_CALLBACK (ChangePassword), (gpointer)window);
    g_signal_connect (button4, "clicked", G_CALLBACK (CreateAccount), (gpointer)window);

   

    gtk_widget_show_all(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

}
