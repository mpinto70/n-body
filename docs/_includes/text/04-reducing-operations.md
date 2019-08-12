## Reducing the number of operations

In order to reduce the number of operations performed, I use some variations of equations of previous sections:

$$
\begin{align}
\mathbf{\Delta v}_i & = \mathbf{a}_i \Delta t  \tag{11} \\
\mathbf{s}_i & = \mathbf{s}_{i_0} + \mathbf{v}_i \Delta t + \frac12 \mathbf{\Delta v}_i \Delta t \tag{12} \\
\mathbf{v}_i & = \mathbf{v}_{i_0} + \mathbf{\Delta v}_i  \tag{13} \\
\mathbf{a}_i & = \frac {G\sum_{j=1}^{n} \frac {m_i m_j} {r_{ij}^2} \mathbf{u}_{ij}}{m_i} \\
& = G\sum_{j=1}^{n} \frac {\mathbf{u}_{ij}} {r_{ij}^2} m_j \tag{14} \\
\end{align}
$$

The velocity change $$\mathbf{\Delta v}_i$$ (eq. 11) has to be calculated to determine next velocity $$\mathbf{v}_i$$
(eq. 13) and can be reused in next position calculation $$\mathbf{s}_i$$ (eq. 12). For acceleration calculation
$$\mathbf{a}_i$$ (eq. 14) eq. 15 I use the following matrix product:

$$
\mathbf{a}_i = G
\begin{bmatrix}
\mathbf{0}                        & \frac{\mathbf{u}_{12}}{r_{12}^2}  & \cdots & \frac{\mathbf{u}_{1n}}{r_{1n}^2} \\
\frac{\mathbf{-u}_{12}}{r_{12}^2} & \mathbf{0}                        & \cdots & \frac{\mathbf{u}_{2n}}{r_{2n}^2} \\
\vdots                            & \vdots                            & \ddots & \vdots                           \\
\frac{\mathbf{-u}_{1n}}{r_{1n}^2} & \frac{\mathbf{-u}_{2n}}{r_{2n}^2} & \cdots & \mathbf{0}                       \\
\end{bmatrix}
\begin{bmatrix}
m_1    \\
m_2    \\
\vdots \\
m_n    \\
\end{bmatrix}
\tag{15}
$$
