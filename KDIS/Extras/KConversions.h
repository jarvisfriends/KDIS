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
    KConversions
    created:    18/12/2008
    author:     Karl Jones

    purpose:    Holds all common conversions, Datum conversion,
                unit conversion etc
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include <cmath>

#ifndef KDIS_PI
    #define KDIS_PI 3.14159265358979323846
#endif

namespace KDIS {
namespace UTILS {

/************************************************************************/
/* Conversions to and from radians / degrees                            */
/************************************************************************/

template<class Type>
inline Type RadToDeg( Type Rad )
{
    return static_cast<Type>(Rad * ( 180.0 / KDIS_PI ));
};

template<class Type>
inline Type DegToRad( Type Deg )
{
    return static_cast<Type>(Deg * ( KDIS_PI / 180.0 ));
};

/************************************************************************/
/* Conversions to and from feet / meters                                */
/************************************************************************/

template<class Type>
inline Type FeetToMeters( Type Feet )
{
    return static_cast<Type>(Feet / 3.2808);
};

//////////////////////////////////////////////////////////////////////////

template<class Type>
inline Type MetersToFeet( Type Meters )
{
    return static_cast<Type>(Meters * 3.2808);
};

/************************************************************************/
/* Conversions to and from Geocentric / Geodetic - ECEF / LLA           */
/************************************************************************/

// Reference Ellipsoids, data taken from Wikipedia and DoD, WGS84, DMA TR 8350.2-B,1 Sept. 1991

enum RefEllipsoid
{
    Airy,
    Airy_Modified,
    Australian_National,
    Bessel_1841,
    Bessel_1841_Namibia,
    Clarke_1866,
    Clarke_1880,
    Everest_Sabah_Sarawak,
    Everest_1830,
    Everest_1948,
    Everest_1956,
    Everest_1969,
    Fischer_1960,
    Fischer_1960_Modified,
    Fischer_1968,
    GRS_1980,
    Helmert_1906,
    Hough,
    International_1924,
    Karsovsky_1940,
    SGS_1985,
    South_American_1969,
    Sphere_6371km,
    WGS_1960,
    WGS_1966,
    WGS_1972,
    WGS_1984
};

//////////////////////////////////////////////////////////////////////////

template<class Type>
inline void GetEllipsoidAxis( RefEllipsoid R, Type & MajorAxis, Type & MinorAxis )
{
    switch( R )
    {
    case Airy:
        MajorAxis = static_cast<Type>(6377563.396);
        MinorAxis = static_cast<Type>(6356256.909);
        // 1/F 299.324965
        break;

    case Airy_Modified:
        MajorAxis = static_cast<Type>(6377340.189);
        MinorAxis = static_cast<Type>(6356034.448);
        // 1/F 299.324965
        break;

    case Australian_National:
        MajorAxis = static_cast<Type>(6378160.000);
        MinorAxis = static_cast<Type>(6356774.719);
        // 1/F 298.250000
        break;

    case Bessel_1841:
        MajorAxis = static_cast<Type>(6377397.155);
        MinorAxis = static_cast<Type>(6356078.963);
        // 1/F 299.152813
        break;

    case Bessel_1841_Namibia:
        MajorAxis = static_cast<Type>(6377483.865);
        MinorAxis = static_cast<Type>(6356078.963);
        // 1/F 299.152813
        break;

    case Clarke_1866:
        MajorAxis = static_cast<Type>(6378206.400);
        MinorAxis = static_cast<Type>(6356583.800);
        // 1/F 294.978698
        break;

    case Clarke_1880:
        MajorAxis = static_cast<Type>(6378249.145);
        MinorAxis = static_cast<Type>(6356514.870);
        // 1/F 293.465000
        break;

    case Everest_Sabah_Sarawak:
        MajorAxis = static_cast<Type>(6377298.556);
        MinorAxis = static_cast<Type>(6356097.550);
        // 1/F 300.801700
        break;

    case Everest_1830:
        MajorAxis = static_cast<Type>(6377276.345);
        MinorAxis = static_cast<Type>(6356075.413);
        // 1/F 300.801700
        break;

    case Everest_1948:
        MajorAxis = static_cast<Type>(6377304.063);
        MinorAxis = static_cast<Type>(6356103.039);
        // 1/F 300.801700
        break;

    case Everest_1956:
        MajorAxis = static_cast<Type>(6377301.243);
        MinorAxis = static_cast<Type>(6356100.228);
        // 1/F 300.801700
        break;

    case Everest_1969:
        MajorAxis = static_cast<Type>(6377295.664);
        MinorAxis = static_cast<Type>(6356094.668);
        // 1/F 300.801700
        break;

    case Fischer_1960:
        MajorAxis = static_cast<Type>(6378166.000);
        MinorAxis = static_cast<Type>(6356784.284);
        // 1/F 298.300000
        break;

    case Fischer_1960_Modified:
        MajorAxis = static_cast<Type>(6378155.000);
        MinorAxis = static_cast<Type>(6356773.320);
        // 1/F 298.300000
        break;

    case Fischer_1968:
        MajorAxis = static_cast<Type>(6378150.000);
        MinorAxis = static_cast<Type>(6356768.337);
        // 1/F 298.300000
        break;

    case GRS_1980:
        MajorAxis = static_cast<Type>(6378137.000);
        MinorAxis = static_cast<Type>(6356752.314);
        // 1/F 298.257222
        break;

    case Helmert_1906:
        MajorAxis = static_cast<Type>(6378200.000);
        MinorAxis = static_cast<Type>(6356818.170);
        // 1/F 298.300000
        break;

    case Hough:
        MajorAxis = static_cast<Type>(6378270.000);
        MinorAxis = static_cast<Type>(6356794.343);
        // 1/F 297.000000
        break;

    case International_1924:
        MajorAxis = static_cast<Type>(6378388.000);
        MinorAxis = static_cast<Type>(6356911.946);
        // 1/F 297.000000
        break;

    case Karsovsky_1940:
        MajorAxis = static_cast<Type>(6378245.000);
        MinorAxis = static_cast<Type>(6356863.019);
        // 1/F 298.300000
        break;

    case SGS_1985:
        MajorAxis = static_cast<Type>(6378136.000);
        MinorAxis = static_cast<Type>(6356751.302);
        // 1/F 298.257000
        break;

    case South_American_1969:
        MajorAxis = static_cast<Type>(6378160.000);
        MinorAxis = static_cast<Type>(6356774.719);
        // 1/F 298.250000
        break;

    case Sphere_6371km:
        MajorAxis = static_cast<Type>(6371000);
        MinorAxis = static_cast<Type>(6371000);
        break;

    case WGS_1960:
        MajorAxis = static_cast<Type>(6378165.000);
        MinorAxis = static_cast<Type>(6356783.287);
        // 1/F 298.300000
        break;

    case WGS_1966:
        MajorAxis = static_cast<Type>(6378145.000);
        MinorAxis = static_cast<Type>(6356759.769);
        // 1/F 298.250000
        break;

    case WGS_1972:
        MajorAxis = static_cast<Type>(6378135.000);
        MinorAxis = static_cast<Type>(6356750.520);
        // 1/F 298.260000
        break;

    case WGS_1984:
        MajorAxis = static_cast<Type>(6378137.000);
        MinorAxis = static_cast<Type>(6356752.314245);
        // 1/F 298.257224
        break;
    }
};

//////////////////////////////////////////////////////////////////////////

template<class Type>
inline void DecimalToDMS( Type Decimal, Type & DegOUT, Type & MinOUT, Type & SecOUT )
{
    Decimal = std::abs( Decimal ); // Make sure the value is not negative
    DegOUT = static_cast<Type>(( KUINT32 )Decimal);
    Decimal -= DegOUT; // Degrees

    MinOUT = static_cast<Type>(Decimal * 60.0);

    Decimal = MinOUT - static_cast<Type>(( KUINT32 )MinOUT);

    MinOUT = static_cast<Type>(( KUINT32 )MinOUT); // Minutes
    SecOUT = static_cast<Type>(Decimal * 60.0); // Seconds
};

//////////////////////////////////////////////////////////////////////////

template<class Type>
inline Type DMSToDecimal( Type Deg, Type Min, Type Sec )
{
    return static_cast<Type>(Deg + ( Min / 60.0 ) + ( Sec / 3600.0 ));
};

//////////////////////////////////////////////////////////////////////////

//************************************
// FullName:    KDIS::UTILS<Type>::GeodeticToGeocentric
// Description: Converts Geodetic coords to Geocentric Cartesian.
// Parameter:   Type GeodeticLat - in degrees
// Parameter:   Type GeodeticLon - in degrees
// Parameter:   Type GeodeticHeight - in meters
// Parameter:   Type & GeocentricX
// Parameter:   Type & GeocentricY
// Parameter:   Type & GeocentricZ
// Parameter:   RefEllipsoid R
//************************************

template<class Type>
inline void GeodeticToGeocentric( Type GeodeticLat, Type GeodeticLon, Type GeodeticHeight,
                                  Type & GeocentricX, Type & GeocentricY, Type & GeocentricZ,
                                  RefEllipsoid R )
{
    GeodeticLat = DegToRad( GeodeticLat );
    GeodeticLon = DegToRad( GeodeticLon );

    Type MajorAxis, MinorAxis;
    GetEllipsoidAxis( R, MajorAxis, MinorAxis );

    Type Esq = ( pow( MajorAxis, 2 ) - pow( MinorAxis, 2 ) ) / pow( MajorAxis, 2 );
    Type V = MajorAxis / sqrt( 1 - ( Esq * pow( sin( GeodeticLat ), 2 ) ) );

    GeocentricX = ( V + GeodeticHeight ) * cos( GeodeticLat ) * cos( GeodeticLon );
    GeocentricY = ( V + GeodeticHeight ) * cos( GeodeticLat ) * sin( GeodeticLon );
    GeocentricZ = ( ( 1 - Esq ) * V + GeodeticHeight ) * sin( GeodeticLat );
};

//////////////////////////////////////////////////////////////////////////

//************************************
// FullName:    KDIS::UTILS<Type>::GeocentricToGeodetic
// Description: Converts Geocentric Cartesian coords to Geodetic.
// Parameter:   Type x - in radians
// Parameter:   Type y - in radians
// Parameter:   Type z - in radians
// Parameter:   Type & lat
// Parameter:   Type & lon
// Parameter:   Type & alt
// Parameter:   RefEllipsoid R
//************************************

template<class Type>
inline void GeocentricToGeodetic( Type x, Type y, Type z,Type & lat, Type & lon, Type & alt, RefEllipsoid R )
{
    // This is the 'closed form solution'
    // equations described by https://microem.ru/files/2012/08/GPS.G1-X-00006.pdf
    // and many other places on the web. start at wikipedia, "ECEF"

    Type  a;   // semi-major axis
    Type  b;   // semi-minor axis
    GetEllipsoidAxis( R, a, b );

    Type  const e2       = (a*a-b*b) / (a*a); // eccentricity (first)
    Type  const e_prime2 = (a*a-b*b) / (b*b); // eccentricity (second)
    Type  const f        =  1 - b/a ;   // flattening

    // 'auxiliary values'
    Type const p = sqrt(x*x + y*y);
    Type const theta = static_cast<Type>(atan2 ( (z*a) , (p*b)));

    // latitude
    lat = static_cast<Type>(atan2 ( ( z + (e_prime2) * b * pow (sin(theta),3) ),
                                    ( p - (e2*a*pow(cos(theta),3)))));

    // Radius of curvature
    Type const N = a / sqrt ( 1 - e2*sin(lat)*sin(lat));

    // altitude
    Type cosLat = cos(lat);
    Type const COS_THRESHOLD = 0.0000001;
    if( (cosLat > -COS_THRESHOLD) && (cosLat < COS_THRESHOLD) ) // Very near the poles
        alt = std::abs( z ) - b;
    else
        alt = p / cosLat - N;

    // longitude
    lon = static_cast<Type>(atan2(y,x));

    lon = RadToDeg( lon );
    lat = RadToDeg( lat );
};

//////////////////////////////////////////////////////////////////////////

template<class Type>
inline void RotateAboutAxis( Type d[3] ,Type const s[3] ,Type const n[3] ,Type  t )
{
    double  st = sin( t );
    double  ct = cos( t );

    d[0] = static_cast<Type>((1.0-ct)*(n[0]*n[0]*s[0] + n[0]*n[1]*s[1] + n[0]*n[2]*s[2]) + ct*s[0] + st*(n[1]*s[2]-n[2]*s[1]));
    d[1] = static_cast<Type>((1.0-ct)*(n[0]*n[1]*s[0] + n[1]*n[1]*s[1] + n[1]*n[2]*s[2]) + ct*s[1] + st*(n[2]*s[0]-n[0]*s[2]));
    d[2] = static_cast<Type>((1.0-ct)*(n[0]*n[2]*s[0] + n[1]*n[2]*s[1] + n[2]*n[2]*s[2]) + ct*s[2] + st*(n[0]*s[1]-n[1]*s[0]));
};

template<class Type>
inline void Cross( Type  d[3] ,Type const  a[3] ,Type const b[3] )
{
    d[0] = a[1] * b[2] - b[1] * a[2] ;
    d[1] = b[0] * a[2] - a[0] * b[2] ;
    d[2] = a[0] * b[1] - b[0] * a[1] ;
};

template<class Type>
inline Type Dot( Type const a[3] ,Type const b[3] )
{
    return  a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
};

//************************************
// FullName:    KDIS::UTILS<Type>::HeadingPitchRollToEuler
// Description: Converts Heading, Pitch and Roll to Euler for DIS.
// Parameter:   Type H - Heading in radians
// Parameter:   Type P - Pitch in radians
// Parameter:   Type R - Roll in radians
// Parameter:   Type Lat - Geodetic Latitude in radians
// Parameter:   Type Lon - Geodetic Longitude in radians
// Parameter:   Type & Psi - Euler angle out
// Parameter:   Type & Theta - Euler angle out
// Parameter:   Type & Phi - Euler angle out
//************************************

template<class Type>
inline void HeadingPitchRollToEuler( Type H, Type P, Type R, Type Lat, Type Lon, Type & Psi, Type & Theta,
                                     Type & Phi )
{
    // local NED
    //Type const  D0[3] = { 1.0 , 0.0 , 0.0 };
    Type const  E0[3] = { 0.0 , 1.0 , 0.0 };
    Type const  N0[3] = { 0.0 , 0.0 , 1.0 };
    Type        me[3];
    Type        N[3];
    Type        E[3];
    Type        D[3];
    // 'E'
    RotateAboutAxis( E , E0 , N0 , Lon );
    me[0] = -E[0] ;
    me[1] = -E[1] ;
    me[2] = -E[2] ;
    // 'N'
    RotateAboutAxis( N , N0 , me , Lat );
    // 'D'
    Cross( D , N , E );
    /*
    *  Orientation
    */
    // rotate about D by heading
    Type  N1[3] , E1[3] , D1[3] ;
    RotateAboutAxis( N1 , N  , D , H );
    RotateAboutAxis( E1 , E  , D , H );
    memcpy( D1 , D  , sizeof( Type[3] ) );
    // rotate about E1 vector by pitch
    Type  N2[3] , E2[3] , D2[3] ;
    RotateAboutAxis( N2 , N1 , E1 , P );
    memcpy( E2 , E1 , sizeof( Type[3] ) );
    RotateAboutAxis( D2 , D1 , E1 , P );
    // rotate about N2 by roll
    Type  N3[3] , E3[3] , D3[3] ;
    memcpy( N3 , N2 , sizeof( Type[3] ) );
    RotateAboutAxis( E3 , E2 , N2 , R );
    RotateAboutAxis( D3 , D2 , N2 , R );

    // calculate angles from vectors
    Type  x0[3] = { 1.0 , 0.0 , 0.0 };   // == D0
    Type  y0[3] = { 0.0 , 1.0 , 0.0 };   // == E0
    Type  z0[3] = { 0.0 , 0.0 , 1.0 };   // == Z0
    Type  y2[3] ;
    Type  z2[3] ;
    Psi = static_cast<Type>(atan2(  Dot( N3 , y0 ) , Dot( N3 , x0 ) ));
    Theta = static_cast<Type>(atan2( -Dot( N3 , z0 ) , sqrt( pow(Dot( N3 , x0 ), 2) + pow(Dot( N3 , y0 ), 2) ) ));
    RotateAboutAxis( y2 , y0 , z0 , Psi );
    RotateAboutAxis( z2 , z0 , y2 , Theta );
    Phi = static_cast<Type>(atan2(  Dot( E3 , z2 ) , Dot( E3 , y2 ) ));
};

//////////////////////////////////////////////////////////////////////////

//************************************
// FullName:    KDIS::UTILS<Type>::EulerToHeadingPitchRoll
// Description: Converts Euler to Heading, Pitch and Roll.
// Parameter:   Type Lat - Geodetic Latitude in radians
// Parameter:   Type Lon - Geodetic Longitude in radians
// Parameter:   Type Psi - Euler angle
// Parameter:   Type Theta - Euler angle
// Parameter:   Type Phi - Euler angle
// Parameter:   Type & H - Heading in radians out
// Parameter:   Type & P - Pitch in radians out
// Parameter:   Type & R - Roll in radians out
//************************************

template<class Type>
void EulerToHeadingPitchRoll( Type Lat, Type Lon, Type Psi, Type Theta, Type Phi, Type & H, Type & P, Type & R )
{
    // local NED vectors in ECEF coordinate frame
    Type  N[3] ;
    Type  E[3] ;
    Type  D[3] ;

    // Calculate NED from lat and lon
    // local NED
    //Type const  D0[3] = { 1. , 0. , 0. };
    Type const  E0[3] = { 0. , 1. , 0. };
    Type const  N0[3] = { 0. , 0. , 1. };
    Type        me[3] ;
    // 'E'
    RotateAboutAxis( E , E0 , N0 , Lon );
    me[0] = -E[0] ;
    me[1] = -E[1] ;
    me[2] = -E[2] ;
    // 'N'
    RotateAboutAxis( N , N0 , me , Lat );
    // 'D'
    Cross( D , N , E );
    /*
     *  Orientation:
     *    input : (x0,y0,z0)=(N,E,D) and (Psi,Theta,Phi Euler angles)
     *    output: (x3,y3,z3)=body vectors in local frame
     */
    // rotate about Z by Psi
    Type  X[]= {1.,0.,0.};
    Type  Y[]= {0.,1.,0.};
    Type  Z[]= {0.,0.,1.};
    Type  X1[3] , Y1[3] , Z1[3] ;
    RotateAboutAxis( X1 , X  , Z , Psi );
    RotateAboutAxis( Y1 , Y  , Z , Psi );
    memcpy(          Z1 , Z  , sizeof( Type[3] ) );
    // rotate about Y1 vector by Theta
    Type  X2[3] , Y2[3] , Z2[3] ;
    RotateAboutAxis( X2 , X1 , Y1 , Theta );
    memcpy(          Y2 , Y1 , sizeof( Type[3] ) );
    RotateAboutAxis( Z2 , Z1 , Y1 , Theta );
    // rotate about X2 by Phi
    Type  X3[3] , Y3[3] , Z3[3] ;
    memcpy(          X3 , X2 , sizeof( Type[3] ) );
    RotateAboutAxis( Y3 , Y2 , X2 , Phi );
    RotateAboutAxis( Z3 , Z2 , X2 , Phi );
    // calculate angles from vectors
    Type x0[3];
    memcpy( x0 , N , sizeof( Type[3] ) );
    Type y0[3];
    memcpy( y0 , E , sizeof( Type[3] ) );
    Type z0[3];
    memcpy( z0 , D , sizeof( Type[3] ) );
    Type  y2[3] ;
    Type  z2[3] ;
    H = static_cast<Type>(atan2(  Dot( X3 , y0 ) , Dot( X3 , x0 ) ));
    P = static_cast<Type>(atan2( -Dot( X3 , z0 ) , sqrt( pow(Dot( X3 , x0 ), 2) + pow(Dot( X3 , y0 ), 2) ) ));
    RotateAboutAxis( y2 , y0 , z0 , H );
    RotateAboutAxis( z2 , z0 , y2 , P );
    R = static_cast<Type>(atan2(  Dot( Y3 , z2 ) , Dot( Y3 , y2 ) ));
}

} // END namespace UTILS
} // END namespace KDIS

#undef KDIS_PI
