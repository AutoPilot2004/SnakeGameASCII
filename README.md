# How to build #

To build this project you will need [cmake](https://cmake.org/) (minimum version required is 3.27.0)

```shell

git clone https://github.com/AutoPilot2004/SnakeGameASCII.git
cd SnakeGameASCII
mkdir build
cd build

```

## Windows ##

For multi-config generators (e.g. `Visual Studio`):

- Debug:

	```shell

	cmake ..
	cmake --build . --config Debug

	```

- Release:

	```shell

	cmake ..
	cmake --build . --config Release

	```

For single-config generators (e.g. `Ninja`):

- Debug:

	```shell

	cmake -DCMAKE_BUILD_TYPE=Debug ..
	cmake --build .

	```

- Release:

	```shell

	cmake -DCMAKE_BUILD_TYPE=Release ..
	cmake --build .

	```