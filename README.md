# particles

Implements particle systems using openGL

TODO: Add a representative image for your project here

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake -G "Visual Studio 16 2019" ..
particles/build $ start CS312-Particles.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
particles/build $ ../bin/Debug/billboard
particles/build $ ../bin/Debug/confetti
particles/build $ ../bin/Debug/demo
```

*macOS*

Open terminal to the directory containing this repository.

```
particles $ mkdir build
particles $ cd build
particles/build $ cmake ..
particles/build $ make
```

To run each program from build, you would type

```
particles/build $ ../bin/billboard
particles/build $ ../bin/confetti
particles/build $ ../bin/demo
```

## Results

## Required materials

Confetti particle system:

https://user-images.githubusercontent.com/48161551/116501454-cdfa2300-a87e-11eb-8207-f4f085ae2471.mov

## Unique demo

Smoke plume particle system:

https://user-images.githubusercontent.com/48161551/116501452-cd618c80-a87e-11eb-8566-1252ddfc8790.mov
