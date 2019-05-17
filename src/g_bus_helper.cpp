//
// Created by lucas on 17/05/19.
//

#include "g_bus_helper.h"


g_bus_helper::g_bus_helper() : t() {
    mainLoop = g_main_loop_new(nullptr, FALSE);
}

void g_bus_helper::connect() {
    g_bus_own_name(G_BUS_TYPE_SESSION, "com.thelvm.touchless", G_BUS_NAME_OWNER_FLAGS_NONE, nullptr,
                   on_name_acquired, nullptr, nullptr, nullptr);

    g_bus_helper::t = std::thread(g_main_loop_run, mainLoop);
}

void g_bus_helper::on_name_acquired(GDBusConnection *connection, const gchar *name, gpointer user_data) {
    touchlessGesture * interface;
    GError *error;

    interface = touchless_gesture_skeleton_new();
    //g_signal_lookup("changed", touchlessGesture)
    error = nullptr;
    g_dbus_interface_skeleton_export (G_DBUS_INTERFACE_SKELETON (interface), connection, "/com/theLVM/touchless/gesture", &error);
}

g_bus_helper::~g_bus_helper() {
    g_main_loop_quit(mainLoop);
    t.join();
}

