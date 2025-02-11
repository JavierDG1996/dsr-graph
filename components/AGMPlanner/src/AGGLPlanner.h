//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.3
//
// <auto-generated>
//
// Generated from file `AGGLPlanner.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __AGGLPlanner_h__
#define __AGGLPlanner_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/GCObject.h>
#include <Ice/Value.h>
#include <Ice/Incoming.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/Optional.h>
#include <IceUtil/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 >= 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 3
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace RoboCompAGGLPlanner
{

class AGGLPlanner;
class AGGLPlannerPrx;

}

namespace RoboCompAGGLPlanner
{

struct Parameters
{
    ::std::string pythonarg;
    ::std::string agglplanarg;
    ::std::string agglfile;
    ::std::string initfile;
    ::std::string aggtgoal;
    ::std::string resultplan;

    /**
     * Obtains a tuple containing all of the struct's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&, const ::std::string&> ice_tuple() const
    {
        return std::tie(pythonarg, agglplanarg, agglfile, initfile, aggtgoal, resultplan);
    }
};

using Ice::operator<;
using Ice::operator<=;
using Ice::operator>;
using Ice::operator>=;
using Ice::operator==;
using Ice::operator!=;

}

namespace RoboCompAGGLPlanner
{

class AGGLPlanner : public virtual ::Ice::Object
{
public:

    using ProxyType = AGGLPlannerPrx;

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(::std::string id, const ::Ice::Current& current) const override;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector<::std::string> ice_ids(const ::Ice::Current& current) const override;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual ::std::string ice_id(const ::Ice::Current& current) const override;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual bool AGGlplannerexecution(Parameters arguments, const ::Ice::Current& current) = 0;
    /// \cond INTERNAL
    bool _iceD_AGGlplannerexecution(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&) override;
    /// \endcond
};

}

namespace RoboCompAGGLPlanner
{

class AGGLPlannerPrx : public virtual ::Ice::Proxy<AGGLPlannerPrx, ::Ice::ObjectPrx>
{
public:

    bool AGGlplannerexecution(const Parameters& arguments, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _makePromiseOutgoing<bool>(true, this, &AGGLPlannerPrx::_iceI_AGGlplannerexecution, arguments, context).get();
    }

    template<template<typename> class P = ::std::promise>
    auto AGGlplannerexecutionAsync(const Parameters& arguments, const ::Ice::Context& context = ::Ice::noExplicitContext)
        -> decltype(::std::declval<P<bool>>().get_future())
    {
        return _makePromiseOutgoing<bool, P>(false, this, &AGGLPlannerPrx::_iceI_AGGlplannerexecution, arguments, context);
    }

    ::std::function<void()>
    AGGlplannerexecutionAsync(const Parameters& arguments,
                              ::std::function<void(bool)> response,
                              ::std::function<void(::std::exception_ptr)> ex = nullptr,
                              ::std::function<void(bool)> sent = nullptr,
                              const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _makeLamdaOutgoing<bool>(response, ex, sent, this, &RoboCompAGGLPlanner::AGGLPlannerPrx::_iceI_AGGlplannerexecution, arguments, context);
    }

    /// \cond INTERNAL
    void _iceI_AGGlplannerexecution(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<bool>>&, const Parameters&, const ::Ice::Context&);
    /// \endcond

    /**
     * Obtains the Slice type ID of this interface.
     * @return The fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:

    /// \cond INTERNAL
    AGGLPlannerPrx() = default;
    friend ::std::shared_ptr<AGGLPlannerPrx> IceInternal::createProxy<AGGLPlannerPrx>();

    virtual ::std::shared_ptr<::Ice::ObjectPrx> _newInstance() const override;
    /// \endcond
};

}

/// \cond STREAM
namespace Ice
{

template<>
struct StreamableTraits<::RoboCompAGGLPlanner::Parameters>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 6;
    static const bool fixedLength = false;
};

template<typename S>
struct StreamReader<::RoboCompAGGLPlanner::Parameters, S>
{
    static void read(S* istr, ::RoboCompAGGLPlanner::Parameters& v)
    {
        istr->readAll(v.pythonarg, v.agglplanarg, v.agglfile, v.initfile, v.aggtgoal, v.resultplan);
    }
};

}
/// \endcond

/// \cond INTERNAL
namespace RoboCompAGGLPlanner
{

using AGGLPlannerPtr = ::std::shared_ptr<AGGLPlanner>;
using AGGLPlannerPrxPtr = ::std::shared_ptr<AGGLPlannerPrx>;

}
/// \endcond

#else // C++98 mapping

namespace IceProxy
{

namespace RoboCompAGGLPlanner
{

class AGGLPlanner;
/// \cond INTERNAL
void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< AGGLPlanner>&);
::IceProxy::Ice::Object* upCast(AGGLPlanner*);
/// \endcond

}

}

namespace RoboCompAGGLPlanner
{

class AGGLPlanner;
/// \cond INTERNAL
::Ice::Object* upCast(AGGLPlanner*);
/// \endcond
typedef ::IceInternal::Handle< AGGLPlanner> AGGLPlannerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::RoboCompAGGLPlanner::AGGLPlanner> AGGLPlannerPrx;
typedef AGGLPlannerPrx AGGLPlannerPrxPtr;
/// \cond INTERNAL
void _icePatchObjectPtr(AGGLPlannerPtr&, const ::Ice::ObjectPtr&);
/// \endcond

}

namespace RoboCompAGGLPlanner
{

struct Parameters
{
    ::std::string pythonarg;
    ::std::string agglplanarg;
    ::std::string agglfile;
    ::std::string initfile;
    ::std::string aggtgoal;
    ::std::string resultplan;

    bool operator==(const Parameters& rhs_) const
    {
        if(this == &rhs_)
        {
            return true;
        }
        if(pythonarg != rhs_.pythonarg)
        {
            return false;
        }
        if(agglplanarg != rhs_.agglplanarg)
        {
            return false;
        }
        if(agglfile != rhs_.agglfile)
        {
            return false;
        }
        if(initfile != rhs_.initfile)
        {
            return false;
        }
        if(aggtgoal != rhs_.aggtgoal)
        {
            return false;
        }
        if(resultplan != rhs_.resultplan)
        {
            return false;
        }
        return true;
    }

    bool operator<(const Parameters& rhs_) const
    {
        if(this == &rhs_)
        {
            return false;
        }
        if(pythonarg < rhs_.pythonarg)
        {
            return true;
        }
        else if(rhs_.pythonarg < pythonarg)
        {
            return false;
        }
        if(agglplanarg < rhs_.agglplanarg)
        {
            return true;
        }
        else if(rhs_.agglplanarg < agglplanarg)
        {
            return false;
        }
        if(agglfile < rhs_.agglfile)
        {
            return true;
        }
        else if(rhs_.agglfile < agglfile)
        {
            return false;
        }
        if(initfile < rhs_.initfile)
        {
            return true;
        }
        else if(rhs_.initfile < initfile)
        {
            return false;
        }
        if(aggtgoal < rhs_.aggtgoal)
        {
            return true;
        }
        else if(rhs_.aggtgoal < aggtgoal)
        {
            return false;
        }
        if(resultplan < rhs_.resultplan)
        {
            return true;
        }
        else if(rhs_.resultplan < resultplan)
        {
            return false;
        }
        return false;
    }

    bool operator!=(const Parameters& rhs_) const
    {
        return !operator==(rhs_);
    }
    bool operator<=(const Parameters& rhs_) const
    {
        return operator<(rhs_) || operator==(rhs_);
    }
    bool operator>(const Parameters& rhs_) const
    {
        return !operator<(rhs_) && !operator==(rhs_);
    }
    bool operator>=(const Parameters& rhs_) const
    {
        return !operator<(rhs_);
    }
};

}

namespace RoboCompAGGLPlanner
{

/**
 * Base class for asynchronous callback wrapper classes used for calls to
 * IceProxy::RoboCompAGGLPlanner::AGGLPlanner::begin_AGGlplannerexecution.
 * Create a wrapper instance by calling ::RoboCompAGGLPlanner::newCallback_AGGLPlanner_AGGlplannerexecution.
 */
class Callback_AGGLPlanner_AGGlplannerexecution_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_AGGLPlanner_AGGlplannerexecution_Base> Callback_AGGLPlanner_AGGlplannerexecutionPtr;

}

namespace IceProxy
{

namespace RoboCompAGGLPlanner
{

class AGGLPlanner : public virtual ::Ice::Proxy<AGGLPlanner, ::IceProxy::Ice::Object>
{
public:

