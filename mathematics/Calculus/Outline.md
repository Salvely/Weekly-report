# Outline for Calculus Course

## Numbers, Functions & Graphs

- Introduction
  - Calculus is about motion and change.
  - The study object in Calculus is function
  - Function is a rule that tells us how one variable changes depend on another
- Real Number System
  - integers
  - rational numbers
  - irrational numbers
- Real line & absolute theorem
- Coordinate Plane & distance formula & the midpoint formula
- Some Curves in Coordinate Plane
  - Straight line
    - slope
    - equation
    - slop-point form
    - general form
    - parallel & perpendicular lines
  - Circles
  - Parabola
- Functions
  - one to one / multiple to one mappings
  - composite functions
  - polynomials -> rational functions
  - rational functions
  - algebraic functions
  - transecendental functions
- Graph of a functions
  - discontinuty
  - asymptote when x undefined
- some important trigonometric functions

## Derivative

### Definitions

- What is Calculus?
  - Differential Calculus: The problem of **Tangents**
    - Let Q be a second nearby point on the curve, and draw the secant line PQ.
    - The tangent line at P can now be thought of as the limiting position of the variable secant as Q slides along the curve toward P
  - Integral Calculus: the problem of **Area**
- Slope Calculation
  - Derivative Definiton
    - the slope of the secant line as P approaches Q (but not equal)
  - $\Delta$ notation
  - Slope definition
    - $f\prime(x_{0}) = \lim\limits_{\Delta{x}\rightarrow0}\frac{f(x_{0} + \Delta{x}) - f(x_{0})}{\Delta{x}}$
  - Slope Calculation
    - write $f(x+\Delta{x}) - f(x)$
    - divide it by $\Delta{x}$
    - as $\Delta{x}\rightarrow0$, obtain its limits
  - Tangent existence
    - must the same limit approaching from left or right
  - Differential Point
    - means that the tangent exists at $x_{0}$
  - Differential Functions
    - every point on the domain of the functions is differential
  - Important Notations
    - The derivative of a function $f(x)$ has been denoted above by $f\prime(x)$.
    - It reminds us that the derivetive of the function $f(x)$ is another function that is associated with the given function
    - when we write the function as $y = f(x)$, we could use $y\prime$ to denote its derivative
    - But it doesn't suggest the nature for the process for which $f\prime(x)$ is obtained from $f(x)$
    - when we use $\frac{\Delta{y}}{\Delta{x}}$, here $\Delta{y}$ is not an independent variable, it's the change in $y$ while $x$ changes
    - Leibniz wrote the limit of this difference quotient, which of course is the derivative $f\prime(x)$, in the form $\frac{dy}{dx}$ (read "dy over dx").
    - $\frac{dy}{dx}$ reminds us of the whole process of $\frac{\Delta{y}}{\Delta{x}}$ as $\Delta{x}$ approaches 0
    - but while calculating the slope on a specific point, we must use $\frac{dy}{dx}\vert_{x=x_{0}}$
- Velocity & the rate of change. Newton & Leibniz
  - Instantaneous Velocity
    - is the average velocity from $v(t)$ to $v(t+\Delta{t})$ as $\Delta{t}$ approaches 0
- Concept of a limit & Two Trigonometric Limits
  - Definition
    - When x approaches x0, f(x) approaches f(x0)
    - more precise: when x is close to $x_{0}$, f(x) is close to $f(x_{0})$
    - more more precise: no matter how close $\vert{x - x_{0}}\vert$ is, there always exists an $\epsilon > 0$ that $f(x) - f(x_{0}) < \epsilon$
    - formal definiton:
      - For each positive number $\epsilon$ there exists a positive number $\delta$ with the property that $\vert{f(x)-L}\vert < \epsilon$, for any number $x < a$ that satisfies the inequality $\vert{x-a}\vert < \delta$.
  - Important Tips
    - we only care about the value **near x=a**, but **not the valu at x=a**
  - Left Limit & Right limit
    - left limit
      - when x approaches a from the left side, the f(x) approaches value L
    - right limit
      - when x approaches a from the right side, the f(x) approaches value L
  - Limit Existence
    - Important: the limit only exists if both sides limit are equal
  - Calculation rules of the limit
    - addition / subtraction
    - multiply / division(denominator != 0)
  - Some trigonometric limit
    - $\lim\limits_{\theta\rightarrow0}\frac{\sin\theta}{\theta}=1$
      - could be obtained through geometry
    - $\lim\limits_{\theta\rightarrow0}\frac{1-\cos\theta}{\theta}=0$
