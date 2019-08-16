## Approximations

It should be noted that, from eq. 2, $$\mathbf{r} = \mathbf{r}(t)$$ and consequently $$\mathbf{F} = \mathbf{F}(t)$$ (eq.
4). The simulation will progress in small time increments $$\Delta t$$ and consider that $$\mathbf{F}$$ is constant
during these increments. The consequence of this procedure is shown in the figure below.

<img src="assets/images/deviation.svg">

The dashed circle is where the body would really be after $$\Delta t = t_1 - t_0$$ time elapsed, but since I consider
that the force $$\mathbf{F}$$ is constant during $$\Delta t$$ interval, the calculated position is the one shown by the
filled green disk. The deviation $$\varepsilon$$ has the following relations:

$$
\begin{align}
\varepsilon & \propto \Delta t                  \tag{11} \\
\varepsilon & \propto | \mathbf{v} |            \tag{12} \\
\varepsilon & \propto \textrm{orbit curvature}  \tag{13} \\
\end{align}
$$

For all the factors affecting $$\varepsilon$$ $$\Delta t$$ is the only one that can be manipulated during the
simulation.
