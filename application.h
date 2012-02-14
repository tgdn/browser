#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gtk/gtk.h>

#include "mainwindow.h"

void init_application (int argc, char *argv[]);

void start();

void _new_tab();

#endif /* __APPLICATION_H__ */
