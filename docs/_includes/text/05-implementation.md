## Implementation

Since $$\mathbf{Gm}$$ is constant (eq. 19), it can be calculated at the beginning of the simulation and then reused in
every iteration to calculate $$\mathbf{A}$$.

### Scale

For [solar system](https://en.wikipedia.org/wiki/Solar_System) simulations:

$$
10^{10}\,\mathrm{m}  < r < 10^{13}\,\mathrm{m}   \\
10^{3}\,\mathrm{m/s} < v < 10^{5}\,\mathrm{m/s} \\
10^{22}\,\mathrm{kg} < m < 10^{31}\,\mathrm{kg} \\
10^{11}\,\mathrm{m^3/s^2} < G\,m < 10^{20}\,\mathrm{m^3/s^2} \\
$$

In order to avoid numbers that are too big or too small, we should strive to combine big numbers with small numbers
(like I did with $$G\,m$$). Also, eq. 17 could be written as

$$
\mathbf{a}_i = G\sum_{j=1}^{n} \frac {\mathbf{r}_{ij}} {r_{ij}^3} m_j
$$

I could have made $$\mathbf{U}_{ij}=\mathbf{r}_{ij}$$ and $$\mathbf{R}_{ij}=r_{ij}^{-3}$$, but in that case
$$10^{-39}<R_{ij}<10^{-30}$$, which is a very small number. So I preferred to formulate the problem as I did, because
$$\mathbf{U}_{ij}=\mathbf{u}_{ij}$$, which is the unitary vector, and $$\mathbf{R}_{ij}=r_{ij}^{-2}$$ which makes
$$10^{-23}<R_{ij}<10^{-20}$$, that are not so small as the other.