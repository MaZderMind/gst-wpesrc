plugin_LTLIBRARIES = libgstwebkitembedded.la

libgstwebkitembedded_la_SOURCES = \
        foo.c \
        foo.h \
        webkitembedded-plugin.c


# compiler and linker flags used to compile this plugin, set in configure.ac
libgstwebkitembedded_la_CFLAGS = $(GST_CFLAGS)
libgstwebkitembedded_la_LIBADD = \
        $(GST_LIBS) \
        $(GST_PLUGINS_BASE_LIBS) \
        -lgstvideo-1.0 \
        -lgstaudio-1.0
libgstwebkitembedded_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)
libgstwebkitembedded_la_LIBTOOLFLAGS = --tag=disable-static
