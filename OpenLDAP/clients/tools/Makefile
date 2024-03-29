# $OpenLDAP$
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2011 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
##---------------------------------------------------------------------------
#
# Top-level Makefile template
#

PACKAGE= OpenLDAP
VERSION= 2.4.28
RELEASEDATE= 2011/11/24


SHELL = /bin/sh

top_builddir = ../..

srcdir = .
top_srcdir = ../..

prefix = /usr/local
exec_prefix = ${prefix}
ldap_subdir = /openldap

bindir = ${exec_prefix}/bin
datadir = ${prefix}/share$(ldap_subdir)
includedir = ${prefix}/include
infodir = ${prefix}/share/info
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localstatedir = ${prefix}/var
mandir = ${prefix}/share/man
moduledir = ${exec_prefix}/libexec$(ldap_subdir)
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
sysconfdir = ${prefix}/etc$(ldap_subdir)
schemadir = $(sysconfdir)/schema

PLAT = UNIX
EXEEXT = 
OBJEXT = o

BUILD_LIBS_DYNAMIC = static

BUILD_SLAPD = no

SHTOOL = $(top_srcdir)/build/shtool

INSTALL = $(SHTOOL) install -c
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL) -m 644
INSTALL_SCRIPT = $(INSTALL)

STRIP = -s

LINT = lint
5LINT = 5lint

MKDEP = $(top_srcdir)/build/mkdep $(MKDEPFLAG) \
	-d "$(srcdir)" -c "$(MKDEP_CC)" -m "$(MKDEP_CFLAGS)"
MKDEP_CC	= cc
MKDEP_CFLAGS = -M

MKVERSION = $(top_srcdir)/build/mkversion -v "$(VERSION)"

LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIBRELEASE = 2.4
LIBVERSION = 10:1:8
LTVERSION = -release $(LIBRELEASE) -version-info $(LIBVERSION)

# libtool --only flag for libraries: platform specific
NT_LTONLY_LIB = # --only-$(BUILD_LIBS_DYNAMIC)
LTONLY_LIB = $(UNIX_LTONLY_LIB)

# libtool --only flag for modules: depends on linkage of module
# The BUILD_MOD macro is defined in each backend Makefile.in file
LTONLY_yes = --tag=disable-shared
LTONLY_mod = --tag=disable-static
LTONLY_MOD = $(LTONLY_$(BUILD_MOD))

# platform-specific libtool flags
NT_LTFLAGS_LIB = -no-undefined -avoid-version -rpath $(libdir)
NT_LTFLAGS_MOD = -no-undefined -avoid-version -rpath $(moduledir)
UNIX_LTFLAGS_LIB = $(LTVERSION) -rpath $(libdir)
UNIX_LTFLAGS_MOD = $(LTVERSION) -rpath $(moduledir)

# libtool flags
LTFLAGS     = $(UNIX_LTFLAGS)
LTFLAGS_LIB = $(UNIX_LTFLAGS_LIB)
LTFLAGS_MOD = $(UNIX_LTFLAGS_MOD)

# LIB_DEFS defined in liblber and libldap Makefile.in files.
# MOD_DEFS defined in backend Makefile.in files.

# platform-specific LINK_LIBS defined in various Makefile.in files.
# LINK_LIBS referenced in library and module link commands.
LINK_LIBS = $(MOD_LIBS) $(UNIX_LINK_LIBS)

LTSTATIC = -static

LTLINK   = $(LIBTOOL) --mode=link \
	$(CC) $(LTSTATIC) $(LT_CFLAGS) $(LDFLAGS) $(LTFLAGS)

LTCOMPILE_LIB = $(LIBTOOL) $(LTONLY_LIB) --mode=compile \
	$(CC) $(LT_CFLAGS) $(LT_CPPFLAGS) $(LIB_DEFS) -c

LTLINK_LIB = $(LIBTOOL) $(LTONLY_LIB) --mode=link \
	$(CC) $(LT_CFLAGS) $(LDFLAGS) $(LTFLAGS_LIB)

LTCOMPILE_MOD = $(LIBTOOL) $(LTONLY_MOD) --mode=compile \
	$(CC) $(LT_CFLAGS) $(LT_CPPFLAGS) $(MOD_DEFS) -c

LTLINK_MOD = $(LIBTOOL) $(LTONLY_MOD) --mode=link \
	$(CC) $(LT_CFLAGS) $(LDFLAGS) $(LTFLAGS_MOD)

LTINSTALL = $(LIBTOOL) --mode=install $(INSTALL) 
LTFINISH = $(LIBTOOL) --mode=finish

