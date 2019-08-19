## Simulations

In order to assess the effect of using a bigger $$\Delta t$$, I ran two simulations for the inner solar system, for 300
years with two different values for $$\Delta t$$: $$2\mathrm{s}$$ and $$20\mathrm{s}$$. The commands ran were:

```
bin/exe files/inner-solar-system 300 2 >/tmp/solar-system.2.out
bin/exe files/inner-solar-system 300 10 >/tmp/solar-system.20.out
```

In order to generate the graphs for these simulations I ran the following commands:

```
gnuplot -c files/inner-solar-system.gnuplot /tmp/solar-system.2.out 2
gnuplot -c files/inner-solar-system.gnuplot /tmp/solar-system.20.out 20
```

The results are shown below.

<img src="assets/images/solar-system.2.out.png">

<img src="assets/images/solar-system.20.out.png">

Note that, for the bigger $$\Delta t$$, Mercury orbit is expanding a lot. For the smaller $$\Delta t$$ the expansion is
more limited.
