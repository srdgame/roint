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
#ifndef __ROINT_RGZ_H
#define __ROINT_RGZ_H

#ifndef WITHOUT_ROINT_CONFIG
#	include "roint/config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif 


/// Rgz entry.
/// Everything after the end entry is ignored.
struct RORgzEntry {
	unsigned char type; //< entry type : 'f' for file, 'd' for directory, 'e' for end entry
	char path[256]; //< path (NUL-terminated, "end" in end entry, uses '\\' as dir separator)

	// file entries:
	unsigned int datalength;
	unsigned char *data;
};

/// Rgz archive.
/// Archive format similar to tar.gz.
struct RORgz {
	unsigned int entrycount;
	struct RORgzEntry *entries;
};


/// Loads the rgz from a data buffer. (NULL on error)
ROINT_DLLAPI struct RORgz *rgz_loadFromData(const unsigned char *data, unsigned int length);
/// Loads the rgz from a file. (NULL on error)
ROINT_DLLAPI struct RORgz *rgz_loadFromFile(const char *fn);
// Frees everything inside the RORgz structure allocated by us (including the rgz itself!)
ROINT_DLLAPI void rgz_unload(struct RORgz *rgz);


#ifdef __cplusplus
}
#endif 

#endif /* __ROINT_RGZ_H */
