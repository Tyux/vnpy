"""
vn.py - By Traders, For Traders.

The vn.py project is an open-source quantitative trading framework
that is developed by traders, for traders.

The project is mainly written in Python and uses C++ for low-layer
and performance sensitive infrastructure.

Using the vn.py project, institutional investors and professional
traders, such as hedge funds, prop trading firms and investment banks,
can easily develop complex trading strategies with the Event Engine
Strategy Module, and automatically route their orders to the most
desired destinations, including equity, commodity, forex and many
other financial markets.
"""

import ast
import platform
import re

from setuptools import Extension, find_packages, setup


with open("vnpy/__init__.py", "rb") as f:
    version_line = re.search(
        r"__version__\s+=\s+(.*)", f.read().decode("utf-8")
    ).group(1)
    version = str(ast.literal_eval(version_line))

if platform.uname().system == "Windows":
    compiler_flags = ["/MP", "/std:c++17",  # standard
                      "/O2", "/Ob2", "/Oi", "/Ot", "/Oy", "/GL",  # Optimization
                      "/wd4819"  # 936 code page
                      ]
    extra_link_args = []
else:
    compiler_flags = ["-std=c++17",
                      "-Wno-delete-incomplete", "-Wno-sign-compare",
                      ]
    extra_link_args = ["-lstdc++"]

vnctpmd = Extension("vnpy.api.ctp.vnctpmd",
                    [
                        "vnpy/api/ctp/vnctp/vnctpmd/vnctpmd.cpp",
                    ],
                    include_dirs=["vnpy/api/ctp/include",
                                  "vnpy/api/ctp/vnctp", ],
                    define_macros=[],
                    undef_macros=[],
                    library_dirs=["vnpy/api/ctp/libs", "vnpy/api/ctp"],
                    libraries=["thostmduserapi", "thosttraderapi", ],
                    extra_compile_args=compiler_flags,
                    extra_link_args=extra_link_args,
                    depends=[],
                    runtime_library_dirs=["$ORIGIN"],
                    language="cpp",
                    )
vnctptd = Extension("vnpy.api.ctp.vnctptd",
                    [
                        "vnpy/api/ctp/vnctp/vnctptd/vnctptd.cpp",
                    ],
                    include_dirs=["vnpy/api/ctp/include",
                                  "vnpy/api/ctp/vnctp", ],
                    define_macros=[],
                    undef_macros=[],
                    library_dirs=["vnpy/api/ctp/libs", "vnpy/api/ctp"],
                    libraries=["thostmduserapi", "thosttraderapi", ],
                    extra_compile_args=compiler_flags,
                    extra_link_args=extra_link_args,
                    runtime_library_dirs=["$ORIGIN"],
                    depends=[],
                    language="cpp",
                    )
vnoes = Extension("vnpy.api.oes.vnoes",
                  [
                      "vnpy/api/oes/vnoes/generated_files/classes_1.cpp",
                      "vnpy/api/oes/vnoes/generated_files/classes_2.cpp",
                      "vnpy/api/oes/vnoes/generated_files/module.cpp",
                  ],
                  include_dirs=["vnpy/api/oes/include",
                                "vnpy/api/oes/vnoes", ],
                  define_macros=[("BRIGAND_NO_BOOST_SUPPORT", "1")],
                  undef_macros=[],
                  library_dirs=["vnpy/api/oes/libs"],
                  libraries=["oes_api"],
                  extra_compile_args=compiler_flags,
                  extra_link_args=extra_link_args,
                  depends=[],
                  language="cpp",
                  )

if platform.uname().system == "Windows":
    # use pre-built pyd for windows ( support python 3.7 only )
    ext_modules = []
else:
    ext_modules = [vnctptd, vnctpmd, vnoes]

pkgs = find_packages()

setup(
    name="vnpy",
    version=version,
    author="vn.py team",
    author_email="vn.py@foxmail.com",
    license="MIT",
    url="https://www.vnpy.com",
    description="A framework for developing quant trading systems.",
    long_description=__doc__,
    keywords='quant quantitative investment trading algotrading',
    include_package_data=True,
    packages=pkgs,
    package_data={"": [
        "*.json", "*.md", "*.ico", "*.ini",
        "*.dll", "*.so", "*.pyd"
    ]},
    classifiers=[
        "Development Status :: 5 - Production/Stable",
        "Operating System :: Microsoft :: Windows :: Windows 7",
        "Operating System :: Microsoft :: Windows :: Windows 8",
        "Operating System :: Microsoft :: Windows :: Windows 10",
        "Operating System :: Microsoft :: Windows :: Windows Server 2008",
        "Operating System :: Microsoft :: Windows :: Windows Server 2012",
        "Operating System :: Microsoft :: Windows :: Windows Server 2012",
        "Operating System :: POSIX :: Linux"
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.7",
        "Topic :: Office/Business :: Financial :: Investment",
        "Programming Language :: Python :: Implementation :: CPython",
        "License :: OSI Approved :: MIT License",
        "Natural Language :: Chinese (Simplified)",
        "Natural Language :: Chinese (Simplified)"
    ],
    install_requires=[],
    ext_modules=ext_modules
)
