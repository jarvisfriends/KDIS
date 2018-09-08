
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

#include "./GED_BasicGroundCombatSoldier.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GED_BasicGroundCombatSoldier::GED_BasicGroundCombatSoldier() :
    m_ui16EntityID( 0 ),
    m_i8Spd( 0 ),
    m_i8HdAz( 0 ),
    m_i8HdElv( 0 ),
    m_i8HdScanRt( 0 ),
    m_i8HdElvRt( 0 )
{
    for( KINT8 i = 0; i < 3; ++i )
    {
        m_i16Offsets[i] = 0;
        m_i8Ori[i] = 0;
    }
}

//////////////////////////////////////////////////////////////////////////

GED_BasicGroundCombatSoldier::GED_BasicGroundCombatSoldier(KDataStream &stream) noexcept(false)
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GED_BasicGroundCombatSoldier::GED_BasicGroundCombatSoldier( KUINT16 ID, KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset, const EntityAppearance & EA,
        KINT8 Psi, KINT8 Theta, KINT8 Phi, KINT8 Speed, KINT8 HeadAzimuth, KINT8 HeadElevation,
        KINT8 HeadScanRate, KINT8 HeadElevationRate ) :
    m_ui16EntityID( ID ),
    m_EA( EA ),
    m_i8Spd( Speed ),
    m_i8HdAz( HeadAzimuth ),
    m_i8HdElv( HeadElevation ),
    m_i8HdScanRt( HeadScanRate ),
    m_i8HdElvRt( HeadElevationRate )
{
    m_i16Offsets[0] = XOffset;
    m_i16Offsets[1] = YOffset;
    m_i16Offsets[2] = ZOffset;
    m_i8Ori[0] = Psi;
    m_i8Ori[1] = Theta;
    m_i8Ori[2] = Phi;
}

//////////////////////////////////////////////////////////////////////////

GED_BasicGroundCombatSoldier::~GED_BasicGroundCombatSoldier()
{
}

//////////////////////////////////////////////////////////////////////////

