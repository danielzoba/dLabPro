// dLabPro class CFunction (function)
// - dLabPro script container and executer
//
// AUTHOR : Matthias Wolff
// PACKAGE: dLabPro/classes
//
// This file was generated by dcg. DO NOT MODIFY! Modify function.def instead.
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
#include "dlp_function.h"

// Class CFunction

CFunction::CFunction(const char* lpInstanceName, BOOL bCallVirtual) : inherited(lpInstanceName,0)
{
	DEBUGMSG(-1,"CFunction::CFunction; (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	dlp_strcpy(m_lpClassName,"function");
	dlp_strcpy(m_lpObsoleteName,"");
	dlp_strcpy(m_lpProjectName,"function");
	dlp_strcpy(m_version.no,"2.5.3");
	dlp_strcpy(m_version.date,"");
	m_nClStyle = CS_AUTOACTIVATE;

	if (bCallVirtual)
	{
		DLPASSERT(OK(AutoRegisterWords()));
		Init(TRUE);
	}
}

CFunction::~CFunction()
{
  //{{CGEN_DONECODE
  ArgDestroy();
  StackDestroy();
  DONE;
  //}}CGEN_DONECODE
}

INT16 CFunction::AutoRegisterWords()
{
	DEBUGMSG(-1,"CFunction::AutoRegisterWords",0,0,0);
	IF_NOK(inherited::AutoRegisterWords()) return NOT_EXEC;

	//{{CGEN_REGISTERWORDS

	// Register methods
	REGISTER_METHOD("(","",LPMF(CFunction,BraceOn),"Ignored, to be used for better legibility of UPN code",0,"<function this>","")
	REGISTER_METHOD(")","",LPMF(CFunction,BraceOff),"Ignored, to be used for better legibility of UPN code",0,"<function this>","")
	REGISTER_METHOD("-argv","",LPMF(CFunction,OnArgv),"Gets a command line argument.",0,"<int nArg> <function this>","")
	REGISTER_METHOD("-cd","",LPMF(CFunction,OnCd),"Change directory.",0,"<string sDir> <function this>","")
	REGISTER_METHOD("-check","",LPMF(CFunction,Check),"Self check of session.",0,"<function this>","")
	REGISTER_METHOD("-copy","",LPMF(CFunction,OnCopy),"Copies an instance.",0,"<instance iSrc> <instance iDst>","")
	REGISTER_METHOD("-cwd","",LPMF(CFunction,OnCwd),"Get the current working directory.",0,"<function this>","")
	REGISTER_METHOD("-destroy","",LPMF(CFunction,OnDestroy),"Destroys an instance",0,"<instance iInst>","")
	REGISTER_METHOD("-dup","",LPMF(CFunction,Dup),"Duplicates the top stack element.",0,"<function this>","")
	REGISTER_METHOD("-echo","",LPMF(CFunction,OnEcho),"Prints a message.",0,"<string sMessage> <function this>","")
	REGISTER_METHOD("-explain","explain",LPMF(CFunction,OnExplain),"Prints detailled description of an instance or identifier.",0," ","[<identifier>]")
	REGISTER_METHOD("-get","get",LPMF(CFunction,OnGet),"Reads a field of an instance.",0,"<instance iInst>","<field_id>")
	REGISTER_METHOD("-help","help",LPMF(CFunction,OnHelp),"Prints help table of an instance.",0,"<instance iInst>","")
	REGISTER_METHOD("-internalize","internalize",LPMF(CFunction,OnInternalize),"Makes instance field(s) internal.",0,"<instance iInst>","<field_id>|*")
	REGISTER_METHOD("-list","",LPMF(CFunction,OnList),"Lists operation, token sequence, labes, etc.",0,"<function this>","[aggrops|classes|help|labels|memory|scalops|strops|tokens|types]")
	REGISTER_METHOD("-load","",LPMF(CFunction,OnLoad),"Loads source code from a file.",0,"<string sFilename> <function this>","")
	REGISTER_METHOD("-pid","",LPMF(CFunction,OnPid),"Returns the process ID.",0,"<function this>","")
	REGISTER_METHOD("-prompt","",LPMF(CFunction,OnPrompt),"Prompt for user input.",0,"<string sMessage> <function this>","")
	REGISTER_METHOD("-reset","reset",LPMF(CFunction,OnReset),"Resets (fields of) an instance.",0,"<instance iInst>","[<field_id>|*]")
	REGISTER_METHOD("-restore","",LPMF(CFunction,OnRestore),"Restores an instance from a file.",0,"<string filename> <instance iInst>","")
	REGISTER_METHOD("-rot","",LPMF(CFunction,Rot),"Rotates the stack upwards one element.",0,"<function this>","")
	REGISTER_METHOD("-save","",LPMF(CFunction,OnSave),"Saves an instance to a file.",0,"<string filename> <instance iInst>","")
	REGISTER_METHOD("-see","see",LPMF(CFunction,OnSee),"Prints field(s) of an instance.",0,"<instance iInst>","<field_id>|*")
	REGISTER_METHOD("-set","set",LPMF(CFunction,OnSet),"Writes a field of an instance.",0,"<value> <instance iInst>","<field_id>")
	REGISTER_METHOD("-stacktrace","",LPMF(CFunction,OnStacktrace),"Dumps the stack trace to a data table.",0,"<data idTrace> <function this>","")
	REGISTER_METHOD("-status","",LPMF(CFunction,Status),"Prints status information of the function.",0,"<function this>","")
	REGISTER_METHOD("-swap","",LPMF(CFunction,Swap),"Exchanges the two top stack elements.",0,"<function this>","")
	REGISTER_METHOD("-system","",LPMF(CFunction,OnSystem),"Executes a shell command.",0,"<string sCmd> <function this>","")
	REGISTER_METHOD("-trace_error","",LPMF(CFunction,OnTraceError),"Stops dLabPro when the specified error occurs",0,"<string lpsError> <function this>","")
	REGISTER_METHOD("-type","type",LPMF(CFunction,OnType),"Select elementary data type.",0,"<function this>","<typename>")
	REGISTER_METHOD("-version","",LPMF(CFunction,OnVersion),"Returns the dLabPro build identifier.",0,"<function this>","")
	REGISTER_METHOD("?error","",LPMF(CFunction,OnGetError),"Check error state.",0,"<function this>","")
	REGISTER_METHOD("?instance","-is_instance",LPMF(CFunction,OnIsInstance),"Check instance existence and class.",0,"<string sInstanceId> <string sClassId> <function this>","")
	REGISTER_METHOD("?platform","",LPMF(CFunction,OnPlatform),"Tests if dLabPro is running on specified platform.",0,"<string sPlatformId> <function this>","")
	REGISTER_METHOD("break","",LPMF(CFunction,Break),"Break while loop",0,"<function this>","")
	REGISTER_METHOD("brk","",LPMF(CFunction,OnBrk),"Break point.",0,"<string sId> <function this>","")
	REGISTER_METHOD("cont","",LPMF(CFunction,Cont),"Resume after break point.",0,"<function this>","")
	REGISTER_METHOD("continue","",LPMF(CFunction,Continue),"Continue while loop",0,"<function this>","")
	REGISTER_METHOD("else","",LPMF(CFunction,Else),"Conditional jump (negative control path).",0,"<function this>","")
	REGISTER_METHOD("end","endif",LPMF(CFunction,End),"Conditional jump or while loop (end of control paths).",0,"<function this>","")
	REGISTER_METHOD("goto","",LPMF(CFunction,Goto),"Unconditional jump to a jump label.",0,"<function this>","<labelname>")
	REGISTER_METHOD("if","",LPMF(CFunction,OnIf),"Conditional jump (positive control path).",0,"<BOOL bCondition> <function this>","")
	REGISTER_METHOD("include","",LPMF(CFunction,OnInclude),"Includes a source file.",0,"<string sFilename> <function this>","")
	REGISTER_METHOD("label","",LPMF(CFunction,Label),"== Preprocessor directive ==; defines a jump label.",0,"<function this>","<labelname>")
	REGISTER_METHOD("leave","",LPMF(CFunction,Leave),"Leaves the function.",0,"<function this>","")
	REGISTER_METHOD("parent","up",LPMF(CFunction,Parent),"Implicit identifier of parent instance.",0,"<function this>","")
	REGISTER_METHOD("quit","",LPMF(CFunction,Quit),"Exits dLabPro session.",0,"<function this>","")
	REGISTER_METHOD("return","",LPMF(CFunction,Return),"Leaves the function returning a value.",0,"<value>","")
	REGISTER_METHOD("step","",LPMF(CFunction,Step),"Execute one instruction after a break point.",0,"<function this>","")
	REGISTER_METHOD("this","-root",LPMF(CFunction,This),"Implicit identifier of the current function.",0,"<function this>","")
	REGISTER_METHOD("while","",LPMF(CFunction,OnWhile),"Loop",0,"<BOOL bCondition> <function this>","")
	REGISTER_METHOD("{","",LPMF(CFunction,Define),"Defines the function body.",0,"<function this>","<script> }")

	// Register options
	REGISTER_OPTION("/disarm","",LPMV(m_bDisarm),LPMF(CFunction,OnDisarmSet),"Do not call classproc for next interpreted instance.",0)
	REGISTER_OPTION("/dn3","",LPMV(m_bDn3),NULL,"(De)serialize from/to DN3 file.",0)
	REGISTER_OPTION("/inline","",LPMV(m_bInline),LPMF(CFunction,OnInlineSet),"Define an inline function.",0)
	REGISTER_OPTION("/noerror","",LPMV(m_bNoerror),NULL,"Suppress error messages.",0)
	REGISTER_OPTION("/nonstop","",LPMV(m_bNonstop),LPMF(CFunction,OnNonstopSet),"Never stop running.",OF_NONAUTOMATIC)
	REGISTER_OPTION("/stderr","",LPMV(m_bStderr),NULL,"Use standard error stream.",0)
	REGISTER_OPTION("/stop","",LPMV(m_bStop),LPMF(CFunction,OnStopSet),"Stop at break points and long listings.",OF_NONAUTOMATIC)
	REGISTER_OPTION("/time","",LPMV(m_bTime),NULL,"Measures and outputs elapsed time to process one line of input.",0)
	REGISTER_OPTION("/xml","",LPMV(m_bXml),NULL,"(De)serialize from/to XML file.",0)
	REGISTER_OPTION("/zip","",LPMV(m_bZip),NULL,"Compress file during serialization.",0)

	// Register fields
	REGISTER_FIELD("ai","",LPMV(m_iAi),NULL,"",FF_HIDDEN | FF_NOSET | FF_NOSAVE,6002,1,"",NULL)
	REGISTER_FIELD("ai2","",LPMV(m_iAi2),NULL,"",FF_HIDDEN | FF_NOSET | FF_NOSAVE,6002,1,"",NULL)
	REGISTER_FIELD("ai_used","",LPMV(m_bAiUsed),NULL,"",FF_HIDDEN | FF_NOSET | FF_NOSAVE,1000,1,"bool",(BOOL)0)
	REGISTER_FIELD("arg","",LPMV(m_idArg),NULL,"",FF_HIDDEN | FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("caller","",LPMV(m_iCaller),NULL,"",FF_HIDDEN | FF_NOSET | FF_NOSAVE | FF_NONAUTOMATIC,6002,1,"",NULL)
	REGISTER_FIELD("last_fml","",LPMV(m_lpsLastFml),NULL,"Interpreter code translated and queued from last formula token.",FF_NOSET | FF_NOSAVE,5001,1,"text",NULL)
	REGISTER_FIELD("mic","",LPMV(m_mic),NULL,"",FF_HIDDEN | FF_NOSET,10000,1,"SMic",0)
	REGISTER_FIELD("par","",LPMV(m__iPar),NULL,"",FF_HIDDEN | FF_NOSET | FF_NOSAVE,6002,1,"CDgen",NULL)
	REGISTER_FIELD("pp","",LPMV(m_nPp),NULL,"",FF_HIDDEN | FF_NOSET,2004,1,"int",(INT32)0)
	REGISTER_FIELD("sfl","",LPMV(m_idSfl),NULL,"",FF_HIDDEN | FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("stack","",LPMV(m_aStack),NULL,"",FF_HIDDEN | FF_NOSET | FF_NOSAVE,6000,1,"StkItm*",NULL)
	REGISTER_FIELD("stack_inst","",LPMV(m_lpasStackInst),NULL,"",FF_HIDDEN | FF_NOSET | FF_NOSAVE,6000,1,"CDlpObject**",NULL)
	REGISTER_FIELD("stack_inst_pos","",LPMV(m_nStackInstPos),NULL,"",FF_HIDDEN | FF_NOSET,2002,1,"short",(INT16)0)
	REGISTER_FIELD("stack_len","",LPMV(m_nStackLen),NULL,"",FF_HIDDEN | FF_NOSET,2002,1,"short",(INT16)-1)
	REGISTER_FIELD("stack_str","",LPMV(m_lpasStackStr),NULL,"",FF_HIDDEN | FF_NOSET | FF_NOSAVE,6000,1,"char**",NULL)
	REGISTER_FIELD("stack_str_pos","",LPMV(m_nStackStrPos),NULL,"",FF_HIDDEN | FF_NOSET,2002,1,"short",(INT16)0)
	REGISTER_FIELD("teq","",LPMV(m_idTeq),NULL,"",FF_HIDDEN | FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("teq_offset","",LPMV(m_nTeqOffset),NULL,"",FF_HIDDEN | FF_NOSET,2004,1,"int",(INT32)0)
	REGISTER_FIELD("time","",LPMV(m_time),NULL,"Used by option {@link /time}.",FF_HIDDEN | FF_NOSET | FF_NOSAVE,10000,1,"time_t",dlp_time())
	REGISTER_FIELD("tsq","",LPMV(m_idTsq),NULL,"",FF_HIDDEN | FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("xm","",LPMV(m_nXm),NULL,"",FF_HIDDEN | FF_NOSET,2004,1,"int",(INT32)0)

	// Register errors
	REGISTER_ERROR("~e1_0_0__1",EL_ERROR,FNC_INTERNAL,"Internal error (%s) at %s(%ld).")
	REGISTER_ERROR("~e2_0_0__1",EL_ERROR,FNC_SYNTAX,"Syntax error.")
	REGISTER_ERROR("~e3_0_0__1",EL_ERROR,FNC_EXPECT,"Expect %s.")
	REGISTER_ERROR("~e4_0_0__1",EL_ERROR,FNC_NOTALLOWED,"%s is not allowed %s.")
	REGISTER_ERROR("~e5_0_0__1",EL_ERROR,FNC_STACKOVERFLOW,"Stack overflow.")
	REGISTER_ERROR("~e6_0_0__1",EL_WARNING,FNC_STACKOVERFLOW_WARNING,"Stack overflow (%d unused elements).")
	REGISTER_ERROR("~e7_0_0__1",EL_ERROR,FNC_STACKUNDERFLOW,"Stack underflow%s%s.")
	REGISTER_ERROR("~e8_0_0__1",EL_ERROR,FNC_TYPECAST,"Cannot cast argument %ld from %s to %s.")
	REGISTER_ERROR("~e9_0_0__1",EL_ERROR,FNC_LABEL,"Label '%s' not found.")
	REGISTER_ERROR("~e0_1_0__1",EL_ERROR,FNC_NOMORETOKENS,"No more tokens to execute.")
	REGISTER_ERROR("~e1_1_0__1",EL_ERROR,FNC_UNDEF,"'%s' undefined.")
	REGISTER_ERROR("~e2_1_0__1",EL_ERROR,FNC_DBL,"'%s' was already %s.")
	REGISTER_ERROR("~e3_1_0__1",EL_ERROR,FNC_INVALID,"Invalid %s '%s'.")
	REGISTER_ERROR("~e4_1_0__1",EL_ERROR,FNC_CANTEXEC,"Cannot execute %s %s.%s.")
	REGISTER_ERROR("~e5_1_0__1",EL_ERROR,FNC_UNEXOEF,"Unexpected end of function searching for %s.")
	REGISTER_ERROR("~e6_1_0__1",EL_ERROR,FNC_EXTRACHARS,"Extra characters following %s in %s.")
	REGISTER_ERROR("~e7_1_0__1",EL_ERROR,FNC_NOSET,"Field %s is write-protected.")
	REGISTER_ERROR("~e8_1_0__1",EL_ERROR,FNC_DESTROY,"Cannot destroy instance %s.")
	REGISTER_ERROR("~e9_1_0__1",EL_ERROR,FNC_MISSING,"Missing %s.")
	REGISTER_ERROR("~e0_2_0__1",EL_WARNING,FNC_STDIN,"Broken pipe <stdin>.")
	REGISTER_ERROR("~e1_2_0__1",EL_WARNING,FNC_IGNORE,"Ignoring %s.")
	REGISTER_ERROR("~e2_2_0__1",EL_WARNING,FNC_TOOLONG,"%s too long%s.")
	REGISTER_ERROR("~e3_2_0__1",EL_WARNING,FNC_LISTINI,"Too %s list initializers for record %ld.")
	REGISTER_ERROR("~e4_2_0__1",EL_WARNING,FNC_ASGNONNULL,"Assignment on NULL has no effect.")
	REGISTER_ERROR("~e5_2_0__1",EL_WARNING,FNC_COMPAT,"Backward compatibility: %s")
	//}}CGEN_REGISTERWORDS

	return O_K;
}

INT16 CFunction::Init(BOOL bCallVirtual)
{
	DEBUGMSG(-1,"CFunction::Init, (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	//{{CGEN_INITCODE
  INIT;
  m_nInStyle |= IS_GLOBAL;
  ArgParse();
  if (!GetRootFnc()) SetRootFnc(this);
  LoadClassRegistry(GetRootFnc()==this);

  INT16 i = 0;
  while(dlp_scalop_entry(i)->opc >= 0) {
    REGISTER_OPERATOR(dlp_scalop_entry(i)->sym,NULL,dlp_scalop_entry(i)->opc,dlp_scalop_entry(i)->res,dlp_scalop_entry(i)->ops,dlp_scalop_entry(i)->sig,dlp_scalop_entry(i)->nam);
    i++;
  }

	//}}CGEN_INITCODE

	// If last derivation call reset (do not reset members; already done by Init())
	if (bCallVirtual) return Reset(FALSE);
	else              return O_K;
}

INT16 CFunction::Reset(BOOL bResetMembers)
{
	DEBUGMSG(-1,"CFunction::Reset; (bResetMembers=%d)",(int)bResetMembers,0,0);
	//{{CGEN_RESETCODE
  RESET;
  IFIELD_RESET(CData,"tsq");
  IFIELD_RESET(CData,"sfl");
  if (GetRootFnc()==this) IFIELD_RESET(CDgen,"par");
  CDgen::TsqInit(m_idTsq);
  CDgen::TsqInit(m_idTeq);
  if (GetRootFnc()==this) m__iPar->Setup("dlp");
	//}}CGEN_RESETCODE

	return O_K;
}

INT16 CFunction::ClassProc()
{
	//{{CGEN_CLASSCODE
  CLASSPROC;
  const SMic* lpMic = CDlpObject_MicGet(this);
  m_iCaller = lpMic ? lpMic->iCaller : NULL;
  if (CData_GetNRecs(m_idTsq)>0)
    if (OK(ArgCommit()))
      Exec();
	//}}CGEN_CLASSCODE

	return O_K;
}

#define CODE_DN3 /* check this for xml specific save code */
#define SAVE  SAVE_DN3
INT16 CFunction::Serialize(CDN3Stream* lpDest)
{
	//{{CGEN_SAVECODE
  SAVE;
	//}}CGEN_SAVECODE

	return O_K;
}
#undef  SAVE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific save code */
#define SAVE  SAVE_XML
INT16 CFunction::SerializeXml(CXmlStream* lpDest)
{
	//{{CGEN_SAVECODE
  SAVE;
	//}}CGEN_SAVECODE

	return O_K;
}
#undef  SAVE
#undef  CODE_XML

#define CODE_DN3 /* check this for dn3 specific restore code */
#define RESTORE  RESTORE_DN3
INT16 CFunction::Deserialize(CDN3Stream* lpSrc)
{
	//{{CGEN_RESTORECODE
  CData* idArg = NULL;
  if (GetRootFnc()==this)
  {
    ICREATE(CData,idArg,NULL);
    CData_Copy(idArg,m_idArg);
  }
  RESTORE;
  if (GetRootFnc()==this)
  {
    CData_Copy(m_idArg,idArg);
    IDESTROY(idArg);
    m__iPar->Setup("dlp");
  }
  CDgen::TsqInit(m_idTeq);
	//}}CGEN_RESTORECODE

	return O_K;
}
#undef  RESTORE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific restore code */
#define RESTORE  RESTORE_XML
INT16 CFunction::DeserializeXml(CXmlStream* lpSrc)
{
	//{{CGEN_RESTORECODE
  CData* idArg = NULL;
  if (GetRootFnc()==this)
  {
    ICREATE(CData,idArg,NULL);
    CData_Copy(idArg,m_idArg);
  }
  RESTORE;
  if (GetRootFnc()==this)
  {
    CData_Copy(m_idArg,idArg);
    IDESTROY(idArg);
    m__iPar->Setup("dlp");
  }
  CDgen::TsqInit(m_idTeq);
	//}}CGEN_RESTORECODE

	return O_K;
}
#undef  RESTORE
#undef  CODE_XML

INT16 CFunction::Copy(CDlpObject* __iSrc)
{
	//{{CGEN_COPYCODE
  return COPY;
	//}}CGEN_COPYCODE

	return O_K;
}

// Runtime class type information and class factory
INT16 CFunction::InstallProc(void* lpItp)
{
	//{{CGEN_INSTALLCODE
  return INSTALL;
	//}}CGEN_INSTALLCODE

	return O_K;
}

CFunction* CFunction::CreateInstance(const char* lpName)
{
	CFunction* lpNewInstance;
	ICREATEEX(CFunction,lpNewInstance,lpName,NULL);
	return lpNewInstance;
}

INT16 CFunction::GetClassInfo(SWord* lpClassWord)
{
	if (!lpClassWord) return NOT_EXEC;
	dlp_memset(lpClassWord,0,sizeof(SWord));

	lpClassWord->nWordType          = WL_TYPE_FACTORY;
	lpClassWord->nFlags             = CS_AUTOACTIVATE;
	lpClassWord->ex.fct.lpfFactory  = (LP_FACTORY_PROC)CFunction::CreateInstance;
	lpClassWord->ex.fct.lpfInstall  = CFunction::InstallProc;
	lpClassWord->ex.fct.lpProject   = "function";
	lpClassWord->ex.fct.lpBaseClass = "-";
	lpClassWord->lpComment          = "dLabPro script container and executer";
	lpClassWord->ex.fct.lpAutoname  = "";
	lpClassWord->ex.fct.lpCname     = "CFunction";
	lpClassWord->ex.fct.lpAuthor    = "Matthias Wolff";

	dlp_strcpy(lpClassWord->lpName             ,"function");
	dlp_strcpy(lpClassWord->lpObsname          ,"");
	dlp_strcpy(lpClassWord->ex.fct.version.no  ,"2.5.3");

	return O_K;
}

INT16 CFunction::GetInstanceInfo(SWord* lpClassWord)
{
	return CFunction::GetClassInfo(lpClassWord);
}

BOOL CFunction::IsKindOf(const char* lpClassName)
{
  if (dlp_strncmp(lpClassName,"function",L_NAMES) == 0) return TRUE;
  else return inherited::IsKindOf(lpClassName);
}

INT16 CFunction::ResetAllOptions(BOOL bInit)
{
	DEBUGMSG(-1,"CFunction::ResetAllOptions;",0,0,0);
	//{{CGEN_RESETALLOPTIONS
	_this->m_bDisarm = FALSE;
	_this->m_bDn3 = FALSE;
	_this->m_bInline = FALSE;
	_this->m_bNoerror = FALSE;
	if (bInit) _this->m_bNonstop = FALSE;
	_this->m_bStderr = FALSE;
	if (bInit) _this->m_bStop = FALSE;
	_this->m_bTime = FALSE;
	_this->m_bXml = FALSE;
	_this->m_bZip = FALSE;
	//}}CGEN_RESETALLOPTIONS

	return inherited::ResetAllOptions(bInit);
}

// Generated primary method invocation functions

#ifndef __NOITP
//{{CGEN_PMIC
INT16 CFunction::OnArgv()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	INT32 nArg = (INT32)MIC_GET_N(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	MIC_PUT_S(Argv(nArg));
	return __nErr;
}

INT16 CFunction::OnCd()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	char* sDir = MIC_GET_S(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Cd(sDir);
	return __nErr;
}

INT16 CFunction::OnCwd()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	MIC_PUT_S(Cwd());
	return __nErr;
}

INT16 CFunction::OnEcho()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	char* sMessage = MIC_GET_S(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Echo(sMessage);
	return __nErr;
}

INT16 CFunction::OnLoad()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	char* sFilename = MIC_GET_S(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Load(sFilename);
	return __nErr;
}

INT16 CFunction::OnPid()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	MIC_PUT_N(Pid());
	return __nErr;
}

INT16 CFunction::OnPrompt()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	char* sMessage = MIC_GET_S(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Prompt(sMessage);
	return __nErr;
}

INT16 CFunction::OnStacktrace()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	data* idTrace = MIC_GET_I_EX(idTrace,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Stacktrace(idTrace);
	return __nErr;
}

INT16 CFunction::OnSystem()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	char* sCmd = MIC_GET_S(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	MIC_PUT_N(System(sCmd));
	return __nErr;
}

INT16 CFunction::OnTraceError()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	char* lpsError = MIC_GET_S(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = TraceError(lpsError);
	return __nErr;
}

INT16 CFunction::OnVersion()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	MIC_PUT_S(Version());
	return __nErr;
}

INT16 CFunction::OnIsInstance()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	char* sClassId = MIC_GET_S(1,0);
	char* sInstanceId = MIC_GET_S(2,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	MIC_PUT_B(IsInstance(sInstanceId, sClassId));
	return __nErr;
}

INT16 CFunction::OnPlatform()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	char* sPlatformId = MIC_GET_S(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	MIC_PUT_B(Platform(sPlatformId));
	return __nErr;
}

INT16 CFunction::OnBrk()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	char* sId = MIC_GET_S(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Brk(sId);
	return __nErr;
}

INT16 CFunction::OnIf()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	BOOL bCondition = MIC_GET_B(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = If(bCondition);
	return __nErr;
}

INT16 CFunction::OnInclude()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	char* sFilename = MIC_GET_S(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = Include(sFilename);
	return __nErr;
}

INT16 CFunction::OnWhile()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	BOOL bCondition = MIC_GET_B(1,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = While(bCondition);
	return __nErr;
}

//}}CGEN_PMIC
#endif /* #ifndef __NOITP */


// Generated secondary method invocation functions

//{{CGEN_SMIC
INT16 CFunction::BraceOn()
{
    // Ignored
	return O_K;
}

INT16 CFunction::BraceOff()
{
    // Ignored
	return O_K;
}

INT32 CFunction::Pid()
{
    return dlp_getpid();
	return 0;
}

INT16 CFunction::TraceError(char* lpsError)
{
    CDlpObject_SetTraceError(lpsError);
	return O_K;
}

const char* CFunction::Version()
{
    return dlp_get_version_info();
	return NULL;
}

INT16 CFunction::OnGetError()
{
    // This is no actual method!
    // It's only been defined for documentation.
	return O_K;
}

INT16 CFunction::End()
{
    // Nothing to be done
	return O_K;
}

INT16 CFunction::Label()
{
    // This is no actual method!
    // It is only been defined for documentation.
	return O_K;
}

//}}CGEN_SMIC


// Generated option change callback functions

//{{CGEN_OCCF
INT16 CFunction::OnDisarmSet()
{
    CFunction* iRoot = GetRootFnc();
    if (!iRoot) return NOT_EXEC;
    if(this != iRoot) {
      this->m_bDisarm = FALSE;
      if (iRoot->m_nCheck>=2) Msg(      "  - DELEGATE --> Option /disarm",0,0,0);
      ISETOPTION(iRoot,"/disarm");
    }

	return O_K;
}

INT16 CFunction::OnInlineSet()
{
    if (!(m_nXm & XM_EXEC))
    {
      CFunction* iParent = (CFunction*)OfKind("function",GetParent());
      if (!iParent) return NOT_EXEC;
      if (iParent->m_nCheck>=2) Msg(      "  - DELEGATE --> Option /inline",0,0,0);
    ISETOPTION(iParent,"/inline");
    }

	return O_K;
}

INT16 CFunction::OnNonstopSet()
{
    dlp_set_nonstop_mode(TRUE);

	return O_K;
}

INT16 CFunction::OnStopSet()
{
    dlp_set_nonstop_mode(FALSE);

	return O_K;
}

//}}CGEN_OCCF


// Generated field change callback functions

//{{CGEN_FCCF
//}}CGEN_FCCF


// EOF
