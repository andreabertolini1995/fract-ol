<h1 align="center"> Fract-ol </h1>

<p align="center">
  <img src="https://github.com/andreabertolini1995/fract-ol/assets/51784826/03869de7-dd10-437d-96ac-36ecdf7192ee" />
</p>

This project is about creating a simple computer graphics program to show the beauty of fractals.

## What is a fractal?

A fractal is an abstract mathematical object, like a curve or a surface, which pattern remains the same at every scale.

To understand what fractals are all about, we need to take a step back and dive a little bit into the world of complex numbers.

Let's consider a point `A` and a constant `c` in the complex plane, as well as the generic function $f(z) = z^2 + c$. 
Let's now imagine to apply this function to the point `A` and iteratively apply the same function to its result, again and again, for let's say about 100 iterations.

It's very interesting to see that for some values of `c` the iteration converges, while for others it diverges to infinity at different speed. In the following example, `A` is set to `0.4 + 0.4i`.

https://github.com/andreabertolini1995/fract-ol/assets/51784826/c4cf570e-9c60-4391-a9cb-3c98a96b212a

When iterated from `A = 0`, the set of complex numbers `c` for which the function $f(z) = z^2 + c$ does not diverge to infinity is called the [Mandelbrot Set](https://en.wikipedia.org/wiki/Mandelbrot_set). 

On the other hand, for a given complex number `c`, the [Julia set](https://en.wikipedia.org/wiki/Julia_set) of c is the set of all `A` for which the iteration $f(z) = z^2 + c$ does not diverge to infinity.

Particularly interesting to see are the boundaries of the different Julia sets for a given value of `c`, i.e. the perimiter in the complex plane outside which the iterations diverges to infinity.

https://github.com/andreabertolini1995/fract-ol/assets/51784826/f5125428-00dd-49b9-a96e-2b18b7d2b436

Within the scope of this project, it was required to display the Mandelbrot set as well as any possible Julia set, given a different value of the constant `c` as input.

## Run the code

To run the algorithm, it is first needed to clone the repository, move the its directory and then execute the Makefile. 
```
git clone https://github.com/andreabertolini1995/fract-ol.git
cd fract_ol
make
```

Then, you can launch the executable followed by the name of the fractal you want to display. With the mouse wheel you will be able to zoom in and out almost infinitely (within the limits of the
computer). 
```
./fractol mandelbrot
```

https://github.com/andreabertolini1995/fract-ol/assets/51784826/c0fd1f8b-e653-4b70-a4cc-3c2dc4226547


For the Julia set, it is required to specify the complex coordinates of the constant `c`.
```
./fractol julia 0.285 0.01
```

https://github.com/andreabertolini1995/fract-ol/assets/51784826/247c0853-aec7-4a41-80fc-60b0251fc552

