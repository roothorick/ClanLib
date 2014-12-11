/*
**  ClanLib SDK
**  Copyright (c) 1997-2015 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
**    Mark Page
*/

#pragma once

#include "API/Display/TargetProviders/transfer_buffer_provider.h"
#include "API/Core/System/disposable_object.h"

namespace clan
{

class GL1TransferBufferProvider : public TransferBufferProvider
{
/// \name Construction
/// \{
public:
	GL1TransferBufferProvider();
	~GL1TransferBufferProvider();
	void create(int size, BufferUsage usage);
	void create(void *data, int size, BufferUsage usage);
/// \}

/// \name Attributes
/// \{
public:
	void *get_data() { return data; }
/// \}

/// \name Operations
/// \{
public:
	void lock(GraphicContext &gc, BufferAccess access) {}
	void unlock() {}
	void upload_data(GraphicContext &gc, int offset, const void *data, int size);
/// \}

/// \name Implementation
/// \{
private:
	char *data;
	int size;

/// \}
};

}
