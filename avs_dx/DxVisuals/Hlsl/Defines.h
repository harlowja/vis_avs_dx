#pragma once
#include "../Expressions/variableTypes.h"

namespace Hlsl
{
	// A set of HLSL macros with their values.
	class Defines
	{
		vector<std::pair<CStringA, CStringA>> m_map;

	public:
		Defines() = default;
		Defines( const Defines& ) = default;

		void set( const CStringA& name, const CStringA& value );
		void set( const CStringA& name, const char* value );
		void reset( const CStringA& name, const char* value );

		void clear() { m_map.clear(); }

		void set( const CStringA &key, uint32_t value );
		void set( const CStringA &key, int value );
		void set( const CStringA &key, float value );
		void set( const CStringA &key, bool value );

		// Add macro with value like "0x11, 0x22, 0x33"
		void set( const CStringA &key, const vector<int>& vec );

		template<size_t size>
		void set( const CStringA &key, const array<float3, size>& arr )
		{
			CStringA str;
			str.Preallocate( 128 );
			for( const float3& value : arr )
			{
				if( str.GetLength() > 0 )
					str += ", ";
				str.AppendFormat( "float3( %g, %g, %g )", value.x, value.y, value.z );
			}
			set( key, str );
		}

		template<size_t size>
		void set( const CStringA &key, const array<float, size>& arr )
		{
			CStringA str;
			str.Preallocate( 128 );
			for( float value : arr )
			{
				if( str.GetLength() > 0 )
					str += ", ";
				str.AppendFormat( "%g", value );
			}
			set( key, str );
		}
		
		// Add macro with value like "float2( 0, 1 )" 
		void set( const CStringA &key, const float2& value );
		// Add macro with value like "float3( 0, 1, 2 )" 
		void set( const CStringA &key, const float3& value );
		// Add macro with value like "float4( 0, 1, 2, 3 )" 
		void set( const CStringA &key, const float4& value );
		// Add macro with value like "uint2( 1, 2 )" 
		void set( const CStringA &key, const uint2& value );

		// Add macro with resource bind register like "t3" or "u2"
		void setBinding( const CStringA &key, char type, UINT slot );

		// For manually expanding macros, only used by effect state compute shaders.
		CStringA expand( CStringA hlsl ) const;

		// For HLSL-expanding macros, used by various per-effect shaders.
		vector<D3D_SHADER_MACRO> data() const;
	};
}