    bool AGGlplannerexecution(const ::RoboCompAGGLPlanner::Parameters& arguments, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return end_AGGlplannerexecution(_iceI_begin_AGGlplannerexecution(arguments, context, ::IceInternal::dummyCallback, 0, true));
    }

    ::Ice::AsyncResultPtr begin_AGGlplannerexecution(const ::RoboCompAGGLPlanner::Parameters& arguments, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_AGGlplannerexecution(arguments, context, ::IceInternal::dummyCallback, 0);
    }

    ::Ice::AsyncResultPtr begin_AGGlplannerexecution(const ::RoboCompAGGLPlanner::Parameters& arguments, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_AGGlplannerexecution(arguments, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_AGGlplannerexecution(const ::RoboCompAGGLPlanner::Parameters& arguments, const ::Ice::Context& context, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_AGGlplannerexecution(arguments, context, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_AGGlplannerexecution(const ::RoboCompAGGLPlanner::Parameters& arguments, const ::RoboCompAGGLPlanner::Callback_AGGLPlanner_AGGlplannerexecutionPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_AGGlplannerexecution(arguments, ::Ice::noExplicitContext, cb, cookie);
    }

    ::Ice::AsyncResultPtr begin_AGGlplannerexecution(const ::RoboCompAGGLPlanner::Parameters& arguments, const ::Ice::Context& context, const ::RoboCompAGGLPlanner::Callback_AGGLPlanner_AGGlplannerexecutionPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_AGGlplannerexecution(arguments, context, cb, cookie);
    }

    bool end_AGGlplannerexecution(const ::Ice::AsyncResultPtr& result);

private:

    ::Ice::AsyncResultPtr _iceI_begin_AGGlplannerexecution(const ::RoboCompAGGLPlanner::Parameters&, const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    /**
     * Obtains the Slice type ID corresponding to this interface.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

protected:
    /// \cond INTERNAL

    virtual ::IceProxy::Ice::Object* _newInstance() const;
    /// \endcond
};

}

}

namespace RoboCompAGGLPlanner
{

class AGGLPlanner : public virtual ::Ice::Object
{
public:

    typedef AGGLPlannerPrx ProxyType;
    typedef AGGLPlannerPtr PointerType;

    virtual ~AGGLPlanner();

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(const ::std::string& id, const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual const ::std::string& ice_id(const ::Ice::Current& current = ::Ice::emptyCurrent) const;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    virtual bool AGGlplannerexecution(const Parameters& arguments, const ::Ice::Current& current = ::Ice::emptyCurrent) = 0;
    /// \cond INTERNAL
    bool _iceD_AGGlplannerexecution(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

protected:

    /// \cond STREAM
    virtual void _iceWriteImpl(::Ice::OutputStream*) const;
    virtual void _iceReadImpl(::Ice::InputStream*);
    /// \endcond
};

/// \cond INTERNAL
inline bool operator==(const AGGLPlanner& lhs, const AGGLPlanner& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) == static_cast<const ::Ice::Object&>(rhs);
}

inline bool operator<(const AGGLPlanner& lhs, const AGGLPlanner& rhs)
{
    return static_cast<const ::Ice::Object&>(lhs) < static_cast<const ::Ice::Object&>(rhs);
}
/// \endcond

}

/// \cond STREAM
namespace Ice
{

template<>
struct StreamableTraits< ::RoboCompAGGLPlanner::Parameters>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 6;
    static const bool fixedLength = false;
};

template<typename S>
struct StreamWriter< ::RoboCompAGGLPlanner::Parameters, S>
{
    static void write(S* ostr, const ::RoboCompAGGLPlanner::Parameters& v)
    {
        ostr->write(v.pythonarg);
        ostr->write(v.agglplanarg);
        ostr->write(v.agglfile);
        ostr->write(v.initfile);
        ostr->write(v.aggtgoal);
        ostr->write(v.resultplan);
    }
};

template<typename S>
struct StreamReader< ::RoboCompAGGLPlanner::Parameters, S>
{
    static void read(S* istr, ::RoboCompAGGLPlanner::Parameters& v)
    {
        istr->read(v.pythonarg);
        istr->read(v.agglplanarg);
        istr->read(v.agglfile);
        istr->read(v.initfile);
        istr->read(v.aggtgoal);
        istr->read(v.resultplan);
    }
};

}
/// \endcond

namespace RoboCompAGGLPlanner
{

/**
 * Type-safe asynchronous callback wrapper class used for calls to
 * IceProxy::RoboCompAGGLPlanner::AGGLPlanner::begin_AGGlplannerexecution.
 * Create a wrapper instance by calling ::RoboCompAGGLPlanner::newCallback_AGGLPlanner_AGGlplannerexecution.
 */
template<class T>
class CallbackNC_AGGLPlanner_AGGlplannerexecution : public Callback_AGGLPlanner_AGGlplannerexecution_Base, public ::IceInternal::TwowayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)(bool);

    CallbackNC_AGGLPlanner_AGGlplannerexecution(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallbackNC<T>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    /// \cond INTERNAL
    virtual void completed(const ::Ice::AsyncResultPtr& result) const
    {
        AGGLPlannerPrx proxy = AGGLPlannerPrx::uncheckedCast(result->getProxy());
        bool ret;
        try
        {
            ret = proxy->end_AGGlplannerexecution(result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::CallbackNC<T>::exception(result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::CallbackNC<T>::_callback.get()->*_response)(ret);
        }
    }
    /// \endcond

private:

    Response _response;
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompAGGLPlanner::AGGLPlanner::begin_AGGlplannerexecution.
 */
template<class T> Callback_AGGLPlanner_AGGlplannerexecutionPtr
newCallback_AGGLPlanner_AGGlplannerexecution(const IceUtil::Handle<T>& instance, void (T::*cb)(bool), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_AGGLPlanner_AGGlplannerexecution<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompAGGLPlanner::AGGLPlanner::begin_AGGlplannerexecution.
 */
template<class T> Callback_AGGLPlanner_AGGlplannerexecutionPtr
newCallback_AGGLPlanner_AGGlplannerexecution(T* instance, void (T::*cb)(bool), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_AGGLPlanner_AGGlplannerexecution<T>(instance, cb, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class with cookie support used for calls to
 * IceProxy::RoboCompAGGLPlanner::AGGLPlanner::begin_AGGlplannerexecution.
 * Create a wrapper instance by calling ::RoboCompAGGLPlanner::newCallback_AGGLPlanner_AGGlplannerexecution.
 */
template<class T, typename CT>
class Callback_AGGLPlanner_AGGlplannerexecution : public Callback_AGGLPlanner_AGGlplannerexecution_Base, public ::IceInternal::TwowayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(bool, const CT&);

    Callback_AGGLPlanner_AGGlplannerexecution(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::TwowayCallback<T, CT>(obj, cb != 0, excb, sentcb), _response(cb)
    {
    }

    /// \cond INTERNAL
    virtual void completed(const ::Ice::AsyncResultPtr& result) const
    {
        AGGLPlannerPrx proxy = AGGLPlannerPrx::uncheckedCast(result->getProxy());
        bool ret;
        try
        {
            ret = proxy->end_AGGlplannerexecution(result);
        }
        catch(const ::Ice::Exception& ex)
        {
            ::IceInternal::Callback<T, CT>::exception(result, ex);
            return;
        }
        if(_response)
        {
            (::IceInternal::Callback<T, CT>::_callback.get()->*_response)(ret, CT::dynamicCast(result->getCookie()));
        }
    }
    /// \endcond

private:

    Response _response;
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompAGGLPlanner::AGGLPlanner::begin_AGGlplannerexecution.
 */
template<class T, typename CT> Callback_AGGLPlanner_AGGlplannerexecutionPtr
newCallback_AGGLPlanner_AGGlplannerexecution(const IceUtil::Handle<T>& instance, void (T::*cb)(bool, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_AGGLPlanner_AGGlplannerexecution<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::RoboCompAGGLPlanner::AGGLPlanner::begin_AGGlplannerexecution.
 */
template<class T, typename CT> Callback_AGGLPlanner_AGGlplannerexecutionPtr
newCallback_AGGLPlanner_AGGlplannerexecution(T* instance, void (T::*cb)(bool, const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_AGGLPlanner_AGGlplannerexecution<T, CT>(instance, cb, excb, sentcb);
}

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