# Misc UNIX commands used in build environment
AR = ar
BASENAME = basename
CAT = cat
CHMOD = chmod
DATE = date
ECHO = $(SHTOOL) echo
HOSTNAME = $(SHTOOL) echo -e "%h%d"
LN = $(SHTOOL) mkln
LN_H = $(LN)
LN_S = $(LN) -s
MAKEINFO = ${SHELL} /Volumes/SystemRoot/home/thomasa/Documents/CodingProjects/Repository/GitHub/darling/src/external/OpenLDAP/OpenLDAP/build/missing --run makeinfo
MKDIR = $(SHTOOL) mkdir -p
MV = $(SHTOOL) move
PWD = pwd
RANLIB = ranlib
RM = rm -f
SED = sed
SUBST = $(SHTOOL) subst

# For manual pages
# MANCOMPRESS=@MANCOMPRESS@
# MANCOMPRESSSUFFIX=@MANCOMPRESSSUFFIX@
MANCOMPRESS=$(CAT)
MANCOMPRESSSUFFIX=

SOELIM=soelim

INCLUDEDIR= $(top_srcdir)/include
LDAP_INCPATH= -I$(LDAP_INCDIR) -I$(INCLUDEDIR)
LDAP_LIBDIR= $(top_builddir)/libraries

LUTIL_LIBS = 
LTHREAD_LIBS =  

BDB_LIBS = 

LDAP_LIBLBER_LA = $(LDAP_LIBDIR)/liblber/liblber.la
LDAP_LIBLDAP_LA = $(LDAP_LIBDIR)/libldap/libldap.la
LDAP_LIBLDAP_R_LA = $(LDAP_LIBDIR)/libldap_r/libldap_r.la

LDAP_LIBREWRITE_A = $(LDAP_LIBDIR)/librewrite/librewrite.a
LDAP_LIBLUNICODE_A = $(LDAP_LIBDIR)/liblunicode/liblunicode.a
LDAP_LIBLUTIL_A = $(LDAP_LIBDIR)/liblutil/liblutil.a

LDAP_L = $(LDAP_LIBLUTIL_A) \
	$(LDAP_LIBLDAP_LA) $(LDAP_LIBLBER_LA)
SLAPD_L = $(LDAP_LIBLUNICODE_A) $(LDAP_LIBREWRITE_A) \
	$(LDAP_LIBLUTIL_A) $(LDAP_LIBLDAP_R_LA) $(LDAP_LIBLBER_LA)

WRAP_LIBS = 
# AutoConfig generated 
AC_CC	= cc
AC_CFLAGS = -g -O2
AC_DEFS =  # -DHAVE_CONFIG_H
AC_LDFLAGS = 
AC_LIBS = -lresolv 

KRB4_LIBS = 
KRB5_LIBS = 
KRB_LIBS =  
SASL_LIBS = -lsasl2
TLS_LIBS = 
AUTH_LIBS = 
SECURITY_LIBS = $(SASL_LIBS) $(KRB_LIBS) $(TLS_LIBS) $(AUTH_LIBS)
ICU_LIBS = 

MODULES_CPPFLAGS = 
MODULES_LDFLAGS = 
MODULES_LIBS = 
SLAPD_PERL_LDFLAGS = 

SLAPD_SQL_LDFLAGS = 
SLAPD_SQL_INCLUDES = 
SLAPD_SQL_LIBS = 

SLAPD_LIBS =       $(ICU_LIBS)

# Our Defaults
CC = $(AC_CC)
DEFS = $(LDAP_INCPATH) $(XINCPATH) $(XDEFS) $(AC_DEFS) $(DEFINES)
CFLAGS = $(AC_CFLAGS) $(DEFS)
LDFLAGS = $(LDAP_LIBPATH) $(AC_LDFLAGS) $(XLDFLAGS)
LIBS = $(XLIBS) $(XXLIBS) $(AC_LIBS) $(XXXLIBS)

LT_CFLAGS = $(AC_CFLAGS)
LT_CPPFLAGS = $(DEFS)

all:		all-common all-local FORCE
install:	install-common install-local FORCE
clean:		clean-common clean-local FORCE
veryclean:	veryclean-common veryclean-local FORCE
depend:		depend-common depend-local FORCE

# empty common rules
all-common:
install-common:
clean-common:
veryclean-common:	clean-common FORCE
depend-common:
lint-common:
lint5-common:

# empty local rules
all-local:
install-local:
clean-local:
veryclean-local:	clean-local FORCE
depend-local:
lint-local:
lint5-local:

veryclean: FORCE
	$(RM) Makefile
	$(RM) -r .libs

Makefile: Makefile.in $(top_srcdir)/build/top.mk

pathtest:
	$(SHTOOL) --version

# empty rule for forcing rules
FORCE:

##---------------------------------------------------------------------------

# Makefile for LDAP tools
# $OpenLDAP$
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2011 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
## <http://www.OpenLDAP.org/license.html>.

SRCS	= ldapsearch.c ldapmodify.c ldapdelete.c ldapmodrdn.c \
		ldappasswd.c ldapwhoami.c ldapcompare.c \
		ldapexop.c ldapurl.c common.c
