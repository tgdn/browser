#include "notebook.h"

static void notebook_init(Notebook *notebook);
static void notebookclass_init(NotebookClass *notebook_class);

GType notebook_get_type()
{
  static GType t = 0;
  if (!t) {
    const GTypeInfo info =
    {
      sizeof(NotebookClass),
      NULL, /* base init */
      NULL, /* base finalize */
      (GClassInitFunc)notebookclass_init,
      NULL, /* class finalize */
      NULL, /* class data */
      sizeof(Notebook),
      0,    /* n pre allocs */
      (GInstanceInitFunc)notebook_init,
      0
    };
    
    t = g_type_register_static(GTK_TYPE_NOTEBOOK, "Notebook",
                &info, 0);
  }
  return t;
}

GtkWidget* notebook_new()
{
  return GTK_WIDGET(g_object_new(notebook_get_type(), NULL));
}

static void notebook_init(Notebook *notebook)
{
  notebook -> tabs_showed = TRUE;
  
  GtkWidget *nb = GTK_WIDGET(notebook);
  
  gtk_notebook_set_group_name(GTK_NOTEBOOK(nb), "main_tabs");
  gtk_notebook_set_scrollable(GTK_NOTEBOOK(nb), TRUE);
  
  
  gtk_widget_set_can_focus(nb, FALSE);
  //gtk_widget_set_size_request(nb, 200, 200);
  //gtk_window_resize(GTK_NOTEBOOK(nb), 600, 450);
}

static void notebookclass_init(NotebookClass *notebook_class)
{
}

void notebook_show_tabs(GtkWidget *notebook)
{
  Notebook *nb = (Notebook *)notebook;
  
  nb->tabs_showed = TRUE;
  gtk_notebook_set_show_tabs(GTK_NOTEBOOK(notebook), TRUE);
}

void notebook_hide_tabs(GtkWidget *notebook)
{
  Notebook *nb = (Notebook *)notebook;
  
  nb->tabs_showed = FALSE;
  gtk_notebook_set_show_tabs(GTK_NOTEBOOK(notebook), FALSE);
}

void notebook_show_hide_tabs(GtkWidget *notebook)
{
  Notebook *nb = (Notebook *)notebook;
  
  if (TRUE == nb->tabs_showed) {
    notebook_hide_tabs(notebook);
  } else {
    notebook_show_tabs(notebook);
  }
}

void notebook_new_tab(GtkWidget *notebook)
{
  Notebook *nb = (Notebook *)notebook;
  
  GtkWidget *tabview = tabview_new();
  gtk_notebook_set_tab_reorderable(GTK_NOTEBOOK(notebook), tabview, TRUE);
  gtk_notebook_set_tab_detachable(GTK_NOTEBOOK(notebook), tabview, TRUE);
  gtk_widget_set_can_focus(tabview, FALSE);
  
  GtkWidget *label = gtk_label_new("Test tab");
  gtk_widget_set_can_focus(label, FALSE);
  
  gtk_notebook_append_page(GTK_NOTEBOOK(notebook), tabview, label);
}
