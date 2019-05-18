//
// Created by lucas on 17/05/19.
//

#include <iostream>
#include "g_bus_helper.h"

touchlessGesture * g_bus_helper::interface;

g_bus_helper::g_bus_helper() : t() {
    interface = touchless_gesture_skeleton_new();
    mainLoop = g_main_loop_new(nullptr, FALSE);
}

void g_bus_helper::connect() {
    g_bus_own_name(G_BUS_TYPE_SESSION,
            "com.thelvm.touchless",
            G_BUS_NAME_OWNER_FLAGS_NONE,
            nullptr,
            on_name_acquired,
            nullptr,
            nullptr,
            nullptr);

    g_bus_helper::t = std::thread(g_main_loop_run, mainLoop);
}

void g_bus_helper::on_name_acquired(GDBusConnection *connection, const gchar *name, gpointer user_data) {
    std::cout << "Connected to DBus" << std::endl;

    GError *error = nullptr;
    g_dbus_interface_skeleton_export (G_DBUS_INTERFACE_SKELETON (interface), connection, "/com/thelvm/touchless/gesture", &error);
}

g_bus_helper::~g_bus_helper() {
    g_main_loop_quit(mainLoop);
    t.join();
}

