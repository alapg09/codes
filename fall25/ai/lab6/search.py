# search.py
# ---------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util
import sys
import queue

from  collections import namedtuple

class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]

def whateverFirstSearch(problem, frontier):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Implement the graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print("Start:", problem.getStartState())
    print("Is the start a goal?", problem.isGoalState(problem.getStartState()))
    print("Start's successors:", problem.getSuccessors(problem.getStartState()))

    Argument:
       problem -- an obj of type SearchProblem (or a subclass of) to solve.

       frontier - The object to use for holding the frontier.  This
       dictates the type of search performed.
    Returns
       A tuple containing:
         - list of actions that reach the goal or None if goal not found
         - cost of actions or None if goal not found
         - number of items removed from the frontier
         - number of items added to the frontier.
    """
    "*** YOUR CODE HERE ***"
    util.raiseNotDefined()


def depthFirstSearchStats(problem):
    """
        Call whateverFirstSearch and return results that
        will respect DFS behavior.
        Returns: the 4 tuple returned by whateverFirstSearch
    """
    util.raiseNotDefined()


def depthFirstSearch(problem):
    """
    Do not change this function

    Search the deepest nodes in the search tree first.
    """
    return depthFirstSearchStats(problem)[0] # return the list of actions only


def breadthFirstSearchStats(problem):
    """ Search the shallowest nodes in the search tree first.
        Returns: the 4 tuple returned by whateverFirstSearch
    """
    
    "*** YOUR CODE HERE ***"

    util.raiseNotDefined()


def breadthFirstSearch(problem):
    """ Do not change this function"""
    return breadthFirstSearchStats(problem)[0] # return the list of actions only


def uniformCostSearchStats(problem):

    start = problem.getStartState() # initial
    frontier = util.PriorityQueue() # priority queue for ucs

    frontier.push((start, [] , 0), 0)  # state, actions, cost ; priority = cost
    
    frontier_puts = 1
    frontier_gets = 0   # keeping track of pushes and gets
    explored = dict()  # to avoid repetition
    while not frontier.isEmpty():
        state, actions, cost_so_far = frontier.pop()
        frontier_gets += 1
        if state in explored and explored[state] <= cost_so_far:    # if state already explored at equal or lower cost  
            continue    
        explored[state] = cost_so_far   # new
        if problem.isGoalState(state): # goal check
            return actions, cost_so_far, frontier_gets, frontier_puts
        for succ, action, stepCost in problem.getSuccessors(state): # negihbours
            new_cost = cost_so_far + stepCost
            if succ not in explored or new_cost < explored.get(succ, float('inf')):     #state not explroed or cheaper path
                frontier.push((succ, actions + [action], new_cost), new_cost)   # push with new cost as priority    
                frontier_puts += 1
    return None, 0, frontier_gets, frontier_puts    # default
    util.raiseNotDefined()

def uniformCostSearch(problem):
    """Search the node of least total cost first."""
    return uniformCostSearchStats(problem)[0]


def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearchStats(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    start = problem.getStartState() # similar to ucs
    frontier = util.PriorityQueue()
    start_h = heuristic(start, problem) # calc hueristic
    frontier.push((start, [], 0), start_h)
    frontier_puts = 1
    explored = dict()  # dict because pointing state -> best g
    frontier_gets = 0
    while not frontier.isEmpty():
        state, actions, g = frontier.pop()
        frontier_gets += 1
        if state in explored and explored[state] <= g:  # already found one with <= cost
            continue
        explored[state] = g
        if problem.isGoalState(state):  # goal check
            return actions, g, frontier_gets, frontier_puts
        for succ, action, stepCost in problem.getSuccessors(state): # neighbours
            new_g = g + stepCost
            h = heuristic(succ, problem)
            f = new_g + h   # logic begind A*
            if succ not in explored or new_g < explored.get(succ, float('inf')):    # state not explored or lower cost
                frontier.push((succ, actions + [action], new_g), f)
                frontier_puts += 1
    return None, 0, frontier_gets, frontier_puts

def aStarSearch(problem, heuristic=nullHeuristic):
    """ Do not change this function"""
    return aStarSearchStats(problem, heuristic)[0]
def GreedySearchStats(problem, heuristic=nullHeuristic):
    """Greedy Best-First Search: priority = heuristic(state)."""
    start = problem.getStartState() # very similar implementationto both of the above functions - like ucs and also A*
    frontier = util.PriorityQueue()
    frontier.push((start, [], 0), heuristic(start, problem))
    frontier_puts = 1
    explored = set()
    frontier_gets = 0
    while not frontier.isEmpty():
        state, actions, g = frontier.pop()
        frontier_gets += 1
        if state in explored:   # no additional check because cost not involved here only heuristic involved 
            continue
        explored.add(state)
        if problem.isGoalState(state):
            return actions, g, frontier_gets, frontier_puts
        for succ, action, stepCost in problem.getSuccessors(state):
            if succ not in explored:
                frontier.push((succ, actions + [action], g + stepCost), heuristic(succ, problem))
                frontier_puts += 1
    return None, 0, frontier_gets, frontier_puts

def GreedySearch(problem, heuristic=nullHeuristic):
    return GreedySearchStats(problem, heuristic)[0]

# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
greedy = GreedySearch
 