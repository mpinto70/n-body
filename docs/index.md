---
title: Multiparticle gravity system
---

{% include formula_formatting.html %}

# Multiparticle gravity system

This system was inspired by [these articles](https://wordpress.com/read/blogs/158040751/posts/26)


The relevant equations to this problem are:

$$
\begin{align}
\mathbf{s}_i & = \mathbf{s}_{i_0} + \mathbf{v}_i t + \mathbf{a}_i \frac{t^2}{2} \tag{1} \\
\mathbf{v}_i & = \mathbf{v}_{i_0} + \mathbf{a}_i t  \tag{2} \\
\\
\mathbf{F} & = m \mathbf{a} \Rightarrow \mathbf{a} = \frac{\mathbf{F}}{m}  \tag{3} \\
\mathbf{r}_{ij} & = \mathbf{s}_j - \mathbf{s}_i  \tag{4} \\
r_{ij}^2 & = \mathbf{r}_{ij} \cdot \mathbf{r}_{ij}  \tag{5} \\
\mathbf{u}_{ij} & = \frac {\mathbf{r}_{ij}} {r_{ij}}  \tag{6} \\
\mathbf{F}_{ij} & = G \frac {m_i \cdot m_j} {r_{ij}^2} \mathbf{u}_{ij}  \tag{7} \\
\end{align}
$$

In which:
* $$\mathbf{s}_i$$ is the postion of particle $$p_i$$
* $$\mathbf{v}_i$$ is the velocity of particle $$p_i$$
* $$\mathbf{a}_i$$ is the acceleration of particle $$p_i$$
* $$\mathbf{r}_{ij}$$ is the distance vector pointing from particle $$p_i$$ to particle $$p_j$$ (see equation 4)
* $$\mathbf{u}_{ij}$$ is the unit vector pointing in the direction of $$\mathbf{r}_{ij}$$
* $$\mathbf{F}_{ij}$$ is the gravitational force acting on particle $$p_i$$ due to its interaction with
particle $$p_j$$

Since the gravitational pull act on both particles with the same intensity and inverted directions:
$$\mathbf{F}_{ij} = -\mathbf{F}_{ji}$$. Thus, it is possible to build an antisymmetric matrix to represent the
gravitational forces each particle is subjected.

$$
\begin{bmatrix}
\mathbf{0}       & \mathbf{F}_{12}  & \mathbf{F}_{13}  & \cdots & \mathbf{F}_{1n} \\
-\mathbf{F}_{12} & \mathbf{0}       & \mathbf{F}_{23}  & \cdots & \mathbf{F}_{2n} \\
-\mathbf{F}_{13} & -\mathbf{F}_{23} & \mathbf{0}       & \cdots & \mathbf{F}_{3n} \\
\vdots           & \vdots           & \vdots           & \ddots & \vdots          \\
-\mathbf{F}_{1n} & -\mathbf{F}_{2n} & -\mathbf{F}_{3n} & \cdots & \mathbf{0}      \\
\end{bmatrix}
$$

In order to compute the total gravitational force acting on a particle $$p_i$$, it suffices to sum all
the forces of line $$i$$ of the above matrix.