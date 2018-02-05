test : package
	cd build && make test

generate : CMakeLists.txt
	mkdir -p build
	cd build && cmake ..

package : generate 
	mkdir -p build
	cd build && cmake ..
	cd build && make

clean :
	rm -rf build

