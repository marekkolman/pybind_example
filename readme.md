# Decription

This repo show an example of python bindings of C++ code using **pybind**.

The exple is largely based on `https://github.com/pybind/python_example`

The objective is to build a python package called `python_example` off existing C++ code.

# Install

- `pip install pybind11-global` -> this will allow to create _pybind_ bindings



# Project structure

The project structure contains:

- two python package setup files (`pyproject.toml` and `setup.py`)
- C++ project off which python package will be built (`./src`)

```
.
├── pyproject.toml
├── readme.md
├── setup.py
└── src
    ├── CMakeLists.txt
    ├── binder.cpp
    ├── functions.cpp
    ├── functions.h
    └── main.cpp
```



# python package installer files

To build/install a python package from C++ code two python package setup files need to be present:

- `pyproject.toml`
- `setup.py`



## File 1: `pyproject.toml`

This files allows python to _build_ package. If this file isn't present, it is not possible to _build_ wheelfile, but 
`pip install . ` will work



## File 2: `setup.py`

This file contains the actual instructions about how to build the extension.

Key part is

```python
ext_modules = [
    Pybind11Extension("python_example",
        ["src/binder.cpp", "src/functions.cpp"],
        # Example: passing in the version to the compiled code
        define_macros = [('VERSION_INFO', __version__)],
        ),
]
```

The extension name `python_example` must match that of the C++ `binder.cpp` code. 

Next, all `cpp` files that contain the source code (i.e. _not_ just the `binder.cpp`) need to be included, it this case the actual code is in `functions.cpp`. 

Note that header files are not listed, as the `Pybind11Extension` class doesn't accept header files.



# C++ files

The C++ files are in folder `./src`:

- `functions.cpp` and headers `functions.h`. The actual source code whose functions will be compiled into a python package. Note that these contain some _stl_ components such as `std::variant` or `std::optional`
- `main.cpp` this file contains some testing calls of the functions for dev purposes.  This file isn't necessary for compiling the package, it is used for C++ code debugging
-   `binder.cpp` this is where 'bindings' are actually defined. This imports headers `headers.h` and wraps them into  `PYBIND11_MODULE`.
- `CMakeLists.txt` this CMake file. It is not used by the python packaging but we use this file to have a C++ project where
  - C++ source code are not defined in the `main.cpp` file but in dedicated file(s) `functions.cpp` and `headers.h`,
  - allow the project involving the `pybind11` code compile
  - allow for debugging the project using `main.cpp` file




# Building/installing package

To _build_ a python package (i.e. generate wheel) off the C++ code, go in the project root folder and run

```bash
python -m build --wheel
```

To build and install a package off the C++ code, go in the project root folder and run

```bash
pip install .
```

