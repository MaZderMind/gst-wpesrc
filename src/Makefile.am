plugin_LTLIBRARIES = libgstwpe.la

# sources used to compile this plug-in
libgstwpe_la_SOURCES = \
	gstwpesrc.cpp \
	WPEThreadedView.cpp

# compiler and linker flags used to compile this plugin, set in configure.ac
libgstwpe_la_CXXFLAGS = \
	$(GST_PLUGINS_BASE_CFLAGS) \
	$(GST_BASE_CFLAGS) \
	$(GST_CFLAGS) \
	$(SOUP_CFLAGS) \
	$(WPE_CFLAGS)

libgstwpe_la_LIBADD = \
	$(GST_PLUGINS_BASE_LIBS) \
	$(GST_BASE_LIBS) \
	$(GST_LIBS) \
	$(SOUP_LIBS) \
	$(WPE_LIBS)

libgstwpe_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)

# headers we need but don't want installed
noinst_HEADERS = \
	gstwpesrc.h \
	WPEThreadedView.h
