# Monte Carlo Metropolis Nanoparticles!

This project consists in a simple yet powerful implementation of the Monte Carlo Metropolis algorithm to study the magnetization reversal of nanoparticles.
This program was developed during the post-doctoral of Vagner Zeizer Carvalho Paes at Universidade Federal do Parana, Curitiba, Brazil during 2018-2019.
Firstly, it was designed as a first step to study the hyperthermic properties of nanoparticles, including the effects of interaction such as the dipole-dipole and exchange.

## Introduction 

This program written in C++ is an implementation of the Metropolis Monte Carlo to calculate the magnetization reversal of nanoparticles as a function of applied magnetic field and temperature.
This was motivated by the study of hyperthemic properties of nanoparticles in my first post-doctoral stage at Universidade Federal do Parana, Curitiba, Brazil during 2018-2019.
There are several material parameters that can be tuned in order to obtain a different simulation.
The common parameters are:

1. Saturation magnetization, M<sub>S</sub>;
2. Magnetocrystalline anisotropy constants, K<sub>1</sub> and K<sub>2</sub>, including in-plane anisotropies and perpendicular anisotropies;
3. Rotatable anisotropy, K<sub>rot</sub>;
4. Field-dependent anisotropy, K<sub>F</sub>.


There are magnetic interactions included, such as the Dipole-Dipole, Exchange, and Dzyaloshiinsi-Moriya, whose intensities are given by the following parameters:

1. beta -> dipole-dipole strength;
2. jota -> exchange strength;
3. m -> dzyaloshinskii moriya strength.

Nanoparticle arrangement:

1. "square" -> a planar array of nanoparticles;
2. "nanomembrane" -> forms a nanomembrane;
3. "half_nanomembrane" -> forms a half nanomembrane.


## Content of the files: 

1. main_metroplis_2D.cpp: main code of the metropolis implementation;
2. init_vecloop.cpp: initialization of the magnetization vector;
3. after_vecs.cpp: function to change the position of a single spin modification;
4. angles_vecs.cpp: it finds the spherical angles between vectors -> it is used to calculate interactions;
5. creating_pos.cpp: it creates the geometric structure previously chosen;
6. energy_array.cpp: it implements boundary conditions for the geometric structure previously chosen;
7. formula_dipolar.cpp: formula for the dipole-dipole interaction;
8. formula_exchange.cpp: formula for the exchange interaction;
9. formula_moriya.cpp: formula for the dzyaloshiinski-moriya interaction;
10. rand_vec.cpp: it generates the new configuration within a solid cone;
11. hystMCM_cpp.dat: output of the calculation. 







## MIT License

Copyright (c) 2019 Vagner Zeizer C. Paes

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.






