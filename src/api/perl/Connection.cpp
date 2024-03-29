/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of Connection.xs. Do not edit this file, edit Connection.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Connection.xs"
/* Copyright (c) 1999-2018 David Muse
   See the file COPYING for more information */

#include <config.h>

// SCO OSR6 requires this
#ifdef SQLRELAY_HAVE_SYS_VNODE_H
	#include <sys/vnode.h>
#endif

#include "../c++/sqlrelay/sqlrclient.h"
#include <EXTERN.h>
#define explicit

#if defined(WIN32)

	// some versions of active perl erroneously try to
	// use __inline__ which isn't valid for MSVC
	#ifdef _MSC_VER
		#define __inline__ __inline
	#endif

	// msvc < 2013 (version 18.00) don't have stdbool.h
	// active perl 5.20 and up require either stdbool.h or this workaround
	#if _MSC_VER<1800
		#include <patchlevel.h>
		#if PERL_REVISION>5 || (PERL_REVISION==5 && PERL_VERSION>=20)
			#define PERL_BOOL_AS_CHAR
			#define __inline__ inline
		#endif
	#endif
#endif

#ifndef _SCO_DS
extern "C" {
#endif
	#include <perl.h>
#ifndef _SCO_DS
}
#endif

#include <XSUB.h>
#ifdef CLASS
	#undef CLASS
#endif

#ifdef THIS
	#undef THIS
#endif

#ifdef PERL500
	#ifndef SvUV
        	#define SvUV SvIV
	#endif
	#ifndef sv_setuv
        	#define sv_setuv sv_setiv
	#endif
	#ifndef PERLREALLYOLD
        	#undef sv_setpv
        	#define sv_setpv(a,b) Perl_sv_setpv(a,(char *)b)
        	#undef sv_setpvn
        	#define sv_setpvn(a,b,c) Perl_sv_setpvn(a,(char *)b,c)
	#else
		#define CLASS "SQLRelay::Connection"
	#endif
#endif

#ifdef WIN32
	#undef XS_EXTERNAL
	#undef XS_INTERNAL
	#define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
	#define XS_INTERNAL(name) STATIC XSPROTO(name)
#endif

/* xsubpp outputs __attribute__((noreturn)) this isn't
 * understood by gcc < 3.0. */
#ifdef __GNUC__
	#if __GNUC__ < 3
		#define __attribute__(x)
	#endif
#endif

typedef class sqlrconnection sqlrconnection;

#line 95 "Connection.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 237 "Connection.c"

