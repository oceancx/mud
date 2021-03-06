//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module mud.proto;
#else
#include <obj/Indexer.h>
#include <proto/Entity.h>
#include <proto/Proto.h>
#endif

namespace mud
{
	EntityRegistry s_registry;

	Complex::Complex(Id id, Type& type)
		: m_id(index(type, id, Ref(this, type)))
		, m_type(type)
		, m_prototype(proto(type))
		, m_parts(m_prototype.m_parts.size())
	{}

	Complex::Complex(Id id, Type& type, const std::vector<Ref>& parts)
		: Complex(id, type)
	{
		this->setup(parts);
	}

	Complex::~Complex()
	{
		unindex(m_type, m_id);
	}

	void Complex::setup(const std::vector<Ref>& parts)
	{
		for (Ref ref : parts)
			this->add_part(ref);
	}
}
