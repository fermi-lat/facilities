## Process this file with automake to produce Makefile.in
#
# $Id: Makefile.am,v 1.2 2000/01/17 00:58:50 pfkeb Exp $
#
# Author: Paul_Kunz@slac.stanford.edu
#

# The following set,  else would follow GNU conventions
AUTOMAKE_OPTIONS = foreign

noinst_LTLIBRARIES = libfacilities.la

libfacilities_la_SOURCES = \
	Clock.cxx          \
	ScheduledEvent.cxx \
	Scheduler.cxx

INCLUDES = -I$(top_srcdir)
