#include <gtk/gtk.h>
#include "PJ_RPI.h"
#include <stdio.h>


int getal;

void LedToggel (GtkWidget *wid, gpointer ptr)
{
      GPIO_SET = 1 << 17;
         sleep(2);
      GPIO_CLR = 1 << 17;
         sleep(2);
}

void LedToggel2 (GtkWidget *wid, gpointer ptr)
{
      GPIO_SET = 1 << 27;
         sleep(2);
      GPIO_CLR = 1 << 27;
         sleep(2);
}

// int main (int argc, char *argv[])
// {
//  gtk_init (&argc, &argv);
//  GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
//  gtk_widget_show (win);
//  gtk_main ();
//  return 0;
// }



int main (int argc, char *argv[])
{
   
   //PJ libary check
   if(map_peripheral(&gpio) == -1) 
	{
       	 	printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
        	return -1;
    	}

    //gpio
    INP_GPIO(17);
    OUT_GPIO(17);
    INP_GPIO(27);
    OUT_GPIO(27);

    gtk_init (&argc, &argv);
    GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    //elements
    //btn
    GtkWidget *btn = gtk_button_new_with_label("ledtoggel");
    GtkWidget *btn2 = gtk_button_new_with_label("ledtoggel2");
    //lbl
    GtkWidget *lbl = gtk_button_new_with_label("led1");
    GtkWidget *lbl2 = gtk_button_new_with_label("led2");
    //functie en label aan button connecteren
    g_signal_connect (btn,"clicked", G_CALLBACK (LedToggel),
    lbl);
    g_signal_connect (btn2,"clicked", G_CALLBACK (LedToggel2),
    lbl2);
    //box (om elements samen te steken)
    GtkWidget *box = gtk_vbox_new(FALSE,5);
    gtk_box_pack_start (GTK_BOX (box), btn, TRUE,TRUE,0); //button 1 in box
    gtk_box_pack_start (GTK_BOX (box), lbl, TRUE,TRUE,0); //label 1 in box
    gtk_box_pack_start (GTK_BOX (box), btn2, TRUE,TRUE,0); //button 2 in box
    gtk_box_pack_start (GTK_BOX (box), lbl2, TRUE,TRUE,0); //label 2 in box
    //box mee geven aan window
    gtk_container_add (GTK_CONTAINER (win), box);
    gtk_widget_show_all (win);
    gtk_main();
}