- Continuous Functions
  - Continuous at point $x=a$
    - f(x) is defined at x=a (a is in the domain of f(x))
    - f(x) has limit at x=a(left limit = right limit)
    - $f(x)=\lim\limits_{x\rightarrow{a}}f(x)$
  - Continous Functions
    - function is continuous at every point in its domain
  - Formal Definition
    - $\lim\limits_{\Delta{x}\rightarrow{0}}f(x+\Delta{x})-f(x)=0$
    - $\lim\limits_{\Delta{x}\rightarrow{0}}f(x+\Delta{x})=f(x)$
    - $\lim\limits_{\Delta{x}\rightarrow{0}}\Delta{y}=0$
  - Derived Theorem
    - If a function is differential at $x=a$, then it is continuous at $x=a$
    - Differentiable -> Continuous
    - $\lim\limits_{\Delta{x}\rightarrow{0}}\Delta{y}=\lim\limits_{\Delta{x}\rightarrow{0}}\frac{\Delta{y}}{\Delta{x}}\Delta{x}=\lim\limits_{\Delta{x}\rightarrow{0}}\frac{dy}{dx}\Delta{x}=0$
  - 3 Theorem about Continuous functions
    - Mean Value Theorem
      - Supppose a function is continous on close interval $[a,b]$
      - And differntiable on an open interval $(a,b)$
      - Then there must be a point c on interval $(a,b)$
      - where the slope of the tangent line at c is equal to the slope of the secant line AB
      - **Application: Demonstate how the function increase and decrease, as well as stay constant**
    - Extreme Value Theorem
      - If f(x) is differentiable in closed interval $[a,b]$
      - then there exists both a maximum value & a minimum value in $[a,b]$
      - **Application: To find the maximum and minimum value on an interval**
    - Intermediate Value Theorem
      - there always be a value K on interval $[a,b]$ where f(a) <= K <= f(b)
      - **Application: To get the zero points of the equation(roots)**

### Computations

- Polynomials Derivative
- The product and Quotient Rules
- Composite functions and the Chain Rule
- Some trigonometric Derivatives
- Implicit Functions and Fractional Exponent
- Derivatives of higher order

### Applications

- Drawing function graph using some points and its derivative
  - To draw the graph
    - let $f\prime{x}=0$ to find critical points
    - judge if the derivative around critical points are not both positive or negative
    - get the zeros of $f(x)$
    - The behavior of $f(x)$ as $x\rightarrow{\infin}$ and as $x\rightarrow-\infty$.
    - points near where $f(x)$ is not defined
  - To get the absolute maximum
    - compare the critical points value with the interval boundary value
    - compare the critical points value with each other
- Concavity and Points of Inflection
  - Points of inflection
    - points where concavity changes($f\prime\prime(x)$ changes)
    - check $f\prime\prime(x)$ around the point of inflection to confirm it
- Applied Maximum and Minimum Problems
- More Maximum-Minimum Problems. Reflection and Refraction
- Related Rates
- Newton's Method for Solving Equations
- (Optional) Applications to Economics. Marginal Analysis

## Special Functions

### Exponential

- $y=e^x$ and $y=\ln{x}$
- $e=\lim\limits_{n\rightarrow+\infin}(1+\frac{1}{n})^n$ derives from the meaning of $e$
- the purpose of e is to proof the existence of a function which $\frac{d}{dx}f(x)=f(x)$

### Logarithms

- $\frac{d}{dx}\log_{a}x=\frac{1}{x\ln{a}}$
- $\ln{x}=\int_{1}^{x}\frac{dt}{t}$
- technique
  - when dealing with $y=x^{x}$, first compute $\ln{y}$
  - transform multiple factor into a sequence of $\ln$

### Trigonometric

- some basic formula
  - $\tan^2\theta+1=\sec^2\theta$
  - $\cot^2\theta+1=\csc^2\theta$
  - $\tan{(\theta+\delta)}=\frac{\tan{\theta}+\tan{\delta}}{1-\tan{\theta}\tan{\delta}}$
  - $\tan{(\theta-\delta)}=\frac{\tan{\theta}-\tan{\delta}}{1+\tan{\theta}\tan{\delta}}$