OBJS	= ldapsearch.o ldapmodify.o ldapdelete.o ldapmodrdn.o \
		ldappasswd.o ldapwhoami.o ldapcompare.o \
		ldapexop.o ldapurl.o common.o

LDAP_INCDIR= ../../include       
LDAP_LIBDIR= ../../libraries

MKVOPTS = -s

XLIBS =  $(LDAP_L)
XXLIBS	= $(SECURITY_LIBS) $(LUTIL_LIBS)

XSRCS	= ldsversion.c ldmversion.c lddversion.c ldrversion.c \
	ldpversion.c ldwversion.c ldcversion.c ldeversion.c lduversion.c

PROGRAMS = ldapsearch ldapmodify ldapdelete ldapmodrdn \
	ldappasswd ldapwhoami ldapcompare ldapexop ldapurl


ldapsearch:	ldsversion.o
	$(LTLINK) -o $@ ldapsearch.o common.o ldsversion.o $(LDAP_LIBLDAP_R_LA) $(LIBS)

ldapmodify:	ldmversion.o
	$(LTLINK) -o $@ ldapmodify.o common.o ldmversion.o $(LIBS)

ldapdelete:	lddversion.o
	$(LTLINK) -o $@ ldapdelete.o common.o lddversion.o $(LIBS)

ldapmodrdn:	ldrversion.o
	$(LTLINK) -o $@ ldapmodrdn.o common.o ldrversion.o $(LIBS)

ldappasswd:	ldpversion.o
	$(LTLINK) -o $@ ldappasswd.o common.o ldpversion.o $(LIBS)

ldapwhoami:	ldwversion.o
	$(LTLINK) -o $@ ldapwhoami.o common.o ldwversion.o $(LIBS)

ldapcompare: ldcversion.o
	$(LTLINK) -o $@ ldapcompare.o common.o ldcversion.o $(LIBS)

ldapexop: ldeversion.o
	$(LTLINK) -o $@ ldapexop.o common.o ldeversion.o $(LIBS)

ldapurl: lduversion.o
	$(LTLINK) -o $@ ldapurl.o lduversion.o $(LIBS)

ldsversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapsearch > $@

ldsversion.o: ldapsearch.o common.o $(XLIBS)

ldmversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapmodify > $@

ldmversion.o: ldapmodify.o common.o $(XLIBS)

lddversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapdelete > $@

lddversion.o: ldapdelete.o common.o $(XLIBS)

ldpversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldappasswd > $@

ldpversion.o: ldappasswd.o common.o $(XLIBS)

ldrversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapmodrdn > $@

ldrversion.o: ldapmodrdn.o common.o $(XLIBS)

ldwversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapwhoami > $@

ldwversion.o: ldapwhoami.o common.o $(XLIBS)

ldcversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapcompare > $@

ldcversion.o: ldapcompare.o common.o $(XLIBS)

ldeversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapexop > $@

ldeversion.o: ldapexop.o common.o $(XLIBS)

lduversion.c: Makefile
	@-$(RM) $@
	$(MKVERSION) $(MKVOPTS) ldapurl > $@

lduversion.o: ldapurl.o $(XLIBS)

install-local:	FORCE
	-$(MKDIR) $(DESTDIR)$(bindir)
	@(								\
	    for prg in $(PROGRAMS); do					\
		$(LTINSTALL) $(INSTALLFLAGS) $(STRIP) -m 755 $$prg$(EXEEXT)	\
		    $(DESTDIR)$(bindir);				\
	    done							\
	)
	$(RM) $(DESTDIR)$(bindir)/ldapadd$(EXEEXT)
	$(LN_S) $(DESTDIR)$(bindir)/ldapmodify$(EXEEXT) $(DESTDIR)$(bindir)/ldapadd$(EXEEXT)

# $OpenLDAP$
## This work is part of OpenLDAP Software <http://www.openldap.org/>.
##
## Copyright 1998-2011 The OpenLDAP Foundation.
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted only as authorized by the OpenLDAP
## Public License.
##
## A copy of this license is available in the file LICENSE in the
## top-level directory of the distribution or, alternatively, at
## <http://www.OpenLDAP.org/license.html>.
##---------------------------------------------------------------------------
#
# Makefile Template for Programs
#

all-common: $(PROGRAMS) FORCE

clean-common: 	FORCE
	$(RM) $(PROGRAMS) $(XPROGRAMS) $(XSRCS) *.o *.lo a.out core *.core \
		    .libs/* *.exe

depend-common: FORCE
	$(MKDEP) $(DEFS) $(DEFINES) $(SRCS)

lint: FORCE
	$(LINT) $(DEFS) $(DEFINES) $(SRCS)

lint5: FORCE
	$(5LINT) $(DEFS) $(DEFINES) $(SRCS)

Makefile: $(top_srcdir)/build/rules.mk

