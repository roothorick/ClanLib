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
**    Harry Storbacka
**    Mark Page
*/

#pragma once


#include "API/GL/opengl_wrap.h"
#include "API/GL/opengl.h"
#include "API/Display/TargetProviders/program_object_provider.h"
#include "API/Core/System/disposable_object.h"

namespace clan
{

class GL1GraphicContextProvider;

class GL1ProgramObjectProvider : public ProgramObjectProvider, DisposableObject
{
/// \name Construction
/// \{

public:
	GL1ProgramObjectProvider( GL1GraphicContextProvider *gc_provider );
	virtual ~GL1ProgramObjectProvider();

/// \}
/// \name Attributes
/// \{

public:
	/// \brief Returns the OpenGL program object handle.
	unsigned int get_handle() const;

	/// \brief Returns true if the link succeeded.
	bool get_link_status() const;

	/// \brief Returns true if validation succeeded.
	bool get_validate_status() const;

	/// \brief Returns the current info log for the program object.
	std::string get_info_log() const;

	/// \brief Returns the shaders used in this program.
	std::vector<ShaderObject> get_shaders() const;

	/// \brief Returns the location of a named active attribute.
	int get_attribute_location(const std::string &name) const;

	/// \brief Returns the location of a named uniform variable.
	int get_uniform_location(const std::string &name) const;

	int get_uniform_buffer_size(int block_index) const;
	int get_uniform_buffer_index(const std::string &block_name) const;
	int get_storage_buffer_index(const std::string &name) const;

/// \}
/// \name Operations
/// \{

public:
	/// \brief Add shader to program object.
	void attach(const ShaderObject &obj);

	/// \brief Remove shader from program object.
	void detach(const ShaderObject &obj);

	/// \brief Bind attribute to specific location.
	/** <p>This function must be called before linking.</p>*/
	void bind_attribute_location(int index, const std::string &name);

	/// \brief Bind shader out variable a specific color buffer location.
	/** <p>This function must be called before linking.</p>*/
	void bind_frag_data_location(int color_number, const std::string &name);

	/// \brief Link program.
	/** <p>If the linking fails, get_link_status() will return false and
	    get_info_log() will return the link log.</p>*/
	void link();

	/// \brief Validate program.
	/** <p>If the validation fails, get_validate_status() will return
	    false and get_info_log() will return the validation log.</p>*/
	void validate();

	/// \brief Set uniform variable(s).
	void set_uniform1i(int location, int);
	void set_uniform2i(int location, int, int);
	void set_uniform3i(int location, int, int, int);
	void set_uniform4i(int location, int, int, int, int);
	void set_uniformiv(int location, int size, int count, const int *data);
	void set_uniform1f(int location, float);
	void set_uniform2f(int location, float, float);
	void set_uniform3f(int location, float, float, float);
	void set_uniform4f(int location, float, float, float, float);
	void set_uniformfv(int location, int size, int count, const float *data);
	void set_uniform_matrix(int location, int size, int count, bool transpose, const float *data);

	void set_uniform_buffer_index(int block_index, int bind_index);
	void set_storage_buffer_index(int buffer_index, int bind_unit_index);

/// \}
/// \name Implementation
/// \{

private:
	void on_dispose();

	std::vector<ShaderObject> shaders;

	Mat4f modelview_matrix;
	Mat4f projection_matrix;

	GL1GraphicContextProvider *gc_provider;

	friend class GL1GraphicContextProvider;

/// \}
};

}
