//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#pragma once

#ifndef MUD_MODULES
#include <gfx/Renderer.h>
#include <gfx/Filter.h>
#endif
#include <gfx-pbr/Forward.h>

#ifndef MUD_CPP_20
#include <vector>
#include <map>
#endif

namespace mud
{
	enum ShaderOptionRadiance : unsigned int
	{
		RADIANCE_ENVMAP,
		RADIANCE_ARRAY,
	};

	export_ class refl_ MUD_GFX_PBR_EXPORT BlockRadiance : public DrawBlock
	{
	public:
		BlockRadiance(GfxSystem& gfx_system, BlockFilter& filter, BlockCopy& copy);

		void init_gfx_block() final;
		void render_gfx_block() final;

		void begin_gfx_block(Render& render) final;
		void submit_gfx_block(Render& render) final;

		void begin_gfx_pass(Render& render) final;
		void submit_gfx_element(Render& render, const Pass& render_pass, DrawElement& element) const final;
		void submit_gfx_cluster(Render& render, const Pass& render_pass, DrawCluster& cluster) const final;

		void submit_pass(Render& render, const Pass& render_pass, ShaderVersion& shader_version) const;

		void prefilter_radiance(Radiance& radiance);

		struct RadianceUniform
		{
			void createUniforms()
			{
				s_radiance_map = bgfx::createUniform("s_radiance_map", bgfx::UniformType::Int1);
			}

			bgfx::UniformHandle s_radiance_map;

		} u_radiance;

		struct PrefilterUniform
		{
			void createUniforms()
			{
				u_prefilter_envmap_params = bgfx::createUniform("u_prefilter_envmap_params", bgfx::UniformType::Vec4);
			}

			bgfx::UniformHandle u_prefilter_envmap_params;

		} u_prefilter;

		BlockFilter& m_filter;
		BlockCopy& m_copy;

		Program& m_prefilter_program;

		std::vector<Radiance*> m_prefilter_queue;
		std::map<uint16_t, uint16_t> m_prefiltered;
	};
}
