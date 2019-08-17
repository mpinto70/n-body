## Reducing the number of operations

In order to reduce the number of operations performed, I use some variations of equations of previous sections:

$$
\begin{align}
\mathbf{\Delta v}_i & = \mathbf{a}_i \Delta t                                               \tag{14} \\
\mathbf{s}_i & = \mathbf{s}_{i_0} + (\mathbf{v}_i + \frac12 \mathbf{\Delta v}_i) \Delta t   \tag{15} \\
\mathbf{v}_i & = \mathbf{v}_{i_0} + \mathbf{\Delta v}_i                                     \tag{16} \\
\mathbf{a}_i & = \frac {G\sum_{j=1}^{n} \frac {m_i m_j} {r_{ij}^2} \mathbf{u}_{ij}}{m_i} \\
& = G\sum_{j=1}^{n} \frac {\mathbf{u}_{ij}} {r_{ij}^2} m_j                                  \tag{17} \\
\end{align}
$$

The velocity change $$\mathbf{\Delta v}_i$$ (eq. 14) has to be calculated to determine next velocity $$\mathbf{v}_i$$
(eq. 16) and can be reused in next position calculation $$\mathbf{s}_i$$ (eq. 15). For acceleration calculation
$$\mathbf{a}_i$$ (eq. 17) I use the following matrix product:

$$
\underbrace{
\begin{bmatrix}
\mathbf{a}_1    \\
\mathbf{a}_2    \\
\vdots          \\
\mathbf{a}_n    \\
\end{bmatrix}
}_{\mathbf{A}}
=
\underbrace{
\begin{bmatrix}
\mathbf{0}                        & \frac{\mathbf{u}_{12}}{r_{12}^2}  & \cdots & \frac{\mathbf{u}_{1n}}{r_{1n}^2} \\
\frac{\mathbf{-u}_{12}}{r_{12}^2} & \mathbf{0}                        & \cdots & \frac{\mathbf{u}_{2n}}{r_{2n}^2} \\
\vdots                            & \vdots                            & \ddots & \vdots                           \\
\frac{\mathbf{-u}_{1n}}{r_{1n}^2} & \frac{\mathbf{-u}_{2n}}{r_{2n}^2} & \cdots & \mathbf{0}                       \\
\end{bmatrix}
}_{\mathbf{Ur}}
\underbrace{
\left( G
\begin{bmatrix}
m_1    \\
m_2    \\
\vdots \\
m_n    \\
\end{bmatrix}
\right)
}_{\mathbf{Gm}}                                                                             \tag{18}
$$

Using [Hadamard product](https://en.wikipedia.org/wiki/Hadamard_product_(matrices)), eq. 18 becomes
$$
\underbrace{
\begin{bmatrix}
\mathbf{a}_1    \\
\mathbf{a}_2    \\
\vdots          \\
\mathbf{a}_n    \\
\end{bmatrix}
}_{\mathbf{A}}
=
\left(
\underbrace{
\begin{bmatrix}
\mathbf{0}          & \mathbf{u}_{12}   & \cdots    & \mathbf{u}_{1n}   \\
\mathbf{-u}_{12}    & \mathbf{0}        & \cdots    & \mathbf{u}_{2n}   \\
\vdots              & \vdots            & \ddots    & \vdots            \\
\mathbf{-u}_{1n}    & \mathbf{-u}_{2n}  & \cdots    & \mathbf{0}        \\
\end{bmatrix}
}_{\mathbf{U}}
\circ
\underbrace{
\begin{bmatrix}
0                   & r_{12}^{-2}       & \cdots    & r_{1n}^{-2}       \\
r_{12}^{-2}         & 0                 & \cdots    & r_{2n}^{-2}       \\
\vdots              & \vdots            & \ddots    & \vdots            \\
r_{1n}^{-2}         & r_{2n}^{-2}       & \cdots    & 0                 \\
\end{bmatrix}
}_{\mathbf{R}}
\right)
\underbrace{
\begin{bmatrix}
G\,m_1  \\
G\,m_2  \\
\vdots  \\
G\,m_n  \\
\end{bmatrix}
}_{\mathbf{Gm}} \\
\\
\\
\mathbf{A}=(\mathbf{U} \circ \mathbf{R}) \, \mathbf{Gm}                                     \tag{19}
$$

Note that $$\mathbf{Gm}$$ is constant, $$\mathbf{U}=-\mathbf{U}^\mathsf{T}$$, and $$\mathbf{R}=\mathbf{R}^\mathsf{T}$$.

One of the [properties of the Hadamard product](https://en.wikipedia.org/wiki/Hadamard_product_(matrices)#Properties) is

$$
\mathbf{x^*}(\mathbf{K} \circ \mathbf{L})\mathbf{y}=\mathrm{tr}(\mathbf{D_x^*KD_yL^\mathsf{T}}) \tag{20}
$$

If we have $$\mathbf{x^*}=\mathbf{1}$$, then $$\mathbf{D_x^*}=\mathbf{I}$$, eq. 20 becomes

$$
\mathbf{A}=\mathrm{tr}(\mathbf{UD_{Gm}R})                                                   \tag{21}
$$

