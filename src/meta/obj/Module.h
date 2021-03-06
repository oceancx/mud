
#pragma once

#if !defined MUD_MODULES || defined MUD_OBJ_LIB
#include <refl/Module.h>
#endif

#ifndef MUD_MODULES
#include <meta/infra/Module.h>
#endif
        
#include <obj/Forward.h>
#include <obj/Types.h>
#include <obj/Api.h>

#include <meta/obj/Convert.h>

#ifndef MUD_OBJ_REFL_EXPORT
#define MUD_OBJ_REFL_EXPORT MUD_IMPORT
#endif

namespace mud
{
	export_ class MUD_OBJ_REFL_EXPORT mud_obj : public Module
	{
	private:
		mud_obj();

	public:
		static mud_obj& m() { static mud_obj instance; return instance; }
	};
}

#ifdef MUD_OBJ_MODULE
extern "C"
MUD_OBJ_REFL_EXPORT Module& getModule();
#endif
