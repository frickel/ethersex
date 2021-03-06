/* 
 * Copyright (c) 2009 by Stefan Riepenhausen <rhn@gmx.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * For more information on the GPL, please go to:
 * http://www.gnu.org/copyleft/gpl.html
 */

#ifndef ECMD_SCRIPTING_H
#define ECMD_SCRIPTING_H

#ifdef ECMD_SCRIPT_SUPPORT

#define STR_EQUALS "eq"
#define STR_NOTEQUALS "ne"
#define OK "OK"
#define NOT "!"
#define EQUALS "=="
#define NOTEQUALS "!="
#define GREATER ">"
#define LOWER "<"
#define GREATEREQUALS ">="
#define LOWEREQUALS "<="

#ifdef DEBUG_ECMD_SCRIPT
# include "core/debug.h"
# define SCRIPTDEBUG(a...)  debug_printf("ECMD script: " a)
#else
# define SCRIPTDEBUG(a...)
#endif

typedef struct {
  struct vfs_file_handle_t *handle;
  uint16_t linenumber;
  vfs_size_t filepointer;
} script_t;

script_t current_script;

typedef struct {
  char value[ECMD_SCRIPT_VARIABLE_LENGTH];
} variables_t;

variables_t vars[ECMD_SCRIPT_MAX_VARIABLES];

#endif  /* ECMD_SCRIPT_SUPPORT */

#endif /* ECMD_SCRIPTING_H */
