# POO_CS
Programmation Orienté Object pour le Calcul Scientifique

Projet de simulation équation de transport : résolution d'équation d'advection linéaire
# Dependencies

You will need gnuplot for plotting datas

### With apt :
```sh 
$ sudo apt install gnuplot
```

# Build 

## Build in release mode

```sh 
$ mkdir release && cmake -DCMAKE_BUILD_TYPE=Release ..

$ cmake --build
```

## Build in debug/standard mode

```sh 
$ mkdir build && cmake -DCMAKE_BUILD_TYPE=Debug ..

$ cmake --build
```

# Usage

```sh 
# Make sure the project has been built properly and you are in build dir
$ ./Main 
    or
$ ./Main [t_Initial] [t_Final] [pas de temps] [x_min] [x_max] [pas d espace] [maillage]

# To visualize results you need to be in main directory
$ cd ..

$ gnuplot plot.p
```

# For tests 

```sh
# Make sure the project has been built properly and you are in build dir
$ ctest
```

# Author

[Adrien HENROT](https://github.com/Nxirda)
