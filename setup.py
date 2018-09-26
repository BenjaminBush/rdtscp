import setuptools

rdtscp_module = setuptools.Extension('rdtscp_module',
                           sources = ['rdtscp_module.c'])

setuptools.setup(name = 'rdtscp_module',
      version = '1.0',
      description = 'C Extension for Python3 to call RDTSCP()',
      ext_modules = [rdtscp_module],
      author = "Benjamin Bush",
      url= "https://github.com/BenjaminBush/rdtscp")
