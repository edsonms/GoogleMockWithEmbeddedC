<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="https://i.imgur.com/6wj0hh6.jpg" alt="Project logo"></a>
</p>

<h3 align="center">Project Title</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![GitHub Issues](https://img.shields.io/github/issues/kylelobo/The-Documentation-Compendium.svg)](https://github.com/kylelobo/The-Documentation-Compendium/issues)
[![GitHub Pull Requests](https://img.shields.io/github/issues-pr/kylelobo/The-Documentation-Compendium.svg)](https://github.com/kylelobo/The-Documentation-Compendium/pulls)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)

</div>

---

<p align="center"> Few lines describing your project.
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Deployment](#deployment)
- [Usage](#usage)
- [Built Using](#built_using)
- [TODO](../TODO.md)
- [Contributing](../CONTRIBUTING.md)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

The aim of this project is to give an example of how Google Mock and Google test can be used to mock pure Embedded C functions and test them using unit tests.

## 🏁 Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 

### Prerequisites

To be able to build and run this project on Windows, you will need to install git, MinGW (gcc), CMAKE and add them to the PATH. I also recommend installing and using VSCode to build and debug the project, with the extensions CMAKE and CMAKETools. After that just clone the project doing:
```
git clone https://github.com/edsonms/GoogleMockWithEmbeddedC.git
```
Then, inside the folder of the cloned project, run:
```
git submodule update --init
```

After that just open the project folder with VSCode and you are ready to build and run your tests.

## 🔧 Running the tests <a name = "tests"></a>

To run the tests, just run the compiled executable called GoogleMockWithEmbeddedC.exe, inside the folder test/build/test/. If you are using VSCode, you can run the test directly from there, if you have the MinGW (GCC) configured to be used as compiler, and the compiling target set to GoogleMockWithEmbeddedC

## 🎈 Usage <a name="usage"></a>

TBD

## 🚀 Deployment <a name = "deployment"></a>

TBD

## ⛏️ Built Using <a name = "built_using"></a>

- [CMake](https://cmake.org/) - CMake
- [MinGW](https://osdn.net/projects/mingw/) - MinGW (32bits)
- [VSCode](https://code.visualstudio.com/) - Visual Studio Code

## ✍️ Authors <a name = "authors"></a>

- [@edsonms](https://github.com/edsonms) - Idea & Initial work
  https://www.linkedin.com/in/edsonms/

## 🎉 Acknowledgements <a name = "acknowledgement"></a>

- References
https://google.github.io/googletest/gmock_for_dummies.html#Using%20Mocks%20in%20Tests
https://martinfowler.com/articles/mocksArentStubs.html#TheDifferenceBetweenMocksAndStubs
http://blog.wingman-sw.com/linker-substitution-in-c-limitations-and-workarounds