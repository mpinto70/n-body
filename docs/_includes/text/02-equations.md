## Other equations

[Newton's second law of motion](https://en.wikipedia.org/wiki/Newton%27s_laws_of_motion#Newton's_second_law):

$$
\mathbf{F} = m \mathbf{a} \Rightarrow \mathbf{a} = \frac{\mathbf{F}}{m}  \tag{5}
$$

[Constant linear acceleration
equations](https://en.wikipedia.org/wiki/Equations_of_motion#Constant_linear_acceleration_in_any_direction)

$$
\begin{align}
\mathbf{s} & = \mathbf{s}_{0} + \mathbf{v} t + \frac12 \mathbf{a}t^2 \tag{6} \\
\mathbf{v} & = \mathbf{v}_{0} + \mathbf{a} t  \tag{7} \\
\end{align}
$$


<img src="assets/images/n-body.svg">

Considering multi-body interaction illustrated in above figure, eq. 3 and eq. 4 become:

$$
\begin{align}
\mathbf{u}_{ij} & =
\begin{cases}
\frac {\mathbf{r}_{ij}} {r_{ij}}, & i \ne j\\
\mathbf{0}, & i = j
\end{cases} \tag{8} \\
\\
\mathbf{F}_{ij} & =
\begin{cases}
G \frac {m_i m_j} {r_{ij}^2} \mathbf{u}_{ij}, & i \ne j \\
\mathbf{0}, & i = j
\end{cases} \tag{9} \\
\\
\mathbf{F}_{ij} & = -\mathbf{F}_{ji} \tag{10}
\end{align}
$$

