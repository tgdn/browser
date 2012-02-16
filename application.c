#include "application.h"

GtkApplication *app = NULL;
GtkWidget *main_window = NULL;

void init_application (int argc, char *argv[])
{
  const gchar *application_name = "Browser";
  g_set_application_name(application_name);

  const gchar *prgname = "Browser";
  g_set_prgname(prgname);
  
  const gchar *application_id = "net.launchpad.Browser";
  GApplicationFlags flags = G_APPLICATION_HANDLES_COMMAND_LINE;
  app = gtk_application_new (application_id, flags);
  
  start();
}

void start()
{
  if (gtk_application_get_windows(app) != NULL)
  {
    GList *windows_list = gtk_application_get_windows(app);
    windows_list[0];
    g_print("There already is a window: exiting application\n");
    
    g_free(windows_list);
  }
  
  /* Create main window */
  main_window = mainwindow_new();
  
  /* Add window to application */
  gtk_application_add_window(app, GTK_WINDOW(main_window));
  
  /* Not stable
   * this is for testing
  */
  _new_tab();
  
  gtk_widget_show_all(main_window);
  
  gtk_main(); 
}

void _new_tab() {
  MainWindow *mainwin = (MainWindow *)main_window;
  notebook_new_tab(mainwin -> notebook);
}
