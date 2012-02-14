#include "mainpanel.h"

static void mainpanel_init(MainPanel *mainpanel);
static void mainpanelclass_init(MainPanelClass *mainpanel_class);

GType mainpanel_get_type()
{
  static GType t = 0;
  if (!t) {
    const GTypeInfo info =
    {
      sizeof(MainPanelClass),
      NULL, /* base init */
      NULL, /* base finalize */
      (GClassInitFunc)mainpanelclass_init,
      NULL, /* class finalize */
      NULL, /* class data */
      sizeof(MainPanel),
      0,    /* n pre allocs */
      (GInstanceInitFunc)mainpanel_init,
      0
    };
    
    t = g_type_register_static(GTK_TYPE_VBOX, "MainPanel",
                &info, 0);
  }
  return t;
}

GtkWidget* mainpanel_new(GtkWidget *container)
{
  MainPanel *panel = g_object_new(mainpanel_get_type(), NULL);
  panel -> container = container;
  
  return GTK_WIDGET(panel);
}

static void mainpanel_init(MainPanel *mainpanel)
{
  GtkWidget *mp = GTK_WIDGET(mainpanel);
}

static void mainpanelclass_init(MainPanelClass *mainpanel_class)
{
}
