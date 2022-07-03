
# CodeWars - Local

Minimal setup for running [codewars.com](codewars.com) C++ tests locally so that you can use your preferred editor.

Assumes you already have ***cmake*** and a suitable ***C++ compiler*** installed.

Steps

* Clone the repo
```
git clone git@github.com:dgkimpton/codewars-local.git
cd codewars-local
mkdir build
cd build
cmake ../
cd ..
```

* Copy your solution into `solution.h`
* Copy your tests into `tests.cpp`.
* Build (e.g. `cmake --build ./build` )

### Note
Notice that you can only run your own tests this way, to "attempt" the kata you'll need to copy the solution code back to the codewars website. 