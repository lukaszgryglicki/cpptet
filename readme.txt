This program is based on:
http://www.ils.uec.ac.jp/~dima/PAPERS/2010vladie.pdf
http://mizugadro.mydns.jp/t/index.php/Fslog.cin
http://mizugadro.mydns.jp/t/index.php/Fsexp.cin

For compilation see Makefile, in my system: "c++ -O3 -o prog_name source.cc -lm"
For running:
1. Compile
2. Run from terminal: ./cpptet:

./cpptet [e|l|h] [Re=1 [Im=0 [iterRe=0.5 [iterIm=0]]]]
e: sexp
l: slog
h: hexp


1st argument is type of function to compute, it can be:
e - compute tetration/sexp - exp superfunction
l - compute arctetration/superlogarithm - exp Abel function
h - compute fractional exp iteration (default 1/2) using sexp(c+slog(z))

Next two parameters are for specify function complex argument: Re(z) and Im(z)
2nd arguments is Re(z), if not given 1 is assumed
3rd argument is Im(z), if not given 0 is assumed

Next two parameters are only used for 'h' funcion (fractional iterate) and specify fractional iteration value c, default is 1/2 = half iterate exp()
4th argument is Re(c), if not given 0.5 is assumed
5th argument is Im(c), if not given 0 is assumed

For example to compute: 
tet(2): 		e 2
tet(i): 		e 0 1
tet(2-pi*i): 		e 2 -3.14
ate(1000)		l 1000
ate(-e*i)		l 0 -2.718
exp[1/2](10)		h 10
exp[0.9](e+pi*i)	h 2.718 3.14 0.9
exp[i](i)		h 0 1 0 1


And so on

*** I've ONLY adopted code from links at the beginning of this file ***
... and added way to call sexp, slog and any partial iterate of exp() from C++

