# -*- mode:python -*-
import sys
import os
import SCons.Defaults
import SCons.Builder
OriginalShared = SCons.Defaults.SharedObjectEmitter
OriginalStatic = SCons.Defaults.StaticObjectEmitter

def DoLint(env, source):
    for s in source:
        print s
        env.Lint(s.srcnode().name + ".lint", s)

def SharedObjectEmitter(target, source, env):
    DoLint(env, source)
    return OriginalShared(target, source, env)

def StaticObjectEmitter(target, source, env):
    DoLint(env, source)
    return OriginalStatic(target, source, env)

SCons.Defaults.SharedObjectEmitter = SharedObjectEmitter
SCons.Defaults.StaticObjectEmitter = StaticObjectEmitter

# actual build
build_varible = COMMAND_LINE_TARGETS

## Set Include and Lib path
cpp_path = ['#/apue', '#/_external/']
lib_path = ['.', '#/_external/apue.3e/lib']
env = Environment(ENV = {'PATH' : os.environ['PATH']},
                  tools = ['default', 'gcc'],
                  CPPPATH = cpp_path,
                  LIBPATH = lib_path)

## Set Debug Args
debug = ARGUMENTS.get('debug', 0)
if int(debug):
    env.Append(CCFLAGS = '-g')
    env['BUILD_DIR'] = 'build/debug'
else:
    env['BUILD_DIR'] = 'build/release'
cpp_path.append(env['BUILD_DIR'])


## Set Root Dir
env['BUILD_ROOT'] = Dir('#').abspath

## Define Linter
env["LINT"] = "$BUILD_ROOT/scripts/cpplint.py --linelength=120 --extensions=hpp,cpp,h,c" \
              "--verbose=5 --root=$BUILD_DIR" \

linter = SCons.Builder.Builder(
    action=['$LINT $SOURCE', 'date > $TARGET'],
    suffix='.lint',
    src_suffix=['.cpp', '.h'])
env.Append(BUILDERS={'Lint': linter})

## Do Compile
builds = env.SConscript(
    dirs='.',
    exports='env',
    variant_dir=env['BUILD_DIR'],
    duplicate=1)
