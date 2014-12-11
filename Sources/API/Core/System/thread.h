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


#pragma once

#include "runnable.h"
#include "exception.h"
#include <memory>

namespace clan
{
/// \addtogroup clanCore_System clanCore System
/// \{

class Thread_Impl;

/// \brief Thread class.
class Thread
{
/// \name Construction
/// \{

public:
	/// \brief Constructs a thread object.
	Thread();

	~Thread();

/// \}
/// \name Attributes
/// \{

public:

/// \}
/// \name Operations
/// \{

public:
	/// \brief Starts a thread.
	void start(Runnable *runnable);

	template<class C>
	void start(C *instance, void (C::*member)())
	{
		Runnable *r = new RunnableMember_v0<C>(instance, member);
		try
		{
			start(r);
		}
		catch (const Exception&)
		{
			delete r;
			throw;
		}
	}

	template<class C, class P1>
	void start(C *instance, void (C::*member)(P1 p1), P1 p1)
	{
		Runnable *r = new RunnableMember_v1<C, P1>(instance, member, p1);
		try
		{
			start(r);
		}
		catch (const Exception&)
		{
			delete r;
			throw;
		}
	}

	template<class C, class P1, class P2>
	void start(C *instance, void (C::*member)(P1 p1, P2 p2), P1 p1, P2 p2)
	{
		Runnable *r = new RunnableMember_v2<C, P1, P2>(instance, member, p1, p2);
		try
		{
			start(r);
		}
		catch (const Exception&)
		{
			delete r;
			throw;
		}
	}

	template<class C, class P1, class P2, class P3>
	void start(C *instance, void (C::*member)(P1 p1, P2 p2, P3 p3), P1 p1, P2 p2, P3 p3)
	{
		Runnable *r = new RunnableMember_v3<C, P1, P2, P3>(instance, member, p1, p2, p3);
		try
		{
			start(r);
		}
		catch (const Exception&)
		{
			delete r;
			throw;
		}
	}

	template<class C, class P1, class P2, class P3, class P4>
	void start(C *instance, void (C::*member)(P1 p1, P2 p2, P3 p3, P4 p4), P1 p1, P2 p2, P3 p3, P4 p4)
	{
		Runnable *r = new RunnableMember_v4<C, P1, P2, P3, P4>(instance, member, p1, p2, p3, p4);
		try
		{
			start(r);
		}
		catch (const Exception&)
		{
			delete r;
			throw;
		}
	}

	template<class C, class P1, class P2, class P3, class P4, class P5>
	void start(C *instance, void (C::*member)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5), P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
	{
		Runnable *r = new RunnableMember_v5<C, P1, P2, P3, P4, P5>(instance, member, p1, p2, p3, p4, p5);
		try
		{
			start(r);
		}
		catch (const Exception&)
		{
			delete r;
			throw;
		}
	}

	/// \brief Blocks until thread has completed its execution.
	void join();

	/// \brief Terminates the thread.
	///
	/// Warning: This is a dangerous function that should only be used in the most extreme cases.
	/// If the target thread owns a critical section, the critical section will not be released.
	/// If the target thread is allocating memory from the heap, the heap lock will not be released.
	/// Windows XP/2000:  The target thread's initial stack is not freed, causing a resource leak.
	void kill();

	/// \brief Sets the name (displayed in debuggers) of the calling thread.
	/** <p>Currently this only works with the Visual Studio compiler and debugger.</p>*/
	static void set_thread_name(const char *name);

/// \}
/// \name Implementation
/// \{

private:
	std::shared_ptr<Thread_Impl> impl;
/// \}
};

}

/// \}
