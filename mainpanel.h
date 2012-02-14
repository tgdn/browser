#ifndef __MAINPANEL_H__
#define __MAINPANEL_H__

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gtk/gtk.h>

#include "notebook.h"

typedef struct __MainPanel         MainPanel;
typedef struct __MainPanelClass    MainPanelClass;

struct __MainPanel {
  GtkVBox parent;
  
  GtkWidget *notebook;
  GtkWidget *container;
};

struct __MainPanelClass {
  GtkVBoxClass parent;
};

GtkWidget* mainpanel_new(GtkWidget *container);
GType mainpanel_get_type();

#endif /* __MAINPANEL_H__ */
