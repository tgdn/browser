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
  
  GtkBox *toolbar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  
  GtkImage *back_button_image = gtk_image_new_from_stock("gtk-go-back",
                                                 GTK_ICON_SIZE_SMALL_TOOLBAR);
  GtkButton *back_button = gtk_button_new();
  gtk_button_set_image(back_button, GTK_WIDGET(back_button_image));
  
  GtkImage *forward_button_image = gtk_image_new_from_stock("gtk-go-forward",
                                                 GTK_ICON_SIZE_SMALL_TOOLBAR);
  GtkButton *forward_button = gtk_button_new();
  gtk_button_set_image(forward_button, GTK_WIDGET(forward_button_image));
  
  /* Add back and forward buttons to toolbar */
  gtk_box_pack_start(toolbar, GTK_WIDGET(back_button),
                      FALSE, FALSE, 0);
  gtk_box_pack_start(toolbar, GTK_WIDGET(forward_button),
                      FALSE, FALSE, 0);
  
  /* Create our entry */
  GtkEntry *entry = gtk_entry_new();
  
  /* Create the completion object */
  GtkEntryCompletion *entry_completion = gtk_entry_completion_new();
  
  /* Assign the completion to the entry */
  gtk_entry_set_completion (entry, entry_completion);
  g_object_unref (entry_completion);
  
  /* Add widgets to TabView */
  gtk_box_pack_start (GTK_BOX(tv), GTK_WIDGET(toolbar), FALSE, FALSE, 0);
}

static void tabviewclass_init(TabViewClass *tabview_class)
{
}
