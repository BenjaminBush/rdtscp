from distutils.core import setup, Extension

rdtscp_module = Extension('rdtscp_module',
                           sources = ['rdtscp_module.c'])

setup(name = 'rdtscp_module',
      version = '1.0',
      description = 'C Extension for Python3 to call RDTSCP()',
      ext_modules = [rdtscp_module])
