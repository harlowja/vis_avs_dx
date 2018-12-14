#pragma once
#include "../Effects/includeDefs.h"
#include "../Render/EffectStateShader.hpp"
#include "Prototype.h"

namespace Expressions
{
	class Compiler
	{
		const Prototype& proto;

	public:
		Compiler( const Prototype& effectPrototype );

		// Recompile stuff from the strings
		HRESULT update( RString effect_exp[ 4 ] );

		// Rebuild the state shader
		HRESULT buildState( EffectStateShader& ess );

	private:

		enum eExpressionBits : uint8_t
		{
			None = 0,
			Init = 1,
			Frame = 2,
			Beat = 4,
			Fragment = 8,
		};

		// Local copy of the effect's expression strings
		std::array<CStringA, 4> m_expressions;

		// Global functions / resource declarations used by the state shaders.
		CAtlMap<CStringA, bool> m_globalsCode;

		struct sVariable
		{
			// Name of the variable from the user's expressions
			CStringA name;
			// Offset inside effectStates, from the start of this effect's state block, in 32-bit elements. -1 indicates local variables which that don't need to hit the state buffer.
			int offset = -1;

			eVarType vt = eVarType::unknown;

			// Combination of bits that says where it's used.
			eExpressionBits usageMask = eExpressionBits::None;
		};

		CStringA m_hlslState;
		CStringA m_hlslFragment;

		std::vector<sVariable> m_vars;

		HRESULT parse( uint8_t what, CStringA& hlsl );

		HRESULT deductTypes();
	};
}