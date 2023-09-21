# How to build #

To build this project you will need [cmake](https://cmake.org/) (minimum version required is 3.27.0)

After cloning this git repo and opening the folder:

```shell

mkdir build
cd build

```

## Windows ##

For multi-configuration build tools:

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

For other type of build tools:

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