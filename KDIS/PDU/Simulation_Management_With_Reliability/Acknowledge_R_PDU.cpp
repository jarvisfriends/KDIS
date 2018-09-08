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

#include "./Acknowledge_R_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU()
{
    m_ui8PDUType = Acknowledge_R_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU(KDataStream &stream) noexcept(false)
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU(const Header &H, KDataStream &stream) noexcept(false) :
    Acknowledge_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                                      AcknowledgeFlag AF, AcknowledgeResponseFlag ARF, KUINT32 RequestID ) :
    Acknowledge_PDU( OriginatingEntityID, ReceivingEntityID, AF, ARF, RequestID )
{
    m_ui8PDUType = Acknowledge_R_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Simulation_Management_Header & SimMgrHeader, AcknowledgeFlag AF,
                                      AcknowledgeResponseFlag ARF, KUINT32 RequestID ) :
    Acknowledge_PDU( SimMgrHeader, AF, ARF, RequestID )
{
    m_ui8PDUType = Acknowledge_R_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Create_Entity_R_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Acknowledge_PDU( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID(), CreateEntityPDU, ARF, pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Remove_Entity_R_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Acknowledge_PDU( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID(), RemoveEntityPDU, ARF, pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Start_Resume_R_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Acknowledge_PDU( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID(), Start_ResumePDU, ARF, pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Stop_Freeze_R_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Acknowledge_PDU( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID(), Stop_FreezePDU, ARF, pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::Acknowledge_R_PDU( const Transfer_Control_Request_PDU & pdu, AcknowledgeResponseFlag ARF ) :
    Acknowledge_PDU( pdu.GetOriginatingEntityID(), pdu.GetReceivingEntityID(), TransferControlRequest, ARF, pdu.GetRequestID() )
{
    m_ui8PDUType = Acknowledge_PDU_Type;
    m_ui16PDULength = ACKNOWLEDGE_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Acknowledge_R_PDU::~Acknowledge_R_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

KString Acknowledge_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Acknowledge-R PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "\tAcknowledge Flag:   "   << GetEnumAsStringAcknowledgeFlag( m_ui16AcknowledgeFlag )
       << "\n\tResponse Flag:      " << GetEnumAsStringAcknowledgeResponseFlag( m_ui16ResponseFlag )
       << "\n\tRequest ID:         " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Acknowledge_R_PDU::operator == ( const Acknowledge_R_PDU & Value ) const
{
    if( Acknowledge_PDU::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Acknowledge_R_PDU::operator != ( const Acknowledge_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
