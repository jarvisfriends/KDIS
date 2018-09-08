/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include "./SecondaryOperationalData.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SecondaryOperationalData::SecondaryOperationalData() :
    m_ui8Param1( 0 ),
    m_ui8Param2( 0 ),
    m_ui16NumFundParamSets( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

SecondaryOperationalData::SecondaryOperationalData(KDataStream &stream) noexcept(false)
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SecondaryOperationalData::SecondaryOperationalData( KUINT8 Param1, KUINT8 Param2, KUINT16 NumFundParamSets ) :
    m_ui8Param1( Param1 ),
    m_ui8Param2( Param2 ),
    m_ui16NumFundParamSets( NumFundParamSets )
{
}

//////////////////////////////////////////////////////////////////////////

SecondaryOperationalData::~SecondaryOperationalData()
{
}

//////////////////////////////////////////////////////////////////////////

void SecondaryOperationalData::SetParameter1( KUINT8 P )
{
    m_ui8Param1 = P;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 SecondaryOperationalData::GetParameter1() const
{
    return m_ui8Param1;
}

//////////////////////////////////////////////////////////////////////////

void SecondaryOperationalData::SetParameter2( KUINT8 P )
{
    m_ui8Param2 = P;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 SecondaryOperationalData::GetParameter2() const
{
    return m_ui8Param2;
}

//////////////////////////////////////////////////////////////////////////

void SecondaryOperationalData::SetNumberOfFundamentalParamSets( KUINT8 NFPDS )
{
    m_ui16NumFundParamSets = NFPDS;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SecondaryOperationalData::GetNumberOfFundamentalParamSets() const
{
    return m_ui16NumFundParamSets;
}

//////////////////////////////////////////////////////////////////////////

KString SecondaryOperationalData::GetAsString() const
{
    KStringStream ss;

    ss << "SecondaryOperationalData:"
       << "\n\tParameter 1:                   " << ( KUINT16 )m_ui8Param1
       << "\n\tParameter 2:                   " << ( KUINT16 )m_ui8Param2
       << "\n\tNumber Fundamental Param Sets: " << m_ui16NumFundParamSets
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void SecondaryOperationalData::Decode(KDataStream &stream) noexcept(false)
{
    if( stream.GetBufferSize() < SECONDARY_OPERATIONAL_DATA_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8Param1
           >> m_ui8Param2
           >> m_ui16NumFundParamSets;
}

//////////////////////////////////////////////////////////////////////////

KDataStream SecondaryOperationalData::Encode() const
{
    KDataStream stream;

    SecondaryOperationalData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SecondaryOperationalData::Encode( KDataStream & stream ) const
{
    stream << m_ui8Param1
           << m_ui8Param2
           << m_ui16NumFundParamSets;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SecondaryOperationalData::operator == ( const SecondaryOperationalData & Value ) const
{
    if( m_ui8Param1             != Value.m_ui8Param1 )            return false;
    if( m_ui8Param2             != Value.m_ui8Param2 )            return false;
    if( m_ui16NumFundParamSets  != Value.m_ui16NumFundParamSets ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SecondaryOperationalData::operator != ( const SecondaryOperationalData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
