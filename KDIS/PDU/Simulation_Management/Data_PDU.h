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

/********************************************************************
    class:      Data_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Sent in response to a data query or set data request.
    size:       320 bits/ 40 octets - not including variable param sizes
*********************************************************************/

#pragma once

#include "./Comment_PDU.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Data_PDU : public Comment_PDU
{
protected:

    KUINT32 m_ui32RequestID;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 DATA_PDU_SIZE = 40;

    Data_PDU();

    Data_PDU( const Header & H );

    Data_PDU(KDataStream &stream) noexcept(false);

    Data_PDU(const Header &H, KDataStream &stream) noexcept(false);

    Data_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OriginatingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID,
              KUINT32 RequestID );

    virtual ~Data_PDU();

    //************************************
    // FullName:    KDIS::PDU::Data_PDU::SetRequestID
    //              KDIS::PDU::Data_PDU::GetRequestID
    // Description: Request ID, identifies the matching response
    //              to a Data Query PDU or Set Data PDU.
    // Parameter:   KUINT32 ID
    //************************************
    void SetRequestID( KUINT32 ID );
    KUINT32 GetRequestID() const;

    //************************************
    // FullName:    KDIS::PDU::Data_PDU::SetVariableDatum
    // Description: Sets variable datums and updates PDU length.
    // Parameter:   const vector<VarDtmPtr> & VD
    //************************************
    virtual void SetVariableDatum(const std::vector<KDIS::DATA_TYPE::VarDtmPtr> & VD);

    //************************************
    // FullName:    KDIS::PDU::Data_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Data_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream?
    //************************************
    virtual void Decode(KDataStream &stream, bool ignoreHeader = false) noexcept(false);

    //************************************
    // FullName:    KDIS::PDU::Data_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Data_PDU & Value ) const;
    KBOOL operator != ( const Data_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
