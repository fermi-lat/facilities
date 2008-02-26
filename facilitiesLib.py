#$Id: facilitiesLib.py,v 1.2 2008/02/22 01:30:26 golpa Exp $
def generate(env, **kw):
	if not kw.get('depsOnly',0):
		env.Tool('addLibrary', library = ['facilities'])

def exists(env):
	return 1;
