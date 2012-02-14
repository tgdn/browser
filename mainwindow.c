#include "mainwindow.h"

static void mainwindow_init(MainWindow *window);
static void mainwindowclass_init(MainWindowClass *window_class);

GType mainwindow_get_type()
{
  static GType t = 0;
  if (!t) {
    const GTypeInfo info =
    {
      sizeof(MainWindowClass),
      NULL, /* base init */
      NULL, /* base finalize */
      (GClassInitFunc)mainwindowclass_init,
      NULL, /* class finalize */
      NULL, /* class data */
      sizeof(MainWindow),
      0,    /* n pre allocs */
      (GInstanceInitFunc)mainwindow_init,
      0
    };
    
    t = g_type_register_static(GTK_TYPE_WINDOW, "MainWindow",
                &info, 0);
  }
  return t;
}

GtkWidget* mainwindow_new()
{
  return GTK_WIDGET(g_object_new(mainwindow_get_type(),
                      "type", GTK_WINDOW_TOPLEVEL, NULL));
}

static void mainwindow_init(MainWindow *window)
{
  GtkWidget *w = GTK_WIDGET(window);
  gtk_widget_set_size_request(w, 200, 200);
  gtk_window_resize(GTK_WINDOW(w), 600, 450);
  
  g_signal_connect(w, "delete-event", G_CALLBACK(mainwindow_close), NULL);
  
  gtk_window_set_title(GTK_WINDOW(w), "A title");
  gtk_window_set_position(GTK_WINDOW(w), GTK_WIN_POS_CENTER);
  
  // Widgets
  window -> main_panel = mainpanel_new(w);
  window -> notebook = notebook_new();
  
  MainPanel *mp = (MainPanel *)window -> main_panel;
  mp -> notebook = window -> notebook;
  
  gtk_box_pack_start(GTK_BOX(window -> main_panel),
                               window -> notebook, TRUE, TRUE, 0);
  
  gtk_container_add(GTK_CONTAINER(w), window -> main_panel); 
}

static void mainwindowclass_init(MainWindowClass *window_class)
{
}

void mainwindow_show(GtkWidget *window)
{
  MainWindow *mainwin = (MainWindow *)window;
  
  mainwin->showed = TRUE;
  gtk_widget_show(window);
}

void mainwindow_hide(GtkWidget *window)
{
  MainWindow *mainwin = (MainWindow *)window;
  
  mainwin->showed = FALSE;
  gtk_widget_hide(window);
}

void mainwindow_show_hide(GtkWidget *window)
{
  MainWindow *mainwin = (MainWindow *)window;
  
  if (TRUE == mainwin->showed) {
    mainwindow_hide(window);
  } else {
    mainwindow_show(window);
  }
}

void mainwindow_close(GtkWidget *widget) {
  mainwindow_hide(widget);
  gtk_main_quit();
}
