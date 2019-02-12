#!/bin/sh
GST_PLUGIN_PATH=`dirname $0`/../src/.libs/ GST_DEBUG="*:2,wpesrc:5" gst-launch-1.0 \
	compositor name=c ! "video/x-raw,width=1920,height=1080,framerate=25/1" ! ximagesink \
	videotestsrc ! "video/x-raw,width=1920,height=1080,framerate=25/1" ! c. \
	wpesrc draw-background=false location="http://127.0.0.1:8080/example.html" ! "video/x-raw(memory:GLMemory),width=1920,height=1080,framerate=25/1" ! gldownload ! c. \
