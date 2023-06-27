### repenvar.sh
### ************************************************************************ ###
### environement variables for a "rep" c++ type project.
### Pierre GRANDEMANGE
### 15/02/2023
### ************************************************************************ ###



### documentation
### ----------------------------------------------------------------------------
### export: https://stackoverflow.com/questions/1158091/defining-a-variable-with-or-without-export


### rep c++ framework shared objects, functions, data...
### "mainFolder" is the top folder. All other paths are referenced to this one.
### make sure that you have thiroot.sh/$ROOTSYS set
### ----------------------------------------------------------------------------
export mainFolder=$(pwd)
export data=$mainFolder/data

### cppshare git submodule paths
export cppshare=$mainFolder/cppshare
export repNamespaces=$cppshare/repNamespaces
export repObjects=$cppshare/repObjects

### update path to use executable everywhere
export PATH=$mainFolder/build:${PATH}

