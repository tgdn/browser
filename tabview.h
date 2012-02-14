#ifndef __TABVIEW_H__
#define __TABVIEW_H__

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gtk/gtk.h>

typedef struct __TabView         TabView;
typedef struct __TabViewClass    TabViewClass;

struct __TabView {
  GtkVBox parent;
};

struct __TabViewClass {
  GtkVBoxClass parent;
};

GtkWidget* tabview_new();
GType tabview_get_type();

#endif /* __TABVIEW_H__ */
