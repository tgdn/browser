#include "tabview.h"

static void tabview_init(TabView *tabview);
static void tabviewclass_init(TabViewClass *tabview_class);

GType tabview_get_type()
{
  static GType t = 0;
  if (!t) {
    const GTypeInfo info =
    {
      sizeof(TabViewClass),
      NULL, /* base init */
      NULL, /* base finalize */
      (GClassInitFunc)tabviewclass_init,
      NULL, /* class finalize */
      NULL, /* class data */
      sizeof(TabView),
      0,    /* n pre allocs */
      (GInstanceInitFunc)tabview_init,
      0
    };
    
    t = g_type_register_static(GTK_TYPE_VBOX, "TabView",
                &info, 0);
  }
  return t;
}

GtkWidget* tabview_new()
{
  TabView *tabview = g_object_new(tabview_get_type(), NULL);
  
  return GTK_WIDGET(tabview);
}

static void tabview_init(TabView *tabview)
{
  GtkWidget *tv = GTK_WIDGET(tabview);
}

static void tabviewclass_init(TabViewClass *tabview_class)
{
}
