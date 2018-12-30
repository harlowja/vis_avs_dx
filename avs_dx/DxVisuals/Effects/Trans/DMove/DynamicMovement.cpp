#include "stdafx.h"
#include "DynamicMovement.h"
#include <../InteropLib/interop.h>

IMPLEMENT_EFFECT( DynamicMovement, C_DMoveClass )
using namespace Expressions;

namespace
{
	class Proto : public Prototype
	{
	public:
		Proto()
		{
			addBeatConstant( "b" );
			addConstantInput( "w", eVarType::u32 );	// screen width in pixels
			addConstantInput( "h", eVarType::u32 );	// screen height in pixels

			addState( "alpha", 0.5f );

			addFragmentOutput( "d" );
			addFragmentOutput( "r" );
			addFragmentOutput( "x" );
			addFragmentOutput( "y" );
		}
	};
	static const Prototype& prototype()
	{
		static const Proto p;
		return p;
	}
}

HRESULT DynamicMovementStructs::StateData::defines( Hlsl::Defines& def ) const
{
	def.set( "w", screenSize.cx );
	def.set( "h", screenSize.cy );
	return S_OK;
}

DynamicMovementStructs::StateData::StateData( AvsState& ass ) :
	CommonStateData( "DynamicMovement", prototype() )
{ }

DynamicMovement::DynamicMovement( AvsState *pState ) :
	tBase( pState )
{ }

HRESULT DynamicMovement::render( bool isBeat, RenderTargets& rt )
{
	if( !renderer.bindShaders( isBeat ) )
		return S_FALSE;
	const UINT psReadSlot = renderer.pixel().bindPrevFrame;
	return MovementFx::render( rt, avs->subpixel, avs->wrap, psReadSlot, avs->blend, avs->rectcoords );
}