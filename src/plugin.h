/*
 * Copyright (c) 2002-2009 BalaBit IT Ltd, Budapest, Hungary
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 *
 * Note that this permission is granted for only version 2 of the GPL.
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef PLUGIN_H_INCLUDED
#define PLUGIN_H_INCLUDED

#include "cfg-parser.h"
#include "cfg-grammar.h"

typedef struct _Plugin Plugin;

struct _Plugin
{
  gint type;
  const gchar *name;
  void (*setup_context)(Plugin *self, CfgLexer *lexer, gint plugin_type, const gchar *plugin_name);
  CfgParser *parser;
};

Plugin *plugin_find(gint plugin_type, const gchar *plugin_name);
gpointer plugin_new_instance(CfgLexer *lexer, Plugin *plugin, YYLTYPE *yylloc);


void plugin_register(Plugin *p, int number);
gboolean plugin_load_module(const gchar *module_name);

#endif