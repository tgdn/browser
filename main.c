#include <glib.h>
#include <gtk/gtk.h>

#include "application.h"

int main (int argv, char *argc[])
{
  g_print("Launching browser");
  gtk_init(&argv, &argc);
  
  init_application(argv, argc);
  return 0;
}
