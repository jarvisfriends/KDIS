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
    class:      Data_Query_R_PDU
    DIS:        (6) 1278.1A - 1998
    created:    29:04:2009
    author:     Karl Jones

    purpose:    Requests for data from an entity are communicated by a Data Query-R PDU
*********************************************************************/

#pragma once

#include "./../Simulation_Management/Data_Query_PDU.h"
#include "./Reliability_Header.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Data_Query_R_PDU : public Data_Query_PDU,
                                     public Reliability_Header
{
public:

    static const KUINT16 DATA_QUERY_R_PDU_SIZE = 44;

    Data_Query_R_PDU();

    Data_Query_R_PDU(KDataStream &stream) noexcept(false);

    Data_Query_R_PDU(const Header &H, KDataStream &stream) noexcept(false);

    virtual ~Data_Query_R_PDU();

    //************************************
    // FullName:    KDIS::PDU::Data_Query_R_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Data_Query_R_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream?
    //************************************
    virtual void Decode(KDataStream &stream, bool ignoreHeader = false) noexcept(false);

    //************************************
    // FullName:    KDIS::PDU::Data_Query_R_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Data_Query_R_PDU & Value ) const;
    KBOOL operator != ( const Data_Query_R_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS

