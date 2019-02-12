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
#ifndef _GST_FOO_H_
#define _GST_FOO_H_

#include <gst/base/gstbasetransform.h>

G_BEGIN_DECLS
#define GST_TYPE_FOO           (gst_foo_get_type())
#define GST_FOO(obj)           (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_FOO, GstFoo))
#define GST_FOO_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),  GST_TYPE_FOO, GstFooClass))
#define GST_IS_FOO(obj)        (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_FOO))
#define GST_IS_FOO_CLASS(obj)  (G_TYPE_CHECK_CLASS_TYPE((klass),  GST_TYPE_FOO))
typedef struct _GstFoo GstFoo;
typedef struct _GstFooClass GstFooClass;


struct _GstFoo
{
  GstBaseTransform base_foo;

};

struct _GstFooClass
{
  GstBaseTransformClass base_foo_class;

};

GType gst_foo_get_type (void);

G_END_DECLS
#endif // _GST_FOO_H_
