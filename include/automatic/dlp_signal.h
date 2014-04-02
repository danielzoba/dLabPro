/* dLabPro class CSignal (signal)
 * - Header file
 *
 * AUTHOR : Guntram Strecha
 * PACKAGE: dLabPro/classes
 *
 * This file was generated by dcg. DO NOT MODIFY! Modify signal.def instead.
 * 
 * Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
 * - Chair of System Theory and Speech Technology, TU Dresden
 * - Chair of Communications Engineering, BTU Cottbus
 * 
 * This file is part of dLabPro.
 * 
 * dLabPro is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 * 
 * dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with dLabPro. If not, see <http://www.gnu.org/licenses/>.
 */

/*{{CGEN_INCLUDE */
#include "dlp_config.h"
#include "dlp_object.h"
#include "dlp_var.h"
#include "dlp_math.h"
#include "dlp_data.h"
/*}}CGEN_END */

/*{{CGEN_ERRORS */
#undef FOP_ERR_FAIL        
#undef FOP_ERR_NOTSUPP     
#undef FOP_ERR_INVARG      
#undef FOP_ERR_INVDESCR    
#define FOP_ERR_FAIL         -1001
#define FOP_ERR_NOTSUPP      -1002
#define FOP_ERR_INVARG       -1003
#define FOP_ERR_INVDESCR     -1004
/*}}CGEN_END */

/* C/C++ language abstraction layer */
#undef signal_par
#define signal_par CSignal

/* dLabPro/C++ language abstraction layer */
#undef signal
#define signal CSignal

/*{{CGEN_DEFINE */
#define FOP_PRECALC(idX,idY,idS,idR,idL)                                              {                                                                                     DLPASSERT((idY!=NULL)&&(idX!=NULL));                                                if(idY==idX) { ICREATE(CData,idR,NULL); }                                           else           idR = idY;                                                           if(CData_GetNNumericComps(idX) == CData_GetNComps(idX)) idS = idX;                  else {                                                                                ICREATEEX(CData, idL, "~lab", NULL);                                                ICREATEEX(CData, idS, "~src", NULL);                                                CMatrix_CopyLabels(idL,idX);                                                        CData_Select(idS,idX,0,CData_GetNNumericComps(idX));                              }                                                                                 }
#define FOP_POSTCALC(idX,idY,idS,idR,idL)                                             {                                                                                     if(idR != idY) {                                                                      CData_Copy(BASEINST(idY),BASEINST(idR));                                            IDESTROY(idR);                                                                    }                                                                                   CData_CopyDescr(idY,idX);                                                           CDlpObject_CopySelective(BASEINST(idY),BASEINST(idX),WL_TYPE_INSTANCE);             CData_Join(idY,idL);                                                                if(idS != idX) IDESTROY(idS);                                                       IDESTROY(idL);                                                                    }
/*}}CGEN_DEFINE */

#ifndef __SIGNAL_H
#define __SIGNAL_H

/*{{CGEN_HEADERCODE */
#undef  dlp_calloc
#define dlp_calloc(A,B) __dlp_calloc(A,B,__FILE__,__LINE__,"CSignal_...",NULL)
/*}}CGEN_HEADERCODE */

/* Class CSignal */

#ifdef __cplusplus

