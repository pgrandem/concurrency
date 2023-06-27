### gwin.sh
### ************************************************************************ ###
### set gedit windows for "nptf: null project to fork"
### Pierre GRANDEMANGE
### 17/11/2022
### ************************************************************************ ###

### open a customised selection of code files
### ----------------------------------------------------------------------------
gedit --new-window 	$mainFolder/source/include/localFunctions.h 	\
										$repNamespaces/include/RDump.h 						\
										$repNamespaces/include/RMath.h 						&
sleep 0.3
gedit --new-window 	$mainFolder/source/src/localFunctions.cc 	\
										$repNamespaces/src/RDump.cc 						\
										$repNamespaces/src/RMath.cc 						&
sleep 0.3
gedit --new-window	$mainFolder/source/main.cc &
### ----------------------------------------------------------------------------





### open all local files (readme main.cc etc...)
#gedit --new-window 	$rep/readme.txt gwin.sh Makefile ../source/main.cc \
#						../source/src/*.cc  ../source/include/*.h &

### wait for 300ms
#sleep 0.3

### open rall rep Objects & Namespaces .h files
#gedit --new-window $repObjects/include/*.h	$repNamespaces/include/*.h &

### wait for 300ms
#sleep 0.3

### open all rep Objects & Namespaces .cc files
##gedit --new-window $repObjects/src/*.cc	$repNamespaces/src/*.cc &

### selection, by alphabetical order
#gedit --new-window 	$repNamespaces/src/RDump.cc 	\
#						$repObjects/src/RMath.cc 		&

### wait for 300ms
#sleep 0.3



