SUBDIRS = 
dist_doc_DATA = README
ACLOCAL_AMFLAGS = -I m4

#---------------------------------------------

lib_LTLIBRARIES = libcrumbs.la
libcrumbs_la_SOURCES = impl/crumbs.c impl/keyboard.c impl/texture.c impl/font.c impl/audio.c impl/impl.h
libcrumbs_la_LDFLAGS = -version-info 1:0:0

AM_CPPFLAGS = -I$(top_srcdir)

includecrumbsdir = $(pkgincludedir)
includecrumbs_HEADERS = $(top_srcdir)/crumbs.h

