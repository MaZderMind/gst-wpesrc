/* GStreamer
 * Copyright (C) 2019 Philippe Normand <philn>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Suite 500,
 * Boston, MA 02110-1335, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "foo.h"

/* pad templates */
static GstStaticPadTemplate sinktemplate = GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS("video/x-raw,format=RGBx")
);
static GstStaticPadTemplate srctemplate = GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS("video/x-raw,format=RGBx")
);
// If your source- and sink-caps are not identical, you *must* implement transform_caps or the element
// will not link successfully

GST_DEBUG_CATEGORY_STATIC (gst_foo_debug);
#define GST_CAT_DEFAULT gst_foo_debug




/* parent class */
#define gst_foo_parent_class parent_class
G_DEFINE_TYPE (GstFoo, gst_foo, GST_TYPE_BASE_TRANSFORM);

/* GObject member methods */
static void gst_foo_set_property (GObject * object, guint prop_id, const GValue * value, GParamSpec * pspec);
static void gst_foo_get_property (GObject * object, guint prop_id, GValue * value, GParamSpec * pspec);
static void gst_foo_finalize (GObject * obj);

/* GstBaseTransform member methods */
static gboolean gst_foo_set_caps (GstBaseTransform * base, GstCaps * in, GstCaps * out);
static gboolean gst_foo_start (GstBaseTransform * base);
static GstFlowReturn gst_foo_transform_ip (GstBaseTransform * base, GstBuffer * in);
static gboolean gst_foo_sink_event (GstBaseTransform * base, GstEvent * event);

static void
gst_foo_class_init (GstFooClass * klass)
{
  GstElementClass *element_class = GST_ELEMENT_CLASS (klass);

  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
  gobject_class->set_property = gst_foo_set_property;
  gobject_class->get_property = gst_foo_get_property;
  gobject_class->finalize = gst_foo_finalize;



  GstBaseTransformClass *trans_class = GST_BASE_TRANSFORM_CLASS (klass);
  trans_class->set_caps = GST_DEBUG_FUNCPTR (gst_foo_set_caps);
  trans_class->start = GST_DEBUG_FUNCPTR (gst_foo_start);
  trans_class->transform_ip = GST_DEBUG_FUNCPTR (gst_foo_transform_ip);
  trans_class->sink_event = GST_DEBUG_FUNCPTR (gst_foo_sink_event);
  //trans_class->passthrough_on_same_caps = TRUE;

  GST_DEBUG_CATEGORY_INIT (gst_foo_debug, "foo", 0, "Foo");

  gst_element_class_add_static_pad_template (element_class, &sinktemplate);
  gst_element_class_add_static_pad_template (element_class, &srctemplate);

  gst_element_class_set_static_metadata (element_class, "Foo",
      "",
      "A phase-meter shows the amount of phase difference in a pair of correlated signals. It allows the sound technician to adjust for optimal stereo and to diagnose mistakes such as an inverted signal. Furthermore it provides an indication of mono-compatibility, and possible phase-cancellation that takes place when a stereo-signal is mixed down to mono.",
      "Philippe Normand <philn>");
}

static void
gst_foo_init (GstFoo * foo)
{
  GST_DEBUG_OBJECT (foo, "init");

}

void
gst_foo_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec)
{
  GstFoo *foo = GST_FOO (object);

  switch (property_id) {

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (foo, property_id, pspec);
      break;
  }
}

void
gst_foo_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec)
{
  GstFoo *foo = GST_FOO (object);

  switch (property_id) {

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (foo, property_id, pspec);
      break;
  }
}

void
gst_foo_finalize (GObject * object)
{
  GstFoo *foo = GST_FOO (object);
  GST_DEBUG_OBJECT (foo, "finalize");


  G_OBJECT_CLASS (gst_foo_parent_class)->finalize (object);
}

static gboolean
gst_foo_set_caps (GstBaseTransform * base, GstCaps * in, GstCaps * out)
{
  GstFoo *foo = GST_FOO (base);
  GST_DEBUG_OBJECT (foo, "set_caps in=%" GST_PTR_FORMAT " out=%" GST_PTR_FORMAT, in, out);

  return TRUE;
}

static gboolean
gst_foo_start (GstBaseTransform * base)
{
  GstFoo *foo = GST_FOO (base);
  GST_DEBUG_OBJECT (foo, "start");

  return TRUE;
}

static GstFlowReturn
gst_foo_transform_ip (GstBaseTransform * base, GstBuffer * in)
{
  GstFoo *foo = GST_FOO (base);
  GST_DEBUG_OBJECT (foo, "transform_ip");

  return GST_FLOW_OK;
}

static gboolean
gst_foo_sink_event (GstBaseTransform * base, GstEvent * event)
{
  GstFoo *foo = GST_FOO (base);
  GST_DEBUG_OBJECT (foo, "sink_event");

  return GST_BASE_TRANSFORM_CLASS (parent_class)->sink_event (base, event);
}
