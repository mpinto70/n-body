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
\mathbf{F}_i & = m \mathbf{a}_i \Rightarrow \mathbf{a}_i = \frac{\mathbf{F}_i}{m_i}  \tag{3} \\
\\
\mathbf{r}_{ij} & = \mathbf{s}_j - \mathbf{s}_i  \tag{4} \\
r_{ij}^2 & = \mathbf{r}_{ij} \cdot \mathbf{r}_{ij}  \tag{5} \\
\mathbf{u}_{ij} & =
\begin{cases}
\frac {\mathbf{r}_{ij}} {r_{ij}}, & i \ne j\\
\mathbf{0}, & i = j
\end{cases} \tag{6} \\
\\
\mathbf{F}_{ij} & =
\begin{cases}
G \frac {m_i m_j} {r_{ij}^2} \mathbf{u}_{ij}, & i \ne j \\
\mathbf{0}, & i = j
\end{cases} \tag{7} \\
\end{align}
$$

In which:
* $$\mathbf{s}_i$$ is the postion of particle $$p_i$$
* $$\mathbf{v}_i$$ is the velocity of particle $$p_i$$
* $$\mathbf{a}_i$$ is the acceleration of particle $$p_i$$
* $$\mathbf{r}_{ij}$$ is the distance vector pointing from particle $$p_i$$ to particle $$p_j$$ (eq. 4)
* $$\mathbf{u}_{ij}$$ is the unit vector pointing in the direction of $$\mathbf{r}_{ij}$$
* $$\mathbf{F}_{ij}$$ is the gravitational force acting on particle $$p_i$$ due to its interaction with
particle $$p_j$$. Note that $$\mathbf{F}_{ij} = -\mathbf{F}_{ji}$$.

## Reducing the number of operations

In order to reduce the number of operations performed, some simplifications are possible:

$$
\begin{align}
\mathbf{\Delta v}_i & = \mathbf{a}_i t  \tag{8} \\
\mathbf{s}_i & = \mathbf{s}_{i_0} + \mathbf{v}_i t + \mathbf{\Delta v}_i \frac{t}{2} \tag{9} \\
\mathbf{v}_i & = \mathbf{v}_{i_0} + \mathbf{\Delta v}_i  \tag{10} \\
\mathbf{a}_i & = \frac {G\sum_{j=1}^{n} \frac {m_i m_j} {r_{ij}^2} \mathbf{u}_{ij}}{m_i}
= G\sum_{j=1}^{n} \frac {m_j} {r_{ij}^2} \mathbf{u}_{ij}
= G\sum_{j=1}^{n} \frac {\mathbf{u}_{ij}} {r_{ij}^2} m_j \tag{11} \\
\end{align}
$$

It is necessary to calculate the change in velocity $$\mathbf{a}_i$$ (eq. 8), and then we can reuse this result to
help in the calculations of next position $$\mathbf{s}_i$$ (eq. 9) and next velocity $$\mathbf{v}_i$$ (eq. 10). It is
still necessary to calculate the acceleration $$\mathbf{a}_i$$ (eq. 11). For this we can use an asymmetric matrix and a
vector (eq. 12):
$$
\mathbf{a}_i = G
\begin{bmatrix}
\mathbf{0}                        & \frac{\mathbf{u}_{12}}{r_{12}^2}  & \frac{\mathbf{u}_{13}}{r_{13}^2}  & \cdots & \frac{\mathbf{u}_{1n}}{r_{1n}^2} \\
\frac{\mathbf{-u}_{12}}{r_{12}^2} & \mathbf{0}                        & \frac{\mathbf{u}_{23}}{r_{23}^2}  & \cdots & \frac{\mathbf{u}_{2n}}{r_{2n}^2} \\
\frac{\mathbf{-u}_{13}}{r_{13}^2} & \frac{\mathbf{-u}_{23}}{r_{23}^2} & \mathbf{0}                        & \cdots & \frac{\mathbf{u}_{3n}}{r_{3n}^2} \\
\vdots                            & \vdots                            & \vdots                            & \ddots & \vdots                           \\
\frac{\mathbf{-u}_{1n}}{r_{1n}^2} & \frac{\mathbf{-u}_{2n}}{r_{2n}^2} & \frac{\mathbf{-u}_{3n}}{r_{3n}^2} & \cdots & \mathbf{0}                       \\
\end{bmatrix}
\begin{bmatrix}
m_1    \\
m_2    \\
m_3    \\
\vdots \\
m_n    \\
\end{bmatrix}
\tag{12}
$$
