# POO_CS
Programmation Orienté Object pour le Calcul Scientifique

Projet de simulation équation de transport : résolution d'équation d'advection linéaire

## Build in release mode

```sh 
mkdir release && cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build
```

## Build in debug/standard mode

```sh 
mkdir build && cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build
```

# Usage

```sh 
# Make sure the project has been built properly and you are in build dir
./Main 
    or
./Main [t_Initial] [t_Final] [pas de temps] [x_min] [x_max] [pas d espace] [maillage]
```

Upwind Scheme :
$$ u^{n+1}i = u^n_i-a\frac{\Delta t}{\Delta x} (u^n_i - u^n{i-1})$$

Lax-Wendroff Scheme :
$$ u^{n+1}i = u^n_i-a\frac{\Delta t}{2\Delta x} (u^n{i+1} - u^n_{i-1}) + a^2 \frac{\Delta t^2}{2\Delta x^2}(u^n_{i+1}-2u^n_i+u^n_{i-1})$$

# Author

[Adrien HENROT](https://github.com/Nxirda)