XS_EUPXS(XS_SQLRelay__Connection_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_new)
{
    dVAR; dXSARGS;
    if (items != 8)
       croak_xs_usage(cv,  "CLASS, server, port, socket, user, password, retrytime, tries");
    {
	const char *	server = (const char *)SvPV_nolen(ST(1))
;
	uint16_t	port;
	const char *	socket = (const char *)SvPV_nolen(ST(3))
;
	const char *	user = (const char *)SvPV_nolen(ST(4))
;
	const char *	password = (const char *)SvPV_nolen(ST(5))
;
	int32_t	retrytime;
	int32_t	tries;
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	sqlrconnection *	RETVAL;

	port=(uint16_t)SvUV(ST(2))
;

	retrytime=(int32_t)SvIV(ST(6))
;

	tries=(int32_t)SvIV(ST(7))
;
#line 97 "Connection.xs"
		RETVAL=new sqlrconnection(server,port,socket,
					user,password,retrytime,tries,true);
#line 272 "Connection.c"
	ST(0) = sv_newmortal();
	sv_setref_pv( ST(0), CLASS, (void*)RETVAL );
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::DESTROY() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	delete THIS;
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_setConnectTimeout); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_setConnectTimeout)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "THIS, timeoutsec, timeoutusec");
    {
	int32_t	timeoutsec;
	int32_t	timeoutusec;
	sqlrconnection *	THIS;

	timeoutsec=(int32_t)SvIV(ST(1))
;

	timeoutusec=(int32_t)SvIV(ST(2))
;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::setConnectTimeout() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->setConnectTimeout(timeoutsec, timeoutusec);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_setAuthenticationTimeout); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_setAuthenticationTimeout)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "THIS, timeoutsec, timeoutusec");
    {
	int32_t	timeoutsec;
	int32_t	timeoutusec;
	sqlrconnection *	THIS;

	timeoutsec=(int32_t)SvIV(ST(1))
;

	timeoutusec=(int32_t)SvIV(ST(2))
;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::setAuthenticationTimeout() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->setAuthenticationTimeout(timeoutsec, timeoutusec);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_setResponseTimeout); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_setResponseTimeout)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "THIS, timeoutsec, timeoutusec");
    {
	int32_t	timeoutsec;
	int32_t	timeoutusec;
	sqlrconnection *	THIS;

	timeoutsec=(int32_t)SvIV(ST(1))
;

	timeoutusec=(int32_t)SvIV(ST(2))
;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::setResponseTimeout() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->setResponseTimeout(timeoutsec, timeoutusec);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_setBindVariableDelimiters); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_setBindVariableDelimiters)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, delimiters");
    {
	const char *	delimiters = (const char *)SvPV_nolen(ST(1))
;
	sqlrconnection *	THIS;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::setBindVariableDelimiters() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->setBindVariableDelimiters(delimiters);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_getBindVariableDelimiterQuestionMarkSupported); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_getBindVariableDelimiterQuestionMarkSupported)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::getBindVariableDelimiterQuestionMarkSupported() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getBindVariableDelimiterQuestionMarkSupported();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_getBindVariableDelimiterColonSupported); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_getBindVariableDelimiterColonSupported)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::getBindVariableDelimiterColonSupported() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getBindVariableDelimiterColonSupported();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_getBindVariableDelimiterAtSignSupported); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_getBindVariableDelimiterAtSignSupported)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::getBindVariableDelimiterAtSignSupported() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getBindVariableDelimiterAtSignSupported();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_getBindVariableDelimiterDollarSignSupported); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_getBindVariableDelimiterDollarSignSupported)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::getBindVariableDelimiterDollarSignSupported() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getBindVariableDelimiterDollarSignSupported();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_enableKerberos); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_enableKerberos)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "THIS, service, mech, flags");
    {
	const char *	service = (const char *)SvPV_nolen(ST(1))
;
	const char *	mech = (const char *)SvPV_nolen(ST(2))
;
	const char *	flags = (const char *)SvPV_nolen(ST(3))
;
	sqlrconnection *	THIS;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::enableKerberos() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->enableKerberos(service, mech, flags);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_enableTls); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_enableTls)
{
    dVAR; dXSARGS;
    if (items != 8)
       croak_xs_usage(cv,  "THIS, version, cert, password, ciphers, validate, ca, depth");
    {
	const char *	version = (const char *)SvPV_nolen(ST(1))
;
	const char *	cert = (const char *)SvPV_nolen(ST(2))
;
	const char *	password = (const char *)SvPV_nolen(ST(3))
;
	const char *	ciphers = (const char *)SvPV_nolen(ST(4))
;
	const char *	validate = (const char *)SvPV_nolen(ST(5))
;
	const char *	ca = (const char *)SvPV_nolen(ST(6))
;
	uint16_t	depth;
	sqlrconnection *	THIS;

	depth=(uint16_t)SvUV(ST(7))
;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::enableTls() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->enableTls(version, cert, password, ciphers, validate, ca, depth);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_disableEncryption); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_disableEncryption)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::disableEncryption() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->disableEncryption();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_endSession); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_endSession)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::endSession() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->endSession();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_suspendSession); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_suspendSession)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::suspendSession() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->suspendSession();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_getConnectionPort); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_getConnectionPort)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	int16_t	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::getConnectionPort() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getConnectionPort();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_getConnectionSocket); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_getConnectionSocket)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::getConnectionSocket() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getConnectionSocket();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_resumeSession); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_resumeSession)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "THIS, port, socket");
    {
	int16_t	port;
	const char *	socket = (const char *)SvPV_nolen(ST(2))
;
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	port=(int16_t)SvIV(ST(1))
;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::resumeSession() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->resumeSession(port, socket);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_ping); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_ping)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::ping() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->ping();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_selectDatabase); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_selectDatabase)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, database");
    {
	const char *	database = (const char *)SvPV_nolen(ST(1))
;
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::selectDatabase() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->selectDatabase(database);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_getCurrentDatabase); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_getCurrentDatabase)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::getCurrentDatabase() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getCurrentDatabase();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_getLastInsertId); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_getLastInsertId)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	uint64_t	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::getLastInsertId() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getLastInsertId();
	XSprePUSH; PUSHu((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_autoCommitOn); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_autoCommitOn)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::autoCommitOn() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->autoCommitOn();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_autoCommitOff); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_autoCommitOff)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::autoCommitOff() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->autoCommitOff();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_begin); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_begin)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::begin() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->begin();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_commit); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_commit)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::commit() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->commit();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_rollback); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_rollback)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::rollback() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->rollback();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_identify); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_identify)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::identify() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->identify();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_dbVersion); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_dbVersion)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::dbVersion() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->dbVersion();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_dbHostName); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_dbHostName)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::dbHostName() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->dbHostName();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_dbIpAddress); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_dbIpAddress)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::dbIpAddress() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->dbIpAddress();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_serverVersion); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_serverVersion)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::serverVersion() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->serverVersion();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_clientVersion); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_clientVersion)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::clientVersion() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->clientVersion();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_bindFormat); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_bindFormat)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::bindFormat() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->bindFormat();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_errorMessage); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_errorMessage)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::errorMessage() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->errorMessage();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_errorNumber); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_errorNumber)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	int64_t	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::errorNumber() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->errorNumber();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_debugOn); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_debugOn)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::debugOn() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->debugOn();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_debugOff); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_debugOff)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::debugOff() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->debugOff();
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_getDebug); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_getDebug)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	bool	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::getDebug() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getDebug();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_setDebugFile); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_setDebugFile)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, filename");
    {
	const char *	filename = (const char *)SvPV_nolen(ST(1))
;
	sqlrconnection *	THIS;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::setDebugFile() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->setDebugFile(filename);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_setClientInfo); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_setClientInfo)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, clientinfo");
    {
	const char *	clientinfo = (const char *)SvPV_nolen(ST(1))
;
	sqlrconnection *	THIS;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::setClientInfo() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	THIS->setClientInfo(clientinfo);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SQLRelay__Connection_getClientInfo); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_getClientInfo)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	sqlrconnection *	THIS;
	const char *	RETVAL;
	dXSTARG;

	if( sv_isobject(ST(0)) && (SvTYPE(SvRV(ST(0))) == SVt_PVMG) )
		THIS = (sqlrconnection *)SvIV((SV*)SvRV( ST(0) ));
	else{
		warn( "SQLRelay::Connection::getClientInfo() -- THIS is not a blessed SV reference" );
		XSRETURN_UNDEF;
	}
