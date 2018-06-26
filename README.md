# pybind11 example

This repo has a basic example of using pybind11 from CMake.

More details are available from [here](https://hopstorawpointers.blogspot.com/2018/06/using-c-code-from-python-with-pybind11.html)

Requirments:

  * CMake
  * pybind11 (v2.2 or higher)
  * gcc
  * python (and python-dev)

To build you can do

```
mkdir build
cd build
cmake ..
make 
```

To run the python example code, from the `build` directory run:

```
PYTHONPATH=. python3 ../bindings.py
```

or directly from CMake run

```
make test
```

## Run in Docker

For ease of use I have a docker container based on Ubuntu 18.04 with all requirements installed.

To run this container you can do 

```
docker run -it -v `pwd`:/data/code matrim/pybind-example /bin/bash
```

Then `cd /data/code` and build the example as per the instructions above.
