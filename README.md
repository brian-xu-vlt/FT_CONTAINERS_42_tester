<p align="center">
  <a href="" rel="noopener">
 <img width=200px src="./assets/head.jpg" alt="Project logo"></a>
</p>

<h3 align="center">FT_CONTAINERS: tester</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![License](https://img.shields.io/badge/license-GPL-lightgrey)](/LICENSE)

</div>

---

<p align="center"> This project is a tester I developed will completing the FT_CONTAINERS project.
    <br> 
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)

## 🧐 About <a name = "about"></a>

<p align="center">
  <a href="" rel="noopener">
 <img width=800px src="./assets/preview.gif" alt="Project logo"></a>
</p>

This tester is intended to be used on FT_CONTAINERS, a École 42's project in which students have to reimplement some of the STL containers, based on c++98. This tester is designed to work for the projects as per May 2021's version. Meaning it will not test the new revision and bonuses.
It performs tests to verify the student implementation based on STL behaviour and output comparison.

Tests are performed on: 

- Vector
- Stack
- Map
- List
- Set
- Deque
- Queue

Note: this test assumes you have implemented your own ft::pair. If you have not, uncomment the last block of comment in `./include/your_headers.hpp`

## 🏁 Getting Started <a name = "getting_started"></a>

- First place your projects headers in directory : `./includes/your_headers_files`
- Then update the file `./includes/your_headers.hpp` to include your files.
- `make f` will precompile your headers and check their std98 compiliance, then compile the tester and run every tests.
- Note: Tester will stop at the first failure (except tests performed on max_size of some containers as their result mey vary with OS, and may reflect some personnal decision on implementation which may be valid and yield to variation with STL).
- `make <container name>` will perform tests on a specific container.
