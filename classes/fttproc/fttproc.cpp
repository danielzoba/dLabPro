// dLabPro class CFTTproc (FTTproc)
// - Fourier-t-transform
//
// AUTHOR : Steffen Kuerbis
// PACKAGE: dLabPro/classes
//
// This file was generated by dcg. DO NOT MODIFY! Modify fttproc.def instead.
// 
// Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
// - Chair of System Theory and Speech Technology, TU Dresden
// - Chair of Communications Engineering, BTU Cottbus
// 
// This file is part of dLabPro.
// 
// dLabPro is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
// 
// dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
// details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with dLabPro. If not, see <http://www.gnu.org/licenses/>.


//{{CGEN_INCLUDE
//}}CGEN_END
#include "dlp_fttproc.h"

// Class CFTTproc

CFTTproc::CFTTproc(const char* lpInstanceName, BOOL bCallVirtual) : inherited(lpInstanceName,0)
{
	DEBUGMSG(-1,"CFTTproc::CFTTproc; (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	dlp_strcpy(m_lpClassName,"FTTproc");
	dlp_strcpy(m_lpObsoleteName,"");
	dlp_strcpy(m_lpProjectName,"FTTproc");
	dlp_strcpy(m_version.no,"1.0.0");
	dlp_strcpy(m_version.date,"");
	m_nClStyle = CS_AUTOACTIVATE;

	if (bCallVirtual)
	{
		DLPASSERT(OK(AutoRegisterWords()));
		Init(TRUE);
	}
}

CFTTproc::~CFTTproc()
{
  //{{CGEN_DONECODE

  dlm_ftt_done(m_lpFtt,FALSE);

  DONE;

  //}}CGEN_DONECODE
}

INT16 CFTTproc::AutoRegisterWords()
{
	DEBUGMSG(-1,"CFTTproc::AutoRegisterWords",0,0,0);
	IF_NOK(inherited::AutoRegisterWords()) return NOT_EXEC;

	//{{CGEN_REGISTERWORDS
	REGISTER_METHOD("-analyze","",LPMF(CFTTproc,OnAnalyze),"Run ftt filtering.",0,"<data dSignal> <data dPitch> <data dReal> <data dImag> <FTTproc this>","")
	REGISTER_METHOD("-status","",LPMF(CFTTproc,Status),"Display status information.",0,"<FTTproc this>","")
	REGISTER_OPTION("/noreset","",LPMV(m_bNoreset),NULL,"Do not reset filter states on -analyze.",0)

	// Register fields
	REGISTER_FIELD("bandwidth","",LPMV(m_nBandwidth),LPMF(CFTTproc,OnBandwidthChanged),"bandwidth [Bark].",0,3004,1,"float",(FLOAT32)0.8)
	REGISTER_FIELD("coeff","",LPMV(m_nCoeff),LPMF(CFTTproc,OnCoeffChanged),"number of frequency channels .",0,2004,1,"int",(INT32)20)
	REGISTER_FIELD("finc","",LPMV(m_nFinc),LPMF(CFTTproc,OnFincChanged),"frequency increment [Bark].",0,3004,1,"float",(FLOAT32)0.8)
	REGISTER_FIELD("ftt","",LPMV(m_lpFtt),NULL,"",FF_HIDDEN | FF_NOSET,6000,1,"MLP_FTT_TYPE*",NULL)
	REGISTER_FIELD("ftt_type","",LPMV(m_lpsFttType),LPMF(CFTTproc,OnFttTypeChanged),"type of ftt.",0,255,255,"char[255]","M")
	REGISTER_FIELD("log","",LPMV(m_nLog),LPMF(CFTTproc,OnLogChanged),"range of logarithm in compatibility mode [dB]",0,3004,1,"float",(FLOAT32)90.0)
	REGISTER_FIELD("maxval","",LPMV(m_nMaxval),LPMF(CFTTproc,OnMaxvalChanged),"maximum value of samples in compatibility mode",0,3004,1,"float",(FLOAT32)32767.0)
	REGISTER_FIELD("norm_coeff","",LPMV(m_nNormCoeff),LPMF(CFTTproc,OnNormCoeffChanged),"normalize factor",0,3004,1,"float",(FLOAT32)1.0)
	REGISTER_FIELD("sm_coeff","",LPMV(m_nSmCoeff),LPMF(CFTTproc,OnSmCoeffChanged),"smooth coefficient",0,3004,1,"float",(FLOAT32)0.7)
	REGISTER_FIELD("startfreq","",LPMV(m_nStartfreq),LPMF(CFTTproc,OnStartfreqChanged),"start frequency [Hz].",0,3004,1,"float",(FLOAT32)100.)
	REGISTER_ERROR("~e8_1_0__1",EL_WARNING,FTT_LEN,"Parameters len, wlen and crate not equal. wlen is used!")
	REGISTER_ERROR("~e9_1_0__1",EL_WARNING,FTT_WINDOW,"Window type is '%s'. FTT sets wtype to '%s'!")
	REGISTER_ERROR("~e0_2_0__1",EL_ERROR,FTT_WTYPE,"FTT type is '%s'. FTT needs ftt_type '%s'.")
	//}}CGEN_REGISTERWORDS

	return O_K;
}

INT16 CFTTproc::Init(BOOL bCallVirtual)
{
	DEBUGMSG(-1,"CFTTproc::Init, (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	//{{CGEN_INITCODE
  INIT;
	//}}CGEN_INITCODE

	// If last derivation call reset (do not reset members; already done by Init())
	if (bCallVirtual) return Reset(FALSE);
	else              return O_K;
}

INT16 CFTTproc::Reset(BOOL bResetMembers)
{
	DEBUGMSG(-1,"CFTTproc::Reset; (bResetMembers=%d)",(int)bResetMembers,0,0);
	//{{CGEN_RESETCODE

  // Call reset of class CFBAproc
  RESET;
  // Extra reset

    m_nSrate = 8000.;
    m_nLen = 4;
    m_nCrate = m_nLen;
    m_nWlen = m_nLen;
    m_nCoeff = 20;
    m_nOutDim = m_nCoeff;
    dlp_strcpy(m_lpsWtype,"rectangle");
  if(InitFTT(FALSE) != O_K) return NOT_EXEC;

	//}}CGEN_RESETCODE

	return O_K;
}

INT16 CFTTproc::ClassProc()
{
	//{{CGEN_CLASSCODE
  return CLASSPROC;
	//}}CGEN_CLASSCODE

	return O_K;
}

#define CODE_DN3 /* check this for xml specific save code */
#define SAVE  SAVE_DN3
INT16 CFTTproc::Serialize(CDN3Stream* lpDest)
{
	//{{CGEN_SAVECODE
  return SAVE;
	//}}CGEN_SAVECODE

	return O_K;
}
#undef  SAVE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific save code */
#define SAVE  SAVE_XML
INT16 CFTTproc::SerializeXml(CXmlStream* lpDest)
{
	//{{CGEN_SAVECODE
  return SAVE;
	//}}CGEN_SAVECODE

	return O_K;
}
#undef  SAVE
#undef  CODE_XML

#define CODE_DN3 /* check this for dn3 specific restore code */
#define RESTORE  RESTORE_DN3
INT16 CFTTproc::Deserialize(CDN3Stream* lpSrc)
{
	//{{CGEN_RESTORECODE
  return RESTORE;
	//}}CGEN_RESTORECODE

	return O_K;
}
#undef  RESTORE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific restore code */
#define RESTORE  RESTORE_XML
INT16 CFTTproc::DeserializeXml(CXmlStream* lpSrc)
{
	//{{CGEN_RESTORECODE
  return RESTORE;
	//}}CGEN_RESTORECODE

	return O_K;
}
#undef  RESTORE
#undef  CODE_XML

INT16 CFTTproc::Copy(CDlpObject* __iSrc)
{
	//{{CGEN_COPYCODE
  return COPY;
	//}}CGEN_COPYCODE

	return O_K;
}

// Runtime class type information and class factory
INT16 CFTTproc::InstallProc(void* lpItp)
{
	//{{CGEN_INSTALLCODE
  return INSTALL;
	//}}CGEN_INSTALLCODE

	return O_K;
}

CFTTproc* CFTTproc::CreateInstance(const char* lpName)
{
	CFTTproc* lpNewInstance;
	ICREATEEX(CFTTproc,lpNewInstance,lpName,NULL);
	return lpNewInstance;
}

INT16 CFTTproc::GetClassInfo(SWord* lpClassWord)
{
	if (!lpClassWord) return NOT_EXEC;
	dlp_memset(lpClassWord,0,sizeof(SWord));

	lpClassWord->nWordType          = WL_TYPE_FACTORY;
	lpClassWord->nFlags             = CS_AUTOACTIVATE;
	lpClassWord->ex.fct.lpfFactory  = (LP_FACTORY_PROC)CFTTproc::CreateInstance;
	lpClassWord->ex.fct.lpfInstall  = CFTTproc::InstallProc;
	lpClassWord->ex.fct.lpProject   = "FTTproc";
	lpClassWord->ex.fct.lpBaseClass = "FBAproc";
	lpClassWord->lpComment          = "Fourier-t-transform";
	lpClassWord->ex.fct.lpAutoname  = "";
	lpClassWord->ex.fct.lpCname     = "CFTTproc";
	lpClassWord->ex.fct.lpAuthor    = "Steffen Kuerbis";

	dlp_strcpy(lpClassWord->lpName             ,"FTTproc");
	dlp_strcpy(lpClassWord->lpObsname          ,"");
	dlp_strcpy(lpClassWord->ex.fct.version.no  ,"1.0.0");

	return O_K;
}

INT16 CFTTproc::GetInstanceInfo(SWord* lpClassWord)
{
	return CFTTproc::GetClassInfo(lpClassWord);
}

BOOL CFTTproc::IsKindOf(const char* lpClassName)
{
  if (dlp_strncmp(lpClassName,"FTTproc",L_NAMES) == 0) return TRUE;
  else return inherited::IsKindOf(lpClassName);
}

INT16 CFTTproc::ResetAllOptions(BOOL bInit)
{
	DEBUGMSG(-1,"CFTTproc::ResetAllOptions;",0,0,0);
	//{{CGEN_RESETALLOPTIONS
	_this->m_bNoreset = FALSE;
	//}}CGEN_RESETALLOPTIONS

	return inherited::ResetAllOptions(bInit);
}

// Generated primary method invocation functions

#ifndef __NOITP
//{{CGEN_PMIC
INT16 CFTTproc::OnAnalyze()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	data* dImag = MIC_GET_I_EX(dImag,data,1,1);
	data* dReal = MIC_GET_I_EX(dReal,data,2,2);
	data* dPitch = MIC_GET_I_EX(dPitch,data,3,3);
	data* dSignal = MIC_GET_I_EX(dSignal,data,4,4);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Analyze(dSignal, dPitch, dReal, dImag);
	return __nErr;
}

//}}CGEN_PMIC
#endif /* #ifndef __NOITP */


// Generated secondary method invocation functions

//{{CGEN_SMIC
INT16 CFTTproc::Analyze(data* dSignal, data* dPitch, data* dReal, data* dImag)
{
    /* Check parameters for FTT */
    if((m_nWlen!=m_nLen)||(m_nWlen!=m_nCrate))
    {  IERROR(this, FTT_LEN,"wlen",0,0);                                  //  Error in Paramters
       m_nLen=m_nCrate=m_nWlen;
    }
    if(dlp_strncmp(dlp_strlwr(m_lpsWtype),"rectangle",255))
    {  IERROR(this, FTT_WINDOW, m_lpsWtype, "rectangle",0);          //  Error in Paramters
       dlp_strcpy(m_lpsWtype,"rectangle");
    }
    if(dlp_strncmp(m_lpsFttType,"M",255) && dlp_strncmp(m_lpsFttType,"C",255))
      return IERROR(this, FTT_WTYPE, m_lpsFttType,  "M or C",0);                 //  Error in Paramters

    if(InitFTT(m_bNoreset) != O_K) return NOT_EXEC;

    return CFBAproc::Analyze(dSignal,dPitch,dReal,dImag);
	return O_K;
}

//}}CGEN_SMIC


// Generated option change callback functions

//{{CGEN_OCCF
//}}CGEN_OCCF


// Generated field change callback functions

//{{CGEN_FCCF
INT16 CFTTproc::OnBandwidthChanged()
{
    return InitFTT(FALSE);

	return O_K;
}

INT16 CFTTproc::OnCoeffChanged()
{
    InitFTT(FALSE);

	return O_K;
}

INT16 CFTTproc::OnFincChanged()
{
    return InitFTT(FALSE);

	return O_K;
}

INT16 CFTTproc::OnFttTypeChanged()
{
    return InitFTT(FALSE);

	return O_K;
}

INT16 CFTTproc::OnLogChanged()
{
    return InitFTT(FALSE);

	return O_K;
}

INT16 CFTTproc::OnMaxvalChanged()
{
    return InitFTT(FALSE);

	return O_K;
}

INT16 CFTTproc::OnNormCoeffChanged()
{
    return InitFTT(FALSE);

	return O_K;
}

INT16 CFTTproc::OnSmCoeffChanged()
{
    return InitFTT(FALSE);

	return O_K;
}

INT16 CFTTproc::OnStartfreqChanged()
{
    return InitFTT(FALSE);

	return O_K;
}

//}}CGEN_FCCF


// EOF
