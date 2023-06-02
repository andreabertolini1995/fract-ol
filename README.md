<h1 align="center"> Fract-ol </h1>

<p align="center">
  <img src="https://github.com/andreabertolini1995/fract-ol/assets/51784826/03869de7-dd10-437d-96ac-36ecdf7192ee" />
</p>

This project is about creating a simple computer graphics program to show the beauty of fractals.

## What is a fractal?

A fractal is an abstract mathematical object, like a curve or a surface, which pattern remains the same at every scale.
<!-- The term fractal was first used by mathematician Benoit Mandelbrot in 1974. He based it on the Latin word fractus which means "broken" or "fractured". -->

To understand what fractals are all about, we need to take a step back and dive a little bit into the world of complex numbers.
Let's consider a point `A` and a constant `c` in the complex plane, as well as the generic function $f(z) = z^2 + c$. Let's now imagine to apply this function to the point A and iteratively apply the same function to its result, and again, and again, for let's say about 100 iterations.

It's very interesting to see that for some values of `c` the iteration converges, while for others it diverges to infinity, anyways at a different speed. In the following example, the point `A` has been set to `0.4 + 0.4i`.



### Mandelbrot set
The Mandelbrot set is the set of complex numbers C for which the function f(z) = z^2 + C does not diverge to infinity when iterated from z=0. 

### Julia set
For a complex number c, the filled-in Julia set of c is the set of all z for which the iteration z → z2 + c does not diverge to infinity.


