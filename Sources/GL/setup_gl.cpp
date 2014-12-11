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
*/

#include "GL/precomp.h"
#include "setup_gl_impl.h"
#include "API/GL/setup_gl.h"
#include "API/GL/opengl_target.h"

namespace clan
{

/////////////////////////////////////////////////////////////////////////////
// SetupGL Construction:

Mutex SetupGL_Impl::cl_opengl_mutex;
int SetupGL_Impl::cl_opengl_refcount = 0;
OpenGLTarget *SetupGL_Impl::cl_opengl_target = 0;

SetupGL::SetupGL()
{
	SetupGL_Impl::init();
}


SetupGL::~SetupGL()
{
	SetupGL_Impl::deinit();

}

void SetupGL_Impl::init()
{
	MutexSection mutex_lock(&SetupGL_Impl::cl_opengl_mutex);
	if (SetupGL_Impl::cl_opengl_refcount == 0)
		SetupGL_Impl::cl_opengl_target = new OpenGLTarget();
	SetupGL_Impl::cl_opengl_refcount++;
}

void SetupGL_Impl::deinit()
{
	MutexSection mutex_lock(&SetupGL_Impl::cl_opengl_mutex);
	SetupGL_Impl::cl_opengl_refcount--;
	if (SetupGL_Impl::cl_opengl_refcount == 0)
		delete SetupGL_Impl::cl_opengl_target;
}

}
