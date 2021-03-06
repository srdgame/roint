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
#ifndef __ROINT_H
#define __ROINT_H
/// \file roint.h
///
/// Entry point for the roint library.\n
/// Includes all utility headers and file format headers.\n
/// ROINT = Ragnarok Online INTerface.
/// \sa UtilityHeaders
/// \sa FileFormatHeaders


/// \defgroup UtilityHeaders  Utility Headers
#include "roint/constant.h"
#include "roint/log.h"
#include "roint/memory.h"
#include "roint/text.h"


/// \defgroup FileFormatHeaders  File Format Headers
/// \warning The original client uses <code>int</code> for most count fields,
///          so never go over <code>INT_MAX</code> if you want to be compatible.
#include "roint/act.h" // sprite animations
#include "roint/gat.h" // ground info
#include "roint/gnd.h" // 3d ground model
#include "roint/grf.h" // archive
#include "roint/imf.h" // sprite interaction
#include "roint/pal.h" // palette
#include "roint/rgz.h" // archive
#include "roint/rsm.h" // 3d model
#include "roint/spr.h" // sprite images
#include "roint/str.h" // effect animation
#include "roint/rsw.h" // resource world

#endif /* __ROINT_H */
