<p align="center">
  <a href="https://profile.intra.42.fr/users/bvalette" rel="noopener">
 <img width=200px src="./assets/head.png" alt="Project logo"></a>
</p>


<h3 align="center">FT_CONTAINERS: tester</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-active-success.svg)]()
[![License](https://img.shields.io/badge/license-GPL-lightgrey)](/LICENSE)

</div>

---

<p align="center">
  <img width=100px src="./assets/cpp.png" alt="Project logo"></a>
  <h3>This project is a tester I developed while completing the FT_CONTAINERS project at École 42.</h3>
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Acknowledgement](#acknowledgement)

## 🧐 About <a name = "about"></a>

<p align="center">
  <a href="" rel="noopener">
 <img width=800px src="./assets/preview.gif" alt="Project logo"></a>
</p>

This tester is intended to be used on FT_CONTAINERS, a École 42's project in which students have to reimplement some of the STL containers, based on c++98. This tester is designed to work for the projects as per May 2021's version. Meaning it will not test the new revision and bonuses. But you will be able to test each container individually.
It performs tests to verify the student implementation based on STL behaviour and output comparison.

Tests are performed on: 

- Vector
- Stack
- Map
- List
- Set
- Deque
- Queue

Note: this test assumes you have implemented your own ft::pair (as you should).

## 🏁 Getting Started <a name = "getting_started"></a>

- First, place your projects headers in directory : `./includes/your_headers_files`
- Then update the file `./includes/your_headers.hpp` to include your files.

## 👩‍💻 Usage <a name = "usage"></a>

- `make f` will precompile your headers and check their std98 compliance, then compile the tester and run every tests.
- `make [container names]` will perform tests on a specific containers, one after the other according to the list passed.
- `make cpp98` will perform tests one your header to verify cpp98 compliance.

Note: Each tester will stop at the first failure (except tests performed on max_size of some containers as their result may vary with OS, and may reflect some personnal decision on implementation which may be valid and yield to variation with STL).

## ⚠️  Acknowledgement <a name = "acknowledgement"></a>

Please note this test is based on my own work, you should use it as a complement of your own testes. First because it might be wrong on some points, second because you will learn much more by doing your tester than doing the project itself: you will learn how to use the STL's version, its limitations, its power etc. ... 

