/*
    ------------------------------------------------------------------------------------
    LICENSE:
    ------------------------------------------------------------------------------------
    This file is part of The Open Ragnarok Project
    Copyright 2007 - 2011 The Open Ragnarok Team
    For the latest information visit http://www.open-ragnarok.org
    ------------------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any later
    version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
    this program; if not, write to the Free Software Foundation, Inc., 59 Temple
    Place - Suite 330, Boston, MA 02111-1307, USA, or go to
    http://www.gnu.org/copyleft/lesser.txt.
    ------------------------------------------------------------------------------------
*/
#ifndef __ROINT_MEMORY_H
#define __ROINT_MEMORY_H

#ifdef ROINT_INTERNAL
#	include "config.h"
#elif !defined(WITHOUT_ROINT_CONFIG)
#	include "roint/config.h"
#endif

#ifndef ROINT_DLLAPI
#	define ROINT_DLLAPI
#endif
#include <stddef.h> // size_t

#ifdef __cplusplus
extern "C" {
#endif 

typedef void* (*roint_alloc_func)(size_t);
typedef void (*roint_free_func)(void*);

// Set a custom malloc function to use troughout ROInt engine.
// Pass NULL to return to the default function.
ROINT_DLLAPI void set_roint_malloc_func(roint_alloc_func);
ROINT_DLLAPI void set_roint_free_func(roint_free_func);
    
ROINT_DLLAPI roint_alloc_func get_roint_malloc_func();
ROINT_DLLAPI roint_free_func get_roint_free_func();

#ifdef __cplusplus
}
#endif 

#endif /* __ROINT_MEMORY_H */
