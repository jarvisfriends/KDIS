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

#include "./Intercom_Signal_PDU.h"

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

Intercom_Signal_PDU::Intercom_Signal_PDU()
{
    m_ui8PDUType = IntercomSignal_PDU_Type;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Intercom_Signal_PDU::Intercom_Signal_PDU(KDataStream &stream) noexcept(false)
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Intercom_Signal_PDU::Intercom_Signal_PDU(const Header &H, KDataStream &stream) noexcept(false) :
    Signal_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Intercom_Signal_PDU::Intercom_Signal_PDU( const EntityIdentifier & ID, KUINT16 RadioID, const EncodingScheme & ES,
                                          KUINT32 SampleRate, KUINT16 Samples, const KOCTET * Data, KUINT16 DataLength ) :
    Signal_PDU( ID, RadioID, ES,SampleRate, Samples, Data, DataLength )
{
    m_ui8PDUType = IntercomSignal_PDU_Type;
    SetData( Data, DataLength );
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Intercom_Signal_PDU::~Intercom_Signal_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

KString Intercom_Signal_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Intercom Signal PDU-\n"
       << Radio_Communications_Header::GetAsString()
       << m_EncodingScheme.GetAsString()
       << "Sample Rate:        " << m_ui32SampleRate << "\n"
       << "Data Length:        " << m_ui16DataLength << "\n"
       << "Samples:            " << m_ui16Samples    << "\n";

    // Data is not printed as we don't know what the data is.

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Intercom_Signal_PDU::operator == ( const Intercom_Signal_PDU & Value ) const
{
    if( Signal_PDU::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Intercom_Signal_PDU::operator != ( const Intercom_Signal_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
