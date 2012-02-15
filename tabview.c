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
  
  GtkWidget *toolbar = gtk_toolbar_new();
  
  /* Back button */
  GtkToolItem *back_button = gtk_tool_button_new_from_stock("gtk-go-back");
  gtk_widget_set_can_focus(GTK_WIDGET(back_button), FALSE);
  
  /* Forward button */
  GtkToolItem *forward_button = gtk_tool_button_new_from_stock("gtk-go-forward");
  gtk_widget_set_can_focus(GTK_WIDGET(forward_button), FALSE);
  
  /* Add back and forward buttons to toolbar */
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), back_button, 0);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), forward_button, 1);
  
  /*
  ** URI entry
  */
  
  /* Create our entry */
  GtkWidget *uri_entry = gtk_entry_new();
  
  /* Create the completion object */
  //GtkEntryCompletion *uri_entry_completion = gtk_entry_completion_new();
  
  /* Assign the completion to the entry */
  //gtk_entry_set_completion (GTK_ENTRY(uri_entry), uri_entry_completion);
  //g_object_unref (entry_completion);
  
  /* end URI entry */
  
  /*
  ** Search entry
  */
  
  /* Create our entry */
  GtkWidget *search_entry = gtk_entry_new();
  
  /* end search entry */
  
  /* entry and search container */
  //GtkWidget *entries_container = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  GtkWidget *entries_paned = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
  gtk_paned_add1(GTK_PANED(entries_paned), uri_entry);
  gtk_paned_add2(GTK_PANED(entries_paned), search_entry);
  //gtk_box_pack_start();
  
  /* Add entry to toolbar */
  GtkToolItem *entry_tool_item = gtk_tool_item_new();
  //gtk_container_add(GTK_CONTAINER(entry_tool_item), entries_paned);
  //gtk_toolbar_insert(GTK_TOOLBAR(toolbar), entry_tool_item, 3);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), GTK_TOOL_ITEM(entries_paned), 3);
  /*gtk_box_pack_start(toolbar, GTK_WIDGET(entry),
                      FALSE, FALSE, 0);*/
  
  /* Add widgets to TabView */
  gtk_box_pack_start (GTK_BOX(tv), GTK_WIDGET(toolbar), FALSE, FALSE, 0);
}

static void tabviewclass_init(TabViewClass *tabview_class)
{
}
