# -*- mode:python -*-
import sys
import os

Import('env')
env = env.Clone()

builds = env.SConscript(
    dirs='apue',
    exports='env',
    duplicate=1)

# print env.GetBuildPath('.')
