//
// Created by lucas on 17/05/19.
//

#include <iostream>
#include <thread>

#include "gio/gio.h"
#include "gesture_gdbus_codegen.h"




static void on_gesture_signal(touchlessGesture *proxy,
                              const gchar *gesture,
                              gpointer user_data) {
    printf("Signal received: %s\n", gesture);
}

static void on_name_appeared(GDBusConnection *connection,
                             const gchar *name,
                             const gchar *owner_name,
                             gpointer user_data) {
    printf("Parser running\n");
}

static void on_name_vanished(GDBusConnection *connection,
                             const gchar *name,
                             gpointer user_data) {

    printf("Parser not running\n");
}

int main(int argc, char **argv) {

    g_bus_watch_name(G_BUS_TYPE_SESSION,
                     "com.thelvm.touchless",
                     G_BUS_NAME_WATCHER_FLAGS_NONE,
                     on_name_appeared,
                     on_name_vanished,
                     nullptr,
                     nullptr);

    GError *error = nullptr;
    touchlessGesture *m_proxy = touchless_gesture_proxy_new_for_bus_sync(G_BUS_TYPE_SESSION,
                                                       G_DBUS_PROXY_FLAGS_NONE,
                                                       "com.thelvm.touchless",
                                                       "/com/thelvm/touchless/gesture",
                                                       nullptr,
                                                       &error);
    g_signal_connect(m_proxy, "changed", G_CALLBACK(on_gesture_signal), nullptr);

    GMainLoop *mainLoop = g_main_loop_new(nullptr, false);
    std::thread t(g_main_loop_run, mainLoop);

    printf("Press enter to exit...\n");
    std::cin.get();

    g_main_loop_quit(mainLoop);
    t.join();

    return 0;
}