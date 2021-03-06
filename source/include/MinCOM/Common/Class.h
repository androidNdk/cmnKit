/*
* File name   : Class.h
*
* Copyright (c) 2008 Scientific Software
*
* Modification History:
* Date        Name                Description
* 2008-12-14  Egor Pushkin        Initial version
* 2009-01-23  Egor Pushkin        Routines were organized into class
*/

#ifndef CLASS_H__MINCOM__INCLUDED_
#define CLASS_H__MINCOM__INCLUDED_

namespace MinCOM
{

	/**
	 * Provides unified tool to instantiate all MinCOM classes.
	 * Potentially this tool is responsible for memory management of all
	 * allocated objects.
	 */ 
	template
	<
		/**
		 * Template argument should indicate particular class compatible
		 * to MinCOM object.
		 */ 
		class T
	>
	class Class
	{
	public:

		static Strong<ICommon> Create() 
		{ 
			try
			{
				return PostInit(Strong<ICommon>(new T())); 
			}
			catch ( ... )
			{
				return NULL;
			}
		}	

		template< class T1 > 
		static Strong<ICommon> Create(const T1& p1) 
		{ 
			try
			{
				return PostInit(Strong<ICommon>(new T(p1))); 
			}
			catch ( ... )
			{
				return NULL;
			}
		}	

		template< class T1, class T2 > 
		static Strong<ICommon> Create(const T1& p1, const T2& p2) 
		{ 
			try
			{
				return PostInit(Strong<ICommon>(new T(p1, p2))); 
			}
			catch ( ... )
			{
				return NULL;
			}
		}	

		template< class T1, class T2, class T3 > 
		static Strong<ICommon> Create(const T1& p1, const T2& p2, const T3& p3) 
		{ 
			try
			{
				return PostInit(Strong<ICommon>(new T(p1, p2, p3))); 
			}
			catch ( ... )
			{
				return NULL;
			}
		}

		template< class T1, class T2, class T3, class T4 >
		static Strong<ICommon> Create(const T1& p1, const T2& p2, const T3& p3, const T4& p4)
		{
			try
			{
				return PostInit(Strong<ICommon>(new T(p1, p2, p3, p4)));
			}
			catch ( ... )
			{
				return NULL;
			}
		}

		template< class T1, class T2, class T3, class T4, class T5 >
		static Strong<ICommon> Create(const T1& p1, const T2& p2, const T3& p3, const T4& p4, const T5& p5)
		{
			try
			{
				return PostInit(Strong<ICommon>(new T(p1, p2, p3, p4, p5)));
			}
			catch ( ... )
			{
				return NULL;
			}
		}
		
		template< class T1, class T2, class T3, class T4, class T5, class T6 >
		static Strong<ICommon> Create(const T1& p1, const T2& p2, const T3& p3, const T4& p4, const T5& p5, const T6& p6)
		{
			try
			{
				return PostInit(Strong<ICommon>(new T(p1, p2, p3, p4, p5, p6)));
			}
			catch ( ... )
			{
				return NULL;
			}
		}		
		
		/**
		 * Tool to provide client with class identifier.
		 */
		static Clsid DefaultClsid()
		{
			return clsid_;
		}

	private:

		static const Clsid clsid_;

	private:

		static Strong<ICommon> PostInit(const Strong<ICommon> & common)
		{
			// Configure object.
			common->SetSelf(common);
			// Perform post initialization.
			if ( mc::Error::IsFailed(common->PostInit()) )
				return NULL;
			// Return correctly initialized object.
			return common;
		}	

	};

}

#endif // !CLASS_H__MINCOM__INCLUDED_
