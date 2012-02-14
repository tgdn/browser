#ifndef __NOTEBOOK_H__
#define __NOTEBOOK_H__

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gtk/gtk.h>

#include "tabview.h"

typedef struct __Notebook         Notebook;
typedef struct __NotebookClass    NotebookClass;

struct __Notebook {
  GtkNotebook parent;
  
  gboolean tabs_showed;
};

struct __NotebookClass {
  GtkNotebookClass parent;
};

GtkWidget* notebook_new();
GType notebook_get_type();

/* Show or hide tabs in notebook */
void notebook_show_tabs(GtkWidget *notebook);
void notebook_hide_tabs(GtkWidget *notebook);

/* If tabs are shown hide them,
else show them */
void notebook_show_hide_tabs(GtkWidget *notebook);

/* adding tabs */
void notebook_new_tab(GtkWidget *notebook);

#endif /* __NOTEBOOK_H__ */