- 2 important limit formula
  - $\lim\limits_{x\rightarrow{0}}\frac{\sin{x}}{x}=1$
  - $\lim\limits_{\theta\rightarrow{0}}\frac{1-\cos{\theta}}{\theta}=0$
- some derivative about the other 4 function
  - $\frac{d}{dx}\tan{x}=\sec^2{x}$
  - $\frac{d}{dx}\cot{x}=-\csc^2{x}$
  - $\frac{d}{dx}\sec{x}=\sec{x}\tan{x}$
  - $\frac{d}{dx}\csc{x}=-\csc{x}\cot{x}$
- inverse trigonometric functions
  - $\int\frac{dx}{\sqrt{1-x^2}}=\arcsin{x}$
  - $\int\frac{dx}{1+x^2}=\arctan{x}$

## Integrals

### Indefinite Integrals & Differential Equations

- the meaning of $\frac{dy}{dx}$
  - use tangent lines to approximate the curve
- Introduction to Integration
- Integration by substitution
- Integration by separating variables
- Applications
  - Velocity, Speed, Acceleration
  - Newton second law
  - Gravity law
  - Escape speed

### Definite Integrals

- Definition
  - The idea of exhastion is the key of Calculus
  - Definite Integral is about the problem of **Area**
  - Difference between Definite Integrals and Infinite Integrals
    - Infinite Integrals is a collection of functions
    - Definite Integrals is an value
- $\sigma$ Notation and the special Sums
- How Definite Integrals come from?
  - divide the intervals
  - sum their(maximum/minimum) function values
  - calculate the limit when the longest interval length -> 0
- Calculus Basic Theorem
  - assuming $A(x)=\int_{a}^{x}f(x)$
  - The relationship between
    - f(x) and A(x): $\frac{dA}{dx}=f(x)$
    - F(x) and A(x): $A(x)=F(x)+C$
    - A(b) calculation: $A(b)=F(b)-F(a)$
- Properties of Definite Integrals
  - Difference between Area(always positive) & Integral results(must have negative value for function below the x-axis)
  - $\int_{a}^{b}f(x)=-\int_{b}^{a}f(x)$
  - $\int_{a}^{b}f(x)=\int_{a}^{c}f(x)+\int_{c}^{b}f(x)$
  - mulplication rule: $c\int_{a}^{b}f(x)=\int_{a}^{b}cf(x))$
  - addition rule
  - comparison rule
- Summary
  - Sigma Notation
  - Special Sums
  - Area under a curve; lower sums and upper sums.
  - Definite integral as a limit of sums.
  - Limits of integration, integrand, variable of integration.
  - Integrable Functions
  - Every Continuous function is integrable
  - Fundamental Theorem of Calculus.
  - Indefinite integral.
  - Algebraic and geometric areas.
  - Variable limit of integration

### Applications

- The intutive meaning of integration
- Area between two curves
- Volume
  - Disk Method
  - Cylindrical Shells Method
- Arc & Surface
  - Arc(smooth-> have continuous changing derivative) Length Calculation
    - method
      - slice the arc and calculate each segment length
      - then sum them
      - as the numebr of segments n->0, the sum -> the length of the arc
    - $s=\int_{a}^{b}\sqrt{1+\frac{dy}{dx}^2}dx$ or $\int_{a}^{b}\sqrt{1+\frac{dx}{dy}^2}dy$
  - Surface Area of a Revolution
    - $S=\int_{a}^{b}2\pi{r}ds$ and $ds=\sqrt{1+\frac{dy}{dx}^2}dx$
- Physical Applications
  - Work and Energy
  - Hydrostatic Force

### Some Common Integration Methods

## Some Important Theorem in Single Variable Calculus

## Series

### Infinite Series

### Power Series

## Intro to Multi-dimension: Conic Sections

## Higher Dimension Representation

### Polar Coordinates

### Parameter Equations

## Vectors

### Vectors in 2D plane

### Vectors in 3D space & surfaces

## Multivariable Derivative & Integral

### Partial Derivatives

### Multiple Integrals

## Line & Surface Relationships

## Some Important Theorem in Multivariable Calculus