GroupedEntityCategory GED_BasicGroundCombatSoldier::GetGroupedEntityCategory() const
{
    return BasicGroundCombatSoldierGEC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 GED_BasicGroundCombatSoldier::GetLength() const
{
    return GED_BASIC_GROUND_COMBAT_SOLDIER_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityID( KUINT16 ID )
{
    m_ui16EntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GED_BasicGroundCombatSoldier::GetEntityID() const
{
    return m_ui16EntityID;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityLocation( KINT16 XOffset, KINT16 YOffset, KINT16 ZOffset )
{
    m_i16Offsets[0] = XOffset;
    m_i16Offsets[1] = YOffset;
    m_i16Offsets[2] = ZOffset;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityLocation( KINT16 Offsets[3] )
{
    for( KUINT8 i = 0; i < 3; ++i )
    {
        m_i16Offsets[i] = Offsets[i];
    }
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityLocationXOffset( KINT16 X )
{
    m_i16Offsets[0] = X;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityLocationYOffset( KINT16 Y )
{
    m_i16Offsets[1] = Y;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityLocationZOffset( KINT16 Z )
{
    m_i16Offsets[2] = Z;
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_BasicGroundCombatSoldier::GetEntityLocationXOffset() const
{
    return m_i16Offsets[0];
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_BasicGroundCombatSoldier::GetEntityLocationYOffset() const
{
    return m_i16Offsets[1];
}

//////////////////////////////////////////////////////////////////////////

KINT16 GED_BasicGroundCombatSoldier::GetEntityLocationZOffset() const
{
    return m_i16Offsets[2];
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityAppearance( const EntityAppearance & EA )
{
    m_EA = EA;
}

//////////////////////////////////////////////////////////////////////////

const EntityAppearance & GED_BasicGroundCombatSoldier::GetEntityAppearance() const
{
    return m_EA;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance & GED_BasicGroundCombatSoldier::GetEntityAppearance()
{
    return m_EA;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityOrientation( KINT8 Psi, KINT8 Theta, KINT8 Phi )
{
    m_i8Ori[0] = Psi;
    m_i8Ori[1] = Theta;
    m_i8Ori[2] = Phi;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityOrientation( KINT8 Ori[3] )
{
    for( KINT8 i = 0; i < 3; ++i )
    {
        m_i8Ori[i] = Ori[i];
    }
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityOrientationPsi( KINT8 P )
{
    m_i8Ori[0] = P;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityOrientationTheta( KINT8 T )
{
    m_i8Ori[1] = T;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetEntityOrientationPhi( KINT8 P )
{
    m_i8Ori[2] = P;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatSoldier::GetEntityOrientationPsi() const
{
    return m_i8Ori[0];
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatSoldier::GetEntityOrientationTheta() const
{
    return m_i8Ori[1];
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatSoldier::GetEntityOrientationPhi() const
{
    return m_i8Ori[2];
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetSpeed( KINT8 S )
{
    m_i8Spd = S;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatSoldier::GetSpeed() const
{
    return m_i8Spd;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetHeadAzimuth( KINT8 H )
{
    m_i8HdAz = H;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatSoldier::GetHeadAzimuth() const
{
    return m_i8HdAz;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetHeadElevation( KINT8 H )
{
    m_i8HdElv = H;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatSoldier::GetHeadElevation() const
{
    return m_i8HdElv;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetHeadScanRate( KINT8 H )
{
    m_i8HdScanRt = H;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatSoldier::GetHeadScanRate() const
{
    return m_i8HdScanRt;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::SetHeadElevationRate( KINT8 H )
{
    m_i8HdElvRt = H;
}

//////////////////////////////////////////////////////////////////////////

KINT8 GED_BasicGroundCombatSoldier::GetHeadElevationRate() const
{
    return m_i8HdElvRt;
}

//////////////////////////////////////////////////////////////////////////

KString GED_BasicGroundCombatSoldier::GetAsString() const
{
    KStringStream ss;

    ss << "GED Basic Ground Combat Soldier\n"
       << "\tEntity ID:                   " << m_ui16EntityID  << "\n"
       << "\tLocation Offsets(x,y,z):     " << m_i16Offsets[0] << " " << m_i16Offsets[1] << " " << m_i16Offsets[2] << "\n"
       << IndentString( m_EA.GetAsString( EntityType( Lifeform, Land, 0, 0, 0, 0, 0 ) ), 1 )
       << "\tOrientation(Psi,Theta,Phi):  " << ( KINT16 )m_i8Ori[0]    << " " << ( KINT16 )m_i8Ori[1] << " " << ( KINT16 )m_i8Ori[2] << "\n"
       << "\tSpeed:                       " << ( KINT16 )m_i8Spd       << "m/s\n"
       << "\tHead Azimuth:                 " << ( KINT16 )m_i8HdAz    << "\n"
       << "\tHeadElevation:               " << ( KINT16 )m_i8HdElv     << "\n"
       << "\tHead Scan Rate:              " << ( KINT16 )m_i8HdScanRt << "\n"
       << "\tHead Elevation Rate:         " << ( KINT16 )m_i8HdElvRt   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::Decode(KDataStream &stream) noexcept(false)
{
    if( stream.GetBufferSize() < GED_BASIC_GROUND_COMBAT_SOLDIER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16EntityID
           >> m_i16Offsets[0]
           >> m_i16Offsets[1]
           >> m_i16Offsets[2]
           >> KDIS_STREAM m_EA
           >> m_i8Ori[0]
           >> m_i8Ori[1]
           >> m_i8Ori[2]
           >> m_i8Spd
           >> m_i8HdAz
           >> m_i8HdElv
           >> m_i8HdScanRt
           >> m_i8HdElvRt;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GED_BasicGroundCombatSoldier::Encode() const
{
    KDataStream stream;

    GED_BasicGroundCombatSoldier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GED_BasicGroundCombatSoldier::Encode( KDataStream & stream ) const
{
    stream << m_ui16EntityID
           << m_i16Offsets[0]
           << m_i16Offsets[1]
           << m_i16Offsets[2]
           << KDIS_STREAM m_EA
           << m_i8Ori[0]
           << m_i8Ori[1]
           << m_i8Ori[2]
           << m_i8Spd
           << m_i8HdAz
           << m_i8HdElv
           << m_i8HdScanRt
           << m_i8HdElvRt;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicGroundCombatSoldier::operator == ( const GED_BasicGroundCombatSoldier & Value ) const
{
    if( m_ui16EntityID      != Value.m_ui16EntityID )   return false;
    if( m_i16Offsets[0]     != Value.m_i16Offsets[0] )  return false;
    if( m_i16Offsets[1]     != Value.m_i16Offsets[1] )  return false;
    if( m_i16Offsets[2]     != Value.m_i16Offsets[2] )  return false;
    if( m_EA                != Value.m_EA )             return false;
    if( m_i8Ori[0]          != Value.m_i8Ori[0] )       return false;
    if( m_i8Ori[1]          != Value.m_i8Ori[1] )       return false;
    if( m_i8Ori[2]          != Value.m_i8Ori[2] )       return false;
    if( m_i8Spd             != Value.m_i8Spd )          return false;
    if( m_i8HdAz            != Value.m_i8HdAz )         return false;
    if( m_i8HdElv           != Value.m_i8HdElv  )       return false;
    if( m_i8HdScanRt        != Value.m_i8HdScanRt )     return false;
    if( m_i8HdElvRt         != Value.m_i8HdElvRt )      return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GED_BasicGroundCombatSoldier::operator != ( const GED_BasicGroundCombatSoldier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
