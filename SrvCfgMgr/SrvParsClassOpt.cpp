/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 or later licence
 *
 * $Id: SrvParsClassOpt.cpp,v 1.6 2004-09-28 20:12:39 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 */

#include <limits.h>
#include "SrvParsClassOpt.h"
#include "DHCPConst.h"

TSrvParsClassOpt::TSrvParsClassOpt(void)
{
    T1Beg    = SERVER_DEFAULT_MIN_T1;
    T1End    = SERVER_DEFAULT_MAX_T1;
    T2Beg    = SERVER_DEFAULT_MIN_T2;
    T2End    = SERVER_DEFAULT_MAX_T2;
    PrefBeg  = SERVER_DEFAULT_MIN_PREF;
    PrefEnd  = SERVER_DEFAULT_MAX_PREF;
    ValidBeg = SERVER_DEFAULT_MIN_VALID;
    ValidEnd = SERVER_DEFAULT_MAX_VALID;

    ClassMaxLease= ULONG_MAX;
}

//T1,T2,Valid,Prefered time routines
void TSrvParsClassOpt::setT1Beg(unsigned long t1)
{
    this->T1Beg=t1;
}

void TSrvParsClassOpt::setT1End(unsigned long t1)
{
    this->T1End=t1;
}

unsigned long TSrvParsClassOpt::getT1Beg()
{
    return T1Beg;
}

unsigned long TSrvParsClassOpt::getT1End()
{
    return T1End;
}

void TSrvParsClassOpt::setT2Beg(unsigned long t2)
{
    this->T2Beg=t2;
}

void TSrvParsClassOpt::setT2End(unsigned long t2)
{
    this->T2End=t2;
}

unsigned long TSrvParsClassOpt::getT2Beg()
{
    return this->T2Beg;
}

unsigned long TSrvParsClassOpt::getT2End()
{
    return this->T2End;
}

void TSrvParsClassOpt::setPrefBeg(unsigned long pref)
{
    this->PrefBeg=pref;
}

void TSrvParsClassOpt::setPrefEnd(unsigned long pref)
{
    this->PrefEnd=pref;
}

unsigned long TSrvParsClassOpt::getPrefBeg()
{
    return this->PrefBeg;
}

unsigned long TSrvParsClassOpt::getPrefEnd()
{
    return this->PrefEnd;
}

void TSrvParsClassOpt::setValidEnd(unsigned long valid)
{
    this->ValidEnd=valid;
}

void TSrvParsClassOpt::setValidBeg(unsigned long valid)
{
    this->ValidBeg=valid;
}

unsigned long TSrvParsClassOpt::getValidEnd()
{
    return this->ValidEnd;
}

unsigned long TSrvParsClassOpt::getValidBeg()
{
    return this->ValidBeg;
}

//Rejected clients access routines
void TSrvParsClassOpt::addRejedClnt(SmartPtr<TStationRange> addr)
{
    this->RejedClnt.append(addr);
}
void TSrvParsClassOpt::firstRejedClnt()
{
    this->RejedClnt.first();
}
SmartPtr<TStationRange> TSrvParsClassOpt::getRejedClnt()
{
    return this->RejedClnt.get();
}
void TSrvParsClassOpt::setRejedClnt(TContainer<SmartPtr<TStationRange> > *rejedClnt)
{
    this->RejedClnt.clear();
    rejedClnt->first();
    SmartPtr<TStationRange> addr;
    while(addr=rejedClnt->get())
        this->RejedClnt.append(addr);
}

//Accepted clients access routines
void TSrvParsClassOpt::addAcceptClnt(SmartPtr<TStationRange> addr)
{
    this->AcceptClnt.append(addr);
}

void TSrvParsClassOpt::firstAcceptClnt()
{
    this->AcceptClnt.first();
}

SmartPtr<TStationRange> TSrvParsClassOpt::getAcceptClnt()
{
    return this->AcceptClnt.get();
}

void TSrvParsClassOpt::setAcceptClnt(TContainer<SmartPtr<TStationRange> > *acceptClnt)
{
    this->AcceptClnt.clear();
    acceptClnt->first();
    SmartPtr<TStationRange> addr;
    while(addr=acceptClnt->get())
        this->AcceptClnt.append(addr);
}

//Pool access routines
void TSrvParsClassOpt::addPool(SmartPtr<TStationRange> addr)
{
    this->Pool.append(addr);
}
void TSrvParsClassOpt::firstPool()
{
    this->Pool.first();
}
SmartPtr<TStationRange> TSrvParsClassOpt::getPool()
{
    return this->Pool.get();
}

void TSrvParsClassOpt::setPool(TContainer<SmartPtr<TStationRange> > *pool)
{
    this->Pool.clear();
    pool->first();
    SmartPtr<TStationRange> addr;
    while(addr=pool->get())
        this->Pool.append(addr);
}

void TSrvParsClassOpt::setClassMaxLease(unsigned long classMaxLease) {
    this->ClassMaxLease = classMaxLease;
}


unsigned long TSrvParsClassOpt::getClassMaxLease() {
    return this->ClassMaxLease;
}

TSrvParsClassOpt::~TSrvParsClassOpt(void)
{
}

long TSrvParsClassOpt::countPool()
{
    return this->Pool.count();
}