class CSignal : public CDlpObject 
{

typedef CDlpObject inherited;
typedef CSignal thisclass;

/*{{CGEN_FRIENDS */
/*}}CGEN_FRIENDS */
public:
	CSignal(const char* lpInstanceName, BOOL bCallVirtual = 1);
	virtual ~CSignal();

/* Virtual and static function overrides */
public:
	virtual INT16 AutoRegisterWords();
	virtual INT16 Init(BOOL bCallVirtual = 0);
	virtual INT16 Reset(BOOL bResetMembers = 1);
	virtual INT16 Serialize(CDN3Stream* lpDest);
	virtual INT16 SerializeXml(CXmlStream* lpDest);
	virtual INT16 Deserialize(CDN3Stream* lpSrc);
	virtual INT16 DeserializeXml(CXmlStream* lpSrc);
	virtual INT16 Copy(CDlpObject* iSrc);
	virtual INT16 ClassProc();
	static  INT16 InstallProc(void* lpItp);
	static  CSignal* CreateInstance(const char* lpName);
	static  INT16 GetClassInfo(SWord* lpClassWord);
	virtual INT16 GetInstanceInfo(SWord* lpClassWord);
	virtual BOOL  IsKindOf(const char* lpClassName);
	virtual INT16 ResetAllOptions(BOOL bInit = 0);

/* Primary method invocation functions             */
/* DO NOT CALL THESE FUNCTIONS FROM C SCOPE.       */
/* THEY MAY INTERFERE WITH THE INTERPRETER SESSION */
#ifndef __NOITP
public:
/*{{CGEN_PMIC */
/*}}CGEN_PMIC */
#endif /* #ifndef __NOITP */

/* Secondary method invocation functions */
public:
/*{{CGEN_SMIC */
/*}}CGEN_SMIC */

/* Option changed callback functions */
public:
/*{{CGEN_OCCF */
/*}}CGEN_OCCF */

/* Field changed callback functions */
public:
/*{{CGEN_FCCF */
/*}}CGEN_FCCF */

/* Scanned member functions */
/*{{CGEN_EXPORT */

/* Taken from 'sig_op.c' */
	public: static INT16 Op(INT16 nOpc, StkItm* R, StkItm* P);

/* Taken from 'sig_iam.c' */
	public: static INT16 Cep2Lpc(CData* idA, CData* idG, CData* idC, INT32 n);
	public: static INT16 Cep2MCep(CData* idC2, CData* idC1, FLOAT64 nLambda2, INT32 n);
	public: static INT16 Cep(CData* idY, CData* idX, INT32 nCoeff);
	public: static INT16 DeFrame(CData* idY, CData* idX, INT32 nLen);
	public: static INT16 DeScale(CData* idY, CData* idX);
	public: static INT16 Distribution(CData* idY, CData* idX, CData* idP);
	public: static INT16 Dtw(CData* idP, CData* idS, CData* idD);
	public: static INT16 F02Exc(CData* idE, CData* idF, INT32 nF, INT32 nL, const char* sT);
	public: static INT16 Fft(CData* idY, CData* idX);
	public: static INT16 Filter(CData* Y, CData* X, CData* B, CData* A, CData* M);
	public: static INT16 Fir(CData* Y, CData* X, CData* B, CData* M);
	public: static INT16 Frame(CData* idY, CData* idX, INT32 nLen, INT32 nStep);
	public: static INT16 GCep(CData* idY, CData* idX, FLOAT64 nGamma, INT32 nCoeff);
	public: static INT16 GCep2GCep(CData* idY, CData* idX, FLOAT64 nGamma2, INT32 n);
	public: static INT16 GCep2Lpc(CData* idY, CData* idG, CData* idX, INT32 n);
	public: static INT16 GCep2MLpc(CData* idY, CData* idG, CData* idX, FLOAT64 nLambda2, INT32 n);
	public: static INT16 GCepNorm(CData* idY, CData* idG, CData* idX);
	public: static INT16 GetF0(CData* idY, CData* idX, INT32 nMin, INT32 nMax, const char* sTyp);
	public: static INT16 GMult(CData* idY, CData* idX);
	public: static INT16 IFft(CData* idY, CData* idX);
	public: static INT16 IGCepNorm(CData* idY, CData* idG, CData* idX);
	public: static INT16 IGMult(CData* idY, CData* idX);
	public: static INT16 Iir(CData* Y, CData* X, CData* A, CData* M);
	public: static INT16 IMCep(CData* idY, CData* idC, CData* idE, FLOAT64 nLambda);
	public: static INT16 IMlt(CData* idY, CData* idX);
	public: static INT16 Lpc(CData* idY, CData* idG, CData* idX, INT32 nCoeff, const char* lpsMethod);
	public: static INT16 Lpc2Cep(CData* idC, CData* idG, CData* idA, INT32 n);
	public: static INT16 Lpc2GCep(CData* idY, CData* idG, CData* idX, FLOAT64 nGamma2, INT32 n);
	public: static INT16 Lpc2MGCep(CData* idY, CData* idG, CData* idX, FLOAT64 nGamma2, FLOAT64 nLambda2, INT32 n);
	public: static INT16 Lpc2MLpc(CData* idA2, CData* idG2, CData* idG1, CData* idA1, FLOAT64 nLambda2, INT32 n);
	public: static INT16 Lsf2Poly(CData* idY, CData* idX);
	public: static INT16 MCep2Cep(CData* idC2, CData* idC1, INT32 n);
	public: static INT16 MCep2MCep(CData* idC2, CData* idC1, FLOAT64 nLambda2, INT32 n);
	public: static INT16 MCep2MLpc(CData* idY, CData* idG, CData* idX, FLOAT64 nLambda2, INT32 n);
	public: static INT16 MCep(CData* idY, CData* idX, FLOAT64 nLambda, INT32 nCoeff);
	public: static INT16 Denoise(CData* idY, CData* idX, INT32 nT, FLOAT64 nP, const char* lpsType);
	public: static INT16 MCepEnhance(CData* idY, CData* idC);
	public: static INT16 MFb(CData* idY, CData* idX, FLOAT64 nLambda, INT32 nCoeff, const char* lpsMethod);
	public: static INT16 Mfft(CData* idY, CData* idX, FLOAT64 nLambda);
	public: static INT16 MFilter(CData* idY, CData* idX, CData* idB, CData* idA, FLOAT64 nLambda, CData* idM);
	public: static INT16 MFir(CData* Y, CData* X, CData* B, FLOAT64 nLambda, CData* M);
	public: static INT16 MGCep(CData* idY, CData* idX, FLOAT64 nGamma, FLOAT64 nLambda, INT32 nCoeff);
	public: static INT16 MGCep2Lpc(CData* idY, CData* idG, CData* idX, INT32 n);
	public: static INT16 MGCep2MGCep(CData* idY, CData* idX, FLOAT64 nGamma2, FLOAT64 nLambda2, INT32 n);
	public: static INT16 MGCep2MLpc(CData* idY, CData* idG, CData* idX, FLOAT64 nLambda2, INT32 n);
	public: static INT16 MIir(CData* Y, CData* X, CData* A, FLOAT64 nLambda, CData* M);
	public: static INT16 MLpc(CData* idY, CData* idG, CData* idX, FLOAT64 nLambda, INT32 nCoeff, const char* lpsMethod);
	public: static INT16 MLpc2GCep(CData* idY, CData* idG, CData* idX, FLOAT64 nGamma2, INT32 n);
	public: static INT16 MLpc2Lpc(CData* idA2, CData* idG2, CData* idG1, CData* idA1, INT32 n);
	public: static INT16 MLpc2MCep(CData* idY, CData* idG, CData* idX, FLOAT64 nLambda2, INT32 n);
	public: static INT16 ISvq(CData* idY, CData* idI, CData* idQ);
	public: static INT16 IVq(CData* idY, CData* idI, CData* idQ);
	public: static INT16 MLpc2MGCep(CData* idY, CData* idG, CData* idX, FLOAT64 nGamma2, FLOAT64 nLambda2, INT32 n);
	public: static INT16 MLpc2MLpc(CData* idA2, CData* idG2, CData* idG1, CData* idA1, FLOAT64 nLambda2, INT32 n);
	public: static INT16 MLsf2MLsf(CData* idY, CData* idX, FLOAT64 nLambda2);
	public: static INT16 Mlt(CData* idY, CData* idX);
	public: static INT16 Noisify(CData* idY, CData* idX);
	public: static INT16 Pitchmark(CData* idY, CData* idX, char* sMethod, INT32 nMin, INT32 nMean, INT32 nMax);
	public: static INT16 Poly2Lsf(CData* idY, CData* idX);
	public: static INT16 Rmdc(CData* idY, CData* idX);
	public: static INT16 Roots(CData* idY, CData* idX);
	public: static INT16 Scale(CData* idY, CData* idX, COMPLEX64 nScale);
	public: static INT16 Svq(CData* idQ, CData* idI, CData* idX, CData* idB);
	public: static INT16 Unwrap(CData* idY, CData* idX);
	public: static INT16 Vq(CData* idQ, CData* idI, CData* idX, INT32 nBits, const char* sMethod);
	public: static INT16 Window(CData* idY, CData* idX, INT32 nLenIn, INT32 nLenOut, const char* lpsWindow, BOOL bNorm);
	public: static INT16 Zcr(CData* idY, CData* idX, CData* idP);

/* Taken from 'sig_work.c' */
	private: static COMPLEX64 GetMinQuant(INT16 nType, COMPLEX64 nScale);
	private: static INT16 GetVar(CData* idSrc, const char* sName, COMPLEX64* nValue);
	private: static INT16 SetVar(CData* idDst, const char* sName, COMPLEX64 nValue);
	private: static INT16 GetData(CData* idSrc, const char* sName, CData** iData);
	private: static INT16 SetData(CData* idDst, const char* sName, CData* iData);
	private: static INT16 ScaleImpl(CData* idY, CData* idX, COMPLEX64 nScale);
	public: static INT16 SetScale(CData* idDst, COMPLEX64 nScale);
	private: static INT16 FftImpl(CData* idY, CData* idX, BOOL bInv);
/*}}CGEN_EXPORT */

/* Member variables */
public:
/*{{CGEN_ICXX_FIELDS */
/*}}CGEN_ICXX_FIELDS */

#else  /* #ifdef __cplusplus */

typedef struct CSignal
{
  /* Pointer to C base instance */
  struct CDlpObject* m_lpBaseInstance;

/*{{CGEN_IC_FIELDS */
/*}}CGEN_IC_FIELDS */

#endif /* #ifdef __cplusplus */

/*{{CGEN_FIELDS */
/*}}CGEN_FIELDS */

/*{{CGEN_OPTIONS */
/*}}CGEN_OPTIONS */
}

#ifndef __cplusplus
CSignal
#endif
;

/* Class CSignal (C functions)*/

/* Virtual function overrides */
void  CSignal_Constructor(CSignal*, const char* lpInstanceName, BOOL bCallVirtual);
void  CSignal_Destructor(CDlpObject*);
INT16 CSignal_AutoRegisterWords(CDlpObject*);
INT16 CSignal_Reset(CDlpObject*, BOOL bResetMembers);
INT16 CSignal_Init(CDlpObject*, BOOL bCallVirtual);
INT16 CSignal_Serialize(CDlpObject*, CDN3Stream* lpDest);
INT16 CSignal_SerializeXml(CDlpObject*, CXmlStream* lpDest);
INT16 CSignal_Deserialize(CDlpObject*, CDN3Stream* lpSrc);
INT16 CSignal_DeserializeXml(CDlpObject*, CXmlStream* lpSrc);
INT16 CSignal_Copy(CDlpObject*, CDlpObject* __iSrc);
INT16 CSignal_ClassProc(CDlpObject*);
INT16 CSignal_InstallProc(void* lpItp);
CSignal* CSignal_CreateInstance(const char* lpName);
INT16 CSignal_GetClassInfo(SWord* lpClassWord);
INT16 CSignal_GetInstanceInfo(CDlpObject*, SWord* lpClassWord);
BOOL  CSignal_IsKindOf(CDlpObject*, const char* lpClassName);
INT16 CSignal_ResetAllOptions(CDlpObject*, BOOL bInit);

/* Primary method invocation functions             */
/* DO NOT CALL THESE FUNCTIONS FROM C SCOPE.       */
/* THEY MAY INTERFERE WITH THE INTERPRETER SESSION */
#ifndef __NOITP
/*{{CGEN_CPMIC */
/*}}CGEN_CPMIC */
#endif /* #ifndef __NOITP */

/* Secondary method invocation functions */
/*{{CGEN_CSMIC */
/*}}CGEN_CSMIC */

/* Option changed callback functions */
/*{{CGEN_COCCF */
/*}}CGEN_COCCF */

/* Field changed callback functions */
/*{{CGEN_CFCCF */
/*}}CGEN_CFCCF */

/* Scanned C (member) functions */
/*{{CGEN_CEXPORT */

/* Taken from 'sig_op.c' */
INT16 CSignal_Op(INT16 nOpc, StkItm* R, StkItm* P);

/* Taken from 'sig_iam.c' */
INT16 CSignal_Cep2Lpc(CData* idA, CData* idG, CData* idC, INT32 n);
INT16 CSignal_Cep2MCep(CData* idC2, CData* idC1, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_Cep(CData* idY, CData* idX, INT32 nCoeff);
INT16 CSignal_DeFrame(CData* idY, CData* idX, INT32 nLen);
INT16 CSignal_DeScale(CData* idY, CData* idX);
INT16 CSignal_Distribution(CData* idY, CData* idX, CData* idP);
INT16 CSignal_Dtw(CData* idP, CData* idS, CData* idD);
INT16 CSignal_F02Exc(CData* idE, CData* idF, INT32 nF, INT32 nL, const char* sT);
INT16 CSignal_Fft(CData* idY, CData* idX);
INT16 CSignal_Filter(CData* Y, CData* X, CData* B, CData* A, CData* M);
INT16 CSignal_Fir(CData* Y, CData* X, CData* B, CData* M);
INT16 CSignal_Frame(CData* idY, CData* idX, INT32 nLen, INT32 nStep);
INT16 CSignal_GCep(CData* idY, CData* idX, FLOAT64 nGamma, INT32 nCoeff);
INT16 CSignal_GCep2GCep(CData* idY, CData* idX, FLOAT64 nGamma2, INT32 n);
INT16 CSignal_GCep2Lpc(CData* idY, CData* idG, CData* idX, INT32 n);
INT16 CSignal_GCep2MLpc(CData* idY, CData* idG, CData* idX, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_GCepNorm(CData* idY, CData* idG, CData* idX);
INT16 CSignal_GetF0(CData* idY, CData* idX, INT32 nMin, INT32 nMax, const char* sTyp);
INT16 CSignal_GMult(CData* idY, CData* idX);
INT16 CSignal_IFft(CData* idY, CData* idX);
INT16 CSignal_IGCepNorm(CData* idY, CData* idG, CData* idX);
INT16 CSignal_IGMult(CData* idY, CData* idX);
INT16 CSignal_Iir(CData* Y, CData* X, CData* A, CData* M);
INT16 CSignal_IMCep(CData* idY, CData* idC, CData* idE, FLOAT64 nLambda);
INT16 CSignal_IMlt(CData* idY, CData* idX);
INT16 CSignal_Lpc(CData* idY, CData* idG, CData* idX, INT32 nCoeff, const char* lpsMethod);
INT16 CSignal_Lpc2Cep(CData* idC, CData* idG, CData* idA, INT32 n);
INT16 CSignal_Lpc2GCep(CData* idY, CData* idG, CData* idX, FLOAT64 nGamma2, INT32 n);
INT16 CSignal_Lpc2MGCep(CData* idY, CData* idG, CData* idX, FLOAT64 nGamma2, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_Lpc2MLpc(CData* idA2, CData* idG2, CData* idG1, CData* idA1, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_Lsf2Poly(CData* idY, CData* idX);
INT16 CSignal_MCep2Cep(CData* idC2, CData* idC1, INT32 n);
INT16 CSignal_MCep2MCep(CData* idC2, CData* idC1, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_MCep2MLpc(CData* idY, CData* idG, CData* idX, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_MCep(CData* idY, CData* idX, FLOAT64 nLambda, INT32 nCoeff);
INT16 CSignal_Denoise(CData* idY, CData* idX, INT32 nT, FLOAT64 nP, const char* lpsType);
INT16 CSignal_MCepEnhance(CData* idY, CData* idC);
INT16 CSignal_MFb(CData* idY, CData* idX, FLOAT64 nLambda, INT32 nCoeff, const char* lpsMethod);
INT16 CSignal_Mfft(CData* idY, CData* idX, FLOAT64 nLambda);
INT16 CSignal_MFilter(CData* idY, CData* idX, CData* idB, CData* idA, FLOAT64 nLambda, CData* idM);
INT16 CSignal_MFir(CData* Y, CData* X, CData* B, FLOAT64 nLambda, CData* M);
INT16 CSignal_MGCep(CData* idY, CData* idX, FLOAT64 nGamma, FLOAT64 nLambda, INT32 nCoeff);
INT16 CSignal_MGCep2Lpc(CData* idY, CData* idG, CData* idX, INT32 n);
INT16 CSignal_MGCep2MGCep(CData* idY, CData* idX, FLOAT64 nGamma2, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_MGCep2MLpc(CData* idY, CData* idG, CData* idX, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_MIir(CData* Y, CData* X, CData* A, FLOAT64 nLambda, CData* M);
INT16 CSignal_MLpc(CData* idY, CData* idG, CData* idX, FLOAT64 nLambda, INT32 nCoeff, const char* lpsMethod);
INT16 CSignal_MLpc2GCep(CData* idY, CData* idG, CData* idX, FLOAT64 nGamma2, INT32 n);
INT16 CSignal_MLpc2Lpc(CData* idA2, CData* idG2, CData* idG1, CData* idA1, INT32 n);
INT16 CSignal_MLpc2MCep(CData* idY, CData* idG, CData* idX, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_ISvq(CData* idY, CData* idI, CData* idQ);
INT16 CSignal_IVq(CData* idY, CData* idI, CData* idQ);
INT16 CSignal_MLpc2MGCep(CData* idY, CData* idG, CData* idX, FLOAT64 nGamma2, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_MLpc2MLpc(CData* idA2, CData* idG2, CData* idG1, CData* idA1, FLOAT64 nLambda2, INT32 n);
INT16 CSignal_MLsf2MLsf(CData* idY, CData* idX, FLOAT64 nLambda2);
INT16 CSignal_Mlt(CData* idY, CData* idX);
INT16 CSignal_Noisify(CData* idY, CData* idX);
INT16 CSignal_Pitchmark(CData* idY, CData* idX, char* sMethod, INT32 nMin, INT32 nMean, INT32 nMax);
INT16 CSignal_Poly2Lsf(CData* idY, CData* idX);
INT16 CSignal_Rmdc(CData* idY, CData* idX);
INT16 CSignal_Roots(CData* idY, CData* idX);
INT16 CSignal_Scale(CData* idY, CData* idX, COMPLEX64 nScale);
INT16 CSignal_Svq(CData* idQ, CData* idI, CData* idX, CData* idB);
INT16 CSignal_Unwrap(CData* idY, CData* idX);
INT16 CSignal_Vq(CData* idQ, CData* idI, CData* idX, INT32 nBits, const char* sMethod);
INT16 CSignal_Window(CData* idY, CData* idX, INT32 nLenIn, INT32 nLenOut, const char* lpsWindow, BOOL bNorm);
INT16 CSignal_Zcr(CData* idY, CData* idX, CData* idP);

/* Taken from 'sig_work.c' */
COMPLEX64 CSignal_GetMinQuant(INT16 nType, COMPLEX64 nScale);
INT16 CSignal_GetVar(CData* idSrc, const char* sName, COMPLEX64* nValue);
INT16 CSignal_SetVar(CData* idDst, const char* sName, COMPLEX64 nValue);
INT16 CSignal_GetData(CData* idSrc, const char* sName, CData** iData);
INT16 CSignal_SetData(CData* idDst, const char* sName, CData* iData);
INT16 CSignal_ScaleImpl(CData* idY, CData* idX, COMPLEX64 nScale);
INT16 CSignal_SetScale(CData* idDst, COMPLEX64 nScale);
INT16 CSignal_FftImpl(CData* idY, CData* idX, BOOL bInv);
/*}}CGEN_CEXPORT */

#endif /*#ifndef __SIGNAL_H */


/* EOF */
