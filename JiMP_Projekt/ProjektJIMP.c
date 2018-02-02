/*
 ============================================================================
 Name        : wodomierz_2.c
 Author      : Przemys³aw Bielecki
 Version     :
 Copyright   : Your copyright notice
 Description : wodomierz in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>
#include <fcntl.h>
#include <unistd.h>


#define NUM_COMMANDS 2

struct wyniki
{
	int number_of_cycles;
	int number_of_samples;
};

static void activate (GtkApplication *app, gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *vbox;
	GtkWidget *hbox1;
	GtkWidget *hbox2;
	GtkWidget *label1;
	GtkWidget *label2;
	GtkWidget *label3;
	GtkWidget *label4;

	struct wyniki *otrzymane_wyniki = user_data;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Projekt JiMP");
    gtk_window_set_default_size (GTK_WINDOW (window), 250, 150);
    gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), 0);

    label1 = gtk_label_new ("Liczba probek w sygnale wynosi: ");
    label2 = gtk_label_new ("Liczba cykli wynosi: ");

    label3 = gtk_label_new ("0");
    label4 = gtk_label_new ("0");

    char *display1, *display2;

    display1 = g_strdup_printf("%d", otrzymane_wyniki->number_of_samples);
    gtk_label_set_text (GTK_LABEL(label3), display1);

    display2 = g_strdup_printf("%d", otrzymane_wyniki->number_of_cycles);
    gtk_label_set_text (GTK_LABEL(label4), display2);

    free(display1);
    free(display2);

    button = gtk_button_new_with_label ("OK");

    hbox1=gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 1);
    gtk_box_pack_start (GTK_BOX(hbox1), label1, 0, 0, 10);
    gtk_box_pack_start (GTK_BOX(hbox1), label3, 0, 0, 0);

    hbox2=gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 1);
    gtk_box_pack_start (GTK_BOX(hbox2), label2, 0, 0, 10);
    gtk_box_pack_start (GTK_BOX(hbox2), label4, 0, 0, 0);

    vbox=gtk_box_new (GTK_ORIENTATION_VERTICAL, 1);
    gtk_box_pack_start (GTK_BOX(vbox), hbox1, 0, 0, 10);
    gtk_box_pack_start (GTK_BOX(vbox), hbox2, 0, 0, 10);
    gtk_box_pack_start (GTK_BOX(vbox), button, 0, 0, 10);

    gtk_container_add (GTK_CONTAINER (window), vbox);

    g_signal_connect_swapped(button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

    gtk_widget_show_all (window);
}

void kontrola_pliku(FILE* f)
{
    if(NULL==f)
	{
		printf("Nie udalo sie otworzyc pliku\n");
		exit(1);
	}
}


void read_ints (const char* file_name, int data[]) 
{
	FILE* file = fopen (file_name, "r");
	kontrola_pliku(file);

	int i = 0;

	fscanf (file, "%d", &data[i]);
	while (!feof (file))
    {
		i++;
    	fscanf (file, "%d", &data[i]);
    }

	fclose (file);
}

int ilosc_linii(FILE* myfile)
{
	int ch, number_of_lines=0;

	do
	{
	    ch = fgetc(myfile);
	    if(ch == '\n')
	        number_of_lines++;
	} while (ch != EOF);

	return number_of_lines;
}

int main(int argc, char* argv[]) {

	if(argc<4)
	{
		printf("Nie podano argumentow\n");
		return 1;
	}

	FILE* myfile = fopen(argv[1], "r");
	kontrola_pliku(myfile);

	int number_of_lines = 0;
	int counter=0;
	int i=0;

	number_of_lines=ilosc_linii(myfile);

	int *dataA;
	dataA=(int*)malloc(number_of_lines* sizeof(*dataA)); 
	fclose(myfile);
	read_ints(argv[1], dataA);

	myfile = fopen(argv[2], "r");
	kontrola_pliku(myfile);


	int *dataB;
	dataB=(int*)malloc(number_of_lines* sizeof(*dataB));
	fclose(myfile);
	read_ints(argv[2], dataB);

	myfile = fopen(argv[3], "r");
	kontrola_pliku(myfile);


	int *dataC;
	dataC=(int*)malloc(number_of_lines* sizeof(*dataC)); 
	fclose(myfile);
	read_ints(argv[3], dataC);

	int *dataD;
	dataD=(int*)malloc(number_of_lines* sizeof(*dataD));

	int *Odl;
	Odl=(int*)malloc(number_of_lines/10* sizeof(*Odl));

	int odl_counter=0;
	int kierunek=1;
	int mxA, mxD;
	int mnA, mnD;
	int mxposD;
	int lookformaxA=1, lookformaxD=1;
	int delta=3;
	int maxD_acc;
	int max_counter=-1;
	int max_counterB=0;
	int dir_ch=0;
	 
	FILE* max_file = fopen("max_tab.txt", "w");
	kontrola_pliku(max_file);

	FILE* dir_file = fopen("dir_tab.txt", "w");
	kontrola_pliku(dir_file);


	for(i=0; i<number_of_lines; i++)
		{
			dataD[i]=dataA[i]+dataB[i]-dataC[i];
		}

	for (i=0; i<number_of_lines; i++)
	{
		if(counter>21)// urednianie
		{
			dataD[i-2]=dataD[i-3]+dataD[i-2]+dataD[i-1]+dataD[i];
			dataD[i-2]=dataD[i-2]>>2;
			dataA[i-2]=dataA[i-3]+dataA[i-2]+dataA[i-1]+dataA[i];
			dataA[i-2]=dataA[i-2]>>2;
		}

		if(dataD[i-2]>mxD)
		{
			mxD=dataD[i-2];
			mxposD=i-2;
		}
		if(dataD[i-2]<mnD)
		{
			mnD=dataD[i-2];
		}

		if(lookformaxD)
		{
			if(dataD[i-2]<mxD-delta)
			{
				maxD_acc=mxD;
				mnD=dataD[i-2];

			    if(odl_counter>0)
			    	fprintf(max_file, "%d  %d\n", mxposD, maxD_acc);

				lookformaxD=0;

				Odl[odl_counter]=counter;
				odl_counter++; 
				counter=0;
				max_counter=max_counter+1;
				if(dataD[mxposD-1]>dataA[mxposD+1])
				{
					if(kierunek==2)
					{
						dir_ch=1;
						fprintf(dir_file, "%d  %d\n", i, kierunek+600);
					}
					else if (kierunek==1)
					{
						dir_ch=0;
						fprintf(dir_file, "%d  %d\n", i, kierunek+600);
					}

					kierunek=1;

					if(dir_ch==1)
					{
						fprintf(dir_file, "%d  %d\n", i, kierunek+600);
					}
				}
				else if(dataA[mxposD-1]<dataA[mxposD+1])
				{
					if(kierunek==1) {
						dir_ch=1;
						fprintf(dir_file, "%d  %d\n", i, kierunek+600);
					}
					else {
						dir_ch=0;
						fprintf(dir_file, "%d  %d\n", i, kierunek+600);
					}

					kierunek=2;

					if(dir_ch==1)
					{
						fprintf(dir_file, "%d  %d\n", i, kierunek+600);
					}
				}


			}
		}
		else
		{
			if(dataD[i-2]>mnD+delta)
			{
				mxD=dataD[i-2];
				mxposD=i-2;
			    lookformaxD=1;
			}
		}

		if(dataA[i-2]>mxA)
		{
			mxA=dataA[i-2];
		}
		if(dataA[i-2]<mnA)
		{
			mnA=dataA[i-2];
		}

		if(lookformaxA)
		{
			if(dataA[i-2]<mxA-delta)
			{
				mnA=dataA[i-2];
				lookformaxA=0;
				max_counterB=max_counterB+1;
			}
		}
		else
		{
			if(dataA[i-2]>mnA+delta)
		    {
				mxA=dataA[i-2];
				lookformaxA=1;
			}
		}

		counter=counter+1;
	}
	fclose(max_file);

	fprintf(dir_file, "%d  %d\n", number_of_lines, kierunek+600);

	struct wyniki *otrzymane_wyniki_wsk, otrzymane_wyniki;

	otrzymane_wyniki.number_of_cycles = max_counter;
	otrzymane_wyniki.number_of_samples = number_of_lines;
	otrzymane_wyniki_wsk=&otrzymane_wyniki;

	free(dataA);
	free(dataB);
	free(dataC);

	FILE *f = fopen("dataD.txt", "w");
	kontrola_pliku(f);

	for(i=0; i<number_of_lines; i++)
	{
		fprintf(f, "%d\n",dataD[i]);
	}

	fclose(f);

	int a=fork();

	if(a>0)
	{
		char * commandsForGnuplot[] = {"set title \"Wykres z zaznaczonymi maksimami\"", "plot 'dataD.txt' with lines title 'wykres sygnalu', 'max_tab.txt' with points title 'maksima', 'dir_tab.txt' with histeps title 'linia kierunku'"};
   		FILE * temp = fopen("dataD.txt", "w");																
    	kontrola_pliku(temp);

    	FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    	kontrola_pliku(gnuplotPipe);

    	for (i=0; i < number_of_lines; i++)
    	{
   		 	fprintf(temp, "%d \n", dataD[i]);
    	}

    	for (i=0; i < NUM_COMMANDS; i++)
    	{
    		fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
    	}

    	free(dataD);
    }
    if(a==0)
    {
    	GtkApplication *app;
 		int argc2=0;
		app = gtk_application_new (NULL, G_APPLICATION_FLAGS_NONE);
		g_signal_connect (app, "activate", G_CALLBACK (activate), otrzymane_wyniki_wsk);
		g_application_run (G_APPLICATION (app), argc2, NULL);
		g_object_unref (app);
	}

	fclose(dir_file);
	return 0;
}




