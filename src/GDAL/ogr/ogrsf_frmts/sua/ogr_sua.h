/******************************************************************************
 * $Id: ogr_sua.h 31777 2015-11-26 14:14:41Z rouault $
 *
 * Project:  SUA Translator
 * Purpose:  Definition of classes for OGR .sua driver.
 * Author:   Even Rouault, even dot rouault at mines dash paris dot org
 *
 ******************************************************************************
 * Copyright (c) 2010, Even Rouault <even dot rouault at mines-paris dot org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#ifndef OGR_SUA_H_INCLUDED
#define OGR_SUA_H_INCLUDED

#include "ogrsf_frmts.h"

/************************************************************************/
/*                             OGRSUALayer                              */
/************************************************************************/

class OGRSUALayer : public OGRLayer
{
    OGRFeatureDefn*    poFeatureDefn;
    OGRSpatialReference *poSRS;

    VSILFILE*          fpSUA;
    int                bEOF;
    int                bHasLastLine;
    CPLString          osLastLine;

    int                nNextFID;

    OGRFeature *       GetNextRawFeature();

  public:
                        OGRSUALayer(VSILFILE* fp);
                        ~OGRSUALayer();


    virtual void                ResetReading();
    virtual OGRFeature *        GetNextFeature();

    virtual OGRFeatureDefn *    GetLayerDefn() { return poFeatureDefn; }

    virtual int                 TestCapability( const char * );
};

/************************************************************************/
/*                           OGRSUADataSource                           */
/************************************************************************/

class OGRSUADataSource : public OGRDataSource
{
    char*               pszName;

    OGRLayer**          papoLayers;
    int                 nLayers;

  public:
                        OGRSUADataSource();
                        ~OGRSUADataSource();

    int                 Open( const char * pszFilename );

    virtual const char*         GetName() { return pszName; }

    virtual int                 GetLayerCount() { return nLayers; }
    virtual OGRLayer*           GetLayer( int );

    virtual int                 TestCapability( const char * );
};

#endif /* ndef OGR_SUA_H_INCLUDED */
