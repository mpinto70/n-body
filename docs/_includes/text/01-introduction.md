## Introduction

Given two bodies $$p_1$$ and $$p_2$$ of masses $$m_1$$ and $$m_2$$; separated by a distance $$r$$,
[Newton's law of universal gravitation](https://en.wikipedia.org/wiki/Newton%27s_law_of_universal_gravitation)
establishes that the gravitational force that attracts one body to the other is:

$$
F = G \frac{m_1 m_2}{r^2} \tag{1}
$$

where $$F$$ is the gravitational force of two bodies; $$r$$ is the distance between them and $$G$$ is the [gravitational
constant](https://en.wikipedia.org/wiki/Gravitational_constant): $$G = 6.67430 \times 10^{-11}
\frac{\mathrm{m}^3}{\mathrm{kg}\cdot\mathrm{s}^2}$$. The gravitational force is the same in both bodies and point from
one body to the other.

<img src="assets/images/2-body.svg">

Given the positions of $$p_1$$, $$\mathbf{s}_{1}$$, and $$p_2$$, $$\mathbf{s}_{2}$$, the
vector pointing from $$p_1$$ to $$p_2$$ is

$$\mathbf{r}_{12} = \mathbf{s}_{2} - \mathbf{s}_{1} \tag{2}$$

And the unitary vector in the direction from $$p_1$$ to $$p_2$$ is

$$\mathbf{u}_{12} = \frac {\mathbf{r}_{12}}{\sqrt {\mathbf{r}_{12} \cdot \mathbf{r}_{12}}}  \tag{3}$$

The vector form of eq. 1 is:

$$\mathbf{F}_{12} = G \frac{m_1 m_2}{\mathbf{r}_{12} \cdot \mathbf{r}_{12}} \mathbf{u}_{12} \tag{4}$$

As can be seen in the figure above: $$\mathbf{F}_{12} = -\mathbf{F}_{21}$$.
