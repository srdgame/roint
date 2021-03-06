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
#ifndef __ROINT_INTERNAL_H
#define __ROINT_INTERNAL_H

#include "roint.h"

#include "internal_config.h"
#include "reader.h"
#include "writer.h"

#include <stddef.h> // size_t

extern roint_log_func _xlog;

extern roint_alloc_func _xalloc;
extern roint_free_func _xfree;

extern struct ROPal *pal_load(struct _reader *reader);
extern int pal_save(const struct ROPal *, struct _writer *writer);

// util
extern int _add_over_limit(size_t val1, size_t val2, size_t limit);
extern int _mul_over_limit(size_t val1, size_t val2, size_t limit);

#endif /* __ROINT_INTERNAL_H */
