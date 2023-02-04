Definition: 1 | rj | Lmax

TS parameters:
- Aspiration criteria: the current f(sol) + swapping a currently tabu improvement > best f(sol) so far
- Max. iterations are to be passed as input
- Max. iterations w/o improvement are to be passed as input as well
- tabu list for a randomly generated set of n jobs will be a class with its proper nxn matrix
- a pair<int,int> of indexes with their values altered shall be in an list of such pairs
- lower diagonal, as well as unused entries, shall be initialized with either 0 or -1 (to be defined)
- n-1+n-2+n-3+...+3+2+1 neighbourhood N(i,k) shall be determined through exaustive sweeping
- the top five best candidate pairs to be swapped shall be in a separate vector of size = 5 (whether at same class or not yet to be defined)
- once N(i,k) is done, swap the best non-tabu pair in top-5, if the best tabu improvement does not result in a better f(sol) than the best so far
- if, however, a swap which yield a better solution than the best thus far, ignore the pair being tabu and swap them, resetting the number of iterations to stay as tabu to 3

"BASIC TABU SEARCH ALGORITHM":
Step 1: Choose an initial solution i in S; set i* = i and k = 0
Step 2: Set k = k + 1 and generate a subset V* of solution in N(i,k) such that either one of tabu conditions is violated or at least one of the aspiration conditions holds
Step 3: Choose a best j in V* and set i = j
Step 4: If f(i) < F(i*) then set i* = i
Step 5: Update tabu and aspiration conditions
Step 6: If a stopping condition is met then stop; else go to step 2


OUR APPROACH IN TERMS OF THE "BASIC TABU SEARCH ALGORITHM":
Initial solution sol shall be a random permutation of n jobs, and the best-so-far-value shall be the f(sol) for initial sol;
Increment k so to determine the best five choices through sweeping. Doing so shall be N(sol,1) or the neighbourhood
In other words, the N(i,k) will be exaustive every time thus being of no relevance except as the mean to determine the top five
The violation of tabu condition shall be ignored, and so shall be the aspiration condition hold criteria. Like previously stated, N(i,k) shall be exaustive.
V* is the vector with the top five choices, and it will be then traversed from best to worse. The first pair not in tabu list or the first which increase the globalbest i* shall be selected and swapped.
The value of f is then updated, and so the best global if increased.
The update of conditions for tabu are decreasing all index pairs greater than zero and removing then from tabu list if they become zero after decreased
Aspiration condition is inherently attached to f(i*), thus having nothing to update
The stopping condition are one of the following:
- k > max. iterations
- f(i*) didn't increase for the last max. iterations w/o improvement
- f(i*) = the constant from which Lmax is subtracted, meaning Lmax is zero therefore the best possible solution (one of possible many with the same f(sol) = constant minus zero)
- As for the four stopping criteria showed at the video, only the first one is yet uncovered --- and so will stay, for N(i,k+1) is exaustive and as such never equals zero.

WHAT TO DO WHEN ALL PAIRS AT TOP FIVE ARE TABU:
- push_back an extra value and keep doing so while the remaining pairs are tabu
- if they all happen to be tabu once ended, decrease every pair at the list up until at least one of them is removed
- repeat the process, since at least the removed value shall be at the top five for not being tabu either alone or with others equally removed at the previous step
- swap the best choice --- and do not bother checking f(i*) since any pair which could increase it if swapped would have been done at the very first step since such condition implies ignoring the pair being tabu, then reset its value to 3.

INPUT:
- a line containing both max iterations, the max anyhow and the limit for f(i*) to remain unimproved
- the value of n so the tabu list can be created with proper size and initialize cells whose index are an invalid pair and those indexed by a so far unused pair, filling them with 0 or -1 or both, as must be determined before this point in time)
- next n lines shall have a job number, its release date, its due date, each with a single space between them and a LF next to the due date
- An input file generator will be implemented
- Parameters such as both limit of iterations and the value of n will be passed as arguments to the gen
- Other parameters such as distributions, probabilities, and intervals for release and due dates are to be previously determined and hardcoded at gen
