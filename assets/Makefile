app_windows:
	cd build/cmake && cmake ../.. && msbuild HELLO.sln /p:Configuration=Release

app_linux:
	cd build/cmake && cmake ../.. && make VERBOSE=1

make_dir:
	mkdir build && cd build && mkdir cmake