#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gtk/gtk.h>

#include "mainpanel.h"

typedef struct __MainWindow         MainWindow;
typedef struct __MainWindowClass    MainWindowClass;

struct __MainWindow {
  GtkWindow parent;
  GtkWidget *main_panel;
  GtkWidget *notebook;
  
  gboolean showed;
};

struct __MainWindowClass {
  GtkWindowClass parent;
};

GtkWidget* mainwindow_new();
GType mainwindow_get_type();

/* Main window show or hide */
void mainwindow_show(GtkWidget *window);
void mainwindow_hide(GtkWidget *window);

/* If the window now is shown, hide it,
   else show it */
void mainwindow_show_hide(GtkWidget *window);

void mainwindow_close();

#endif /* __MAINWINDOW_H__ */
