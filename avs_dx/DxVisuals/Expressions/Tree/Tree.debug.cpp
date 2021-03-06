#include "stdafx.h"
#include "Tree.h"
#include "../utils.hpp"
using namespace Expressions;

void Tree::dbgPrint() const
{
	if( m_nodes.empty() )
		return;
	dbgPrintList( 0, 0 );
}

void Tree::dbgPrintList( int i, int level ) const
{
	do
	{
		dbgPrintNode( i, level );
	} while( nextSibling( i ) );
}

namespace
{
	const char* typeName( eVarType vt )
	{
		if( vt == eVarType::unknown )
			return "unknown";
		return hlslName( vt );
	}
}

void Tree::dbgPrintNode( int ind, int level ) const
{
	const Node& node = m_nodes[ ind ];
	const eNode nt = node.node;

#define INDENT level * 2, ""

	if( nt == eNode::Code )
	{
		logDebug( "%*scode: %s \"%.*s\"", INDENT,
			typeName( node.vt ), node.length, m_codez.data() + node.id );
		return;
	}

	if( nt == eNode::Var )
	{
		logDebug( "%*svar: %s %s", INDENT,
			typeName( symbols.vars.type( node.id ) ), cstr( symbols.vars.name( node.id ) ) );
		return;
	}

	if( nt == eNode::Func )
	{
		logDebug( "%*sfunc: %s %s[ %i ]", INDENT,
			typeName( node.vt ), cstr( symbols.functions.name( node.id ) ), node.length );
		if( node.length > 0 )
			dbgPrintList( ind + 1, level + 1 );
	}

	if( nt == eNode::Expr )
	{
		logDebug( "%*sexpr: %s[ %i ]", INDENT,
			typeName( node.vt ), node.length );
		if( node.length > 0 )
			dbgPrintList( ind + 1, level + 1 );
	}
}