#!/bin/sh
GST_PLUGIN_PATH=`dirname $0`/../src/.libs/ GST_DEBUG="*:2,wpesrc:5" gst-launch-1.0 \
	wpesrc location="http://127.0.0.1:8080/example.html" ! gldownload ! videoconvert ! ximagesink
