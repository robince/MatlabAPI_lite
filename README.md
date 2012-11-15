MatlabAPIlite
==============

Templated version of MatlabAPI with fewer features, but support for all Matlab numeric types

This is based on the [Fortran 95 Matlab API](http://www.mathworks.com/matlabcentral/fileexchange/25934-fortran-95-interface-to-matlab-api-with-extras) by James Tursa.

It is a stripped down version with only basic support for working with Matlab arrays. There is no sparse or complex support or many of the useful additional functions in the full MatlabAPI package. 

This is templated with [PyF95++](http://sourceforge.net/apps/mediawiki/blockit/index.php?title=PyF95%2B%2B) from the [BlockIt](http://sourceforge.net/projects/blockit/) package so it supports all numeric Matlab types.

Also it replaces the common block approach with `c_f_pointer` from `iso_c_binding`. So if you have a compiler that supports it and want to use data types other than double maybe it is useful. Otherwise check out the main MatlabAPI package. 

