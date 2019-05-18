//
// Created by lucas on 17/05/19.
//

#ifndef GESTURE_PARSER_G_BUS_HELPER_H
#define GESTURE_PARSER_G_BUS_HELPER_H

#include <glib.h>
#include <thread>
#include "gesture_gdbus_codegen.h"

class g_bus_helper {
private:
    std::thread t;
    GMainLoop *mainLoop;
    static void on_name_acquired(GDBusConnection *connection, const gchar *name, gpointer user_data);

public:
    static touchlessGesture *interface;
    g_bus_helper();
    ~g_bus_helper();
    void connect();
};


#endif //GESTURE_PARSER_G_BUS_HELPER_H
