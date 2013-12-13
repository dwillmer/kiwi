/*------------------------------------------------------------------------------
| Copyright (c) 2013, Nucleic Development Team.
|
| Distributed under the terms of the Modified BSD License.
|
| The full license is in the file COPYING.txt, distributed with this software.
|-----------------------------------------------------------------------------*/
#pragma once
#include "constraint.h"
#include "solverimpl.h"
#include "strength.h"
#include "variable.h"


namespace kiwi
{

class Solver
{

public:

	Solver() {}

	~Solver() {}

	/* Add a constraint to the solver.

	If the constraint has already been added, this method is a no-op. If
	the strength of the constraint is required and the constraint cannot
	be satisfied, an UnsatisfiableConstraint exception will be thrown.

	*/
	void add( const Constraint& constraint )
	{
		m_impl.add( constraint );
	}

	/* Remove a constraint from the solver.

	If the constraint does not exist in the solver, this method is a
	no-op. This method always succeeds.

	*/
	void remove( const Constraint& constraint )
	{
		m_impl.remove( constraint );
	}

	void addEdit( const Variable& variable, double strength )
	{
		m_impl.addEdit( variable, strength );
	}

	void removeEdit( const Variable& variable )
	{
		m_impl.removeEdit( variable );
	}

	void suggestValue( const Variable& variable double value )
	{
		m_impl.suggestValue( variable, value );
	}

	/* Solve the system for the current set of constraints.

	Call this method to resolve the system after making changes to the
	constraints or edit variables. If the constraints are such that the
	objective function is unbounded, an UnboundedObjective exception
	will be thrown.

	*/
	void solve()
	{
		m_impl.solve();
	}

	/* Reset the solver to the empty starting condition.

	This method resets the internal solver state to the empty starting
	condition, as if no constraints have been added. This can be faster
	than deleting the solver and creating a new one when the system is
	large, since it avoids unecessary heap (de)allocations.

	*/
	void reset()
	{
		m_impl.reset();
	}

	void dump()
	{
		m_impl.dump();
	}

private:

	Solver( const Solver& );

	Solver& operator=( const Solver& );

	impl::SolverImpl m_impl;
};

} // namespace kiwi
