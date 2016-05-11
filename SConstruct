# -*- mode:python -*-
import sys
import os

build_varible = COMMAND_LINE_TARGETS

cpp_path = ['.', '#/_external/']
lib_path = ['.', '#/_external/apue.3e/lib']

env = Environment(ENV = {'PATH' : os.environ['PATH']},
                  tools = ['default', 'gcc'],
                  CPPPATH = cpp_path,
                  LIBPATH = lib_path)

debug = ARGUMENTS.get('debug', 0)
if int(debug):
    env.Append(CCFLAGS = '-g')
    env['BUILD_DIR'] = 'build/debug'
else:
    env['BUILD_DIR'] = 'build/release'

dirs = ['']
builds = env.SConscript(
    dirs='.',
    exports='env',
    variant_dir=env['BUILD_DIR'],
    duplicate=1)
