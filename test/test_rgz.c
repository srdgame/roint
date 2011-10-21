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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <roint.h>

int main(int argc, char **argv)
{
	const char *archive;
	struct RORgz *rgz;
	unsigned int i;
	int ret;

	if (argc != 2) {
		const char *exe = argv[0];
		printf("Usage:\n  %s archive.rgz\n", exe);
		return(EXIT_FAILURE);
	}

	archive = argv[1];
	rgz = rgz_loadFromFile(archive);
	if (rgz == NULL) {
		printf("error : failed to load file '%s'\n", archive);
		return(EXIT_FAILURE);
	}
	ret = EXIT_SUCCESS;
	for (i = 0; i < rgz->entrycount; i++) {
		struct RORgzEntry *entry = &rgz->entries[i];
		printf("[%u] '%c'  \"%s\"  %u  %p\n", i, entry->type, entry->path, entry->datalength, entry->data);
		if (entry->type != 'f' && entry->type != 'd' && entry->type != 'e' ) {
			printf("error : unknown entry type '%c' (0x%x)\n", entry->type, (unsigned char)entry->type);
			ret = EXIT_FAILURE;
		}
		if (memchr(entry->path, 0, sizeof(entry->path)) == NULL) {
			printf("error : path should be NUL-terminated\n");
			ret = EXIT_FAILURE;
		}
		if (strchr(entry->path, '/') != NULL) {
			printf("error : path should not use / as path separator\n");
			ret = EXIT_FAILURE;
		}
		if (entry->datalength > 0 && entry->type != 'f' ) {
			printf("error : should not have data\n");
			ret = EXIT_FAILURE;
		}
		if (entry->datalength > 0 && entry->data == NULL) {
			printf("error : should have non-NULL data\n");
			ret = EXIT_FAILURE;
		}
		if (entry->datalength == 0 && entry->data != NULL) {
			printf("error : should have NULL data\n");
			ret = EXIT_FAILURE;
		}
	}
	if (ret == EXIT_SUCCESS)
		printf("OK\n");
	return(ret);
}