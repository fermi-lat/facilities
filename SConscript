# -*- python -*-
# $Id: SConscript,v 1.46 2010/09/14 17:38:13 jrb Exp $
# Authors: T.Burnett <tburnett@u.washington.edu>, Navid Golpayegani <golpa@slac.stanford.edu>
# Version: facilities-02-19-09
import os
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()
swigEnv = baseEnv.Clone()

# Write a config.h containing a list of all the packages in the current build
configfile = open(os.path.join(str(Dir('.').srcnode()),'src','config.h'), 'w')
configfile.write('/* Autogenerated by scons; do not edit! */\n')
configfile.write('#define PACKAGES "')
for package in packages:
    configfile.write(os.path.basename(package))
    configfile.write(' ')
configfile.write('"\n')

if 'obfLdPath' in libEnv:
    configfile.write('#define REL_OBFLDPATH "')
    rpathNode = Dir(str(libEnv['GLASTEXTvalue'])).rel_path(Dir(str(libEnv['obfLdPath'])))
    configfile.write(str(rpathNode))
    configfile.write('"\n')
                 

configfile.close()

libEnv.Tool('addLinkDeps', package = 'facilities',
            toBuild = 'shared')
facilitiesLib = libEnv.SharedLibrary('facilities', listFiles(['src/*.cxx']))

swigEnv.Tool('facilitiesLib')
swigEnv.Tool('addLibrary', library=swigEnv['pythonLibs'])
lib_pyFacilities = swigEnv.SwigLibrary('_py_facilities', 'src/py_facilities.i')

progEnv.Tool('facilitiesLib')
test_time = progEnv.Program('test_time', ['src/test/test_time.cxx'])
test_env = progEnv.Program('test_env', ['src/test/test_env.cxx'])
test_Util = progEnv.Program('test_Util',[ 'src/test/testUtil.cxx'])

progEnv.Tool('registerTargets', package = 'facilities',
             libraryCxts = [[facilitiesLib, libEnv]],
             swigLibraryCxts = [[lib_pyFacilities, swigEnv]],
             testAppCxts = [[test_time, progEnv], [test_env,progEnv],
                            [test_Util,progEnv]],
             includes = listFiles(['facilities/*.h']),
             python = ['python/facilities.py', 'src/py_facilities.py'])



