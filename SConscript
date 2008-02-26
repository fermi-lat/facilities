#$Id: SConscript,v 1.2 2008/02/22 01:30:26 golpa Exp $
Import('baseEnv')
Import('listFiles')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('facilitiesLib', depsOnly = 1)
facilitiesLib = libEnv.StaticLibrary('facilities', listFiles(['src/*.cxx']))

progEnv.Tool('facilitiesLib')
test_time = progEnv.Program('test_time', ['src/test/test_time.cxx'])
test_env = progEnv.Program('test_env', ['src/test/test_env.cxx'])
test_Util = progEnv.Program('test_Util', 'src/test/testUtil.cxx')

progEnv.Tool('registerObjects', package = 'facilities', libraries = [facilitiesLib], testApps = [test_time, test_env, test_Util], includes = listFiles(['facilities/*.h']))

