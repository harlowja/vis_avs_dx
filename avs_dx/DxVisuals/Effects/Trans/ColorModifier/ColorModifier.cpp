#include "stdafx.h"
#include "ColorModifier.h"

IMPLEMENT_EFFECT( ColorModifier, C_DColorModClass )
using namespace Expressions;

namespace
{
	class Proto : public Prototype
	{
	public:
		Proto()
		{
			addBeatConstant( "beat" );
			addFragmentOutput( "red" );
			addFragmentOutput( "green" );
			addFragmentOutput( "blue" );
		}
	};
	static const Prototype& prototype()
	{
		static const Proto p;
		return p;
	}
}

ColorModifierStructs::StateData::StateData( AvsState& ass ) :
	Compiler( "ColorModifier", prototype() )
{ }

HRESULT ColorModifier::render( bool isBeat, RenderTargets& rt )
{
	omBlend( eBlend::None );
	const UINT psReadSlot = renderer.pixel().bindPrevFrame;
	BoundPsResource read;
	CHECK( rt.writeToNext( psReadSlot, read, false ) );

	if( !renderer.bindShaders( isBeat ) )
		return S_FALSE;
	drawFullscreenTriangle( false );
	return S_OK;
}