;

	RETVAL = THIS->getClientInfo();
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_isYes); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_isYes)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "CLASS, str");
    {
	const char *	str = (const char *)SvPV_nolen(ST(1))
;
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	bool	RETVAL;
	dXSTARG;

	RETVAL = sqlrconnection::isYes(str);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SQLRelay__Connection_isNo); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SQLRelay__Connection_isNo)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "CLASS, str");
    {
	const char *	str = (const char *)SvPV_nolen(ST(1))
;
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	bool	RETVAL;
	dXSTARG;

	RETVAL = sqlrconnection::isNo(str);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_SQLRelay__Connection); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_SQLRelay__Connection)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        newXS("SQLRelay::Connection::new", XS_SQLRelay__Connection_new, file);
        newXS("SQLRelay::Connection::DESTROY", XS_SQLRelay__Connection_DESTROY, file);
        newXS("SQLRelay::Connection::setConnectTimeout", XS_SQLRelay__Connection_setConnectTimeout, file);
        newXS("SQLRelay::Connection::setAuthenticationTimeout", XS_SQLRelay__Connection_setAuthenticationTimeout, file);
        newXS("SQLRelay::Connection::setResponseTimeout", XS_SQLRelay__Connection_setResponseTimeout, file);
        newXS("SQLRelay::Connection::setBindVariableDelimiters", XS_SQLRelay__Connection_setBindVariableDelimiters, file);
        newXS("SQLRelay::Connection::getBindVariableDelimiterQuestionMarkSupported", XS_SQLRelay__Connection_getBindVariableDelimiterQuestionMarkSupported, file);
        newXS("SQLRelay::Connection::getBindVariableDelimiterColonSupported", XS_SQLRelay__Connection_getBindVariableDelimiterColonSupported, file);
        newXS("SQLRelay::Connection::getBindVariableDelimiterAtSignSupported", XS_SQLRelay__Connection_getBindVariableDelimiterAtSignSupported, file);
        newXS("SQLRelay::Connection::getBindVariableDelimiterDollarSignSupported", XS_SQLRelay__Connection_getBindVariableDelimiterDollarSignSupported, file);
        newXS("SQLRelay::Connection::enableKerberos", XS_SQLRelay__Connection_enableKerberos, file);
        newXS("SQLRelay::Connection::enableTls", XS_SQLRelay__Connection_enableTls, file);
        newXS("SQLRelay::Connection::disableEncryption", XS_SQLRelay__Connection_disableEncryption, file);
        newXS("SQLRelay::Connection::endSession", XS_SQLRelay__Connection_endSession, file);
        newXS("SQLRelay::Connection::suspendSession", XS_SQLRelay__Connection_suspendSession, file);
        newXS("SQLRelay::Connection::getConnectionPort", XS_SQLRelay__Connection_getConnectionPort, file);
        newXS("SQLRelay::Connection::getConnectionSocket", XS_SQLRelay__Connection_getConnectionSocket, file);
        newXS("SQLRelay::Connection::resumeSession", XS_SQLRelay__Connection_resumeSession, file);
        newXS("SQLRelay::Connection::ping", XS_SQLRelay__Connection_ping, file);
        newXS("SQLRelay::Connection::selectDatabase", XS_SQLRelay__Connection_selectDatabase, file);
        newXS("SQLRelay::Connection::getCurrentDatabase", XS_SQLRelay__Connection_getCurrentDatabase, file);
        newXS("SQLRelay::Connection::getLastInsertId", XS_SQLRelay__Connection_getLastInsertId, file);
        newXS("SQLRelay::Connection::autoCommitOn", XS_SQLRelay__Connection_autoCommitOn, file);
        newXS("SQLRelay::Connection::autoCommitOff", XS_SQLRelay__Connection_autoCommitOff, file);
        newXS("SQLRelay::Connection::begin", XS_SQLRelay__Connection_begin, file);
        newXS("SQLRelay::Connection::commit", XS_SQLRelay__Connection_commit, file);
        newXS("SQLRelay::Connection::rollback", XS_SQLRelay__Connection_rollback, file);
        newXS("SQLRelay::Connection::identify", XS_SQLRelay__Connection_identify, file);
        newXS("SQLRelay::Connection::dbVersion", XS_SQLRelay__Connection_dbVersion, file);
        newXS("SQLRelay::Connection::dbHostName", XS_SQLRelay__Connection_dbHostName, file);
        newXS("SQLRelay::Connection::dbIpAddress", XS_SQLRelay__Connection_dbIpAddress, file);
        newXS("SQLRelay::Connection::serverVersion", XS_SQLRelay__Connection_serverVersion, file);
        newXS("SQLRelay::Connection::clientVersion", XS_SQLRelay__Connection_clientVersion, file);
        newXS("SQLRelay::Connection::bindFormat", XS_SQLRelay__Connection_bindFormat, file);
        newXS("SQLRelay::Connection::errorMessage", XS_SQLRelay__Connection_errorMessage, file);
        newXS("SQLRelay::Connection::errorNumber", XS_SQLRelay__Connection_errorNumber, file);
        newXS("SQLRelay::Connection::debugOn", XS_SQLRelay__Connection_debugOn, file);
        newXS("SQLRelay::Connection::debugOff", XS_SQLRelay__Connection_debugOff, file);
        newXS("SQLRelay::Connection::getDebug", XS_SQLRelay__Connection_getDebug, file);
        newXS("SQLRelay::Connection::setDebugFile", XS_SQLRelay__Connection_setDebugFile, file);
        newXS("SQLRelay::Connection::setClientInfo", XS_SQLRelay__Connection_setClientInfo, file);
        newXS("SQLRelay::Connection::getClientInfo", XS_SQLRelay__Connection_getClientInfo, file);
        newXS("SQLRelay::Connection::isYes", XS_SQLRelay__Connection_isYes, file);
        newXS("SQLRelay::Connection::isNo", XS_SQLRelay__Connection_isNo, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

