SUBDIRS = 
dist_doc_DATA = README
ACLOCAL_AMFLAGS = -I m4

#---------------------------------------------

lib_LTLIBRARIES = libcrumbs.la
libcrumbs_la_SOURCES = crumbs.c keyboard.c texture.c font.c audio.c impl.h
libcrumbs_la_LDFLAGS = -version-info 1:0:0

AM_CPPFLAGS = -I..

includecrumbsdir = $(pkgincludedir)
includecrumbs_HEADERS = ../crumbs.h

